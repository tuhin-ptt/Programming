'''This program finds the index of first occurrence of a query element in a given sorted array'''
'''When we found the query element, we will look only left of the query to get its first occurrence.'''
def first_occurrence_bs(arr, q):
    ans = -1
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l+r)/2)
        if q == arr[mid]:
            ans = mid #update if q is found in new position
            r = mid-1
        elif q > arr[mid]:
            l = mid+1
        else:
            r = mid-1
    return ans

arr = [1,2,3,4,4,4]
q = int(input("Enter a query to find first occurrence: "))

ans = first_occurrence_bs(arr, q)
if ans == -1:
    print("Not Found")
else:
    print("First occurrence at index: ", ans)