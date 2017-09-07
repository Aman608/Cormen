#include<bits/stdc++.h>
using namespace std;
void insertionSort_recurrence(int a[],int first, int last)
{
    int i,j,k;
    if(first>=last)
        return;
    else
    {
        insertionSort_recurrence(a, first, last-1 );
        k = a[last];
        j = last - 1;
        while(j>=0 && a[j]>k)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }

}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
  int a[] = {5,4,1,2,3};
  insertionSort_recurrence(a,0,4);
    printArray(a,5);
}
