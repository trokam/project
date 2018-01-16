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

/// C++
#include <cassert>
#include <iostream>

/// Wt
#include <Wt/WLogger.h>

/// Trokam
#include "postgresql.h"

/***********************************************************************
 *
 *
 **********************************************************************/
Trokam::postgresql::postgresql(std::string connection_parameters)
{
    dbConnection= new pqxx::connection(connection_parameters);
    
    Wt::log("info") << "connected to database";
    Wt::log("info") << "backend version: " << dbConnection->server_version();
    Wt::log("info") << "protocol version: " << dbConnection->protocol_version();
}

/***********************************************************************
 *
 *
 **********************************************************************/
Trokam::postgresql::~postgresql()
{
    delete dbConnection;
}

/***********************************************************************
 *
 *
 **********************************************************************/
void Trokam::postgresql::execSql(const std::string &sentence)
{
    try
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Begin a transaction acting on our current connection.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        pqxx::work T(*dbConnection, "execute_no_answer");

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Perform a query on the database, storing result tuples in R.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        T.exec(sentence);

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Tell the transaction that it has been successful.
        /// This is not really necessary if no modifications are made
        /// to commit.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        T.commit();
    }
    catch(const pqxx::sql_error &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// The sql_error exception class gives us
        /// some extra information.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "SQL error: " << e.what();
        Wt::log("error") << "Query was: " << e.query();
    }
    catch(const std::exception &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// All exceptions thrown by libpqxx are
        /// derived from std::exception.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Exception: " << e.what();
    }
    catch(...)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// This is really unexpected.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Unhandled exception";
    }
}

/***********************************************************************
 *
 *
 **********************************************************************/
void Trokam::postgresql::execSql(const std::string &sentence,
                                  std::string &answer)
{
    try
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Begin a transaction acting on our current connection.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        pqxx::work T(*dbConnection, "execute");

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Perform a query on the database, storing result tuples in R.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        pqxx::result R(T.exec(sentence));

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Put in the string 'answer' the element of the of the first
        /// column of the first row of the results.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        pqxx::result::const_iterator c= R.begin();
        if(c != R.end())
        {
            answer= c[0].as(std::string());
        }

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Tell the transaction that it has been successful.
        /// This is not really necessary if no modifications are made
        /// to commit.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        T.commit();
    }
    catch(const pqxx::sql_error &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// The sql_error exception class gives us
        /// some extra information.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "SQL error: " << e.what();
        Wt::log("error") << "Query was: " << e.query();
    }
    catch(const std::exception &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// All exceptions thrown by libpqxx are
        /// derived from std::exception.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Exception: " << e.what();
    }
    catch(...)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// This is really unexpected.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Unhandled exception";
    }
}

/***********************************************************************
 *
 *
 **********************************************************************/
void Trokam::postgresql::execSql(const std::string &sentence,
                                  boost::scoped_ptr<pqxx::result> &answer)
{
    try
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Begin a transaction acting on our current connection.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        pqxx::work T(*dbConnection, "execute");

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Perform a query on the database, storing result tuples in R.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        answer.reset(new pqxx::result(T.exec(sentence)));

        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// Tell the transaction that it has been successful.
        /// This is not really necessary if no modifications are made
        /// to commit.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        T.commit();
    }
    catch(const pqxx::sql_error &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// The sql_error exception class gives us
        /// some extra information.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "SQL error: " << e.what();
        Wt::log("error") << "Query was: " << e.query();
    }
    catch(const std::exception &e)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// All exceptions thrown by libpqxx are
        /// derived from std::exception.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Exception: " << e.what();
    }
    catch(...)
    {
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        /// This is really unexpected.
        /// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Wt::log("error") << "Unhandled exception";
    }
}
