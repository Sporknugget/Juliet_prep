/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__zero_14.c
Label Definition File: CWE617_Reachable_Assertion__zero.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * Sinks:
 *    GoodSink: assert(true), which will never trigger
 *    BadSink : assert(false), which will always trigger
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#ifndef OMITBAD

void CWE617_Reachable_Assertion__zero_14_bad()
{

    {
        /* FLAW: this assertion can be reached, and will always trigger */
        assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
        * function, assert(1)
        */
        assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
        * function, assert(1)
        */
        assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
    }
}

void CWE617_Reachable_Assertion__zero_14_good()
{
    good1();
    good2();
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
    CWE617_Reachable_Assertion__zero_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__zero_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif