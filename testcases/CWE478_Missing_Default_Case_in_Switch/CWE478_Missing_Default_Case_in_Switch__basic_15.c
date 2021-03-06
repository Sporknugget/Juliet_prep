/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE478_Missing_Default_Case_in_Switch__basic_15.c
Label Definition File: CWE478_Missing_Default_Case_in_Switch__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 478 Missing Default Case in Switch
 * Sinks:
 *    GoodSink: Use default case in switch statement
 *    BadSink : No default case in a switch statement
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE478_Missing_Default_Case_in_Switch__basic_15_bad()
{



    {
        const char *charString = "shouldn\'t see this value";
        int x;
        x = (rand() % 3);
        switch (x)
        {
        case 0:
            charString = "0";
            break;
        case 1:
            charString = "1";
            break;
            /* FLAW: x could be 2, and there is no 'default' case for that */
        }
        printLine(charString);
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







    {
        const char *charString = "shouldn\'t see this value";
        int x;
        x = (rand() % 3);
        switch (x)
        {
        case 0:
            charString = "0";
            break;
        case 1:
            charString = "1";
            break;
            /* FIX: provide a 'default' case for other values */
        default:
            return;
        }
        printLine(charString);
    }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



    {
        const char *charString = "shouldn\'t see this value";
        int x;
        x = (rand() % 3);
        switch (x)
        {
        case 0:
            charString = "0";
            break;
        case 1:
            charString = "1";
            break;
            /* FIX: provide a 'default' case for other values */
        default:
            return;
        }
        printLine(charString);
    }






}

void CWE478_Missing_Default_Case_in_Switch__basic_15_good()
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
    CWE478_Missing_Default_Case_in_Switch__basic_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE478_Missing_Default_Case_in_Switch__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
