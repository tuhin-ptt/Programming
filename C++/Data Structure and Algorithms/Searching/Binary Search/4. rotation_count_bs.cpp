/* This program counts how many times a given sorted array is rotated */
/* After rotating a sorted array, a transition from big to small number occurs inside the array.
The index of that small number is the solution of this problem. */
#include<iostream>
using namespace std;
int rotation_count_bs(int *arr, int n){
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(mid>l && arr[mid]<arr[mid-1]){
            ans = mid;
            break;
        }
        else if(mid<r && arr[mid]>arr[mid+1]){
            ans = mid+1;
            break;
        }
        if(arr[mid] > arr[r]) l = mid+1;
        else r = mid-1;
    }
    return ans;
}

int main()
{
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter a rotated sorted array of size "<<n<<": ";
    for(int i=0; i<n; i++) cin>>arr[i];

    int ans = rotation_count_bs(arr, n);
    cout<<"Number of times arr is rotated: "<<ans<<endl;
}
