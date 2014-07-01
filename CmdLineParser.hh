/*!
 *   \file  CmdLineParser.hh
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
#include <list>
#include <vector>

namespace clp {

    class CmdLineOpt {
        public:
            CmdLineOpt();
            CmdLineOpt(std::string longOpt, char shortOpt, std::string desc, 
                    bool argRequired);
            ~CmdLineOpt();
            std::string usage();

            std::string longOpt;
            char        shortOpt;
            std::string desc;
            bool        argRequired;
    };

    class CmdLineOptList : public std::list<CmdLineOpt> {
        public:
            CmdLineOptList();
            ~CmdLineOptList();

            bool hasShortOpt    (char shortOpt);
            bool hasLongOpt     (std::string longOpt);
            CmdLineOpt* getShortOpt  (char shortOpt);
            CmdLineOpt* getLongOpt   (std::string longOpt);
    };
    

    class CmdLineParser : public std::vector<std::string> {
        public:
            CmdLineParser(int argc, char** argv, std::string usageHead);
            ~CmdLineParser();
    
            bool registerOpt(std::string longOpt, char shortOpt, std::string desc, 
                    bool argRequired);
            bool registerOpt(CmdLineOpt opt);
            
            void start();
            char next();
            std::string getCurrOptArg();

            void usage();
            void dumpOpts();
    
        private:
            int     argc;
            char**  argv;
            std::string     usageHead;
            CmdLineOptList  optList;
            std::vector<std::string>::iterator iter;
            CmdLineOpt      *currOpt;
    };

}
