/**
 *  \brief Function of coding using the International Telegraph Alphabet No. 2 and adding phasing signals
 *  \param[in] input_text, 
 *  \param[in] type_of_coder, \\ if 0 -> CBRS if 1 -> SBRS
 *  \param[out] binarycode  
 * 
*/

#include "Coder.h"
#include "TextCoder.h"

std::vector<bool> Coder(const char* input_text,const bool & type_of_coder){

    

    std::vector<bool> phasing_binarycode = {} ;

    // =========================================================================
    // Adding initial phasing signals
    // At least 10 seconds of signal pair sequences must be transmitted.
    // =========================================================================


    for(int i = 0;i < Phasing_initial_num;i++)//Phasing_initial_num
    {
        phasing_binarycode.insert(phasing_binarycode.end(), PhasingSign_2.begin(), PhasingSign_2.end());
        phasing_binarycode.insert(phasing_binarycode.end(), PhasingSign_1.begin(), PhasingSign_1.end());
    }

    // =========================================================================
    // DX and RX channel diversity
    // =========================================================================

    const std::vector<bool> Textcode = TextCoder(input_text);

    std::vector<bool> messageDX   = Sign27;
    messageDX.insert(messageDX.end(), Sign28.begin(), Sign28.end()) ;
    messageDX.insert(messageDX.end(), Textcode.begin(), Textcode.end()) ;

    std::vector<bool> messageDiff = PhasingSign_1;
    messageDiff.insert(messageDiff.end(), PhasingSign_1.begin(), PhasingSign_1.end());

    std::vector<bool> messageRX = messageDiff;
    messageRX.insert(messageRX.end(), messageDX.begin(), messageDX.end());//  2 more



    // =========================================================================
    // Combining two DX and RX channels into one stream
    // =========================================================================



    const int Len_RX = messageRX.size();
    const int Len_DX = messageDX.size();

    std::vector<bool> stream = {};

    for(int i = 0;i<= (Len_RX/7)-1;i++){

        if(i < Len_DX/7){

            stream.insert(stream.end(), messageDX.begin()+i*7, messageDX.begin()+(i+1)*7);

        }
        else{

            stream.insert(stream.end(), PhasingSign_1.begin(), PhasingSign_1.end());

        }
        
        stream.insert(stream.end(), messageRX.begin()+i*7, messageRX.begin()+(i+1)*7);
    }


    // =========================================================================
    // Addition of final phasing signals
    // At least 2 seconds of signal pair sequences must be transmitted
    // =========================================================================

    for (int i = 0;i < Phasing_final_num;i++){

        stream.insert(stream.end(), PhasingSign_1.begin(), PhasingSign_1.end());

    }
    // =========================================================================
    // Сombine
    // =========================================================================


    std::vector<bool> binarycode = {} ;
    
    binarycode = phasing_binarycode;
    binarycode.insert(binarycode.end(), stream.begin(), stream.end());

    return binarycode;

}
