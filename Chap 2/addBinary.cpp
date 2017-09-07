#include<bits/stdc++.h>
using namespace std;
void addBinary(int a[], int b[], int c[], int n)
{
    int carry = 0;
    for(int i=n-1;i>=0;i--) //index 0 taken to be most significant bit.
    {
        c[i+1] = (a[i]+b[i] + carry)%2;
        if(a[i]+b[i]+carry > 1)
            carry = 1;
        else
            carry = 0;
    }
    c[0] = carry;
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {1,0,0,0};
    int b[] = {1,0,0,1};
    int c[5];
    addBinary(a,b,c,4);
    printArray(c,5);
}
