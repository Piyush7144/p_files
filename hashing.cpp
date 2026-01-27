
1. Two sum (here 2 pointers can also be applied if it is sorted)

Given an array A[] and a number x, check for pair in A[] with sum as x

void printPairs(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++)
    {
        int temp = sum - arr[i];
 
        if (s.find(temp) != s.end())
            cout << "Pair with given sum "
                 << sum << " is (" << arr[i] << ","
                    << temp << ")" << endl;
 
        s.insert(arr[i]);
    }
}

1.2 Count pairs with given sum

int getPairsCount(int arr[], int n, int k) {

    unordered_map<int, int> m;
    int ans = 0;

    for(int i = 0; i< n; i++){
        int val = k - arr[i];
        if(m[val]){
            ans += m[val];
        }
        m[arr[i]]++;
    }
    return ans;
}


2. Four sum problem:

Find unique a + b+ c+ d = target:

i. Simplest approch. O(n4)

for(int i = to n-4)
    for(int j = i+1 to n-3)
        for(int k = j+1 to n-2)
            for(l = k+1 to n-1)
                sum = num[i] + num[j] +nums[k] +nums[l];
                if(sum == target)
                    count++;

and set to store the unique values


hashing:

n = [-2, -1, 0, 0, 1, 2] 

n[i] + n[j] + n[k] + n[l] = target

n[k] + n[l] = targe - (n[i] + n[j])
 First sum              second sum


 Method 2: Hashing Based Solution[O(n2)] 

Approach: 

Store sums of all pairs in a hash table
Traverse through all pairs again and search for X – (current pair sum) in the hash table.
If a pair is found with the required sum, then make sure that all elements are distinct 
array elements and an element is not considered more than once.

void findFourElements(int arr[], int n, int X)
{
    // Store sums of all pairs
    // in a hash table
    unordered_map<int, pair<int, int> > mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = { i, j };
 
    // Traverse through all pairs and search
    // for X - (current pair sum).
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
 
            // If X - sum is present in hash table,
            if (mp.find(X - sum) != mp.end()) {
 
                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j
                    && p.second != i && p.second != j) {
                    cout << arr[i] << ", " << arr[j] << ", "
                         << arr[p.first] << ", "
                         << arr[p.second];
                    return;
                }
            }
        }
    }
}

//for no dulicates we can use another hash



3. Longest Consecutive sequence: 

ar: {100, 2, 400, 3,1,4}

ans 1,2,3,4

//Easy solution is O(nlon(n)) using sorting

Algorithm: 

Create an empty hash.
Insert all array elements to hash.
Do following for every element arr[i]
Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 
in the hash, if not found, then this is the first element a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with 
this element. Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.

int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);
 
    // check each possible sequence from
    // the start then update optimal length
    for (int i = 0; i < n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i] - 1) == S.end())
        {
            // Then check for next elements
            // in the sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if
            // this length is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}


4. Largest subarray with 0 sum, containing 0, -ve and positive nums

Naive Approach: This involves the use of brute force where two nested loops are used. 
The outer loop is used to fix the starting position of the sub-array, and the inner loop 
is used for the ending position of the sub-array and if the sum of elements is equal to zero, 
then increase the count.



Efficient approch:

Algorithm:  

Create an extra space, an array of length n (prefix), a variable (sum), length (max_len), 
and a hash map (hm) to store the sum-index pair as a key-value pair.
Move along the input array from the start to the end.
For every index, update the value of sum = sum + array[i].
Check every index, if the current sum is present in the hash map or not.
If present, update the value of max_len to a maximum difference of two indices 
(current index and index in the hash-map) and max_len.
Else, put the value (sum) in the hash map, with the index as a key-value pair.
Print the maximum length (max_len).



int maxLen(int arr[], int n)
{
    // Map to store the previous sums
    unordered_map<int, int> presum;
 
    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result
 
    // Traverse through the given array
    for (int i = 0; i < n; i++) {
        // Add current element to sum
        sum += arr[i];
 
        if (arr[i] == 0 && max_len == 0)
            max_len = 1;
        if (sum == 0)
            max_len = i + 1;
 
        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {
            // If this sum is seen before, then update max_len
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            // Else insert this sum with index in hash table
            presum[sum] = i;
        }
    }
 
    return max_len;
}


5. Count the number of subarrays having a given xor

A Simple Solution is to use two loops to go through all 
possible subarrays of arr[] and count the number of subarrays having XOR of their elements as m. 


long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0; // Initialize ans
 
    // Pick starting point i of subarrays
    for (int i = 0; i < n; i++) {
        int xorSum = 0; // Store XOR of current subarray
 
        // Pick ending point j of subarray for each i
        for (int j = i; j < n; j++) {
            // calculate xorSum
            xorSum = xorSum ^ arr[j];
 
            // If xorSum is equal to given value,
            // increase ans by 1.
            if (xorSum == m)
                ans++;
        }
    }
    return ans;
}



Efficient Approach:
An Efficient Solution solves the above problem in O(n) time. Let us call the XOR of all elements in the range [i+1, j] as A, 
in the range [0, i] as B, and in the range [0, j] as C. If we do XOR of B with C, the overlapping elements in [0, i] from B 
and C zero out, and we get XOR of all elements in the range [i+1, j], i.e. A. Since A = B XOR C, we have B = A XOR C. Now, 
if we know the value of C and we take the value of A as m, we get the count of A as the count of all B satisfying this relation. 
Essentially, we get the count of all subarrays having XOR-sum m for each C. As we take the sum of this count overall C, we get our answer.



long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0; // Initialize answer to be returned
 
    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    int* xorArr = new int[n];
 
    // Create map that stores number of prefix array
    // elements corresponding to a XOR value
    unordered_map<int, int> mp;
 
    // Initialize first element of prefix array
    xorArr[0] = arr[0];
 
    // Computing the prefix array.
    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i - 1] ^ arr[i];
 
    // Calculate the answer
    for (int i = 0; i < n; i++) {
       
        // Find XOR of current prefix with m.
        int tmp = m ^ xorArr[i];
 
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        ans = ans + ((long long)mp[tmp]);
 
        // If this subarray has XOR equal to m itself.
        if (xorArr[i] == m)
            ans++;
 
        // Add the XOR of this subarray to the map
        mp[xorArr[i]]++;
    }
 
    // Return total count of subarrays having XOR of
    // elements as given value m
    return ans;
}



6. Length of the longest substring without repeating characters

The idea is to scan the string from left to right, keep track of the maximum 
length Non-Repeating Character Substring seen so far in res. When we traverse 
the string, to know the length of current window we need two indexes. 
1) Ending index ( j ) : We consider current index as ending index. 
2) Starting index ( i ) : It is same as previous window if current character was 
not present in the previous window. To check if the current character was present 
in the previous window or not, we store last index of every character in an array 
lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated 
the start index i. Else we keep same i.  


int longestUniqueSubsttr(string str)
{
    int n = str.size();
 
    int res = 0; // result
 
    // last index of all characters is initialized
    // as -1
    vector<int> lastIndex(NO_OF_CHARS, -1);
 
    // Initialize start of current window
    int i = 0;
 
    // Move end of current window
    for (int j = 0; j < n; j++) {
 
        // Find the last index of str[j]
        // Update i (starting index of current window)
        // as maximum of current value of i and last
        // index plus 1
        i = max(i, lastIndex[str[j]] + 1);
 
        // Update result if we get a larger window
        res = max(res, j - i + 1);
 
        // Update last index of j.
        lastIndex[str[j]] = j;
    }
    return res;
}

or  

int longestUniqueSubsttr(string s)
{
     
    // Creating a set to store the last positions
    // of occurrence
    map<char, int> seen ;
    int maximum_length = 0;
 
    // Starting the initial point of window to index 0
    int start = 0;
 
    for(int end = 0; end < s.length(); end++)
    {
         
        // Checking if we have already seen the element or
        // not
        if (seen.find(s[end]) != seen.end())
        {
             
            // If we have seen the number, move the start
            // pointer to position after the last occurrence
            start = max(start, seen[s[end]] + 1);
        }
 
        // Updating the last seen value of the character
        seen[s[end]] = end;
        maximum_length = max(maximum_length,
                             end - start + 1);
    }
    return maximum_length;
}


7. Implement LRU cache algorithm:


Queue which is implemented using a doubly linked list. The maximum size of the queue 
will be equal to the total number of frames available (cache size). The most recently 
used pages will be near front end and least recently pages will be near the rear end. 
A Hash with page number as key and address of the corresponding queue node as value.

When a page is referenced, the required page may be in the memory. If it is in the memory, 
we need to detach the node of the list and bring it to the front of the queue. 
If the required page is not in memory, we bring that in memory. In simple words, we add a 
new node to the front of the queue and update the corresponding node address in the hash. 
If the queue is full, i.e. all the frames are full, we remove a node from the rear of the 
queue, and add the new node to the front of the queue.


class LRUCache {
    // store keys of cache
    list<int> dq;
 
    // store references of key in cache
    unordered_map<int, list<int>::iterator> ma;
    int csize; // maximum capacity of cache
 
public:
    LRUCache(int);
    void refer(int);
    void display();
};
 
// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}
 
// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end()) {
        // cache is full
        if (dq.size() == csize) {
            // delete least recently used element
            int last = dq.back();
 
            // Pops the last elmeent
            dq.pop_back();
 
            // Erase the last
            ma.erase(last);
        }
    }
 
    // present in cache
    else
        dq.erase(ma[x]);
 
    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}
 
// Function to display contents of cache
void LRUCache::display()
{
 
    // Iterate in the deque and print
    // all the elements in it
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";
 
    cout << endl;
}
 
// Driver Code
int main()
{
    LRUCache ca(4);
 
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
 
    return 0;
}