#***************************************************************************
#*   Autoversion makefile                     v.20170112.001402   (euler)  *
#*   Copyright (C) 2014-2017 by Ruben Carlo Benante <rcb@beco.cc>          *
#*                                                                         *
#*   This makefile sets BUILD and allows to set MAJOR.MINOR version,       *
#*   DEBUG and OBJ to compile a range of different targets                 *
#***************************************************************************
#*   This program is free software; you can redistribute it and/or modify  *
#*   it under the terms of the GNU General Public License as published by  *
#*   the Free Software Foundation; version 2 of the License.               *
#*                                                                         *
#*   This program is distributed in the hope that it will be useful,       *
#*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
#*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
#*   GNU General Public License for more details.                          *
#*                                                                         *
#*   You should have received a copy of the GNU General Public License     *
#*   along with this program; if not, write to the                         *
#*   Free Software Foundation, Inc.,                                       *
#*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
#***************************************************************************
#*   To contact the author, please write to:                               *
#*   Ruben Carlo Benante                                                   *
#*   Email: rcb@beco.cc                                                    *
#*   Webpage: http://drbeco.github.io/                                     *
#***************************************************************************
#
# Usage:
#
#	* Options:
#		- DEBUG=[0|1] turn on/off debug MACRO
#		- Version is MAJOR.MINOR.DATE.TIME
#			+ MAJOR=N makes this major version N
#			+ MINOR=N makes this minor version N
#		- OBJ=someobjetc.o : compile and link with objetc or source
#		- You can force update with flag -B
#
# Examples:
#
# * From linux prompt:
#    - Normal C program (ex1.c)
#        $ make ex1.x
#    - Aspipo program (ex1.c) with object:
#        $ make ex1.x OBJ=libaspipo-ux64.o
#    - Multiple objects:
#        $ make ex1.x OBJ="mylib1.o mylib2.o"
#    - Multiple sources to generate a single binary ex1.x:
#    	 $ make ex1.x SRC="mysrc1.c mysrc2.c"
#	 - Normal C program (ex2.c) version 2.3, no debug
#	 	 $ make ex2.x MAJOR=2 MINOR=3 DEBUG=0
#	 - Brainforce:
#	     $ make ex1.bf.x
#	 - Portugol:
#	 	 $ make ex1.gpt.x
#
# * Directly from vim editor command line:
#    - Normal C program (ex1.c)
#        :make ex1.x
#    - Aspipo program (ex1.c)
#        :make ex1.x OBJ=libaspipo-ux64.o
#
# * Copy from 'rascunhos' to 'trabalhos'
# 	- $ make copy PRG=ex1
# 	It will try to copy every file matching patterns:
#		cp ex1.c 		# c source code
#		cp ex1.h 		# c library source code
# 		cp ex1.x 		# binary from c source code
# 		cp ex1.gpt 		# portugol source code
# 		cp ex1.gpt.x 	# binary from portugol source code
# 		cp ex1.bf 		# brainforce source code
# 		cp ex1.bf.x 	# binary from brainforce source code
# 		cp ex1.cpl.x 	# binary from c code with some prolog predicates linked to it
# 		cp ex1.pl 		# prolog source code
# 		cp ex1.pl.x 	# binary from prolog source code
# 		cp ex1.so 		# shared library object from c source code
# 		cp ex1.pl.so 	# c library object with some functions that may be called by a prolog program
# 	to the '../trabalhos' folder
#
# * CTAGS
# 	 - Generate a 'tags' index file with all tags in all C source codes
# 	 	$ make tags
# 	 - Use with vi:
# 	 	:make tags
# 	 	- To find a function or other tag, use $ vim -t tag
# 	 	- Inside vi, use :ta tag
#
#
# * clean
#   Clean temporary files *.o and errors.err
#   	$ make clean
#
# * wipe 
#	- WARNING!! Clean all created files: *.x *.so *.o errors.err and tags
# 		$ make wipe
#
# Log:
# 2017-03-03:
# 		* added -fdiagnostics-color=always to colorize tee output
# 		* added -pg -fprofile-arcs to allow gprof command on debug
# 2017-03-05:
# 		* added variable CCCOLOR to work with vi
# 			- set makeprg=make\ o=%< CCCOLOR=never\ $* 
# 			- set makeprg=make\ %<.x CCCOLOR=never\ $*
# 			- set makeprg=make\ CCCOLOR=never\ $*
#		* added CPPFLAGS += -D$(D) so we can pass values to
#			C-Pre-processor via make prog.x D=VARIABLE=VALUE
# 2017-03-06:
# 		* ifeq "$(DEBUG)" "1" to set CFLAGS
# 		* added _XOPEN_SOURCE=700 to pair with -ansi
# 		* added _FORTIFY_SOURCE=1 to help catch overflows
# 2017-03-18:
# 		* added -lcurl to link with libcurl

# disable builtin rules with MAKEFLAGS and .SUFFIXES
MAKEFLAGS += --no-builtin-rules
#.SUFFIXES:
.PHONY: clean wipe nomatch
.PRECIOUS: %.o
SHELL=/bin/bash -o pipefail

# asure functions that return values are not ignored
FORTIFY ?= 1
# turn on/off debug mode
DEBUG ?= 1
# version major number
MAJOR ?= 0
# version minor number
MINOR ?= 1
# object files to compile with the source
OBJ ?=
# other source files to be compiled together
SRC ?=
# colorize output
CCCOLOR ?= always
# create a define
D ?= D_
# project Euler exercise number
N ?= 0
PENAME := $(shell printf '%-8s' pe$(N).c)
# build date
BUILD = $(shell date +"%g%m%d.%H%M%S")
# build date inside binary code
DEFSYM = $(subst .,_,$(BUILD))
# automatic version number
VERSION = "\"$(MAJOR).$(MINOR).$(BUILD)\""
# c compiler
CC = gcc
# brainforce compiler
BF = bf
# gportugol compiler
PT = gpt
# prolog linker
PLLD = swipl-ld
# prolog compiler
PL = swipl
# c flags for the c compiler
CFLAGS = -Wall -Wextra -std=gnu99 -fdiagnostics-color=$(CCCOLOR)
#CFLAGS = -Wall -Wextra -g -O0 -std=gnu99 -pg -fprofile-arcs -fdiagnostics-color=$(CCCOLOR)
ifeq "$(DEBUG)" "0"
# not a debug, go fast
CFLAGS += -Ofast
else ifeq "$(DEBUG)" "1"
# it is a debug, add symbols and no optimizations
CFLAGS += -g -O0
else
# exaustive debug
CFLAGS += -g -O0 -pg -fprofile-arcs -ansi -Wpedantic
endif
#-pedantic-errors -Werror
#-Ofast -c
# pre-processor flags
CPPFLAGS = -DVERSION=$(VERSION) -DBUILD="\"$(BUILD)\"" -DDEBUG=$(DEBUG) -D$(D) -D_FORTIFY_SOURCE=$(FORTIFY)
ifeq "$(DEBUG)" "2"
# POSIX extra stuff
CPPFLAGS += -D_XOPEN_SOURCE=700
endif
# libraries to link, options to the linker
LDLIBS = -Wl,--defsym,BUILD_$(DEFSYM)=0 -lm -lpthread -lncurses -lcurl -lgmp
# making a shared library
CCSHARED = -shared -fPIC
# brainforce options
BFFLAGS = -i on -p both -r on -w on
# making a prolog shared library
PLLDSHARED = -shared
# making a stand alone prolog program
PLFLAGS = --goal=main --stand_alone=true

# prevent built-in rules for %.o
%.o : %.c

# Programa BrainForce.
%.bf.x : %.bf
	$(BF) $^ -o $@ $(BFFLAGS) 2>&1 | tee errors.err

# Algoritmo em PORTUGOL.
%.gpt.x : %.gpt
	$(PT) $^ -o $@ 2>&1 | tee errors.err

# Compila um programa em PROLOG para binario individual.
%.pl.x : %.pl $(SRC)
	$(PL) $(PLFLAGS) -o $@ -c $^ 2>&1 | tee errors.err

# file.pl: regras de PROLOG que podem ser chamada por um programa em C.
%.cpl.x : %.c %.pl
	$(PLLD) $^ -o $@ 2>&1 | tee errors.err

# file.c: modulo C com funcoes que podem ser chamadas pelo PROLOG.
%.plc.so : %.c
	$(PLLD) $(PLLDSHARED) $^ -o $@ 2>&1 | tee errors.err

# Shared library
%.so : %.c $(OBJ) $(SRC)
	-$(CC) $(CCSHARED) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) $^ -o $@ 2>&1 | tee errors.err
ifeq "$(CCCOLOR)" "always"
	@sed -i -r "s/\x1B\[(([0-9]+)(;[0-9]+)*)?[m,K,H,f,J]//g" errors.err
endif

# Programa em C (incluindo bibliotecas como allegro ou libaspipo).
# Inclui VERSION, data de BUILD e DEBUG (opcional).
%.x : %.c $(OBJ) $(SRC)
	-$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) $^ -o $@ 2>&1 | tee errors.err
ifeq "$(CCCOLOR)" "always"
	@sed -i -r "s/\x1B\[(([0-9]+)(;[0-9]+)*)?[m,K,H,f,J]//g" errors.err
endif
	-@[ ! -s errors.err ] && echo $@ version $(VERSION) > VERSION

# override built-in rules for mathing everything (exactly the same rule as %.x above)
% : %.c $(OBJ) $(SRC)
	-$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) $^ -o $@ 2>&1 | tee errors.err
	@echo $@ version $(VERSION) > VERSION
ifeq "$(CCCOLOR)" "always"
	@sed -i -r "s/\x1B\[(([0-9]+)(;[0-9]+)*)?[m,K,H,f,J]//g" errors.err
endif
	-@[ ! -s errors.err ] && echo $@ version $(VERSION) > VERSION

nomatch :
	@echo 'makefile error: no rules for the given goal(s)' $(warning nomatch)

# CUIDADO! Apaga tudo que o makefile pode criar.
wipe :
	rm -f *.x *.so *.o errors.err tags a.out

# Apaga temporarios desnecessarios.
clean :
	rm -f *.o errors.err

copy :
	-cp $(PRG).c ../trabalhos 			# c source code
	-cp $(PRG).h ../trabalhos 			# c library source code
	-cp $(PRG).x ../trabalhos			# binary from c source code
	-cp $(PRG).gpt ../trabalhos			# portugol source code
	-cp $(PRG).gpt.x ../trabalhos		# binary from portugol source code
	-cp $(PRG).bf ../trabalhos			# brainforce source code
	-cp $(PRG).bf.x ../trabalhos		# binary from brainforce source code
	-cp $(PRG).cpl.x ../trabalhos		# binary from c code with some prolog predicates linked to it
	-cp $(PRG).pl ../trabalhos			# prolog source code
	-cp $(PRG).pl.x ../trabalhos		# binary from prolog source code
	-cp $(PRG).so ../trabalhos			# shared library object from c source code
	-cp $(PRG).pl.so ../trabalhos		# c library object with some functions that may be called by a prolog program

# Gera arquivo de indice tags com funcoes de todos fontes em C
tags :
	ctags -R
	ctags -R -x | less -F

# Gera um novo peN
euler :
	@cp -i peN.c pe$(N).c
	@sed -i 's/PEN.c   /$(PENAME)/' pe$(N).c
	@sed -i 's/PEN pe ## N/PEN pe ## $(N)/' pe$(N).c
	@echo "pe$(N).c"

#* ------------------------------------------------------------------- *
#* makefile config for Vim modeline                                    *
#* vi: set ai noet ts=4 sw=4 tw=0 wm=0 fo=croqlt :                     *
#* Template by Dr. Beco <rcb at beco dot cc> Version 20170506.191339   *

