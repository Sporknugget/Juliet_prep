/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__semicolon_02.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: semicolon
 *    GoodSink: Removed statement that has no effect
 *    BadSink : A statement that has no effect
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__semicolon_02_bad()
{

    {
        /* FLAW: the statement has no effect */
        ;
        printLine("Hello from bad()");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        /* FIX: Do not include a statement that has no effect */
        printLine("Hello from good()");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        /* FIX: Do not include a statement that has no effect */
        printLine("Hello from good()");
    }
}

void CWE398_Poor_Code_Quality__semicolon_02_good()
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
    CWE398_Poor_Code_Quality__semicolon_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__semicolon_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
