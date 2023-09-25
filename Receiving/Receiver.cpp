#include "Receiver.h"

Receiver::Receiver(){

    LoadConf(Settings.CONFIG_FILE);    
    Log("\n\nClASS Created\n");


    Log("filename_in - " + Settings.IMPUT_TEXT_FILE + "\n");
    Log("filename_out - " + Settings.OUTPUT_TEXT_FILE + "\n");
}

Receiver::Receiver(const std::string configure_file)
{
    Settings.CONFIG_FILE = configure_file;
    std::cout << "Config file has changed to - " << configure_file << std::endl; 
    Receiver();
}

int Receiver::LoadConf(const std::string){
    
    
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

void Receiver::Log(const std::string message){

    std::ofstream log;
    log.open(Settings.LOG_FILE,std::ios_base::app);
            log.write(message.c_str(),message.length());
    log.close();
}

Receiver::~Receiver()
{

    Log("CLASS Destracted\n");
}



int Receiver::Read_from_file(){
    
    Log("Reading \n");

    std::ifstream in;

    in.open(Settings.IMPUT_TEXT_FILE); 

    if (in.is_open())
    {

        in.seekg(Modulation.reading_position);

        if (in.peek() != std::ifstream::traits_type::eof())
        {
            short temp;
            while (in >> temp)
            {
                Modulation.modulated_buf.push_back(temp);
            }
            Modulation.reading_position = Modulation.reading_position + in.gcount(); 
            Log("Reading pos = " + std::to_string(Modulation.reading_position) + '\n');
            in.close(); 
            Log("Modulation.modulated_buf size = " + std::to_string(Modulation.modulated_buf.size()) + '\n');

            std::fstream clear_file(Settings.IMPUT_TEXT_FILE, std::ios::out);
            clear_file.close();

            return 0;
        }
        else
        {
            Log("End of file \n");
            in.close(); 
            return 1;
        }

       
    }

    else
    {

      Log("Not opened " + Settings.IMPUT_TEXT_FILE + '\n');

    }

}
void Receiver::_Decoder(){
    
    Log("Decoder \n");
    Receiving.received_text = Decoder(Demodulation.demodulated_buf);
    Log("Receiving.received_text size = " + std::to_string(Receiving.received_text.size()) + '\n');
    Write_text_to_file(Settings.OUTPUT_TEXT_FILE,Receiving.received_text);
}

void Receiver::Demodulator(){
    Log("Demodulator \n");
    Demodulation.demodulated_buf = IncoherentReception(Modulation.modulated_buf);
    Modulation.modulated_buf.clear();
    Log("Demodulation.demodulated_buf size = " + std::to_string(Demodulation.demodulated_buf.size()) + '\n');
}
int Receiver::Rec(){

    Log("Rec \n");

    if (Read_from_file() == 1)
    {
        return 1;
    }
    
    
    Demodulator();
    _Decoder();

}

int Receiver::Write_text_to_file(const std::string FileName ,const std::string Messege){

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