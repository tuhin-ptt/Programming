'''Binary search basic program'''
def binary_search(arr, q):
    l = 0
    r = len(arr) - 1
    while l<=r:
        mid = int((l+r)/2)
        if(q == arr[mid]):
            print("Found at: ", mid)
            return
        elif q > arr[mid]:
            l = mid+1
        else:
            r = mid-1
    print("Not Found")
    return


arr = [1,2,3,4,5,6,7,10,22]
q = input("Enter a query to search: ")
q = int(q)
binary_search(arr, q)