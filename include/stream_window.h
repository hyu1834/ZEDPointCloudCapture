#ifndef STREAMWINDOW_H
#define STREAMWINDOW_H
/*
 *  Standard Libraries
*/


/*
 *  3rd Party Libraries
*/
//QT
#include <QWidget>
#include <QImage>

//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

/*
 *  Local Libraries
*/


/*
	ENUM
*/



/*
	MACRO
*/


namespace Ui {
class streamWindow;
}

class streamWindow : public QWidget
{
    Q_OBJECT

public:
    explicit streamWindow(QString title, QWidget *parent = 0);
    ~streamWindow();

    void setImage(cv::Mat img, QImage::Format format);

private:
    Ui::streamWindow *ui;
};

#endif // STREAMWINDOW_H
