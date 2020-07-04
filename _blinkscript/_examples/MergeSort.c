#include <cs50.h>
#include <stdio.h>
#include <string.h>


void merge(int list[], int idx_low, int idx_high, int idx_mid){
    int i, j, k, c[50];
    i = idx_low;
    k = idx_low;
    j = idx_mid + 1; // right side of the array

    while (i <= idx_mid && j <= idx_high){ // check if left side of the array
        if (list[i] < list[j]){ // if left is smaller than right
            c[k] = list[i]; // copy to dummpy array with same index
            // move on to next item
            k++;
            i++;
        }else{
            c[k] = list[j]; // take the right side to the left
            // move on to next item
            k++;
            j++;
        }
    }

    // checking function if the smaller is on the left
    while (i <= idx_mid){ // Left side
        c[k] = list[i];
        k++;
        i++;
    }

    while (j <= idx_high){ // Right side
        c[k] = list[j];
        k++;
        j++;
    }

    for (i = idx_low; i < k; i++){
        list[i] = c[i];
    }
}

void mergeSort (int list[], int idx_low, int idx_high){
    // check if there are items inbetween the index number, by it's value
    if (idx_low < idx_high){

        // find the middle index number
        int idx_mid;
        idx_mid = (idx_low + idx_high) / 2; // mid point moved to the left as the function recurring


        // recurisve, find left side
        mergeSort (list, idx_low, idx_mid); // idx_mid = 6, 3, 1, 0
        // recursive, find right side
        mergeSort (list, idx_mid+1, idx_high); // idx_mid = 4, 6(not smaller than idx_high logically, then return)

        // merge left and right
        merge (list, idx_low, idx_high, idx_mid);

    }

    return;
}

int main(){
    int list[] = {38, 27, 43, 3, 9, 82, 10};

    // index number of low and high position of the index
    int idx_low = 0;
    int idx_high = 6;

    // Recurisive Sort
    mergeSort (list, idx_low, idx_high);

    // Print out the result
    for (int i = 0; i < 6; i++){
        printf("%d\n", list[i]);
    }
}
