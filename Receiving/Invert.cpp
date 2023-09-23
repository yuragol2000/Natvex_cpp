#include <vector>

std::vector<bool> Invert(const std::vector<bool> demodulated){

    std::vector<bool> demodulated_invert;

    for (int i = 0; i < demodulated.size(); i++)
    {
        demodulated_invert.push_back(!demodulated[i]);
    }
    
    return demodulated_invert;
}