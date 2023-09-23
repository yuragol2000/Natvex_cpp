#include  "hilbert.h"

std::vector<std::complex<double>> Hilbert(const std::vector<double> xr){

    std::cout << "Hilbert START" << std::endl;

    int n = xr.size();
    std::cout << n << std::endl;


    
    double* x = new double[n]();
    for (size_t i = 0; i < n; i++)
    {
        x[i] = xr[i];
    }


  

    std::vector<std::complex<double>> y = FFT(xr,n);

    std::vector<std::complex<double>> m = IFFT(y,n);


    std::cout << "Hilbert End" << std::endl;

    return m;
}