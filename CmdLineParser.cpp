/*!
 *   \file  CmdLineParser.cpp
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

#include "CmdLineParser.hh"

using namespace clp;
using namespace std;

#define OPTCHAR_END         ('\0')
#define OPTCHAR_UNKNOWN     ('?')
#define OPTCHAR_PARAMS      ('!')

CmdLineParser::CmdLineParser(int argc, char** argv, string usageHead) :
    vector(),
    argc(argc),
    argv(argv),
    usageHead(usageHead),
    iter(begin())
{
    for(int i=0 ; i<argc; ++i) 
        push_back(std::string(argv[i]));
}


CmdLineParser::~CmdLineParser() 
{
}


bool CmdLineParser::registerOpt(string longOpt, char shortOpt, string desc, 
        bool argRequired) 
{
    CmdLineOpt opt(longOpt, shortOpt, desc, argRequired);
    optList.push_back(opt);
}

bool CmdLineParser::registerOpt(CmdLineOpt opt) 
{
    optList.push_back(opt);
}

void CmdLineParser::start() 
{
    iter = begin();
    currOpt = NULL;
}

char CmdLineParser::next() 
{
    ++iter;
    if(iter == end()) return OPTCHAR_END;

    if(currOpt && currOpt->argRequired) ++iter; // Skip arg
    currOpt = NULL;
    if((*iter).at(0) == '-') { // Option
        if((*iter).at(1) == '-') { // long option
            currOpt = optList.getLongOpt(((string)(*iter)).substr(2));
        } else { // short option
            currOpt = optList.getShortOpt((*iter).at(1));
        }

        if(currOpt) { // Known opt
            return currOpt->shortOpt;
        } else { // Unknwon opt
            return OPTCHAR_UNKNOWN;
        }
    } else { // Params
        return OPTCHAR_PARAMS;
    }
    
}

string CmdLineParser::getCurrOptArg() {
    if(!currOpt) return (*iter); // Params
    if(!currOpt->argRequired) return ""; // No args required
    return (*(iter+1)); // Argument
}


void CmdLineParser::usage() 
{
    cout << usageHead << endl;
    cout << endl;
    cout << "Options:" << endl;
    for(list<CmdLineOpt>::iterator i=optList.begin() ;
            i!=optList.end() ; ++i) {
        cout << i->usage() << endl;
    }
}

void CmdLineParser::dumpOpts() 
{
    for(vector<string>::iterator i=this->begin() ;
            i!=this->end() ; ++i)
        cout << *i << endl;
}
