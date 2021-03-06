/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE506_Embedded_Malicious_Code__w32_file_attrib_created_08.c
Label Definition File: CWE506_Embedded_Malicious_Code__w32.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 506 Embedded Malicious Code
 * Sinks: file_attrib_created
 *    GoodSink: Do not modify the file's created time attribute
 *    BadSink : Modify the file's created time attribute
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* Note that the FILETIME structure is based on 100-nanosecond intervals.
 * It is helpful to define the following symbols when working with file times.
 * http://support.microsoft.com/kb/188768
 */
#define _SECOND ((INT64)10000000)
#define _MINUTE (60 * _SECOND)
#define _HOUR   (60 * _MINUTE)
#define _DAY    (24 * _HOUR)

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE506_Embedded_Malicious_Code__w32_file_attrib_created_08_bad()
{

    {
        {
            FILETIME ftCreate;
            ULONGLONG qwResult;
            HANDLE hFile = INVALID_HANDLE_VALUE;
            do
            {
                hFile = CreateFile(TEXT("badFile.txt"),
                                   GENERIC_READ | GENERIC_WRITE, /* needed for SetFileTime to work properly */
                                   0,
                                   NULL,
                                   CREATE_ALWAYS,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
                if (hFile == INVALID_HANDLE_VALUE)
                {
                    break;
                }
                if (GetFileTime(hFile,
                                &ftCreate,
                                NULL,
                                NULL) == 0)
                {
                    break;
                }
                /* adapted from http://support.microsoft.com/kb/188768 */
                qwResult = (((ULONGLONG) ftCreate.dwHighDateTime) << 32) + ftCreate.dwLowDateTime;
                /* Subtract 10 days from real creation date */
                qwResult -= 10 * _DAY;
                /* Copy result back into ftCreate */
                ftCreate.dwLowDateTime  = (DWORD)(qwResult & 0xFFFFFFFF);
                ftCreate.dwHighDateTime = (DWORD)(qwResult >> 32);
                /* FLAW: Modify the file's creation time */
                SetFileTime(hFile,
                            &ftCreate,
                            (LPFILETIME)NULL,
                            (LPFILETIME)NULL);
            }
            while (0);
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            HANDLE hFile = CreateFile(TEXT("goodFile.txt"),
                                      GENERIC_READ | GENERIC_WRITE,
                                      0,
                                      NULL,
                                      CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, NULL);
            /* FIX: Do not modify the file's attributes */
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            HANDLE hFile = CreateFile(TEXT("goodFile.txt"),
                                      GENERIC_READ | GENERIC_WRITE,
                                      0,
                                      NULL,
                                      CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, NULL);
            /* FIX: Do not modify the file's attributes */
            if (hFile != INVALID_HANDLE_VALUE)
            {
                CloseHandle(hFile);
            }
        }
    }
}

void CWE506_Embedded_Malicious_Code__w32_file_attrib_created_08_good()
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
    CWE506_Embedded_Malicious_Code__w32_file_attrib_created_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE506_Embedded_Malicious_Code__w32_file_attrib_created_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
