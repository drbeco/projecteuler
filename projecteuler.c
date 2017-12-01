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

/* globals */
char funcname[SBUFF]="", funcdata[SBUFF]=""; /* info to print when interrupted by signal */
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
    sprintf(funcdata, "Starting.\n");
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
/* given a, returns the next prime p > a */
ulong nextprime(ulong a)
{
    ulong p;
    uint i, noprime;
    static ulong *pcache=NULL;
    static uint psize=0, first=1, msg=0;
    ulong *tmp;
    
    strcpy(funcname, __PRETTY_FUNCTION__);
    
    if(first)
    {
        psize=2;
        pcache=malloc(sizeof(2)); /* initial cache */
        pcache[0]=2;
        pcache[1]=3;
        first=0;
    }
    
    for(i=0; i<psize; i++)
        if(pcache[i]>a)
        {
            sprintf(funcdata, "Looking into cache p[%u]=%lu\n", i, pcache[i]);
            return pcache[i];  /* a hit */
        }
        
    /* need more primes (from pcache[i] to p>a)*/
        
    p=pcache[i-1];
    do
    {
        do
        {
            noprime=0;
            p=p+2; /* try this p */
            sprintf(funcdata, "Figuring out if %lu is prime to add to cache p[%u]\n", p, psize-1);
            for(i=0; i<psize; i++)
                if(p%pcache[i]==0)
                {
                    noprime=1;
                    break;
                }
        }while(noprime);
        /* found p next prime in cache, increase cache */
        if(psize>=SAFEMEM || (tmp = realloc(pcache, sizeof(ulong)*(psize+1))) == NULL)
        {
            if(!msg)
            {
                fprintf(stderr, "Run out of memory. No more cache. Need calculations from now on.\n");
                fprintf(stderr, "Last prime on cache p[%u]=%lu\n", psize, p);
                msg=1;
            }
            break;
        }
        psize++;
        pcache = tmp;
        pcache[psize-1]=p; /* add new prime to cache */ 
    }while(p<=a); /* repeat until find p>a or run out of memory or safe guard */
    
    if(p>a)
        return p; /* lucky */
        
    /* run out of memory? old method, lets calc. */  
    do
    {
        do
        {
            noprime=0;
            p+=2; /* try this p */
            sprintf(funcdata, "Figuring out if %lu is prime using cache p[%u] and calculus.\n", p, psize-1);
            /* trying only division by primes */
            for(i=0; i<psize; i++)
                if(p%pcache[i]==0)
                {
                    noprime=1;
                    break;
                }
                
            if(noprime) /* cache says it is no good */
                continue; /* get another p */
                
            /* trying division by all odds after cache */
            for(i=pcache[i]+2; i<=(p/2+1); i++)
                if(p%i==0)
                {
                    noprime=1;
                    break;
                }
        }while(noprime);
    }while(p<=a);
        
    return p;
}

/* ---------------------------------------------------------------------- */
ulong mdc(ulong a, ulong b)
{
    ulong c;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

/* ---------------------------------------------------------------------- */
ulong mmc(ulong a, ulong b)
{
    ulong c;
    for(c=1;;c++)
        if(c%a == 0 && c%b == 0)
            return c;
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */


