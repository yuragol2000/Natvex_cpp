#include  "hilbert.h"
/**
 *  \brief Discrete-time analytic signal using Hilbert transform
 * 
 *  
 *  \param[in] xr Input signal, specified as a real-valued vector or matrix. If xr is complex, then hilbert ignores its imaginary part.
 * 
 *  \return returns the analytic signal, x, from a real data sequence, xr. If xr is a matrix, then hilbert finds the analytic signal corresponding to each column.
 * 
 * 
*/
std::vector<std::complex<double>> Hilbert(const std::vector<double> xr){

    int n = xr.size();
    
    double* x = new double[n]();
    
    for (size_t i = 0; i < n; i++)
    {
        x[i] = xr[i];
    }

    std::vector<std::complex<double>> y = FFT(xr,n);
    std::vector<std::complex<double>> m = IFFT(y,n);

    return m;
}