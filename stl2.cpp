// Add element
// remove element
// search element
// replace element
// iterate
// order of stored element
// sorting
// size




1. Vectors:

vector<int> a;                                       // empty vector of ints
vector<int> b (5, 10);                                // five ints with value 10
vector<int> c (b.begin(),b.end());                     // iterating through second
vector<int> d (c);                                   // copy of c

at(): Returns the reference to the element at a particular position (can also be done using ‘[ ]’ operator). Its time complexity is O(1).
back(): Returns the reference to the last element. Its time complexity is O(1).
begin(): Returns an iterator pointing to the first element of the vector. Its time complexity is O(1).
clear(): Deletes all the elements from the vector and assign an empty vector. Its time complexity is O(N) where N is the size of the vector.
empty(): Returns a boolean value, true if the vector is empty and false if the vector is not empty. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last element of the vector. Its time complexity is O(1).
erase(): Deletes a single element or a range of elements. Its time complexity is O(N + M) where N is the number of the elements erased and M is the number of the elements moved.
front(): Returns the reference to the first element. Its time complexity is O(1).
insert(): Inserts new elements into the vector at a particular position. ts time complexity is O(N + M) where N is the number of elements inserted and M is the number of the elements moved .
pop_back(): Removes the last element from the vector. Its time complexity is O(1).
push_back(): Inserts a new element at the end of the vector. Its time complexity is O(1).
resize(): Resizes the vector to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the resized vector.
size(): Returns the number of elements in the vector. Its time complexity is O(1).


void traverse(vector<int> v)
{
    vector <int>::iterator it;
    for(it = v.begin();it != v.end();++it)
        cout << *it <<  ‘ ‘;
    cout << endl;
    for(int i = 0;i < v.size();++i)
        cout << v[i] << ‘ ‘;
    cout << endl;
 }


 int main()
{
    vector <int> v;
    vector <int>::iterator it;
    v.push_back(5);
    while(v.back() > 0)
        v.push_back(v.back() - 1);
    for(it = v.begin(); it != v.end();++it)
        cout << *it << ' ';
    cout << endl;
    for(int i = 0;i < v.size();++i)
        cout << v.at(i) << ' ';
    cout << endl;
    while(!v.empty())
    {
        cout << v.back() << ' ';
        v.pop_back();
    }
    cout << endl;
    return 0;
}

Add an element: v.push_back(x)  O(1)
Remove :  v.erase(v.begin() + i)  O(N+M)
		  v.pop_back(x)  O(1)
Search: if( v[x] = ?)  O(1) 
Replace: v[x] = 34  O(1)
Iterate: vector <int>::iterator it;
    	for(it = v.begin();it != v.end();++it)
        cout << *it <<  ‘ ‘;
    	cout << endl;
    	for(int i = 0;i < v.size();++i)
        cout << v[i] << ‘ ‘;
Stored order: order in which inserted
Sorting: sort(v.begin(), v.end())  O(nlog(n))
		 sort(a.begin(), a.end(), greater<int>()) //for descending order
size: v.size()



2.  Pair:

pair <int, char> p1;                    // default
pair <int, char> p2 (1, ‘a’);            // value inititialization
pair <int, char> p3 (p2);               // copy of p2


p1 = make_pair(2, ‘b’) or {2,'b'}

	pair <int, char> p;
    pair <int, char> p1(2, 'b');
    p = make_pair(1, 'a');
    cout << p.first << ' ' <<  p.second << endl;


3. Sets:

set<int> s1;                               // Empty Set
int a[]= {1, 2, 3, 4, 5, 5};
set<int> s2 (a, a + 6);                    // s2 = {1, 2, 3, 4, 5}
set<int> s3 (s2);                          // Copy of s2
set<int> s4 (s3.begin(), s3.end());         // Set created using iterators

begin(): Returns an iterator to the first element of the set. Its time complexity is O(1).
clear(): Deletes all the elements in the set and the set will be empty. Its time complexity is O(N) where N is the size of the set.
count(): Returns 1 or 0 if the element is in the set or not respectively. Its time complexity is O(logN) where N is the size of the set.
empty(): Returns true if the set is empty and false if the set has at least one element. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last element. Its time complexity is O(1).
erase(): Deletes a particular element or a range of elements from the set. Its time complexity is O(N) where N is the number of element deleted.
find(): Searches for a particular element and returns the iterator pointing to the element if the element is found otherwise it will return the iterator returned by end(). Its time complexity is O(logN) where N is the size of the set.
insert(): insert a new element. Its time complexity is O(logN) where N is the size of the set.
size(): Returns the size of the set or the number of elements in the set. Its time complexity is O(1).


int main()
{
    set <int> s;
    set <int>::iterator it;
    int A[] = {3, 5, 2, 1, 5, 4};
    for(int i = 0;i < 6;++i)
        s.insert(A[i]);
    for(it = s.begin();it != s.end();++it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}


Add an element: s.insert(x) O(log(n))
Remove : s.erase(x) O(log(n))
Search: bool present = s.find(element) != s.end();  O(log(n))
		     s.count(x) ==  1 present, 0 not present  O(log(n))
Iterate: for(it = s.begin();it != s.end();++it)
        cout << *it << ' ';
Order: Stored in sorted order(ascending)
size: s.size() O(1)


//Unordered_set

unordered_set<string> s; // Stored in not perticular order

s.insert("abc"); //log(n)
s.insert("c");

auto it = s.find("abd");

if( it != s.end())
	cout<< (*it);

s.erase("string");
s.erase(it);

for(auto value: s){
	cout<< value <<endl;
}


3. Maps:

map <char ,int > mp;

mp[‘b’]  = 1;

count( ): searches the map for the elements mapped by the given key and returns the number of matches.As map stores each element with unique key, then it will return 1 if match if found otherwise return 0.Its time complexity is O(logN).
clear( ): clears the map, by removing all the elements from the map and leaving it with its size 0.Its time complexity is O(N).
begin( ): returns an iterator(explained above) referring to the first element of map.Its time complexity is O(1).
end( ): returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element.Its time complexity is O(1).
empty( ): checks whether the map is empty or not. It doesn’t modify the map.It returns 1 if the map is empty otherwise returns 0.Its time complexity is O(1).
erase( ): removes a single element or the range of element from the map.
find( ): Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map otherwise it returns an iterator to the theoretical element which follows the last element of map.Its time complexity is O(logN).
insert( ): insert a single element or the range of element in the map.Its time complexity is O(logN), when only element is inserted and O(1) when position is also given.





Add an element: mp[x] = y, or mp.insert({1,2}) here 1 is key and 2 is value O(log(n))
Remove : mp.erase(x) O(log(n))
Search: bool present = mp.find(element) != mp.end();  O(log(n))
		     s.count(x) ==  1 present, 0 not present  O(log(n))
Iterate: map<int, string> ::iterator it;
 	for(it = mp.begin(); it != mp.end(); it++)
 	{
 		cout<< it->first<< " "<<it->second<<endl;
 	}
 	for(auto &pr: mp){
 		cout<<pr.first << " "<< pr.second<<endl;
 	}
Order: Stored in sorted order(ascending)
size: s.size() O(1)


//unordered_maps

unordered_maps<int, string> m; // Order doesn't matter

on average O(1) (collisions)

//we can't insert insert pairs etc in unorderred_map





4. Stack

stack <int> s;


push( ): Insert element at the top of stack. Its time complexity is O(1).
pop( ): removes element from top of stack. Its time complexity is O(1).
top( ): access the top element of stack. Its time complexity is O(1).
empty( ): checks if the stack is empty or not. Its time complexity is O(1).
size( ): returns the size of stack. Its time complexity is O(1).


5. Queue

push( ): inserts an element in queue at one end(rear ). Its time complexity is O(1).
pop( ): deletes an element from another end if queue(front). Its time complexity is O(1).
front( ): access the element on the front end of queue. Its time complexity is O(1).
empty( ): checks if the queue is empty or not. Its time complexity is O(1).
size( ): returns the size of queue. Its time complexity is O(1).



6. Priority Queue:

priority_queue<int> maxpq; //max priority queue
priority_queue<int, vector<int>, greater<int> > minpq  // min priority queue

empty(): Returns true if the priority queue is empty and false if the priority queue has at least one element. Its time complexity is O(1).
pop(): Removes the largest element from the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
push(): Inserts a new element in the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
size(): Returns the number of element in the priority queue. Its time complexity is O(1).
top(): Returns a reference to the largest element in the priority queue. Its time complexity is O(1).



int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}


//sorting:

sort(a, a+n);
//sort(a+2, a+n);

sort(a.begin(), a.end()); // sort vectors

//comparator function

bool myswap(int a, int b )
{
	if(a>  b) return true;
	return false;
}


bool myswappair(pair<int, int> a, pair<int, int> b)
{
	if(a > b) return true;
	return false;
}

sort(a.begin(), a.end(), myswap);


bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}



7. strings:



Tokenizing in c++:

int main()
{
      
    string line = "GeeksForGeeks is a must try";
      
    // Vector of string to save tokens
    vector <string> tokens;
      
    // stringstream class check1
    stringstream check1(line);
      
    string intermediate;
      
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
      
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}


Numbers to string: to_string(val):

int i_val = 20;
 
    // Declaring float
    float f_val = 30.50;
 
    // Conversion of int into string using
    // to_string()
    string stri = to_string(i_val);
 
    // Conversion of float into string using
    // to_string()
    string strf = to_string(f_val);
 
    // Displaying the converted strings
    cout << "The integer in string is : ";
    cout << stri << endl;
    cout << "The float in string is : ";
    cout << strf << endl;

Output:

The integer in string is : 20
The float in string is : 30.500000


Converting Strings to Numbers: stoi(str)

int main()
{
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "31337 geek";
 
    int myint1 = stoi(str1);
    int myint2 = stoi(str2);
    int myint3 = stoi(str3);
 
    cout << "stoi(\"" << str1 << "\") is "
         << myint1 << '\n';
    cout << "stoi(\"" << str2 << "\") is "
         << myint2 << '\n';
    cout << "stoi(\"" << str3 << "\") is "
         << myint3 << '\n';
 
    return 0;
}

Output:

stoi("45") is 45
stoi("3.14159") is 3
stoi("31337 geek") is 31337 


String operator and functions:

getline() :- This function is used to store a stream of characters as entered by the user in the object memory.
			getline(cin, str);

length():-This function finds the length of the string
empty(): Tests whether the string is empty. This function return a Boolean value.
clear(): This function clears all the characters from the string. The string becomes empty (length becomes 0) after this operation.
compare() :- It is used to compare two strings. It returns the difference of second string and first string in integer.

if ( str.compare(str1) == 0 )
        cout << "Strings are equal";
    else 
        cout << "Strings are unequal";
    return 0;


find(): The function returns the index of the first occurrence of sub-string, if the sub-string is not found it returns string::npos(string::pos is static member with value as the highest possible for the size_t data structure)

string str = "geeksforgeeks a computer science";
string str1 = "geeks";

// Find first occurrence of "geeks"
size_t found = str.find(str1);
if (found != string::npos)
    cout << "First occurrence is " << found << endl;

substr(): This function takes two values pos and len as an argument and returns a 
newly constructed string object with its value initialized to a copy of a sub-string of 
this object. Copying of string start from pos and done till pos+len means [pos, pos+len).

string s1 = "Geeks";
string r = s1.substr(1, 3);


How to get sub-string after a character?

string s = "dog:cat";
  
// Find position of ':' using find()
int pos = s.find(":");

// Copy substring after pos
string sub = s.substr(pos + 1);

// prints the result
cout << "String is: " << sub;

// using transform() function and ::toupper in STL
    transform(su.begin(), su.end(), su.begin(), ::toupper);
// using transform() function and ::tolower in STL
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower);


// Append character to string in c++
s.push_back(ch);
or  
s += ch;