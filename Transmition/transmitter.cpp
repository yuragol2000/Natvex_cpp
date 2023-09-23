/**
 *  \brief Transmition function
 *  \param[in] binarycode 
 *  \param[out] s_fsk 
 * 
*/

#include "transmitter.h"

char* input = new char[100]();

std::mutex m;
std::condition_variable cv;
bool _var  = false;//индикатор передачи false - нет true - есть 
bool ret() {return _var;};

void Coder_thread(Transmitter& _obj)
{
    
    std::unique_lock<std::mutex> ulm (m);
    while (true)
    {
        //_var = true;
        //cv.notify_one();
        //cv.wait(ulm);


        usleep(800000);
        
    }
    
       
}


void Modulation_thread(Transmitter& _obj){
    
    _obj.Log("Modulating " + _obj.Settings.OUTPUT_TEXT_FILE + '\n');
    while (true)
    {
        if (_var == false)
        {
            if (!_obj.Write_text_to_file(_obj.Settings.OUTPUT_TEXT_FILE,"LOL\n"));
                break;
        }
        else
        {
            if (!_obj.Write_text_to_file(_obj.Settings.OUTPUT_TEXT_FILE,"1\n"));
                break;
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

    //std::thread t1 (Read,std::ref(tr));
    //std::thread t2 (Coder_thread,std::ref(tr));

    
    
    std::thread t2 (Modulation_thread,std::ref(tr));
   // std::thread t1 (Modulation_thread,std::ref(tr));

    //Read(std::ref(tr));
    // std::thread t2 (foo,tr);
    
    //t2.join();
    std::string command;
    while (true)
    {
        std::cout  << "CONSOLE" << std::endl << "INPUT: ";
        std::cin >> command;

        if (command == "stop")
        {
           // t2.detach();
            //t3.detach();
            break;
        }
        else if (command == "stop_1")
        {
            //t1.detach();
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
        else if (command == "mod")
        {
            tr.Modulator();
        }
        else if (command == "bin")
        {
            tr.Write_bin();
        }
        else
        {
            std::cout  << "UNNOWN COMMAND " << command << std::endl;
        } 
        usleep(500000);
    }

    //const std::vector<bool> binarycode = Coder(readen_text, type_of_coder);
    
    //const std::vector<double> s_fsk = Modulation(binarycode);

    //Writing(filename_out,s_fsk);
}


int main(){


    //std::thread t0(Transmition);

    //t0.join();
    Transmition();

    //clock_t tStart = clock();

    //int z = Receiver(filename_in2,filename_out2);

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);  

    return 0;
}