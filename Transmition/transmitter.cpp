/**
 *  \brief Transmition function
 *  \param[in] binarycode 
 *  \param[out] s_fsk 
 * 
*/

#include "transmitter.h"

bool _var  = false;//индикатор передачи false - нет true - есть 

void Coder_thread(Transmitter& _obj)
{
    
    _var = true;
    while (true)
    {

        if (_obj.Trans() != 0)
        {
            _var = false;
            break;
        }

        usleep(800000);
        
    }
}


void Modulation_thread(Transmitter& _obj){
    
    _obj.Log("Modulating " + _obj.Settings.OUTPUT_TEXT_FILE + '\n');
    while (true)
    {

        if (_var == false)
        {
            _obj.Alpha();
        }
        else
        {
            
        }
        
        usleep(800000);
    }
    
}
void Transmitter::Write_text(){
    std::cout << Reading.text_buffer_1 << std::endl;
}
void Transmitter::Write_bin(){
    std::cout  << "Bin Size = " << Coding.codered_buffer_1.size() << std::endl;
    for (int i = 0; i < Coding.codered_buffer_1.size(); i++)
    {
        if (i%7 == 0)
        {
            std::cout << std::endl;
        }
        
        std::cout << Coding.codered_buffer_1[i] << " " ;
    }
    
    
}
void Transmition(){
    
    Transmitter tr;

    std::thread t1 (Modulation_thread,std::ref(tr));

    std::string command;

    while (true)
    {
        std::cout  << "CONSOLE" << std::endl << "INPUT: ";
        std::cin >> command;
        std::system("clear");
        
        if (command == "stop")
        {
            t1.detach();
            break;
        }
        else if (command == "stop_1")
        {
            t1.detach();
        }
        else if (command == "read")
        {
            tr.Read_from_file(tr.Settings.IMPUT_TEXT_FILE);
        }
        else if (command == "coder")
        {
            tr._Coder();
        }
        else if (command == "text")
        {
            tr.Write_text();
        }
        else if (command == "tr")
        {
            std::thread t2 (Coder_thread,std::ref(tr));
            t2.join();
        }
        else if (command == "a")
        {
            tr.Alpha();
        }
        else if (command == "mod")
        {
            tr.Modulator();
        }
        else
        {
            std::cout  << "UNNOWN COMMAND " << command << std::endl;
        } 
        usleep(500000);
    }
}


int main(){

    Transmition();

    return 0;
}