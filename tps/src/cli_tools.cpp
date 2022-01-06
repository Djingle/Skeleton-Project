#include "../include/cli_tools.h"

#include <iostream>

void printUsage(int                           argc,
                char**                        argv,
                const std::vector< ArgPair >& requiredArgs)
{
    std::string programName = argv[0];

    int nProvidedArgs   = argc - 1;
    int nRequiredArgs   = requiredArgs.size();
    int nValidArgs      = std::min(nProvidedArgs, nRequiredArgs);
    int nMissingArgs    = nRequiredArgs - nProvidedArgs;

    std::string paramsInfo = std::to_string(nMissingArgs) + " missing arguments";
    if( nMissingArgs < 0 )
    {
        paramsInfo = std::to_string(-nMissingArgs) + " surplus arguments";
    }

    std::cout << "Usage" << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << programName << " ";
    for( int i = 0; i < nRequiredArgs - 1; i++ )
    {
        std::cout << requiredArgs[i].first << " ";
    }
    std::cout << requiredArgs.back().first << "\n" << std::endl;
    std::cout << "Arguments:" << std::endl;
    std::cout << "----------" << std::endl;
    for( int i = 0; i < nRequiredArgs - 1; i++ )
    {
        std::cout << requiredArgs[i].first << ": " << requiredArgs[i].second << std::endl;
    }
    std::cout << requiredArgs.back().first << ": " << requiredArgs.back().second << std::endl;
    std::cout << std::endl;
    std::cout << "Command line info:" << std::endl;
    std::cout << paramsInfo << std::endl;
    for( int i = 0; i < nValidArgs; i++ )
    {
        std::cout << requiredArgs[i].first << ": " << argv[i + 1] << std::endl;
    }
    std::cout << std::endl;
    if( nMissingArgs > 0 )
    {
        std::cout << "Missing parameters:" << std::endl;
        for( int i = nProvidedArgs; i < nRequiredArgs; i++ )
        {
            std::cout << requiredArgs[i].first << std::endl;
        }
    }
    else
    {
        std::cout << "Surplus parameters:" << std::endl;
        for( int i = nRequiredArgs; i < nProvidedArgs; i++ )
        {
            std::cout << argv[i + 1] << std::endl;
        }
    }
}
