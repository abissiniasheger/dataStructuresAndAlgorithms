def selectionSort(arr, sortedArray):
    if len(arr) > 0:
        sortedArray.append(findSmallest(arr))
        selectionSort(arr, sortedArray)

def findSmallest(arr):
    min = arr[0]
    for i in range(len(arr)):
        if min > arr[i]:
            min = arr[i]
    return arr.pop(arr.index(min))
        
arr = [100, 5, 2, 8, 1, 4, -1, 3, 50, 7, 6, -12]
sortedArray = []
selectionSort(arr, sortedArray)

print "The Sorted Array:"
for j in range(len(sortedArray)):
    print sortedArray[j],
    
    