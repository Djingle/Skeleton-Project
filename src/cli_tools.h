///
/// \file cli_tools.h
/// \brief Header file of cli_tools
/// \author EMERY Bryan, HORNY Gregory, LABAYE Paul, LAURENT Titouan, RAJENDIRAN Vinojan
/// \version 0.2.0
///


#ifndef CLI_TOOLS_H
#define CLI_TOOLS_H

#include <string>
#include <vector>

typedef std::pair<std::string, std::string> ArgPair;

///
/// \fn void printUsage(int argc,char** argv,const std::vector< ArgPair >& requiredArgs)
/// \brief Prints help about the command line and its option
///
/// \param argc: number of arguments in the command line
/// \param argv: arguments in the ocmmand line
/// \param requiredArgs: a set of pairs: (1) a short name for the command line parameter associated with (2) a description of this parameter
///
void printUsage(int argc,
                char** argv,
                const std::vector< ArgPair >& requiredArgs);

///
/// \fn void waitUserInput()
/// \brief Waits for the user to feed something to the standard input
///
void waitUserInput();

#endif // CLI_TOOLS_H