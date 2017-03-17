#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main (int argc, char** argv) {
	string imageName("Imagens/bandeirajapao.jpg"); 
    
    if (argc > 1) {
        imageName = argv[1];
    }
    
    Mat image;
    
    image = imread(imageName.c_str(), IMREAD_COLOR);

	namedWindow("Original", WINDOW_AUTOSIZE);
	moveWindow("Original", 0, 0);
	imshow("Original", image);

	// por fazer ainda


	waitKey();

	return 0;
}