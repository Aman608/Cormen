#include<bits/stdc++.h>
using namespace std;
int linearSearch(int a[], int key,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			return i;
	}
	return -1;
}
int main()
{
    int a[] = {2,3,7,5,1};
    cout << linearSearch(a,3,5);
}
