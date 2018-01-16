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
#include <string>
#include <iostream>

/// Boost
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

/// Wt
#include <Wt/WLogger.h>

/// Trokam
#include "options.h"

Trokam::Options::Options()
{}

void Trokam::Options::readSettings(const std::string &filename)
{
    try
    {
        boost::property_tree::ptree pt;
        boost::property_tree::ini_parser::read_ini(filename, pt);
        optDbHost= pt.get<std::string>("database.host");
        optDbName= pt.get<std::string>("database.name");
        optDbUser= pt.get<std::string>("database.user");
        optDbPass= pt.get<std::string>("database.pass");
    }
    catch(const std::exception& e)
    {
        Wt::log("error") << "settings file not found.";
        Wt::log("error") << e.what();
    }
}


Trokam::Options::Options(const Trokam::Options &opt)
{
    optDbHost= opt.dbHost();
    optDbName= opt.dbName();
    optDbUser= opt.dbUser();
    optDbPass= opt.dbPass();
}

/**
 * Copy constructor.
 **/
Trokam::Options& Trokam::Options::operator= (const Trokam::Options &opt)
{
    /**
     * Avoid self-assignment.
     */
    if(this == &opt)
    {
        return *this;
    }

    /**
     * Copy data.
     */
    optDbHost= opt.dbHost();
    optDbName= opt.dbName();
    optDbUser= opt.dbUser();
    optDbPass= opt.dbPass();

    /**
     * Return 'this' object.
     */
    return *this;
}


std::string Trokam::Options::dbHost() const
{
    return optDbHost;
}

std::string Trokam::Options::dbName() const
{
    return optDbName;
}

std::string Trokam::Options::dbUser() const
{
    return optDbUser;
}

std::string Trokam::Options::dbPass() const
{
    return optDbPass;
}

std::string Trokam::Options::dbHost(const std::string &host)
{
    optDbHost= host;
    return optDbHost;
}

std::string Trokam::Options::dbName(const std::string &name)
{
    optDbName= name;
    return optDbName;
}

std::string Trokam::Options::dbUser(const std::string &user)
{
    optDbUser= user;
    return optDbUser;
}

std::string Trokam::Options::dbPass(const std::string &pass)
{
    optDbPass= pass;
    return optDbPass;
}
