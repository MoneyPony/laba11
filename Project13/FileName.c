#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
int main()
{
    double arr[100];
    int n;
    setlocale(LC_ALL, "RUS");
    do
    {
        printf("Введите количество элементов массива: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Количество элементов должно быть положительным числом.\n");
        }
    } while (n <= 0);
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
    }
    int min_index = 0, max_index = 0;
    double min_value = arr[0], max_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
            min_index = i;
        }
        if (arr[i] > max_value)
        {
            max_value = arr[i];
            max_index = i;
        }
    }
    double sum = 0, average = 0;
    int count = 0;
    if (min_index < max_index)
    {
        for (int i = min_index + 1; i < max_index; i++)
        {
            sum += arr[i];
            count++;
        }
    }
    else
    {
        for (int i = max_index + 1; i < min_index; i++)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count > 0)
    {
        average = sum / count;
        printf("Среднее арифметическое элементов между минимальным и максимальным элементами: %.2lf\n", average);
    }
    else
        printf("Нет чисел между минимальным и максимальным");
}