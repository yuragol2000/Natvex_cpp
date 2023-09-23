#include "Phasing.h"

int Phasing(const std::vector<bool> demodulated)
{
    int start_pos = 0;       //1 = DX  0 = RX , sign "-"  if need to invert 
    unsigned int offset = 0; // offset to corect


    int len_of_phasing = demodulated.size();
    if (len_of_phasing < 6*7)
    {
        std::cout  << "Too few bits to phasing" << std::endl;
        return -5;
    }
    
    for (int i = 0; i < len_of_phasing; i++)
    {
        int temp_CB_2 = 0 ;
        int temp_SB_2 = 0 ;

        for (int j = 0; j < 7; j++)
        {
   
            temp_CB_2 +=  (demodulated[j+i] == PhasingSign_CB_2[j]);
            temp_SB_2 +=  (demodulated[j+i] == PhasingSign_SB_2[j]);            
        }

        if (temp_CB_2 == 7)
        {

            if (len_of_phasing-i < 5*7)
            {
                std::cout  << "Too few bits to phasing or resieving ERROR" << std::endl;
                return -5;
            }
            for (int j = 0; j < 7; j++)
            {
                temp_CB_2 +=  (demodulated[j+i+7]  == PhasingSign_CB_1[j]); 
                temp_CB_2 +=  (demodulated[j+i+14] == PhasingSign_CB_2[j]);        
                temp_CB_2 +=  (demodulated[j+i+21] == PhasingSign_CB_1[j]);          
                temp_CB_2 +=  (demodulated[j+i+28] == PhasingSign_CB_2[j]);          
                temp_CB_2 +=  (demodulated[j+i+35] == PhasingSign_CB_1[j]);          
            }     
            std::cout << "i = " << i << " CB_2 = " << temp_CB_2 << std::endl;
            if (temp_CB_2 == 7*6)
            {
                start_pos = 1;
                offset = i+42;
                break;
            }                     
            
        }
        else if (temp_SB_2 == 7 )
        {
            if (len_of_phasing-i < 5*7)
            {
                std::cout  << "Too few bits to phasing or resieving ERROR" << std::endl;
                return -5;
            }
            for (int j = 0; j < 7; j++)
            {
                temp_SB_2 +=  (demodulated[j+i+7]  == PhasingSign_SB_1[j]); 
                temp_SB_2 +=  (demodulated[j+i+14] == PhasingSign_SB_2[j]);        
                temp_SB_2 +=  (demodulated[j+i+21] == PhasingSign_SB_1[j]);          
                temp_SB_2 +=  (demodulated[j+i+28] == PhasingSign_SB_2[j]);          
                temp_SB_2 +=  (demodulated[j+i+34] == PhasingSign_SB_1[j]);          
            }     
            if (temp_SB_2 == 7*6)
            {
                start_pos = -1;
                offset = i+42;
                break;
            } 
        }
    }

    return offset*start_pos;

}
