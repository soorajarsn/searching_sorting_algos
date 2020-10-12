
    #include<stdio.h>
    #include"./sorting.h"
    #include"./helper.h"
    #include<stdlib.h>
    int main(){
        int n;
        inputSize(&n);
        // printf("BUBBLE SORT");
        // useAlgo(bubbleSort,n);
        // printf("\nINSERTION SORT");
        // useAlgo(insertionSort,n);
        // printf("\nSELECTION SORT");
        // useAlgo(selectionSort,n);
        // printf("\nMERGE SORT");
        // useAlgo(useMergeSort,n);
        // printf("\nHEAP SORT");
        // useAlgo(heapSort,n);
        // printf("Sorted Array worst Case Quick Sort");
        // useAlgo(useQuickSort,n);
        // printf("\n Sorted Array Best Case Quick Sort\n");
        // useAlgo(useQuickSort_sortedBest,n);
        printf("\n Counting Sort ");
        useAlgo(CountingSort,n);
        printf("\n Radix Sort");
        useAlgo(radixSort,n);
        return 0;
    }
