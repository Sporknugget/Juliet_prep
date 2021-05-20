/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__addition_15.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: addition
 *    GoodSink: Adding two ints and storing the result
 *    BadSink : Adding two ints but not storing the result has no effect
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__addition_15_bad()
{



    {
        int intOne = 1, intTwo = 1, intSum = 0;
        printIntLine(intSum);
        /* FLAW: the statement has no effect */
        intOne + intTwo; /* This generates a compiler warning, but we expect it to */
        printIntLine(intSum);
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







    {
        int intOne = 1, intTwo = 1, intSum = 0;
        printIntLine(intSum);
        /* FIX: Do not include a statement that has no effect */
        intSum = intOne + intTwo;
        printIntLine(intSum);
    }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



    {
        int intOne = 1, intTwo = 1, intSum = 0;
        printIntLine(intSum);
        /* FIX: Do not include a statement that has no effect */
        intSum = intOne + intTwo;
        printIntLine(intSum);
    }






}

void CWE398_Poor_Code_Quality__addition_15_good()
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
    CWE398_Poor_Code_Quality__addition_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__addition_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif