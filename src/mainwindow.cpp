#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::paused = false;
bool MainWindow::preview = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), colorLeftStreamWindow(NULL), colorRightStreamWindow(NULL), colorSBSStreamWindow(NULL),
depthStreamWindow(NULL), frameRate(500)	{
	ui->setupUi(this);
	// Open application in full screen mode
	QWidget::showMaximized();

	// Initialize Realsense
	initializeCamera();
	//pointCloud3D = boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> >(new pcl::PointCloud<pcl::PointXYZRGB>);

	//Timer trigger to capture point cloud every 0.5 seconds
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updatePointCloud()));
	timer->start(frameRate); //time specified in ms

	//connect(ui->colorResolutionBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_resolutionChanged(int)));
}

MainWindow::~MainWindow()	{
	delete zed;
	delete ui;
}

/*
	Class Function
*/
void MainWindow::initializeCamera()	{
	zed = new StereoLabsZED(ui->colorResolutionBox->currentIndex(),
				ui->depthSenseModeBox->currentIndex(),
				ui->unitBox->currentIndex(),
				ui->coordinateBox->currentIndex());
}


/*
	Clicked Signal Methods
*/
void MainWindow::on_previewButton_clicked()	{
	if(preview)	{
		preview = false;
		ui->previewButton->setText("Preview");
		ui->pauseButton->setEnabled(false);
		ui->showLeftStreamButton->setEnabled(false);
		ui->showRightStreamButton->setEnabled(false);
		ui->showSBSStreamButton->setEnabled(false);
		ui->showDepthStreamButton->setEnabled(false);

		ui->colorResolutionBox->setEnabled(true);
		ui->depthSenseModeBox->setEnabled(true);
		ui->unitBox->setEnabled(true);
		ui->coordinateBox->setEnabled(true);
	}
	else	{
		preview = true;
		ui->previewButton->setText("Stop");
		ui->pauseButton->setEnabled(true);
		ui->showLeftStreamButton->setEnabled(true);
		ui->showRightStreamButton->setEnabled(true);
		ui->showSBSStreamButton->setEnabled(true);
		ui->showDepthStreamButton->setEnabled(true);

		ui->colorResolutionBox->setEnabled(false);
		ui->depthSenseModeBox->setEnabled(false);
		ui->unitBox->setEnabled(false);
		ui->coordinateBox->setEnabled(false);
	}
}

void MainWindow::on_pauseButton_clicked()	{
	if(paused)	{
		paused = false;
		ui->pauseButton->setText("Pause");
		ui->savePointCloudButton->setEnabled(false);
		ui->saveImagesButton->setEnabled(false);
	}
	else	{
		paused = true;
		ui->pauseButton->setText("Resume");
		ui->savePointCloudButton->setEnabled(true);
		ui->saveImagesButton->setEnabled(true);
	}
}

void MainWindow::on_savePointCloudButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
		return;
	}
	if(zed->getPointCloud()->size() < 1)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Point Cloud Size < 1"));
		return;
	}

	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Point Cloud File"), QString(),
														  tr("Text Files (*.txt);;All Files (*.*)"));
	// if a file is selected
	if(filePath != "")  {
		exportPointCloud<pcl::PointXYZRGB>(filePath.toUtf8().constData(), zed->getPointCloud(), 0.0, 0.0, 0.0);
		QMessageBox::information(this, "Export Point Cloud",
					 QString::fromStdString("Exported: " + formatNumber<int>(zed->getPointCloud()->size()) + " points"));
	}
}

void MainWindow::on_saveImagesButton_clicked()	{
	if(!paused)	{
		QMessageBox::critical(this, "Error!", QString::fromStdString("Error: Save cannot be completed, frame is not paused"));
	}
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save Images File"), QString(),
														  tr("Portable Network Graphics (*.png);;Joint Photographic Experts Group (*.JPEG)"));
	// if a file is selected
	if(filePath != "")  {
		std::string path, extension;
		splitFilepathExtension(filePath.toUtf8().data(), path, extension);
		if(extension.empty())	{
			QMessageBox::critical(this, "Error!", QString::fromStdString("Error: File name without extension"));
			return;
		}
		std::cout << path << "  " << extension << "\n";
		
		//Save Left image
		cv::cvtColor(colorLeftImage, colorLeftImage, CV_RGBA2RGB);
		cv::imwrite(path + "_L." + extension, colorLeftImage);
		
		//Save Right image
		cv::cvtColor(colorRightImage, colorRightImage, CV_RGBA2RGB);
		cv::imwrite(path + "_R." + extension, colorRightImage);

		//Save Side by Side image
		cv::cvtColor(colorSBSImage, colorSBSImage, CV_RGBA2RGB);
		cv::imwrite(path + "_SBS." + extension, colorSBSImage);
		
		//Save Depth image
		cv::imwrite(path + "_D." + extension, depthImage);
	}
}

void MainWindow::on_showLeftStreamButton_clicked()	{
	if(!colorLeftStreamWindow)	{
		colorLeftStreamWindow = new streamWindow("Left Stream");
		colorLeftStreamWindow->show();
		ui->showLeftStreamButton->setText("Hide Left Stream");
	}
	else	{
		delete colorLeftStreamWindow;
		colorLeftStreamWindow = NULL;
		ui->showLeftStreamButton->setText("Show Left Stream");
	}
	
}

void MainWindow::on_showRightStreamButton_clicked()	{
	if(!colorRightStreamWindow)	{
		colorRightStreamWindow = new streamWindow("Right Stream");
		colorRightStreamWindow->show();
		ui->showRightStreamButton->setText("Hide Right Stream");
	}
	else	{
		delete colorRightStreamWindow;
		colorRightStreamWindow = NULL;
		ui->showRightStreamButton->setText("Show Right Stream");
	}
}

void MainWindow::on_showSBSStreamButton_clicked()	{
	if(!colorSBSStreamWindow)	{
		colorSBSStreamWindow = new streamWindow("Side By Side Stream");
		colorSBSStreamWindow->show();
		ui->showSBSStreamButton->setText("Hide SBS Stream");
	}
	else	{
		delete colorSBSStreamWindow;
		colorSBSStreamWindow = NULL;
		ui->showSBSStreamButton->setText("Show SBS Stream");
	}
}

void MainWindow::on_showDepthStreamButton_clicked()	{
	if(!depthStreamWindow)	{
		depthStreamWindow = new streamWindow("Depth Stream");
		depthStreamWindow->show();
		ui->showDepthStreamButton->setText("Hide Depth Stream");
	}
	else	{
		delete depthStreamWindow;
		depthStreamWindow = NULL;
		ui->showDepthStreamButton->setText("Show Depth Stream");
	}
}

void MainWindow::on_colorResolutionBox_currentIndexChanged(int index)	{
	std::cout << index << "\n";
	delete zed;
	zed = new StereoLabsZED(ui->colorResolutionBox->currentIndex(),
				ui->depthSenseModeBox->currentIndex(),
				ui->unitBox->currentIndex(),
				ui->coordinateBox->currentIndex());
}

void MainWindow::on_depthSenseModeBox_currentIndexChanged(int index)	{
	std::cout << index << "\n";
	delete zed;
	zed = new StereoLabsZED(ui->colorResolutionBox->currentIndex(),
				ui->depthSenseModeBox->currentIndex(),
				ui->unitBox->currentIndex(),
				ui->coordinateBox->currentIndex());
}

void MainWindow::on_unitBox_currentIndexChanged(int index)	{
	std::cout << index << "\n";
	delete zed;
	zed = new StereoLabsZED(ui->colorResolutionBox->currentIndex(),
				ui->depthSenseModeBox->currentIndex(),
				ui->unitBox->currentIndex(),
				ui->coordinateBox->currentIndex());
}

void MainWindow::on_coordinateBox_currentIndexChanged(int index)	{
	std::cout << index << "\n";
	delete zed;
	zed = new StereoLabsZED(ui->colorResolutionBox->currentIndex(),
				ui->depthSenseModeBox->currentIndex(),
				ui->unitBox->currentIndex(),
				ui->coordinateBox->currentIndex());
}


/*
	Trigger Signal Methods
*/
void MainWindow::on_actionExit_triggered()	{
	QApplication::quit();
}


void MainWindow::on_actionHelp_triggered()	{
	QString helpStr = QString::fromStdString(std::string("Click \"Preview\" button to start camera stream\n") +
											 "Click \"Pause\" button to pause the camera stream\n" +
											 "Click \"Save Point Cloud\" button to save captured point cloud" 
											);
	QMessageBox::information(this, "Help", helpStr);
}

void MainWindow::on_actionAbout_triggered()	{
	QString aboutStr = QString::fromStdString(std::string("Program Title: Intel RealSense R200 Point Cloud Capture\n") + 
											  "Developer: Hiu Hong Yu\n" +
											  "Developer Email: hiuyu@ucdavis.edu\n" +
											  "Organization: Advanced Highway Maintenance and Construction Research Center (AHMCT), University of California, Davis\n" +
											  "Copy Right 2017"
											 );
	QMessageBox::information(this, "About", aboutStr);
}

void MainWindow::updatePointCloud()	{
	//if preview started and frame not paused
	if(preview && !paused)	{
		//Capture a frame
		if(zed->captureFrame())	{
			cv::Mat temp;

			//Compute point cloud
			zed->computePointCloud();
			
			//Get Left Image
			temp = zed->getImage(sl::VIEW_LEFT);
			temp.copyTo(colorLeftImage);
			//Get Right Image
			temp = zed->getImage(sl::VIEW_RIGHT);
			temp.copyTo(colorRightImage);
			//Get Side by Side Image
			temp = zed->getImage(sl::VIEW_SIDE_BY_SIDE);
			temp.copyTo(colorSBSImage);
			//Get Depth Image
			temp = zed->getImage(sl::VIEW_DEPTH);
			temp.copyTo(depthImage);
			
			//Copy color image to pc image with depth image as mask
			colorLeftImage.copyTo(pcImage, depthImage);
			ui->pcImage->setPixmap(QPixmap::fromImage(QImage(pcImage.data, pcImage.cols, 
									 pcImage.rows, pcImage.step, 
									 QImage::Format_RGBA8888)));
		
			
			//if show left stream
			if(colorLeftStreamWindow != NULL)	{
				colorLeftStreamWindow->setImage(colorLeftImage, QImage::Format_RGBA8888);
			}
			//if show right stream
			if(colorRightStreamWindow != NULL)	{
				colorRightStreamWindow->setImage(colorRightImage, QImage::Format_RGBA8888);
			}
			//if show side by side stream
			if(colorSBSStreamWindow != NULL)	{
				colorSBSStreamWindow->setImage(colorSBSImage, QImage::Format_RGBA8888);
			}
			//if show depth stream
			if(depthStreamWindow != NULL)	{
				cv::cvtColor(depthImage, depthImage, CV_RGBA2GRAY);
				depthStreamWindow->setImage(depthImage, QImage::Format_Grayscale8);
			}
		}
	}
	
}
