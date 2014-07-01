/*!
 *   \file  main.cpp
 *   \brief  
 *  
 *  <+DETAILED+>
 *  
 *  \author  Bertrand.F (), 
 *  
 *  \internal
 *       Created:  27/06/2014
 *      Revision:  none
 *      Compiler:  gcc
 *  Organization:  
 *     Copyright:  Copyright (C), 2014, Bertrand.F
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <iostream>
#include <string>

#include "CmdLineParser.hh"
using namespace std;
using namespace clp;

#define USAGE_HEAD      "Usage: pgname [options]\nDo some very useful stuff nobody knows about."

int main(int argc, char** argv)
{
    char opt;
    CmdLineParser cmdParser(argc, argv, USAGE_HEAD);
    cmdParser.registerOpt("arg1",    'a', "Argument 1",              true);
    cmdParser.registerOpt("help",    'h', "Prints this help",        false);
    cmdParser.registerOpt("verbose", 'v', "Prints a lot of stuff",   false);
    cmdParser.usage();
    cout << "" << endl;
    cmdParser.dumpOpts();

    cmdParser.start();
    while((opt=cmdParser.next()) != '\0') {
        switch(opt) {
            case 'a':
            case 'h':
            case 'v':
                cout << "Got opt '" << opt << "' with arg '" << cmdParser.getCurrOptArg() << "'" << endl;
                break;
            case '?':
                cout << "Unknown char: " << opt << endl;
                break;
            case '!':
                cout << "Got param: " << cmdParser.getCurrOptArg() << endl;
                break;
            default:
                cerr << "Unhandled char: " << opt << endl;
                break;
        }
   }

    return 0;
}
