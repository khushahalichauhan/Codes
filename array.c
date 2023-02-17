#include <stdio.h>
#include <stdlib.h>

// creating an array----------------------------------------
//  struct Array
//  {
//      int *A;
//      int size;
//      int length;
//  };

// void Display(struct Array arr)
// {
//     int i;
//     printf("\nElements are\n");
//     for (i = 0; i < arr.length; i++)
//     {
//         printf("%d ", arr.A[i]);
//     }
// }
// int main()
// {
//     struct Array arr;
//     int n, i;
//     printf("Enter the size of array");
//     scanf("%d", &arr.size);
//     arr.A = (int *)malloc(arr.size * sizeof(int));
//     arr.length = 0;
//     printf("enter number of numbers");
//     scanf("%d", &n);
//     printf("Enter all elements\n");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr.A[i]);
//     }
//     arr.length = n;
//     Display(arr);
// }

// inserting and appending items in an array----------------
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]); // swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    printf("%d\n", LinearSearch(&arr, 5));
    Display(arr);
    return 0;
}
