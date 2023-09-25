 #include "Simb_Decoder.h"
 
std::string Receiver::Compare(std::string DX, std::string RX){

    std::string final;

    int len =  RX.size();

    if (DX.size() != RX.size())
    {
        Log("Different sizes\n");
        if (DX.size() > RX.size())
        {
            len =RX.size();

        }else {
            len =DX.size();
        }
        
    }
    else{

    }
    



    for (int i = 0; i < len; i++)
    {
        if (DX[i] == RX[i])
        {
            final += DX[i];
        }
        else 
        {
            final += '*';
        }
        
    }
    return final;
}

 std::string Receiver::Text_Decoder(const std::vector<int> DX , const std::vector<int> RX){

    std::string Text_RX;
    std::string Print_text_RX;
    std::string Text_DX;
    std::string Print_text_DX;

    int len = RX.size();


    int last_simb = -1;
    if (RX.size() != DX.size())
    {
        Log("Sizes not compatative\n");
    }

    else{
        for (int i = 0; i < len; i++)
        {
            int sum = RX[i];
            std::string arr = "";
            std::string Print = "";
            if (last_simb == 1 && sum != 73)

                switch (sum)
                {
                    case 14:
                        arr = 'A';
                        Print = 'A'; 
                        break;
                    case 88:
                        arr = 'B';
                        Print = 'B';
                        break;
                    case 35:
                        arr = 'C'; 
                        Print = 'C';
                        break;
                    case 26:
                        arr = 'D'; 
                        Print = 'D'; 
                        break;
                    case 74:
                        arr = 'E'; 
                        Print = 'E';                
                        break;
                    case 19:
                        arr = 'F'; 
                        Print = 'F';                 
                        break;
                    case 41:
                        arr = 'G'; 
                        Print = 'G';                 
                        break;
                    case 52:
                        arr = 'H';
                        Print = 'H';
                        break;
                    case 38:
                        arr = 'I'; 
                        Print = 'I';
                        break;
                    case 11:
                        arr = 'J'; 
                        Print = 'J';
                        break;
                    case 67:
                        arr = 'K'; 
                        Print = 'K';                
                        break;
                    case 44:
                        arr = 'L'; 
                        Print = 'L'; 
                        break;
                    case 49:
                        arr = 'M'; 
                        Print = 'M'; 
                        break;
                    case 50:
                        arr = 'N';
                        Print = 'N';                
                        break;
                    case 56:
                        arr = 'O'; 
                        Print = 'O';                 
                        break;
                    case 37:
                        arr = 'P'; 
                        Print = 'P'; 
                        break;
                    case 69:
                        arr = 'Q'; 
                        Print = 'Q';
                        break;
                    case 42:
                        arr = 'R'; 
                        Print = 'R';                
                        break;
                    case 22:
                        arr = 'S'; 
                        Print = 'S';
                        break;
                    case 104:
                        arr = 'T'; 
                        Print = 'T';  
                        break;
                    case 70:
                        arr = 'U'; 
                        Print = 'U';                
                        break;
                    case 97:
                        arr = 'V'; 
                        Print = 'V';
                        break;
                    case 13:
                        arr = 'W'; 
                        Print = 'W';
                        break;
                    case 81:
                        arr = 'X'; 
                        Print = 'X';
                        break;
                    case 21:
                        arr = 'Y'; 
                        Print = 'Y';                
                        break;
                    case 28:
                        arr = 'Z'; 
                        Print = 'Z';
                        break;
        
                    case 82:
                        last_simb = 1;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1; 
                        break;

                    case 100:
                        arr = '\n';
                        Print = '\n'; 
                        break;
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
        
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:

                        arr = '*';
                        Print = '*';
                        break;
                }
            else if (last_simb == 0 && sum != 82)    
                switch (sum)
                {
                    case 14:
                        arr = '-'; 
                        Print = '-';
                        break;
                    case 98:
                        arr = ' ';      
                        Print = ' ';
                        break;
                    case 88:
                        arr = '?'; 
                        Print = '?';
                        break;
                    case 50:
                        arr = ','; 
                        Print = ',';
                        break;
                    case 49:
                        arr = '.'; 
                        Print = '.';
                        break;
                    case 35:
                        arr = ':'; 
                        Print = ':';
                        break;
        
                    case 37:
                        arr = '0'; 
                        Print = '0';     
                        break;
                    case 69:
                        arr = '1'; 
                        Print = '1';                     
                        break;
                    case 13:
                        arr = '2'; 
                        Print = '2';     
                        break;
                    case 74:
                        arr = '3'; 
                        Print = '3';                     
                        break;
                    case 42:
                        arr = '4'; 
                        Print = '4';     
                        break;
                    case 104:
                        arr = '5'; 
                        Print = '5';                                     
                        break;
                    case 21:
                        arr = '6'; 
                        Print = '6';     
                        break;
                    case 70:
                        arr = '7'; 
                        Print = '7';           
                        break;
                    case 38:
                        arr = '8'; 
                        Print = '8';     
                        break;
                    case 56:
                        arr = '9'; 
                        Print = '9';
                        break;
                    case 28:
                        arr = '+'; 
                        Print = '+';
                        break;
                    case 97:
                        arr = '='; 
                        Print = '=';
                        break;
                    case 81:
                        arr = '/'; 
                        Print = '/';                
                        break;
        
        
                    case 82:
                        last_simb = 1;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1; 
                        break;
        
                    case 100:
                        arr =  char(13);
                        Print =  char(13);// new line  check 
                        break;
        
        
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:
                        arr = '*';
                        Print = '*';
                        break;
                }
            else
            {
                switch (sum)
                {
                    case 82:
                        last_simb = 1; 
                        break;
                    case 100:
                        arr = char(10) ; // new line  check 
                        Print = char(10) ;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1;
                        break;
                        
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
        
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:
                        arr = '*';
                        Print = '*';
                        break;
                }
            } 
            Text_RX += arr;
            Print_text_RX += Print;

        }
        for (int i = 0; i < len; i++)
        {
            int sum = DX[i];
            std::string arr = "";
            std::string Print = "";
            if (last_simb == 1 && sum != 73)

                switch (sum)
                {
                    case 14:
                        arr = 'A';
                        Print = 'A'; 
                        break;
                    case 88:
                        arr = 'B';
                        Print = 'B';
                        break;
                    case 35:
                        arr = 'C'; 
                        Print = 'C';
                        break;
                    case 26:
                        arr = 'D'; 
                        Print = 'D'; 
                        break;
                    case 74:
                        arr = 'E'; 
                        Print = 'E';                
                        break;
                    case 19:
                        arr = 'F'; 
                        Print = 'F';                 
                        break;
                    case 41:
                        arr = 'G'; 
                        Print = 'G';                 
                        break;
                    case 52:
                        arr = 'H';
                        Print = 'H';
                        break;
                    case 38:
                        arr = 'I'; 
                        Print = 'I';
                        break;
                    case 11:
                        arr = 'J'; 
                        Print = 'J';
                        break;
                    case 67:
                        arr = 'K'; 
                        Print = 'K';                
                        break;
                    case 44:
                        arr = 'L'; 
                        Print = 'L'; 
                        break;
                    case 49:
                        arr = 'M'; 
                        Print = 'M'; 
                        break;
                    case 50:
                        arr = 'N';
                        Print = 'N';                
                        break;
                    case 56:
                        arr = 'O'; 
                        Print = 'O';                 
                        break;
                    case 37:
                        arr = 'P'; 
                        Print = 'P'; 
                        break;
                    case 69:
                        arr = 'Q'; 
                        Print = 'Q';
                        break;
                    case 42:
                        arr = 'R'; 
                        Print = 'R';                
                        break;
                    case 22:
                        arr = 'S'; 
                        Print = 'S';
                        break;
                    case 104:
                        arr = 'T'; 
                        Print = 'T';  
                        break;
                    case 70:
                        arr = 'U'; 
                        Print = 'U';                
                        break;
                    case 97:
                        arr = 'V'; 
                        Print = 'V';
                        break;
                    case 13:
                        arr = 'W'; 
                        Print = 'W';
                        break;
                    case 81:
                        arr = 'X'; 
                        Print = 'X';
                        break;
                    case 21:
                        arr = 'Y'; 
                        Print = 'Y';                
                        break;
                    case 28:
                        arr = 'Z'; 
                        Print = 'Z';
                        break;
        
                    case 82:
                        last_simb = 1;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1; 
                        break;

                    case 100:
                        arr = '\n';
                        Print = '\n'; 
                        break;
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
        
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:

                        arr = '*';
                        Print = '*';
                        break;
                }
            else if (last_simb == 0 && sum != 82)    
                switch (sum)
                {
                    case 14:
                        arr = '-'; 
                        Print = '-';
                        break;
                    case 98:
                        arr = ' ';      
                        Print = ' ';
                        break;
                    case 88:
                        arr = '?'; 
                        Print = '?';
                        break;
                    case 50:
                        arr = ','; 
                        Print = ',';
                        break;
                    case 49:
                        arr = '.'; 
                        Print = '.';
                        break;
                    case 35:
                        arr = ':'; 
                        Print = ':';
                        break;
        
                    case 37:
                        arr = '0'; 
                        Print = '0';     
                        break;
                    case 69:
                        arr = '1'; 
                        Print = '1';                     
                        break;
                    case 13:
                        arr = '2'; 
                        Print = '2';     
                        break;
                    case 74:
                        arr = '3'; 
                        Print = '3';                     
                        break;
                    case 42:
                        arr = '4'; 
                        Print = '4';     
                        break;
                    case 104:
                        arr = '5'; 
                        Print = '5';                                     
                        break;
                    case 21:
                        arr = '6'; 
                        Print = '6';     
                        break;
                    case 70:
                        arr = '7'; 
                        Print = '7';           
                        break;
                    case 38:
                        arr = '8'; 
                        Print = '8';     
                        break;
                    case 56:
                        arr = '9'; 
                        Print = '9';
                        break;
                    case 28:
                        arr = '+'; 
                        Print = '+';
                        break;
                    case 97:
                        arr = '='; 
                        Print = '=';
                        break;
                    case 81:
                        arr = '/'; 
                        Print = '/';                
                        break;
        
        
                    case 82:
                        last_simb = 1;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1; 
                        break;
        
                    case 100:
                        arr = arr + char(13);
                        Print = Print + char(13);// new line  check 
                        break;
        
        
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:
                        arr = '*';
                        Print = '*';
                        break;
                }
            else
            {
                switch (sum)
                {
                    case 82:
                        last_simb = 1; 
                        break;
                    case 100:
                        arr = char(10) ; // new line  check 
                        Print = char(10) ;  
                        break;
        
                    case 73:
                        last_simb = 0;
                        break;
        
                    case 112:
                        arr = '<'; 
                        last_simb = -1;
                        break;
                        
        
                    case 7:
                        arr = '{';     //PhasingSign_1 
                        break;
        
                    case 76:
                        arr = '}';     //PhasingSign_2
                        break;
                    default:
                        arr = '*';
                        Print = '*';
                        break;
                }
            } 

            Text_DX += arr;
            Print_text_DX += Print;

        }
            
    }
    
    return Compare(Print_text_DX,Print_text_RX);
 }

std::tuple<std::vector<int>,std::vector<int>> Receiver::Simb_Decoder(const std::vector<bool> demodulated){


    std::string readen_text  ;

    int len_of_demodulated = demodulated.size();
    int num_of_simb = len_of_demodulated/7;

    const std::vector<bool> RegistrLet = {1,0,1,0,0,1,0};  
    const std::vector<bool> RegistrDig = {1,0,0,1,0,0,1}; 

    std::vector<int> simb_arr ;

    for (int i = 0; i < num_of_simb; i++)
    {
        int temp_simb = 0;

        for (int j = 6; j >=0; j--)
        {
            temp_simb += pow(2,6-j)*demodulated[i*7+j];
        }
        
        simb_arr.push_back(temp_simb);
    }

    std::vector<int> simb_arr_DX;
    std::vector<int> simb_arr_RX;

    for (int i = 0; i < simb_arr.size()-1; i  +=2 )
    {
        simb_arr_DX.push_back(simb_arr[i]);
        simb_arr_RX.push_back(simb_arr[i+1]);

    }

    //   1 => registrLet
    //   0 => registrDig
    //  -1 => none

    return std::tie(simb_arr_DX,simb_arr_RX);
}

bool Receiver::AlphaCheck(const std::vector<bool> demodulated){
    
    int len_of_demodulated = demodulated.size();
    int num_of_simb = len_of_demodulated/7;

    std::vector<int> simb_arr ;

    for (int i = 0; i < num_of_simb; i++)
    {
        int temp_simb = 0;

        for (int j = 6; j >=0; j--)
        {
            temp_simb += pow(2,6-j)*demodulated[i*7+j];
        }
        
        simb_arr.push_back(temp_simb);
    }
    for (size_t i = 0; i < simb_arr.size(); i++)
    {
        if (simb_arr[i] == 7)
        {
            
        }
        else
        {
            return false;
        }
    }
    return true;
}
