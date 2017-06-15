/*
	ZED wrapper is a wrapper class for easy access some common
	feature from ZED camera.
	such as capture frame, get depth, left/right color image
	Function in this class are modified from ZED sample
*/

#ifndef ZED_WRAPPER_H
#define ZED_WRAPPER_H
/*
 *  Standard Libraries
*/
#include <iostream>

/*
 *  3rd Party Libraries
*/
// ZED includes
#include <sl/Camera.hpp>

//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

//PCL
#include <pcl/common/common_headers.h>

/*
 *  Local Libraries
*/


/*
	ENUM
*/


/*
	MACRO
*/

class StereoLabsZED	{
	private:
		sl::InitParameters initParameters;
		sl::Camera zed;
		
		boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> > pointCloud3D;	
		
	protected:

	public:
		StereoLabsZED(int resolution = 0, int senseMode = 0, int unit = 0, int coordSys = 0);
		~StereoLabsZED();
		bool captureFrame();
		cv::Mat getImage(sl::VIEW type);
		void computePointCloud();
		sl::Resolution getResolution();
		boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> > getPointCloud();
		unsigned char getColor(float color, int index);
		/**
		*  This function convert a RGBA color packed into a packed RGBA PCL compatible format
		**/
		inline float convertColor(float colorIn);
};

#endif
