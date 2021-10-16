'''This program finds the floor of a given query in a sorted array'''
'''Floor of x: the largest number that is less than or equal to x.
   For example, floor of 5 in {3,4,7} is 4'''

def find_floor(arr, d):
    l = 0
    r = len(arr)-1
    ans = -1
    while l <= r:
        mid = int((l+r)/2)
        if q == arr[mid]:
            ans = q
            break
        elif q > arr[mid]:
            ans = arr[mid] #since arr[mid]<q, arr[mid] is a candidate floor of q
            l = mid+1
        else:
            r = mid-1
    return ans


arr = [1,2,3,4,6,7]
q = int(input("Enter a query to find: "))
ans = find_floor(arr, q)
if ans == -1:
    print("Not Found.")
else:
    print("Floor is: ", ans)