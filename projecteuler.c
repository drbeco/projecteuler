 /**************************************************************************
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
 **************************************************************************/

#include "projecteuler.h" 

/* ---------------------------------------------------------------------- */
/* globals */
volatile sig_atomic_t oneminute=0;
volatile sig_atomic_t CTRLC=0;

/* ---------------------------------------------------------------------- */
/* grabbing control */
void startmain(void)
{
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    signal(SIGALRM, oneminuterule);
    alarm(ONEMINUTE); /* alarm in 1 minute */
    printf("Project Euler version %s\n", VERSION);
    printf("Ctrl-C to dump. Ctrl-\\ to abort.\n");
    /* startfunc("main"); */
    return;
}

/* ---------------------------------------------------------------------- */
/* every function starts beautifully */
/* void startfunc(const char *s) */
/* { */
/*     strcpy(funcname, s); */
/*     snprintf(funcdata, SBUFF, "Starting.\n"); */
/*     raise(SIGINT); */
    /* return; */
/* } */

/* ---------------------------------------------------------------------- */
/* give signals back to owner */
extern inline void finishmain(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    return;
}

/* ---------------------------------------------------------------------- */
/* Control-C gives info */
void sigproc()
{
    /* int i, er; */
    /* signal(SIGINT, sigproc); /1* so captura o primero Ctrl+c *1/ */
    /* er=write(1, "Func: ", 6); */
    /* for(i=0, er-=5; funcname[i]!='\0' && i<SBUFF && er==1; i++) */
    /*     er=write(1, &funcname[i], 1); */
    /* er=write(1, "Data: ", 6); */
    /* for(i=0, er-=5; funcdata[i]!='\0' && i<SBUFF && er==1; i++) */
    /*     er=write(1, &funcdata[i], 1); */
    /* if(er!=1) */
    /* { */
    /*     finishmain(); */
    /*     write(2, "\nError sigproc()\n", 17); */
    /*     abort(); */
    /* } */
    CTRLC=1;
}

/* ---------------------------------------------------------------------- */
/* Print only if Control-c is pressed */
void ctrlc_printf(char *fmt, ...)
{
    va_list args;
    int i=CTRLC;
   
    CTRLC=0;
    if(i)
    {
        /* printf("Func: %s", funcname); */
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
        sleep(1);
    }
    return;
}

/* ---------------------------------------------------------------------- */
/* Control-\ ends all */
void quitproc()
{                
    signal(SIGQUIT, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    signal(SIGALRM, SIG_DFL);
    /* (void)write(2,"\nctrl-\\ pressed!\n", 17); */
    abort();
    /* printf("\nctrl-\\ pressed!\n"); */
    /* printf("Func: %s\n", funcname); */
    /* printf("Data: %s\n", funcdata); */
    /* printf("Aborting...\n"); */
    /* exit(0); */
}

/* ---------------------------------------------------------------------- */
/* The answer should be ready in just one minute */
void oneminuterule()
{
    write(1, "\n ---- One minute rule broken ! ----\n", 37);
    alarm(ONEMINUTE);
}

/* ---------------------------------------------------------------------- */

/* ...your functions here */


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

