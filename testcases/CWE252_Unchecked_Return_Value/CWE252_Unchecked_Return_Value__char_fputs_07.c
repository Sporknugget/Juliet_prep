/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_fputs_07.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fputs
 *    GoodSink: Check if fputs() fails
 *    BadSink : Do not check if fputs() fails
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__char_fputs_07_bad()
{

    {
        /* FLAW: Do not check the return value */
        fputs("string", stdout);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        /* FIX: check the return value */
        if (fputs("string", stdout) == EOF)
        {
            printLine("fputs failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        /* FIX: check the return value */
        if (fputs("string", stdout) == EOF)
        {
            printLine("fputs failed!");
        }
    }
}

void CWE252_Unchecked_Return_Value__char_fputs_07_good()
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
    CWE252_Unchecked_Return_Value__char_fputs_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_fputs_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
