/*  Q.2.2. Return Kth to Last: Implement an algorithm to find the kth to last 
    element of a singly linked list. */

// Author: Nikhil Singh
// Last Modified: 20/06/2022


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


void deleteNode(ListNode *&head) {

    ListNode *runner = nullptr;
    while(head != nullptr) {

        runner = head->next;
        delete(head);
        head = runner;
    }
}


void displayList(ListNode *head) {

    while(head != NULL) {

        cout << head->data << "->";
        head = head->next;
    }
    cout << "null\n";
}


ListNode *kThToLastHelper(ListNode *&head, int k, int &idx) {

    if(head == nullptr) { return nullptr; }
  
    ListNode *current = kThToLastHelper(head->next, k, idx);
    idx = idx + 1;
    if(idx == k) { return head; }
    return current;
}


ListNode *kThToLastRecur(ListNode *head, int k) {
        
    int idx = 0;
    return kThToLastHelper(head, k, idx);
}


ListNode *kThToLastIters(ListNode *head, int k) {
    
    if(head == nullptr) return head;
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;
    
    for(int i = 0; i < k; i++) {
        if(ptr1 == nullptr) return nullptr;
        ptr1 = ptr1->next;
    }

    while(ptr1 != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;  
    }
    return ptr2;
}


int main(void) {

    ListNode *head = nullptr;

    for(int i = 8; i > 0; i--) { insertAtHead(head, i); }
    cout << "List: ";
    displayList(head);

    cout << "\nUsing Iterative Approach";
    cout << "\nFifth node from the last is: ";
    ListNode *node5 = kThToLastIters(head, 5);
    if(node5 != nullptr) { cout << node5->data << endl; } 
    else { cout << "null\n"; }

    cout << "\nUsing Recursive Approach";
    cout << "\nFifth node from the last is: ";
    node5 = kThToLastRecur(head, 5);
    if(node5 != nullptr) { cout << node5->data << endl; } 
    else { cout << "null\n"; }

    deleteNode(head);
    return 0;
}
