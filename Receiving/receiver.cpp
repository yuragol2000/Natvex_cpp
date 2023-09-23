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
    //std::thread t2 (Coder_thread,std::ref(tr));

    
    
    //std::thread t2 (Modulation_thread,std::ref(tr));
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
            //t3.detach();rc.Settings.IMPUT_TEXT_FILE
            break;
        }
        else if (command == "stop_1")
        {
            //t1.detach();
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
        usleep(500000);
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