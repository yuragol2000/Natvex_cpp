#include "Transmitter.h"

/**
 *  \brief Function of writing modulated signal to output file, changing double to short 
 * 
 *  \param[in] s_fsk
 * 
 *  \param[in] type_of_coder 0 -> CBRS, 1 -> SBRS
 *  \param[out] binarycode  
 * 
 *   
 * 
*/
int Transmitter::Writing(std::vector<double> s_fsk){


    std::ofstream out;   
    out.open(Settings.OUTPUT_TEXT_FILE,std::ios::app);  

    if (out.is_open())
    {
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

        for (size_t i = 0; i < s_fsk_short.size(); i++){

            out << s_fsk_short[i] <<" ";
            
        }
        out.close();
    }  
    else
    {
        Log("Can't open output file \n");
        out.close();
        return -1;
    }  
    
    return 0;

}