#include "IFFT.h"
/**
 *  \brief Inverse fast Fourier transform
 * 
 *  \param[in] xr Input array, specified as a vector, a matrix, or a multidimensional array. If Y is of type single, then ifft natively computes in single precision, and X is also of type single. Otherwise, X is returned as type double.
 *  \param[in] n Inverse transform length, specified as [] or a nonnegative integer scalar. Padding Y with zeros by specifying a transform length larger than the length of Y can improve the performance of ifft. The length is typically specified as a power of 2 or a product of small prime numbers. If n is less than the length of the signal, then ifft ignores the remaining signal values past the nth entry and returns the truncated result. If n is 0, then ifft returns an empty matrix.
 * 
 *  \return returns the n-point inverse Fourier transform of Y by padding Y with trailing zeros to length n.
 * 
*/
std::vector<std::complex<double>> IFFT(std::vector<std::complex<double>>  xr,const int n){
    
    int N = n;
    int  Ncompl = N/2+1;

    fftw_complex* in = static_cast<fftw_complex*>(fftw_malloc(N*sizeof(fftw_complex)));
    fftw_complex* out = static_cast<fftw_complex*>(fftw_malloc(N*sizeof(fftw_complex)));

    fftw_plan p = fftw_plan_dft_1d(N, in, out,FFTW_BACKWARD,FFTW_ESTIMATE);

    in[0][REAL] = xr[0].real();
    in[0][IMAG] = xr[0].imag();


    for (size_t i = 1; i < Ncompl-1; i++)
    {
        in[i][REAL] = 2*xr[i].real();
        in[i][IMAG] = 2*xr[i].imag();
    }

    in[Ncompl-1][REAL] = xr[Ncompl-1].real();
    in[Ncompl-1][IMAG] = xr[Ncompl-1].imag();


    fftw_execute(p);
    

    std::vector<std::complex<double>> y = {};



    for (size_t m = 0; m < n; m++)
    {
        //std::cout << out[m][REAL]/n<< " " <<  out[m][IMAG]/n << std::endl;

        std::complex<double> temp (out[m][REAL]/n,out[m][IMAG]/n);
        y.push_back(temp);
    }



    fftw_destroy_plan( p );
    fftw_free(in);
    fftw_free(out);
    
    return y;    
}

