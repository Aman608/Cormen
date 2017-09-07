#include<bits/stdc++.h>
using namespace std;
void swap(int *p, int*q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void selectionSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j;
        int curr_index = i;
        for(j = i+1;j<n;j++)
        {
            if(a[curr_index] > a[j])
            {

                curr_index = j;

            }
        }
        swap(&a[i], &a[curr_index]);
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {10,20,30,40,50};
  selectionSort(a,5);
    printArray(a,5);
}
