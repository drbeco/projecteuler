/***************************************************************************
 *   projecteuler.c                           Version 20170112.001402      *
 *                                                                         *
 *   Project Euler                                                         *
 *   Copyright (C) 2015-2017    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

#include "projecteuler.h" 

/* ---------------------------------------------------------------------- */
/* globals */
volatile sig_atomic_t oneminute=0;

/* ---------------------------------------------------------------------- */
/* grabbing control */
void startmain(const char *s)
{
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    signal(SIGALRM, oneminuterule);
    alarm(ONEMINUTE); /* alarm in 1 minute */
    printf("Project Euler version %s\n", VERSION);
    startfunc(s);
}

/* ---------------------------------------------------------------------- */
/* every function starts beautifully */
void startfunc(const char *s)
{
    strcpy(funcname, s);
    snprintf(funcdata, SBUFF, "Starting.\n");
    raise(SIGINT);
}

/* ---------------------------------------------------------------------- */
/* Control-C gives info */
void sigproc()
{
    printf("\nDumping information (ctrl-c). To abort, press ctrl-\\!\n");
    signal(SIGINT, sigproc); /* so captura o primero Ctrl+c */
    printf("Func: %s()\n", funcname);
    printf("Data: %s\n", funcdata);
}

/* ---------------------------------------------------------------------- */
/* Control-\ ends all */
void quitproc()
{                
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    printf("\nctrl-\\ pressed!\n");
    printf("Func: %s\n", funcname);
    printf("Data: %s\n", funcdata);
    printf("Aborting...\n");
    exit(0);
}

/* ---------------------------------------------------------------------- */
/* The answer should be ready in just one minute */
void oneminuterule()
{
    oneminute++;
    if(oneminute==1)
        printf("---- One minute rule broken ! ----\n");
    alarm(ONEMINUTE);
    return;
}

/* ---------------------------------------------------------------------- */

/* ...your functions here */


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */


