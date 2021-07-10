#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
};

void insertAtHead(Node** head_ref, int n){
    Node* new_node = new Node();
    new_node->data = n;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int n){
    if(prev_node == NULL){
        cout<< " prev node cannot be null";
        return;
    }
    Node* new_node = new Node();
    new_node->data = n;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev  = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<< node->data <<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<< last->data <<" ";
        last = last->prev;
    }
}


void insertAtLast(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
 
    Node* last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
    new_node->prev = last;
    return;
}

int main(){
    Node* head = NULL;
 
    insertAtLast(&head, 6);
    insertAtLast(&head, 7);
    insertAtLast(&head, 1);
    insertAtLast(&head, 4);
    insertAfter(head->next, 8);
 
    cout << "Created DLL is: ";
    printList(head);
    return 0;
}