/***************************************************************************
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
 ***************************************************************************/

#include "projecteuler.h"

/* Project Euler Exercise Number */
#define PEN pe ## N

void PEN(void);

/* ---------------------------------------------------------------------- */
/* main function */
int main(void)
{
    startmain(__PRETTY_FUNCTION__);
    PEN();
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Exercise description:
 *
 */

void PEN(void)
{
    ulong r=0; /* answer */
    /* startfunc(__PRETTY_FUNCTION__); */    

    /* answer */
    printf("%s: %lu\n", __FUNCTION__, r);
    return;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */
