Representation:

struct Node
{
  int data;
  Node *next;
};


1. Inserting a node:

i. At the front of the linked list

void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}


ii. After a given node. 

void insertAfter(Node* prev_node, int new_data) 
{
   
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    { 
        cout << "the given previous node cannot be NULL"; 
        return; 
    }

    Node* new_node = new Node();

    new_node->data = new_data; 

    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
}

iii. At the end. 

void append(Node** head_ref, int new_data) 
{ 
   
    // 1. allocate node
    Node* new_node = new Node();
   
    // Used in step 5
    Node *last = *head_ref;
   
    // 2. Put in the data
    new_node->data = new_data; 
   
    // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL; 
   
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) //Imp
    { 
        *head_ref = new_node; 
        return; 
    } 
   
    // 5. Else traverse till the last node
    while (last->next != NULL) 
        last = last->next; 
   
    // 6. Change the next of last node
    last->next = new_node; 
    return; 
} 



2. Delete a given node: 

void deleteNode(Node** head_ref, int key)
{
     
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
    else
    {
	    while (temp != NULL && temp->data != key)
	    {
	        prev = temp;
	        temp = temp->next;
	    }
	 
	    // If key was not present in linked list
	    if (temp == NULL)
	        return;
	 
	    // Unlink the node from linked list
	    prev->next = temp->next;
	 
	    // Free memory
	    delete temp;
    }
}


3. Delect loop in linked list

// at some point in loop fast pointer will catch up slow pointer , 
//or it will behind slow pointer by one one, it then catches slow pointer in next step
//Floyd’s Cycle-Finding Algorithm
bool detectLoop(Node* head)
    {
        // your code here
        Node* temp1 = head;
        Node* temp2 = head;
        while(temp1 != NULL && temp2 != NULL && temp2->next != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if(temp1 == temp2)
                return true;
        }
        return false;
    }

//Using hashing

bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}


4. Find first node of loop in a linked list

//First using set
ListNode* detectCycle(ListNode* A)
{
    unordered_set<ListNode*> uset;
 
    ListNode *ptr = A;

    while (ptr != NULL) {

        if (uset.find(ptr) != uset.end())
          return ptr;

        else
            uset.insert(ptr);
         
        ptr = ptr->next;
    }
    return NULL;
}


//second method

1. first find collsion point of slow and fast pointer 
2. Find starting point  
   a. Initialize temp to head 
   b. move temp and slow pointer one step simultaneoulsy till they don't collide
   c.' They collide at start of the loop  


Node* detectLoop(Node* head)
{

    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
 

    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != fast)
        return NULL;
 
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
 
    return slow;
}


4.2 Write a program to Delete loop in a linked list.

void detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
 
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
           
        // this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
          if(slow == fast) {
              while(fast->next != slow) fast = fast->next;
        }
          else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}



5. Move last element to front of a given Linked List

void moveToFront(Node **head_ref) 
{ 
    /* If linked list is empty, or 
    it contains only one node, 
    then nothing needs to be done,
    simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 

    Node *secLast = NULL; 
    Node *last = *head_ref; 
  

    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
  
    /* Set the next of second last as NULL */
    secLast->next = NULL; 
  
    /* Set next of last as head node */
    last->next = *head_ref; 
  
    /* Change the head pointer
    to point to last node now */
    *head_ref = last; 
} 


6. Find the middle element of linked List

 void printMiddle(class Node *head){
        struct Node *slow_ptr = head;
        struct Node *fast_ptr = head;
  
        if (head!=NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            cout << "The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }


7. Check if a linked list is circular linked list 

bool isCircular(struct Node *head)
{
    // An empty linked list is circular
    if (head == NULL)
       return true;
 
    struct Node *node = head->next;
 
    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;
 
    // If loop stopped because of circular
    // condition
    return (node == head);
}


8. Reverse a linked list: 

void reverse()
{
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

//Recursion method
struct Node* head;
void Reverse(struct Node* p)
{
	if(p ->next == NULL)
	{
		head = p;
		return;
	}
	Reverse(p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;

}


9.  Print linked list in forward and backward direction using recursion


void Print(struct Node* p)
{
	if(p == NULL)
	{
		return ;
	}
	printf("%d", p->data);
	Print(p->next)
}

void ReverserPrint(struct Node* p)
{
	if(p == NULL)
		return;
	ReverserPrint(p->next);
	printf("%d ",p->data );
}


10. Reverse a Linked List in group of Given Size. [Very Imp]


Node* reverse(Node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}



11. Remove duplicates from a sorted linked list

void removeDuplicates(Node* head)
{
    Node* current = head;
 
    Node* next_next;
     

    if (current == NULL)
    return;
 
    while (current->next != NULL)
    {
	    /* Compare current node with next node */
	    if (current->data == current->next->data)
	    {
	        /* The sequence of steps is important*/       
	        next_next = current->next->next;
	        free(current->next);
	        current->next = next_next;
	    }
	    else /* This is tricky: only advance if no deletion */
	    {
	        current = current->next;
	    }
    }
}


12. Remove duplicates from and unsorted linked list 

i. Two loop  

void removeDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data) {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

ii. hashing. 

void removeDuplicates(struct Node *start)
{
    // Hash to store seen values
    unordered_set<int> seen;
 
    /* Pick elements one by one */
    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
           prev->next = curr->next;
           delete (curr);
        }
        else
        {
           seen.insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}


13. Add 1 to a number represented as linked list

Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. 
Keep moving to the next node while there is a carry.
Reverse modified linked list and return head.


Node *addOneUtil(Node *head)
{
    // res is head node of the resultant list
    Node* res = head;
    Node *temp, *prev = NULL;
 
    int carry = 1, sum;
 
    while (head != NULL) //while both lists exist
    {

        sum = carry + head->data;
        carry = (sum >= 10)? 1 : 0;
         sum = sum % 10;
         head->data = sum;
 
        // Move head and second pointers to next nodes
        temp = head;
        head = head->next;
    }
 
    // if some carry is still there, add a new node to
    // result list.
    if (carry > 0)
        temp->next = newNode(carry);
 
    // return head of the resultant list
    return res;
}
 
Node* addOne(Node *head)
{
    // Reverse linked list
    head = reverse(head);
 
    // Add one from left to right of reversed
    // list
    head = addOneUtil(head);
 
    // Reverse the modified list
    return reverse(head);
}


14. Add two numbers represented by linked list 

void LinkedList::sum(LinkedList* l2)
{
    reverse();
    l2->reverse();
 
    Node *start1 = head, *start2 = l2->head;
 
    Node* prev = NULL;
    int carry = 0;
 
    // While both lists exist
    while (start1 && start2) {
 
        // Current sum
        int temp = start1->data + start2->data + carry;
 
        // Handle carry
        start1->data = temp % 10;
        carry = temp / 10;
        prev = start1;
 
        // Get to next nodes
        start1 = start1->next;
        start2 = start2->next;
    }
 
    // If there are remaining digits
    // in any one of the lists
    if (start1 || start2) {
 
        if (start2)
            prev->next = start2;
 
        start1 = prev->next;
 
        // While first list has digits remaining
        while (start1) {
            int temp = start1->data + carry;
            start1->data = temp % 10;
            carry = temp / 10;
            prev = start1;
            start1 = start1->next;
        }
    }
 
    // If a new node needs to be
    // created due to carry
    if (carry > 0) {
        prev->next = new Node(carry);
    }
 
    // Reverse the resultant list
    reverse();
}



15. Intersection of two Sorted Linked Lists

 
/*This solution uses the temporary
 dummy to build up the result list */
Node* sortedIntersect(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
 
    /* Once one or the other
    list runs out -- we're done */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);
}



16. Write a function to get the intersection point of two Linked Lists

There are two singly linked lists in a system. By some programming error, the end 
node of one of the linked list got linked to the second list, 
forming an inverted Y shaped list. Write a program to get the point where two linked list merge. 

//Using hashing , we can also use two loops

public static Node MegeNode(Node n1, Node n2)
    {
        // define hashset
        HashSet<Node> hs = new HashSet<Node>();
        while (n1 != null) {
            hs.add(n1);
            n1 = n1.next;
        }
        while (n2 != null) {
            if (hs.contains(n2)) {
                return n2;
            }
            n2 = n2.next;
        }
        return null;
    }


//Best solution:

(Using difference of node counts) 

Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that 
from here onwards both the lists have equal no of nodes
Then we can traverse both the lists in parallel till we come across a common 
node. (Note that getting a common node is done by comparing the address of the nodes

int getIntesectionNode(Node* head1, Node* head2)
{
 
    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
 
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}

int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
 
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
 
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
 
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
 
    return -1;
}



17. Merge Two sorted linked lists:

//same as merge of merge sort 
ListNode* mergeTwoLists(listNode* l1, listNode* l2) {
    ListNode dummy;
    ListNode* last = &dummy;
    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2 -> data) {
            last->next = l1;
            last = l1;
            l1 = l1->next;
        }
        else{
            last->next = l2;
            last = l2;
            l2 = l2->next;
        }
    }
    if(l1 != NULL) {
        last->next = l2;
    }
    if(l2 != NULL) {
        last->next = l2;
    }
    return dummy.next;
}

//Recusion based
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
     
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
     
    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}



18. Merge sort:

void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(Node* source,
                    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}


19. Quick sort on linked list: 

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end,
                       struct Node** newHead,
                       struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
// here the sorting happens exclusive of the end node
struct Node* quickSortRecur(struct Node* head,
                            struct Node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct Node* pivot
        = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct Node** headRef)
{
    (*headRef)
        = quickSortRecur(*headRef, getTail(*headRef));
    return;
}



20. Split a cirucular linked list into two halves:

void splitList(Node *head, Node **head1_ref,
                           Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
     
    if(head == NULL)
        return;
     
    /* If there are odd nodes in the circular list then
       fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head &&
          fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
     
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
         
    /* Set the head pointer of first half */
    *head1_ref = head;
         
    /* Set the head pointer of second half */
    if(head->next != head)
        *head2_ref = slow_ptr->next;
         
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;
         
    /* Make first half circular */
    slow_ptr->next = head;
}


21. Function to check if a singly linked list is palindrome


METHOD 1 (Use a Stack) 

A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from the stack and compare 
data of popped node with the currently visited node.
If all nodes matched, then return true, else false.


METHOD 2 (By reversing the list) 
This method takes O(n) time and O(1) extra space. 
1) Get the middle of the linked list. 
2) Reverse the second half of the linked list. 
3) Check if the first half and second half are identical. 
4) Construct the original linked list by reversing the second half again 
and attaching it back to the first half

bool compareLists(struct Node*, struct Node*);
 
// Function to check if given linked list is
// palindrome or not
bool isPalindrome(struct Node* head)
{
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
     
    // To handle odd size list
    struct Node* midnode = NULL;
     
    // initialize result
    bool res = true;
 
    if (head != NULL && head->next != NULL)
    {
         
        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptrr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
 
            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;
         
        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;
         
        // Reverse the second half
        reverse(&second_half);
         
        // compare
        res = compareLists(head, second_half);
 
        // Construct the original list back
        reverse(&second_half); // Reverse the second half again
 
        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}
 

22. Nth node from the end of a linked list: 

void printNthFromLast(struct Node* head, int n)
{
    int len = 0, i;
    struct Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    if (len < n)
        return;
 
    temp = head;

    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;
}


23. Delete in a circular linked list :

void deleteNode(Node** head, int key)
{
     
    // If linked list is empty
    if (*head == NULL)
        return;
         
    // If the list contains only a single node
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
     
    Node *last=*head,*d;
     
    // If head is to be deleted
    if((*head)->data==key)
    {
         
        // Find the last node of the list
        while(last->next!=*head)
            last=last->next;
             
        // Point last node to the next of head i.e.
        // the second node of the list
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
    }
     
    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
     
    // If node to be deleted was found
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
    }


24. Insert in a circular linked list:

void push(Node** head_ref, int data)
{
    // Create a new node and make head as next
    // of it.
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;
 
    /* If linked list is not NULL then set the
    next of last node */
    if (*head_ref != NULL)
    {
        // Find the node before head and update
        // next of it.
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */
 
    *head_ref = ptr1;
}


25. Reverse a doubly linked list:

void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;
     
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }
     
    /* Before changing the head, check for the cases like empty
        list and list with only one node */
    if(temp != NULL )
        *head_ref = temp->prev;
}

26. Find pairs with given sum in doubly linked list

Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked list whose sum is equal 
to given value x, without using any extra space? 

If current sum of first and second is less than x, then we move 
first in forward direction. If current sum of first and second element is 
greater than x, then we move second in backward direction.
Loop termination conditions are also different from arrays. The loop terminates 
when two pointers cross each other (second->next = first), or they become the same (first == second).


void pairSum(struct Node *head, int x)
{
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    struct Node *first = head;
    struct Node *second = head;
    while (second->next != NULL)
        second = second->next;
 
    // To track if we find a pair or not
    bool found = false;
 
    // The loop terminates when two pointers
    // cross each other (second->next
    // == first), or they become same (first == second)
    while (first != second && second->next != first)
    {
        // pair found
        if ((first->data + second->data) == x)
        {
            found = true;
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;
 
            // move first in forward direction
            first = first->next;
 
            // move second in backward direction
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
 
    // if pair is not present
    if (found == false)
        cout << "No pair found";
}



27. Count triplets in a sorted DLL whose sum is equal to given value “X”.(sorted)


Method 3 Efficient Approach(Use of two pointers): 
Traverse the doubly linked list from left to right. For each current node
 during the traversal, initialize two pointers first = pointer to the node 
 next to the current node and last = pointer to the last node of the list. 
 Now, count pairs in the list from first to last pointer that sum up to value 
 (x – current node’s data) (algorithm described in this post). Add this count 
 to the total_count of triplets. Pointer to the last node can be found only once in the beginning.


int countTriplets(struct Node* head, int x)
{
    // if list is empty
    if (head == NULL)
        return 0;
 
    struct Node* current, *first, *last;
    int count = 0;
 
    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != NULL)
        last = last->next;
 
    // traversing the doubly linked list
    for (current = head; current != NULL; current = current->next) {
 
        // for each current node
        first = current->next;
 
        // count pairs with sum(x - current->data) in the range
        // first to last and add it to the 'count' of triplets
        count += countPairs(first, last, x - current->data);
        //coutPairs same as privous question
    }
 
    // required count of triplets
    return count;
}


28. Sort a k sorted doubly linked list:

Efficient Approach: We can sort the list using the MIN HEAP data structure. 
The approach has been explained in Sort a nearly sorted (or K sorted) array. 
We only have to be careful while traversing the input doubly linked list and 
adjusting the required next and previous links in the final sorted list.

struct Node* sortAKSortedDLL(struct Node* head, int k)
{
    // if list is empty
    if (head == NULL)
        return head;
 
    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    struct Node* newHead = NULL, *last;
 
    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++) {
        // push the node on to 'pq'
        pq.push(head);
 
        // move to the next node
        head = head->next;
    }
 
    // loop till there are elements in 'pq'
    while (!pq.empty()) {
 
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if (newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
 
            // 'last' points to the last node
            // of the result sorted list so far
            last = newHead;
        }
 
        else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
 
        // remove element from 'pq'
        pq.pop();
 
        // if there are more nodes left in the input list
        if (head != NULL) {
            // push the node on to 'pq'
            pq.push(head);
 
            // move to the next node
            head = head->next;
        }
    }
 
    // making 'next' of last node point to NULL
    last->next = NULL;
 
    // new head of the required sorted DLL
    return newHead;
}


29. Rotate DoublyLinked list by N nodes.


void rotate(struct Node** head_ref, int N)
{
    if (N == 0)
        return;
 
    // Let us understand the below code
    // for example N = 2 and
    // list = a <-> b <-> c <-> d <-> e.
    struct Node* current = *head_ref;
 
    // current will either point to Nth
    // or NULL after this loop. Current
    // will point to node 'b' in the
    // above example
    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }
 
    // If current is NULL, N is greater
    // than or equal to count of nodes
    // in linked list. Don't change the
    // list in this case
    if (current == NULL)
        return;
 
    // current points to Nth node. Store
    // it in a variable. NthNode points to
    // node 'b' in the above example
    struct Node* NthNode = current;
 
    // current will point to last node
    // after this loop current will point
    // to node 'e' in the above example
    while (current->next != NULL)
        current = current->next;
 
    // Change next of last node to previous
    // head. Next of 'e' is now changed to
    // node 'a'
    current->next = *head_ref;
 
    // Change prev of Head node to current
    // Prev of 'a' is now changed to node 'e'
    (*head_ref)->prev = current;
 
    // Change head to (N+1)th node
    // head is now changed to node 'c'
    *head_ref = NthNode->next;
 
    // Change prev of New Head node to NULL
    // Because Prev of Head Node in Doubly
    // linked list is NULL
    (*head_ref)->prev = NULL;
 
    // change next of Nth node to NULL
    // next of 'b' is now NULL
    NthNode->next = NULL;
}


30. Rotate a Doubly Linked list in group of Given Size.[Very IMP]


Node* reverseByN(Node* head, int k)
{
    if (!head)
        return NULL;
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    int count = 0;
    while (curr != NULL && count < k) {
        newHead = curr;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k) {
        Node* rest = reverseByN(curr, k);
        head->next = rest;
        if (rest != NULL)
            // it is required for prev link otherwise u wont
            // be backtrack list due to broken links
            rest->prev = head;
    }
    return newHead;
}


31. Sort a linked list of 0s, 1s and 2s

Traverse the list and count the number of 0s, 1s, and 2s. Let the counts be n1, n2, and n3 respectively.
Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1, and finally n3 nodes with 2.

void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = head;
 
    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}


32. Merge k sorted linked lists | Set 2 (Using Min Heap)

Create a min-heap and insert the first element of all the ‘k’ linked lists.
As long as the min-heap is not empty, perform the following steps:
Remove the top element of the min-heap (which is the current minimum among all the 
    elements in the min-heap) and add it to the result list.
If there exists an element (in the same linked list) next to the element popped out 
in previous step, insert it into the min-heap.
Return the head node address of the merged list.

struct Node* mergeKSortedLists(
    struct Node* arr[], int k)
{
    // priority_queue 'pq' implemented
    // as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;
 
    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);
     
      // Handles the case when k = 0
      // or lists have no elements in them   
      if (pq.empty())
        return NULL;
   
      struct Node *dummy = newNode(0);
      struct Node *last = dummy;
   
    // loop till 'pq' is not empty
    while (!pq.empty()) {
 
        // get the top element of 'pq'
        struct Node* curr = pq.top();
        pq.pop();
 
          // add the top element of 'pq'
          // to the resultant merged list
        last->next = curr;
          last = last->next; 
       
          // check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }
 
    // address of head node of the required merged list
    return dummy->next;
}



33. Delete nodes which have a greater value on right side

Method 2 (Use Reverse) 
Thanks to Paras for providing the below algorithm. 
1. Reverse the list. 
2. Traverse the reversed list. Keep max till now. If the next node is less 
than max, then delete the next node, otherwise max = next node. 
3. Reverse the list again to retain the original order. 
Time Complexity: O(n)

void delLesserNodes(struct Node** head_ref)
{
    /* 1) Reverse the linked list */
    reverseList(head_ref);
 
    _delLesserNodes(*head_ref);
 
    reverseList(head_ref);
}

void _delLesserNodes(struct Node* head)
{
    struct Node* current = head;
 
    /* Initialize max */
    struct Node* maxnode = head;
    struct Node* temp;
 
    while (current != NULL &&
           current->next != NULL)
    {
        /* If current is smaller than max,
        then delete current */
        if (current->next->data < maxnode->data)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
 
        /* If current is greater than max,
            then update max and move current */
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}


34.Segregate even and odd nodes in a Linked List 


Method 2 
The idea is to split the linked list into two: one containing all 
even nodes and other containing all odd nodes. And finally, attach the odd 
node linked list after the even node linked list.


void segregateEvenOdd(struct Node **head_ref)
{
    // Starting node of list having
    // even values.
    Node *evenStart = NULL;
     
    // Ending node of even values list.
    Node *evenEnd = NULL;
     
    // Starting node of odd values list.
    Node *oddStart = NULL;
     
    // Ending node of odd values list.
    Node *oddEnd = NULL;
     
    // Node to traverse the list.
    Node *currNode = *head_ref;
     
    while(currNode != NULL){
        int val = currNode -> data;
         
        // If current value is even, add
        // it to even values list.
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }
             
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }
         
        // If current value is odd, add
        // it to odd values list.
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
                     
        // Move head pointer one step in
        // forward direction
        currNode = currNode -> next;   
    }
     
    // If either odd list or even list is empty,
    // no change is required as all elements
    // are either even or odd.
    if(oddStart == NULL || evenStart == NULL){
        return;
    }
     
    // Add odd list after even list.    
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
     
    // Modify head pointer to
    // starting of even list.
    *head_ref = evenStart;
}


Remaining Questions:

1. Flatten a linked list  
2. Clone a linked list with next and random pointer  
3. Find the first non-repeating character from a stream of characters

