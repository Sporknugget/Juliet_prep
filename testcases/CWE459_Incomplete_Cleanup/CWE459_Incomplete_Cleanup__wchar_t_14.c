/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE459_Incomplete_Cleanup__wchar_t_14.c
Label Definition File: CWE459_Incomplete_Cleanup.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 459 Incomplete Cleanup
 * Sinks:
 *    GoodSink: Clean up properly
 *    BadSink : Don't unlink
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _wunlink
#define FOPEN _wfopen
#define MKTEMP _wmktemp
#else
#include <unistd.h>
#define UNLINK unlink
#define FOPEN fopen
#define MKTEMP mktemp
#endif

#ifndef OMITBAD

void CWE459_Incomplete_Cleanup__wchar_t_14_bad()
{

    {
        {
            wchar_t * filename;
            wchar_t tmpl[] = L"badXXXXXX";
            FILE *pFile;
            /* Establish that this is a temporary file and that it should be deleted */
            filename = MKTEMP(tmpl);
            if (filename != NULL)
            {
                pFile = FOPEN(filename, L"w");
                if (pFile != NULL)
                {
                    fprintf(pFile, "Temporary file");
                    fclose(pFile);
                    /* FLAW: We don't unlink */
                }
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            wchar_t * filename;
            wchar_t tmpl[] = L"goodXXXXXX";
            FILE *pFile;
            /* Establish that this is a temporary file and that it should be deleted */
            filename = MKTEMP(tmpl);
            if (filename != NULL)
            {
                pFile = FOPEN(filename, L"w");
                if (pFile != NULL)
                {
                    fprintf(pFile, "Temporary file");
                    fclose(pFile);
                    /* FIX: Unlink the temporary file */
                    UNLINK(filename); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
                }
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            wchar_t * filename;
            wchar_t tmpl[] = L"goodXXXXXX";
            FILE *pFile;
            /* Establish that this is a temporary file and that it should be deleted */
            filename = MKTEMP(tmpl);
            if (filename != NULL)
            {
                pFile = FOPEN(filename, L"w");
                if (pFile != NULL)
                {
                    fprintf(pFile, "Temporary file");
                    fclose(pFile);
                    /* FIX: Unlink the temporary file */
                    UNLINK(filename); /* EXPECTED INCIDENTAL: CWE367 TOCTOU - This POSIX API is essentially insecure by design */
                }
            }
        }
    }
}

void CWE459_Incomplete_Cleanup__wchar_t_14_good()
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
    CWE459_Incomplete_Cleanup__wchar_t_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE459_Incomplete_Cleanup__wchar_t_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
