/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15.c
Label Definition File: CWE252_Unchecked_Return_Value__w32ImpersonateSelf.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks:
 *    GoodSink: Check the return value of ImpersonateSelf() and handle it properly
 *    BadSink : Do not check if ImpersonateSelf() fails
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32")

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_bad()
{



        /* FLAW: Do not check if ImpersonateSelf() fails */
        ImpersonateSelf(SecurityImpersonation);






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







        /* FIX: Check to see if ImpersonateSelf() fails */
        if (!ImpersonateSelf(SecurityImpersonation))
        {
            exit(1);
        }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



        /* FIX: Check to see if ImpersonateSelf() fails */
        if (!ImpersonateSelf(SecurityImpersonation))
        {
            exit(1);
        }






}

void CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_good()
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
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__w32ImpersonateSelf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif