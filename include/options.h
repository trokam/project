/***********************************************************************
 *                            T R O K A M
 *                         Fair Search Engine
 *
 * Copyright (C) 2018, Nicolas Slusarenko
 *                     nicolas.slusarenko@trokam.com
 *
 * This file is part of Trokam.
 *
 * Trokam is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Trokam is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Trokam. If not, see <http://www.gnu.org/licenses/>. 
 **********************************************************************/

#ifndef TROKAM_OPTIONS_H
#define TROKAM_OPTIONS_H

/// C++
#include <string>

namespace Trokam
{
    class Options
    {
        public:
            Options();
            Options(const Options &opt);
            Options& operator= (const Options &opt);

            /**
             * Read the settings from file.
             */
            void readSettings(const std::string &filename);

            std::string  dbHost() const;
            std::string  dbName() const;
            std::string  dbUser() const;
            std::string  dbPass() const;

            std::string  dbHost(const std::string &host);
            std::string  dbName(const std::string &name);
            std::string  dbUser(const std::string &user);
            std::string  dbPass(const std::string &pass);

        private:
            std::string  optDbHost;
            std::string  optDbName;
            std::string  optDbUser;
            std::string  optDbPass;
    };
}

#endif /// TROKAM_OPTIONS_H
