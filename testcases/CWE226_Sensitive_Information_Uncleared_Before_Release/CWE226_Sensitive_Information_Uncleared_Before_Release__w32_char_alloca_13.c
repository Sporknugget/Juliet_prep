/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE226_Sensitive_Information_Uncleared_Before_Release__w32_char_alloca_13.c
Label Definition File: CWE226_Sensitive_Information_Uncleared_Before_Release__w32.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 226 Sensitive Information Uncleared Before Release
 * Sinks: alloca
 *    GoodSink: Clear the password buffer before releasing the memory from the stack
 *    BadSink : Release password from the stack without first clearing the buffer
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE226_Sensitive_Information_Uncleared_Before_Release__w32_char_alloca_13_bad()
{

    {
        {
            char * password = (char *)ALLOCA(100*sizeof(char));
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
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
                        &hUser) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
            /* FLAW: Release password from the stack without first clearing the buffer */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            char * password = (char *)ALLOCA(100*sizeof(char));
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
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
                        &hUser) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
            passwordLen = strlen(password);
            /* FIX: Clear password prior to release from stack */
            SecureZeroMemory(password, passwordLen * sizeof(char));
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            char * password = (char *)ALLOCA(100*sizeof(char));
            size_t passwordLen = 0;
            HANDLE hUser;
            char * username = "User";
            char * domain = "Domain";
            /* Initialize password */
            password[0] = '\0';
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
                        &hUser) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
            passwordLen = strlen(password);
            /* FIX: Clear password prior to release from stack */
            SecureZeroMemory(password, passwordLen * sizeof(char));
        }
    }
}

void CWE226_Sensitive_Information_Uncleared_Before_Release__w32_char_alloca_13_good()
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
    CWE226_Sensitive_Information_Uncleared_Before_Release__w32_char_alloca_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE226_Sensitive_Information_Uncleared_Before_Release__w32_char_alloca_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
