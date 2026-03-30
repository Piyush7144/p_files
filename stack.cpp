Questions:

1. Nearest greater to left
2. Nearest greater to right (next greater element)
3. Nearest smaller to left (next smaller element)
4. Nearest smaller to right
5. Stock span problem
6. Maximum area of histogram
7. Max area of rectangle Binary matrix
8. Rain water tapping
9. Implement a min stack
10. Implement stack using heap
11. The celebrity problem
12. Longest valid parenthesis
13. Iterative tower of honai


14. postfix evaluation
15. infix to postfix


Identification:

1. Array
2. O(n2)
3. for(int i = 0; i< n; i++)
   {
   	  for(j...)
   	  {
   	  	o _____ i _____N

   	  	j : o to i  j++
   	  	j : i to o j--
   	  	j : i to n  j++
   	  	j : n to i j--
   	  } // we can use stack here for sure ( loop j is dependent on i)
   } 


1. Next largest element or nearest greater to right

stack empty -> -1
s.top() > ar[i] -> s.top()
s.top() <= ar[i] -> pop while 1. stack empty
							or 2. s.top() > ar[i]


void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
        /* if stack is not empty, then
        pop an element from stack.
        If the popped element is smaller
        than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}

2. Nearest greater to left

void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = 0; i < n ; i++) {
    
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}


3. Nearest smaller to left

void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = 0; i < n ; i++) {
    
        if (!s.empty()) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}

4. Nearest smaller to right

void printNGE(int arr[], int n)
{
    stack<int> s;
    int res[n];
    for (int i = n - 1; i >= 0; i--) {
      
        if (!s.empty()) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}


5. The stock span problem

The span Si of the stock’s price on a given day i is defined as the maximum number 
of consecutive days just before the given day, for which the price of the stock on 
the current day is less than or equal to its price on the given day. 
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, 
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6} 

void calculateSpan(int price[], int n, int S[])
{
    stack<int> st;
    st.push(0);
 
    S[0] = 1;
 
    for (int i = 1; i < n; i++) {
        
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
 
        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
    }
}


6. Largest area in a histogram:

// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array


long long getMaxArea(long long arr[], int n){
    vector<long long> left(n), right(n);
    stack<long long> s; 
    //nsl
    
    for(int i=0;i<n;i++){
        if(s.empty()){
            left[i] = -1;
        }else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }else{
                left[i] = s.top();
            }
        }
        s.push(i);
    }
    
    //empty stack 
    while(!s.empty()){
        s.pop();
    }
    
    //nsr 
    int j = 0 ; 
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            right[j++] = n;
        }else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                right[j++] = n;
            }else{
                right[j++] = s.top();
            }
        }
        s.push(i);
    }
    
    reverse(right.begin(),right.end());
    
    //calculation of width 
    for(int i=0;i<n;i++){
        left[i] = right[i] - left[i] -1;
    }
    
    long long ans = INT_MIN;
    //calculate getMaxArea
    for(int i=0;i<n;i++){
        long x = left[i] * arr[i];
        if(x>ans){
            ans = x;
        }
     }
     return ans;
}



7.  Max area rectangle in a binary matrix:

int MAH(int a[], int n)
{
    int i, ans=0;
    stack<int> s;
    vector<int> nsl(n),nsr(n);
 
    //finding nearest smaller to left
    for(i=0;i<n;i++)
    {
        if(s.empty())
            nsl[i]=-1;
        else if(a[s.top()]<a[i])
            nsl[i]=s.top();
        else
        {
            while (!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                nsl[i]=-1;
            else
                nsl[i]=s.top();
        }
        s.push(i);
    }
 
    while(!s.empty())
        s.pop();
 
    // finding nearest smaller element to right
    for(i=n-1;i>=0;i--)
    {
        if(s.empty())
            nsr[i]=n;
        else if(a[s.top()]<a[i])
            nsr[i]=s.top();
        else
        {
            while (!s.empty() && a[s.top()]>=a[i])
                s.pop();
            if(s.empty())
                nsr[i]=n;
            else
                nsr[i]=s.top();
        }
        s.push(i);
    }
 
    for(i=0;i<n;i++)
        ans=max(ans, a[i]*(nsr[i]-nsl[i]-1));
    return ans;
}
 
int Solution::maximalRectangle(vector<vector<int> > &a)
{
    
        int n,m,i,j;
        n=a.size();
        m=a[0].size();
        int temp[m]={0}, ans=0;
 
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                a[i][j]!=0?(temp[j]+=a[i][j]):(temp[j]=0);
 
            ans=max(ans, MAH(temp,m));
        }
    return ans;
}


8. Tapping rain water problem

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}


8.2 The Celebrity Problem

In a party of N people, only one person is known to everyone. Such a person may be present 
in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like 
“does A know B? “. Find the stranger (celebrity) in the minimum number of questions.

If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
Repeat above two steps till there is only one person.
Ensure the remained person is a celebrity. (What is the need of this step?

stack solution Algorithm: 

Create a stack and push all the id’s in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, 
then B can’t be a celebrity push A in stack.
Assign the remaining element in the stack as the celebrity.
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the 
number of people whom the celebrity knows. if the count of persons who knows the celebrity 
is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.

int findCelebrity(int n)
{
    // Handle trivial
    // case of size = 2
    stack<int> s;
 
    // Celebrity
    int C;
 
    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);
 
    // Extract top 2
  
 
    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
   
   
    // Potential candidate?
    C = s.top();
    s.pop();
 
    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) ||
                 !knows(i, C)) )
            return -1;
    }
 
    return C;
}


Optimal Approach: The idea is to use two pointers, one from start and one from the end. 
Assume the start person is A, and the end person is B. If A knows B, then A must not be 
the celebrity. Else, B must not be the celebrity. At the end of the loop, only one index 
will be left as a celebrity. Go through each person again and check whether this is the celebrity. 
The Two Pointer approach can be used where two pointers can be assigned, one at the start 
and the other at the end, and the elements can be compared and the search space can be reduced.


8.3 minimum element in stack with extra space:

//ref https://www.youtube.com/watch?v=asf9P2Rcopo
//solution

stack<int> s;
stack<int> ss;//auxiliary stack to get min element in O(1)

int getMin()
{
    if(ss.size() == 0)
        return -1;
    return ss.top();
}

void push(int a)
{
    s.push(a);
    if(ss.size() == 0 || ss.top() >= a)
        ss.push(a);
    return;
}

int pop()
{
    if(s.size() == 0)
        return -1;

    int ans = s.top();
    s.pop();
    if(ss.top() == ans)
        ss.pop();

    return ans;
}


8.4 Minimum stack implementation in O(1) space  

eg. 8, 10, 6, 3, 7  

//2 * curr - minimum variable

//pseudo
void push()
{
    if empty stack 
        then push(curr)
    else if (curr>= min)
        then push(curr)
    else
        push(2*curr - min)
        min = curr 
}

void pop()
{
    if emptystack
        then underflow
    else if(curr >= min)
        then pop(curr)
    else
        min = (2*min - curr)
        pop(curr)
}

int getMin()
{
    return min;
}

//code

void push(int x)
{
    if(s.size() == 0)
    {
        s.push(x)
        minEle = x;
    }
    else
    {
        if(x >= minEle)
            s.push(x);
        else if(x < minEle)
        {
            s.push(2*x - minEle)
            minEle = x;

        }
    }
}

int pop()
{
    if(s.size() == 0)
        return -1;
    else
    {
        if(s.top() >= minEle)
            s.pop();
        else if(s.top(() < minEle))
        {
            minEle = 2* mnEle  - s.top();
            s.pop();
        }
    }

}

int top()
{
    if(s.size()== 0)
}
//Apna college:


8.4  Postfix expression evaluation

int postfixEvaluation(string s){

    stack<int> st;

    for(int i = 0; i< s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <='9'){
            st.push(s[i]-'0');
        }

        else{
            int op2 = st.top();
            st.pop();

            int op1= st.top();
            st.pop();

            switch(s[i])
            {
                case '+':
                    st.push(op1+ op2);
                    break;
                case '-':
                    st.push(op1- op2);
                    break;
                case '*':
                    st.push(op1* op2);
                    break;
                case '/':
                    st.push(op1/ op2);
                    break;
                case '^':
                    st.push(pow(op1, op2));
                    break;
            }
        }
    }

    return st.top();
}


8.5 Infix to postfix:

Algo:

1. If operand
    print 
2. if '('
    push to stack  
3. if ')'
    pop from stack and print until '(' if found
4. If operator 

    pop from stack and print until an  
    operator with less precedence is found, don't push ^ (right precedese)

    push 


int preci( char c){

    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string s){

    stack<char> st;
    string res;

    for(int i = 0; i< s.length(); i++){

        if((s[i] >= 'a' && s[i] <= 'z') &&
            s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && preci(st.top())> preci(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

8.6 infix to prefix

Algo: 

reverse(infix)
change brackets
do infixToPostfix()
reverse(ans)


8.7 Balanced parenthesis


bool isValid(string s){
    int n = s.size();

    stack<char> st;

    bool ans = true;

    for(int i = 0; i< n; i++){

        if(s[i] == '{' or s[i] == '(' or s[i] == '[')
        {
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            if(!st.empty() and st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(s[i] == ']'){
            if(!st.empty() and st.top() == '['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(s[i] == '}'){
            if(!st.empty() and st.top() == '{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }

    if(!st.empty()){
        ans = false;
    }

    return ans;

}

int main(){

    string s = "{([])}}";

    if(isValid(s)){
        cout<<"Valid string"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }
}

9. Stack implementation:

#define n 100In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.

class stack{

    int* arr;
    int _top;

public:
    stack(){
        arr = new int[n];
        _top = -1;
    }

    void push(int x ){
        if(_top == n-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }

        _top++;
        arr[_top] = x;
    }

    void pop(){
        if(_top == -1){
            cout<<"No element to pop"<<endl;
            return;
        }
        _top--;
    }

    int top(){
        if(_top == -1){
            cout<<"No elemnt in stack"<<endl;
            return -1;
        }
        return arr[_top];
    }

    bool empty(){
        return _top == -1;
    }
};

int main(){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}

10. Queue implementation:


#define n 20

class queue{
    int* arr;
    int _front;
    int back;

public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;

        if(_front == -1){
        _front++;
        }

    }

    void pop(){
        if(_front == -1 || _front > back) {
            cout<<"No elements in queue"<<endl;
            return;
        }

        front++;
    }

    int front() {
        if(_front == -1 || _front > back) {
            cout<<"No element in queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        if(_front == -1 || _front> back) {
            return true;
        }
        return false;
    }
};


int main()
{
    queue q;
    q.push(1);
    q.push(2);

    cout<<q.front()<<endl;

    q.pop();
    cout<<q.front()<<endl;
}


11. Queue using two stack:

//dequeue is costly

dequeue operation:

1. If both stacks are empty then print error. 
2. If stack2 is empty  
   while stack1 is not empty, push everything from stack1 to stack2
3. Pop the element from stack2 and return it. 
s

class queue{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) { //O(1)
        s1.push(x);
    }
    int pop(){ //O(n)
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    cout<<q.
}


12. Queue using one stack:

enqueue(x):

push x to stack1. 

dequeue(x):

deQueue:

1. If stack1 is empty then print error. 
2. If stack1 has only element then return it.  
3. Recursively pop everything from the stack1, store the  
popped item in a variable res, push the res back to stack1 and return res.  
s
class queue{
    stack<int> s;

public:
    void push(int x){
        s.push(x);
    }

    int pop(){
        if(s.empty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        int x = s.top();
        s.pop();

        if(s.empty())
        {
            return x;
        }

        int item = pop();//recurion
        s.push(x);
        return item;
    }
    bool empty(){
        if(s.empty() )
            return true;
        return false;
    }
}


13. Stack using queue   

Two methods:

1. Making push method costly
2. Making pop mething costly



1. Making push operation costly

class stack{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stack(){
        N= 0;
    }

    void push(int val) {
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};


int main(){
    stack s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;

    return 0;
}


2. Making pop operation costly


class stack(){
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stack() {
        N= 0;
    }

    void pop(){
        if(q1.empty()){
            return;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int size(){
        return N;
    }
};
int main(){

    return 0;
}

3. stack using single queue:

class MyStack {
public:
    
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = que.front(); 
        que.pop(); 
        return x; 
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.size() == 0; 
    }
};
