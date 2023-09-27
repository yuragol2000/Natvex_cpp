#include "Transmitter.h"

/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
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
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/

Transmitter::Transmitter(const std::string configure_file)
{
    Settings.CONFIG_FILE = configure_file;
    std::cout << "Config file has changed to - " << configure_file << std::endl; 
    Transmitter();
}

/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/

int Transmitter::LoadConf(const std::string){
    
    
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
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
void Transmitter::Log(const std::string message){

    std::ofstream log;
    log.open(Settings.LOG_FILE,std::ios_base::app);
            log.write(message.c_str(),message.length());
    log.close();
}
/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
Transmitter::~Transmitter()
{

    delete  Reading.text_buffer_1;

    Log("CLASS Destracted\n");
}

/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
void Transmitter::_Coder(){
    
    Log("Coder \n");
    Coding.codered_buffer_1 = Coder(Reading.text_buffer_1,Settings.TYPE_OF_CODER);
    
    for (size_t i = 0; i < Settings.LEN_OF_READING_BUFFER; i++)
    {
        Reading.text_buffer_1[i] = '\0';
    }
    
    Log("Coding.codered_buffer_1 size = " + std::to_string(Coding.codered_buffer_1.size()) + '\n');

}
/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
int Transmitter::Alpha_init(){
    Log("ALPHA init \n");
    Modulating.modulated_buffer_alpha = Modulation(Coding.codered_buffer_alpha);
    Log("Modulator.modulated_buffer_alpha size = " + std::to_string(Modulating.modulated_buffer_alpha.size()) + '\n');
    
}


/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
int Transmitter::Alpha(){
    Log("ALPHA \n");
    Writing(Modulating.modulated_buffer_alpha);

}
/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
int Transmitter::Trans(){
    Log("\n");
    int read_ = Read_from_file(Settings.IMPUT_TEXT_FILE);
    if (read_ == 0)
    {

    }
    else if (read_ == 2)
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
    Modulator();
    return 0;
}
/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 * 
 *  \param[in] input_text
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
void Transmitter::Modulator(){
    Log("Modulator \n");
    Modulating.modulated_buffer_1 = Modulation(Coding.codered_buffer_1);
     Log("Modulator.modulated_buffer_1 size = " + std::to_string(Modulating.modulated_buffer_1.size()) + '\n');
    Writing(Modulating.modulated_buffer_1);

}
