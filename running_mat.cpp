#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int, char**){
	Mat image;
  	Vec3b val;

	image = imread("imagem.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	if(!image.data)
		cout << "nao abriu imagem.jpg" << endl;

	namedWindow("Imagem", WINDOW_AUTOSIZE);

	for(int i=200;i<210;i++){
		for(int j=10;j<200;j++){
	    	image.at<uchar>(i,j) = 0;
	    }
	}

	imshow("Imagem", image);
	waitKey();

	image = imread("imagem.jpg", CV_LOAD_IMAGE_COLOR);

	val[0] = 0;   //B
	val[1] = 0;   //G
	val[2] = 255; //R

	for(int i=200;i<210;i++){
		for(int j=10;j<200;j++){
	    	image.at<Vec3b>(i,j)=val;
	    }
	}

	imshow("Imagem", image);
	waitKey();
	
	return 0;
}