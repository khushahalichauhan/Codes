#include <stdio.h>

// sum of first n natural numbers-----------------------------
 int sum(int n)
 {
     if (n == 0)
     {
         return 0;
     }
     return sum(n - 1) + n;
 }
 int main()
 {
     int r;
     r = sum(5);
     printf("%d", r);
     return 0;
 }

// finding factorial------------------------------------------
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return fact(n - 1) * n;
}
int main()
{
    int r;
    r = fact(5);
    printf("%d", r);
    return 0;
}

// power of a number using recursion------------------------
int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return power(m, n - 1) * m;
}
int main()
{
    int r;
    r = power(3, 4);
    printf("%d", r);
    return 0;
}

// another code for power of a number using recursion---------------------
int power1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power1(m * m, n / 2);
    }
    return m * power1(m * m, (n - 1) / 2);
}
int main()
{
    int r;
    r = power1(2, 9);
    printf("%d", r);
    return 0;
}

// taylor series e^x---------------------------------------
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main()
{
    printf("%1f \n", e(4, 15));
    return 0;
}

// taylor series e^x usinh honers rule---------------------------------------
double e(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return e(x, n - 1);
}

int main()
{
    printf("%1f \n", e(4, 15));
    return 0;
}

// fibonacci series - memoization technique also included--------------
int F[10]; // initialise a global array
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = mfib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = mfib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    printf("%d", mfib(6));
}

// combination formula using pascals triangle-----------------------
int C(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return C(n - 1, r - 1) + C(n - 1, r);
}
int main()
{
    printf("%d \n", C(5, 3));
    return 0;
}

// tower of hanoi problem-----------------------------
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("(%d,%d)\n", A, C);
        TOH(n - 1, B, A, C);
    }
}
int main()
{
    TOH(4, 1, 2, 3);
    return 0;
}

// ---------------------------------------------------------
void count(int n)

{

    static int d = 1;

    printf("%d", n);

    printf("%d", d);

    d++;

    if (n > 1)
        count(n - 1);

    printf("%d", d);
}

void main()

{

    count(3);
}