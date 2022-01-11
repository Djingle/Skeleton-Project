#include <iostream>

#include "../include/cli_tools.h"

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    /* ! STUDENTS TODO ! */
    // Add three parameters of types int, double and string

    // Check command line validity
    if( (size_t)argc != requiredArgs.size()+1 )
    {
        std::cerr << "Error: command line arguments do not fit with usage" << std::endl;
        printUsage(argc, argv, requiredArgs);
        return -1;
    }

    // Get arguments from command line
    int         iArg  = 1;
    /* ! STUDENTS TODO ! */
    // Declare your parameters here to store their value in a variable
    try
    {
        /* ! STUDENTS TODO ! */
        // Get the parameters value
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while parsing arguments:" << std::endl;
        std::cerr << e.what() << "\n";
        std::cerr << "Abort process." << std::endl;
        return 1;
    }    
    // ****************************************************************************************

    /* ! STUDENTS TODO ! */
    // Print the parameters to console

    return 0;
}