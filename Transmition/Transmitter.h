#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

#include "INIReader.h"
#include "Modulation.h"



struct threads_control
{

};

struct settings
{
    std::string IMPUT_TEXT_FILE;
    std::string OUTPUT_TEXT_FILE;
    std::string CONFIG_FILE = "CONF/navtex_transmition.conf";
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

    bool start_reading = true;
    unsigned int reading_position = 0;
    unsigned int num_to_print = 0;
};
struct coding
{
    std::vector<bool> codered_buffer_1;
    std::vector<bool> codered_buffer_2;
    std::vector<bool> codered_buffer_3;

    std::vector<bool> codered_buffer_alpha = {0,0,0,0,1,1,1, 0,0,0,0,1,1,1};

};
struct modulating
{
    std::vector<double> modulated_buffer_1;
    std::vector<double> modulated_buffer_2;
    std::vector<double> modulated_buffer_3;
    std::vector<double> modulated_buffer_alpha ;
};
class Transmitter
{
public:
    settings Settings;

    reading Reading;
    coding Coding;
    modulating Modulating;

    int Z = 0  ;

    int Writing(std::vector<double>);
    int LoadConf(const std::string);
    Transmitter(const std::string);
    std::vector<bool> Coder(const char* ,const bool & );
    void Reader();
    void _Coder();
    void Modulator();

    void Log(const std::string);
    int Trans();
    int Alpha_init();
    int Alpha();
    void Write_text();
    void Write_bin();
    int Read_from_file(std::string);
    Transmitter();
    ~Transmitter();
};