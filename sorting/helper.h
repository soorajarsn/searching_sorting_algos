
    #include<stdio.h>
    #include<time.h>
    #include<stdlib.h>
    void inputArray(int*,int);
    void inputSize(int*);
    void outputSortedArray(int*,int);
    void outputTimeTaken(clock_t,clock_t);
    void useAlgo(void (*algo)(int*,int),int n);
    void useAlgo(void (*algo)(int*,int),int n){
        clock_t start,end;
        int *arr;
        arr = (int*)malloc(n*sizeof(int));
        inputArray(arr,n);
        start = clock();
        (*algo)(arr,n);
        end = clock();
        outputSortedArray(arr,n);
        outputTimeTaken(start,end);
        free(arr);
    }
    void inputArray(int* arr,int n){
        printf("\nEnter %d integers: ",n);
        for(int i = 0; i < n; i++)
            scanf("%d",arr+i);
    }
    void inputSize(int *n){
        printf("\nArray Size : ");
        scanf("%d",n);
    }
    void outputSortedArray(int* arr,int n){
        printf("\n");
        for(int i = 0; i < n; i++)
            printf("%d ",arr[i]);
    }
    void outputTimeTaken(clock_t start,clock_t end){
        float cpu_time;
        cpu_time = ((float)(end-start))/CLOCKS_PER_SEC;
        printf("\nTime taken in ms is %f \n",cpu_time*1000);
    }

