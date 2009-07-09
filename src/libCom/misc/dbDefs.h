/*************************************************************************\
* Copyright (c) 2009 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* $Id$
 *
 *      Author:          Marty Kraimer
 *      Date:            6-1-90
 */

#ifndef INC_dbDefs_H
#define INC_dbDefs_H

#ifdef TRUE
#   undef TRUE
#endif
#define TRUE 1

#ifdef FALSE
#   undef FALSE
#endif
#define FALSE 0

#ifndef LOCAL 
#   define LOCAL static
#endif

/* number of elements in an array */
#ifndef NELEMENTS
#   define NELEMENTS(array) (sizeof (array) / sizeof ((array) [0]))
#endif

/* byte offset of member in structure*/
#ifndef OFFSET
#   define OFFSET(structure, member) ((int) &(((structure *) 0) -> member))
#endif

/*Process Variable Name Size */
/* PVNAME_STRINGSZ includes the nil terminator */
#define PVNAME_STRINGSZ 61
#define PVNAME_SZ (PVNAME_STRINGSZ - 1)

#define DB_MAX_CHOICES 30

#endif /* INC_dbDefs_H */
