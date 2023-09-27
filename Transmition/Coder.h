#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "TextCoder.h"
#include "Invert.h"
#include "Transmitter.h"



const std::vector<bool> PhasingSign_1 = {0,0,0,0,1,1,1}; 
const std::vector<bool> PhasingSign_2 = {1,0,0,1,1,0,0}; 

const std::vector<bool> Sign27 = {1,1,1,0,0,0,0}; //Carriage return
const std::vector<bool> Sign28 = {1,1,0,0,1,0,0}; // /n

const int Phasing_initial_num = 20;  
const int Phasing_final_num   = 60;  
