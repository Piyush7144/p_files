1. 3 sum problem:

Method 2: This method uses sorting to increase the efficiency of the code. 

Approach: By Sorting the array the efficiency of the algorithm can be improved. 
This efficient approach uses the two-pointer technique. Traverse the array and 
fix the first element of the triplet. Now use the Two Pointers algorithm to find 
if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take 
linear time so it is better than a nested loop.

Algorithm : 
Sort the given array.
Loop over the array and fix the first element of the possible triplet, arr[i].
Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
If the sum is smaller than the required sum, increment the first pointer.
Else, If the sum is bigger, Decrease the end pointer to reduce the sum.
Else, if the sum of elements at two-pointer is equal to given sum then print the triplet and break.

bool find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
 
    /* Sort the elements */
    sort(A, A + arr_size);
 
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) {

        l = i + 1; 
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}

Method 3:

Approach: This approach uses extra space but is simpler than the two-pointers approach. 
Run two loops outer loop from start to end and inner loop from i+1 to end. Create a hashmap 
or set to store the elements in between i+1 to j-1. So if the given sum is x, check if there 
is a number in the set which is equal to x – arr[i] – arr[j]. If yes print the triplet. 
 
Algorithm: 
Traverse the array from start to end. (loop counter i)
Create a HashMap or set to store unique pairs.
Run another loop from i+1 to end of the array. (loop counter j)
If there is an element in the set which is equal to x- arr[i] – arr[j], then print the triplet 
(arr[i], arr[j], x-arr[i]-arr[j]) and break
Insert the jth element in the set.

bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {
 
        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }
 
    // If we reach here, then no triplet was found
    return false;
}


2. Remove duplicates from sorted array and modify array such that all unique elements are in the front


//first method
store all elements in set(log(n)) then insert all set element in array from beginning
O(nlog(n)) solution:


//second method two pointers
class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		int i = 0;

		for(int j = 1; j< nums.size(); j++){
			if(nums[j] != nums[i]){
				i++;
				nums[i] = nums[j];
			}
		}
	}
	return i+1;
}


3. Max consecutive ones:

class Solutions{
	public:
		int maxOnes(vector<int>& nums) {
			int count = 0;
			int maxi = 0;
			for(int i = 0; i< nums.size(); i++)
			{
				if(nums[i] == 1) {
					count++;
				}
				else {
					count = 0;
				}
				maxi = max(maxi,count);
			}
			return maxi;
		}
}



4. Subarray with given sum (non negative)


a. naive O(n^2) find all Subarray

	for (i = 0; i < n; i++) {
		        curr_sum = arr[i];
 
        // try all subarrays starting with 'i'
        for (j = i + 1; j <= n; j++) {
            if (curr_sum == sum) {
                cout << "Sum found between indexes "
                     << i << " and " << j - 1;
                return 1;
            }
            if (curr_sum > sum || j == n)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }

Efficient Approach: There is an idea if all the elements of the array are positive.
If a subarray has sum greater than the given sum then there is no possibility that
adding elements to the current subarray the sum will be x (given sum). Idea is to
use a similar approach to a sliding window. Start with an empty subarray, add elements 
to the subarray until the sum is less than x.If the sum is greater than x, remove elements 
from the start of the current subarray.


b. using two pointers
   

   int subArraySum(int arr[], int n, int sum)
{
    int curr_sum = arr[0], start = 0, i;
 
    
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
 
        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }

        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
    cout << "No subarray found";
    return 0;
}


5. Subarray with given sum Handles Negative Numbers

https://stackoverflow.com/questions/39322019/using-a-map-to-
find-subarray-with-given-sum-with-negative-numbers/39322103#39322103


The idea is to store the sum of elements of every 
prefix of the array in a hashmap, i.e for every index
store the sum of elements upto that index hashmap. 
So to check if there is a subarray with sum equal to
 s, check for every index i, and sum upto that index 
 as x. If there is a prefix with sum equal to x – s, 
 then the subarray with given sum is found.

//code 

void subArraySum(int arr[], int n, int sum)
{
   
    unordered_map<int, int> map;
 
    int curr_sum = 0;
 
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
 
        if (curr_sum == sum)
        {
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl;
            return;
        }

        if (map.find(curr_sum - sum) != map.end())
        {
            cout << "Sum found between indexes "
                 << map[curr_sum - sum] + 1
                 << " to " << i << endl;
            return;
        }
 
        map[curr_sum] = i;
    }

    cout << "No subarray with given sum exists";
}

