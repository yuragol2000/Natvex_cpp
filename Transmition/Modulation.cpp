/**
 *  \brief Frequency manipulation function
 * 
 *  \param[in] binarycode Binary codered signal
 * 
 *  \return s_fsk Frequency manipulated signal
 * 
*/
#include "Modulation.h"

std::vector<double> Transmitter::Modulation(const std::vector<bool> &binarycode){

    double f[2] = {Fp - dFp, Fp + dFp};                   // Manipulation frequencies
   
    std::vector<double> t = {};

    const unsigned int DIM2 = binarycode.size() * FsFd;

    for(double i = 0; i < DIM2; i++){
        t.push_back(i / Fs);
    }
    
    const unsigned int DIM1 = 2;

    std::vector<double> carriers = {} ;

    
    for(unsigned int i = 0; i < DIM1 * DIM2; i += 2){

        carriers.push_back(std::cos(2 * PI * t[i/2] * f[0]));
        carriers.push_back(std::cos(2 * PI * t[i/2] * f[1]));
    }

    std::vector<double> s_fsk = {};

    for(unsigned int i = 0; i < DIM2; i += FsFd){

        for(unsigned int j = 0; j < FsFd; j++){

            const bool bit = binarycode[i / FsFd];

            s_fsk.push_back(carriers[(i + j) * DIM1] * (1 - bit) + carriers[( i+ j) * DIM1 + 1] * bit);
        }

    }

    return s_fsk;
 }
