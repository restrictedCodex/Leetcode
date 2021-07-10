#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insertAtHead(Node **head_ref, int n)
{
    Node *new_node = new Node();
    new_node->data = n;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int n)
{
    if (prev_node == NULL)
    {
        cout << "the prev node cant be null";
        return;
    }
    Node *new_node = new Node();
    new_node->data = n;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(Node **head_ref, int n)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = n;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}

Node *reverse(Node *head)
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertAtHead(&head, 1);
    insertAtEnd(&head, 6);
    insertAfter(head, 2);
    insertAfter(head, 3);
    insertAfter(head, 4);
    insertAfter(head, 5);
    deleteNode(&head, 1);
    printList(head);
    head = reverse(head);
    printList(head);
    return 0;
}