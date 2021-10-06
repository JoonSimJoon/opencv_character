#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"
using namespace cv;
using namespace std;


//Mat::zeros(int rows, int cols, int type);
// start point = 150,150
// 1px = 3*3
int arr[32][32] = { 0, };

void Init(int arr[][32], int size);
void Make(int arr[][32], int size);
void Coloring(Mat *tmp, int arr[][32], int size);
void Print_Mat(Mat* tmp);
int main(int argc, char** argv) {

	//create image window
	namedWindow("image", 1);

	//create test Mat, 400 x 400
	Mat testMat = Mat::zeros(900, 900, CV_8UC3);
	Init(arr, 32);
	Make(arr, 32);
	Coloring(&testMat, arr, 32);
	Print_Mat(&testMat);

	//close all windows
	destroyAllWindows();

	return 0;
}
void Init(int arr[][32], int size) {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			arr[i][j] = 0;
		}
	}
}

void Make(int arr[][32], int size) {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			//arr[i][j] = 1;
		}
	}
	arr[15][15] = 1;
}

void Coloring(Mat *tmp, int arr[][32], int size) {
	Mat mat = *tmp;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			if (arr[i][j] == 1) {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						mat.at<Vec3b>(Point(y+i*5+150, x+j*5+150)) = Vec3b(255, 100, 100);
					}
				}
			}
		}
	}
}

void Print_Mat(Mat* tmp){
	Mat mat = *tmp;
	//write text
	putText(mat, "HI!!", cvPoint(80, 100),FONT_HERSHEY_PLAIN, 3, cvScalar(0, 255, 255), 4); 
	for (int i = 145; i < 755; i++) {
		for (int j = 0; j < 5; j++) {
			mat.at<Vec3b>(Point(i, 145 + j)) = Vec3b(125, 50, 100);
			mat.at<Vec3b>(Point(145 + j, i)) = Vec3b(125, 50, 100);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
		}
	}
	for (int i = 145; i < 755; i++) {
		for (int j = 0; j < 5; j++) {
			mat.at<Vec3b>(Point(i, 755 + j)) = Vec3b(125, 50, 100);
			mat.at<Vec3b>(Point(755 + j, i)) = Vec3b(125, 50, 100);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
		}
	}
	mat.at<Vec3b>(Point(150, 150)) = Vec3b(255, 100, 100);

	//show image
	imshow("image", mat);
	waitKey(0);
}
