
    #include<stdio.h>
    #include<time.h>
    #include<stdlib.h>
    void inputArray(int*,int);
    void inputSize(int*);
    void outputTimeTaken(clock_t,clock_t);
    void inputArray(int* arr,int n){
        FILE* file = fopen("input.txt","r");
        if(!file){
            printf("can't read file");
            exit(-1);
        }
        for(int i = 0; i < n && !feof(file); i++)
            fscanf(file,"%d",arr+i);
        fclose(file);
    }
    void inputSize(int *n){
        printf("\nArray Size : ");
        scanf("%d",n);
    }
    void outputTimeTaken(clock_t start,clock_t end){
        float cpu_time;
        cpu_time = ((float)(end-start))/CLOCKS_PER_SEC;
        printf("\nTime taken in ms is %f \n",cpu_time*1000);
    }

