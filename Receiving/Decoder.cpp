#include "Decoder.h"



std::string Receiver::Decoder(std::vector<bool> demodulated){

    std::string decodered;
    if (AlphaCheck(demodulated))
    {
        Log("alpha\n");
        return "";
    }
    
    int ans = Phasing(demodulated);

    Log("Phasing = "  + std::to_string(ans) + "\n");

    int buf_size = demodulated.size()-abs(ans);
    int offset = buf_size%7;

    Log("OFFSET = "  + std::to_string(offset) + "\n");
    
    if (offset != 0)
    {
        //demodulated change
    }
    
    
    if (ans == 0)
    {
        Log("ERROR Decoding\n");
    }
    else if (ans < 0)
    {
        Log("Invert\n");
        std::vector<bool> demodulated_invert = Invert(demodulated);
        std::vector<int> Simb_DX;
        std::vector<int> Simb_RX;
        std::tie(Simb_DX,Simb_RX) = Simb_Decoder(demodulated_invert);

        decodered = Text_Decoder(Simb_DX,Simb_RX);
        
    }
    else {
        Log("Straight\n");

        std::vector<int> Simb_DX;
        std::vector<int> Simb_RX;
        std::tie(Simb_DX,Simb_RX) = Simb_Decoder(demodulated);
        
        decodered = Text_Decoder(Simb_DX,Simb_RX);
    }
    

    return decodered;
}