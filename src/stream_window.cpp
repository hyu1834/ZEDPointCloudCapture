#include "stream_window.h"
#include "ui_streamwindow.h"

streamWindow::streamWindow(QString title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::streamWindow)
{
	
    ui->setupUi(this);
	this->setWindowTitle(title);
}

streamWindow::~streamWindow()
{
    delete ui;
}


void streamWindow::setImage(cv::Mat img, QImage::Format format)	{
	ui->streamImage->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, format)));
}
