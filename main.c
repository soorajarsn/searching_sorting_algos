
    #include<stdio.h>
    #include"./sorting.h"
    #include"./helper.h"
    #include<stdlib.h>
    int main(){
        int n;
        inputSize(&n);
        printf("BUBBLE SORT");
        // useAlgo(bubbleSort,n);
        printf("\nINSERTION SORT");
        useAlgo(insertionSort,n);
        printf("\nSELECTION SORT");
        useAlgo(selectionSort,n);
        printf("\nMERGE SORT");
        useAlgo(useMergeSort,n);
        printf("\nHEAP SORT");
        useAlgo(heapSort,n);
        return 0;
    }
