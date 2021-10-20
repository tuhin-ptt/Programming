int bin_search(vector<int> &A, int B, int l, int r)
{
    if(A[l] < A[r])
    {
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(B == A[mid])
            {
                return mid;
            }
            else if(B > A[mid])  l = mid+1;
            else r = mid -1;
        }
    }
    else
    {
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(B == A[mid])
            {
                return mid;
            }
            else if(B > A[mid])  r = mid-1;
            else l = mid+1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B)
{
    int l = 0;
    int r = A.size() - 1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1])
        {
            int ans1 = bin_search(A, B, 0, mid);
            int ans2 = bin_search(A, B, mid+1, A.size()-1);
            if(ans1 == -1 && ans2 == -1) return -1;
            else if(ans1 == -1) return ans2;
            else return ans1;
        }
        else if(A[mid] > A[mid-1] && A[mid] < A[mid+1]) l = mid+1;
        else if(A[mid] < A[mid-1] && A[mid] > A[mid+1]) r = mid-1;
    }
}