/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_08.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

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

void CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_08_bad()
{

    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (data == NULL) {exit(-1);}
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
                free(data);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD










    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (data == NULL) {exit(-1);}
            twoIntsStruct * tmpData;
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
            * allocated with realloc() */
            if (tmpData != NULL)
            {
                data = tmpData;
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{

    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            if (data == NULL) {exit(-1);}
            twoIntsStruct * tmpData;
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
            * allocated with realloc() */
            if (tmpData != NULL)
            {
                data = tmpData;
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
}

void CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_08_good()
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
    CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
