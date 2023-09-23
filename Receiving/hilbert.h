#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
#include <tuple>

#include "inversion.h"
#include "filter.h"
#include "FFT.h"
#include "IFFT.h"

std::vector<std::complex<double>> Hilbert(const std::vector<double> xr);
