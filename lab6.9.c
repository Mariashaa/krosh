#include <stdio.h>        // подключаем заголовочный файл stdio.h
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h> 

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
}

int* GetArrayDels(int num, int* len)
{
    int array_dels[100];
    int k = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            array_dels[k] = i;
            k++;
        }
    }
    *len = k - 1;
    /*
    printf("\n %d", num);
    for (int i = 0; i < k ; i++)
    {
        printf("\nArray[%d] = %d", i, array_dels[i]);
    }
    printf("\n");
    */
    return array_dels;
}

// ѕоиск пары двух взаимно простых чисел
bool SearchPair(int a, int b)
{        
    int len1, len2;
    int* array_a = GetArrayDels(abs(a), &len1);
    int* array_b = GetArrayDels(abs(b), &len2);
    bool f = true;    // числа взаимно-простые
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
        {
            if (array_a[i] == array_b[i] && array_a[i] != 1)
            {
                f = false; // числа Ќ≈ взаимно простые
                i = len1;
                break;
            }
        }
    return f;
}

int FindIndexMax(int* main_array, int len)
{
    int max = main_array[0];
    int max_index = 0;
    for (int i = 1; i < len; i++)
    {
        if (max < main_array[i])
        {
            max = main_array[i];
            max_index = i;
        }            
    }
    return max_index;
}

int FindIndexMin(int* main_array, int len)
{
    int min = main_array[0];
    int min_index = 0;
    for (int i = 1; i < len; i++)
    {
        if (min > main_array[i])
        {
            min = main_array[i];
            min_index = i;
        }
    }
    return min_index;
}

void Replace(int i, int j, int* main_array, int len)
{
    printf("\nЌайдено два взаимно простых числа:");
    printf("\n %d %d \n", main_array[i], main_array[j]);  // ¬ывод двух взаимно простых чисел
    int index_min_in_pair, index_max_in_pair;
    if (main_array[i] > main_array[j])
    {
        index_min_in_pair = j;
        index_max_in_pair = i;
    }
    else
    {
        index_min_in_pair = i;
        index_max_in_pair = j;
    }
   // printf("\n %d %d \n", index_max_in_pair, index_min_in_pair);
    int index_max = FindIndexMax(main_array, len);
   // printf("\n %d %d \n", index_max, index_min);
 
    if (index_min_in_pair != index_max)
    {
        // ћен€ем меньшее из них местами с максимум в исходном массиве
        int temp = main_array[index_min_in_pair];
        main_array[index_min_in_pair] = main_array[index_max];
        main_array[index_max] = temp;
        // ќбновл€ем индекс минимального в паре при необходимости        
        temp = index_min_in_pair;
        index_min_in_pair = index_max;
        if (index_max_in_pair == index_max)
        {
            index_max = temp;
            index_max_in_pair = temp;
        }
        else
        {
            index_max = temp;
        }
    }

     int index_min = FindIndexMin(main_array, len);
    // ћен€ем большее из них местами с минимумом в исходном массиве
    if (index_max_in_pair != index_min)
    {
        int temp = main_array[index_max_in_pair];
        main_array[index_max_in_pair] = main_array[index_min];
        main_array[index_min] = temp;
        // ќбновл€ем индекс минимального в паре при необходимости        
        temp = index_max_in_pair;
        index_max_in_pair = index_min;
        if (index_min_in_pair == index_min)
        {
            index_min = temp;
            index_min_in_pair = temp;
        }
        else
        {
            index_min = temp;
        }
    }
}

int main(void)                  // определ€ем функцию main
{                               // начало функции
    char* locale = setlocale(LC_ALL, "");
 
    srand(time(NULL));
    int n = 0;
    printf(" n -> ");
    scanf_s("%d", &n);
    int A[100];
    fill(n, A);
    int i,j;
    printf("\n»сходный массив: \n");
    for (i = 0; i < n; i++)
        printf("%4d ", A[i]);

    bool f = false;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
    {
            if (SearchPair(A[i], A[j]))
            {
                Replace(i, j, A, n);
                i = n;
                f = true;
                break;
            }                
    }

    
    if (f)
    {
        printf("–езультат перестановки: \n");
        for (i = 0; i < n; i++)
            printf("%4d ", A[i]);
    }
    else
    {
        printf("¬заимно простых чисел не найдено. \n");
    }


    return 0;                   // выходим из функции
}                          

// конец функции
