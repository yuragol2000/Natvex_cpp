#include "Reading_Modulated_file.h"

std::vector<short> Reading_Modulated_file(const std::string filename_in){


    std::vector<short> modulated;

    std::ifstream in;

    in.open(filename_in); 
    
    if (in.is_open())
    {
        short temp;
        while (in >> temp)
        {
            modulated.push_back(temp);
        }


    }
    else
    {

    std::cout << "Not opened "<< filename_in << std::endl ;

    }

    in.close();     


    return modulated;
}
