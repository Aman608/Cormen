#include<bits/stdc++.h>
#include<tuple>
using namespace std;
tuple<int, int, int> find_max_crossing(int a[], int p, int mid, int q)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int left_index, right_index, right_sum = INT_MIN;
    for(int i=mid;i>=p;i--)
    {
        sum = sum+a[i];
        if(sum>left_sum)
        {
            left_index = i;
            left_sum = sum;
        }
    }
    sum = 0;
    for(int i=mid+1;i<=q;i++)
    {
        sum = sum+a[i];
        if(sum > right_sum)
        {
            right_index = i;
            right_sum = sum;
        }
    }
    return make_tuple(left_index, right_index, left_sum+right_sum);
}

tuple<int, int,int> find_max_subarray(int a[], int low, int high)
{
    if(low==high)
    return make_tuple(low,high,a[low]);
    int mid = (high+low)/2;
    int left_low, left_high,left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;
    tie(left_low, left_high,left_sum) = find_max_subarray(a,low,mid);
    tie(right_low, right_high, right_sum) = find_max_subarray(a,mid+1,high);
    tie(cross_low, cross_high, cross_sum) = find_max_crossing(a,low, mid, high);

    if(left_sum >= right_sum && left_sum >= cross_sum)
        return make_tuple(left_low, left_high, left_sum);
    else if(right_sum>= left_sum && right_sum>= cross_sum)
        return make_tuple(right_low, right_high, right_sum);
    else
        return make_tuple(cross_low, cross_high, cross_sum);
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
    tie(i,j,sum) = find_max_subarray(a,0,15);
    cout << sum;
}
