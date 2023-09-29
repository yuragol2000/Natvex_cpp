#include "Reading_Modulated_file.h"
/**
 *  \brief Reading modulated signal.  
 * 
 *  \return  Modulated signal.
 *
*/
int Receiver::Read_from_file(){
    
    Log("Reading \n");

    std::ifstream in;

    in.open(Settings.IMPUT_TEXT_FILE); 

    if (in.is_open())
    {

        in.seekg(Modulation.reading_position);

        if (in.peek() != std::ifstream::traits_type::eof())
        {
            short temp;
            while (in >> temp)
            {
                Modulation.modulated_buf.push_back(temp);
            }
            Modulation.reading_position = Modulation.reading_position + in.gcount(); 
            Log("Reading pos = " + std::to_string(Modulation.reading_position) + '\n');
            in.close(); 
            Log("Modulation.modulated_buf size = " + std::to_string(Modulation.modulated_buf.size()) + '\n');

            std::fstream clear_file(Settings.IMPUT_TEXT_FILE, std::ios::out);
            clear_file.close();

            return 0;
        }
        else
        {
            Log("End of file \n");
            in.close(); 
            return 1;
        }

       
    }

    else
    {

      Log("Not opened " + Settings.IMPUT_TEXT_FILE + '\n');

    }

}