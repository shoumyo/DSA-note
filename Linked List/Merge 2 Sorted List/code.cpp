#include <iostream>
using namespace std;

struct Listnode
{
    int val;
    Listnode *next;
    Listnode()
    {
        val = 0;
        next = NULL;
    }
    Listnode(int x)
    {
        val = x;
        next = NULL;
    }
    Listnode(int x, Listnode *ne)
    {
        val = x;
        next = ne;
    }
};

Listnode *mergeTwoLists(Listnode *head1, Listnode *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return head1 == NULL ? head2 : head1;
    }

    if (head1->val <= head2->val)
    {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next=mergeTwoLists(head1,head2->next);
        return head2;
    }
}

// Helper function to print the linked list
void printList(Listnode *head)
{
    Listnode *current = head;
    while (current != NULL)
    {
        cout << current->val;
        if (current->next != NULL)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Listnode *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Listnode *head = new Listnode(arr[0]);
    Listnode *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new Listnode(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    // Test Case 1: Two sorted linked lists
    cout << "Test Case 1: Two sorted linked lists" << endl;
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    
    Listnode *list1 = createList(arr1, 4);
    Listnode *list2 = createList(arr2, 4);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    Listnode *merged1 = mergeTwoLists(list1, list2);
    cout << "Merged List: ";
    printList(merged1);
    cout << endl;

    // Test Case 2: One empty list
    cout << "Test Case 2: One empty list" << endl;
    int arr3[] = {1, 2, 3};
    Listnode *list3 = createList(arr3, 3);
    Listnode *list4 = NULL; // Empty list
    
    cout << "List 3: ";
    printList(list3);
    cout << "List 4: (empty)" << endl;
    
    Listnode *merged2 = mergeTwoLists(list3, list4);
    cout << "Merged List: ";
    printList(merged2);
    cout << endl;

    // Test Case 3: Both empty lists
    cout << "Test Case 3: Both empty lists" << endl;
    Listnode *list5 = NULL;
    Listnode *list6 = NULL;
    
    Listnode *merged3 = mergeTwoLists(list5, list6);
    cout << "Merged List: ";
    printList(merged3);
    cout << endl;

    // Test Case 4: Lists with duplicate values
    cout << "Test Case 4: Lists with duplicate values" << endl;
    int arr7[] = {1, 1, 3, 5};
    int arr8[] = {1, 2, 2, 6};
    
    Listnode *list7 = createList(arr7, 4);
    Listnode *list8 = createList(arr8, 4);
    
    cout << "List 7: ";
    printList(list7);
    cout << "List 8: ";
    printList(list8);
    
    Listnode *merged4 = mergeTwoLists(list7, list8);
    cout << "Merged List: ";
    printList(merged4);
    cout << endl;

    // Test Case 5: Lists of different lengths
    cout << "Test Case 5: Lists of different lengths" << endl;
    int arr9[] = {1, 4, 7};
    int arr10[] = {2, 3, 5, 6, 8, 9};
    
    Listnode *list9 = createList(arr9, 3);
    Listnode *list10 = createList(arr10, 6);
    
    cout << "List 9: ";
    printList(list9);
    cout << "List 10: ";
    printList(list10);
    
    Listnode *merged5 = mergeTwoLists(list9, list10);
    cout << "Merged List: ";
    printList(merged5);

    return 0;
}