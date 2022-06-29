#include <iostream>     
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void insertionsort(int list[], int low, int high);
int partition(int list[], int low, int high);
int randPartition(int list[], int low, int high);
void heapsort(int *begin, int *end);
void introsort(int list[], int *begin, int *end, int maxdepth);
void printlist(int list[], int size);

int main()
{
    int list[] = { 5, 7, -8, 9, 10, 4, -7, 0, -12, 1, 6, 2, 3, -4, -15, 12, 57, 36, -42, 68, -92, 74, 33, -4, -102, 23, -26, 107};
    int size = sizeof(list) / sizeof(list[0]);     //calculates size of our array
 
    // get the maximum depth
    int maxdepth = log(size) * 2;
 
    // sort the array using introsort the algorithm
    introsort(list, list, list + size - 1, maxdepth);
 
    // print the sorted array
    printlist(list, size);

    return 0;
}
 
// Function to perform insertion sort on subarray `a[low…high]`
void insertionsort(int list[], int low, int high)
{
    // start from the second element in the subarray (the element at index `low` is already sorted)
    for (int i = low + 1; i <= high; i++)
    {
        int value = list[i];
        int j = i;
 
        // find index `j` within the sorted subset a[0…i-1] where element a[i] belongs
        while (j > low && list[j - 1] > value)
        {
            list[j] = list[j - 1];
            j--;
        }
 
        // Note that the subarray `a[j…i-1]` is shifted to the right by one position, i.e., `a[j+1…i]`
 
        list[j] = value;
    }
}
 
// Function to partition the array using Lomuto partition scheme
int partition(int list[], int low, int high)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = list[high];
 
    // elements less than the pivot will be pushed to the left of `pIndex`-- elements more than the pivot will be pushed to the right of `pIndex` -- equal elements can go either way
    int pIndex = low;
 
    // each time we find an element less than or equal to the pivot, `pIndex` is incremented, and that element would be placed before the pivot.
    for (int i = low; i < high; i++)
    {
        if (list[i] <= pivot)
        {
            swap(list[i], list[pIndex]);
            pIndex++;
        }
    }
 
    // swap `pIndex` with pivot
    swap (list[pIndex], list[high]);
 
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
 
// Quicksort randomized partition to rearrange elements across pivot
int randPartition(int list[], int low, int high)
{
    // choose a random index between `[low, high]`
    int pivotIndex = rand() % (high - low + 1) + low;
 
    // swap the end element with the element present at a random index
    swap(list[pivotIndex], list[high]);
 
    // call the partition procedure
    return partition(list, low, high);
}
 
// Function to perform heapsort on the given range of elements
void heapsort(int *begin, int *end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
 
// Function to perform introsort on the given array
void introsort(int list[], int *begin, int *end, int maxdepth)
{
    // perform insertion sort if partition size is 16 or smaller
    if ((end - begin) < 16) {
        insertionsort(list, begin - list, end - list);
    }
    // perform heapsort if the maximum depth is 0
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        // otherwise, perform Quicksort
        int pivot = randPartition(list, begin - list, end - list);
        introsort(list, begin, list + pivot - 1, maxdepth - 1);
        introsort(list, list + pivot + 1, end, maxdepth - 1);
    }
}

//Function to print our list given an array 
void printlist(int list[], int size){

    for(int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
    cout << " " <<endl;
}
 
