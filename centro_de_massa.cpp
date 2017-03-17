#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){
    string imageName("Imagens/bandeirajapao.jpg"); 
    if( argc > 1){
        imageName = argv[1];
    }
    
    Mat image;
    
    image = imread(imageName.c_str(), IMREAD_COLOR);
    
    if(image.empty()){
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    
    namedWindow( "Display window", WINDOW_AUTOSIZE );
    imshow( "Display window", image );               
    waitKey(0);
    
    Mat_<Vec3b> copyImg = image;
    
    /*MatIterator_<Vec3b> it, end;
    for(it = copyImg.begin<Vec3b>(), end = copyImg.end<Vec3b>(); it != end; ++it){
        if (( int( (*it)[0] ) < 100) && ( int ( (*it)[1] ) < 100 ) && ( int( (*it)[2]) > 50)  ) {
            //cout << " " << int((*it)[0]) << " " << int((*it)[1]) << " " << int((*it)[2]) << endl;  
            cout << (*it) << endl;
            (*it)[0] = 200;
            (*it)[1] = 0;
            (*it)[2] = 200;
        }
    }*/
    
    bool red = false;
    int tam_y = 0; 
    int tam_x = 0;
    int maior_x = 0;
    bool nacabou = true;
    bool nprecisa = false;
    int centrox=0, centroy=0;
    
    for (int i = 0; i < copyImg.rows; ++i) {
        if (red) {
            tam_y++;
            red = false;
        }
        if (nacabou) {
            if (tam_x >= maior_x) {
                maior_x = tam_x;
            } else {
                nacabou = false;
            }
        }
        tam_x = 0;
        for (int j = 0; j < copyImg.cols; ++j) {
            if (copyImg(i,j)[2] > 200 && copyImg(i,j)[0] < 50 && copyImg(i,j)[1] < 50) {
                tam_x++;
                copyImg(i,j)[0] = 200;
                copyImg(i,j)[1] = 0;
                copyImg(i,j)[2] = 200;
                red = true;
                
                if (!nacabou && !nprecisa) {
                    copyImg(i,j)[0] = 0;
                    copyImg(i,j)[1] = 255;
                    copyImg(i,j)[2] = 0;
                    
                    centroy = j;
                    
                    nprecisa = true;
                }
                
            }
        }
    }
    
    bool sair = false;
    for (int i = 0; i < copyImg.rows && !sair; ++i) {
        for (int j = 0; j < copyImg.cols; ++j) {
            if (copyImg(i,j)[2] == 200 && copyImg(i,j)[0] == 200) {
                centrox = i + tam_y/2;                
                sair = true;
                break;
            }
        }         
    }
    
    centroy = centroy + maior_x/2;
    
    cout << "i = " << centrox << " j = " << centroy << endl;
    
    copyImg(centrox, centroy)[0] = 0;
    copyImg(centrox, centroy)[1] = 0;
    copyImg(centrox, centroy)[2] = 0;
    
    imshow( "Display window", copyImg );     
    
    waitKey(0); 

    
    return 0;
}