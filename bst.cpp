1. BST  Insert

BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
 
        root->left = Insert(root->left, value);
    }
    return root;
}


2. BST Search

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}


3. BST delete node

1 Node to be deleted is the leaf: Simply remove from the tree. 
2) Node to be deleted has only one child: Copy the child to the node and delete the child 
3 Node to be deleted has two children: Find inorder successor of the node. Copy contents of 
the inorder successor to the node and delete the inorder successor. Note that inorder predecessor 
can also be used. 

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

d
4. Minimum and maximum in BST

int minValue(struct node* node) 
{ 
    struct node* current = node; 
      
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
    { 
        current = current->left; 
    } 
    return(current->data); 
} 




5. BST and inorder if array represent inorder of BST

bool isInorder(int arr[], int n)
{
    // Array has one or no element
    if (n == 0 || n == 1)
        return true;
  
    for (int i = 1; i < n; i++)
  
        // Unsorted pair found
        if (arr[i-1] > arr[i])
            return false;
  
    // No unsorted pair found
    return true;
}
  

6. BST kth smallest element

Node* kthSmallest(struct Node* root, int& k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    // search in left subtree
    Node* left = kthSmallest(root->left, k);
 
    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;
 
    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;
 
    // else search in right subtree
    return kthSmallest(root->right, k);
}




7. LCA in BST

node *lca(node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    // If both n1 and n2 are greater than 
    // root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 

8.  Print nodes in soreted order:(inorder)

 void inorder(Node* node) {
    if(node == NULL) {
      return;
    }
    
    inorder(node->left);
    System.out.print(node->data + " ");
    inorder(node->right);
  }


9. Binary tree to binary search tree:

Following is a 3 step solution for converting Binary tree to Binary Search Tree.

1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.

2) Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. 
In the following implementation, Quick Sort is used which takes (n^2) time. This can be done in 
O(nLogn) time using Heap Sort or Merge Sort.

3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step 
takes O(n) time.
3
sf




10. Construct BST from given preorder traversal

Method 1 ( O(n2) time complexity ) 
The first element of preorder traversal is always root. We first construct the root. 
Then we find the index of the first element which is greater than the root. Let the 
index be ‘i’. The values between root and ‘i’ will be part of the left subtree, and 
the values between ‘i+1’ and ‘n-1’ will be part of the right subtree. Divide given 
pre[] at index “i” and recur for left and right sub-trees.

node* constructTreeUtil(int pre[], int* preIndex, int low,
                        int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;
 
    // The first node in preorder traversal is root. So take
    // the node at preIndex from pre[] and make it root, and
    // increment preIndex
    node* root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
 
    // If the current subarry has only one element, no need
    // to recur
    if (low == high)
        return root;
 
    // Search for the first element greater than root
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
 
    // Use the index of element found in preorder to divide
    // preorder array in two parts. Left subtree and right
    // subtree
    root->left = constructTreeUtil(pre, preIndex, *preIndex,
                                   i - 1, size);
    root->right
        = constructTreeUtil(pre, preIndex, i, high, size);
 
    return root;
}
 
// The main function to construct BST from given preorder
// traversal. This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
                             size);
}


11. Check binary tree or bst or not 


method1: correct but not efficent

int isBST(struct node* node)
{
  if (node == NULL)
    return 1;
     
  /* false if the max of the left is > than us */
  if (node->left != NULL && maxValue(node->left) > node->data)
    return 0;
     
  /* false if the min of the right is <= than us */
  if (node->right != NULL && minValue(node->right) < node->data)
    return 0;
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))
    return 0;
     
  /* passing all that, it's a BST */
  return 1;
}

Method 2 above runs slowly since it traverses over some parts of the tree many times. 
A better solution looks at each node only once. The trick is to write a utility helper 
function isBSTUtil(struct node* node, int min, int max) that traverses down the tree 
keeping track of the narrowing min and max allowed values as it goes, looking at each 
node only once. The initial values for min and max should be INT_MIN and INT_MAX — they 
narrow from there. 

Note: This method is not applicable if there are duplicate elements with value INT_MIN or INT_MAX.


int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}


12. Inorder predecessor and successor for a given key in BST

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}




13. Normal bst to balanced bst:

1 Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
      aGet the middle of left half and make it left child of the root
          created in step 1.
      bGet the middle of right half and make it right child of the
          root created in step 1.

Node* buildTreeUtil(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}


14.  Merge two bst:

//basically result is inorder of resultend bst:

Method 2 (Merge Inorder Traversals) 
1() Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
4) Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.
Time complexity of this method is O(m+n) which is better than method 1. This method takes O(m+n) time even if the input BSTs are not balanced. 
Following is implementation of this method.


node* mergeTrees(node *root1, node *root2, int m, int n)
{
    // Store inorder traversal of
    // first tree in an array arr1[]
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
 
    // Store inorder traversal of second
    // tree in another array arr2[]
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
 
    // Merge the two sorted array into one
    int *mergedArr = merge(arr1, arr2, m, n);
 
    // Construct a tree from the merged
    // array and return root of the tree
    return sortedArrayToBST (mergedArr, 0, m + n - 1);
}


int *merge(int arr1[], int arr2[], int m, int n)
{
    // mergedArr[] is going to contain result
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
 
    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaller element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
 
    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }
 
    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }
 
    return mergedArr;
}

void storeInorder(node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    storeInorder(node->left, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* now recur on right child */
    storeInorder(node->right, inorder, index_ptr);
}

node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    node *root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);

    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}


15. Count BST nodes that lie in a given range

int getCount(node *root, int low, int high)
{
    // Base case
    if (!root) return 0;
 
    // Special Optional case for improving efficiency
    if (root->data == high && root->data == low)
        return 1;
 
    // If current node is in range, then include it in count and
    // recur for left and right children of it
    if (root->data <= high && root->data >= low)
         return 1 + getCount(root->left, low, high) +
                    getCount(root->right, low, high);
 
    // If current node is smaller than low, then recur for right
    // child
    else if (root->data < low)
         return getCount(root->right, low, high);
 
    // Else recur for left child
    else return getCount(root->left, low, high);
}


16. Find a pair with given sum in a Balanced BST

//using array and two pointers
A Better Solution is to create an auxiliary array and store the Inorder traversal of BST 
in the array. The array will be sorted as Inorder traversal of BST always produces sorted data. 
Once we have the Inorder traversal, we can pair in O(n) time (See this for details). This solution 
works in O(n) time but requires O(n) auxiliary space.  

