'''This program counts how many times a given sorted array is rotated'''
'''After rotating a sorted array, a transition from big to small number occurs inside the array.
The index of that small number is the solution of this problem.'''
def rotation_count_bs(arr):
    ans = 0
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l+r)/2)
        if mid>l and arr[mid]<arr[mid-1]:
            ans = mid
            break
        elif mid<r and arr[mid]>arr[mid+1]:
            ans = mid + 1
            break
        if arr[mid] > arr[r]:
            l = mid + 1
        else:
            r = mid - 1
    return ans

arr  = list(map(int, input("Enter a rotated sorted array: ").strip().split()))
ans = rotation_count_bs(arr)
print("Number of times arr is rotated: ", ans)