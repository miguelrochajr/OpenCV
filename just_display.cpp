#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv ){
	if( argc != 2){
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);  // Read the file

    /* 
        CV_LOAD_IMAGE_UNCHANGED (<0) loads the image as is (including the alpha channel if present)
        CV_LOAD_IMAGE_GRAYSCALE ( 0) loads the image as an intensity one
        CV_LOAD_IMAGE_COLOR (>0) loads the image in the BGR format
    */

    if(!image.data) {   // Check for invalid input
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow("Display window", WINDOW_AUTOSIZE );  // Create a window for display.
    imshow( "Display window", image );   // Show our image inside it.

    waitKey(0); 
	return 0;
}