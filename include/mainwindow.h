#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 *  Standard Libraries
*/
#include <iostream>

/*
 *  3rd Party Libraries
*/
//QT
#include <QTime>
#include <QtGui>
#include <QFile>
#include <QImage>

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QCoreApplication>

//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

//PCL
#include <pcl/common/common_headers.h>


/*
 *  Local Libraries
*/
#include "str_utils.h"
#include "point_cloud_utils.h"
#include "stream_window.h"
//#include "color_stream_window.h"
//#include "depth_stream_window.h"
#include "zed_wrapper.h"

/*
	ENUM
*/


/*
	MACRO
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		/*
			Clicked Signal Methods
		*/
		void on_previewButton_clicked();
		void on_pauseButton_clicked();
		void on_savePointCloudButton_clicked();
		void on_saveImagesButton_clicked();
		void on_showLeftStreamButton_clicked();
		void on_showRightStreamButton_clicked();
		void on_showSBSStreamButton_clicked();
		void on_showDepthStreamButton_clicked();
		void on_colorResolutionBox_currentIndexChanged(int index);
		void on_depthSenseModeBox_currentIndexChanged(int index);
		void on_unitBox_currentIndexChanged(int index);
		void on_coordinateBox_currentIndexChanged(int index);


		/*
			Trigger Signal Methods
		*/
		void on_actionExit_triggered();
		void on_actionHelp_triggered();
		void on_actionAbout_triggered();
		void updatePointCloud();

	private:
		Ui::MainWindow *ui;
		QTimer* timer;

		cv::Mat colorLeftImage;
		cv::Mat colorRightImage;
		cv::Mat colorSBSImage;
		cv::Mat depthImage;
		cv::Mat pcImage;
		
		streamWindow* colorLeftStreamWindow;
		streamWindow* colorRightStreamWindow;
		streamWindow* colorSBSStreamWindow;
		streamWindow* depthStreamWindow;
		int frameRate;

		static bool paused;
		static bool preview;

		StereoLabsZED* zed;
		
		boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> > pointCloud3D;

		/*
			Class Function
		*/
		void initializeCamera();
};

#endif // MAINWINDOW_H
