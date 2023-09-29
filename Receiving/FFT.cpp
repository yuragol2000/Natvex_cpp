#include "FFT.h"


/**
 *  \brief Fast Fourier transform
 * 
 *  \param[in] xr  Input array, specified as a vector, matrix, or multidimensional array.
 *  \param[in] n Transform length, specified as [] or a nonnegative integer scalar. Specifying a positive integer scalar for the transform length can improve the performance of fft. The length is typically specified as a power of 2 or a value that can be factored into a product of small prime numbers (with prime factors not greater than 7). If n is less than the length of the signal, then fft ignores the remaining signal values past the nth entry and returns the truncated result. If n is 0, then fft returns an empty matrix.
 * 
 *  \return  returns the n-point DFT.
 *
*/

std::vector<std::complex<double>> FFT(std::vector<double> xr,const int n){
    
    int N = n;

    int  Ncompl = N/2+1;

    double*       in  = static_cast<double*>(fftw_malloc(N*sizeof(double)));
    fftw_complex* out = static_cast<fftw_complex*>(fftw_malloc(Ncompl*sizeof(fftw_complex)));

    fftw_plan p = fftw_plan_dft_r2c_1d(N, in, out,FFTW_ESTIMATE);

    for (size_t i = 0; i < N; i++)
    {
        in[i] = xr[i];
    }

    fftw_execute(p);
    

    std::vector<std::complex<double>> y ;

    //std::cout <<  sizeof(out)/sizeof(out[0])<< std::endl;

    for (size_t m = 0; m < Ncompl; m++)
    {
        //std::cout << out[m][REAL] << " " <<  out[m][IMAG] << std::endl;

        std::complex<double> temp (out[m][REAL],out[m][IMAG]);
        y.push_back(temp);
    }

    fftw_destroy_plan( p );
    fftw_free(in);
    fftw_free(out);

    return y;    
}




