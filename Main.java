import java.util.Arrays;
import java.util.Scanner;

class Main {
    // Merge sort method
    void mergeSort(int[] a, int n) {
        if (n < 2) {
            return; // Base case: if array has 0 or 1 element, it's already sorted
        }
        int mid = n / 2; // Calculate the middle index
        int[] l = new int[mid]; // Left sub-array
        int[] r = new int[n - mid]; // Right sub-array
        // Copy elements to left sub-array
        for (int i = 0; i < mid; i++) {
            l[i] = a[i];
        }
        // Copy elements to right sub-array
        for (int i = mid; i < n; i++) {
            r[i - mid] = a[i];
        }
        // Recursively sort left and right sub-arrays
        mergeSort(l, mid);
        mergeSort(r, n - mid);
        // Merge the sorted sub-arrays
        merge(a, l, r, mid, n - mid);
    }

    // Merge method to merge two sorted arrays
    void merge(int[] a, int[] l, int[] r, int left, int right) {
        int i = 0, j = 0, k = 0;
        // Compare elements of left and right sub-arrays and merge them into the original array
        while (i < left && j < right) {
            if (l[i] <= r[j]) {
                a[k++] = l[i++];
            } else {
                a[k++] = r[j++];
            }
        }
        // Copy remaining elements from left sub-array
        while (i < left) {
            a[k++] = l[i++];
        }
        // Copy remaining elements from right sub-array
        while (j < right) {
            a[k++] = r[j++];
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        
        int[] array = new int[n];
        System.out.println("Enter the elements:");
        // Input the elements of the array
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }
        
        Main ob = new Main();
        // Call the mergeSort method to sort the array
        ob.mergeSort(array, array.length);
        
        // Print the sorted array
        System.out.println("Sorted Array:");
        System.out.println(Arrays.toString(array));
        
        scanner.close();
    }
}
