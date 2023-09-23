#include "Transmitter.h"


Transmitter::Transmitter(){

    LoadConf(Settings.CONFIG_FILE);    
    Log("\n\nClASS Created\n");


    Reading.text_buffer_1 = new char[Settings.LEN_OF_READING_BUFFER]();
    Reading.text_buffer_2 = new char[Settings.LEN_OF_READING_BUFFER]();
    Reading.text_buffer_3 = new char[Settings.LEN_OF_READING_BUFFER]();

    Log("filename_in - " + Settings.IMPUT_TEXT_FILE + "\n");
    Log("filename_out - " + Settings.OUTPUT_TEXT_FILE + "\n");
}

Transmitter::Transmitter(const std::string configure_file)
{
    Settings.CONFIG_FILE = configure_file;
    std::cout << "Config file has changed to - " << configure_file << std::endl; 
    Transmitter();
}

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

void Transmitter::Log(const std::string message){

    std::ofstream log;
    log.open(Settings.LOG_FILE,std::ios_base::app);
            log.write(message.c_str(),message.length());
    log.close();
}

Transmitter::~Transmitter()
{

    
    delete  Reading.text_buffer_1;
    delete  Reading.text_buffer_2;
    delete  Reading.text_buffer_3;

    Log("CLASS Destracted\n");
}

int Transmitter::Read_from_file(std::string FileName){
    
    std::fstream in;
    in.open(Settings.IMPUT_TEXT_FILE,std::ios::in);
    Log("Read\n");

    if (in.is_open())
    {
                   
        in.seekg(Reading.reading_position);

        if (in.peek() != std::ifstream::traits_type::eof())
        {
            
            in.seekg(Reading.reading_position);

            Log("Reading position = " + std::to_string(Reading.reading_position) + '\n' );
            in.read(Reading.text_buffer_1,Settings.LEN_OF_READING_BUFFER);
            Reading.num_to_print += in.gcount();
            Reading.reading_position = Reading.reading_position + in.gcount(); 
        } 
        else{
            Log("End of file\n");
            Log("Length of input file = " + std::to_string(Reading.num_to_print) + '\n' );
        }
    }
    else
    {
        Log("Can't open input file \n");
        in.close();
        return 1;
    }

    in.close();
    return 0;

}
void Transmitter::_Coder(){
    
    Log("Coder \n");
    Coding.codered_buffer_1 = Coder(Reading.text_buffer_1,Settings.TYPE_OF_CODER);
    for (size_t i = 0; i < Settings.LEN_OF_READING_BUFFER; i++)
    {
        Reading.text_buffer_1[i] = '\0';
    }
    
    Log("Coding.codered_buffer_1 size = " + std::to_string(Coding.codered_buffer_1.size()) + '\n');

}

int Transmitter::Trans(){
    Read_from_file(Settings.IMPUT_TEXT_FILE);
    _Coder();
    Modulator();
}
void Transmitter::Modulator(){
    Log("Modulator \n");
    Modulating.modulated_buffer_1 = Modulation(Coding.codered_buffer_1);
     Log("Modulator.modulated_buffer_1 size = " + std::to_string(Modulating.modulated_buffer_1.size()) + '\n');
    Writing(Settings.OUTPUT_TEXT_FILE,Modulating.modulated_buffer_1);

}
int Transmitter::Write_text_to_file(const std::string FileName ,const std::string Messege){

    std::ofstream out;   
    out.open(FileName,std::ios::app);  
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