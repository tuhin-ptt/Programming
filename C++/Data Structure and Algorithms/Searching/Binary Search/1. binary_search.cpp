/* Binary search basic program */
#include<iostream>
using namespace std;

void bin_search(int *arr, int n, int q){
    int l=0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            cout<<"Found at index: "<<mid<<endl;
            return;
        }
        else if(q > arr[mid]) l = mid+1;
        else r = mid-1;
    }
    cout<<"Not Found"<<endl;
}

int main()
{
    cout<<"Enter a query to search: ";
    int q;
    cin>>q;
    int arr[] = {1,2,3,4,5,6,7,10,23};
    int n = sizeof(arr)/sizeof(arr[0]);
    bin_search(arr, n, q);
}
