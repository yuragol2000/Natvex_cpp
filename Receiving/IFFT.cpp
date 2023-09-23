#include "IFFT.h"

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

