#include "Decoder.h"


std::string Decoder(std::vector<bool> demodulated){

    std::string decodered;

    int ans = Phasing(demodulated);

    std::cout << ans << std::endl;

    int buf_size = demodulated.size()-abs(ans);
    int offset = buf_size%7;
    std::cout << "OFFSET " << offset << std::endl;
    
    if (offset != 0)
    {
        //demodulated change
    }
    
    
    if (ans == 0)
    {
        std::cout << "ERROR Decoding" << std::endl;
    }
    else if (ans < 0)
    {
        std::cout << "Invert "  << std::endl;
        std::vector<bool> demodulated_invert = Invert(demodulated);
        std::vector<int> Simb_DX;
        std::vector<int> Simb_RX;
        std::tie(Simb_DX,Simb_RX) = Simb_Decoder(demodulated_invert);
        
    }
    else {
        std::cout << "Straight "  << std::endl;

        std::vector<int> Simb_DX;
        std::vector<int> Simb_RX;
        std::tie(Simb_DX,Simb_RX) = Simb_Decoder(demodulated);
        
        decodered = Text_Decoder(Simb_DX,Simb_RX);
    }
    

    return decodered;
}