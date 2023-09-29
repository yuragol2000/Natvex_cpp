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

/**
 *  \brief The Receiver class is used for careful use of its features
 *  \date 09.2023
 * 
*/
class Receiver
{
public:
    Receiver(const std::string);
    Receiver();
    ~Receiver();

    int Rec();

    int Reader();
    int _Decoder();
    int Demodulator();
    int Write_text_to_file(const std::string,const std::string);

    int Read_from_file();
    int LoadConf(const std::string);
    int Log(const std::string);
    

private:
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
    struct errors
    {
        const int NO_ERROR = 0;
        const int CANT_OPEN_FILE = 1;
        const int FUNCTION_ERROR = 2;
        const int EOF_ERROR = 3;
    };

    settings Settings;
    modulation Modulation;
    demodulation Demodulation;
    receiving Receiving;
    errors Errors;


    

    std::string Decoder(std::vector<bool>);
    int Phasing(const std::vector<bool> );
    std::string Text_Decoder(const std::vector<int> DX , const std::vector<int> RX);
    std::string Compare(std::string DX, std::string RX);
    bool AlphaCheck(const std::vector<bool> demodulated);
    std::vector<bool> IncoherentReception(const std::vector<short> );
    std::tuple<std::vector<int>,std::vector<int>> Simb_Decoder(const std::vector<bool> demodulated);
   

};