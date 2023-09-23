#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>


#include "INIReader.h"
#include "IncoherentReception.h"
#include "Decoder.h"

struct threads_control
{

};
struct modulation{
    
    unsigned int reading_position = 0;

    std::vector<short> modulated_buf;
};
struct demodulation{

    std::vector<bool> demodulated_buf;
};

struct receiving{

    std::string received_text ;
};

struct settings
{
    std::string IMPUT_TEXT_FILE;
    std::string OUTPUT_TEXT_FILE;
    std::string CONFIG_FILE = "/home/yurock/Workspace/NAVTEX/CONF/navtex_receiving.conf";
    std::string LOG_FILE;
    
    bool TYPE_OF_CODER = 0;

    unsigned int LEN_OF_READING_BUFFER;

};
class Receiver
{
public:
    settings Settings;
    modulation Modulation;
    demodulation Demodulation;
    receiving Receiving;
    
    int Z = 0  ;

    
    int LoadConf(const std::string);
    Receiver(const std::string);

    void Reader();
    void _Decoder();
    void Demodulator();

    void Log(const std::string);
    
    void Write_text();
    int Write_text_to_file(const std::string,const std::string);
    void Write_bin();
    int Rec();
    int Read_from_file();
    Receiver();
    ~Receiver();
};