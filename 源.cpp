#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("1.jpeg");
	Mat img2 = imread("2.jpeg");
	Mat img3 = imread("3.jpeg");
	Mat img4 = imread("4.jpeg");


	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat gray2;
	cvtColor(img2, gray2, COLOR_BGR2GRAY);
	Mat gray3;
	cvtColor(img3, gray3, COLOR_BGR2GRAY);
	Mat gray4;
	cvtColor(img4, gray4, COLOR_BGR2GRAY);

	Mat binary;
	threshold(gray, binary, 100, 255, THRESH_BINARY);
	Mat binary2;
	threshold(gray2, binary2, 54, 255, THRESH_BINARY);
	Mat binary3;
	threshold(gray3, binary3, 125, 255, THRESH_BINARY);
	Mat binary4;
	threshold(gray4, binary4, 130, 255, THRESH_BINARY);

	vector<vector<Point>>contours;
	vector<vector<Point>>contours2;
	vector<vector<Point>>contours3;
	vector<vector<Point>>contours4;

	findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	findContours(binary2, contours2, RETR_TREE, CHAIN_APPROX_SIMPLE);
	findContours(binary3, contours3, RETR_TREE, CHAIN_APPROX_SIMPLE);
	findContours(binary4, contours4, RETR_TREE, CHAIN_APPROX_SIMPLE);


	for (int i = 0;i < contours.size();i++)
	{
		double area = contourArea(contours[i]);//�����������
		if (area < 300 || area>310)
		{
		//��������С������
			continue;
		}
		Rect rect = boundingRect(contours[i]);//ȡһ�����ε��������ͣ�����������Ӿ���
		rectangle(img, rect, Scalar(2, 0, 255), 2);

	}

	for (int i = 0;i < contours2.size();i++)
	{
		double area = contourArea(contours2[i]);//�����������
		if (area <3300||area>3500)
		{
		//��������С������
			continue;
		}
		Rect rect = boundingRect(contours2[i]);//ȡһ�����ε��������ͣ�����������Ӿ���
		rectangle(img2, rect, Scalar(2, 0, 255), 2);

	}

	for (int i = 0;i < contours3.size();i++)
	{
		double area = contourArea(contours3[i]);//�����������
		if (area < 190 || area>195)
		{
			//��������С������
			continue;
		}
		Rect rect = boundingRect(contours3[i]);//ȡһ�����ε��������ͣ�����������Ӿ���
		rectangle(img3, rect, Scalar(2, 0, 255), 2);

	}
	for (int i = 0;i < contours4.size();i++)
	{
		double area = contourArea(contours4[i]);//�����������
		if (area < 800 || area>900)
		{
			//��������С������
			continue;
		}
		Rect rect = boundingRect(contours4[i]);//ȡһ�����ε��������ͣ�����������Ӿ���
		rectangle(img4, rect, Scalar(2, 0, 255), 2);

	}

	namedWindow("car1", WINDOW_NORMAL);
	resizeWindow("car1", img.size());
	imshow("car1", img);

	namedWindow("car2", WINDOW_NORMAL);
	resizeWindow("car2", img2.size());
	imshow("car2",img2);
	namedWindow("car3", WINDOW_NORMAL);
	resizeWindow("car3", img3.size());
	imshow("car3", img3);
	namedWindow("car4", WINDOW_NORMAL);
	resizeWindow("car4", img4.size());
	imshow("car4",img4);

	waitKey(0);
	return 0;
}

//ͼƬԤ������ɻҶ�ͼ����ɶ�ֵͼ��������
//canny(),��ʴ���ͣ���˹ģ��������֪����ô��
//����������ɸѡ�������С�����������͹�ȣ��������/���������ƽ��
//չʾͼƬ