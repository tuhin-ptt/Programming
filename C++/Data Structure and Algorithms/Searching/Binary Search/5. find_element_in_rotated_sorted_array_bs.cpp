/* This program finds the index of a query element in rotated sorted array */
/* A rotated sorted array can be treated as concatenation two individual sorted arrays. First we
have to  find the transition point from big to small value inside the array. At this transition point
we will break the original array into two arrays. then we will apply binary search in both arrays. */

#include<iostream>
using namespace std;
int find_transition_point(int *arr, int n){ //this function is similar to rotation_count_bs
    int l = 0;
    int r = n-1;
    int point = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(mid>l && arr[mid]<arr[mid-1]){
            point = mid;
            break;
        }
        else if(mid<r && arr[mid]>arr[mid+1]){
            point = mid+1;
            break;
        }
        if(arr[mid] > arr[r]) l = mid+1;
        else r = mid-1;
    }
    return point;
}

int bin_search(int *arr, int l, int r, int q){
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            return mid;
        }
        else if(q > arr[mid]) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

void find_element(int *arr, int n, int q){
    int tp = find_transition_point(arr, n);
    int ans1 = bin_search(arr, 0, tp-1, q);
    int ans2 = bin_search(arr, tp, n-1, q);
    if(ans1 == -1 and ans2 == -1) cout<<"Not Found"<<endl;
    else{
        int res;
        if(ans1 != -1) res = ans1;
        else res = ans2;
        cout<<"Found at index: "<<res<<endl;
    }
}

int main()
{
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter a rotated sorted array of size "<<n<<": ";
    for(int i=0; i<n; i++) cin>>arr[i];
    int q;
    cout<<"Enter a query to find: ";
    cin>>q;
    find_element(arr, n, q);
}
