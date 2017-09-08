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
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {27,17,3,16,13,10,1,5,7,12,4,8,9,0};

    max_heapify_iterative(a,2,14);
    printArray(a,14);

}
