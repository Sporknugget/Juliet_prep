/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__addition_18.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: addition
 *    GoodSink: Adding two ints and storing the result
 *    BadSink : Adding two ints but not storing the result has no effect
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__addition_18_bad()
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

/* good1() reverses the blocks on the goto statement */
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

void CWE398_Poor_Code_Quality__addition_18_good()
{
    good1();
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
    CWE398_Poor_Code_Quality__addition_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__addition_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
