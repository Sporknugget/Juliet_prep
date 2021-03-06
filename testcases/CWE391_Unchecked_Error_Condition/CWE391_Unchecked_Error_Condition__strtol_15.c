/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE391_Unchecked_Error_Condition__strtol_15.c
Label Definition File: CWE391_Unchecked_Error_Condition.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 391 Unchecked Error Condition
 * Sinks: strtol
 *    GoodSink: Perform error checks and handling
 *    BadSink : Do not check if strtol() failed
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <errno.h>

#ifndef OMITBAD

void CWE391_Unchecked_Error_Condition__strtol_15_bad()
{



    {
        long longNumber;
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* FLAW: Do not check to see if strtol() failed */
        printf("%li\n", longNumber);
    }






}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{







    {
        long longNumber;
        errno = 0; /* set errno to zero before calling strtol(), which can change its value */
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* FIX: Check errno to see if strtol() failed */
        if (errno == ERANGE)
        {
            printLine("strtol() failed");
            exit(1);
        }
        printf("%li\n", longNumber);
    }


}

/* good2() reverses the blocks in the switch */
static void good2()
{



    {
        long longNumber;
        errno = 0; /* set errno to zero before calling strtol(), which can change its value */
        longNumber = strtol("0xfffffffff", NULL, 0);
        /* FIX: Check errno to see if strtol() failed */
        if (errno == ERANGE)
        {
            printLine("strtol() failed");
            exit(1);
        }
        printf("%li\n", longNumber);
    }






}

void CWE391_Unchecked_Error_Condition__strtol_15_good()
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
    CWE391_Unchecked_Error_Condition__strtol_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE391_Unchecked_Error_Condition__strtol_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
