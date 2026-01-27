Sliding window

Types:

Array of strings , mentioned substring or subarray

window size, largest or minimum so no 


two Types(based on window size)

1. fixed size 2. variable size 


Q1. Maximum Sum Subarray of size K

int maxSum(int arr[], int n, int k)
{
    // k must be greater
    if (n < k)
    {
       cout << "Invalid";
       return -1;
    }

    int res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];

    int curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}

//second approch
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int a[n];
        
        for(int i=0;i<n;i++)
        {
           cin>>a[i]; 
        }

        int i=0,j=0,sum=0;
        int res = INT_MIN;

        while(j<n)
        {
           if(j-i+1<k)
           {
                sum+=a[j];
                j++;
           } 
           else if(j-i+1 ==k)
           {
               sum+=a[j];
               res = max(res, sum);
               sum-=a[i];
               i++;
               j++;
           }
        }
        cout << res << endl;
        
    }
}

2. First negative integer in every window of size k
//We are only inserting array index in deque

void printFirstNegativeInteger(int arr[], int n, int k)
{
    
    deque<int>  Di;

    int i;
    for (i = 0; i < k; i++)
  
        if (arr[i] < 0)
            Di.push_back(i);
   
    for ( ; i < n; i++)
    {
  
        if (!Di.empty())
            cout << arr[Di.front()] << " ";
      
        else
            cout << "0" << " ";

        while ( (!Di.empty()) && Di.front() < (i - k + 1))
            Di.pop_front();  
  
        if (arr[i] < 0)
            Di.push_back(i);
    }
  

    if (!Di.empty())
           cout << arr[Di.front()] << " ";
    else
        cout << "0" << " ";      
     
}



3. Count occurence of anagrams

/ Input : "forxxorfxdofr", "for"
    // Output : 3
    // Explanation : Anagrams of the word for - for, orf, ofr appear in the text and hence the count is 3.


int solve(string s, string ana){

    unordered_map<char, int> m;
    for(auto it : ana) m[it]++;

    int k=ana.length();
    int count=m.size();
    
    int i=0, j=0;
    int ans=0;
    
    while(j<s.length()){
    
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
        
        if((j-i+1)<k) j++;
        
        else if((j-i+1)==k){

            if(count==0) ans++;

            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
}



4. Maximum of all subarrays of size k


void printKMax(int arr[], int n, int k)
{
     
    // Create a Double Ended Queue,
    // Qi that will store indexes
    // of array elements
    // The queue will store indexes
    // of useful elements in every
    // window and it will
    // maintain decreasing order of
    // values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()]
    // are sorted in decreasing order
    std::deque<int> Qi(k);
 
    /* Process first k (or first window)
     elements of array */
    int i;
    for (i = 0; i < k; ++i)
    {
     
        // For every element, the previous
        // smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && arr[i] >=
                            arr[Qi.back()])
           
             // Remove from rear
            Qi.pop_back();
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
     
        // The element at the front of
        // the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";
 
        // Remove the elements which
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <=
                                           i - k)
           
            // Remove from front of queue
            Qi.pop_front();
 
        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while ((!Qi.empty()) && arr[i] >=
                             arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element
    // of last window
    cout << arr[Qi.front()];
}


5. Variable size Sliding window

  Problems:

  array / strings
  subarray/ substring
  some condition( eg sum)
  maximize or minimize window size



5. Longest sub-array having sum k


int lenOfLongSubarr(int arr[],
                    int n,
                    int k)
{
 
    // unordered_map 'um' implemented
    // as hash table
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
 
    // traverse the given array
    for (int i = 0; i < n; i++) {
 
        // accumulate sum
        sum += arr[i];
 
        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;
 
        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;
 
        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end()) {
 
            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
 
    // required maximum length
    return maxLen;
}


6. Longest Substring With K Unique Characters

Method 2 (Linear Time) 
The problem can be solved in O(n). Idea is to maintain a window 
and add elements to the window till it contains less or equal k,
update our result if required while doing so. If unique elements
exceeds than required in window, start removing the elements 
from left side. Below are the implementations of above. The
implementations assume that the input string alphabet contains 
only 26 characters (from ‘a’ to ‘z’). The code can be easily 
extended to 256 characters. 

// This function calculates number of unique characters
// using a associative array count[]. Returns true if
// no. of characters are less than required else returns
// false.
bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;
 
    // Return true if k is greater than or equal to val
    return (k >= val);
}
 
// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int u = 0; // number of unique characters
    int n = s.length();
 
    // Associative array to store the count of characters
    int count[MAX_CHARS];
    memset(count, 0, sizeof(count));
 
    // Traverse the string, Fills the associative array
    // count[] and count number of unique characters
    for (int i=0; i<n; i++)
    {
        if (count[s[i]-'a']==0)
            u++;
        count[s[i]-'a']++;
    }
 
    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        cout << "Not enough unique characters";
        return;
    }
 
    // Otherwise take a window with first element in it.
    // start and end variables.
    int curr_start = 0, curr_end = 0;
 
    // Also initialize values for result longest window
    int max_window_size = 1, max_window_start = 0;
 
    // Initialize associative array count[] with zero
    memset(count, 0, sizeof(count));
 
    count[s[0]-'a']++;  // put the first character
 
    // Start from the second character and add
    // characters in window according to above
    // explanation
    for (int i=1; i<n; i++)
    {
        // Add the character 's[i]' to current window
        count[s[i]-'a']++;
        curr_end++;
 
        // If there are more than k unique characters in
        // current window, remove from left side
        while (!isValid(count, k))
        {
            count[s[curr_start]-'a']--;
            curr_start++;
        }
 
        // Update the max window size if required
        if (curr_end-curr_start+1 > max_window_size)
        {
            max_window_size = curr_end-curr_start+1;
            max_window_start = curr_start;
        }
    }
 
    cout << "Max sustring is : "
         << s.substr(max_window_start, max_window_size)
         << " with length " << max_window_size << endl;
}
 




7. length-of-the-longest-substring-without-repeating-characters


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



8. Find the smallest window in a string containing all characters of another string

string Minimum_Window(string s, string t)
{
 
    int m[256] = { 0 };
 
    // Answer
    int ans = INT_MAX; // length of ans
    int start = 0; // starting index of ans
    int count = 0;
   
    // creating map
    for (int i = 0; i < t.length(); i++) {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }
 
    // References of Window
    int i = 0;
    int j = 0;
 
    // Traversing the window
    while (j < s.length()) {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;
 
        // Condition matching
        if (count == 0) {
            while (count == 0) {
                // Sorting ans
                if (ans > j - i + 1) {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I
 
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
 
                i++;
            }
        }
        j++;
    }
 
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}
 
main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
     
      cout<<"-->Smallest window that contain all character : "<<endl;
    cout << Minimum_Window(s, t);
}