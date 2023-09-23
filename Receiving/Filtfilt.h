#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

#include "inversion.h"
#include "filter.h"

std::vector<double> Filtfilt(const std::vector<double> ,const std::vector<double> ,const std::vector<double> );