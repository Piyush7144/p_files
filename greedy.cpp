1. Activity selection problem

Lots of start and end times are given, find maximum number of activities 
that can be done.

Sol. Take the activity which ends first
     there sort the activities with respect to end time
     Select first activity then activities with start time >= end of previous selected

void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr+n, activityCompare);
 
    cout << "Following activities are selected n";
 
    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
 
    // Consider rest of the activities
    for (int j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (arr[j].start >= arr[i].finish)
      {
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), ";
          i = j;
      }
    }
}


2.  Job Sequencing Problem O(n2 solution) O(nlogn also exits)

Given a set of N jobs where each jobi has a deadline and profit associated with it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit if and only if the job is completed by its deadline. The task is to 
find the number of jobs done and the maximum profit.

struct Job 
{ 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool comparision(Job a, Job b)
{
    return (a.profit > b.profit);
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparision);
        int maxProfit = 0;
        int noJobs = 0;
        
        bool slots[100]; //since 100 is max deadline

        for(int i = 0; i< 100; i++)
        {
            slots[i] = false;
        }
        
        for(int i = 0; i< n; i++)
        {
            for(int j = arr[i].dead-1; j>= 0; j--)
                //important arr[i].dead can be greater than array size
            {
                if(slots[j] == false)
                {
                    slots[j] = true;
                    maxProfit += arr[i].profit;
                    noJobs += 1;
                    break;
                }
            }
        }
        
        return  { noJobs, maxProfit};
        
    } 
};



3. water connection problem

Every house in the colony has at most one pipe going into it and at most one 
pipe going out of it. Tanks and taps are to be installed in a manner such that 
every house with one outgoing pipe but no incoming pipe gets a tank installed 
on its roof and every house with only an incoming pipe and no outgoing pipe gets a tap.’ 

The output will contain the number of pairs of tanks and taps t installed in 
first line and the next t lines contain three integers: house number of tank, 
house number of tap and the minimum diameter of pipe between them.


Perform DFS from appropriate houses to find all different connected components. 
The number of different connected components is our answer t. 
The next t lines of the output are the beginning of the connected component, 
end of the connected component and the minimum diameter from the start to the 
end of the connected component in each line. 
Since, tanks can be installed only on the houses having outgoing pipe and no 
incoming pipe, therefore these are appropriate houses to start DFS from i.e. 
perform DFS from such unvisited houses.
Below is the implementation of above approach:




4. Maximum trains for which stoppage can be provided

Input : n = 3, m = 6 
Train no.|  Arrival Time |Dept. Time | Platform No.
    1    |   10:00       |  10:30    |    1
    2    |   10:10       |  10:30    |    1
    3    |   10:00       |  10:20    |    2
    4    |   10:30       |  12:30    |    2
    5    |   12:00       |  12:30    |    3
    6    |   09:00       |  10:05    |    1
Output : Maximum Stopped Trains = 5
Explanation : If train no. 1 will left 
to go without stoppage then 2 and 6 can 
easily be accommodated on platform 1. 
And 3 and 4 on platform 2 and 5 on platform 3.


Same as activity selection problem with different vectors:

int maxStop(int arr[][3])
{
    // declaring vector of pairs for platform
    vector<pair<int, int> > vect[n + 1];
  
    // Entering values in vector of pairs
    // as per platform number
    // make departure time first element 
    // of pair
    for (int i = 0; i < m; i++)
        vect[arr[i][2]].push_back(
             make_pair(arr[i][1], arr[i][0]));
  
    // sort trains for each platform as per
    // dept. time
    for (int i = 0; i <= n; i++)
        sort(vect[i].begin(), vect[i].end());
      
    // perform activity selection approach
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (vect[i].size() == 0)
            continue;
  
        // first train for each platform will
        // also be selected
        int x = 0;
        count++;
        for (int j = 1; j < vect[i].size(); j++) {
            if (vect[i][j].second >=
                             vect[i][x].first) {
                x = j;
                count++;
            }
        }
    }
    return count;
}



5. Fractional Kapsack


struct Item{
    int value;
    int weight;
};

bool comparision(Item a, Item b)
{
    return ((double) a.value/ a.weight > (double)b.value/ b.weight);
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comparision);
        
        double remaining = W;
        double profit = 0.0;
        
        for(int i = 0; i< n; i++)
        {
            if(remaining >= arr[i].weight)
            {
                profit += arr[i].value;
                remaining -= arr[i].weight;
            }
            else 
            {
                profit += ((double)arr[i].value/ arr[i].weight) * remaining;
                remaining = 0.0;
            }
        }
        
        return profit;
        // Your code here
    }
        
};


6. Greedy Algorithm to find Minimum number of Coins
   (Does not work for  best solution, best sol is with dp)


int deno[] = { 1, 2, 5, 10, 20,
               50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);
 
void findMin(int V)
{
    sort(deno, deno + n);
 
    // Initialize result
    vector<int> ans;
 
    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--) {
 
        // Find denominations
        while (V >= deno[i]) {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
 
    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}


7.  Minimum Number of Platforms Required for a Railway/Bus Station

Given arrival and departure times of all trains that reach a railway station. 
Find the minimum number of platforms required for the railway station so that 
no train is kept waiting.


int findPlatform(int arr[], int dep[], int n)
{
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);
 
    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
 
    // Similar to merge in merge sort to process
    // all events in sorted order
    while (i < n && j < n) {
        // If next event in sorted order is arrival,
        // increment count of platforms needed
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
 
        // Else decrement count of platforms needed
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
 
        // Update result if needed
        if (plat_needed > result)
            result = plat_needed;
    }
 
    return result;
}


8. Buy Maximum Stocks if i stocks can be bought on i-th day

Simple start with minimum price stock

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int> > v;
 
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));   
 
    sort(v.begin(), v.end());   
 
    // Calculating the maximum number of stock count.
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second,
                               (k / v[i].first));
    }
 
    return ans;
}




9. Find the minimum and maximum amount to buy all N candies(Shop in candy store)


In a candy store, there are N different types of candies available and the prices of all the N 
different types of candies are provided to you. You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you 
have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount 
of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.


//Easy solution just sort the candies
vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        int minAmt = 0;
        int maxAmt = 0;
        
        int len = N;
        int base = 0;
        
        for(int i = 0; i< len; i++)
        {
            minAmt += candies[i];
            len -= K;
        }
        for(int j = N-1; j>= base; j--)
        {
             maxAmt += candies[j];
            base += K;
        }
        return {minAmt, maxAmt};
    }


10. Maximum meetings in one room

(same as activity selection problem)


struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2)
{
    return (m1.end < m2.end);
}
 
void maxMeeting(int s[], int f[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {

        meet[i].start = s[i];

        meet[i].end = f[i];
        meet[i].pos = i + 1;
    }

    sort(meet, meet + n, comparator);

    vector<int> m;

    m.push_back(meet[0].pos);

    int time_limit = meet[0].end;
 

    for (int i = 1; i < n; i++) {
        if (meet[i].start >= time_limit)
        {
 
            m.push_back(meet[i].pos);

            time_limit = meet[i].end;
        }
    }

    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
}


11. Check if it is possible to survive on island

Just see the condition you will get the answer  

void survival(int S, int N, int M)
{
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        cout << "No\n";
    else {
        int days = (M * S) / N;
        if (((M * S) % N) != 0)
            days++;
        cout << "Yes " << days << endl;
    }
}


12. Maximum product subset of an array

A better solution is to use the below facts.

If there are even number of negative numbers and no zeros, result
is simply product of all If there are odd number of negative numbers 
and no zeros, result is product of all except the negative integer 
with the least absolute value.
If there are zeros, result is product of all except these zeros with
 one exceptional case. The exceptional case is when there is one 
 negative number and all other elements are 0. In this case, result is 0.



13. Maximize array sum after K negations

Easy with priority_queue , interesting without it.


Sort the array in ascending order. Initialize i = 0.
Increment i and multiply all negative elements by -1 till k becomes zero or a positive element is reached.
Check if the end of the array has occurred. If true then go to (n-1)th element.
If k ==0 or k is even, return the sum of all elements. Else multiply the absolute 
of minimum of ith or (i-1) th element by -1.
Return sum of the array.



14.Maximum sum of absolute difference of any permutation

Ideal: Higest - lowest ; make array of low and high and find absolute difference

def maxSum(a,n):
    sum=0
    a.sort()
    l=[]
    counter=0
    k=0
    i=0
    j=n-1
    while k<n:
        if counter%2==0:
            l.append(a[i])
            i+=1
        else:
            l.append(a[j])
            j-=1
        counter+=1
        k+=1
    maxSum=0
    for i in range(0,n-1):
        maxSum+=abs(l[i+1]-l[i])

    maxSum+=(l[n-1]-l[0])
    print(maxSum)


14  Minimum sum of absolute difference of pairs of two arrays

The solution to the problem is a simple greedy approach. It consists of two steps. 
Step 1 : Sort both the arrays in O (n log n) time. 
Step 2 : Find absolute difference of each pair of corresponding elements 
(elements at same index) of both arrays and add the result to the sum S. 
The time complexity of this step is O(n).
Hence, the overall time complexity of the program is O(n log n


15.  Smallest subset with sum greater than all other elements

The Efficient Approach is to take the largest elements.
We sort values in descending order, then take elements from the 
largest, until we get strictly more than half of total sum of the given array. 



16.  Chocolate Distribution Problem

Given an array A[ ] of positive integers of size N, where each value represents the number 
of chocolates in a packet. Each packet can have a variable number of chocolates. There are 
M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number 
of chocolates given to a student is minimum.


//solution
An efficient solution is based on the observation that to 
minimize the difference, we must choose consecutive elements 
from a sorted packet. We first sort the array arr[0 to n-1], then 
find the subarray of size m with the minimum difference between 
the last and first elements.

def findMinDiff(self, A,N,M):
        i=0
        j=M-1
        d=float("inf")
        A.sort()
        while j<N:
            d=min(d,A[j]-A[i])
            j+=1
            i+=1
        
        return d


17. Find smallest number with given number of digits and sum of digits

There is a Greedy approach to solve the problem. The idea 
is to one by one fill all digits from rightmost to leftmost 
(or from least significant digit to most significant). 
We initially deduct 1 from sum s so that we have smallest 
digit at the end. After deducting 1, we apply greedy approach. 
We compare remaining sum with 9, if remaining sum is more than 9, 
we put 9 at the current position, else we put the remaining sum. 
Since we fill digits from right to left, we put the highest 
digits on the right side. Below is implementation of the idea.



18. Rearrange characters in a string such that no two adjacent are same

Another approach is to fill all the even positions of the result string 
first, with the highest frequency character. If there are still some even 
positions remaining, fill them first. Once even positions are done, then 
fill the odd positions. This way, we can ensure that no two adjacent 
characters are the same. 

char getMaxCountChar(const vector<int>& count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
 
    return ch;
}
 
string rearrangeString(string S)
{
 
    int n = S.size();
    if (!n)
        return "";
 
    vector<int> count(26, 0);
    for (auto ch : S)
        count[ch - 'a']++;
 
    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];
 
    // check if the result is possible or not
    if (maxCount > (n + 1) / 2)
        return "";
 
    string res(n, ' ');
 
    int ind = 0;
    // filling the most frequently occuring char in the even
    // indices
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;
 
    // now filling the other Chars, first filling the even
    // positions and then the odd positions
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}


19.  Find maximum sum possible equal sum of three stacks(+ve numbers)

The idea is to compare the sum of each stack, if they are not same,
 remove the top element of the stack having the maximum sum.
Algorithm for solving this problem: 

Find the sum of all elements of in individual stacks.
If the sum of all three stacks is the same, then this is the maximum sum.
Else remove the top element of the stack having the maximum sum among 
three of stacks. Repeat step 1 and step 2.


int maxSum(int stack1[], int stack2[], int stack3[], int n1,
           int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
 
    // Finding the initial sum of stack1.
    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];
 
    // Finding the initial sum of stack2.
    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];
 
    // Finding the initial sum of stack3.
    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];
 
    // As given in question, first element is top
    // of stack..
    int top1 = 0, top2 = 0, top3 = 0;
    while (1) {
        // If any stack is empty
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;
 
        // If sum of all three stack are equal.
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
 
        // Finding the stack with maximum sum and
        // removing its top element.
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];
    }
}


20. Maximize sum of consecutive differences in a circular array

sort and arange in: a1, an, a2, an-1,…., an/2, a(n/2) + 1 

int maxSum(int arr[], int n)
{
    int sum = 0;
 
    // Sorting the array.
    sort(arr, arr + n);
 
    // Subtracting a1, a2, a3,....., a(n/2)-1, an/2
    // twice and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,.
    // ...., an - 1, an twice.
    for (int i = 0; i < n/2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }
 
    return sum;
}