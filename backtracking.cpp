Backtracking


Template:

bool isSafe(inputs)
{
    //check if it is a valid inputs
}


bool solve (inputs)
{
    1. Base condition or isNextStateAvailable
    return true or append(solution)//for counting

    if( isSafe(inputs))
    {
        1. Add this state(inputs)
        2. Recur for other states
            return true;
        3. Remove this state(inputs)
    }

    return false;
}


1. Rat in the maze

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n)
{
	if(x< n &&  y< n && arr[x][y] == 1)
		return true;
	return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr)
{

	if((x == (n-1)) && (y == (n-1)))
	{
		solArr[x][y] = 1;
		return true;
	}
	if(isSafe(arr,x,y,n))
	{
		solArr[x][y] = 1;
		if(ratinMaze(arr, x+1, y, n, solArr))
		{
			return true;
		}
		if(ratinMaze(arr,x,y+1, n, solArr))
		{
			return true;
		}
		solArr[x][y] = 0;
		return false;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;

	int** arr = new int*[n];
	for(int i = 0; i< n; i++)
	{
		arr[i] = new int[n];
	}


	for(int i = 0; i< n; i++){
		for(int j = 0; j< n; j++){

			cin>>arr[i][j];
		}
	}

	int** solArr = new int*[n];
	for(int i = 0; i<n; i++){
		solArr[i] = new int[n];
		for(int j = 0; j< n; j++)
		{
			solArr[i][j] = 0;
		}
	}

	if(ratinMaze(arr,0,0,n,solArr)){
		for(int i = 0; i< n; i++){
		for(int j = 0; j< n; j++){

			cout<<solArr[i][j];
		}
		}
	}
}







_________________________________________________________________


2. N Queen problem

bool isSafe(int** arr, int x, int y, int n)
{
	//checking upper row
	for(int row = 0; row < x; row++)
	{
		if(arr[row][y] == 1)
			return false;
	}

	int row = x;
	int col = y;
    
    //checking left diaganal
	while(row >= 0 && col >= 0)
	{
		if(arr[row][col] == 1)
			return false;
		row--;
		col--;
	}

	while(row >= 0 && col < n)
	{
		if(arr[row][col] == 1)
			return false;
		row--;
		col++;
	}

	return true;

}


bool nQueen(int** arr, int x, int n) 
{
	if(x >= n)
	{
		return true;
	}

	for(int col = 0; col < n; col++)
	{
		if(isSafe(arr, x, col, n))
		{
			arr[x][col] =1;
			if(nQueen(arr, x+1, n))
				return true;

			arr[x][col] = 0; //backtracking
		}

	}
	return false;
}

int main()
{
	int n;
	cin>>n;

	int** arr = new int*[n];
	for(int i = 0; i< n; i++){
		arr = new int[n];
		for(int j = 0; j< n; j++) {
			arr[i][j] = 0;
		}
	}

	if(nQueen(arr, 0,n )) {
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j< n; j++)
			{
				cout<<arr[i][j]<<" "<<endl;
			}
		}
	}
}





2.2 Printing all solutions of n queen problem:

#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > result;
 
/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int> > board,
            int row, int col)
{
    int i, j;
    int N = board.size();
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

bool solveNQUtil(vector<vector<int> >& board, int col)
{
    /* base case: If all queens are placed
    then return true */
    int N = board.size();
    if (col == N) {
        vector<int> v; //stores only the columns in which queen is present
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        result.push_back(v);
        return true;
    }
 
    /* Consider this column and try placing
    this queen in all rows one by one */
    bool res = false;
    for (int i = 0; i < N; i++) {
        /* Check if queen can be placed on
        board[i][col] */
        if (isSafe(board, i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            // Make result true if any placement
            // is possible
            res = solveNQUtil(board, col + 1) || res;
 
            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    return res;
}
 

 
vector<vector<int> > nQueen(int n)
{
    result.clear();
    vector<vector<int> > board(n, vector<int>(n, 0));
 
    if (solveNQUtil(board, 0) == false) {
        return {};
    }
 
    sort(result.begin(), result.end());
    return result;
}
 
// Driver Code
int main()
{
    int n = 4;
    vector<vector<int> > v = nQueen(n);
 
    for (auto ar : v) {
        cout << "[";
        for (auto it : ar)
            cout << it << " ";
        cout << "]";
    }
 
    return 0;
}

_________________________________________________________________

3. Permutation of string

void permute(char *a, int l, int r) 
{ 
	int i; 
	if (l == r) 
		cout<<a<<endl; 
	else
	{ 
		for (i = l; i <= r; i++) 
		{ 
			swap((a+l), (a+i)); 
			permute(a, l+1, r); 
			swap((a+l), (a+i)); //backtrack 
		} 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	char str[] = "ABC"; 
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
} 



_________________________________________________________________

4. Solve suduko 

#include <bits/stdc++.h>
using namespace std;
 
/
#define UNASSIGNED 0

#define N 9

bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col);

bool isSafe(int grid[N][N], int row,
            int col, int num);

bool SolveSudoku(int grid[N][N])
{
    int row, col;
 
    if (!FindUnassignedLocation(grid, row, col))
        // success!
        return true;
 
    for (int num = 1; num <= 9; num++)
    {
         
        if (isSafe(grid, row, col, num))
        {
             
            grid[row][col] = num;
 
            if (SolveSudoku(grid))
                return true;

            grid[row][col] = UNASSIGNED; // backtracking
        }
    }
 
    return false;
}
 

bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 

bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                                       num)
                return true;
    return false;
}
 

bool isSafe(int grid[N][N], int row,
            int col, int num)
{
    
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
 

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

int main()
{
 
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";
 
    return 0;
}


4.5 Determine if graph can be coloured with at most M colours such
    that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for(int k = 0;k<n;k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) {
            return false; 
        }
    }
    return true; 
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if(node == N) {
        return true; 
    }
    
    for(int i = 1;i<=m;i++) {
        if(isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if(solve(node+1, color, m, N, graph)) return true; 
            color[node] = 0; 
        }
        
    }
    return false; 
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N)
{
    int color[N] = {0};
    if(solve(0,color,m,N,graph)) return true; 
    return false; 
}
_________________________________________________________________












5. Boggle (Find all possible words in a board of characters) 


Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G', 'I', 'Z'},
                       {'U', 'E', 'K'},
                       {'Q', 'S', 'E'}};
      isWord(str): returns true if str is present in dictionary
                   else false.

Output:  Following words of dictionary are present
         GEEKS
         QUIZ



#include <cstring>
#include <iostream>
using namespace std;
  
#define M 3
#define N 3
  
// Let the given dictionary be following
string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dictionary) / sizeof(dictionary[0]);
  
// A given function to check if a given string is present in
// dictionary. The implementation is naive for simplicity. As
// per the question dictionary is given to us.
bool isWord(string& str)
{
    // Linearly search all words
    for (int i = 0; i < n; i++)
        if (str.compare(dictionary[i]) == 0)
            return true;
    return false;
}
  
// A recursive function to print all words present on boggle
void findWordsUtil(char boggle[M][N], bool visited[M][N], int i,
                   int j, string& str)
{
    // Mark current cell as visited and append current character
    // to str
    visited[i][j] = true;
    str = str + boggle[i][j];
  
    // If str is present in dictionary, then print it
    if (isWord(str))
        cout << str << endl;
  
    // Traverse 8 adjacent cells of boggle[i][j]
    for (int row = i - 1; row <= i + 1 && row < M; row++)
        for (int col = j - 1; col <= j + 1 && col < N; col++)
            if (row >= 0 && col >= 0 && !visited[row][col])
                findWordsUtil(boggle, visited, row, col, str);
  
    // Erase current character from string and mark visited
    // of current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}
  
// Prints all words present in dictionary.
void findWords(char boggle[M][N])
{
    // Mark all characters as not visited
    bool visited[M][N] = { { false } };
  
    // Initialize current string
    string str = "";
  
    // Consider every character and look for all words
    // starting with this character
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            findWordsUtil(boggle, visited, i, j, str);
}
  
// Driver program to test above function
int main()
{
    char boggle[M][N] = { { 'G', 'I', 'Z' },
                          { 'U', 'E', 'K' },
                          { 'Q', 'S', 'E' } };
  
    cout << "Following words of dictionary are present\n";
    findWords(boggle);
    return 0;
}




_________________________________________________________________
6. The Knight’s tour problem


Problem Statement:
Given a N*N board with the Knight placed on the first block of 
an empty board. Moving according to the rules of chess knight must 
visit each square exactly once. Print the order of each the cell 
in which they are visited.


Input : 
N = 8
Output:
0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12


#include <bits/stdc++.h>
using namespace std;
 
#define N 8
 
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);
 
/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}
 
/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
 
/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
    int sol[N][N];
 
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
 
    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
    // Since the Knight is initially at the first block
    sol[0][0] = 0;
 
    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);
 
    return 1;
}
 
/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
 
    /* Try all next moves from
    the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
                
               // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
 
// Driver Code
int main()
{
      // Function Call
    solveKT();
    return 0;
}



_________________________________________________________________
7. Print all combinations of balanced parentheses

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
    }
}
 
// Wrapper over _printParenthesis()
void printParenthesis(int n)
{
    if (n > 0)
        _printParenthesis(0, n, 0, 0);
         
    return;
}   