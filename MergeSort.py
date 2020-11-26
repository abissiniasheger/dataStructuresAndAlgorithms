def merge(arr, l, m, r):
  print  "m", m
  print "l", l
  print "r", r
  n1 = m - l + 1
  n2 = r- m
  print "n1", n1
  print "n2", n2
	# create temp arrays 
  L = [0] * (n1) 
  R = [0] * (n2) 
	# Copy data to temp arrays L[] and R[] 
  for i in range(0 , n1):
    L[i] = arr[l + i]
		 

  for j in range(0 , n2):
    R[j] = arr[m + 1 + j]

  i = 0
  j = 0
  k = l

  while i < n1 and j < n2:
    if L[i] <= R[j]:
      arr[k] = L[i]
      i += 1
    else:
      arr[k] = R[j]
      j += 1
    k += 1

  while i < n1:
    arr[k] = L[i]
    i += 1
    k += 1


  while j < n2:
    arr[k] = R[j]
    j += 1
    k += 1

   
def mergeSort(arr, first, last):
  if first < last:
    mid = (first + last - 1)/2
    mergeSort(arr, first, mid)
    mergeSort(arr, mid + 1, last)
    merge(arr, first, mid, last)
# Driver code to test above 
arr = [12, 11, 13, 5] 
n = len(arr) 
print ("Given array is") 
for i in range(n): 
	print ("%d" %arr[i]), 

mergeSort(arr,0,n-1) 
print ("\n\nSorted array is") 
for i in range(n): 
	print ("%d" %arr[i]),
