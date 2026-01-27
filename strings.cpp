1. Print first character of every word


for(int i = 0; i< s.length(); i++)
{
	if(s[i] != ' ')
	{
		if(i == 0)
			cout<<s[i]<<endl;
		else if(s[i-1] == ' ')
			cout<<s[i]<<endl;
	}
}


2. Trim string in c++

int start = 0, end = 0;	
	for(int i = 0; i< (int)st.length(); i++)
	{
		if(st[i] != ' ')
		{
			start = i;
			break;
		}
	}
	for(int i = (int)st.length()-1 ; i>= 0; i--)
	{
		if(st[i] != ' ')
		{
			end = i;
			break;
		}
	}
	
	st = st.substr(start);
	st = st.substr(0,end+1);
	cout<< st<<endl;

3. Find words in sentence after trim:

	int i = 0; 
	string s;
	
	st += " ";
	while(i != (int)st.length())
	{
		if( st[i] != ' ')
			s += st[i];
		else
		{
			cout<<s<<endl;
			s = "";
		}
		i++;
	}

4. String to uppercase and lowercase

//string to lowercase
for(int i = 0; i< (int)st.length(); i++)
{
	if(st[i] >= 'A' && st[i] <= 'Z')
	{
		st[i] = st[i] + ('a' - 'A');
	}
}
	
//sting to uppercase
for(int i = 0; i< (int)st.length(); i++)
{
	if(st[i] >= 'a' && st[i] <= 'z')
		st[i] = st[i] - ('a' - 'A');
}



5. Reverse string:


void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

6. Print all the duplicates in the input string

Algorithm: Let input string be “geeksforgeeks” 
1: Construct character count array from the input string.
count[‘e’] = 4 
count[‘g’] = 2 
count[‘k’] = 2 
……
2: Print all the indexes from the constructed array which have values greater than 1.
Solution 

Time Complexity: O(n), where n = length of the string passed
Space Complexity: O(NO_OF_CHARS)


Using Maps

Approach: The approach is the same as discussed in Method 1, but, using a map to store the count.


Time Complexity: O(N log N), where N = length of the string passed and it generally takes logN time for an element insertion in a map.
Space Complexity: O(K), where K = size of the map (0<=K<=input_string_length).10



7. A Program to check if strings are rotations of each other or not

1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.


bool areRotations(string str1, string str2)
{
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length())
        return false;
 
   string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}


//Second method
Algorithm :

1. If the size of both the strings is not equal, then it can never be possible.
2. Push the original string into a queue q1.
3. Push the string to be checked inside another queue q2.
4. Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.
5. If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.




8.Write a Program to check whether a string is a valid shuffle of two strings or not


boolean shuffleCheck(String first, String second, String result) {
    
    // sort each string to make comparison easier
    first = sortString(first);
    second = sortString(second);
    result = sortString(result);

    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length()) {

      if (i < first.length() && first.charAt(i) == result.charAt(k))
        i++;

      else if (j < second.length() && second.charAt(j) == result.charAt(k))
        j++;

      else {
        return false;
      }

      k++;
    }

    if(i < first.length() || j < second.length()) {
      return false;
    }

    return true;
  }

9. Longest palindromic substring

//notebook

10. Longest recurring subsequence

//same as longest repeating subsequence

11. Print all subsequence of string  

//same as print all subsets of string

12.  print all permutations of string

//done

13.  Split the Binary string into two substring with equal 0’s and 1’s


Initialize count = 0 and traverse the string character by character 
and keep track of the number of 0s and 1s so far, whenever the count of 
0s and 1s become equal increment the count. As in the given question, 
if it is not possible to split string then we must not have any sub string 
	having equal number of 0’s and 1’s on that time count = 0 then return -1 
else print the value of count after the traversal of the complete string.s


14.  Edit distance 

//done

15 . Find next greater number with same set of digits. [Very Very IMP]


//done same as next permutations

16. Check for balance paranthesis:

char utility(char ch){
        if(ch == '(')
            return ')';
        else if(ch == '{')
            return '}';
        else
            return ']';
    }
    
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        int index = 0;
        
        while(index < x.length())
        {
            
            if(x[index] == '(' || x[index] == '[' || x[index] == '{')
            {
                s.push(utility(x[index++]));
                continue;
            }
            else
            {
                if(s.empty()) // if closing is present without opening
                    return false;
                    
                if(s.top() == x[index])
                {
                    index++;
                    s.pop();
                }
                else
                    return false;
            }
        }
        if(s.empty())
            return true;
        else
            return false;
    }


17. Convert a sentence into its equivalent mobile numeric keypad sequence

//easy

18.  Minimum number of bracket reversals needed to make an expression balanced

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

int countRev (string s)
{
    // your code here
    int open = 0, close = 0;
    int len = s.length();
    int result = 0;
    
    if(len % 2 == 1) //check if odd length
        return -1;
    
    for(int i = 0; i< len; i++)
    {
        if(s[i] == '{')
        {
            open++;
            if(open > (len-i-1)) //check if open greater than remaining brackets
            {
                open -= 2;
                result++;
            }
        }
        else
        {
            close++;
            if(close> open)
            {
                open++;
                close--;
                result++;
            }
            else{
                close--;
                open--;
            }
        }
        
    }
    if(open == 0)
        return result;
    else
        return -1;



19. Minimum number of flips to make binary string alternative:

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.

 we are supposed to get alternate string, there are only 2 possibilities, alternate string 
 starting with 0 and alternate string starting with 1. We will try both cases and choose the 
 string which will require minimum number of flips as our final answer. 

int getFlipWithStartingCharcter(string str,
                                char expected)
{
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        //  if current character is not expected,
        // increase flip count
        if (str[i] != expected)
            flipCount++;
 
        //  flip expected character each time
        expected = flip(expected);
    }
    return flipCount;
}


20 Longest Common Prefix

//Easy

21. Find the longest common subsequence between two strings:

//Easy dynamic programming

22. Second most repeated string in a sentence:

//Easy

string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> mp;
        for(int i = 0; i< n; i++)
        {
            mp[arr[i]]++;
        }
        int first = -1;
        int second = -1;
        
        for(auto s: mp)
        {
            if(s.second >= first)
            {
                second = first;
                first = s.second;
            }
            else{
                if(s.second >= second)
                    second = s.second;
            }
        }
        
        for(auto s: mp)
        {
            if(s.second == second)
                return s.first;
        }
        return "";
        
    }


23. Convert Roman Numerals to Integer Number


Algorithm to convert Roman Numerals to Integer Number:  



Split the Roman Numeral string into Roman Symbols (character).
Convert each symbol of Roman Numerals into the value it represents.
Take symbol one by one from starting from index 0: 
If current value of symbol is greater than or equal to the value of next symbol, 
then add this value to the running total.
else subtract this value by adding the value of next symbol to the running total.

    int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}


24. Program to generate all possible valid IP addresses from given string


int is_valid(string ip)
{
    // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        }
        else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
 
    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++) {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3
            || stoi(ips[i]) < 0
            || stoi(ips[i]) > 255)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) == 0)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
            return 0;
    }
    return 1;
}
 
// Function converts string to IP address
void convert(string ip)
{
    int l = ip.length();
 
    // Check for string size
    if (l > 12 || l < 4) {
        cout << "Not Valid IP Address";
    }
 
    string check = ip;
    vector<string> ans;
 
    // Generating different combinations.
    for (int i = 1; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1; k < l; k++) {
                check = check.substr(0, k) + "."
                        + check.substr(k);
                check
                    = check.substr(0, j) + "."
                      + check.substr(j);
                check
                    = check.substr(0, i) + "."
                      + check.substr(i);
 
                // cout<< check <<endl;
                // Check for the validity of combination
                if (is_valid(check)) {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}
 
// Driver code
int main()
{
    string A = "25525511135";
    string B = "25505011535";
 
    convert(A);
    convert(B);
 
    return 0;
}

25. Rearrange characters in a string such that no two adjacent are same

Another approach is to fill all the even positions of the result string first, 
with the highest frequency character. If there are still some even positions remaining, 
fill them first. Once even positions are done, then fill the odd positions. This way, 
we can ensure that no two adjacent characters are the same. 

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


26. Isomorphic Strings

Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for 
every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

//easy check if one charector type is associated with same only one type charactor from both strings

 bool areIsomorphic(string str1, string str2)
    {
        char* ar = new char[26];
        for(int i = 0; i< 26; i++)
            ar[i] = ' ';
            
        char* ar2 = new char[26];
        for(int i = 0; i< 26; i++)
            ar2[i] = ' ';
        
        if(str1.length() == 0 || str2.length() == 0)
            return false;
        if(str1.length() != str2.length())
            return false;
        for(int i = 0; i< str1.length() && i < str2.length(); i++)
        {
            if(ar[str1[i] - 'a'] != ' ' && ar[str1[i] - 'a'] != str2[i])
            {
                    return false;
            }
            ar[str1[i] - 'a'] = str2[i];
            
            if(ar2[str2[i] - 'a'] != ' ' && ar2[str2[i] - 'a'] != str1[i])
            {
                    return false;
            }
            ar2[str2[i] - 'a'] = str1[i];
        }      
        return true;
        // Your code here
        
    }



27. Smallest window that contains all characters of string itself

//Practise it hard to implement
//sliding window O(N) otherwise O(n2)

Algorithm : 
Maintain an array (visited) of maximum possible characters (256 characters) and as soon as we find any in the string, mark that index in the array (this is to count all distinct characters in the string).
Take two pointers start and end which will mark the start and end of window.
Take a counter=0 which will be used to count distinct characters in the window.
Now start reading the characters of the given string and if we come across a character which has not been visited yet increment the counter by 1.
If the counter is equal to total number of distinct characters, Try to shrink the window.
For shrinking the window -: 
If the frequency of character at start pointer is greater than 1 increment the pointer as it is redundant.
Now compare the length of present window with the minimum window length.


string findSubString(string str)
{
    int n = str.length();
 
    // if string is empty or having one char
    if (n <= 1)
        return str;
 
    // Count all distinct characters.
    int dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
 
    // Now follow the algorithm discussed in below
    // post. We basically maintain a window of characters
    // that contains all characters of given string.
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    int count = 0;
    int curr_count[MAX_CHARS] = { 0 };
    for (int j = 0; j < n; j++) {
        // Count occurrence of characters of string
        curr_count[str[j]]++;
 
        // If any distinct character matched,
        // then increment count
        if (curr_count[str[j]] == 1)
            count++;
 
        // if all the characters are matched
        if (count == dist_count) {
            // Try to minimize the window i.e., check if
            // any character is occurring more no. of times
            // than its occurrence in pattern, if yes
            // then remove it from starting and also remove
            // the useless characters.
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }
 
            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}


28. Print Anagrams Together

Given an array of strings, return all groups of strings that are anagrams. 
The groups must be created in order of their appearance in the original array. 
Look at the sample case for clarification.

N = 3
words[] = {no,on,is}
Output: 
no on
is

string rootWord(string st) //gives rootword eg "acb" will be converted into "abc"
    {
        string s = "";
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            for(int i = 0; i< st.length(); i++)
            {
                if(ch == st[i])
                 s += ch;
            }
        }
        return s;
    }
    
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        
        map<string, vector<string>> mp;
        for(auto str: string_list)
        {
            mp[rootWord(str)].push_back(str); //push all the anagrams in one word with their rootWord
        }
        vector<vector<string>> vect;
    
        
        for(auto it= mp.begin(); it != mp.end(); it++)
        {
            vect.push_back(it->second);
        }
        return vect;
    }


29. Robin karp algorithm:



//Polynomial Rolling Hash

//p = prime number usual > string length for less colision

hash("cod") =  (c-'a' +1)*p^0 + (o-'a' +1)*p^1 + (d-'a' +1)*p^2
lli getHash(string key)
{
    lli value = 0;
    lli p = 31;
    lli p_power = 1;
 
    for(char ch : key)
    {
        value = (value + (ch - 'a' + 1)*p_power) % mod;
        p_power = (p_power * p) % mod;
    }
 
    return value;
}


//substring hashing

hash("cod") =  (c-'a' +1)*p^0 + (o-'a' +1)*p^1 + (d-'a' +1)*p^2

hash("od") =  (o-'a' +1)*p^0 + (d-'a' +1)*p^1

hash("cod") =  [(o-'a' +1)*p^1 + (d-'a' +1)*p^2] / p^ 0


dp[0] = c.p^0
dp[1] = c.p^0 + o.p^1
dp[2] = c.p^0 + o.p^1 + d.p^2


hash(substring(L, R)) = (dp[R] - dp[L-1])/ p^L 

void init(string input_string)
{
    lli p = 31;
    lli p_power = 1;
    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);
 
 
    for(int i=1;i<input_string.size();i++)
    {
        char ch = input_string[i];
 
        p_power = (p_power * p) % mod;
        inv[i] = power(p_power , mod - 2);
 
        dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
    }
}
 
lli substringHash(int L , int R)
{
    int result = dp[R];
 
    if(L > 0) result -= dp[L-1];
 
    result = (result * inv[L]) % mod;
 
    return result;
}
 

//Algorithm


int p = 31;
const int N = 1e5+7 , m = 1e9+7;
vector<long long> power(N);

int main()
{
    string s  = "na";
    string t = "apnacollegena";

    int T = t.size(), S = s.size();

    vector<long long> h(T+1, 0);

    power[0] = 1;
    for(int i = 1; i< N; i++)
    {
        power[i] = (power[i-1]*p) %m;
    }
    for(int i = 0; i< T; i++)
    {
        h[i+1] = (h[i] + (t[i] - 'a' +1) *power[i])%m;

    }

    long long h_s  = 0;
    for(int i = 0; i< S; i++){
        h_s = (h_s +(s[i] - 'a' + ))*power[i] %m;
    }

    for(int i = 0; i +S -1< T; i++){
        long long cur_h = (h[i+S] - h[i] +m) %m;

        if(cur_h == (h_s * power[i]) %m){
            cout<<"Found at index" <<i<<endl;
        }
    }
}


30. Kmp algorithm:

//prefix function

vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int> pi(n);

    for(int i = 1; i< n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
        {
            j = pi[j-1]
        }
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
}


int main(){
    string s = "na";
    vector<int> res = presfix_function(s);
    for(auto i: res)
        cout<<i<<" ";

    string t = "apnacollegena";

    int pos = -1;
    int i = 0 , j = 0;
    while( i< t.size()){
        if(t[i] == s[j] ){
            i++;
            j++;
        }
        else{
            if(j != 0)
                j = prefix_function[j-1];
            else
                i++;
        }
        if(j == s.size()){
            pos = i - s.size();
            break;
        }
    }
}

31. minimum-characters-added-front-make-string-palindrome

Efficient approach: We can solve this problem efficiently in O(n) time using lps array of KMP algorithm. 
First we concat string by concatenating given string, a special character and reverse of given string 
then we will get lps array for this concatenated string, recall that each index of lps array represent 
longest proper prefix which is also suffix. We can use this lps array for solving the problem. 


Here we are only interested in the last value of this lps array because it shows us the largest suffix
 of the reversed string that matches the prefix of the original string i.e these many characters already
  satisfy the palindrome property. Finally minimum number of character needed to make the string a palindrome 
  is length of the input string minus last entry of our lps array. Pease see below code for better understanding

