/*  Q.2.3. Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e. any node but the
    first and last node, not necessarily the exact middle) of a singly linked list, given only access to 
    that node.  */

// Author: Nikhil Singh
// Last Modified: 22/06/2022


#include <iostream>
using namespace std;


struct ListNode {
    int data = 0;
    ListNode *next = nullptr;
};


void insertAtHead(ListNode *&head, int data) {

    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}


void deleteNode(ListNode *node) {

    if(node == nullptr || node->next == nullptr) { return; }

    ListNode *current = node->next;
    node->data = current->data;
    node->next = current->next;
    delete current;
}


void displayList(ListNode *head) {

    while(head != nullptr) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null\n";
}


int main(void) {

    ListNode *head = nullptr;

    for(int i = 7; i > 0; i--) { insertAtHead(head, i); }

    cout << "Linked list before deletion\n";
    displayList(head);
    cout << "\nLinked list after deletion\n";
    deleteNode(head->next->next);

    displayList(head);
    return 0;
}

