Identification

1. K
2. Smallest and largest

K + smallest = maxheap
K + largest = minheap


Sorting is a simple solution for heap questions

Complexity changes from nlog(n) to nlog(k) , kth samllest 

Representation:

maxheap: priority_queue<int> maxheap;

minheap: priority_queue<int, vector<int> , greater<int> minheap;



1. Kth smallest element in an unsorted array

void kthSmallest(vector<int>& v, int N, int K)
{
    priority_queue<int> heap1;
 
    for (int i = 0; i < N; ++i) {
 
        heap1.push(v[i]);
 

        if (heap1.size() > K) {
            heap1.pop();
        }
    }

    cout << heap1.top() << endl;
}


2. Return k largest elements in unsorted array 


private static void printKLargestElements(int[] arr, int k, int size) {
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    for (int i = 0; i < size; i++) {
      minHeap.add(arr[i]);
      if (minHeap.size() > k) {
        minHeap.poll();
      }
    }

    while (minHeap.size() > 0) {
      System.out.println(minHeap.peek());
      minHeap.poll();
    }
}


3. Sort a K Sorted Array | Sort Nearly Sorted Array

int sortK(int arr[], int n, int k)
{
 
    int size;
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
}
 


4. Find k closest numbers in an unsorted array

void printKclosest(int arr[], int n, int x,
                   int k)
{
    // Make a max heap of difference with
    // first k elements.
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < k; i++)
        pq.push({ abs(arr[i] - x), i });
 
    // Now process remaining elements.
    for (int i = k; i < n; i++) {
 
        int diff = abs(arr[i] - x);
 
        // If difference with current
        // element is more than root,
        // then ignore it.
        if (diff > pq.top().first)
            continue;
 
        // Else remove root and insert
        pq.pop();
        pq.push({ diff, i });
    }
 
    // Print contents of heap.
    while (pq.empty() == false) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}


5. Find k closest elements to a given value in a sorted array

Input:  [10, 12, 15, 17, 18, 20, 25], k = 4, x = 16
 
Output: [12, 15, 17, 18]

int binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
 
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] < x) {
            low = mid + 1;
        }
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        else {
            return mid;     // key found
        }
    }
 
    return low;             // key not found
}
 
// Function to find the `k` closest elements to `x` in a sorted integer array `arr`
void findKClosestElements(int arr[], int x, int k, int n)
{
    // find the insertion point using the binary search algorithm
    int i = binarySearch(arr, n, x);
 
    int left = i - 1;
    int right = i;
 
    // run `k` times
    while (k-- > 0)
    {
        // compare the elements on both sides of the insertion point `i`
        // to get the first `k` closest elements
        if (left < 0 || (right < n &&
                abs(arr[left] - x) > abs(arr[right] - x))) {
            right++;
        }
        else {
            left--;
        }
    }
 
    // print the `k` closest elements
    left++;
    while (left < right)
    {
        printf("%d ", arr[left]);
        left++;
    }
}



6. Top K Frequent Numbers

unordered_map<int,int>mp;
 priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>MIN;
   vector<int>v={1,1,1,3,2,2,4,4,4};
   int i,n=v.size();
for(i=0;i<n;i++)
{
    mp[v[i]]++;
}
for(auto i=mp.begin();i!=mp.end();i++)
{
   MIN.push({i->second,i->first});
   if(MIN.size()>2)
        MIN.pop();
}
while(MIN.size()>0)
{
    cout<<MIN.top().second;
 MIN.pop();
}



7. K points closest to origin

class comp {
  
public:
    bool operator()(pair<int, int> a,
                    pair<int, int> b)
    {
        int x1 = a.first * a.first;
        int y1 = a.second * a.second;
        int x2 = b.first * b.first;
        int y2 = b.second * b.second;
  
        // return true if distance
        // of point 1 from origin
        // is greater than distance of
        // point 2 from origin
        return (x1 + y1) > (x2 + y2);
    }
};
  
// Function to find the K closest points
void kClosestPoints(int x[], int y[],
                    int n, int k)
{
    // Create a priority queue
    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   comp>
        pq;
  
    // Pushing all the points
    // in the queue
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(x[i], y[i]));
    }
  
    // Print the first K elements
    // of the queue
    for (int i = 0; i < k; i++) {
  
        // Store the top of the queue
        // in a temporary pair
        pair<int, int> p = pq.top();
  
        // Print the first (x)
        // and second (y) of pair
        cout << p.first << " "
             << p.second << endl;
  
        // Remove top element
        // of priority queue
        pq.pop();
    }
}

8. connect-n-ropes-minimum-cost

There are given n ropes of different lengths, we need to connect 
these ropes into one rope. The cost to connect two ropes is equal 
o the sum of their lengths. We need to connect the ropes with minimum cost.

int minCost(int arr[], int n)
{
    // https:// www.geeksforgeeks.org/priority-queue-in-cpp-stl/

    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);
 
    // Initialize result
    int res = 0;
 
    // While size of priority queue is more than 1
    while (pq.size() > 1) {
        // Extract shortest two ropes from pq
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        res += first + second;
        pq.push(first + second);
    }
 
    return res;
}