#include <unistd.h> // sleep()
#include <stdio.h>  // fopen(), fclose(), fprintf(), perror()
#include <stdlib.h> // exit() and EXIT_FAILURE
#include <iostream>

using namespace std;

int main()
{
    char vel = '80';
    char data[] =;
    while (1){

        FILE *file;
        if( NULL == (file = fopen("/dev/ttyUSB1", "w") ) )  //Opening device file
        { // then fopen failed
            perror("fopen failed for serial" );
            exit( EXIT_FAILURE );
        }

        // implied else, fopen successful

        int i = 0;
        //for(i = 0 ; i < 1 ; i++){
            if( 0 >= fprintf(file, "%s", data)) //Writing to the file
            { // fprintf failed
                perror("fprintf data failed" );
                exit( EXIT_FAILURE );
            }

            // implied else, fprintf successful for data

            /*if( 0 >= fprintf(file,"%c",',') ) //To separate digits
            { // then, fprintf failed
                perror( "fprintf for comma failed");
                exit( EXIT_FAILURE );
            }*/

            // implied else, fprintf successful for comma

            sleep(1);
        //} // end for
        fclose(file);

    }
    return(0);
} // end function: main