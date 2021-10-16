/* This program counts how many times a given element occurs in a sorted array */
/* Find first and last occurrences of given element then subtruct last from first and add 1 to get the result */
#include<iostream>
using namespace std;
int first_occurrence_bs(int *arr, int n, int q){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            ans = mid;
            r = mid-1;
        }
        else if(q < arr[mid]) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int last_occurrence_bs(int *arr, int n, int q){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(q == arr[mid]){
            ans = mid;
            l = mid+1;
        }
        else if(q < arr[mid]) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int count_of_an_element_bs(int *arr, int n, int q){
    int f = first_occurrence_bs(arr, n, q);
    int l = last_occurrence_bs(arr, n, q);
    int ans = -1;
    if(f != -1 && l != -1) ans = l-f+1;
    return ans;
}

int main()
{
    int arr[] = {1,2,4,4,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int q;
    cout<<"Enter an element to find its occurrences: ";
    cin>>q;
    int ans = count_of_an_element_bs(arr, n, q);
    if(ans == -1) cout<<"Not Found"<<endl;
    else cout<<"Occurrences: "<<ans<<endl;
}
