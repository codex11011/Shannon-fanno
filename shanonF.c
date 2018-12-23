#include "frequency.c"
// #include "stdafx.h"
#include <stdio.h>
int arr_str[1000];
int count = 0;
int g_level = 0;

void shannon(int start, int end, int arr_x[500], char code[50][50], int level)
{
    int i = start;
    int j = end;
    int isum = arr_x[i], jsum = arr_x[j];

    if (level > g_level)
    {
        g_level = level;
    }
    while (i < (j - 1))
    {
        while (isum > jsum && i < (j - 1))
        {
            j--;
            jsum += arr_x[j];
        }
        while (isum < jsum && i < (j - 1))
        {
            i++;
            isum += arr_x[i];
        }
    }

    if (i == start)
    {
        code[start][level] = '0';
    }
    else if ((i - start) >= 1)
    {
        for (int k = start; k <= i; ++k)
            code[k][level] = '0';

        shannon(start, i, arr_x, code, level + 1);
    }
    if (j == end)
    {
        code[end][level] = '1';
    }
    else if ((end - j) >= 1)
    {
        for (int k = j; k <= end; ++k)
            code[k][level] = '1';

        shannon(j, end, arr_x, code, level + 1);
    }
}

int main(int argc, char *argv[])
{
    int arr[500];
    int n, i, j;
    char str[100];
    int string_length;
    printf("Enter input string\n");
    scanf(" %[^\n]s", str);
    string_length = strlen(str);
    // printf("Enter the number of symbols :");
    // scanf("%d", &n);
    int count_strlength = strlen(str);
    frequency(str, string_length);
    printf("type of words -> %d\n", count);

    printf("frequency unsorted ->\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", arr_str[i]);
    }

    // Take the symbols and sort them as user enters them using insertion sort

    for (i = 0; i < count; ++i)
    {
        int s = arr_str[i];
        // printf("Enter symbol frquency : ");
        // scanf("%d", &s);
        j = i;
        while (j && arr[j - 1] < s)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = s;
    }

    printf("frequency sorted ->\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", arr[i]);
    }

    char code[50][50];

    for (i = 0; i < count; ++i)
    {
        // Mark row as invalid
        for (j = 0; j < count; j++)
        {
            code[i][j] = 'X';
        }
    }

    shannon(0, count - 1, arr, code, 0);

    printf("\n\n DATA  CODE\n");
    // Print the data and code
    for (i = 0; i < count; ++i)
    {
        printf("\n %4d  : ", arr[i]);
        for (j = 0; j <= g_level; j++)
        {
            if (code[i][j] != 'X')
                printf("%c", code[i][j]);
        }
    }

    printf("\n\n");
    return 0;
}
