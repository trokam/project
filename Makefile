########################################################################
#                             T R O K A M
#                          Fair Search Engine
#
#  Copyright (C) 2018, Nicolas Slusarenko
#                      nicolas.slusarenko@trokam.com
#
#  This file is part of Trokam.
#
#  Trokam is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Trokam is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Trokam. If not, see <http://www.gnu.org/licenses/>.
########################################################################

CC=c++

CPPFLAGS=-c -std=c++14 -Wall -Wcpp -I./include

LDFLAGS=-g

LDLIBS= -lboost_program_options \
        -lboost_regex \
        -lboost_signals \
        -lboost_system \
        -lboost_thread \
        -lpqxx \
        -lwt \
        -lwtfcgi

BIN=./bin

INSTALL_SERVER_BIN_DIR=/usr/local/bin/
WEB_SERVER_DOC_ROOT=/var/www/html/

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# info
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SOURCES_INFO= src/appGenerator.cpp \
              src/main.cpp \
              src/options.cpp \
              src/sharedResources.cpp \
              src/topWindow.cpp \
              src/dbHandler.cpp \
              src/postgresql.cpp

OBJECTS_INFO=$(SOURCES_INFO:.cpp=.o)

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# targets
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

all: info

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# individual recipes
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

info: $(OBJECTS_INFO)
	$(CC) $(LDFLAGS) $(OBJECTS_INFO) -o $(BIN)/$@ $(LDLIBS)

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# These are the list of files and the automatically
# generated dependencies to build them
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DEPENDENCIES= $(OBJECTS:.o=.d)

include $(DEPENDENCIES:.cpp=.d)

%.d: %.cpp
		@set -e; rm -f $@; \
		$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
		rm -f $@.$$$$

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.PHONY : install
install :
		sudo cp $(BIN)/info $(INSTALL_SERVER_BIN_DIR)
		sudo cp -r -a docroot/* $(WEB_SERVER_DOC_ROOT)/docroot
		sudo cp -r -a page/* $(WEB_SERVER_DOC_ROOT)
		sudo cp -r -a approot $(INSTALL_SERVER_BIN_DIR)

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.PHONY : clean
clean :
	-rm -f bin/*
	-rm -f src/*.o
