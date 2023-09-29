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
 *  * To start the transfer, you need to configure the config file or use the available.
 * 
 *  * Next, you need to inform the new config file if it has been changed. To do this, write "conf" in the console and enter the path to the new config file.
 * 
 *  * Before sending, you need to add a file with a message. To transfer the necessary file, write to the console "tr" and the path to the desired file.
 * 
 *  * To restart the transmitter, you need to write "restart" to the console.
 * 
 *  * To stop the transmitter, you need to write "stop" to the console.
 * 
 *
*/

/*! \page ReceiverPage How to use Receiver?
 *
 *  * To start the reciving, you need to configure the config file or use the available.
 * 
 *  * Next, you need to inform the new config file if it has been changed. To do this, write "conf" in the console and enter the path to the new config file.
 * 
 *  * To restart the receiver, you need to write "restart" to the console.
 * 
 *  * To stop the receiver, you need to write "stop" to the console.
*/


/**
 *  \brief The Transmitter class is used for careful use of its features
 *  \date 09.2023
 * 
*/
class Transmitter
{
public:
    Transmitter(const std::string);
    Transmitter();
    ~Transmitter();

    int Trans();
    int Trans(std::string);
    
    int LoadConf(const std::string);
    int Write_text();
    int Writing(std::vector<double>);
    int _Modulator();
    int Alpha();
    int _Coder();
    int _Reader(std::string);
private:
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

    struct errors
    {
        const int NO_ERROR = 0;
        const int CANT_OPEN_FILE = 1;
        const int FUNCTION_ERROR = 2;
        const int EOF_ERROR = 3;
    };

    settings Settings;
    errors Errors;
    reading Reading;
    coding Coding;
    modulating Modulating;

    std::vector<double> Modulation(const std::vector<bool> &);
    std::vector<bool> Coder(const char* ,const bool & );
    int Read_from_file(std::string);
    int Log(const std::string);
    int Alpha_init();
    
    
};
//TEST/text.txt