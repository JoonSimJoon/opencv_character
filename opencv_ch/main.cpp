#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"
#include "Init.h"
#include "Coloring.h"
#include "Print.h"
using namespace cv;
using namespace std;


//Mat::zeros(int rows, int cols, int type);
int arr[64][64] = { 0, };

int main(int argc, char** argv) {

	//create image window
	namedWindow("image", 1);

	//create test Mat, 900 x 900
	Mat testMat = Mat::zeros(900, 900, CV_8UC3);
	Init_Map(arr, 64);
	ColorMap(&testMat, arr, 64);
	Print_Mat(&testMat);

	//close all windows
	destroyAllWindows();

	return 0;
}

