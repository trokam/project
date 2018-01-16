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

#ifndef TROKAM_COMMON_H
#define TROKAM_COMMON_H

/***********************************************************************
 * Configuration files.
 **********************************************************************/

#define SERVER_CONFIG_FILE         "/usr/local/etc/trokamProject.cfg"

/***********************************************************************
 * CCS location.
 **********************************************************************/

#define BOOTSTRAP_MIN_CCS          "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"
#define BOOTSTRAP_THEME_MIN_CCS    "https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css"

/***********************************************************************
 * Branding.
 **********************************************************************/
#define WEB_SITE_ADDR              "http://project.trokam.com/proc/info"
#define WEB_SITE_NAME              "Trokam Project"

/***********************************************************************
 * Warnings messages.
 **********************************************************************/

#define WARNING_APPROOT_EMPTY      "the approot is empty, it looks suspect!"

/***********************************************************************
 * Error messages.
 **********************************************************************/

#endif /// TROKAM_COMMON_H
