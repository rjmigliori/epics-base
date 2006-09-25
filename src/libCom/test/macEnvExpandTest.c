/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/*
 * $Id$
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "macLib.h"
#include "envDefs.h"
#include "errlog.h"
#include "epicsUnitTest.h"

void check(const char *str, const char *expect)
{
    char *got = macEnvExpand(str);
    int pass = -1;
    if (expect && !got) {
        testDiag("Got NULL, expected \"%s\".\n", expect);
        pass = 0;
    }
    else if (!expect && got) {
        testDiag("Got \"%s\", expected NULL.\n", got);
        pass = 0;
    }
    else if (expect && got && strcmp(got, expect)) {
        testDiag("Got \"%s\", expected \"%s\".\n", got, expect);
        pass = 0;
    }
    testOk(pass, str);
}

int macEnvExpandTest(void)
{
    int warn = 0;
    testPlan(30);

    check("FOO", "FOO");

    check("${FOO}", NULL); warn++;
    check("${FOO=}", "");
    check("x${FOO=}y", "xy");
    check("${FOO=BAR}", "BAR");
    check("x${FOO=BAR}y", "xBARy");

    epicsEnvSet("FOO","BLETCH");
    check("${FOO}", "BLETCH");
    check("x${FOO}y", "xBLETCHy");
    check("x${FOO}y${FOO}z", "xBLETCHyBLETCHz");
    check("${FOO=BAR}", "BLETCH");
    check("x${FOO=BAR}y", "xBLETCHy");
    check("${FOO=${BAZ}}", "BLETCH");
    check("x${FOO=${BAZ}}y", "xBLETCHy");
    check("${BAR=${FOO}}", "BLETCH");
    check("x${BAR=${FOO}}y", "xBLETCHy");
    check("w${BAR=x${FOO}y}z", "wxBLETCHyz");

    epicsEnvSet("BAR","GLEEP");
    check("${FOO}/${BAR}", "BLETCH/GLEEP");
    check("x${FOO}/${BAR}y", "xBLETCH/GLEEPy");
    check("${BAR=${FOO}}", "GLEEP");

    epicsEnvSet("BLETCH","BAR");
    check("${${FOO}}", "BAR");
    check("x${${FOO}}y", "xBARy");
    check("${${FOO}=GRIBBLE}", "BAR");
    check("x${${FOO}=GRIBBLE}y", "xBARy");

    epicsEnvSet("BLETCH","${BAR}");
    check("${${FOO}}", "GLEEP");

    epicsEnvSet("FOO","${BAR}");
    check("${FOO}","GLEEP");

    epicsEnvSet("BAR","${BAZ}");
    check("${FOO}", NULL); warn++;

    epicsEnvSet("BAR","${BAZ=GRIBBLE}");
    check("${FOO}", "GRIBBLE");

    epicsEnvSet("BAR","${STR1}");
    epicsEnvSet("STR1","VAL1");
    epicsEnvSet("STR2","VAL2");
    check("${FOO}", "VAL1");

    epicsEnvSet("BAR","${STR2}");
    check("${FOO}", "VAL2");

    epicsEnvSet("BAR","${FOO}");
    check("${FOO}", NULL); warn++;
    
    testDiag("Expect %d warning messages here:\n", warn);
    errlogFlush();
    return testDone();
}