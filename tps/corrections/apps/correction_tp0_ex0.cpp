#include <iostream>

#include "../include/cli_tools.h"

int main(int argc, char** argv)
{
    // Parsing command line *******************************************************************
    // Set required arguments
    std::vector< ArgPair > requiredArgs;

    requiredArgs.push_back( ArgPair("shortNameArg1",
                                    "Description of argument 1") );
    requiredArgs.push_back( ArgPair("shortNameArg2",
                                    "Description of argument 2") );
    requiredArgs.push_back( ArgPair("shortNameArg3",
                                    "Description of argument 3") );

    // Check command line validity
    if( (size_t)argc != requiredArgs.size()+1 )
    {
        std::cerr << "Error: command line arguments do not fit with usage" << std::endl;
        printUsage(argc, argv, requiredArgs);
        return -1;
    }

    // Get arguments from command line
    int         iArg  = 1;
    int         vArg1;
    double      vArg2;
    std::string vArg3;
    try
    {
        vArg1 = std::stoi(argv[iArg++]);
        vArg2 = std::stod(argv[iArg++]);
        vArg3 = argv[iArg++];
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error while parsing arguments:" << std::endl;
        std::cerr << e.what() << "\n";
        std::cerr << "Abort process." << std::endl;
        return 1;
    }    
    // ****************************************************************************************

    std::cout << "Arg1: " << vArg1 << "\n"
              << "Arg2: " << vArg2 << "\n"
              << "Arg3: " << vArg3 << std::endl;

    return 0;
}