// Removing duplicates from an unsorted linked list

#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;


struct Node {
    int data = 0;
    Node *next = nullptr;
};


void insertAtHead(Node *&head, int data) {

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}


// Utility:> prints linked list in same order
void displayList(Node *head) {

    while(head) {

        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}


// Utility:> generates pseudo random numbers
static int randomNumbers(const int min, const int max) {

    random_device singleRandNumber;
    mt19937 mt(singleRandNumber());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}


// Method-1:> Using naive algorithm, time complexity = O(2^n)
// space complexity = O(1)
void removeDups1(Node *head) {

    if(head == nullptr || (head && (head->next == nullptr)))  return;

    Node *current = head;

    while(current != nullptr) {

        Node *runner = current;
        while(runner->next != nullptr) {

            if(runner->next->data == current->data) {
                Node *vagueNode = runner->next;
                runner->next = runner->next->next;
                delete vagueNode;
            }
            else runner = runner->next;
        }
        current = current->next;
    }
}


// Method-2:> Using hashtables, time complexity = O(n)
// space complexity = O(n)
void removeDups2(Node *head) {
    
    if(head == nullptr || (head && (head->next == nullptr)))  return;
    
    unordered_map<int, int> mapNode;

    Node *earlier = head;
    Node *current = head->next;

    mapNode[head->data] = 1;
    while(current != nullptr) {

        while(current && mapNode.find(current->data) != mapNode.end()) {
            current = current->next;
        }

        earlier->next = current;
        earlier = current;

        if(current) {
            mapNode[current->data] = 1;
            current = current->next;
        }
    }
}


// Driver function
int main(void) {
    
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    cout << "Testing:> using naive approach" << endl;

    for(int i = 0; i < 10; i++) {
        insertAtHead(head1, randomNumbers(1, 8));
    }

    displayList(head1);
    removeDups1(head1);
    displayList(head1);

    cout << "\nTesting:> using hashtables" << endl;

    for(int i = 0; i < 10; i++) {
        insertAtHead(head2, randomNumbers(1, 5));
    }

    displayList(head2);
    removeDups2(head2);
    displayList(head2);
    return 0;
}
