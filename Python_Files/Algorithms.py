''' Just a collection of helpful sort methods, 
    merge methods, conversions and more
'''
import numpy as np
import math

# Merge: Used as helper to MergeSort Method, parameters are arr[0...n] & middle pointer
def merge(arr, middle):
    i = 0
    j = middle + 1
    n = len(arr)
    arr2 = np.zeros(n, dtype=type(arr))
    
    for k in range(0, n):
        if(j > n-1):
            arr2[k] = arr[i]
            i += 1
        elif(i > middle):
            arr2[k] = arr[j]
            j += 1
        elif(arr[i] < arr[j]):
            arr2[k] = arr[i]
            i += 1
        else:
            arr2[k] = arr[j]
            j +=1
    
    for k in range(0, n):
        arr[k] = arr2[k]

# MergeSort: Parameter arr is an array of length n
def mergeSort(arr):
    n = len(arr)
    if(n > 1):
        middle = math.floor(n/2)
        mergeSort(arr[0:middle])
        mergeSort(arr[middle+1:n])
        merge(arr, middle)

    
def main():
    arr = [5,9,1,3,4,45,67,25,89,9,10,100,14,24,23,57,64,45,26]
    print("Array before sorting: ", arr)
    mergeSort(arr)
    print("Array after sorting: ", arr)

main()