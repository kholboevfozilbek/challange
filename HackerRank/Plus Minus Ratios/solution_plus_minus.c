
/*
problem was when u divide int / int 2 ints result will be int
but I needed int / int -> double so there must me typecast for at
least one of the elements

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool condition(int n);
int count_pos(int* arr, int n);
int count_neg(int* arr, int n);
void plus_Minus(int* arr, int n);

int main()
{
    int n, x;

    scanf("%d", &n);

    if (n > 0 && n <= 100)
    {
        int* arr = (int*)malloc(n*sizeof(int));

        for (size_t i=0; i<n; ++i)
        {
            scanf("%d", &x);
            if (condition(x) == true)
                arr[i] = x;
            else
                return -1;
        }

        plus_Minus(arr, n);

    }
    else
    {
        printf("WORNG data");
        return -1;
    }
    return 0;
}

bool condition(int n)
{
    if(n >= -100 && n <= 100)
        return true;
    return false;
}

void plus_Minus(int* arr, int n)
{
    int positives = count_pos(arr, n);
    int negatives = count_neg(arr, n);
    int zeros = n - positives - negatives;

    double pos_prop = positives/(double)n;
    double neg_prop = negatives/(double)n;
    double zero_prop = zeros/(double)n;


    printf("%lf\n%lf\n%lf\n", pos_prop, neg_prop, zero_prop);
}

int count_pos(int* arr, int n)
{
    int counter = 0;
    for (size_t i=0; i<n; ++i)
    {
        if (arr[i] > 0)
            ++counter;
    }
    return counter;
}

int count_neg(int* arr, int n)
{
    int counter = 0;
    for (size_t i=0; i<n; ++i)
    {
        if (arr[i] < 0)
            ++counter;
    }
    return counter;
}
