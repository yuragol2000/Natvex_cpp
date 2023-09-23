#include <vector>
#include <iostream>

const std::vector<bool> PhasingSign_CB_1 = {0,0,0,0,1,1,1}; 
const std::vector<bool> PhasingSign_CB_2 = {1,0,0,1,1,0,0}; 

const std::vector<bool> PhasingSign_SB_1 = {1,1,1,1,0,0,0}; 
const std::vector<bool> PhasingSign_SB_2 = {0,1,1,0,0,1,1}; 

int Phasing(const std::vector<bool> demodulated);