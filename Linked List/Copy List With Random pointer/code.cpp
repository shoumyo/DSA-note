#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>

struct Listnode
{
    int val;
    Listnode *next;
    Listnode *random;  // Added random pointer
    Listnode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    Listnode(int x)
    {
        val = x;
        next = NULL;
        random = NULL;
    }
    Listnode(int x, Listnode *ne)
    {
        val = x;
        next = ne;
        random = NULL;
    }
};

// Function to copy a linked list with random pointers
Listnode* copyRandomList(Listnode* head){
    if(head == NULL){
        return NULL;
    }
    
    unordered_map<Listnode*, Listnode*> m;
    Listnode* newHead = new Listnode(head->val);
    Listnode* oldTemp = head->next;
    Listnode* newTemp = newHead;
    m[head] = newHead;

    // First pass: create all nodes and build the mapping
    while(oldTemp != NULL){
        Listnode* copyNode = new Listnode(oldTemp->val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    // Second pass: set up random pointers
    oldTemp = head;
    newTemp = newHead;

    while(oldTemp != NULL){
        if(oldTemp->random != NULL){
            newTemp->random = m[oldTemp->random];
        }
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }
    return newHead;
}

// Helper function to create a linked list with random pointers
Listnode* createListWithRandom(int arr[], int n) {
    if (n == 0) return NULL;
    
    // First create nodes
    Listnode* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = new Listnode(arr[i]);
    }
    
    // Connect next pointers
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    
    return nodes[0];
}

// Helper function to set random pointers for testing
void setRandomPointers(Listnode* head, int randomIndices[], int n) {
    Listnode* nodes[n];
    Listnode* temp = head;
    
    // Store all nodes in array
    for (int i = 0; i < n; i++) {
        nodes[i] = temp;
        temp = temp->next;
    }
    
    // Set random pointers
    temp = head;
    for (int i = 0; i < n; i++) {
        if (randomIndices[i] != -1) {
            temp->random = nodes[randomIndices[i]];
        } else {
            temp->random = NULL;
        }
        temp = temp->next;
    }
}

// Helper function to print list with random pointers
void printListWithRandom(Listnode* head) {
    Listnode* temp = head;
    
    // First pass: print values and next pointers
    cout << "List (next pointers): ";
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
    
    // Second pass: print random pointers
    cout << "Random pointers: ";
    temp = head;
    while (temp != NULL) {
        if (temp->random != NULL) {
            cout << temp->val << "->" << temp->random->val << " ";
        } else {
            cout << temp->val << "->NULL ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to verify if two lists are deep copies
bool verifyDeepCopy(Listnode* original, Listnode* copy) {
    Listnode* temp1 = original;
    Listnode* temp2 = copy;
    
    while (temp1 != NULL && temp2 != NULL) {
        // Check if nodes are different objects
        if (temp1 == temp2) {
            cout << "Error: Same node object detected!" << endl;
            return false;
        }
        
        // Check values
        if (temp1->val != temp2->val) {
            cout << "Error: Value mismatch!" << endl;
            return false;
        }
        
        // Check random pointers
        if (temp1->random == NULL) {
            if (temp2->random != NULL) {
                cout << "Error: Random pointer mismatch (one is NULL)!" << endl;
                return false;
            }
        } else {
            if (temp2->random == NULL) {
                cout << "Error: Random pointer mismatch (one is NULL)!" << endl;
                return false;
            }
            if (temp1->random->val != temp2->random->val) {
                cout << "Error: Random pointer value mismatch!" << endl;
                return false;
            }
            // Check if random pointers point to different objects
            if (temp1->random == temp2->random) {
                cout << "Error: Random pointers point to same object!" << endl;
                return false;
            }
        }
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    // Check if both lists ended at same time
    if (temp1 != NULL || temp2 != NULL) {
        cout << "Error: List length mismatch!" << endl;
        return false;
    }
    
    return true;
}

int main()
{
    cout << "=== Testing copyRandomList Function ===" << endl << endl;
    
    // Test Case 1: Normal case
    cout << "Test Case 1: Normal linked list with random pointers" << endl;
    {
        int arr[] = {1, 2, 3, 4, 5};
        int randomIndices[] = {2, 4, 1, 0, -1};  // -1 means NULL
        
        Listnode* head = createListWithRandom(arr, 5);
        setRandomPointers(head, randomIndices, 5);
        
        cout << "Original list:" << endl;
        printListWithRandom(head);
        
        Listnode* copy = copyRandomList(head);
        
        cout << "\nCopied list:" << endl;
        printListWithRandom(copy);
        
        if (verifyDeepCopy(head, copy)) {
            cout << "\n✓ Deep copy verified successfully!" << endl;
        } else {
            cout << "\n✗ Deep copy verification failed!" << endl;
        }
        
        cout << endl;
    }
    
    // Test Case 2: List with self-pointing random pointers
    cout << "Test Case 2: List with self-pointing random pointers" << endl;
    {
        int arr[] = {10, 20, 30};
        int randomIndices[] = {0, 1, 2};  // Each points to itself
        
        Listnode* head = createListWithRandom(arr, 3);
        setRandomPointers(head, randomIndices, 3);
        
        cout << "Original list:" << endl;
        printListWithRandom(head);
        
        Listnode* copy = copyRandomList(head);
        
        cout << "\nCopied list:" << endl;
        printListWithRandom(copy);
        
        if (verifyDeepCopy(head, copy)) {
            cout << "\n✓ Deep copy verified successfully!" << endl;
        } else {
            cout << "\n✗ Deep copy verification failed!" << endl;
        }
        
        cout << endl;
    }
    
    // Test Case 3: List with circular random pointers
    cout << "Test Case 3: List with circular random pointers" << endl;
    {
        int arr[] = {7, 8, 9};
        int randomIndices[] = {1, 2, 0};  // Circular: 7->8, 8->9, 9->7
        
        Listnode* head = createListWithRandom(arr, 3);
        setRandomPointers(head, randomIndices, 3);
        
        cout << "Original list:" << endl;
        printListWithRandom(head);
        
        Listnode* copy = copyRandomList(head);
        
        cout << "\nCopied list:" << endl;
        printListWithRandom(copy);
        
        if (verifyDeepCopy(head, copy)) {
            cout << "\n✓ Deep copy verified successfully!" << endl;
        } else {
            cout << "\n✗ Deep copy verification failed!" << endl;
        }
        
        cout << endl;
    }
    
    // Test Case 4: Empty list
    cout << "Test Case 4: Empty list" << endl;
    {
        Listnode* head = NULL;
        Listnode* copy = copyRandomList(head);
        
        if (copy == NULL) {
            cout << "✓ Empty list copied correctly (NULL)" << endl;
        } else {
            cout << "✗ Empty list copy failed!" << endl;
        }
        
        cout << endl;
    }
    
    // Test Case 5: Single node list
    cout << "Test Case 5: Single node list" << endl;
    {
        int arr[] = {100};
        int randomIndices[] = {-1};  // NULL
        
        Listnode* head = createListWithRandom(arr, 1);
        setRandomPointers(head, randomIndices, 1);
        
        cout << "Original list:" << endl;
        printListWithRandom(head);
        
        Listnode* copy = copyRandomList(head);
        
        cout << "\nCopied list:" << endl;
        printListWithRandom(copy);
        
        if (verifyDeepCopy(head, copy)) {
            cout << "\n✓ Deep copy verified successfully!" << endl;
        } else {
            cout << "\n✗ Deep copy verification failed!" << endl;
        }
        
        cout << endl;
    }
    
    // Test Case 6: All random pointers are NULL
    cout << "Test Case 6: All random pointers are NULL" << endl;
    {
        int arr[] = {5, 6, 7, 8};
        int randomIndices[] = {-1, -1, -1, -1};  // All NULL
        
        Listnode* head = createListWithRandom(arr, 4);
        setRandomPointers(head, randomIndices, 4);
        
        cout << "Original list:" << endl;
        printListWithRandom(head);
        
        Listnode* copy = copyRandomList(head);
        
        cout << "\nCopied list:" << endl;
        printListWithRandom(copy);
        
        if (verifyDeepCopy(head, copy)) {
            cout << "\n✓ Deep copy verified successfully!" << endl;
        } else {
            cout << "\n✗ Deep copy verification failed!" << endl;
        }
    }

    return 0;
}