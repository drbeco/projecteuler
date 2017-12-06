 /**************************************************************************
 *   PEN.c                                    Version 20170112.001402      *
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

/* ---------------------------------------------------------------------- */
/* includes */
#include "projecteuler.h"

/* ---------------------------------------------------------------------- */
/* defines */
/* Project Euler Exercise Number */
#define PEN pe ## N

/* ---------------------------------------------------------------------- */
/* prototypes */
void PEN(void); /* Proj. Euler problem #PEN */

/* ---------------------------------------------------------------------- */
/* main function */
int main(void)
{
    startmain();
    PEN(); /* Proj. Euler problem #PEN */
    finishmain();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Proj. Euler problem #PEN */
/* Problem description:
 *
 */

void PEN(void)
{
    /* local variables */
    ulong r=0; /* answer */

    /* put this command inside a loop to get previews when pressing CTRL-C */
    /* ctrlc("%s: Trying now %u\n", __FUNCTION__, r); */

    printf("%s: %lu\n", __FUNCTION__, r); /* answer */
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

