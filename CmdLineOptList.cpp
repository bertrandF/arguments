/*!
 *   \file  CmdLineOptList.cpp
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

CmdLineOptList::CmdLineOptList() : 
    list() 
{
}


CmdLineOptList::~CmdLineOptList() 
{
}

bool CmdLineOptList::hasShortOpt(char shortOpt) 
{
    for(list<CmdLineOpt>::iterator i = this->begin() ;
            i != this->end() ; ++i) {
        if(i->shortOpt == shortOpt) return true;
    }
    return false;
}

bool CmdLineOptList::hasLongOpt(string longOpt) 
{
    for(list<CmdLineOpt>::iterator i = this->begin() ;
            i != this->end() ; ++i) {
        if(i->longOpt == longOpt) return true;
    }
    return false;
}

CmdLineOpt* CmdLineOptList::getShortOpt(char shortOpt) 
{
    for(list<CmdLineOpt>::iterator i = this->begin() ;
            i != this->end() ; ++i) {
        if(i->shortOpt == shortOpt) return &(*i);
    }
    return NULL;
}

CmdLineOpt* CmdLineOptList::getLongOpt(string longOpt) 
{
    for(list<CmdLineOpt>::iterator i = this->begin() ;
            i != this->end() ; ++i) {
        if(i->longOpt == longOpt) return &(*i);
    }
    return NULL;
}
