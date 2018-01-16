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

/*
/// C
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/// C++
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iostream>
#include <sstream>
#include <vector>

/// Boost
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/tokenizer.hpp>
*/

/// Wt
// #include <Wt/WLogger.h>

/// Postgresql
// #include <pqxx/pqxx>

/// Trokam
// #include "common.h"
#include "dbHandler.h"
	
/***********************************************************************
 *
 **********************************************************************/
Trokam::DbHandler::DbHandler(Trokam::Options &options): opt(options)
{}

/***********************************************************************
 *
 **********************************************************************/
Trokam::DbHandler::~DbHandler()
{}
