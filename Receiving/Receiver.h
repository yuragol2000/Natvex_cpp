#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>


#include "INIReader.h"

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
    std::string CONFIG_FILE = "CONF/navtex_receiving.conf";
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

    std::string Decoder(std::vector<bool>);
    int Phasing(const std::vector<bool> );

    std::string Text_Decoder(const std::vector<int> DX , const std::vector<int> RX);
    std::vector<bool> IncoherentReception(const std::vector<short> );
    std::string Compare(std::string DX, std::string RX);
    bool AlphaCheck(const std::vector<bool> demodulated);

    std::tuple<std::vector<int>,std::vector<int>> Simb_Decoder(const std::vector<bool> demodulated);

    void Write_text();
    int Write_text_to_file(const std::string,const std::string);
    void Write_bin();
    int Rec();
    int Read_from_file();
    Receiver();
    ~Receiver();
};