/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_05.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two variables below are not defined as "const", but are never
 * assigned any other value, so a tool should be able to identify that
 * reads of these will always return their initialized values.
 */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE665_Improper_Initialization__char_ncat_05_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;

    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the staticTrue to staticFalse */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;






    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;

    {
        /* FIX: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* POTENTIAL FLAW: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_ncat_05_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE665_Improper_Initialization__char_ncat_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__char_ncat_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
