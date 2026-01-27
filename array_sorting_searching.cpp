1. Find duplicate element in an element.

Given an array of n elements that contains elements from 0 to n-1, with any 
of these numbers appearing any number of times. Find these repeating numbers 
in O(n) and using only constant memory space

a. for (i = 0; i < size; i++) {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }

b. We can use input array as hash array

for (int i = 0; i < arr_size; i++) {
        numRay[numRay[i] % arr_size]
            = numRay[numRay[i] % arr_size] + arr_size;
    }
    cout << "The repeating elements are : " << endl;
    for (int i = 0; i < arr_size; i++) {
        if (numRay[i] >= arr_size * 2) {
            cout << i << " " << endl;
        }
    }


2. Missing number:

Find missing number in an array(unsorted and sorted)

For sorted array apply binary search and find it.

For unsorted array

a. missing no = n* (n+1) /2 - sum

b. Using xor (xor of all array elemtn) xor (xor of N natural no) 
    is equal to missing number. Because repeative element will
    get removed.s



3. Missing and Reapting number:

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice

Method 2 (Use count array)
Approach: 

Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)

Time Complexity: O(n)

Auxiliary Space: O(n)


Method 7 (Make two equations using sum and sum of squares)
Approach:

Let x be the missing and y be the repeating element.
Let N is the size of array.
Get the sum of all numbers using formula S = N(N+1)/2
Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
Iterate through a loop from i=1….N
S -= A[i]
Sum_Sq -= (A[i]*A[i])
It will give two equations 
x-y = S – (1) 
x^2 – y^2 = Sum_sq 
x+ y = (Sum_sq/S) – (2) 

vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
     
}


Method: 3 Using xor 

In the result xor1, all elements would nullify each other except x and y. 
All the bits that are set in xor1 will be set in either x or y. So if we take 
any set bit (We have chosen the rightmost set bit in code) of xor1 and divide 
the elements of the array in two sets – one set of elements with same bit set
and other set with same bit not set. By doing so, we will get x in one set and 
y in another set. Now if we do XOR of all the elements in first set, we will 
get x, and by doing same in other set we will get y. 
 

void getTwoElements(int arr[], int n,
                    int* x, int* y)
{

    int xor1;
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 

    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
}
 
/* Driver code */
int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);
 
    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}



4. XOR of 2 numbers without using XOR operator

a. simple bit manipulation

result = 0
for(int i = 31; i>= 0; i--)
{
	bool b1 = x & (1<<i);
	bool b2 = y & (1 <<i);

	bool xorbit = (b1& b2) ? 0: (b1|b2);
	resutl <<= i;
	result |= xorbit;
}


efficient approach:

b. (~x | ~y ) & (x | y)



5. Find leaders in an array

Elements which are greater than its right elements

ar[] = {15, 18, 5, 3, 6, 2}

Traverse from right to left;
keep max_element form right

max_element = 2, 6, 18
output = 2, 6, 18

O(n) solution


7. Merge two sorted array:

(O(n1 + n2) Time and O(n1 + n2) Extra Space)

1. Create an array arr3[] of size n1 + n2.
2. Simultaneously traverse arr1[] and arr2[]. 
Pick smaller of current elements in arr1[] and arr2[],
 copy this smaller element to next position in arr3[] and 
 move ahead in arr3[] and the array whose element is picked.
3. If there are remaining elements in arr1[] or arr2[], copy them also in arr3[].


void mergeArrays(int arr1[], int arr2[], int n1,
                             int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}


8. Count inversions in array  

//brute force

Approach: Traverse through the array, and for every index, find the number of smaller elements on 
its right side of the array. This can be done using a nested loop. Sum up the counts for all index 
in the array and print the sum.
Inversion Count for an array indicates – how far (or close) the array is 
from being sorted. If the array is already sorted, then the inversion count is 0, 
but if the array is sorted in the reverse order, the inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 

Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end, so the Time complexity is O(n^2)


//best solution
Use merge sort O(nlon(n)) 

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        }
    }
 
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}


9. kadanes algorithm, Largest Sum Contiguous Subarray

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}



10. Sort an array of 0's 1's & 2's 

//we can count o, 1, and 2 and then substitute but it requires 2 passess

Three pointer appoach(for one pass)

void sortColors(vector<int>& nums) {
       int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo], nums[mid]); 
                lo++;
                mid++;
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi]);
                hi--;
                break; 
            }
        }
    }

11. Best time to buy and sell stock(ease version) others require dp  

say you have an array for which the ith element is the price of a given stock on day i. 
if you were only permitted to complete at most one transaction(buy one stock and sell one stock)
	design an algorithm to find the maximum profit. 

Input: [7, 1, 5, 3, 6, 4]
output: 5( buy on day 2 and sell on day 5)


int maxProfit(vector<int>& prices) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	for(int i = 0; i< prices.size(); i++){
		minPrice = min(minPrice, prices[i]);
		maxPro = max(maxPro, prices[i] - minPrice);
	}
	return maxPro;
}


12. Grid Unique Paths:

Find number of unique paths from (0,0) to (n-1, m-1)


i. brute force using recursion:

int countPaths(int i, int j, int n, int m)
{
	if(i == (n-1) && (j == (m-1)))
		return 1;
	if( i>= n || j >= m)
		return 0;
	else
		return countPaths(i+1, j) + countPaths(i, j+1);
}



ii. dp  


int countPaths(int i, int j, int n, int m, vector<vector<int>> & dp)
{
	if(i == (n-1) && (j == (m-1)))
		return 1;
	if( i>= n || j >= m)
		return 0;
	if(dp[i][j] == 1)
		return dp[i][j];
	else
		return dp[i][j] = countPaths(i+1, j, dp) + countPaths(i, j+1, dp);
}

iii.  for going down m-1 , right n-1

m+n-1 C m-1 // place down ones or
m+n-1 C n-1 //plae right 
//both are equal and ans.


13.  Pascal triangle:

//for Rth and cth column value is
r-1 C c-1

//pascal triangle printing

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> r(numsRows);

	for(int i =0; i< numRows; i++)
	{
		r[i].resize(i+1);
		r[i][0] = r[i][i] = 1;

		for(int j = 1; j < i ; j++)
		{
			r[i][j] = r[i-1][j-1] + r[i-1][j];
		}
	}
	return r;
}


14. Majority element is an array

a. Hashing O(n) time O(n) Space
b. sorting O(nlogn) time O(1) Space
c. Binary search tree with node count. O(nlogn), O(n)

d. Best solution: moore voting algo O(n)

int count =0, element = -1;
for(int i = 0; i< n ; i++)
{
	if(count == 0)
		element = a[i];
	if(element == a[i])
		count += 1;
	else
		count -= 1;
}

return element;

#majority elements n/3

//at max two majority element will be present
for(int ele: nums){
	if(ele == num1) {
		c1++;
	}
	else if(ele == num2)
		c2++;
	else if(c1 == 0)
	{
		num1 = ele;
		c1 = 1;
	}
	else if(c2 == 0)
	{
		num2 = ele;
		c2 = 1;
	}
	else{
		c1--;
		c2--;
	}

}

15. Minimize the maximum differene between the heights:

   // function to find the minimum possible difference
    // between maximum and minimum elements when we have to
    // add/subtract every number by k
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n); // sort the array to get the
                            // corner cases ans.
        int minEle,
            maxEle; // these 2 variables will hold the
                    // between elements max and min value
        int result = arr[n - 1]
                     - arr[0]; // current result when arr[0]
                               // iss min and arr[n-1] is max
 
        for (int i = 1; i <= n - 1; i++) {
            if (arr[i] >= k && arr[n - 1] >= k) {
                maxEle = max(arr[i - 1] + k,
                             arr[n - 1] - k); //
               
                minEle = min(arr[0] + k, arr[i] - k);
 
                result = min(result, maxEle - minEle);
                // if the middle elements max and min
                // difference if less than result then update
                // result.
            }
        }
        return result; // return result.
    }


16. Minimum Swaps to Sort array of n distint elements  

So at each i starting from 0 to N in the given array, where N is the size of the array:

1. If i is not in its correct position according to the sorted array, then

2. We will fill this position with the correct element from the hashmap we built earlier.
We know the correct element which should come here is temp[i], so we look up the index of 
this element from the hashmap. 

3. After swapping the required elements, we update the content of the hashmap accordingly, a
s temp[i] to the ith position, and arr[i] to where temp[i] was earlier.


O(nlogn)

int minSwaps(vector<int>arr,
             int N)
{
  int ans = 0;
  vector<int>temp = arr;
 
  // Hashmap which stores the
  // indexes of the input array
  map <int, int> h;
 
  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++)
  {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++)
  {
    // This is checking whether
    // the current element is
    // at the right place or not
    if (arr[i] != temp[i])
    {
      ans++;
      int init = arr[i];
 
      // If not, swap this element
      // with the index of the
      // element which should come here
      swap(arr, i, h[temp[i]]);
 
      // Update the indexes in
      // the hashmap accordingly
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return ans;
}


17. Factorial of a large number. 
class Node {
public:
    int data;
    Node* prev;
    Node(int n)
    {
        data = n;
        prev = NULL;
    }
};

void Multiply(Node* tail, int n)
{
    Node *temp = tail,
        *prevNode = tail; // Temp variable for keeping tail
    int carry = 0;
    while (temp != NULL) {
        int data = temp->data * n + carry;
        temp->data = data % 10; // stores the last digit
        carry = data / 10;
        prevNode = temp;
        temp = temp->prev; // Moving temp by 1 prevNode will
                        // now denote temp
    }
    // If carry is greater than 0 then we create another
    // node for it.
    while (carry != 0) {
        prevNode->prev = new Node((int)(carry % 10));
        carry /= 10;
        prevNode = prevNode->prev;
    }
}

void print(Node* tail)
{
    if (tail == NULL) // Using tail recursion
        return;
    print(tail->prev);
    cout
        << tail->data; // Print linked list in reverse order
}

// Driver code
int main()
{
    int n = 20;
    Node tail(1); // Create a node and initialise it by 1
    rep(i, 2, n)
        Multiply(&tail, i); // Run a loop from 2 to n and
                            // multiply with tail's i
    print(&tail); // Print the linked list
    cout << endl;
    return 0;
}



18.1 Merging intervals:

Given an array of intervals where intervals[i] = [starti, endi], merge 
all overlapping intervals, and return an array of the non-overlapping intervals 
hat cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) {
            return mergedIntervals; 
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; 
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]); 
            } else {
                mergedIntervals.push_back(tempInterval); 
                tempInterval = it; 
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals; 
    }
};


18.2 Non overlapping intervals: (https://www.youtube.com/watch?v=evA9Z5p16bI)

Given an array of intervals where intervals[i] = [starti, endi], return the minimum number 
of intervals you need to remove to make the rest of the intervals non-overlapping

Two cases:

------
   -------

and 

---------
   ----

class Solution{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){

        sort(intervals.begin(), intervals.end());
        int previous = 0;

        int n = intervals.size();
        int ans = 0;
        int index = 0;

        for(int current = 1; current<n; current++)
        {
            if(intervals[current][0] < intervals[index][1] && intervals[current][1] <= intervals[index][1])
            {
                ans++;
                index = current;
                continue;
            }
             if(intervals[current][0] < intervals[index][1] && intervals[current][1] > intervals[index][1])
            {
                ans++;
            }
            else
            {
                index = current;
            }
        }
        return ans;

    }
}

18.3 Find intersection of intervals given by two lists

https://www.geeksforgeeks.org/find-intersection-of-intervals-given-by-two-lists/
//two- pointers

Maintain two pointers i and j to traverse the two interval lists, arr1 and arr2 respectively.
Now, if arr1[i] has smallest endpoint, it can only intersect with arr2[j]. Similarly, if arr2[j] 
has smallest endpoint, it can only intersect with arr1[i]. If intersection occurs, find the intersecting segment.
[l, r] will be the intersecting segment iff l <= r, where l = max(arr1[i][0], arr2[j][0]) 
and r = min(arr1[i][1], arr2[j][1]).
Increment the i and j pointers accordingly to move ahead.


void printIntervals(vector<vector<int> > arr1,
                    vector<vector<int> > arr2)
{
 
    // i and j pointers for
    // arr1 and arr2 respectively
    int i = 0, j = 0;
 
    // Size of the two lists
    int n = arr1.size(), m = arr2.size();
 
    // Loop through all intervals unless
    // one of the interval gets exhausted
    while (i < n && j < m) {
        // Left bound for intersecting segment
        int l = max(arr1[i][0], arr2[j][0]);
 
        // Right bound for intersecting segment
        int r = min(arr1[i][1], arr2[j][1]);
 
        // If segment is valid print it
        if (l <= r)
            cout << "{" << l << ", "
                 << r << "}\n";
 
        // If i-th interval's right
        // bound is smaller
        // increment i else
        // increment j
        if (arr1[i][1] < arr2[j][1])
            i++;
        else
            j++;
    }
}

19.  Median of running stream:

//brute force:
After every input, sort the array {nlog(n) time }
and then quote the median. 
total: n2log(n) time. 


//optimal solution
we can use a max heap on left side to represent elements that are less than effective median, 
and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 
element. When both heaps contain same number of elements, we pick average of heaps root data 
as effective median. When the heaps are not balanced, we select effective median from the root 
of heap containing more elements.

//code
priority_queue<int , vector<int> greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;


void insert(int x)
{
    if(pqmin.size() == pqmax.size())
    {
        if(pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }

        if(x < pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }
    else
    {
        //case1: size of maxheap > size of minheap
        //case2: size of minheap > size of maxheap

        if(pqmax.size() > pqmin.size())
        {
            if(x >= pqmax.top())
                pqmin.push(x);
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if(x <= pqmin.top())
                pqmax.push(x);
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian()
{
    if(pqmin.size() == pqmax.size())
        return (pqmin.top() + pqmax.top())/ 2.0;
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top();
}
int main()
{
    insert(10);
    cout<<findMedian()<<endl;
    return 0;
}


20. Queue based approach for first non repeating character in a stream

Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
Create a queue of char datatype.
Store each character in queue and increase its frequency in the hash array.
For every character of stream, we check front of the queue.
If the frequency of character at the front of queue is one, then that will be the first non-repeating character.
Else if frequency is more than 1, then we pop that element.
If queue became empty that means there are no non-repeating characters so we will print -1.

void firstnonrepeating(char str[])
{
    queue<char> q;
    int charCount[MAX_CHAR] = { 0 };
 
    // traverse whole stream
    for (int i = 0; str[i]; i++) {
 
        // push each character in queue
        q.push(str[i]);
 
        // increment the frequency count
        charCount[str[i] - 'a']++;
 
        // check for the non pepeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }
 
        if (q.empty())
            cout << -1 << " ";
    }
    cout << endl;
}



21. Merge K sorted arrays:

i. Create a min heap of pairs 
    pair-> {value, array number};
ii. Insert{first element, array number} of all the sorted  
    array into minheap
iii. Main idea: we will pop element from the minheap and store
     into the answer array. Insert the next element of the sorted array
     into the minheap;
iv. We also need to keep track of the indices of the elements: 



//code 

int main()
{
    int k;
    cin>>k;

    vector<vector<itn>> a(k);

    for(int i = 0; i< k; i++)
    {
        int size;
        cin>>size;

        a[i] = vector<int>(size);
        for(int j = 0; j< size; j++)
        {
            cin>>a[i][j];
        }

    }

    vector<int> idx(k, 0);
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> pq;

    for(int i = 0; i< k; i++)
    {
        pq.push({a[i][0], i});
    }

    vector<int> ans;

    while(!pq.empty())
    {
        pair<int, int> x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        //x.second = array number
        if(idx[x.second]+1 < a[x.second].size())
            pq.push({a[x.second][idx[x.second]+1], x.second});

        idx[x.ss] +=1 ;
    }

    for(int i = 0; i< ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}


22. Merge two sorted array in O(1) extra space:


1.Iterate through every element of ar2[] starting from last 
   element. Do following for every element ar2[i]
    a.Store last element of ar1[i]: last = ar1[i]
    b.Loop from last element of ar1[] while element ar1[j] is 
       greater than ar2[i].
          ar1[j+1] = ar1[j] // Move element one position ahead
          j--
    c.If any element of ar1[] was moved or (j != m-1)
          ar1[j+1] = ar2[i] 
          ar2[i] = last

void merge(int ar1[], int ar2[], int m, int n)
{
    // Iterate through all elements
    // of ar2[] starting from the last element
    for (int i = n - 1; i >= 0; i--)
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0
             && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];
 
        // If there was a greater element
        if (j != m - 2 || last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }

}


2nd method  


void merge(int arr1[], int arr2[], int n, int m) {
        int i=0;
        // while loop till last element of array 1(sorted) is greater than
          // first element of array 2(sorted)
        while(arr1[n-1]>arr2[0])
        {
            if(arr1[i]>arr2[0])
            {
                // swap arr1[i] with first element
                  // of arr2 and sorting the updated
                // arr2(arr1 is already sorted)
                swap(arr1[i],arr2[0]);
                sort(arr2,arr2+m);
            }
            i++;
        }
    }
23. Median of two sorted arrays of different sizes:(expert level)

//brute force merge both arrays and find median
//time complexity: O(N1+ N2)
//space complexity: O(N1 + N2)

 Binary Search

Approach: The given two arrays are sorted, so we can utilize the ability of Binary Search to divide the array and find the median.


1. Lets assume that there are two arrays A and B with array A having the minimum number of elements.
   If this is not the case than swap A and B to make A having small size.
2. The edge cases like one array is empty or both are empty will be handled.
3. let n be the size of A and m be the size of B.
   Now think of an idea that if we have to find the median than we have to divide the whole merged array into two parts
   namely left and right parts.
   Now since we are given the size of left part (i.e (n+m+1)/2), Now look at below given example.
   
       A-> 1,2,3,4,5     n = 5
       B-> 1,2,3,4,5,6   m = 6
   
    Here merged array will look like :- 1,1,2,2,3,3,4,4,5,5,6 and median then is 3
    
    Now we can see our left part which is underlined. We divide A and B into two parts such that the 
    sum of left part of both A and B will result in left part of merged array.
    
    A-> 1,2,3,4,5     // pointers l =0 and r = n-1 hence mid = (l+r)/2;
       B -> 1,2,3,4,5,6

    we can see that left part of A is given as n/2 and since total length of left part in merged array
    is (m+n+1)/2, so left part of B = (m+n+1)/2-n/2;
    
    Now we just have to confirm if our left and right partitions in A and B are correct or not.
    
4. Now we have 4 variables indicating four values two from array A and two from array B.
    leftA -> Rightmost element in left part of A = 2
    leftb -> Rightmost element in left part of B = 4
    rightA -> Leftmost element in right part of A = 3
    rightB -> Leftmost element in right part of B = 5
    
    Hence to confirm that partition is correct we have to check the following conditions.
    leftA<=rightB and leftB<=rightA  // This is the case when the sum of two parts of A and B results in left part of merged array
    
    if our partition not works that means we have to  find other mid point in A and then left part in B
    This is seen when
     
    leftA > rightB    //means we have to dec size of A's partition
    so do r = mid-1;
    else
        do l =mid+1;
    
    Hence repeat the above steps with new partitions till we get the answers.
5. If leftA<=rightB and leftB<=rightA
    then we get correct partition and our answer depends on the total size of merged array (i.e. m+n)
    
    If (m+n)%2==0
     ans is max(leftA,leftB)+min(rightA,rightB)/2; // max of left part is nearest to median and min of right part is nearest to medain
    else
     ans is max(leftA,leftB);

double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}
 
24. Intersection of two arrays:

vector<int> intersect(vector<int>& num1, vector<int>& num2)
{
    map<int, int> m;
    vector<int> ans;

    for(int i = 0; i< nums1.size(); i++)
    {
        m[nums1[i]]++;
    }

    for(int i = 0; i< nums2.size(); i++)
    {
        auto i = m.find(nums2[i]);
        if(it ! = m.end() && it->second > 0)
          {
            ans.push_back(nums2[i]);
            it->second--;
          }
    }
    return ans;
}

"2D Matrix questions"

1. Matrix in spiral form:

Approach: The problem can be solved by dividing the matrix into loops or squares or boundaries. 
It can be seen that the elements of the outer loop are printed first in a clockwise manner then 
the elements of the inner loop is printed. So printing the elements of a loop can be solved using 
four loops which prints all the elements. Every ‘for’ loop defines a single direction movement along 
with the matrix. The first for loop represents the movement from left to right, whereas the second 
crawl represents the movement from top to bottom, the third represents the movement from the right 
to left, and the fourth represents the movement from bottom to up.


void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }


2.  Search in a row wise and column wise sorted matrix

int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
   
    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return -1;
   
    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            cout << "n Found at "
                 << i << ", " << j;
            return 1;
        }
        if (mat[i][j] > x)
            j--;
       
        // Check if mat[i][j] < x
        else
            i++;
    }
 
    cout << "n Element not found";
    return 0;
}


3.  Matrix multiplication:

for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {    
        mul[i][j]=0;    
        for(k=0;k<c;k++)    
        {    
            mul[i][j]+=a[i][k]*b[k][j];    
        }    
    }    
}  


4.  Find the row with maximum number of 1s



int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = C - 1;
 
    for (int i = 0; i < R; i++) {
        // Move left until a 0 is found
      bool flag=false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          flag=true ;//present row has more 1's than previous
          }
      // if the present row has more 1's than previous
      if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}




5. Matrix rotion by 90 degree:

After rotating the matrix by 90 degrees in clockwise direction, indices transform into
20 10 00  current_row_index = 0, i = 2, 1, 0 
21 11 01 current_row_index = 1, i = 2, 1, 0 
22 12 02  current_row_index = 2, i = 2, 1, 0


void rotate90Clockwise(int arr[N][N])
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}



//second methond:

 Approach: The Approach is to rotate the given matrix two times, first time with 
 respect to the Main diagonal, next time rotate the resultant matrix with respect to 
 the middle column, Consider the following illustration to have a clear insight into it.


//basically transpose + reverse column:

 void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
             
        cout << '\n';
    }
}
 
void rotate(int arr[N][N])
{
     
    // First rotation
    // with respect to main diagonal
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
     
    // Second rotation
    // with respect to middle column
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N / 2; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = temp;
        }
    }
}


5. Median of row wise sorted matrix:(take u forward)

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

time: log(2^32) * n * log(m)

=> O(32 * N * log(M)) 


6. Kth smallest element in a sorted matrix:

//using binary search:
//based on above approch


This approach uses binary search to iterate over possible solutions. We know that 

answer >= mat[0][0]
answer <= mat[N-1][N-1]


So we do a binary search on this range and in each  iteration determine the no of elements 
greater than or equal to our current middle element. The elements greater than or equal to 
current element can be found in O( n logn ) time using binary search.

int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix
        // further are less than or equal to num
        if (mat[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements
        // in that row
        if (mat[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal
        // to num
        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                   mat[i][greaterThan + jump] <= num) {
                greaterThan += jump;
            }
        }
 
        ans += greaterThan + 1;
    }
    return ans;
}
 
// reuturs kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
    //  We know the answer lies between the first and the last element
    // So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);
 
        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}