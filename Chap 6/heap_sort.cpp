#include<bits/stdc++.h>
#include<tuple>
using namespace std;
int left(int i)
{
    return (2*i + 1);
}
int right(int i)
{
    return (2*i+2);
}
int parent(int i)
{
    return (i-1)/2;
}

void swap(int *a, int*b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify_iterative(int a[], int i,int n)
{

    while(true)
    {

    int l = left(i);
    int largest;
    int r = right(i);


    if(l < n && a[l]>a[i])
        largest = l;
    else
        largest = i;
    if(r<n && a[r] > a[largest])
        largest = r;

    if(largest!=i)
    {swap(&a[largest], &a[i]);
     i = largest;
    }
    else
        break;
    }
}

void build_heap(int a[], int n)
{
    int heap_size = n/2 + 1;
    for(int i=heap_size; i>=0;i--)
        max_heapify_iterative(a,i,n);
}
void heap_sort(int a[], int n)
{

    build_heap(a,n);
    for(int i= n-1;i>=1;i--)
    {
        swap(&a[0], &a[i]);
        max_heapify_iterative(a,0,i);
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {70,60,50,4,5,6,7,8,9,10,11,12,13,14,15};

    heap_sort(a,15);
    printArray(a,15);

}
