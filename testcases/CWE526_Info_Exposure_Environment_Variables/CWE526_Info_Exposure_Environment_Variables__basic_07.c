/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE526_Info_Exposure_Environment_Variables__basic_07.c
Label Definition File: CWE526_Info_Exposure_Environment_Variables__basic.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 526 Information Exposure Through Environment Variables
 * Sinks:
 *    GoodSink: Print a generic error message to the console
 *    BadSink : Expose the contents of an environment variable to the console
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE526_Info_Exposure_Environment_Variables__basic_07_bad()
{

    {
        /* FLAW: environment variable exposed */
        printLine(getenv("PATH"));
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        /* FIX: error message is general */
        printLine("Not in path");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        /* FIX: error message is general */
        printLine("Not in path");
    }
}

void CWE526_Info_Exposure_Environment_Variables__basic_07_good()
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
    CWE526_Info_Exposure_Environment_Variables__basic_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE526_Info_Exposure_Environment_Variables__basic_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
