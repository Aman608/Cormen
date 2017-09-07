#include<bits/stdc++.h>
using namespace std;
int inversion_insertion_sort(int a[], int n)
{
    int x,j,cnt=0;
    for(int i = 1;i<n;i++)
    {
        x = a[i];
        j = i-1;

        while(j>=0 && x < a[j])
        {
            a[j+1] = a[j];
            j = j-1;
            cnt++;
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
    int a[] = {1, 20, 6, 4, 5};
    int inve = inversion_insertion_sort(a,5);
    cout << inve;
}
