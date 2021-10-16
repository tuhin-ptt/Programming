/* This program finds the index of first occurrence of a query element in a given sorted array */
/* When we found the query element, we will look only left of the query to get its first occurrence. */
#include<iostream>
using namespace std;
int first_occurrence_bs(int *arr, int n, int q){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            ans = mid; //updates if new q position is found
            r = mid-1;
        }
        else if(q < arr[mid]) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,4,4,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int q;
    cout<<"Enter a query to find first occurrence: ";
    cin>>q;
    int ans = first_occurrence_bs(arr,n,q);
    if(ans == -1) cout<<"Not Found"<<endl;
    else cout<<"First occurrence at index: "<<ans<<endl;
}
