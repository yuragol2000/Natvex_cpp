#pragma once

#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>

#include "Transmitter.h"

const double Smoothing_part = 0.5;

const int Fd = 100;                           // Character speed
const double Fs = 48000;                      // Sampling rate
const double  FsFd = Fs / Fd; 
const int Fp = 12000;
const int dFp = 170;


const double PI = 3.1415926535897;
