#include<bits/stdc++.h>
#include<tuple>
using namespace std;
tuple<int, int, int> max_subarray_brute(int a[], int n)
{
    int sum=INT_MIN, left_index, right_index,temp=0;
    for(int i=0;i<n;i++)
    {

        temp = 0;
        for(int j=i;j<n;j++)
        {
            temp = temp+a[j];
            if(sum<temp)
            {
                left_index = i;
                right_index = j;
                sum = temp;
            }
        }
    }
    return make_tuple(left_index, right_index, sum);
}
void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}
int main()
{
    int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int i,j,sum;
    tie(i,j,sum) = max_subarray_brute(a,16);
    cout << i<<" " << j<<" " << sum;
}
