#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

#include "INIReader.h"
#include "Coder.h"
#include "Modulation.h"
#include "Writing.h"
#include "Reading_file.h"


struct threads_control
{

};

struct settings
{
    std::string IMPUT_TEXT_FILE;
    std::string OUTPUT_TEXT_FILE;
    std::string CONFIG_FILE = "/home/yurock/Workspace/NAVTEX/CONF/navtex_transmition.conf";
    std::string LOG_FILE;
    
    bool TYPE_OF_CODER = 0;

    unsigned int LEN_OF_READING_BUFFER;
    unsigned int LEN_OF_CODING_BUFFER;
    unsigned int LEN_OF_MODULATING_BUFFER;

};
struct reading
{
    char* text_buffer_1;
    char* text_buffer_2;
    char* text_buffer_3;

    unsigned int reading_position = 0;
    unsigned int num_to_print = 0;
};
struct coding
{
    std::vector<bool> codered_buffer_1;
    std::vector<bool> codered_buffer_2;
    std::vector<bool> codered_buffer_3;

};
struct modulating
{
    std::vector<double> modulated_buffer_1;
    std::vector<double> modulated_buffer_2;
    std::vector<double> modulated_buffer_3;
};
class Transmitter
{
public:
    settings Settings;

    reading Reading;
    coding Coding;
    modulating Modulating;

    int Z = 0  ;

    
    int LoadConf(const std::string);
    Transmitter(const std::string);

    void Reader();
    void _Coder();
    void Modulator();

    void Log(const std::string);
    int Trans();
    void Write_text();
    int Write_text_to_file(const std::string,const std::string);
    void Write_bin();
    int Read_from_file(std::string);
    Transmitter();
    ~Transmitter();
};