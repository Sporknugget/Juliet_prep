/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE483_Incorrect_Block_Delimitation__semicolon_14.c
Label Definition File: CWE483_Incorrect_Block_Delimitation.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 483 Incorrect Block Delimitation
 * Sinks: semicolon
 *    GoodSink: Absence of suspicious semicolon
 *    BadSink : Suspicious semicolon before the if statement brace
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE483_Incorrect_Block_Delimitation__semicolon_14_bad()
{

    {
        {
            int x = (rand() % 3);
            int y = 0;
            /* FLAW: Suspicious semicolon before the if statement brace */
            if (x == 0);
            {
                printLine("x == 0");
                y = 1;
            }
            if (y)
            {
                printLine("x was 0\n");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            int x = (rand() % 3);
            int y = 0;
            /* FIX: Removed suspicious semicolon before the if statement brace */
            if (x == 0)
            {
                printLine("x == 0");
                y = 1;
            }
            if (y)
            {
                printLine("x was 0\n");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            int x = (rand() % 3);
            int y = 0;
            /* FIX: Removed suspicious semicolon before the if statement brace */
            if (x == 0)
            {
                printLine("x == 0");
                y = 1;
            }
            if (y)
            {
                printLine("x was 0\n");
            }
        }
    }
}

void CWE483_Incorrect_Block_Delimitation__semicolon_14_good()
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
    CWE483_Incorrect_Block_Delimitation__semicolon_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE483_Incorrect_Block_Delimitation__semicolon_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif