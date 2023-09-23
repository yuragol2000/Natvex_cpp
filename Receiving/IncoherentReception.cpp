#include "IncoherentReception.h"


std::vector<bool> IncoherentReception(const std::vector<short> modulated){

    std::vector<double> binarycode_double;
    double temp = 0;
    
    for (size_t i = 0; i < modulated.size(); i++)
    {
        temp = static_cast<double>(modulated[i]);
        binarycode_double.push_back(temp/32767);
    }
    
    

    std::vector<double> filtered_high = Filtfilt(bh,ah,binarycode_double);
    std::vector<double> filtered_low   = Filtfilt(bl,al,binarycode_double);

    std::vector<std::complex<double>>  y_h  =  Hilbert(filtered_high);
    std::vector<std::complex<double>>  y_l  =  Hilbert(filtered_low);

    std::vector<double>  env_high;
    std::vector<double>  env_low;

    for (size_t i = 0; i < y_h.size(); i++)
    {
        env_high.push_back(abs(y_h[i]));
    }

    for (size_t i = 0; i < y_l.size(); i++)
    {
        env_low.push_back(abs(y_l[i]));
    }

    std::vector<bool> demodulated; 

    for (size_t i = 0; i < env_high.size(); i +=  FS/FD)
    {
        double sum_H =  0;
        double sum_L =  0; 

        for (size_t j = 0; j < FS/FD; j++)
        {
            sum_H += env_high[i+j];
            sum_L += env_low[i+j]; 
        }

        if (sum_H > sum_L)
        {
            demodulated.push_back(true);
        }
        else if (sum_H < sum_L)
        {
            demodulated.push_back(false);
        }
        else{
            std::cout << "ERROR" << std::endl;
        }
        
    }
    
    return demodulated;
}