#include "Print.h"



void Print_Mat(Mat* tmp) {
	Mat mat = *tmp;
	//write text
	putText(mat, "HI!!", cvPoint(80, 100), FONT_HERSHEY_PLAIN, 3, cvScalar(0, 255, 255), 4);
	for (int i = 120; i < 780; i++) {
		for (int j = 0; j < 10; j++) {
			mat.at<Vec3b>(Point(i, 120 + j)) = Vec3b(204, 204, 204);
			mat.at<Vec3b>(Point(120 + j, i)) = Vec3b(204, 204, 204);
			mat.at<Vec3b>(Point(i, 770 + j)) = Vec3b(204, 204, 204);
			mat.at<Vec3b>(Point(770 + j, i)) = Vec3b(204, 204, 204);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
			//mat.at<Vec3b>(Point(i + j, 145)) = Vec3b(255, 100, 100);
		}
	}
	//show image
	imshow("image", mat);
	waitKey(0);
}
