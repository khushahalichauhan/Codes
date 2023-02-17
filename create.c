#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    // int A[] = {3,5,7,7,4,5,6};
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c += 1;
        p = p->next;
    }
    return c;
}

int rcount(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return rcount(p->next) + 1;
    }
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int rsum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->data + rsum(p->next);
    }
}

int max(struct Node *p)
{
    int maxx = -32768;
    while (p)
    {
        if (p->data > maxx)
        {
            maxx = p->data;
        }
        p = p->next;
    }
    return maxx;
}

int rmax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return -32768;
    x = rmax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

struct Node *search(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *rsearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data == key)
    {
        return p;
    }
    return (rsearch(p->next, key));
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void sortedinsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    struct Node *temp;
    int A[] = {10, 13, 24, 26, 29, 46, 74, 81, 100};
    create(A, 9);
    display(first);
    printf("\n");
    printf("count: %d\n", count(first));
    printf("count using recursion: %d\n", rcount(first));
    printf("sum: %d\n", sum(first));
    printf("sum using recursion: %d\n", rsum(first));
    printf("max element: %d\n", max(first));
    printf("max element using recursion: %d\n", rmax(first));
    // temp = search(first, 81);
    // printf("search: %d\n", temp->data);
    // display(first);
    // printf("\n");
    temp = rsearch(first, 81);
    printf("recursion search: %d\n", temp->data);
    insert(first, 2, 22);
    display(first);
    printf("\n");
    sortedinsert(first, 55);
    display(first);
    return 0;
}