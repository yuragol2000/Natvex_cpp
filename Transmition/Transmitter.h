#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

#include "INIReader.h"


/*! \mainpage NAVTEX
 *
 * This project helps user to use NAVTEX transmitter and receiver program realization.
 * 
 * 
 * - \subpage TransmitterPage "How to use Transmitter?"
 *
 * - \subpage ReceiverPage "How to use Receiver?"
 *
 */ 

/*! \page TransmitterPage How to use Transmitter?
 *
 * Lorem ipsum dolor sit amet
 *
 */

/*! \page ReceiverPage How to use Receiver?
 *
 * This page is about how to draw a circle.
 * Following sections describe circle:
 * - \ref groupCircleDefinition "Definition of Circle"
 * - \ref groupCircleClass "Circle Class"
 */



class Transmitter
{
public:
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

        bool start_reading = true;
        unsigned int reading_position = 0;
        unsigned int num_to_print = 0;
    };

    struct coding
    {
        std::vector<bool> codered_buffer_1;
        std::vector<bool> codered_buffer_alpha = {0,0,0,0,1,1,1, 0,0,0,0,1,1,1};

    };

    struct modulating
    {
        std::vector<double> modulated_buffer_1;
        std::vector<double> modulated_buffer_alpha ;
    };

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
    std::vector<double> Modulation(const std::vector<bool> &);
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