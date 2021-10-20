
def bin_search(A, B, l, r):
    if A[l] < A[r]:
        
        while l <= r:
            mid = int((l+r)/2)
            if B == A[mid]:
                return mid
            elif B > A[mid]:
                l = mid+1
            else: 
                r = mid - 1
    else:
        
        while l <= r:
            mid = int((l+r)/2)
            if B == A[mid]:
                return mid
            elif B > A[mid]:
                r = mid-1
            else: 
                l = mid + 1
    return -1

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    

    def solve(self, A, B):
        l = 0
        r = len(A) - 1
        while l <= r:
            mid = int((l+r)/2)
            if (mid+1) < len(A) and (mid-1) >=0:
                if A[mid] > A[mid-1] and A[mid] > A[mid+1]:
                    ans1 = bin_search(A, B, 0, mid)
                    ans2 = bin_search(A, B, mid+1, len(A)-1)
                    if ans1 == -1 and ans2 == -1:
                        return -1
                    elif ans1 == -1:
                        return ans2
                    else:
                        return ans1
                elif A[mid] > A[mid-1] and A[mid] < A[mid+1]:
                    l = mid+1
                elif A[mid] < A[mid-1] and A[mid] > A[mid+1]:
                    r = mid-1
