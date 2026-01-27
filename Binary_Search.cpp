Binary Search Questions



1. Binary Search in increasing sorted array

sorted array 

ar[] =  {1,2,3,4,5,6,7,8};

element = 2;
return index of 2 i.e 1

//code
int binarySearch(int ar[], int element)
{
	int lo = 0, up = n-1, mid;

	while(lo <= up)
	{
		//int mid = (lo + up)/2;
		mid = lo + (up - lo)/2; // To prevent overflow
		if(ar[mid] == elemnt)
			{
				return mid;
			}
		if(ar[mid] < element)
			lo = mid +1;
		else
			up = mid -1;
	}
	return -1;
}


2. Decreasing Soreted array

ar[] = { 8,7,6,5,4,3,2,1};


		if(ar[mid] < element)
			up = mid -1;
		else
			lo = mid +1;




3. First and Last accurence of an element in sorted array

int binarySearch(int ar[], int element)
{
	int lo = 0, up = n-1, mid;
	int result = -1;

	while(lo <= up)
	{
		
		mid = lo + (up - lo)/2; 
		if(ar[mid] == elemnt)
			{
				//For First accurence
				result = mid;
				up = mid -1;

				//For last accurence
				// result = mid;
				// lo = mid +1;
			}
		if(ar[mid] < element)
			lo = mid +1;
		else
			up = mid -1;
	}
	return result;
}


4. Count of an element in a sorted array

    if(firstIndex = -1)
    	return -1;
    else
        return lastIndex - firstIndex + 1;


5. Number of times a sorted array is rotated

// Lets take left rotated array

Number of rotated depend on index of minimum element;

No of rotation = index of minimum element;

a[] = -2,5, 6, 8, 11, 12, 15, 18
b[] = 11,12,15, 18, -2, 5, 6, 8

Searching in rotated sorted array

Condition

1. Find min element(mid)
2. Find factor to move

if  ar[mid-1] > ar[mid] < ar[mid+1] 
	then it is the minimum element

Sorted element will be there in unsorted direction

//complete code to find idx_of_min_element

int pivotIdx(vector<int> arr, int n){
	if(arr[0] < arr[n-1]){
		return 0;
	}

	int pivot = -1;
	int lo = 0, up = n-1;
	while(lo <= up){
        if(arr[lo] <= arr[up]){
             return lo;
         }
		int mid = lo + (up-lo)/2;
		int next = (mid+1)%n;
		int prev = (mid-1+n)%n;
		if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
          
              pivot = mid;
		      break;
            
		}
		if(arr[lo] <= arr[mid]){

            lo = mid + 1;
		}
		else if(arr[mid] <= arr[up]){
			up = mid - 1;
		}

	}
   
	return pivot;
}






6. Find an element in a rotated sorted array

ar[] = 11, 12, 15, 18, 2, 5, 6

First find index of min element(previous method)
BS(ar, lo, up)

we will get index of min element

int index = minElementIndexInSortedArray(arr);

		int element = 15;

		int pos1 = binarySearch(arr, 0, index - 1, element);
		int pos2 = binarySearch(arr, index, arr.length - 1, element);



// Second method METHOD-2: Using 1 traversal

 		int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            //cout<<nums[mid]<<"\n";
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>=nums[left])//left side is sorted
            {
                if(target<=nums[mid] && target>=nums[left])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    



7. Searching in a nearly sorted array(i-1, i, i+1)


def binary_search(target):
    low=0
    high=len(arr) - 1
    n=len(arr)
    while low <= high : 

        mid = low + (high - low)//2

        if arr[mid]==target:
            return mid

        previous = (mid-1)%n
        next=(mid+1)%n

        if arr[previous]==target:
            return previous

        if arr[next]==target:
            return next

        if arr[mid] < target:
            low=mid+2
        else:
            high = mid -2
    return -1

arr=[10, 3, 40, 20, 50, 80, 70]
ans=binary_search(90)
print(ans)



8. Find floor of an element in a sorted array

Floor of 5 greatest element smaller than or equal to 5;

 while(low<=high)
    {
        int mid;
        mid= low+(high-low)/2;
        if(arr[mid]==x)
        {
            cout<<mid<<endl;
            break;
        }
        else if(arr[mid]<x)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high= mid-1;
        }
    }


9. Ceil of an element is a sorted array

  while(start<=end)
    {
        int mid=(start+end)/2;
        if(a[mid]==ele)
        {
            res=mid;break;
        }
        else if(a[mid]<ele)
        {
            start=mid+1;
        }
        else if(a[mid]>ele)
        {
            res=a[mid];
            end=mid-1;
        }
    }

10. Next Alphabetical Element// based on ceil question

ar[] = ['a', 'c', 'f', 'h'] 

int solve(vector<char>v,int lo,int up,char target)
{
    if(target=='z')return -1;
    int ans=-1;
    while(lo<=up){
        int mid = lo+(up- lo)/2;
        if(v[mid]>target){
            ans = mid ;
            up = mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans ;
}




11. search in an infinite Sorted array

int solve(int A[], int low, int high, int key)
{
    initial low =0, high =1;
	if (low <= high) {
    int mid = low + (high - low) / 2;
    if (A[mid] == key)
        return mid;
    else if (A[mid] < key)
        return solve(A, mid + 1, 2 * high, key);
    else
        return solve(A, low, mid - 1, key);
    }
    else
    return -1;
}


12. Index of First 1 in a Binary Sorted Infinite Array


int bs(int s,int end,int a[],int ele)
{
    int res;
     while(s<=end)
     {
         int mid=s+(end-s)/2;
        if(a[mid]==ele)
        {
            res=mid; //for first accurence search
            end=mid-1;
        }
        else if(a[mid]<ele)
            s=mid+1;
        else
            end=mid-1;
    }
    return res;
}
int main()
{
    int n;
    cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int start=0,end=1,ele;
    ele=1;
    while(ele>a[end])
    {
        start=end;
        end=end*2;
    }
    cout<<bs(start,end,a,1);




13. minimum difference element in a sorted array

when key is present then that is min

if not low, and high stop at nearrest left and right 

//when the binary search stops:
min(abs(ar[low] - key ) , abs(ar[high] - key));



14. Binary search on answers( bs may be applied if not sorted)

//example alloate minimum no of pages and aggresive cow


15. Peak element // return only any one peak element

ar[] = {5, 10, 20, 5}

ans = 20

ar[] = {10, 20, 15 , 23, 90, 67 }

ans 20, 90, return any 


naive, O(n) solution


low = 0
high = n-1

while( low <= high)
{
	int mid  = low + (high-low)/2;

	if( mid> 0 && mid  < n-1)
	{
		if( ar[mid] > ar[mid-1] && ar[mid] > ar[mid+1])
		{
			return mid;
		}

		else if(ar[mid-1] > ar[mid])
		{
			high = mid -1;
		}
		else
			low = mid + 1;
	}
	else if(mid == 0)//boundry conddtion
	{
		if(ar[0] > ar[1])
			return 0; //zero element is peack 0 is index
		else
			return 1;
	}
	else if(mid == n-1)
	{
		if( ar[n-1] > ar[n-2])
		{
			return n-1;
		}
		else
			return n-2;
	}
}


16. Find maximum element in bitonic arrary


First monotonically increasing then Decreasing

same as max element in bitonic array = peak element




17. Search in bitonic array

First find peack element

left is increasing sorted, right is Decreasing sorted

apply different bs on both.


/**/

18. Search in Row wise And Column wise Sorted Array


Start from top right.


int i = 0;
int j = m-1;

while( i>= 0 && < n && j>= 0 && j< m)
{
	if(ar[i][j] == key)
		return i,j

	else if(ar[i][j] >key)
		j--;
	else if( arr[i][j] < key)
		i++;
}
return -1;
}


19. Allocate minimum number of pages

//There is any array with no of no of pages in each book and some student
//Max no of pages allocated is minimum 


//Conditions
i. A Book will be allocated to one student 
ii. Each students must get a minimum element of 1 book. 
iii. Allotment should be in countigous manner 


//better solution
int isPossible(vector<int> &A, int pages, int students) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<A.size();i++) {
        if(sumAllocated + A[i] > pages) {
            cnt++; 
            sumAllocated = A[i];
            if(sumAllocated > pages) return false; 
        }
        else {
            sumAllocated += A[i];
        }
    }
    if(cnt < students) return true; 
    return false; 
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; 
    int low = A[0]; 
    int high = 0;
    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }
    int res = -1; 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        //cout << low << " " << high << " " << mid << endl; 
        if(isPossible(A, mid, B)) {
            res = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    // return res -> this is also correct
    return low; 
}


20. Nth root of a number using binary search:

//Binary search can also be applied where, there is orderd serach space

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; 
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}

21. Agressive cow(spoj)

bool isPossible(int a[], int n, int cows, int minDist) {
        int cntCows = 1; 
        int lastPlacedCow = a[0];
        for(int i = 1;i<n;i++) {
            if(a[i] - lastPlacedCow >= minDist) {
                cntCows++;
                lastPlacedCow = a[i]; 
            }
        }
        if(cntCows >= cows) return true;
        return false; 
    }
    int main() {
    	int t;
    	cin >> t;
    	while(t--) {
    	    int n, cows;
    	    cin >> n >> cows;
    	    int a[n];
    	    for(int i = 0;i<n;i++) cin >> a[i]; 
    	    sort(a,a+n); 
    	    
    	    int low = 1, high = a[n-1] - a[0]; 
    	    
    	    while(low <= high) {
    	        int mid = (low + high) >> 1; 
    	        
    	        if(isPossible(a,n,cows,mid)) {
    	            low = mid + 1;
    	        }
    	        else {
    	            high = mid - 1; 
    	        }
    	    }
    	    cout << high << endl; 
    	}
    	return 0;
    } 

22.Median of row wise sorted matrix:(take u forward)

int countSmallerThanMid(vector<int> &row, int mid) {
    int l = 0, h = row.size() - 1; 
    while(l <= h) {
        int md = (l + h) >> 1; 
        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l; 
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MIN;
    int high = INT_MAX; 
    int n = A.size();
    int m = A[0].size(); 
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            cnt += countSmallerThanMid(A[i], mid); 
        }
        
        if(cnt <= (n * m) / 2) low = mid + 1; 
        else high = mid - 1; 
    }
    return low; 
}


23. The painter’s partition problem

We have to paint n boards of length {A1, A2…An}. There are k painters available and each 
takes 1 unit time to paint 1 unit of board. The problem is to find the minimum time to get 
this job done under the constraints that any painter will only paint continuous sections of 
boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Input : k = 2, A = {10, 10, 10, 10} 
Output : 20.
Here we can divide the boards into 2
equal sized partitions, so each painter 
gets 20 units of board and the total
time taken is 20.

#include <iostream>

using namespace std;

int findFeasible(int boards[], int n, int limit)
{
    int s = 0, painters = 1;
    for(int i = 0; i< n; i++){
        sum += boards[i];

        if(sum > limit)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[], int n, int m){

    int totalLength = 0, k = 0;
    for(int i = 0; i< n; i++){
        k = max(k , boards[i]);
        totalLength += boards[i];
    }

    int low = k, high = totalLength;
    while(loc < high){

        int mid = (low + high)/2;
        int painters = findFeasible(boards,n, mid);
        if(painters <= m)
        {
            high = mid;
        }
        else{
            low = mid-1;
        }
    }

    return low;
}