def quickSort(arr, lo, hi):
    if lo < hi:
        k = partition(arr, lo, hi)
        quickSort(arr, lo, k-1)
        quickSort(arr, k+1, hi)

def partition(arr, lo, hi):
    pivot = arr[hi]
    indexOfPivot = hi
    k = 0
            
    while k < indexOfPivot:
        if arr[k] > pivot:
            tmp = arr[k]
            arr[k] = arr[indexOfPivot-1]
            arr[indexOfPivot-1] = pivot
            arr[indexOfPivot] = tmp
            indexOfPivot = indexOfPivot - 1
            k = k - 1 
        k += 1
    print k
    return k

        
arr = [5, 2, 8, 1, 4, -1, 3, 50, 7, 6, -12, 6]
hi = len(arr) - 1
quickSort(arr, 0, hi)

print "The Sorted Array:"
for j in range(hi+1):
    print arr[j],
    
    