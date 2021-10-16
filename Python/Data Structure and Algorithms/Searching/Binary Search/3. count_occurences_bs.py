'''This program counts how many times a given element occurs in a sorted array'''
'''Find first and last occurrences of given element then subtruct last from first and add 1 to get the result'''

def first_occurrence_bs(arr, q):
    ans = -1
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l+r)/2)
        if q == arr[mid]:
            ans = mid
            r = mid-1
        elif q > arr[mid]:
            l = mid+1
        else:
            r = mid-1
    return ans

def last_occurrence_bs(arr, q):
    ans = -1
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = int((l+r)/2)
        if q == arr[mid]:
            ans = mid
            l = mid+1
        elif q > arr[mid]:
            l = mid+1
        else:
            r = mid-1
    return ans

def count_of_an_element_bs(arr, q):
    f = first_occurrence_bs(arr, q)
    l = last_occurrence_bs(arr, q)
    ans = -1
    if f != -1 and l != -1:
        ans = l-f+1
    return ans


arr = [1,2,3,4,4,4]
q = int(input("Enter an element to count occurrences: "))

ans = count_of_an_element_bs(arr, q)
if ans == -1:
    print("Not Found")
else:
    print("Total Occurrences: ", ans)