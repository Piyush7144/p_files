//Dynamic programming:

i. knapsack

return max(knapsack(wt, profit, w, n-1), 
        profit[n] + knapsack(wt, profit, w - wt[n], n-1));

dp[i][w] = max(profit[i-1] + dp[i-1][j - w[i-1]], dp[i-1][w])


ii. subset sum possible

return isSubsetSum(set, n-1, sum) or isSubsetSum(set, n-1, sum- set[n-1]);

subset[i][j] = subset[i-1][j] or subset[i-1][j- set[i-1]];


iii. coin change problem(unbounded kanpsack)

dp[i][j] = min(1+ dp[i][j-coin[i-1]], dp[i-1][j])


iv. Rob cutting problem:

t[n][Max_len]   = max(price[n - 1] + un_kp(price, length, Max_len - length[n - 1], n),
                  un_kp(price, length, Max_len, n - 1));


v. Lcs 

if(p[n-1] == q[m-1])
   return 1 + lcs(p, q, n-1, m-1);
else
    return max(lcs(p, q, n, m-1)), lcs(p,q , n-1, m);


if(x[i-1] == y[j-1])
    lcs[i][j] = lcs[i-1][j-1] + 1;
else
    lcs[i][j] = max(lcs[i-1][j], lcs[j][j-1])

//shortest common supersequenc = length(s1 + s2) - lcs(s1, s2)
//longeset palindromic subsequence = lcs(s1, reverse(s1))
//minimum no of deletion or insertion in a string to make it a palindrom:
    -> length(st) - lps(st)

//longest common substring:
if(s1[i-1] == s2[j-1])
{
    dp[i][j] = dp[i-1][j-1] +1;
    res = max(res, dp[i][j]);
}
else
    dp[i][j] = 0;

//longest palindromic substring:
if (table[i + 1][j - 1] && str[i] == str[j]) {
    table[i][j] = true;

    if (k > maxLength) {
        start = i;
        maxLength = k;
    }
}


vi. Longest Increasing subsequence:

lis[0] = 1;
for(int i = 1; i< n; i++)
{
    lis[i] = 1;
    for(int j = 0; j< i; j++)
    {
        if(ar[i] > ar[j] && lis[i] < 1+ lis[j])
            lis[i] = lis[j] +1;
    }
}
return *max_element(lis, lis+n);

//minimum jump to reach end:

jump[0] = 0;
for(int i = 1; i< n; i++)
{
    jump[i] = INT_MAX;
    for(int j = 0; j< i; j++)
    {
        if(i <= j+ ar[j] && jumps[j] != INT_MAX)
        {
            jumps[i] = min(jumps[i], jumps[j] + 1);
            break;
        }
    }
}
return jumps[n-1];

//rod cutting:

val[0] = 0;
for(int i = 1; i<= n; i++)
{
    int maxVal = INT_MIN;
    for(int j = 0; j< i; j++)
    {
        maxVal = max(maxVal, price[j] + val[i-j-1]);
    }
    va[i] = maxVal;
}
return val[n];


vii. Edit distance:

if(s1[i-1] == s2[j-1])
    dp[i][j] = dp[i-1][j-1];
else
    dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);


viii. Matrix chain multiplication

int solve(int ar[], int i, int j)
{
    if( i>= j)
        return 0;
    int min= INT_MAX;

    for(int k = i; k<= j-1; k++)
    {
        int tempAns = solve(ar, i, k) + solve(ar, k+1, j)+ ar[i-1]* ar[k] * ar[j];
        if(tempAns < min)
            min = tempAns;
    }
    return min;
}

//egg droping puzzle

int solve(int e, int f)
{
    if(f ==  0 || f ==1 )
        return f;
    if(e == 1)
        return f;
    int mn = INT_MAX;
    for(int k = 1; k<= f; k++)
    {
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
        mn = min(mn, temp);
    }

    return mn;
}


//minimum palindromic partition

int solve(string st, int i, int j)(
{
    if(i >= j)
        return 0;
    if(isPalindrome(st, i, j))
        return 0;

    int mn = INT_MAX;

    for(int k = 1; k<= j-1; k++)
    {
        int temp = 1 + min(solve(st,i,k), solve(st,k+1, j));
        mn = min(mn, temp);
    }

    return mn;
}
1. 0-1 Knapsack

//recurion
int kanpsack(int w[], int profit[], int w, int n)
{
    if(n == 0 || w == 0)
        return 0;
    if(wt[n] > w)
        return knapsack(wt, profit, w, n-1);
    else
    {
        return max(knapsack(wt, profit, w, n-1), 
               profit[n] + knapsack(wt, profit, w-wt[n], n-1));

    }
}


//memoization
int knapsack(int w, int w[], int val[], int i, int** dp)
{
    if( i< 0)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    if(wt[i] > w) {
        dp[i][w] = knapsack(w,wt, val, i-1, dp);
    }
    else{
        dp[i][w] = max(val[i] + knapsack(w-wt[i], wt, val, i-1, dp), 
                    knapsack(w, wt, val, i-1, dp));

    }
    return dp[i][w];
}

int knap(int, w, int wt[], int va[], int n)
{
    int** dp;
    dp = new int*[n+1];
    for(int i = 0; i< n+1; i++)
        dp[i] = new int[w+1];

    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< w+1; j++)
            dp[i][j] = -1;
    }

    return knapsack(w,wt,val, n, dp);
}


//tabulation
int knapsack(int w, int wt[], int val[], int n)
{
    int k[n+1][w+1];

    for(int i = 0; i<= n; i++)
    {
        for(int j = 0; j<= w; j++)
        {
            if( i == 0 || j == 0)
                k[i][j] = 0;
            else if(wt[i-1] <= w){
                k[i][j] = max(val[i-1] + k[i-1][j-wt[i-1]],  
                            k[i-1][w]);
            }
            else
                k[i][j] = k[i-1][j];
        }
    }
    return k[n][w];
}


1. Jump game 1

[1,3,2,0,2]

If we start jumping from the zero index can we reach last index

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int reachable = 0;
        
        for(int i=0;i<n;++i)
        {
            if(reachable < i)
                return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true;        
    }
};




2. Minimum no of jumps to reach end:

Method 2: Dynamic Programming. 
Approach: 

In this way, make a jumps[] array from left to right such that jumps[i] indicate the minimum number of jumps needed to reach arr[i] from arr[0].
To fill the jumps array run a nested loop inner loop counter is j and outer loop count is i.
Outer loop from 1 to n-1 and inner loop from 0 to i.
if i is less than j + arr[j] then set jumps[i] to minimum of jumps[i] and jumps[j] + 1. initially set jump[i] to INT MAX
Finally, return jumps[n-1].



int minJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}


dp: O(n2) solution


Approch 2. linear bfs
https://www.youtube.com/watch?v=_6QpiqTw_ew

int minJumps(int arr[], int n)
{
 
    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;
 
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
 
    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];
 
    // stores the number of steps
    // we can still take
    int step = arr[0];
 
    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;
 
    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;
 
        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);
 
        // we use a step to get to the current index
        step--;
 
        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;
 
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;
 
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
 
    return -1;
}


3. Best time to buy and sell stock one transaction

Algo:

if(arr[i] < min_element)
	min_element = arr[i];
else if(arr[i] - min_element > profit)
	profit = arr[i] - min_element;


3.2 Best time to buy and sell stock any no of times

//Peak valley explanation
Algo:

if(arr[i] > arr[i-1])
	profit += arr[i] - arr[i-1];


3.3 Best time to buy and sell stock for atmost twice

Approach 3 (O(N) time O(1) space) [ACCEPTED]
Suppose you make some profit p1 by doing your first transaction in the stock market. Now you are excited to 
purchase another stock to earn more profit. Suppose the price of the second stock you aim to buy is x. Now, 
for you, the net effective price that you are spending from your pocket for this stock will be x-p1, because 
    you already have p1 bucks in your hand. Now, if you sell the second stock at price y your net profit p2 
will be p2 = y - (x-p1). You have to do nothing but maximize this profit p2. Heres the code:

int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }

//code2
int maxProfit(int price[], int n)
{
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] > max_price)
            max_price = price[i];

        profit[i]
            = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        if (price[i] < min_price)
            min_price = price[i];

        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}


3.3 Best time to buy and sell stock for atmost k transactions  

//this is O(kn2) solution , O(kn) solution also exists


int maxProfit(int price[], int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using
    // atmost t transactions up to day i (including
    // day i)
    int profit[k + 1][n + 1];
 
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int max_so_far = INT_MIN;
 
            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m]);
 
            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }
 
    return profit[k][n - 1];
}
 


4.  Minimum cost to reach the top of the floor by climbing stairs


int minimumCost(int cost[], int n)
{
    // declare an array
    int dp[n];
 
    // base case
    if (n == 1)
        return cost[0];
 
    // initially to climb till 0-th
    // or 1th stair
    dp[0] = cost[0];
    dp[1] = cost[1];
 
    // iterate for finding the cost
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
 
    // return the minimum
    return min(dp[n - 2], dp[n - 1]);
}



5. House robbers:

class solution{
    public int rob(int[] nums){
        int n = nums.length;
        if(n == 0){
            return 0;
        }
        if(n ==1 )
            return nums[0];

        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(dp[0], dp[1]);

        for(int i = 2; i< n; i++)
        {
            dp[i] = Math.max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
}

6. Longest common substring

int longestCommonString (string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];

    int res = 0;
    for(int i = 0; i<= n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] +1;
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
}


7. Longest palindromic substring:

int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();
 
    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
 
    memset(table, 0, sizeof(table));
 
    // All substrings of length 1
    // are palindromes
    int maxLength = 1;
 
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
 
    // return length of LPS
    return maxLength;
}


8. Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can 
remain single or can be paired up. 

f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1. n-th person remains single, we recur 
   for f(n - 1)
2. n-th person pairs up with any of the 
   remaining n - 1 persons. We get (n - 1) * f(n - 2)

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)


int countFriendsPairings(int n)
{
    int dp[n + 1];
 
    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i = 0; i <= n; i++) {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
 
    return dp[n];
}


9. Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, 
find number of ways to reach the given score.


int count(int n)
{
    // table[i] will store count
    // of solutions for value i.
    int table[n + 1], i;
 
    // Initialize all table
    // values as 0
    for(int j = 0; j < n + 1; j++)
            table[j] = 0;
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // One by one consider given 3 moves
    // and update the table[] values after
    // the index greater than or equal to
    // the value of the picked move
    for (i = 3; i <= n; i++)
    table[i] += table[i - 3];
     
    for (i = 5; i <= n; i++)
    table[i] += table[i - 5];
     
    for (i = 10; i <= n; i++)
    table[i] += table[i - 10];
 
    return table[n];
}


10. A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y. 
In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks the 
last coin wins the game or the person who is not able to pick any coin loses the game. For a given value 
of n, find whether A will win the game or not if both are playing optimally.


//We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y. 

bool findWinner(int x, int y, int n)
{
    // To store results
    int dp[n + 1];
 
    // Initial values
    dp[0] = false;
    dp[1] = true;
 
    // Computing other values.
    for (int i = 2; i <= n; i++) {
 
        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;
 
        // Else A loses game.
        else
            dp[i] = false;
    }
 
    // If dp[n] is true then A will
    // game otherwise  he losses
    return dp[n];
}


11. Optimal Strategy For A Game

You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an 
opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from 
the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.


//this uses minmax concept

int dp[100][100];

int solve(int i, int j){
    if(i == j){
        return a[i];
    }
    if(i> j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int l = a[i] + min(solve(i+2, j), solve(i+1, j-1));
    //A[i...j] , remaining coins = A[i+1....j]
    int r = a[j] + min(solve(i,j-2), solve(i+1, j-1));
    //A[i...j] , remaining coins = A[i...j-1]

    return dp[i][j] = max(l,r);
}


12. Wild card pattern matching

DP Initialization: 

// both text and pattern are null
T[0][0] = true; 

// pattern is null
T[i][0] = false; 

// text is null
T[0][j] = T[0][j - 1] if pattern[j – 1] is '*'  

//
if ( pattern[j – 1] == ‘?’) || 
     (pattern[j – 1] == text[i - 1])
    T[i][j] = T[i-1][j-1]

else if (pattern[j – 1] == ‘*’)
    T[i][j] = T[i][j-1] || T[i-1][j]  

else // if (pattern[j – 1] != text[i - 1])
    T[i][j]  = false 


bool strmatch(char str[], char pattern[], int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);
 

    bool lookup[n + 1][m + 1];
 
    // initialize lookup table to false
    memset(lookup, false, sizeof(lookup));
 
    // empty pattern can match with empty string
    lookup[0][0] = true;
 
    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Two cases if we see a '*'
            // a) We ignore ‘*’ character and move
            //    to next  character in the pattern,
            //     i.e., ‘*’ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
            if (pattern[j - 1] == '*')
                lookup[i][j]
                    = lookup[i][j - 1] || lookup[i - 1][j];
 
            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[j - 1] == '?'
                     || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
 
            // If characters don't match
            else
                lookup[i][j] = false;
        }
    }
 
    return lookup[n][m];
}

13. Maximum product subarray

class Solution{
public:

    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n) {
        // code here
        long long int maxp = INT_MIN, prod = 1;
        for(int i=0;i<n;i++){
            prod *= arr[i];
            maxp = max(maxp, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        
        prod = 1;
        for(int i=n-1;i>=0;i--){
            prod *= arr[i];
            maxp = max(maxp, prod);
            if(prod == 0){
                prod = 1;
            }
        }
        
        return maxp;
    }
};



14. minimum lights to activate interviewbit 

There is a corridor in a Jail which is N units long. Given an array A of size N. 
The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

All the lights are of specific power B which if is placed at position X, it can light 
the corridor from [ X-B+1, X+B-1].

Initially all lights are off.

Return the minimum number of lights to be turned ON to light the whole corridor or -1 if 
the whole corridor cannot be lighted.

int solve(vector<int> &A, int B){

    int count = 0;
    int i = 0;
    int n = A.size();

    while(i<n)
    {
        int right = min(i+B-1, n-1);
        int left = max(i-B+1, 0);

        bool bulbfound = false;
        while(right>= left)
        {
            if(A[right] == 1)
            {
                bulbfound = true;
                break;
            }
            right--;
        }

        if(!bulbfound) return -1;

        count++;
        i = right+B;
    }
}

15. No of binary strings with consecutive ones not allowed:


long long countString(int n){

    int zeroEnd = 1;
    int oneEnd = 1;

    int sum = zeroEnd+ oneEnd;
    if(n == 1)
        return sum;

    int  i = 2;
    while(i<= n)
    {
        oneEnd = zeroEnd % mod;
        zeroEnd = sum % mod;

        sum = zeroEnd + oneEnd % mod;
        i++;
    }

    return sum%mod;
}


16. nth Ugly numbers: (numbers which are multiple of 2, 3 or 5) 1 included

class Solution{
public:
    int nthUglyNumber(int n){

        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        for(int i = 1; i< n; i++)
        {
            int twomultiple = dp[p1] * 2;
            int threemultiple = dp[p2]* 3;
            int fivemultiple = dp[p3] * 5;

            dp[i] = min(twomultiple, min(threemultiple, fivemultiple));

            if(dp[i] == twomultiple) p1++;

            if(dp[i] == threemultiple) p2++;

            if(dp[i] == fivemultiple) p2++;

        }
        return dp[n-1];
    }
}


17. Sorted sub matrix sum maximization:

int Solution:: solve(vector<vector<int>> &A)
{

    int n = A.size();
    int m = A[0].size();

    vector<vector<int>> kingdom(n+1, vector<int>(m+1, 0));

    for(int i = n; i>= 0; i++)
    {
        for(int j = m; j >= 0; j++)
        {

            if( i == n || j == m) continue;

            kingdom[i][j] = A[i][j] + kingdom[i+1][j] + kingdom[i][j+1] - kingdom[i+1][j+1];

            ans = max(ans, kingdom[i][j]);
        }
    }
    return ans;
}


18. Russian Doll envelopes problem:( based on LIS)

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        if(n==0)
            return 0;
        
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n+1,1);
        int max = 1;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(envelopes[i][0]>envelopes[j][0]
                   && envelopes[i][1]>envelopes[j][1]
                   && 1+dp[j]>dp[i])
                    dp[i] = 1 + dp[j];
                if(max<dp[i])
                    max = dp[i];
            }
        }
        return max;
    }
};


19. Given an integer element ‘N’, the task is to find the minimum number of operations that need to be 
performed to make ‘N’ equal to 1. 
The allowed operations to be performed are: 

Decrement N by 1.
Increment N by 1.
If N is a multiple of 3, you can divide N by 3.


Sol: Approach: 

If the number is a multiple of 3, divide it by 3.
If the number modulo 3 is 1, decrement it by 1.
If the number modulo 3 is 2, increment it by 1.
There is an exception when the number is equal to 2, in this case the number should be decremented by 1.
Repeat the above steps until the number is greater than 1 and print the count of operations performed in the end.


int static dp[1001];
 
// Function that returns the minimum
// number of operations to be performed
// to reduce the number to 1
int count_minimum_operations(long long n)
{
    // Base cases
    if (n == 2) {
        return 1;
    }
    if (n == 1) {
        return 0;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    if (n % 3 == 0) {
        dp[n] = 1 + count_minimum_operations(n / 3);
    }
    else if (n % 3 == 1) {
        dp[n] = 1 + count_minimum_operations(n - 1);
    }
    else {
        dp[n] = 1 + count_minimum_operations(n + 1);
    }
    return dp[n];
}


20. Given a positive integer N, the task is to find the minimum number of operations needed to 
convert N to 2 either by decrementing N by 3 or dividing N by 5 if N is divisible by 5. If it is 
not possible to reduce N to 2, then print “-1”.

int minimumOperations(int N)
{
    // Initialize the dp array
    int dp[N + 1];
    int i;
 
    // Initialize the array dp[]
    for (int i = 0; i <= N; i++) {
        dp[i] = 1e9;
    }
 
    // For N = 2 number of operations
    // needed is zero
    dp[2] = 0;
 
    // Iterating over the range [1, N]
    for (i = 2; i <= N; i++) {
 
        // If it's not possible to
        // create current N
        if (dp[i] == 1e9)
            continue;
 
        // Multiply with 5
        if (i * 5 <= N) {
            dp[i * 5] = min(dp[i * 5],
                            dp[i] + 1);
        }
 
        // Adding the value 3
        if (i + 3 <= N) {
            dp[i + 3] = min(dp[i + 3],
                            dp[i] + 1);
        }
    }
 
    // Checking if not possible to
    // make the number as 2
    if (dp[N] == 1e9)
        return -1;
 
    // Return the minimum number
    // of operations
    return dp[N];
}