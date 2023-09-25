/**
 *  \brief Coding function using the International Telegraph Alphabet No2
 *  \param[in] input_text, 
 *  \param[out] binarycode  
 * 
*/
#include  "TextCoder.h"


std::vector<bool> TextCoder(const char* input_text){

    const int len_of_text = strlen(input_text);

    std::string text = input_text;

    for (int i = 0; i < len_of_text; i++){

        text[i] = toupper(text[i]);

    }

    // 1  => registrLet
    // 0  => registrDig
    // -1 => none

    int last_simb = -1;

    // =========================================================================
    // We translate the text into bit sequences according to the standard table
    // =========================================================================
    std::vector<bool>binarycode = {};

    for(int i = 0; i < len_of_text; i++){

        std::vector<bool> arr = {};

        if(std::isalpha(text[i])){

            if(last_simb != 1){

                binarycode.insert(binarycode.end(), RegistrLet.begin(), RegistrLet.end()) ;

                last_simb = 1;
            }

            switch (text[i]){

                case 'A':
                    arr = {0,0,0,1,1,1,0};
                    break;
                case 'B':
                    arr = {1,0,1,1,0,0,0};
                    break;
                case 'C':
                    arr = {0,1,0,0,0,1,1};
                    break;
                case 'D':
                    arr = {0,0,1,1,0,1,0};
                    break;
                case 'E':
                    arr = {1,0,0,1,0,1,0};
                    break;
                case 'F':
                    arr = {0,0,1,0,0,1,1};
                    break;
                case 'G':
                    arr = {0,1,0,1,0,0,1};
                    break;
                case 'H':
                    arr = {0,1,1,0,1,0,0};
                    break;
                case 'I':
                    arr = {0,1,0,0,1,1,0};
                    break;
                case 'J':
                    arr = {0,0,0,1,0,1,1};
                    break;
                case 'K':
                    arr = {1,0,0,0,0,1,1};
                    break;
                case 'L':
                    arr = {0,1,0,1,1,0,0};
                    break;
                case 'M':
                    arr = {0,1,1,0,0,0,1};
                    break;
                case 'N':
                    arr = {0,1,1,0,0,1,0};
                    break;
                case 'O':
                    arr = {0,1,1,1,0,0,0};
                    break;
                case 'P':
                    arr = {0,1,0,0,1,0,1};
                    break;
                case 'Q':
                    arr = {1,0,0,0,1,0,1};
                    break;
                case 'R':
                    arr = {0,1,0,1,0,1,0};
                    break;
                case 'S':
                    arr = {0,0,1,0,1,1,0};
                    break;
                case 'T':
                    arr = {1,1,0,1,0,0,0};
                    break;
                case 'U':
                    arr = {1,0,0,0,1,1,0};
                    break;
                case 'V':
                    arr = {1,1,0,0,0,0,1};
                    break;
                case 'W':
                    arr = {0,0,0,1,1,0,1};
                    break;
                case 'X':
                    arr = {1,0,1,0,0,0,1};
                    break;
                case 'Y':
                    arr = {0,0,1,0,1,0,1};
                    break;
                case 'Z':
                    arr = {0,0,1,1,1,0,0};
                    break;

                case char(13):
                    arr = {1,1,1,0,0,0,0};
                    break;

                case char(10):
                    arr = {1,1,0,0,1,0,0};
                    break;    
                default:
                    std::cout << "Cant coder" << static_cast<int>(text[i]) << std::endl;
                    exit(-1);
            }
        }
        else{

            if(last_simb != 0){

                binarycode.insert(binarycode.end(), RegistrDig.begin(), RegistrDig.end()) ;

                last_simb = 0;
            }

            switch (text[i]){

                case '1':
                    arr = {1,0,0,0,1,0,1};
                    break;
                case '2':
                    arr = {0,0,0,1,1,0,1};
                    break;
                case '3':
                    arr = {1,0,0,1,0,1,0};
                    break;
                case '4':
                    arr = {0,1,0,1,0,1,0};
                    break;
                case '5':
                    arr = {1,1,0,1,0,0,0};
                    break;
                case '6':
                    arr = {0,0,1,0,1,0,1};
                    break;
                case '7':
                    arr = {1,0,0,0,1,1,0};
                    break;
                case '8':
                    arr = {0,1,0,0,1,1,0};
                    break;
                case '9':
                    arr = {0,1,1,1,0,0,0};
                    break;
                case '0':
                    arr = {0,1,0,0,1,0,1};
                    break;
                case '-':
                    arr = {0,0,0,1,1,1,0};
                    break;
                case ' ':
                    arr = {1,1,0,0,0,1,0};
                    break;
                case '?':
                    arr = {0,1,0,0,1,1,0};
                    break;
                case ',':
                    arr = {0,1,1,0,0,1,0};
                    break;
                case '.':
                    arr = {0,1,1,0,0,0,1};
                    break;
                case ':':
                    arr = {0,1,0,0,0,1,1};
                    break;

                case '+':
                    arr = {0,0,1,1,1,0,0};
                    break;
                case '=':
                    arr = {1,1,0,0,0,0,1};
                    break;
                case '/':
                    arr = {1,0,1,0,0,0,1};
                    break;

                case char(13):
                    arr = {1,1,1,0,0,0,0};
                    break;

                case char(10):
                    arr = {1,1,0,0,1,0,0};
                    break;    
                default:
                    std::cout << "Cant coder" << static_cast<int>(text[i]) << std::endl;
                    exit(-1);

            }
        }

        binarycode.insert(binarycode.end(), arr.begin(), arr.end()) ;

    }


    return binarycode;
}

