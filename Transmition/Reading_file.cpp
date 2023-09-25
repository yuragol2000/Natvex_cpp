/**
 *  \brief The function of reading text from a file
 *  \param[in] filename_in 
 *  \param[out] readen_text 
 * 
*/

#include "Transmitter.h"

int Transmitter::Read_from_file(std::string FileName){
    
    std::fstream in;
    in.open(Settings.IMPUT_TEXT_FILE,std::ios::in);
    Log("Read\n");

    if (in.is_open())
    {
                   
        in.seekg(Reading.reading_position);

        if (in.peek() != std::ifstream::traits_type::eof())
        {
            
            in.seekg(Reading.reading_position);

            Log("Reading position = " + std::to_string(Reading.reading_position) + '\n' );
            in.read(Reading.text_buffer_1,Settings.LEN_OF_READING_BUFFER);
            Reading.num_to_print = in.gcount();
            Reading.reading_position = Reading.reading_position + in.gcount(); 
            Log("Length of input file = " + std::to_string(Reading.num_to_print) + '\n' );
        } 
        else{
            Log("End of file\n");
            return 2;
        }
    }
    else
    {
        Log("Can't open input file \n");
        in.close();
        return 1;
    }

    in.close();
    return 0;

}