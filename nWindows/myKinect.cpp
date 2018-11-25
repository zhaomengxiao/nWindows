#include "myKinect.h"



/// Initializes the default Kinect sensor
HRESULT myKinect::InitializeDefaultSensor()
{
	//�����ж�ÿ�ζ�ȡ�����ĳɹ����
	HRESULT hr;

	//����kinect
	hr = GetDefaultKinectSensor(&m_pKinectSensor);
	if (FAILED(hr)) {
		return hr;
	}

	//�ҵ�kinect�豸
	if (m_pKinectSensor)
	{
		// Initialize the Kinect and get coordinate mapper and the body reader
		IBodyFrameSource* pBodyFrameSource = NULL;//��ȡ�Ǽ�
		IDepthFrameSource* pDepthFrameSource = NULL;//��ȡ�����Ϣ
		IBodyIndexFrameSource* pBodyIndexFrameSource = NULL;//��ȡ������ֵͼ

															//��kinect
		hr = m_pKinectSensor->Open();

		//coordinatemapper
		if (SUCCEEDED(hr))
		{
			hr = m_pKinectSensor->get_CoordinateMapper(&m_pCoordinateMapper);
		}

		//bodyframe
		if (SUCCEEDED(hr))
		{
			hr = m_pKinectSensor->get_BodyFrameSource(&pBodyFrameSource);
		}

		if (SUCCEEDED(hr))
		{
			hr = pBodyFrameSource->OpenReader(&m_pBodyFrameReader);
		}

		//depth frame
		if (SUCCEEDED(hr)) {
			hr = m_pKinectSensor->get_DepthFrameSource(&pDepthFrameSource);
		}

		if (SUCCEEDED(hr)) {
			hr = pDepthFrameSource->OpenReader(&m_pDepthFrameReader);
		}

		//body index frame
		if (SUCCEEDED(hr)) {
			hr = m_pKinectSensor->get_BodyIndexFrameSource(&pBodyIndexFrameSource);
		}

		if (SUCCEEDED(hr)) {
			hr = pBodyIndexFrameSource->OpenReader(&m_pBodyIndexFrameReader);
		}

		SafeRelease(pBodyFrameSource);
		SafeRelease(pDepthFrameSource);
		SafeRelease(pBodyIndexFrameSource);
	}

	if (!m_pKinectSensor || FAILED(hr))
	{
		std::cout << "Kinect initialization failed!" << std::endl;
		return E_FAIL;
	}

	//skeletonImg,���ڻ��Ǽܡ�������ֵͼ��MAT
	skeletonImg.create(cDepthHeight, cDepthWidth, CV_8UC3);
	skeletonImg.setTo(0);

	//depthImg,���ڻ������Ϣ��MAT
	depthImg.create(cDepthHeight, cDepthWidth, CV_8UC1);
	depthImg.setTo(0);

	return hr;
}

cv::Mat myKinect::getDepthImg()
{
	return depthImg;
}

cv::Mat myKinect::getSkeletonImg()
{
	return skeletonImg;
}



/// Main processing function
void myKinect::Update()
{
	//ÿ�������skeletonImg
	skeletonImg.setTo(0);

	//�����ʧ��kinect���򲻼�������
	if (!m_pBodyFrameReader)
	{
		return;
	}

	IBodyFrame* pBodyFrame = NULL;//�Ǽ���Ϣ
	IDepthFrame* pDepthFrame = NULL;//�����Ϣ
	IBodyIndexFrame* pBodyIndexFrame = NULL;//������ֵͼ

											//��¼ÿ�β����ĳɹ����
	HRESULT hr = S_OK;

	//---------------------------------------��ȡ������ֵͼ����ʾ---------------------------------
	if (SUCCEEDED(hr)) {
		hr = m_pBodyIndexFrameReader->AcquireLatestFrame(&pBodyIndexFrame);//��ñ�����ֵͼ��Ϣ
	}
	if (SUCCEEDED(hr)) {
		BYTE *bodyIndexArray = new BYTE[cDepthHeight * cDepthWidth];//������ֵͼ��8Ϊuchar�������Ǻ�ɫ��û���ǰ�ɫ
		pBodyIndexFrame->CopyFrameDataToArray(cDepthHeight * cDepthWidth, bodyIndexArray);

		//�ѱ�����ֵͼ����MAT��
		uchar* skeletonData = (uchar*)skeletonImg.data;
		for (int j = 0; j < cDepthHeight * cDepthWidth; ++j) {
			*skeletonData = bodyIndexArray[j]; ++skeletonData;
			*skeletonData = bodyIndexArray[j]; ++skeletonData;
			*skeletonData = bodyIndexArray[j]; ++skeletonData;
		}
		delete[] bodyIndexArray;
	}
	SafeRelease(pBodyIndexFrame);//����Ҫ�ͷţ�����֮���޷�����µ�frame����

								 //-----------------------��ȡ������ݲ���ʾ--------------------------
	if (SUCCEEDED(hr)) {
		hr = m_pDepthFrameReader->AcquireLatestFrame(&pDepthFrame);//����������
	}
	if (SUCCEEDED(hr)) {
		UINT16 *depthArray = new UINT16[cDepthHeight * cDepthWidth];//���������16λunsigned int
		pDepthFrame->CopyFrameDataToArray(cDepthHeight * cDepthWidth, depthArray);

		//��������ݻ���MAT��
		uchar* depthData = (uchar*)depthImg.data;
		for (int j = 0; j < cDepthHeight * cDepthWidth; ++j) {
			*depthData = depthArray[j];
			++depthData;
		}
		delete[] depthArray;
	}
	SafeRelease(pDepthFrame);//����Ҫ�ͷţ�����֮���޷�����µ�frame����
	//imshow("depthImg", depthImg);
	//cv::waitKey(5);
	//-----------------------------��ȡ�Ǽܲ���ʾ----------------------------
	if (SUCCEEDED(hr)) {
		hr = m_pBodyFrameReader->AcquireLatestFrame(&pBodyFrame);//��ȡ�Ǽ���Ϣ
	}
	if (SUCCEEDED(hr))
	{
		IBody* ppBodies[BODY_COUNT] = { 0 };//ÿһ��IBody����׷��һ���ˣ��ܹ�����׷��������

		if (SUCCEEDED(hr))
		{
			//��kinect׷�ٵ����˵���Ϣ���ֱ�浽ÿһ��IBody��
			hr = pBodyFrame->GetAndRefreshBodyData(_countof(ppBodies), ppBodies);
		}

		if (SUCCEEDED(hr))
		{
			//��ÿһ��IBody�������ҵ����ĹǼ���Ϣ�����һ�����
			ProcessBody(BODY_COUNT, ppBodies);
		}

		for (int i = 0; i < _countof(ppBodies); ++i)
		{
			SafeRelease(ppBodies[i]);//�ͷ�����
		}
	}
	SafeRelease(pBodyFrame);//����Ҫ�ͷţ�����֮���޷�����µ�frame����

}

//����ؽڽǶ�
double myKinect::AngleBetweenTowVectors(JointType jointA, JointType jointB, JointType jointC)
{

	/*double angle = 0.0;

	DirectX::XMVECTOR vBA = DirectX::XMVectorSubtract(vec[jointB], vec[jointA]);
	DirectX::XMVECTOR vBC = DirectX::XMVectorSubtract(vec[jointB], vec[jointC]);

	DirectX::XMVECTOR vAngle = DirectX::XMVector3AngleBetweenVectors(vBA, vBC);

	angle = DirectX::XMVectorGetX(vAngle) * 180.0 * DirectX::XM_1DIVPI;    // XM_1DIVPI: An optimal representation of 1 / ��

	return angle;*/
	return 0;
	
}

//����segCOM_ /Dampster
void myKinect::SegCOM(Eigen::Vector3f &segcom,Joint &jointP, Joint &jointD,const int &segNum)
{
	Eigen::Vector3f coordP(jointP.Position.X, jointP.Position.Y, jointP.Position.Z);
	Eigen::Vector3f coordD(jointD.Position.X, jointD.Position.Y, jointD.Position.Z);
	switch (segNum)
	{
	case 0://thigh
		segcom = coordP + (coordD - coordP)* 0.433;
		break;
	case 1://shank
		segcom = coordP + (coordD - coordP) * 0.433;
		break;
	case 2://foot
		segcom = coordP + (coordD - coordP) * 0.5;
		break;
	case 3://Upper arm
		segcom = coordP + (coordD - coordP) * 0.436;
		break;
	case 4://forearm and hand
		segcom = coordP + (coordD - coordP) * 0.682;
		break;
	case 5://Pelvis
		segcom = coordP + (coordD - coordP) * 0.105;
		break;
	case 6://Thorax and abdomen
		segcom = coordP + (coordD - coordP) * 0.63;
		break;
	case 7://Head and neck
		segcom = coordP + (coordD - coordP) * 1.0;
		break;
	default:
		break;
	}
	//forearm and hand
	segcom = coordP + (coordD - coordP) * 0.433;
}
//����bodyCOM
Eigen::Vector3f myKinect::BodyCOM(Eigen::Vector3f &thighcom_L, Eigen::Vector3f &thighcom_R, Eigen::Vector3f &shankcom_L,
	Eigen::Vector3f &shankcom_R, Eigen::Vector3f &footcom_L, Eigen::Vector3f &footcom_R, Eigen::Vector3f &upperArmCom_L, 
	Eigen::Vector3f &upperArmCom_R, Eigen::Vector3f &fArmHand_L, Eigen::Vector3f &fArmHand_R,
	Eigen::Vector3f &Pelvis, Eigen::Vector3f &ThoraxAbdomen, Eigen::Vector3f &Headneck)
{
	Eigen::Vector3f thigh_M(0, 0, 0.1), shank_M(0, 0, 0.0465), foot_M(0, 0, 0.0145),
		upperArm_M(0, 0, 0.028),fArmhand_M(0, 0, 0.022), Pelvis_M(0, 0, 0.142), ThoraxAbdomen_M(0, 0, 0.355),
		Headneck_M(0, 0, 0.081);
	Eigen::Vector3f BodyCOM = 
		  thighcom_L.cross(thigh_M) + thighcom_R.cross(thigh_M)
		+ shankcom_L.cross(shank_M) + shankcom_R.cross(shank_M)
		+ footcom_L.cross(foot_M) + footcom_R.cross(foot_M)
		+ upperArmCom_L.cross(upperArm_M) + upperArmCom_R.cross(upperArm_M)
		+ fArmHand_L.cross(fArmhand_M) + fArmHand_R.cross(fArmhand_M)
		+ Pelvis.cross(Pelvis_M) + ThoraxAbdomen.cross(ThoraxAbdomen_M) + Headneck.cross(Headneck_M);
	return BodyCOM;
}


Eigen::Vector3f myKinect::QuaternionToEuler(Eigen::Vector4f &quat)
{
	Eigen::Vector3f v(0.0, 0.0, 0.0);
	v.x() = atan2(2 * quat.x() * quat.w() - 2 * quat.x() * quat.z(),
		1 - 2 * pow(quat.y(), 2) - 2 * pow(quat.z(), 2));

	v.z() = asin(2 * quat.x() * quat.y() + 2 * quat.z() * quat.w());

	v.y() = atan2(2 * quat.x() * quat.w() - 2 * quat.y() * quat.z(),
		1 - 2 * pow(quat.x(), 2) - 2 * pow(quat.z(), 2));

	if (quat.x() * quat.y() + quat.z() * quat.w() == 0.5) {
		v.x() = (2 * atan2(quat.x(), quat.w()));
		v.y() = 0.;
	}
	else if (quat.x() * quat.y() + quat.z() * quat.w() == -0.5)
	{
		v.x() = (-2 * atan2(quat.x(), quat.w()));
		v.y() = 0.;
	}


	v.x() = RadianToDegree(v.x());
	v.y() = RadianToDegree(v.y());
	v.z() = RadianToDegree(v.z());

	return v;
}

//����XYZ����ת��-----------------------
float myKinect::getAngle_x()
{
	return angles.x();
}

float myKinect::getAngle_y()
{
	return angles.y();
}

float myKinect::getAngle_z()
{
	return angles.z();
}
//------------------------------------

double myKinect::RadianToDegree(double angle)
{
	return angle * (180.0 / PI) + 180;
}

bool myKinect::isAvailable()
{
	return false;
}

/// Handle new body data
void myKinect::ProcessBody(int nBodyCount, IBody** ppBodies)
{
	//��¼��������Ƿ�ɹ�
	HRESULT hr;

	//����ÿһ��IBody
	for (int i = 0; i < nBodyCount; ++i)
	{
		IBody* pBody = ppBodies[i];
		if (pBody)//��û�и���������pBody�������bTracked��ʲô����
		{
			BOOLEAN bTracked = false;
			hr = pBody->get_IsTracked(&bTracked);

			if (SUCCEEDED(hr) && bTracked)
			{
				//Joint joints[JointType_Count];//�洢�ؽڵ���
				//JointOrientation JointOrientations[JointType_Count];//�洢�ؽ���ת
				HandState leftHandState = HandState_Unknown;//����״̬
				HandState rightHandState = HandState_Unknown;//����״̬

															 //��ȡ������״̬
				pBody->get_HandLeftState(&leftHandState);
				pBody->get_HandRightState(&rightHandState);

				//�洢�������ϵ�еĹؽڵ�λ��
				DepthSpacePoint *depthSpacePosition = new DepthSpacePoint[_countof(joints)];
			
				//��ùؽڵ���
				hr = pBody->GetJoints(_countof(joints), joints);
				
				if (SUCCEEDED(hr))
				{
					
					//float angle = AngleBetweenTowVectors(JointType_WristRight, JointType_ElbowRight, JointType_ShoulderRight); // Get ElbowRight joint angle

					for (int j = 0; j < _countof(joints); ++j)
					{

						//���ؽڵ���������������ϵ��-1~1��ת���������ϵ��424*512��
						m_pCoordinateMapper->MapCameraPointToDepthSpace(joints[j].Position, &depthSpacePosition[j]);
					}

					//------------------------hand state left-------------------------------
					DrawHandState(depthSpacePosition[JointType_HandLeft], leftHandState);
					DrawHandState(depthSpacePosition[JointType_HandRight], rightHandState);

					//---------------------------body-------------------------------
					DrawBone(joints, depthSpacePosition, JointType_Head, JointType_Neck);
					DrawBone(joints, depthSpacePosition, JointType_Neck, JointType_SpineShoulder);
					DrawBone(joints, depthSpacePosition, JointType_SpineShoulder, JointType_SpineMid);
					DrawBone(joints, depthSpacePosition, JointType_SpineMid, JointType_SpineBase);
					DrawBone(joints, depthSpacePosition, JointType_SpineShoulder, JointType_ShoulderRight);
					DrawBone(joints, depthSpacePosition, JointType_SpineShoulder, JointType_ShoulderLeft);
					DrawBone(joints, depthSpacePosition, JointType_SpineBase, JointType_HipRight);
					DrawBone(joints, depthSpacePosition, JointType_SpineBase, JointType_HipLeft);

					// -----------------------Right Arm ------------------------------------ 
					DrawBone(joints, depthSpacePosition, JointType_ShoulderRight, JointType_ElbowRight);
					DrawBone(joints, depthSpacePosition, JointType_ElbowRight, JointType_WristRight);
					DrawBone(joints, depthSpacePosition, JointType_WristRight, JointType_HandRight);
					DrawBone(joints, depthSpacePosition, JointType_HandRight, JointType_HandTipRight);
					DrawBone(joints, depthSpacePosition, JointType_WristRight, JointType_ThumbRight);

					//----------------------------------- Left Arm--------------------------
					DrawBone(joints, depthSpacePosition, JointType_ShoulderLeft, JointType_ElbowLeft);
					DrawBone(joints, depthSpacePosition, JointType_ElbowLeft, JointType_WristLeft);
					DrawBone(joints, depthSpacePosition, JointType_WristLeft, JointType_HandLeft);
					DrawBone(joints, depthSpacePosition, JointType_HandLeft, JointType_HandTipLeft);
					DrawBone(joints, depthSpacePosition, JointType_WristLeft, JointType_ThumbLeft);

					// ----------------------------------Right Leg--------------------------------
					DrawBone(joints, depthSpacePosition, JointType_HipRight, JointType_KneeRight);
					DrawBone(joints, depthSpacePosition, JointType_KneeRight, JointType_AnkleRight);
					DrawBone(joints, depthSpacePosition, JointType_AnkleRight, JointType_FootRight);

					// -----------------------------------Left Leg---------------------------------
					DrawBone(joints, depthSpacePosition, JointType_HipLeft, JointType_KneeLeft);
					DrawBone(joints, depthSpacePosition, JointType_KneeLeft, JointType_AnkleLeft);
					DrawBone(joints, depthSpacePosition, JointType_AnkleLeft, JointType_FootLeft);

					//---------------------------------------------------------------------------------
					
					//ȡ��COM
					
					SegCOM(thighcom_L, joints[12], joints[13], 0);
					SegCOM(thighcom_R, joints[16], joints[17], 0);
					SegCOM(shankcom_L, joints[13], joints[14], 1);
					SegCOM(shankcom_R, joints[17], joints[18], 1);
					SegCOM(footcom_L, joints[14], joints[15], 2);
					SegCOM(footcom_R, joints[18], joints[19], 2);
					SegCOM(upperArmCom_L, joints[4], joints[5], 3);
					SegCOM(upperArmCom_R, joints[8], joints[9], 3);
					SegCOM(fArmHand_L, joints[5], joints[6], 4);
					SegCOM(fArmHand_R, joints[9], joints[10], 4);
					SegCOM(Pelvis, joints[1], joints[0], 5);
					SegCOM(ThoraxAbdomen, joints[20], joints[1], 6);
					SegCOM(Headneck, joints[3], joints[20], 7);

					segCOMs[0] = thighcom_L; segCOMs[1] = thighcom_R; segCOMs[2] = shankcom_L; segCOMs[3] = shankcom_R; segCOMs[4] = footcom_L; segCOMs[5] = footcom_R; segCOMs[6] = upperArmCom_L;
					segCOMs[7] = upperArmCom_R; segCOMs[8] = fArmHand_L; segCOMs[9] = fArmHand_R; segCOMs[10] = Pelvis; segCOMs[11] = ThoraxAbdomen; segCOMs[12] = Headneck;

					
					myCOM =
						BodyCOM(thighcom_L, thighcom_R, shankcom_L, shankcom_R, footcom_L, footcom_R, upperArmCom_L, upperArmCom_R, fArmHand_L, fArmHand_R, Pelvis, ThoraxAbdomen, Headneck);
					//std::cout << myCOM.x() << "," << myCOM.y() << "," << myCOM.z() << "," << std::endl;
				}
				delete[] depthSpacePosition;
				
				
				//---------test -------------------




				//-----------------------test
				//��ùؽ���ת
				hr = pBody->GetJointOrientations(_countof(joints), JointOrientations);
				if (SUCCEEDED(hr))
				{
					/*quats.w() = JointOrientations[jointnumber].Orientation.w;
					quats.x() = JointOrientations[jointnumber].Orientation.x;
					quats.y() = JointOrientations[jointnumber].Orientation.y;
					quats.z() = JointOrientations[jointnumber].Orientation.z;
					Eigen::Matrix3f Rx = quats.toRotationMatrix();
					Eigen::Vector3f ea1 = Rx.eulerAngles(0, 1, 2);*/
					//std::cout << quats.w() << "," << quats.x() << "," << quats.y() << quats.z() << std::endl;
					quatshow[0] = JointOrientations[jointnumber].Orientation.x;
					quatshow[1] = JointOrientations[jointnumber].Orientation.y;
					quatshow[2] = JointOrientations[jointnumber].Orientation.z;
					quatshow[3] = JointOrientations[jointnumber].Orientation.w;
					angles = QuaternionToEuler(quatshow);
					//����quat
					//for (int i = 0; i < JointType_Count; i++)
					//{
					//	quat[0] = JointOrientations[i].Orientation.x;
					//	quat[1] = JointOrientations[i].Orientation.y;
					//	quat[2] = JointOrientations[i].Orientation.z;
					//	quat[3] = JointOrientations[i].Orientation.w;

					//	/*quat << JointOrientations[i].Orientation.x,
					//			JointOrientations[i].Orientation.y,
					//			JointOrientations[i].Orientation.z,
					//			JointOrientations[i].Orientation.w;*/
					//	quatstream.push_back(quat);
					//}
					//Eigen::Vector4f quats = quatstream[jointnumber];
					//angles = QuaternionToEuler(quats);
					
					//angles = ea1;
					//std::cout << angles.x() << "," << angles.y() << "," << angles.z() << std::endl;
					//д��CSV�ĵ�
					//std::cout << angles  << std::endl;
					//csvfile.open("data.csv", std::ios::out);
					//csvfile << angles.x() <<"," <<angles.y() << "," <<angles.z()<<std::endl;
					
				}
			}
		}
	}
	//cv::imshow("skeletonImg", skeletonImg);
	//cv::waitKey(5);
}

//���ֵ�״̬
void myKinect::DrawHandState(const DepthSpacePoint depthSpacePosition, HandState handState)
{
	//����ͬ�����Ʒ��䲻ͬ��ɫ
	CvScalar color;
	switch (handState) {
	case HandState_Open:
		color = cvScalar(255, 0, 0);
		break;
	case HandState_Closed:
		color = cvScalar(0, 255, 0);
		break;
	case HandState_Lasso:
		color = cvScalar(0, 0, 255);
		break;
	default://���û��ȷ�������ƣ��Ͳ�Ҫ��
		return;
	}

	circle(skeletonImg,
		cvPoint(depthSpacePosition.X, depthSpacePosition.Y),
		20, color, -1);
}


/// Draws one bone of a body (joint to joint)
void myKinect::DrawBone(const Joint* pJoints, const DepthSpacePoint* depthSpacePosition, JointType joint0, JointType joint1)
{
	TrackingState joint0State = pJoints[joint0].TrackingState;
	TrackingState joint1State = pJoints[joint1].TrackingState;

	// If we can't find either of these joints, exit
	if ((joint0State == TrackingState_NotTracked) || (joint1State == TrackingState_NotTracked))
	{
		return;
	}

	// Don't draw if both points are inferred
	if ((joint0State == TrackingState_Inferred) && (joint1State == TrackingState_Inferred))
	{
		return;
	}

	CvPoint p1 = cvPoint(depthSpacePosition[joint0].X, depthSpacePosition[joint0].Y),
		p2 = cvPoint(depthSpacePosition[joint1].X, depthSpacePosition[joint1].Y);

	// We assume all drawn bones are inferred unless BOTH joints are tracked
	if ((joint0State == TrackingState_Tracked) && (joint1State == TrackingState_Tracked))
	{
		//�ǳ�ȷ���ĹǼܣ��ð�ɫֱ��
		line(skeletonImg, p1, p2, cvScalar(255, 255, 255));
	}
	else
	{
		//��ȷ���ĹǼܣ��ú�ɫֱ��
		line(skeletonImg, p1, p2, cvScalar(0, 0, 255));
	}
}


/// Constructor
myKinect::myKinect() :
	m_pKinectSensor(NULL),
	m_pCoordinateMapper(NULL),
	m_pBodyFrameReader(NULL) {
	csvfile.open("data.csv", std::ios::out);
}

/// Destructor
myKinect::~myKinect()
{
	SafeRelease(m_pBodyFrameReader);
	SafeRelease(m_pCoordinateMapper);

	if (m_pKinectSensor)
	{
		m_pKinectSensor->Close();
	}
	SafeRelease(m_pKinectSensor);
	csvfile.close();
}

