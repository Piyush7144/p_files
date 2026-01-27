
Tree 

Theory:

Heigh                               Level
0               1                    1    
            /     \
1          2       3                2
          / \     / \
2        4  NULL NULL NULL          3
        / \
     NULL NULL


siblings: children of same parent
descendents: all the nodes that can be reached from this node and is below it
ancesters: for any node all the nodes along the path fromt that node to root node
degree: no of direct children for node
internal nodes: not a leaf node 
external nodes: leaf node
level: 1 + height
height: we count no of edges in that path 

No of binary trees with n nodes = catalan number

T(n) =  2nCn / (n+1);

With labeled nodes: T(n) * n! (permutations also)

Height vs nodes:

minNode = H + 1;(H = maxHeight)

maxNode = 2^(H+1) -1 (H = minHeight)

For complete binary tree:

minNode = 2H +1;
maxNode = 2^(H+1) -1 

Array Implementation:

node : i 
leftChild : 2*i
rightChild : 2*i +1


Tree creation in c++.

struct Node {
    int data;
    struct Node* left;// or Node* left;
    struct Node* right;// or Node* right;

    Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};


//Another approch
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };
 

// Node* CreateNode(int data)
// {
//     Node* newNode = new Node();
//     if (!newNode) {
//         cout << "Memory error\n";
//         return NULL;
//     }
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

int main()
{
 
    /*create root*/
    struct Node* root = new Node(1);
    /* following is the tree after above statement
 
             1
            / \
          NULL NULL
    */
 
    root->left = new Node(2);
    root->right = new Node(3);
    /* 2 and 3 become left and right children of 1
                    1
                  /    \
                 2       3
               /  \     /  \
            NULL NULL  NULL NULL
    */
 
    root->left->left = new Node(4);
    /* 4 becomes left child of 2
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */
 
    return 0;
}


Taking decision in tree question:
i. Decision at node:
ii. Return type
iii. Base condition
iv. Pass by reference



0. Insert data in tree using level order

Node* InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}


1. level order traversal


First methond using queue:


void printLevelOrder(Node *root)
{
    
    if (root == NULL)  return;
 
    
    queue<Node *> q;
 
    
    q.push(root);
 
    while (!q.empty())
    {
        
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
 
       
        if (node->left != NULL)
            q.push(node->left);
 
       
        if (node->right != NULL)
            q.push(node->right);
    }
}


2. Reverse level order traversal

void reverseLevelOrder(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);
  
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
  
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
  
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
  
    // Now pop all items from stack one by one and print them
    while (!S.empty())
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}



3. Height or maxDepth of Tree

int maxDepth(node* node) 
{ 
    if (node == NULL) 
        return 0;
    else
    { 
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    } 
} 




4.  PreOrder, Inorder and Postorder recursion

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    cout << node->data << " ";
  
    printPreorder(node->left);
 
    printPreorder(node->right);
}



void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
 
    cout << node->data << " ";

    printInorder(node->right);
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    printPostorder(node->left);
 
    printPostorder(node->right);
 
    cout << node->data << " ";
}



4.1 Iterative PreOrder

void iterativePreorder(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
       return; 
  
    // Create an empty stack and push root to it 
    stack<node *> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (!nodeStack.empty()) 
    { 
        // Pop the top item from stack and print it 
        struct node *node = nodeStack.top(); 
        printf ("%d ", node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 


4.2  Iterative Inorder traversal

void inOrder(struct Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || !s.empty()) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
} 



4.3 Iterative postorder traversal

void postOrderIterative(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    // Create two stacks 
    struct Stack* s1 = createStack(MAX_SIZE); 
    struct Stack* s2 = createStack(MAX_SIZE); 
  
    // push root to first stack 
    push(s1, root); 
    struct Node* node; 
  
    // Run while first stack is not empty 
    while (!isEmpty(s1)) { 
        // Pop an item from s1 and push it to s2 
        node = pop(s1); 
        push(s2, node); 
  
        // Push left and right children of removed item to s1 
        if (node->left) 
            push(s1, node->left); 
        if (node->right) 
            push(s1, node->right); 
    } 
  
    // Print all elements of second stack 
    while (!isEmpty(s2)) { 
        node = pop(s2); 
        printf("%d ", node->data); 
    } 
} 



5. Left view PreOrder

void leftViewUtil(struct Node *root,
                int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
      leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}



8. Convert to its mirror

void mirror(struct Node* node) 
{
    if (node == NULL) 
        return; 
    else
    {
        struct Node* temp;
          
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
      
        /* swap the pointers in this node */
        temp     = node->left;
        node->left = node->right;
        node->right = temp;
    }
} 


9. Binary tree is balance or not O(n^2) solution there is also O(n) sol with heigh cal in same fun

bool isBalanced(node* root)
{

    if (root == NULL)
        return true;

    /* Get the height of left and right sub trees */
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;;

    /* If we reach here then 
    tree is not height-balanced */
    return false;
}


O(n) solution:

int height(Node* root, bool& isBalanced)
{
    if(!root)
        return 0;
    int lh = height(root->left, isBalanced);
    int rh = height(root->right, isBalanced);

    if(abs(lh - rh) > 1)
        isBalanced = false;

    return 1+ max(lh+rh);
}



10 Right view

void rightViewUtil(struct Node *root, 
                   int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
  
    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
  
    // Recur for right subtree first, 
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}





12. zig zag traversal //spiral order traversal

void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
        return;
 
    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;
 
    // push the root
    currentlevel.push(root);
 
    // check if stack is empty  
    bool lefttoright = true;
    while (!currentlevel.empty()) {
 
        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();
 
        // if not null
        if (temp) {
 
            // print the data in it
            cout << temp->data << " ";
 
            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}


Dynamic programing on trees:

General Syntax:


int function( inputs)
{
    Base condition:

    Hypothesis:

    Induction:
}


int solve(Node* root, int& res)
{
    //Base condition
    if(root === NULL)
        return 0;

    //hypothesis
    int l = solve(root -> left, res);
    int r = solve(root-> right , res);

    //induction
    int temp = calculates temp answer(eg 1 + max(l+r));

    int ans = max(temp, relation(eg 1+ l+r))

    res = max(res, ans);

    return temp;
}


Diameter of tree:

No of nodes among the longest path in the leafs(leafs are must included)


//& because we don't want to change value of res in every recursion
int solve(Node* root, int& res)
{
    if(root == NULL)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    //when this node is not selected
    int temp = max(l+r) +1;

    //when this node is selected
    int ans = max(temp, 1+l+r);

    res = max(res, ans);

    return temp;
}

int main()
{
    int res = INT_MIN;
    solve(root, res);
    cout<<res<<endl;
}


Maximum path sum from any node to any node:

int solve(Node* root , int& res)
{
    if(root == NULL)
        return 0;
    int l = solve(root -> left, res);
    int r = solve(root -> right, res);

    //root->data for handling negative values:
    int temp = max(max(l+r) + root->data, root->data);
    int ans = max(tem, l+r +root->data);

    res = max(res, ans);

    return ans;
}


Maximum path sum from leaf node to leaf node:

int solve(Node* root, int& res)
{
    if(root == NULL)
        return 0;
    int l = solve(root -> left, res);
    int r = solve(root -> right, res);

    int temp = max(l,r) + root->data;

    //for leaf nodes:
    // if( root->left == NULL and root->right == NULL)
    //     temp = max( temp, root->data);

    int ans = max(temp,l+r+root->data);
    res = max(res, ans);

    return ans;
}



13. Verrtical order traversal:

//O(n) solution:

We can do preorder traversal of the given Binary Tree. While traversing the tree, 
we can recursively calculate HDs. We initially pass the horizontal distance as 0 for 
root. For left subtree, we pass the Horizontal Distance as Horizontal distance of root 
minus 1. For right subtree, we pass the Horizontal Distance as Horizontal Distance of 
root plus 1. For every HD value, we maintain a list of nodes in a hash map. Whenever we 
see a node in traversal, we go to the hash map entry and add the node to the hash map 
using HD as a key in a map.


void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;
 
    // Store current node in map 'm'
    m[hd].push_back(root->key);
 
    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1, m);
 
    // Store nodes in right subtree
    getVerticalOrder(root->right, hd+1, m);
}
 
// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(Node* root)
{
    // Create a map and store vertical order in map using
    // function getVerticalOrder()
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd,m);
 
    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}


13.2 Top view of tree. (same as vertical view just just map will be <int, int> as only one elemlent at that height

void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    // push node and horizontal distance to queue
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
 
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
}

    
13.3 Bottom view of binary tree 

//same as top view just just don't check if that height is present aready
//by doing so we will get the last element of that height


void bottomView(Node *root)
{
    if (root == NULL)
        return;
 
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
 
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;
 
    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q;
 
    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    root->hd = hd;
    q.push(root);  // In STL, push() is used enqueue an item
 
    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();   // In STL, pop() is used dequeue an item
 
        // Extract the horizontal distance value
        // from the dequeued tree node.
        hd = temp->hd;
        m[hd] = temp->data;
 
        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
 
        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
 
    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}


13.4 Boundary Traversal of binary tree

1. Print the left boundary in top-down manner. 
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
    2.1 Print all leaf nodes of left sub-tree from left to right. 
    2.2 Print all leaf nodes of right subtree from left to right. 
3. Print the right boundary in bottom-up manner.
We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.

void printLeaves(struct node* root)
{
    if (root == NULL)
        return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        printf("%d ", root->data);
 
    printLeaves(root->right);
}
 
// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->left) {
 
        // to ensure top down order, print the node
        // before calling itself for left subtree
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to do boundary traversal of a given binary tree
void printBoundary(struct node* root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}

d

13.5  Diagonal Traversal of Binary Tree


Taking decision in tree question:
i. Decision at node:
ii. Return type
iii. Base condition
iv. Pass by reference


//same as top view , just we are passing same distance to right child because they are on the same diagonal

void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
 
    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);
 
    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left,
                      d + 1, diagonalPrint);
 
    // Vertical distance remains
    // same for right child
    diagonalPrintUtil(root->right,
                         d, diagonalPrint);
}
 
// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{
     
    // create a map of vectors
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}


14. Find largest subtree sum:

Approach : Do post order traversal of the binary tree. At every node, find left 
subtree value and right subtree value recursively. The value of subtree rooted at 
current node is equal to sum of current node value, left node subtree sum and right nod


int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
     
    // Subtree sum rooted at current node.
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
 
    // Return current subtree sum to
    // its parent node.
    return currSum;
}



15. Maximum sum of nodes in Binary tree such that no two are adjacent

int sumOfGrandChildren(node* node, map<struct node*, int>& mp)
{
    int sum = 0;
 
    //  call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
               getMaxSumUtil(node->left->right, mp);
 
    //  call for children of right child only if it is not NULL
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) +
               getMaxSumUtil(node->right->right, mp);
 
    return sum;
}
 
//  Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
    if (node == NULL)
        return 0;
 
    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];
 
    //  take current node value and call for all grand children
    int incl = node->data + sumOfGrandChildren(node, mp);
 
    //  don't take current node value and call for all children
    int excl = getMaxSumUtil(node->left, mp) +
               getMaxSumUtil(node->right, mp);
 
    //  choose maximum from both above calls and store that in map
    mp[node] = max(incl, excl);
 
    return mp[node];
}
 
// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
    if (node == NULL)
        return 0;
    map<struct node*, int> mp;
    return getMaxSumUtil(node, mp);
}




16. Check if tree is sum tree: 


//first method O(n2)
int sum(struct node *root)
{
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data +
           sum(root->right);
}
 
// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(struct node* node)
{
    // If node is NULL or it's a leaf
    // node then return true
    if (node == NULL ||
       (node->left == NULL &&
        node->right == NULL))
        return 1;
 
   // Get sum of nodes in left and
   // right subtrees
   int ls = sum(node->left);
   int rs = sum(node->right);
 
   // If the node and both of its
   // children satisfy the property
   // return 1 else 0
    if ((node->data == ls + rs) &&
          isSumTree(node->left) &&
          isSumTree(node->right))
        return 1;
 
   return 0;
}



//method two O(n)


int sumTree(Node* root, bool& flag)
{
    if(root == NULL)
        return 0;

    if(!root->left && !root->right) //leafNode 
        return root->value;

    int lsum= sumTree(root-> left, flag);
    int rsum = sumTree(root-> right, flag);

    if( root->val != lsum + rsum)
        flag = false;

    return root->val + lsum + rsum;
}


17.  Sum of nodes on the longest path from root to leaf node

void sumOfLongRootToLeafPath(Node* root, int sum,
                      int len, int& maxLen, int& maxSum)
{
    // if true, then we have traversed a
    // root to leaf path
    if (!root) {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    // recur for left subtree
    sumOfLongRootToLeafPath(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);
 
    // recur for right subtree
    sumOfLongRootToLeafPath(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}
 
// utility function to find the sum of nodes on
// the longest path from root to leaf node
int sumOfLongRootToLeafPathUtil(Node* root)
{
    // if tree is NULL, then sum is 0
    if (!root)
        return 0;
 
    int maxSum = INT_MIN, maxLen = 0;
 
    // finding the maximum sum 'maxSum' for the
    // maximum length root to leaf path
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
 
    // required maximum sum
    return maxSum;
}


18. Check if a given graph is tree or not

An undirected graph is tree if it has following properties. 
1) There is no cycle. 
2) The graph is connected.
For an undirected graph we can either use BFS or DFS to detect above two properties.
How to detect cycle in an undirected graph? 
We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ 
such that u is already visited and u is not parent of v, then there is a cycle in graph. 
If we don’t find such an adjacent for any vertex, we say that there is no cycle (See Detect 
    cycle in an undirected graph for more details).
How to check for connectivity? 
Since the graph is undirected, we can start BFS or DFS from any vertex and check if all 
vertices are reachable or not. If all vertices are reachable, then graph is connected, otherwise not.


bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for
        // that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current
        // vertex, then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}
 
// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    // Mark all the vertices as not visited and not part of
    // recursion stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // The call to isCyclicUtil serves multiple purposes.
    // It returns true if graph reachable from vertex 0
    // is cyclcic. It also marks all vertices reachable
    // from 0.
    if (isCyclicUtil(0, visited, -1))
             return false;
 
    // If we find a vertex which is not reachable from 0
    // (not marked by isCyclicUtil(), then we return false
    for (int u = 0; u < V; u++)
        if (!visited[u])
           return false;
 
    return true;
}




19. Root to leaf paths in binary tree:


vector<vector<int>> paths(Node* root){
    vector<vector<int>> v;
    vector<int> curr_path;
    pathsUtil(root, v, curr_path);
    return v;
}


void pathsUtil(Node* root, vector<vector<int>>& v, vector<int>& curr_path)
{
    if(root == NULL)
        return;
    curr_path.push_back(root->val);

    if(!root->left && !root->right)
        v.push_back(curr_path);
    pathsUtil(root->left, v, curr_path);
    pathsUtil(root->right, v, curr_path);

    curr_path.pop_back();
}



20. Find Root to leaf path sum.

void findSum(root, curr_sum, sum , &isfound)
{
    if(!root) return;

    curr_sum += root->val;

    if(!root->left && !root->right &&
        curr_sum == sum)
    {
        isfound = true;
    }
    findsum(root->left, curr_sum, sum , isfound);
    findsum(root->left, curr_sum, sum , isfound);
}


21. Root to leaf maximum path sum in binary tree 


void findSum(root, curr_sum , &max)
{
    if(!root) return;

    curr_sum += root->val;

    if(!root->left && !root->right &&
        curr_sum > max)
    {
        max = curr_sum;
    }
    findsum(root->left, curr_sum,  max);
    findsum(root->left, curr_sum, max);
}


22. Root to kth node in binary tree:

void kdistance(Node* root, int k, vector<int> &v)
{
    if(!root)
        return;
    if(k == 0){
        v.push_back(root->val);
        return;
    }
    kdistance(root->left, k-1, v);
    kdistance(root->right, k-1, v);
}


23. K distance nodes from given node in binary tree:

Convert Tree into Graph: Create a hashmap of nodes and their parents. Perform BFS from the target node and add all nodes at distance K to result.
Percolate Distance: Perform DFS from the root and check for the distance of target node distance from each node.


class Solution {
public:
    // Graph is an adjacency list
    map(int, []) Graph
    int[] ans
    
    void buildGraph(TreeNode node, TreeNode parent) {
        if (not node) 
            return
        if (not Graph.count(node.val)) {
            if (parent) {
                Graph[node.val].add(parent.val)
                Graph[parent.val].add(node.val)
            }
            buildGraph(node.left, node)
            buildGraph(node.right, node)
        }
    }
    
    void bfs(TreeNode target, int k) {
        queue q
        // visited map of int : bool
        map <int, bool> visited
        int depth = 0
        if (k == 0) {
            ans.add(target.val)
            return
        }
        q.push(target.val)
        while (not q.empty()) {
            depth = depth + 1
            int q_size = q.size()
            for (int i=0 to i<q_size) {
                int curr_node = q.front()
                visited[curr_node] = true
                q.pop()
                for (int neighbour in Graph[curr_node]) {
                    if (not visited.count(neighbour)) {
                        if (depth == k) 
                            ans.add(neighbour)
                        else 
                            q.push(neighbour)
                    }
                }
            }
            if (depth == k) 
                return
        }
    }
    
    int[] distanceK(TreeNode root, TreeNode target, int K) {
        buildGraph(root, nullptr)
        bfs(target, K)
        return ans
    }
}


24. Check for identical binary trees:

bool identical(Node* root1, Node* root2){
    if(!root1 && !root2) 
        return true;
    if(!root1 || !root2)
        return false;
    if(root1 -> data != root2->data)
        return false;
    return identical(root1->left, root2->left) && 
            identical(root1->right, root2->right)
}


25. Check for subtree in a binary tree:

//do level order traversal and check for subtree with root
void func(Node* root1, Node* root2)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->data == root2->data)
        {
            if(identical(temp, root))
                return true;
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return false;
}

26. check for mirror tree:

bool mirror(Node* root1, Node* root2)
{
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->data != root2->data)
        return false;

    mirror(root1->left, root2->right);
    mirror(root1->right, root2->left);
}

//symmetric tree

bool isymmetric(Node* root)
{
    if(!root) return true;
    return mirror(root->left, root->right);
}



27. Lowerst common ancestor

Node* lca(Node* root, int a, int b)
{
    if(!root)
        return NULL;
    if(root->value == a || root->value == b)
        return root;


    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);

    //check if both nodes are persent in left and right
    if(left && right)
        return root;

    //check if nodes present only in left s
    if(left)
        return left;

    //check if nodes present only in right
    if(right)
        return right;

    //return null if lca not present i.e one of the nodes or both not present
    return NULL;
}


28. Distance between two nodes of a binary tree


Better Solution : 
We first find the LCA of two nodes. Then we find the distance from LCA to two nodes


Node* LCA(Node * root, int n1,int n2)
{
    // Your code here
    if (root == NULL)
       return root;
    if (root->key == n1 || root->key == n2)
       return root;
 
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
           return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}
 
// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(Node *root, int k, int level)
{
    if(root == NULL) return -1;
    if(root->key == k) return level;
 
    int left = findLevel(root->left, k, level+1);
   if (left == -1)
       return findLevel(root->right, k, level+1);
    return left;
}
 
int findDistance(Node* root, int a, int b)
{
    // Your code here
    Node* lca = LCA(root, a , b);
 
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
 
    return d1 + d2;
}


29.  Nodes on same path:

//the lca should be one of the two nodes then it's on the same path

Node* lca(Node* root, int a, int b, bool & flag)
{
    if(!root)
        return NULL;
    if(root->value == a || root->value == b)
        return root;


    Node* left = lca(root->left, a, b);
    Node* right = lca(root->right, a, b);

    //check if both nodes are persent in left and right
    if(left && right)
    {   
        flag = false;
        return root;
    }

    //check if nodes present only in left s
    if(left)
        return left;

    //check if nodes present only in right
    if(right)
        return right;

    //return null if lca not present i.e one of the nodes or both not present
    return NULL;
}




//construction of tree from ordered traversals:
tree can only be constucted if inorder is one of the given orders:
//preorder and postorder combined can't identifiy a unique tree



30. Construct binary tree from preorder and inorder traversal:

P: 1,2,4,5,3,7 (NLR)
I: 4,2,5,1,3,7 (LNR)

//O(n2) solution can be reduced to O(n) using unordered_map for searching
Node* buildtree(vector<int> p, vector<int> in, int & start, int ins, int ine)
{
    if(ine > ins)
    {
        //inorder endiing > insorder start
        return NULL;
    }
    Node* root = new Node(p[start]);
    int mid = search(in, ins, ine, p[start]); //find root in inorder
    start++;

    root->left = buildtree(p,in, start, ins,mid-1);
    root->right = buildtree(p, in, start, mid+1, ine);

    return root;
}



31. Construct binary tree from postorder and inorder traversal:


P: 6, 2, 4, 5, 3,1 (LRN)
I: 6,2,1,4,3,5 (LNR)

Node* buildtree(vector<int> post, vector<int> in, int& curr, int ins, int ine)
{
    if(ine> ins) 
        return NULL;

    Node* root = new Node(post[curr]);
    int mid = search(in, ins, ine, post[curr]);
    curr--;

    root->right = buildtree(post, in, curr, mid+1, ine);
    root->left = buildtree(post, in , curr, ins, mid-1);

    return root;
}


32. Serialization of binary tree:

i. Less memory
ii. Unique property 


//effective serialization is preorder with marker(-1) for empty nodes

eg: {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}
void serialize(Node *root, FILE *fp)
{
    // If current node is NULL, store marker
    if (root == NULL)
    {
        fprintf(fp, "%d ", MARKER);
        return;
    }
 
    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

33. Deserialization of binary tree:


void deSerialize(Node *&root, FILE *fp)
{
    // Read next item from file. If there are no more items or next
    // item is marker, then return
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;
 
    // Else create node with this item and recur for children
    root = newNode(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}


34.  Convert binary tree to inplace double linked list


void treeToLinkedList(Node* root, Node*& head, Node*& tail){

    if(!root) return ;

    treeToLinkedList(root->left, head, tail);

    if(!head ) {
        head = root;
        tail = root;
    }
    else{
        root->left = tail;
        tail->right = root;
        tail = root;
    }

    treeToLinkedList(root->right, head, tail);
}



35. Minimum time to burn tree:

#include<bits/stdc++.h> 

int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(target); 
    map<BinaryTreeNode<int>*,int> vis; 
    vis[target] = 1;
    int maxi = 0; 
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) maxi++; 
    }
    return maxi; 
}
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
                                     map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q; 
    q.push(root); 
    BinaryTreeNode<int>* res; 
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); 
        if(node->data == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp; 
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start); 
    int maxi = findMaxDistance(mpp, target); 
    return maxi; 
}

36. N array tree preorder traversal:

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

