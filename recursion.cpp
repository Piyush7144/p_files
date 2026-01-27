Recursion template:

type function( parameters)
{
	if(base condition)
		return x;

		1. Statements

		2. function(parameters)

		3. Statements
	
}


Generalising recursion:

void fun(int n)
{
	if(n > 0)
	{
		1. At calling time(Ascending)

		2. fun(n-1) * 2;

		3. Returning time(Descending)
	}
}


Tail Recursion:

void fun(int n)
{
	if(n> 0)
	{
		printf("%d", n);
		fun(n-1); //If function call is the last statement
	}
}


Head Recursion:

void fun(int n)
{
	if( n> 0)
	{
		fun(n-1);

		cout<<"Hello "<<n<<endl; //All the process are done at returning time
	}
}


Linear Recursion: O(n)

void fun(int n)
{
	if(n > 0)
	{
		cout<<n<<endl;
		fun(n-1);
	}
}


Tree Recursion: O(n2)

void fun(int n)
{
	if(n > 0)
	{
		cout<<n<<endl;

		fun(n-1);
		fun(n-1);
	}
}

1. Sum of n natural numbers

int fun(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		return n + fun(n-1);
	}
}


2. Find power of a number

int pow(int m, int n)
{
	if( n== 0)
		return 1;
	if(n %2 == 0)
		return pow(m*m, n/2);
	else
		return m* pow(m*m, (n-1)/2);
}


3. Fibonaci numbers

int fib(int n)
{
	if(n <= 1)
		return n;

	return fib(n-2) + fib(n-1);

}


3. Factorial

int fact(int n)
{
	if(n <= 1)
		return 1;
	else
		return n* fact(n-1);
}


4. nCr, By pascals triangle.

int comb(int n, int r)
{
	if(r == 0 || n == r)
		return 1;
	else
		return comb(n-1, r-1) + comb(n-1, r);
}


5. Sum of array

// From right to left
int sum(int ar[], int n)
{
	if(n == 0)
		return ar[0];
	else
	{
		return ar[n] + sum(ar, n-1);
	}
}

// From left to right, we are reducing the size of array
int sum2(int ar[], int n)
{
	if(n == 0) // n == 0 if sum2(ar, n-1) else n == 1 for sum2(ar, n);
		return ar[0];
	else
	{
		return ar[0] + sum(ar+1, n-1);
	}
}

6.  Return the first index of element:

int firstIndex(int input[], int size, int x, int currIndex){
    if(size==currIndex){
        return -1;
    }

    if(input[currIndex] == x){
        return currIndex;
    }

    return firstIndex(input,size,x,currIndex+1);
    
}

7. Count no of zeros in number 

int remainder(int n)
{
	if(n == 0)
		return 0;
	if(n % 10 == 0)
		return 1+ remainder(n/10);
	else
		return remainder(n/10);
}



8. Program to replace pi to 3.14 in string

string change(string s1, int index)
{
	if(  index >= (int)s1.length())
		return s1;
	if(s1[index] ==  'p' && s1[index+1] == 'i')
	{
		if(index + 2 <= (int)s1.length() -1)
			s1 = s1.substr(0,index) + "3.14"+ s1.substr(index+2);
		else
			s1 = s1.substr(0,index) + "3.14";
		
		return change(s1, index +2);
		
	}
	else
		return change(s1, index+1);
}

Another one

string replacePi(string s)
{
 
    if (s.length() == 0 || s.length() == 1)
        return s;
 
    // If the 0th and 1st element
    // of s are p and i we have to
    // handle them for rest we have
    // to call recursion it will
    // give the result
    if (s[0] == 'p' && s[1] == 'i') {
 
        // Smalloutput is a variable
        // used to store recursion result
        string smallOutput = replacePi(s.substr(2));
 
        // And we have to add the recursion
        // result with the first part we
        // handeled and return the answer
        return "3.14" + smallOutput;
    }
    else {
        // If 1st & 2nd element aren't "p" & "i", then keep
        // 1st index as it is & call recursion for rest of
        // the string.
        return s[0] + replacePi(s.substr(1));
    }
}


9.  Remove all accurence of character in string

string remove(string s,char ch)
{
	if((int)s.length() == 0)
	 return s;
	if(s[0] == ch)
	{
		return remove(s.substr(1), ch);
	}
	else
		return s[0] + remove(s.substr(1), ch);
}


10. atoi representation

nt myAtoiRecursive(string str, int n) //here n = str.length(), n== 1 and str[n-1]
									  // will be n == 0 and str[n] for str.length()
{
    // Base case (Only one digit)
    if (n == 1)
        return str[0] - '0';
  
    // If more than 1 digits, recur for (n-1), multiplu result with 10
    // and add last digit
    return (10 * myAtoiRecursive(str, n - 1) + str[n-1] - '0');
}



11. Recursive program to insert a star between pair of identical characters

//First approch
string insert(string s)
{
	if((int)s.length() == 0 || (int)s.length() == 1)
		return s;
	
	string st = "";
	st+= s[0];
	st+= "*";
	st+= s[1];
	
	if(s[0] ==  s[1] && (int)s.length() == 2)
		return st;
		
	else if(s[0] == s[1])
		return st + insert(s.substr(2));
	else
		return s[0] + insert(s.substr(1));
		
}


//Second approch
string pairStar(string& input, string& output,
              int i = 0)
{
    // Append current character
    output = output + input[i];
 
    // If we reached last character
    if (i == input.length() - 1)
        return output;
 
    // If next character is same,
    // append '*'
    if (input[i] == input[i + 1])
        output = output + '*';      
 
    pairStar(input, output, i+1);
}



12. Tower of hanoi

1.First move (n-1) disks from source to helper using destination
2. Move nth disk to the distination rod
3. Move (n-1) disks from helper to destination using source (as helper)

void toh(int n, char source, char aux, char destination)
{
	if(n == 0)
		return ;
	toh(n-1, source, destination, aux);
	cout<<source<<" to " destination<<endl;
	toh(n-1, aux, source, destination);
}




13. Print Keypad Combinations Code(Important)

#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string output, string options[]){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int n1=num%10;  //last digit
    string s1=options[n1];
    for(int i=0;i<s1.length();i++){
        printKeypad(num/10, s1[i]+output, options);
    }
}

void printKeypad(int num){
    string output="";
    string options[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
                      0   1    2       3      4                                   9
    printKeypad(num, output, options);
    
}



14. Count ways to reach the n’th stair

//For two different kinds of steps
int staircase(int n){

	if(n == 1 || n == 0)//ways to each zeroth and first step
		return 1;
	else if(n == 2)
		return 2;
	else
		return staircase(n-1) + staircase(n-2);
}


Generalised: 

//For k different kinds of steps
//Time complexity O(m^n)

int countWaysUtil(int n, int m)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
     
    int res = 0;
    for(int i = 1; i <= m && i <= n; i++)
    {
       res += countWaysUtil(n - i, m);
    }
    return res;
}

Tabulation:

//Time complexity O(m*n)
int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1;
    res[1] = 1;
     
    for(int i = 2; i < n; i++)
    {
       res[i] = 0;
        
       for(int j = 1; j <= m && j <= i; j++)
          res[i] += res[i - j];
    }
    return res[n - 1];
}


15.  Print all subsets of array
//In subsequences order of elements matters
//In many cases we use subsets problem for subsequences also
//If their is repetition then use set during printing.
// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        sub(nums, i+1, temp); //exclude the current element
        temp.push_back(nums[i]); //small work
        sub(nums, i+1, temp); //include the current element
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       
        sub(nums, 0, temp); 
        return ans;
    }
}


Iterative method:

//Time Complexity: O(n2^n)
class gfg
{
     
public:
void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
    for(j = 0; j < set_size; j++)
    {
        /* Check if jth bit in the counter is set
            If set then print jth element from set */
        if(counter & (1 << j))
            cout << set[j];
    }
    cout << endl;
    }
}
};



16. Print all Possible Decodings of a given Digit Sequence

void printAllPossibleCodes(string input, string output){
    //Base Case
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    
    char c1=input[0]-'0'+'a'-1;
    int b=stoi(input.substr(0,2));
    char c2=b-1+'a';
    printAllPossibleCodes(input.substr(1), output+c1);
    if( b>=10 && b<=26){
        printAllPossibleCodes(input.substr(2), output+c2);    
    }
    
        
}

void printAllPossibleCodes(string input) {
    string output="";
    printAllPossibleCodes(input, output);
    
}

int main(){
    string s="1123";
    printAllPossibleCodes(s);
    return 0;
}


17.  Print all permutations of String//Without duplicates


void printPermutations(string s,string output){
    if(s==""){ //base case
        cout<<output<<endl;
        return;
    }
    
    for(int i=0;i<s.length();i++){
        printPermutations(s.substr(0,i)+s.substr(i+1), output+s[i]);
        
    }
    
}

int main(){
    string s="cba";
    string output="";
    printPermutations(s, output);
    return 0;
}


18. Generate Gray code  

vector<string> generateGray(int n)
{
    // Base case
    if (n <= 0)
        return {"0"};
 
    if (n == 1)
    {
      return {"0","1"};
    }
 
    //Recursive case
    vector<string> recAns=
          generateGray(n-1);
    vector<string> mainAns;
     
    // Append 0 to the first half
    for(int i=0;i<recAns.size();i++)
    {
      string s=recAns[i];
      mainAns.push_back("0"+s);
    }
     
     // Append 1 to the second half
    for(int i=recAns.size()-1;i>=0;i--)
    {
       string s=recAns[i];
       mainAns.push_back("1"+s);
    }
    return mainAns;
}
 
// Function to generate the
// Gray code of N bits
void generateGrayarr(int n)
{
    vector<string> arr;
    arr=generateGray(n);
    // print contents of arr
    for (int i = 0 ; i < arr.size();
         i++ )
        cout << arr[i] << endl;
}

19. permutations with spaces:

ABCD
ABC D
AB CD
AB C D
A BCD
A BC D
A B CD
A B C D

void printPatternUtil(const char str[],
                      char buff[], int i,
                            int j, int n)
{
    if (i == n)
    {
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }
 
    // Either put the character
    buff[j] = str[i];
    printPatternUtil(str, buff, i + 1, j + 1, n);
 
    // Or put a space followed by next character
    buff[j] = ' ';
    buff[j + 1] = str[i];
 
    printPatternUtil(str, buff, i + 1, j + 2, n);
}


20. Generate all Balanced Parentheses
    
void _printParenthesis(int pos, int n, 
                       int open, int close)
{
    static char str[MAX_SIZE];    
       
    if (close == n)
    {
        cout << str << endl;
        return;
    }
    else
    {
        if (open > close)
        {
            str[pos] = '}';
            _printParenthesis(pos + 1, n, open,
                            close + 1);
        }
           
        if (open < n)
        {
            str[pos] = '{';
            _printParenthesis(pos + 1, n, 
                             open + 1, close);
        }
  

21. Josephus Problem | Game of Death in a circle

Josephus( list , start , k){
   if list.size = 1
       return list[0]
   start = (start + k) % list.size
   list.remove( start )
   return Josephus( list, start, k)
}


void Josh(vector<int> person, int k, int index)
{
    // Base case , when only one person is left
    if (person.size() == 1) {
        cout << person[0] << endl;
        return;
    }
 
    // find the index of first person which will die
    index = ((index + k) % person.size());
 
    // remove the first person which is going to be killed
    person.erase(person.begin() + index);
 
    // recursive call for n-1 persons
    Josh(person, k, index);
}
 
int main()
{
    int n = 14; // specific n and k  values for original
                // josephus problem
    int k = 2;
    k--; // (k-1)th person will be killed
    int index
        = 0; // The index where the person which will die
 
    vector<int> person;
    // fill the person vector
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }
 
    Josh(person, k, index);
}


22. Sort an array using recursion(no loop, insersion sort)


void sort(vector<int>& v)
{
    if(v.size() ==1 )
        return ;
    int last = v[v.size()-1];
    v.pop_back();

    sort(v);

    insert(v,last);
}

void insert (vector<int>& v, int last)
{
     if(v.size() == 0 || v[v.size()-1] <= last)
     {
        v.push_back(last);
        return;
     }

     int val = v[v.size() -1];
     v.pop_back();

     insert(v,last);

     v.push_back(val);
}


23. Sort stack using recursion



void sort(stack<int>& s)
{
    if(s.size() ==1 )
        return ;
    int last = s.top();
    s.pop();

    sort(s);

    insert(s,last);
}

void insert (stack<int>& s, int last)
{
     if(s.size() == 0 || s.top() <= last)
     {
        s.push(last);
        return;
     }

     int val = s.top();
     s.pop();

     insert(s,last);

     s.push(val);
}


24.  Delete middle element in stack

void deletMidelElementInStack(Stack<Integer> stk){
        int pos=stk.size()/2 + 1;
        delete(stk,pos);
    }

    void delete(Stack<Integer> stk,int pos){
        if(pos==1){
            stk.pop();
            return;
        }

        int temp=stk.pop();
        pos--;
        delete(stk,pos);

        stk.add(temp);

    }

25. Reverse stack using recursion

void reverse(stack<int>& s)
{
    if(s.size() == 0)
        return;
    int temp = s.top();
        s.pop();

    reverse(s);

    insert(s,temp);
    return;
}

void insert(stack<int>& s, int ele)
{
    if(s.size() == 0)
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();

    insert(s,ele);
    s.push(temp);
    return;
}




26. Pemutations of arrays:

vector<vector<int>> ans;

void permute(vector<int> &a , int idx) {
    if(idx == a.size()) {
        ans.push_back(a);
        return;
    }

    for(int i = idx; i< a.size(); i++) {
        swap(a[i], a[idx]);
        permute(a,idx+1);
        swap(a[i], a[idx]);
    }

    return ;
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &i : a)
        cin>>i;
    permute(a,0);

    for(auto v: ans) {
        for(auto i: v) {
            cout<<i <" ";
        }
        cout<<"\n";
    }
}


26.2 Permuations with letter repeated print distinst

// first: we can use maps to check 

//second:

vector<vector<int>> ans;
void permute(vector<int> &a , int idx) {

    if(idx == a.size()) {
        ans.push_back(a);
        return;
    }

    for(int i = idx; i< a.size(); i++) {
        if( i != idx  && a[i] == a[idx])
            continue;
        swap(a[i], a[idx]);
        permute(a,idx+1);
        swap(a[i], a[idx]);
    }

    return ;
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &i : a)
        cin>>i;

    sort(a.begin(), a.end());//club equals together
    permute(a,0);

    for(auto v: ans) {
        for(auto i: v) {
            cout<<i <" ";
        }
        cout<<"\n";
    }
}


26. Next Permutations:


Algorithm:

i. a[i] < a[i+1]
ii. a[index 2] > a [index 1]
iii. swap(a[index1], a [index2])
iv. reverse(index+1 -> last)


void nextPermutations(vector<int> & nums) {
    int n = nums.size(), k, l;
    for(k = n -2; k >= 0; k--) {
        if(nums[k] < nums[k+1]) {
            break;
        }
    }

    if(k < 0) {
        reverse(nums.begin(), nums.end());

    }
    else
    {
        for(l = n-1; l>k; l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        }
        swap(nums[k] , nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
}