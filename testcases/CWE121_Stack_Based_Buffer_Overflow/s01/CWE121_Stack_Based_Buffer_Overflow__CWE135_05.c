/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_05.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE135_05_bad()
{
    void * data;
    data = NULL;

    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = (void *)WIDE_STRING;
    }

    {
        {
            /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
            (void)wcscpy(dest, data);
            printLine((char *)dest);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second staticTrue to staticFalse */
static void goodB2G1()
{
    void * data;
    data = NULL;

    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = (void *)WIDE_STRING;
    }






    {
        {
            /* FIX: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
            (void)wcscpy(dest, data);
            printWLine((wchar_t *)dest);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    void * data;
    data = NULL;

    {
        /* POTENTIAL FLAW: Set data to point to a wide string */
        data = (void *)WIDE_STRING;
    }

    {
        {
            /* FIX: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
            (void)wcscpy(dest, data);
            printWLine((wchar_t *)dest);
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticTrue to staticFalse */
static void goodG2B1()
{
    void * data;
    data = NULL;






    {
        /* FIX: Set data to point to a char string */
        data = (void *)CHAR_STRING;
    }

    {
        {
            /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * 1);
            (void)strcpy(dest, data);
            printLine((char *)dest);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    void * data;
    data = NULL;

    {
        /* FIX: Set data to point to a char string */
        data = (void *)CHAR_STRING;
    }

    {
        {
            /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)ALLOCA((dataLen+1) * 1);
            (void)strcpy(dest, data);
            printLine((char *)dest);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE135_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE121_Stack_Based_Buffer_Overflow__CWE135_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE135_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif