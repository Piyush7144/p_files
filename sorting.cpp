sorting

1. Bubble sort

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
} 

Worst and Average Case Time Complexity: O(n*n). 
Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n).
 Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes

2. Selection sort:

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

3. Insersion sort

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

Time Complexity: O(n^2) 
Auxiliary Space: O(1)
Boundary Cases: Insertion sort takes maximum time to sort if elements
are sorted in reverse order. And it takes minimum time (Order of n) 
when elements are already sorted.
Algorithmic Paradigm: Incremental Approach
Sorting In Place: Yes
Stable: Yes
Online: Yes
Uses: Insertion sort is used when number of elements is small. It can 
also be useful when input array is almost sorted, only few elements are 
misplaced in complete big array.


4. mergesort


void merge(int arr[], int l , int mid , int r) {

	int n1 = mid -l +1;
	int n2 = r-mid;

	int a[n1];
	int b[n2];

	for(int i = 0; i< n1; i++)
	{
		a[i] = arr[l+i];
	}
	for(int i = 0; i< n2; i++)
	{
		b[i] = arr[mid + l +i];
	}

	int i = 0, j = 0, k = l;

	while( i< n1 && j < n2)
	{
		if(a[i] < b[j] )
		{
			arr[k] = a[i];
			k++;
			i++;
		}

		else
		{
			arr[k] = b[j];
			k++;
			j++;
		}
	}

	while( i< n1) {
		arr[k] = a[i];
		k++; i++;
	}
	while( j< n2) {
		arr[k] = b[j];
		k++; j++;
	}
}
void mergeSort(int arr[] , int l, int r) {

	if(l < r) {

		int mid = (l +r) /2;
		megeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, mid , r);
	}
}

Auxiliary Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes


4.2 Iterative mergesort 

void mergeSort(int arr[], int n)
{
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray
                   // to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = min(left_start + curr_size - 1, n-1);
 
           int right_end = min(left_start + 2*curr_size - 1, n-1);
 
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}


5. quickSort

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

Time complexity:

Worst case: O(n2)
Average case: O(nlogn)
best case: O(nlogn)


6. Quicksort iterative

void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
 
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

