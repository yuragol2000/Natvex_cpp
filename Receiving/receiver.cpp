#include "receiver.h"


//int Receiver(const char* filename_in, const char* filename_out){
    
    //const std::vector<short> modulated = Reading_Modulated_file(filename_in);  

    //std::cout << modulated.size() << std::endl;
    
    //const std::vector<bool> demodulated = IncoherentReception(modulated);

    //std::cout << demodulated.size() << std::endl;
        
    //std::string received_text = Decoder(demodulated);
    
    //return 0;
//}

void Reader_thread(Receiver& _obj)
{
    while (true)
    {
        if(_obj.Rec() == 1){
            usleep(8000000);
            continue;
        }
    
        usleep(8000000);
        
    }
    
       
}

void receiver(){

    Receiver rc;

    std::thread t1 (Reader_thread,std::ref(rc));

    std::string command;
    while (true)
    {
        std::cout  << "CONSOLE" << std::endl << "INPUT: ";
        std::cin >> command;

        if (command == "stop")
        {
            t1.detach();
            rc.~Receiver();
            break;
        }
        else if (command == "restart")
        {
            t1.detach();
            rc.~Receiver();

            Receiver tr;
            std::thread t1 (Reader_thread,std::ref(rc));
           
        } 
        else if (command == "conf")
        {
            std::string conf_file_name;
            std::cin >> conf_file_name;

            rc.LoadConf(conf_file_name);
        } 
        else if (command == "read")
        {
            rc.Read_from_file();
        }
        else if (command == "coder")
        {
            rc._Decoder();
        }
        else if (command == "mod")
        {
            rc.Demodulator();
        }
        else
        {
            std::cout  << "UNNOWN COMMAND " << command << std::endl;
        } 
    }

}

int main(){


    //std::thread t0(Transmition);

    //t0.join();
    receiver();

    //clock_t tStart = clock();

    //int z = Receiver(filename_in2,filename_out2);

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);  

    return 0;
}