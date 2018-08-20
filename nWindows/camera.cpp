#include "camera.h"

QImage  Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;

}

camera::camera()
{
}


camera::~camera()
{
}

void camera::openCamera()
{
	// 1. Initial OpenNI
	if (openni::OpenNI::initialize()!= openni::STATUS_OK)
	{
		warningBox("OpenNI Initial Error: ");
	}

	// 2. Open Device
	if (mDevice.open(openni::ANY_DEVICE) != openni::STATUS_OK)
	{
		warningBox("Can't Open Device: ");
	}
}

void camera::createStream()
{
	// depth stream check
	if (mDevice.hasSensor(openni::SENSOR_DEPTH))
	{
		if (mDepthStream.create(mDevice, openni::SENSOR_DEPTH) == openni::STATUS_OK)
		{
			// 3a. set video mode
			
			mMode.setResolution(640, 480);
			mMode.setFps(30);
			mMode.setPixelFormat(openni::PIXEL_FORMAT_DEPTH_1_MM);

			if (mDepthStream.setVideoMode(mMode) != openni::STATUS_OK)
			{
				warningBox("Can't apply VideoMode: ");
			}
		}
		else
		{
			warningBox("Can't create depth stream on device: ");
		}
	}
	else
	{
		warningBox("ERROR: This device does not have depth sensor");
	}
	// color stream check
	if (mDevice.hasSensor(openni::SENSOR_COLOR))
	{
		if (mColorStream.create(mDevice, openni::SENSOR_COLOR) == openni::STATUS_OK)
		{
			// 4a. set video mode
			mMode.setResolution(640, 480);
			mMode.setFps(30);
			mMode.setPixelFormat(openni::PIXEL_FORMAT_RGB888);

			if (mColorStream.setVideoMode(mMode) != openni::STATUS_OK)
			{
				warningBox("Can't apply VideoMode: ");
			}

			// 4b. image registration
			if (mDevice.isImageRegistrationModeSupported(
				openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR))
			{
				mDevice.setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR);
			}
		}
		else
		{
			warningBox("Can't create color stream on device: ");
		}
	}
	else
	{
		warningBox("ERROR: This device does not have color sensor");
	}
	mDepthStream.start();
	mColorStream.start();
	int iMaxDepth = mDepthStream.getMaxPixelValue();
}

void camera::showImage()
{
	// 7. check is color stream is available
	if (mColorStream.isValid())
	{
		// 7a. get color frame
		if (mColorStream.readFrame(&mColorFrame) == openni::STATUS_OK)
		{
			// 7b. convert data to OpenCV format
			const cv::Mat mImageBGR(
				mColorFrame.getHeight(), mColorFrame.getWidth(),
				CV_8UC3, (void*)mColorFrame.getData());
			// 7c. convert form RGB to BGR
			
			cv::cvtColor(mImageBGR, cImageRGB, CV_BGR2RGB);
			// 7d. show image
			colorImage = Mat2QImage(cImageRGB);
		}
	}

	// 8a. get depth frame
	if (mDepthStream.readFrame(&mDepthFrame) == openni::STATUS_OK)
	{
		// 8b. convert data to OpenCV format
		const cv::Mat mImageDepth(
			mDepthFrame.getHeight(), mDepthFrame.getWidth(),
			CV_16UC1, (void*)mDepthFrame.getData());
		// 8c. re-map depth data [0,Max] to [0,255]
		mImageDepth.convertTo(mScaledDepth, CV_8U, 255.0 / 200.0);
		// 8d. show image
		depthImage = Mat2QImage(mScaledDepth);
	}
}

void camera::closeCamera()
{
	mDepthStream.destroy();
	mColorStream.destroy();
	mDevice.close();
	openni::OpenNI::shutdown();
}

bool camera::isnotclosed()
{
	if (mDevice.open(openni::ANY_DEVICE) != openni::STATUS_OK) {
		return false;
	}
	else
	{
		return true;
	}
	
}

void camera::warningBox(char* myMassage)
{
	QMessageBox massage(0);
	massage.setWindowTitle("vedio");
	const char* szTemp1 = openni::OpenNI::getExtendedError();
	char* szTemp2 = myMassage;
	const char* result = NULL;

	std::string temp = std::string(szTemp2) + std::string(szTemp1);
	result = temp.c_str();
	massage.setText(result);
	massage.setIconPixmap(QPixmap(":/myimages/Resources/cameraERROR.png"));
	massage.exec();
}
