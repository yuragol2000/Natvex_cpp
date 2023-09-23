/**
 *  \brief The function of reading text from a file
 *  \param[in] filename_in 
 *  \param[out] readen_text 
 * 
*/


#include "Reading_file.h"

std::string Reading_file(std::string filename_in,const unsigned int pos){


    std::string readen_text ;

    std::ifstream in;

    in.open(filename_in); 

    if (in.is_open())
    {

    }
    else
    {

    std::cout << "Not opened "<< filename_in << std::endl ;

    }

    in.close();     


    return readen_text;
}
