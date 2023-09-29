#include "Transmitter.h"

/**
 *  \brief Default Constructor
 * 
 * Loads the default configuration (latest) and also allocates memory for an array of text.
 *   
 * 
*/
Transmitter::Transmitter(){

    LoadConf(Settings.CONFIG_FILE);    
    Log("\n\nClASS Created\n");
 

    Reading.text_buffer_1 = new char[Settings.LEN_OF_READING_BUFFER]();

    Log("filename_in - " + Settings.IMPUT_TEXT_FILE + "\n");
    Log("filename_out - " + Settings.OUTPUT_TEXT_FILE + "\n");
    Log("--------------------------------------------------------\n\n");

    Alpha_init();
}

/**
 *  \brief A constructor using a specific configuration file
 * 
 *  \param[in] configure_file
 * 
 *  After changing the configuration file, it runs  default Constructor
 * 
*/

Transmitter::Transmitter(const std::string configure_file)
{
    Settings.CONFIG_FILE = configure_file;
    std::cout << "Config file has changed to - " << configure_file << std::endl; 
    Transmitter();
}

/**
 *  \brief Default destructor   
 * 
 *  Destroys the buffer for text
*/
Transmitter::~Transmitter()
{

    delete  Reading.text_buffer_1;

    Log("CLASS Destracted\n");
}

/**
 *  \brief Method of loading the configuration file
 * 
 *  \param[in] conf_file_name
 * 
 *   Reads the necessary constants and variables and puts them in the transmitter class
 *  \warning When adding new variables, you need to change this method
 *  \return Errors
*/

int Transmitter::LoadConf(const std::string conf_file_name){
    
    Settings.CONFIG_FILE = conf_file_name;

    INIReader reader(Settings.CONFIG_FILE);

    Settings.IMPUT_TEXT_FILE = reader.GetString("IMPUT_PARAMETERS","IMPUT_TEXT_FILE","txt");
    Settings.OUTPUT_TEXT_FILE= reader.GetString("IMPUT_PARAMETERS","OUTPUT_TEXT_FILE","bin");

    Settings.LOG_FILE= reader.GetString("IMPUT_PARAMETERS","LOG_FILE","log");

    Settings.LEN_OF_READING_BUFFER = reader.GetInteger("TRANSMITTER_PARAMETERS","LEN_OF_READING_BUFFER",-1);

    std::ofstream clear_file;

    clear_file.open(Settings.OUTPUT_TEXT_FILE, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();

    clear_file.open(Settings.LOG_FILE, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();

    

    Log("LOAD Config FILE " + Settings.CONFIG_FILE +"\n");

    if (true)//TODO проверка на ошибки
    {
        return 0;
    }    
}
/**
 *  \brief Logging method
 * 
 *  \param[in] message Message to be placed in the log file
 * 
 *  \return Errors
 * 
 *  The location of the log file is stored in Settings.LOG_FILE
 * 
*/
int Transmitter::Log(const std::string message){

    std::ofstream log;
    log.open(Settings.LOG_FILE,std::ios_base::app);
    log.write(message.c_str(),message.length());
    log.close();
}


/**
 *  \brief Coding method with logging
 * 
 *  \return Errors
 * 
 *  When encoding, the size of the encoded message is written to the log file, and the text buffer is also cleared
 * 
*/
int Transmitter::_Coder(){
    
    Log("Coder \n");
    Coding.codered_buffer_1 = Coder(Reading.text_buffer_1,Settings.TYPE_OF_CODER);
    
    for (size_t i = 0; i < Settings.LEN_OF_READING_BUFFER; i++)
    {
        Reading.text_buffer_1[i] = '\0';
    }
    
    Log("Coding.codered_buffer_1 size = " + std::to_string(Coding.codered_buffer_1.size()) + '\n');

}
/**
 *  \brief The method of initialization of the idle alpha signal with logging 
 * 
 *  \return Errors
 * 
 * This method is run together with the class constructor or when the idle signal changes
 * 
*/
int Transmitter::Alpha_init(){
    Log("ALPHA init \n");
    Modulating.modulated_buffer_alpha = Modulation(Coding.codered_buffer_alpha);
    Log("Modulator.modulated_buffer_alpha size = " + std::to_string(Modulating.modulated_buffer_alpha.size()) + '\n');
    
}


/**
 *  \brief The method of transmitting an idle alpha signal
 *
 *  \return Errors   
 * 
 *  The modulated signal received when using the Alpha_init method is transmitted
 *   
 * 
*/
int Transmitter::Alpha(){
    Log("ALPHA \n");
    Writing(Modulating.modulated_buffer_alpha);

}
/**
 *  \brief Modulation method with logging
 * 
 *  \return Errors 
 *   
 *  Writes the result of the execution of the Modulation function and sends it to the Writing function
*/
int Transmitter::_Modulator(){
    Log("Modulator \n");
    Modulating.modulated_buffer_1 = Modulation(Coding.codered_buffer_1);
    Log("Modulator.modulated_buffer_1 size = " + std::to_string(Modulating.modulated_buffer_1.size()) + '\n');
    Writing(Modulating.modulated_buffer_1);

}
/**
 *  \brief Method of output to the console of the read text buffer
 *  
 *  \return Errors    
 * 
*/
int Transmitter::Write_text(){
    std::cout << Reading.text_buffer_1 << std::endl;
}
/**
 *  \brief The method of reading the text buffer
 * 
 *  \return Errors 
 *  
*/
int Transmitter::_Reader(std::string input_file_name){
    Read_from_file(input_file_name);
}


/**
 *  \brief The main method of transmission
 * 
 *  \return Errors  
 * 
 *   Starts the method of reading the text buffer, then encodes
    and modulates it. Then sends it to the output stream
 * 
*/
int Transmitter::Trans(){
    Log("\n");
    int read_ = Read_from_file(Settings.IMPUT_TEXT_FILE);
    if (read_ == 0)
    {

    }
    else if (read_ == 3)
    {
        Reading.start_reading = true;
        return 2;
    }
    else if (read_ == -1)
    {
        Log("ERROR\n");
        return -1;
    }
    _Coder();
    _Modulator();
    return 0;
}
/**
 *  \brief The main method of transmission a specific file
 * 
 *  \return Errors  
 * 
 *  \param[in] input_file_name 
 * 
 *   Starts the method of reading the text buffer, then encodes
    and modulates it. Then sends it to the output stream
 * 
*/
int Transmitter::Trans(std::string input_file_name ){
    Log("\n");
    int read_ = Read_from_file(input_file_name);
    if (read_ == 0)
    {

    }
    else if (read_ == 3)
    {
        Reading.start_reading = true;
        return 2;
    }
    else if (read_ == -1)
    {
        Log("ERROR\n");
        return -1;
    }
    _Coder();
    _Modulator();
    return 0;
}

