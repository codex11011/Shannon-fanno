
#include <stdio.h>
#include <string.h>

extern int sum_freq;
extern int count;
extern int arr_str[1000];

struct node
{
    char sym[10];
    float pro;
    int arr[20];
    int top;
} s[20];

typedef struct node node;

void frequency(char *str, int string_length)
{
    int c = 0, i, j = 0, k, space = 0;
    char p[50][100], str1[20], ptr1[50][100];
    char *ptr;

    // printf("Enter the string\n");
    // scanf(" %[^\n]s", str);
    printf("\nstring length --> %d\n", strlen(str));
    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] == ' ') || (str[i] == ', ') || (str[i] == '.'))
        {
            space++;
        }
    }
    for (i = 0, j = 0, k = 0; j < strlen(str); j++)
    {
        if ((str[j] == ' ') || (str[j] == 44) || (str[j] == 46))
        {
            p[i][k] = '\0';
            i++;
            k = 0;
        }
        else
            p[i][k++] = str[j];
    }
    k = 0;
    for (i = 0; i <= space; i++)
    {
        for (j = 0; j <= space; j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        for (j = 0; j <= space; j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }
        printf("%s -> %d times\n", ptr1[i], c);
        strcpy(s[i].sym, ptr1[i]);
        arr_str[i] = c;
        sum_freq += arr_str[i];
        c = 0;
    }
}