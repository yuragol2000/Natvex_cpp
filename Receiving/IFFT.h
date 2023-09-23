# pragma once

#include <vector>
#include <iostream>
#include <complex>
#include "fftw3.h"
#include <memory.h>

#define REAL 0
#define IMAG 1

std::vector<std::complex<double>> IFFT(std::vector<std::complex<double>>  xr,const int N);