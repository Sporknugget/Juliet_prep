/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int64_t_16.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_int64_t_16_bad()
{
    int64_t data;

    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5LL;

    }

    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10LL;
        printLongLongLine(data);

    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    int64_t data;

    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data = 5LL;

    }

    {
        /* FIX: Use data without over-writing its value */
        printLongLongLine(data);

    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    int64_t data;

    {
        /* FIX: Initialize and use data before it is overwritten */
        data = 5LL;
        printLongLongLine(data);

    }

    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data = 10LL;
        printLongLongLine(data);

    }
}

void CWE563_Unused_Variable__unused_value_int64_t_16_good()
{
    goodB2G();
    goodG2B();
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
    CWE563_Unused_Variable__unused_value_int64_t_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_int64_t_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
