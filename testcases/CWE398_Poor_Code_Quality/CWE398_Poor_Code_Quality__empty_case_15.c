/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_case_15.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_case
 *    GoodSink: Case statement contains code
 *    BadSink : An empty case statement has no effect
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__empty_case_15_bad()
{



        /* FLAW: An empty case statement has no effect */
    {
        int x = (rand() % 3);
        switch (x)
        {
        case 0:


    }
    printLine("Hello from bad()");
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







        /* FIX: Do not include an empty case statement */
    {
        int x = (rand() % 3);
        switch (x)
        {
        case 0:
            printLine("Inside the case statement");


    }
    printLine("Hello from good()");
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{



        /* FIX: Do not include an empty case statement */
    {
        int x = (rand() % 3);
        switch (x)
        {
        case 0:
            printLine("Inside the case statement");


    }
    printLine("Hello from good()");
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE398_Poor_Code_Quality__empty_case_15_good()
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
    CWE398_Poor_Code_Quality__empty_case_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_case_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
