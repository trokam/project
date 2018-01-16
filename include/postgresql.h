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

#ifndef TROKAM_POSTGRESQL_H
#define TROKAM_POSTGRESQL_H

/// C++
#include <string>

/// Boost
#include <boost/scoped_ptr.hpp>

/// Postgresql
#include <pqxx/pqxx>

/***********************************************************************
 *
 *
 **********************************************************************/
namespace Trokam
{
    class postgresql
    {
        public:
            postgresql(std::string connection_parameters);
            ~postgresql();
            
            void execSql(const std::string &sentence);
            void execSql(const std::string &sentence, std::string &answer);
            void execSql(const std::string &sentence, boost::scoped_ptr<pqxx::result> &answer);

        private:
            pqxx::connection *dbConnection;
    };
}

#endif /// TROKAM_POSTGRESQL_H
