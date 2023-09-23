#include <cctype>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <cmath>

const std::vector<bool> Sign27 = {1,1,1,0,0,0,0}; //Carriage return
const std::vector<bool> Sign28 = {1,1,0,0,1,0,0}; // /n

std::tuple<std::vector<int>,std::vector<int>> Simb_Decoder(const std::vector<bool> demodulated);
std::string Text_Decoder(const std::vector<int> ,const std::vector<int> );