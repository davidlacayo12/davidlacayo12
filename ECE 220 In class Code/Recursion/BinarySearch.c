#include <stdio.h>

    int BinarySearch(int item, int list[], int start, int end);
    int linearSearch(int array[], int L, int H, int key);
    int binarySearch(int array[], int L, int H, int key);
    int binarySearch_rec(int array[], int L, int H, int key);

    int main(){
        int key;
        int array[5] = {1, 3, 5, 11, 20};
        
        printf("Enter key value: \n");
        scanf("%d", &key);

        printf("Index of key  is : %d\n", binarySearch(array, 0, 5, key));

    } 

    int BinarySearch(int item, int list[], int start, int end){

        int middle = (end-start)/2;

        if(end<start){                                          //not find what we were looking for?
            return -1;
        }

        else if(list[middle] == item){                          //find item? 
            return middle;
        }

        else if(item < list[middle]){                           //checks if we should search first half of array
            return BinarySearch(item, list, start, middle-1);
        }

        else{
            return BinarySearch(item, list, middle+1, end);     //or should we search through second half of the array?
        }


}

int linearSearch(int array[], int L, int H, int key){

    for(int i =L; i < H; i++){
        if(array[i] == key){        //compares item in array to the key --> if not equivalent loops back to next item
            return array[i];        //found item 
        }
        else{
            return -1;              //no item in the array 
        }       
    }


}

int binarySearch(int array[], int L, int H, int key){
    int M;
    while(H >= L ){
        M = (L+H)/2;
            if( array[M] == key){       //compares middle item to key 
                return M;               //found item
            }
            else if(array[M] < key ){
                L = M + 1;              //search second half of the array if key is greater than middle item
            }
            else{
                H = M-1;                //search first half of the array if key is less than middle item
            }
            

    }
}

int binarySearch_rec(int array[], int L, int H, int key){
    int mid;    //index
    mid = (L+H)/2;
    if(L > H){
        return -1;      //base case
    }
    else if(key == array[mid]){
        return mid;         //base case
    }
    else if(key >array[mid]){
        return binarySearch_rec(array, mid+1, H, key);
    }
    else //key < array[mid]
        return binarySearch_rec(array, L, mid-1, key);

}