/* This program finds the floor of a given query in a sorted array */
/* Floor of x: the largest number that is less than or equal to x. For example, floor of 5 in {3,4,7} is 4*/
#include<iostream>
using namespace std;
int find_floor(int *arr, int n, int q){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            ans = q;
            break;
        }
        else if(q > arr[mid]){
            ans = arr[mid]; //since arr[mid]<q, arr[mid] is a candidate floor of q
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}
int main()
{
    int arr[] = {1,2,3,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter a number: ";
    int q;
    cin>>q;
    int ans = find_floor(arr, n, q);
    if(ans == -1) cout<<"Not Found"<<endl;
    else cout<<"Floor is: "<<ans<<endl;
}
