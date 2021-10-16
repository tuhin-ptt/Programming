'''This program finds the index of a query element in rotated sorted array'''
'''A rotated sorted array can be treated as concatenation two individual sorted arrays. First we
have to  find the transition point from big to small value inside the array. At this transition point
we will break the original array into two arrays. then we will apply binary search in both arrays.'''

def  find_transition_point(arr): #this function is similar to rotation_count_bs 
    point = 0
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l+r)/2)
        if mid>l and arr[mid]<arr[mid-1]:
            point = mid
            break
        elif mid<r and arr[mid]>arr[mid+1]:
            point = mid + 1
            break
        if arr[mid] > arr[r]:
            l = mid + 1
        else:
            r = mid - 1
    return point

def binary_search(arr, l, r, q):
    while l<=r:
        mid = int((l+r)/2)
        if(q == arr[mid]):
            return mid
        elif q > arr[mid]:
            l = mid+1
        else:
            r = mid-1
    return -1

def find_element(arr, q):
    tp = find_transition_point(arr)
    ans1 = binary_search(arr, 0, tp-1, q)
    ans2 = binary_search(arr, tp, len(arr)-1, q)
    if ans1 == -1 and ans2 == -1:
        print("Not Found")
    else:
        res = None
        if ans1 != -1:
            res = ans1
        else:
            res = ans2
        print("Found at index: ", res)


        
arr  = list(map(int, input("Enter a rotated sorted array: ").strip().split()))
q = int(input("Enter a query to find: "))
find_element(arr, q)