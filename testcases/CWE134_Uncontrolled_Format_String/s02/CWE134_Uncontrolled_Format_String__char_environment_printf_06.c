/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_printf_06.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__char_environment_printf_06_bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;

    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }

    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodB2G1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;

    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }






    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;

    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* POTENTIAL FLAW: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }

    {
        /* FIX: Specify the format disallowing a format string vulnerability */
        printf("%s\n", data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;






    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }

    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;

    {
        /* FIX: Use a fixed string that does not contain a format specifier */
        strcpy(data, "fixedstringtest");
    }

    {
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        printf(data);
    }
}

void CWE134_Uncontrolled_Format_String__char_environment_printf_06_good()
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
    CWE134_Uncontrolled_Format_String__char_environment_printf_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_environment_printf_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
