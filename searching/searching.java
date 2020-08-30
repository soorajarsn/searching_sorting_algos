import java.util.*;

class Searching{
    public static int linearSearch(int[] arr, int key){
        int comparisons = 0;
        for(int i = 0; i < arr.length; i++){
            comparisons++;
            if(arr[i] == key)
                return comparisons;
        }
        return comparisons;
    }
    public static int binarySearch(int [] arr,int key){
        int left = 0, right = arr.length-1;
        int comparisons = 0;
        while(left <= right){
            int mid = (left+right)/2;
            if(arr[mid] == key){
                comparisons++;
                return comparisons;
            }
            else if(arr[mid] < key){
                comparisons += 2;
                left = mid+1;
            }
            else{
                comparisons += 2;
                right = mid - 1;
            }
        }
        return comparisons;
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements ");
        int n = in.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter "+n+" elments");
        for(int i = 0; i < n; i++)  
            arr[i] = in.nextInt();
        System.out.println("Enter the element to be searched");
        int key = in.nextInt();
        int cmp1 = linearSearch(arr, key);
        int cmp2 = binarySearch(arr, key);
        System.out.println("Linear Search took "+cmp1+" comparisons and cmp2 took "+ cmp2 +" comparisons");
        in.close();
    }
}