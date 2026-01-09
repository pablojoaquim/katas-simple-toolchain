/*===========================================================================*/
/**
 * @file katas.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Develop the code to solve the kata in this file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - @todo Update list of other applicable standards
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
// int working_arr[100];

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

 void printArr (int curr, size_t len, int *arr)
 {
    printf("-- %d ---", curr);
    for (size_t i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
 }

/*****************************************************************************
 * Name         move_zeros
 * Description  Takes an array and moves all of the zeros to the end,
 *              preserving the order of the other elements.
 *****************************************************************************/
void move_zeros(size_t len, int *arr)
{
    // mutate arr in place
    int zerosCnt = 0;
    int i=0;
    while(i < (len-zerosCnt))
    {
        printArr(arr[i], len, arr);
        if (arr[i] == 0)
        {
            /* Move all the string one place */
            for (int j = i; j < len; j++)
            {
                arr[j] = arr[j + 1];
            }
            /* Move the '0' at the end of the array */
            arr[len-1]=0;
            /* To avoid reordening the leading 0s already moved */
            zerosCnt++ ;
        }
        else
        {
            i++;
        }
    }
}
