/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_long_05.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_long_05_bad()
{
    long data;

    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5L;
    }

    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10L;
        printLongLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticTrue to staticFalse */
static void goodB2G1()
{
    long data;

    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5L;
    }






    {
        /* FIX: Use data without over-writing its value */
        printLongLine(data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    long data;

    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5L;
    }

    {
        /* FIX: Use data without over-writing its value */
        printLongLine(data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticTrue to staticFalse */
static void goodG2B1()
{
    long data;






    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 5L;
        printLongLine(data);
    }

    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10L;
        printLongLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    long data;

    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 5L;
        printLongLine(data);
    }

    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10L;
        printLongLine(data);
    }
}

void CWE563_Unused_Variable__unused_value_long_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE563_Unused_Variable__unused_value_long_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_long_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
