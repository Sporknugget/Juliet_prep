/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE482_Comparing_Instead_of_Assigning__basic_04.c
Label Definition File: CWE482_Comparing_Instead_of_Assigning__basic.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 482 Comparing Instead of Assigning
 * Sinks:
 *    GoodSink: Assigning
 *    BadSink : Comparing instead of assigning
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE482_Comparing_Instead_of_Assigning__basic_04_bad()
{

    {
        {
            int intBadSink = 0;
            /* Print original value to avoid any unused variable incidentals */
            printIntLine(intBadSink);
            /* FLAW: meant to assign 5 to intBadSink.  Maintenance note: may generate a compiler warning, this is intentional */
            intBadSink == 5;
            printIntLine(intBadSink);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            int intGoodSink = 0;
            /* Print original value to avoid any unused variable incidentals */
            printIntLine(intGoodSink);
            /* FIX: use = instead of == */
            intGoodSink = 5;
            printIntLine(intGoodSink);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            int intGoodSink = 0;
            /* Print original value to avoid any unused variable incidentals */
            printIntLine(intGoodSink);
            /* FIX: use = instead of == */
            intGoodSink = 5;
            printIntLine(intGoodSink);
        }
    }
}

void CWE482_Comparing_Instead_of_Assigning__basic_04_good()
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
    CWE482_Comparing_Instead_of_Assigning__basic_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE482_Comparing_Instead_of_Assigning__basic_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
