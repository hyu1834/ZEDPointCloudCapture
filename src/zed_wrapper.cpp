#include "zed_wrapper.h"

StereoLabsZED::StereoLabsZED(int resolution, int senseMode, int unit, int coordSys)	{
	pointCloud3D = boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> >(new pcl::PointCloud<pcl::PointXYZRGB>);
	// Resolution setting
	if(resolution == 0)   {
        initParameters.camera_resolution = sl::RESOLUTION_HD2K;
	//pointCloud3D->points.resize(2048 * 1080);
    }
    else if(resolution == 1)   {
        initParameters.camera_resolution = sl::RESOLUTION_HD1080;
	//pointCloud3D->points.resize(1920 * 1080);
    }
    else if(resolution == 2)   {
        initParameters.camera_resolution = sl::RESOLUTION_HD720;
	//pointCloud3D->points.resize(1280 * 720);
    }
    else if(resolution == 3)   {
        initParameters.camera_resolution = sl::RESOLUTION_VGA;
	//pointCloud3D->points.resize(640 * 480);
    }
    else	{

    }

    // Sensing mode
    if(senseMode == 0)	{
    	initParameters.depth_mode = sl::DEPTH_MODE_PERFORMANCE;
    }
    else	{
        //need quite a powerful graphic card in QUALITY
    	initParameters.depth_mode = sl::DEPTH_MODE_QUALITY;
    }

    if(unit == 0)	{
    	// set meter as the OpenGL world will be in meters
    	initParameters.coordinate_units = sl::UNIT_METER; 
    }

    if(coordSys == 0)	{
    	// OpenGL's coordinate system is right_handed
    	initParameters.coordinate_system = sl::COORDINATE_SYSTEM_RIGHT_HANDED_Y_UP; 
    }

    sl::ERROR_CODE err = zed.open(initParameters);
    if (err != sl::SUCCESS) {
    	std::cerr << "Error: " << errorCode2str(err) << "\n";
		zed.close();
    	exit(err);
    }

}

StereoLabsZED::~StereoLabsZED()	{
	// free buffer and close ZED
    //depth_image.free(sl::MEM_CPU);
    //point_cloud.free(sl::MEM_GPU);
	zed.close();
}

bool StereoLabsZED::captureFrame()	{
	return zed.grab(sl::SENSING_MODE_STANDARD) == sl::SUCCESS;
}

cv::Mat StereoLabsZED::getImage(sl::VIEW type)	{
	if(type == sl::VIEW_LEFT || type == sl::VIEW_RIGHT)	{
		sl::Mat temp;
		//get image with provided type
		zed.retrieveImage(temp, type);
		return cv::Mat(temp.getHeight(), temp.getWidth(), CV_8UC4, temp.getPtr<sl::uchar1>(sl::MEM_CPU));
	}
	else if(type == sl::VIEW_DEPTH)	{
		sl::Mat temp;
		//get image for depth
    		zed.retrieveImage(temp, sl::VIEW_DEPTH);
    		return cv::Mat(temp.getHeight(), temp.getWidth(), CV_8UC4, temp.getPtr<sl::uchar1>(sl::MEM_CPU));
	}
	else	{
		//get side by side image
		sl::Resolution imageResolution = getResolution();
		cv::Mat sbs_image(imageResolution.height, imageResolution.width * 2, CV_8UC4);
		cv::Mat left_image(sbs_image, cv::Rect(0, 0, imageResolution.width, imageResolution.height));
		cv::Mat right_image(sbs_image, cv::Rect(imageResolution.width, 0, imageResolution.width, imageResolution.height));

		sl::Mat tmp_sl;
		cv::Mat tmp_cv;

		zed.retrieveImage(tmp_sl, sl::VIEW_LEFT);
		tmp_cv = cv::Mat(tmp_sl.getHeight(), tmp_sl.getWidth(), CV_8UC4, tmp_sl.getPtr<sl::uchar1>(sl::MEM_CPU));
		tmp_cv.copyTo(left_image);
		zed.retrieveImage(tmp_sl, sl::VIEW_RIGHT);
		tmp_cv = cv::Mat(tmp_sl.getHeight(), tmp_sl.getWidth(), CV_8UC4, tmp_sl.getPtr<sl::uchar1>(sl::MEM_CPU));
		tmp_cv.copyTo(right_image);
		//cv::cvtColor(sbs_image, sbs_image, CV_RGBA2RGB);
		return sbs_image;
	}
}

void StereoLabsZED::computePointCloud()	{
	sl::Mat pointCloud;
	//get measurement in XYZRGBA format
	zed.retrieveMeasure(pointCloud, sl::MEASURE_XYZRGBA);
	//clear the point cloud container
	pointCloud3D->clear();
	//std::cout << pointCloud.getHeight() << "\n";

	float *p_data_cloud = pointCloud.getPtr<float>();
	
	if(p_data_cloud)	{
		// Check and adjust points for PCL format
		for(int i = 0; i < zed.getResolution().area(); i += 4)	{
			float X = p_data_cloud[i];
			if(isValidMeasure(X))	{
				pointCloud3D->push_back(pcl::PointXYZRGB());
				pointCloud3D->back().x = X;
				pointCloud3D->back().y = p_data_cloud[i + 1];
				pointCloud3D->back().z = p_data_cloud[i + 2];
				pointCloud3D->back().rgb = convertColor(p_data_cloud[i + 3]);
			}
		}	
	}
}

sl::Resolution StereoLabsZED::getResolution()	{
	return zed.getResolution();
}

boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGB> > StereoLabsZED::getPointCloud()	{
	return pointCloud3D;
}

unsigned char StereoLabsZED::getColor(float color, int index)	{
	//Cast color to unsigned int
	uint32_t color_uint = *(uint32_t*)& color;
	unsigned char* color_uchar = (unsigned char*)&color_uint;
	
	//red = 0
	//green = 1
	//blue = 2	
	return color_uchar[index];
}
/**
*  This function convert a RGBA color packed into a packed RGBA PCL compatible format
**/
inline float StereoLabsZED::convertColor(float colorIn) {
    uint32_t color_uint = *(uint32_t*)& colorIn;
    unsigned char* color_uchar = (unsigned char*)&color_uint;
    color_uint = ((uint32_t)color_uchar[0] << 16 | (uint32_t)color_uchar[1] << 8 | (uint32_t)color_uchar[2]);
    return *reinterpret_cast<float*> (&color_uint);
}

