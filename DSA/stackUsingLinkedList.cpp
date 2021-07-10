#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed into stack\n";
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    *root = (*root)->next;
    int pooped = temp->data;
    free(temp);

    return pooped;
}

int peek(StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    StackNode *root = NULL;

    isEmpty(root);

    return 0;
}