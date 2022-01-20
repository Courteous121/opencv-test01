#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("4.jpeg");

	vector<Mat> channels;//���� channels��ͨ������˼
	split(img, channels);//ͨ������,ͨ������֮����Ӧ��ɫ����Խ�߾�Խ��
	Mat blue = channels.at(0);




	Mat binary;
	threshold(blue, binary, 150, 255, THRESH_BINARY);

	vector<vector<Point>>contours;


	findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);



	for (int i = 0;i < contours.size();i++)
	{
		double area = contourArea(contours[i]);//�����������

		Rect rect = boundingRect(contours[i]);//ȡһ�����ε��������ͣ�����������Ӿ���
		if ((float)rect.height / (float)rect.width < 0.3 || (float)rect.height / (float)rect.width>0.4)
		{
			continue;
		}
		if ((float)rect.height * (float)rect.width < 2000 || (float)rect.height * (float)rect.width>10000)
		{
			continue;
		}
		rectangle(img, rect, Scalar(2, 0, 255), 2);

	}



	namedWindow("car1", WINDOW_NORMAL);
	resizeWindow("car1", img.size());
	imshow("car1", img);


	waitKey(0);
	return 0;
}

