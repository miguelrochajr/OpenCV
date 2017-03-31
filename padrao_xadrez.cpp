#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/core.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat original, hsv, gray;
	cap >> original;
	namedWindow("Original",CV_WINDOW_AUTOSIZE);
	moveWindow("Original", original.size().height*1.5,0);
	int i = 0;

	while (1) {
		double fps = cap.get(CV_CAP_PROP_FPS);
		cap >> original;
		flip(original,original,1);
		cvtColor(original, hsv, CV_BGR2HSV);
		cvtColor(original, gray, CV_BGR2GRAY);

		hsv.at<Vec3b>((hsv.size().height)/2, (hsv.size().width)/2) = {0,0,0};

		Size patternSize = Size(7,11);
		vector<Point2f> corners;


		if (findChessboardCorners(gray, patternSize, corners, CALIB_CB_FAST_CHECK +
			CV_CALIB_CB_ADAPTIVE_THRESH)) {
			i++;
			cout << i << endl;

			cornerSubPix(gray, corners, Size(11,11), Size(-1,-1),
				TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 30, 0.1));

			drawChessboardCorners(original, patternSize, Mat(corners), true);
		}

		imshow("Original", original);

		if(waitKey(30) >= 0) break;
	}

    return 0;
}
