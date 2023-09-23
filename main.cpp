#include "Transmition/transmitter.h"
#include "Receiving/Receiver.h"
//Transmition/Coder.cpp Transmition/TextCoder.cpp 

#include <cstdio>
#include <time.h>
#include <iostream>
//#include "Receiving\\FFT.cpp"

int main(){

    clock_t tStart = clock();
    

    const char filename_in[] = {"/home/yurock/Workspace/NAVTEX/TEST/text.txt"};
    const char filename_out[] = {"/home/yurock/Workspace/NAVTEX/TEST/Modulated.txt"};
    const char filename_in2[] = {"/home/yurock/Workspace/NAVTEX/TEST/Modulated.txt"};
    const char filename_out2[] = {"/home/yurock/Workspace/NAVTEX/TEST/text2.txt"};

    //Transmition(filename_in, filename_out);

    //int z = Receiver(filename_in2,filename_out2);

    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);  

    return 0;
}