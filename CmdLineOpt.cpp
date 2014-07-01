/*!
 *   \file  CmdLineOpt.cpp
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
#include <iostream>
#include <sstream>

using namespace clp;
using namespace std;

#define USAGESTR_STARTINDEX     (30)

CmdLineOpt::CmdLineOpt() {}


CmdLineOpt::CmdLineOpt(string longOpt, char shortOpt, string desc, 
        bool argRequired) :
    longOpt(longOpt),
    shortOpt(shortOpt),
    desc(desc),
    argRequired(argRequired)
{
}


CmdLineOpt::~CmdLineOpt() {}

string CmdLineOpt::usage() 
{
    int reqLen = 8+longOpt.length(); // '  -X, --xxxxx'
    reqLen += (argRequired) ? 5 : 0; // If arg we print ' arg '

    int padd = USAGESTR_STARTINDEX - reqLen; // padding with spaces ' '
    if(padd < 0) padd = 0;

    stringstream ss;
    ss << "  -" << shortOpt << ", --" << longOpt;
    if(argRequired) ss << " arg ";
    for(int i=0 ; i<padd ; ++i)
        ss << " ";
    ss << desc;

    return ss.str();
}
