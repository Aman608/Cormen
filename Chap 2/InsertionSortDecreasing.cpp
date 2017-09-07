#include<bits/stdc++.h>
using namespace std;
void insertion_sort_decreasing(int a[], int n)
{
    int x,j;
    for(int i = 1;i<n;i++)
    {
        x = a[i];
        j = i-1;

        while(j>=0 && x > a[j])
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = x;
    }
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {2,3,7,5,1};
    insertion_sort_decreasing(a,5);
    printArray(a,5);
}
