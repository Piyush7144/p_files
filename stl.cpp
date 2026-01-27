stl

1. pairs and vectors:

void printVec(vector<int> &v)
{
	for(itn i = 0; i< (int)v.size(); i++)
	{
		cout<<v[i]<<" "<<endl;
	}
	cout<<endl;
}

int main()
{
	pair<int, string> p;
	p = make_pair(2,"abc");
	p = {2, "abc"};

	pair<int, string> p1 = p; //copy
	pair<int, string> &p2 = p; //reference

	cout<<p.first <<" "<<p.second<<endl;

	vector<int> v;
	int n;
	cin>>n;


	for(int i = 0; i< n; i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}

	vector<int> v(10,0); //size 10 value 0
	v.push_back(7);


	v.pop_back();

	vector<int> v2 = v; //copy O(n)



	vector<pair<int, int>> v = {{1,2}, {2, 4}};

	for(int i = 0; i< v.size(); i++)
	{
		cout<<v[i].first <<" "<<v[i].second<<endl;
	}

	cin>>x>>y;

	v.push_back({x,y});// v.push_back(make_pair(x,y));


	int N;
	cin>>N:
	vector<int> v[N];

	for(int i = 0; i< N; i++)
	{
		int n;
		cin>>n;

		for(int j = 0; j< n; j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}

	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cout<<v[i][j];
		}
	}


	vector<vector<int> > v;

	for(int i = 0; i< N; i++)
	{
		int n;
		cin>>n;
		vector<int> temp;
		for(int j =0 ; j< n; j++)
		{
			int x;
			cin>>x;
			temp.push_back(x):
		}
		v.push_back(temp);
	}




	//iterators

	vector<int> v = {1,2,3,4,5};
	vector<int> ::iterator it = v.begin();

	// it++ next iterator, it +1 next location (not good for maps and sets)
	for(it =v.begin(); it != v.end(); ++it)
	{
		cout<<*it<<endl;
	}
 	
 	vector<pair<int, int> > vp = {{1,2}, {2,3}};

 	vector<pair<int, int>> :: iterator it;

 	for(it = vp.begin(); it != vp.end(); it++)
 	{
 		cout<< (*it).first <<" "<< (*it).second<<endl;

 		cout<< (it->first) <<" "<< (it->second) <<endl;
 	}


 	for(int value: v) {   //value based loops
 		// value is copy
 		cout<< value<<" ";
 	}

 	for(int &value: v) { // references
 		value = value +1 
 	}


 	for(auto &value: vp){
 		cout<< value.first <<" " <<value.second<<endl;
 	}

 	for(auto it= v.begin(); it != v.end(); it++)
 		cout<< (*it) <<endl;

 	//maps

 	map<int, string> m;

 	m[1] = "piyush";  O(log(n)) times
 	m[2] = "jay";

 	or

 	m.insert({3, "nothing"});

 	map<int, string> ::iterator it;
 	for(it = m.begin(); it != m.end(); it++)
 	{
 		cout<< it->first<< " "<<it->second<<endl;
 	}

 	//maps stores in sortage order of keys

 	// total time O(nlog(n))
 	for(auto &pr: m){
 		cout<<pr.first << " "<< pr.second<<endl;
 	}

 	m[6]; //by default 6 is insert with value 0 , empty stirng for string

 	auto it = m.find(3); //O(log(n))
 	if(it != m.end()){
 		cout<< it->second<<endl;
 	}
 	else
 		cout<<"Not found"<<endl;


 	auto it = m.find(7);
 	if( it != m.end())
 		m.erase(it);

 	m.clear(); // removes everything from map

 	m["acbd"] = "abcd"; // s.size()* log(n); // depends on keys


 	//unordered_maps

 	unordered_maps<int, string> m; // Order doesn't matter

 	on average O(1) (collisions)

 	//we can't insert insert pairs etc in unorderred_map




 	// sets

 	set<string> s; //stores elements in sorted order , also unique elements
 	s.insert("abc"); //log(n)
 	s.insert("c");

 	auto it = s.find("abd");

 	if( it != s.end())
 		cout<< (*it);


 	s.erase("string");
 	s.erase(it);

 	for(auto it = s.begin(); it != end(); it++)
 		cout<< (*it) <<endl

 	or

 	for(auto value: s){
 		cout<< value <<endl;
 	}


 	//Unordered_set

 	unordered_set<string> s;

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



 	// multiset<string> s;


 	//Sorting

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


 	// upper and lower bound

 	int ar[] = {...};
 	sort(a, a+n);

 	int *ptr = lower_bound(a, a+n, 5);

 	if(ptr == (a+n)){
 		cout<< "Not found"<<endl;
 	}
 	else
 	cout<< (*ptr) <<endl;


 	auto it = upper_bound(a.begin(), a.end(), 5);
 	if(it == a.end())
 	{
 		cout<< "Not found"<<endl;
 	}
 	else
 		cout<<(*it) <<endl;

 	//this things also works in sets and maps
 	for sets

 	auto it = s.lower_bound(number);
    //using method like vector it takes O(n)



 	//stack

 	stack<int> s;
 	s.puch(2);
 	s.push(3);

 	while(!s.empty()){
 		cout<<s.top()<<endl;
 		s.pop();
 	}


 	//queue

 	queue<int> q;
 	q.push(1);
 	q.push(4);

 	while(!q.empty()){
 		cout<<q.front()<<endl;
 		q.pop();
 		
 	}
}