#include "Writing.h"

int Writing(const std::string filename_out,const std::vector<double> s_fsk){
    
    std::vector<short> s_fsk_short;

    for (size_t i = 0; i < s_fsk.size(); i++){

        double temp = 0;
        

        if (s_fsk[i] >= 0){
            
            temp = s_fsk[i]*32767;
        }
        else
            temp = s_fsk[i]*32768;
        
        
        s_fsk_short.push_back(temp);
        

    }

    std::ofstream stream(filename_out); 

    for (size_t i = 0; i < s_fsk_short.size(); i++){

       stream << s_fsk_short[i] <<" ";
    }
    
    stream.close(); // ��������� ����

    return 0;
}
