/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE615_Info_Exposure_by_Comment__w32_08.c
Label Definition File: CWE615_Info_Exposure_by_Comment__w32.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 615 Information Exposure by Comment
 * Sinks:
 *    GoodSink: Do not place username and password in comment
 *    BadSink : Information exposure by comment
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD "ABCD1234!"
#define USERNAME "XXXXX Smith!"

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

void CWE615_Info_Exposure_by_Comment__w32_08_bad()
{

    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FLAW: expose username and password in comment*/
                /* Logged in XXXXX Smith using password ABCD1234 */
                printLine("User logged in successfully" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

void CWE615_Info_Exposure_by_Comment__w32_08_good()
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
    CWE615_Info_Exposure_by_Comment__w32_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE615_Info_Exposure_by_Comment__w32_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
