#include "Receiver.h"

/**
 *  \brief Default Constructor
 * 
 * Loads the default configuration (latest) and also allocates memory for an array of text.
 *   
 * 
*/
Receiver::Receiver(){

    LoadConf(Settings.CONFIG_FILE);    
    Log("\n\nClASS Created\n");


    Log("filename_in - " + Settings.IMPUT_TEXT_FILE + "\n");
    Log("filename_out - " + Settings.OUTPUT_TEXT_FILE + "\n");
}

/**
 *  \brief A constructor using a specific configuration file
 * 
 *  \param[in] configure_file
 * 
 *  After changing the configuration file, it runs  default Constructor
 * 
*/
Receiver::Receiver(const std::string configure_file)
{
    Settings.CONFIG_FILE = configure_file;
    std::cout << "Config file has changed to - " << configure_file << std::endl; 
    Receiver();
}

/**
 *  \brief Default destructor   
 * 
 *  Destroys the buffer for text
*/

Receiver::~Receiver()
{

    Log("CLASS Destracted\n");
}
/**
 *  \brief Method of loading the configuration file
 * 
 *  \param[in] conf_file_name
 *  
 *  \return Errors
 * 
 *  \warning When adding new variables, you need to change this method
 * 
 *  Reads the necessary constants and variables and puts them in the transmitter class
*/

int Receiver::LoadConf(const std::string conf_file_name){
    
    Settings.CONFIG_FILE = conf_file_name;

    INIReader reader(Settings.CONFIG_FILE);

    Settings.IMPUT_TEXT_FILE = reader.GetString("IMPUT_PARAMETERS","IMPUT_TEXT_FILE","txt");
    Settings.OUTPUT_TEXT_FILE= reader.GetString("IMPUT_PARAMETERS","OUTPUT_TEXT_FILE","bin");

    Settings.LOG_FILE = reader.GetString("IMPUT_PARAMETERS","LOG_FILE","log");

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

int Receiver::Log(const std::string message){

    std::ofstream log;
    log.open(Settings.LOG_FILE,std::ios_base::app);
            log.write(message.c_str(),message.length());
    log.close();
}

/**
 *  \brief Decoding method with logging
 * 
 *  \return Errors
 * 
 *  Writes the size of the decoded buffer to a log file
 * 
*/

int Receiver::_Decoder(){
    
    Log("Decoder \n");
    Receiving.received_text = Decoder(Demodulation.demodulated_buf);
    Log("Receiving.received_text size = " + std::to_string(Receiving.received_text.size()) + '\n');
    
}

/**
 *  \brief Demodulating method with logging
 *  
 *  \return Errors
 * 
 *  Writes the size of the demodulated buffer to a log file
 * 
*/

int Receiver::Demodulator(){
    Log("Demodulator \n");
    Demodulation.demodulated_buf = IncoherentReception(Modulation.modulated_buf);
    Modulation.modulated_buf.clear();
    Log("Demodulation.demodulated_buf size = " + std::to_string(Demodulation.demodulated_buf.size()) + '\n');
}
/**
 *  \brief The main method of Receiver
 * 
 *  \return Errors  
 * 
 *   Starts the method of reading modulated file, then demodulates
     and decoder it. Then sends it to the output file
 * 
*/
int Receiver::Rec(){

    Log("Rec \n");

    if (Read_from_file() == 1)
    {
        return 1;
    }
    
    Demodulator();
    _Decoder();
    Write_text_to_file(Settings.OUTPUT_TEXT_FILE,Receiving.received_text);
}

/**
 *  \brief  The function of recording the received signal to a file
 * 
 *  \param[in] Output_filename  Name of the output file
 *  \param[in] Messege Message to be placed in the Output_filename
 * 
 *  \return Errors  
 * 
*/
int Receiver::Write_text_to_file(const std::string Output_filename ,const std::string Messege){

    std::ofstream out;   
    out.open(Output_filename,std::ios::app);  
    if (out.is_open())
    {

        
        out << Messege;
    }  
    else
    {
        Log("Can't open output file \n");
        out.close();
        return 1;
    }  
    out.close();

    return 0;
}