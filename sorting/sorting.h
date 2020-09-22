
	#include<stdlib.h>
	#include<stdio.h>
	#define TRUE 1;
	#define FALSE 0;
	void bubbleSort(int*, int);
	void insertionSort(int*, int);
	void selectionSort(int*, int);
	void mergeSort(int*,int,int);
	void heapify(int*,int,int);
	void heapSort(int*,int);
	void swap(int*, int*);
	void merge(int*,int,int,int);
	void useMergeSort(int*,int);
	void quickSort(int*, int, int);
	void quickSort_sortedBest(int*, int, int, int);
	int partition(int*, int, int);
	int partition_sortedBest(int*, int, int);
	void useQuickSort(int*,int);
	void useQuickSort_sortedBest(int*,int);
	void countingSort(int*, int);
	void useCountingSort(int*, int, int);
	void radixSort(int*, int);
	int getMax(int*,int);
	void bubbleSort(int* arr, int n){
		for(int i = 0; i < n-1; i++){
			int swapped = FALSE;
			for(int j = 0; j < n-1-i; j++)
				if(arr[j] > arr[j+1]){
					swap(arr+j,arr+j+1);
					swapped = TRUE;
				}
			if(!swapped)
				break;
		}
	}
	void insertionSort(int* arr,int n){
		for(int i = 1; i < n; i++){
			int key = arr[i];
			int j = i - 1;
			while(j >= 0 && arr[j] > key){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = key;
		}
	}
	void selectionSort(int* arr, int n){
		int minIndex ;
		for(int i = 0; i < n-1; i++){
			minIndex = i;
			for(int j = i+1; j < n; j++)
				if(arr[j] < arr[minIndex])
					minIndex = j;
			swap(arr+minIndex,arr+i);
		}
	}
	void merge(int *arr, int p, int q, int r){
		int n1 = q - p + 1;
		int n2 = r - q;
		int *left,*right;
		left = (int*)malloc(n1*sizeof(int));
		right = (int*)malloc(n2*sizeof(int));
		for(int i = 0; i < n1; i++)
			left[i] = arr[p+i];
		for(int i = 0; i < n2; i++)
			right[i] = arr[q+i+1];
		int i = 0, j = 0, k = p;
		while(i < n1 && j < n2){
			if(left[i] <= right[j]){
				arr[k] = left[i];
				i++;
			}
			else{
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		while(i < n1){
			arr[k] = left[i];
			i++;
			k++;
		}
		while(j < n2){
			arr[k] = right[j];
			j++;
			k++;
		}
	}
	void mergeSort(int *arr,int p, int r){
		if(p < r){
			int q = p + (r-p)/2;
			mergeSort(arr,p,q);
			mergeSort(arr,q+1,r);
			merge(arr,p,q,r);
		}
	}
	void useMergeSort(int *arr,int n){
		mergeSort(arr,0,n-1);
	}
	int partition(int* arr, int low, int high){
		int x = arr[high];
		int i = low - 1;
		for(int j = low; j < high; j++){
			if(arr[j] <= x){
				i = i+1;
				swap(arr+i,arr+j);
			}
		}
		swap(arr+i+1,arr+high);
		return i+1;
	}
	void quickSort(int *arr, int low, int high){
		if(low < high){
			int q = partition(arr,low,high);
			quickSort(arr,low,q-1);
			quickSort(arr,q+1,high);
		}
	}
	void useQuickSort(int* arr, int n){
		quickSort(arr,0,n-1);	
	}
	int partition_sortedBest(int* arr, int low, int high){
		int pivot, mid;
		pivot = mid = (low+high)/2;
		int i = low - 1;
		for(int j = low; j < mid; j++)
			if(arr[j] <= arr[pivot]){
				i = i+1;
				swap(arr+i,arr+j);
			}
		for(int j = mid+1; j <= high; j++)
			if(arr[j] <= arr[pivot]){
				i = i+1;
				if(i == pivot)
					pivot = j;
				swap(arr+j, arr+i);		
			}
		swap(arr+i+1,arr+pivot);
		return i+1;
	}
	void quickSort_sortedBest(int* arr, int low, int high,int n){
		if(low < high){
			int q = partition_sortedBest(arr,low,high);
			quickSort_sortedBest(arr,low,q-1,n);
			quickSort_sortedBest(arr,q+1,high,n);
		}
	}
	void useQuickSort_sortedBest(int* arr, int n){
		quickSort_sortedBest(arr,0,n-1,n);
	}
	void heapify(int* arr,int n, int i){
		int max = i;
		int l = 2*i + 1;
		int r = 2*i + 2;

		if(l < n && arr[l] > arr[max])
			max = l;
		if(r < n && arr[r] > arr[max])
			max = r;
		if(max != i){
			swap(arr+i,arr+max);
			heapify(arr,n,max);
		}
	}
	void heapSort(int* arr, int n){
		for(int i = n/2 - 1; i >= 0; i--)
			heapify(arr,n,i);
		for(int i = n-1; i > 0; i--){
			//delete the root and append to last position
			swap(arr,arr+i);
			heapify(arr,i,0);
		}
	}
	void swap(int* a, int* b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
//soritng in linear time
int getMax(int* arr, int n){
	int max = -1;
	for(int i = 0; i < n; i++)
		if(max < arr[i])
			max = arr[i];
	return max;
}
void CountingSort(int*arr, int n){
	//finding range
	int max = getMax(arr,n);
	max++;
	int* posArr = (int*)malloc(max*sizeof(int));
	for(int i = 0; i < max; i++)
		posArr[i] = 0;
	for(int i = 0; i < n; i++)
		posArr[arr[i]]++;
	for(int i = 1; i < max; i++)
		posArr[i] += posArr[i-1];
	int* sortedArr = (int*)malloc(n*sizeof(int));
	for(int i = n-1; i >= 0; i--)
		sortedArr[--posArr[arr[i]]] = arr[i];
	for(int i = 0; i < n; i++)
		arr[i] = sortedArr[i];
}
void useCountingSort(int* arr, int n, int e){
 	int* r = (int*)malloc(n*sizeof(int));
    int i, count[10] = {0,0,0,0,0,0,0,0,0,0}; 
	
    for (i = 0; i < n; i++) 
        count[(arr[i]/e)%10]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1];
		
    for (i = n - 1; i >= 0; i--)
        r[--count[(arr[i]/e)%10]] = arr[i];
    for (i = 0; i < n; i++) 
        arr[i] = r[i];	
}
void radixSort(int* arr, int n){
	int m = getMax(arr, n);
    for (int e = 1; m/e > 0; e *= 10) 
        useCountingSort(arr, n, e); 
}