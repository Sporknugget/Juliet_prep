/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE535_Info_Exposure_Shell_Error__w32_char_13.c
Label Definition File: CWE535_Info_Exposure_Shell_Error__w32.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 535 Information Exposure Through Shell Error Message
 * Sinks:
 *    GoodSink: Write to stderr, but do not write the password
 *    BadSink : Write to stderr and include the password
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE535_Info_Exposure_Shell_Error__w32_char_13_bad()
{

    {
        {
            char password[100] = "";
            size_t passwordLen = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* FLAW: Write sensitive data to stderr */
            fprintf(stderr, "User attempted access with password: %s\n", password);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            char password[100] = "";
            size_t passwordLen = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* FIX: Do not write sensitive data to stderr */
            fprintf(stderr, "User attempted access\n");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            char password[100] = "";
            size_t passwordLen = 0;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            if (fgets(password, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                password[0] = '\0';
            }
            /* Remove the carriage return from the string that is inserted by fgets() */
            passwordLen = strlen(password);
            if (passwordLen > 0)
            {
                password[passwordLen-1] = '\0';
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* FIX: Do not write sensitive data to stderr */
            fprintf(stderr, "User attempted access\n");
        }
    }
}

void CWE535_Info_Exposure_Shell_Error__w32_char_13_good()
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
    CWE535_Info_Exposure_Shell_Error__w32_char_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE535_Info_Exposure_Shell_Error__w32_char_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
