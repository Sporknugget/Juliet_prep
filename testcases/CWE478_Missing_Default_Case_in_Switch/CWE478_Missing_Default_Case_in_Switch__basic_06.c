/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE478_Missing_Default_Case_in_Switch__basic_06.c
Label Definition File: CWE478_Missing_Default_Case_in_Switch__basic.label.xml
Template File: point-flaw-06.tmpl.c
*/
/*
 * @description
 * CWE: 478 Missing Default Case in Switch
 * Sinks:
 *    GoodSink: Use default case in switch statement
 *    BadSink : No default case in a switch statement
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE478_Missing_Default_Case_in_Switch__basic_06_bad()
{

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
}

#endif /* OMITBAD */

#ifndef OMITGOOD










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
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

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
}

void CWE478_Missing_Default_Case_in_Switch__basic_06_good()
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
    CWE478_Missing_Default_Case_in_Switch__basic_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE478_Missing_Default_Case_in_Switch__basic_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif