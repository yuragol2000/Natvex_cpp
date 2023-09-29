/**
 *  \brief Transmition function
 *  \param[in] binarycode 
 *  \param[out] s_fsk 
 * 
*/

#include "transmitter.h"

bool _var  = false;//индикатор передачи false - нет true - есть 

void Coder_thread(Transmitter& _obj,std::string input_file_name)
{
    
    _var = true;
    while (true)
    {

        if (_obj.Trans(input_file_name) != 0)
        {
            _var = false;
            break;
        }

        usleep(800000);
        
    }
}


void Modulation_thread(Transmitter& _obj){
    
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
            tr.~Transmitter();
            break;
        }
        else if (command == "restart")
        {
            t1.detach();
            tr.~Transmitter();

            Transmitter tr;
            std::thread t1 (Modulation_thread,std::ref(tr));
           
        }        
        else if (command == "read")
        {
            std::string file_name;
            std::cin >> file_name;

            tr._Reader(file_name);

            
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
            std::string file_name;
            std::cin >> file_name;

            std::thread t2 (Coder_thread,std::ref(tr),file_name);
            t2.join();

        }
        else if (command == "conf")
        {
            std::string conf_file_name;
            std::cin >> conf_file_name;

            tr.LoadConf(conf_file_name);
        }
        else if (command == "mod")
        {
            tr._Modulator();
        }
        else
        {
            std::cout  << "UNNOWN COMMAND " << command << std::endl;
        } 
    }
}


int main(){

    Transmition();

    return 0;
}