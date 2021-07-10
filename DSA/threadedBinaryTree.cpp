#include <iostream>
#define MAX_VALUE 65536
using namespace std;
class Node
{ //node declaration
public:
    int k;
    Node *l, *r;
    bool leftTh, rightTh;
};
class ThreadedBinaryTree
{
private:
    Node *root;

public:
    ThreadedBinaryTree()
    { //constructor to initialize the variables
        root = new Node();
        root->r = root->l = root;
        root->leftTh = true;
        root->k = MAX_VALUE;
    }
    void insert(int key)
    {
        Node *p = root;
        for (;;)
        {
            if (p->k < key)
            { //move to right thread
                if (p->rightTh)
                    break;
                p = p->r;
            }
            else if (p->k > key)
            { // move to left thread
                if (p->leftTh)
                    break;
                p = p->l;
            }
            else
            {
                return;
            }
        }
        Node *temp = new Node();
        temp->k = key;
        temp->rightTh = temp->leftTh = true;
        if (p->k < key)
        {
            temp->r = p->r;
            temp->l = p;
            p->r = temp;
            p->rightTh = false;
        }
        else
        {
            temp->r = p;
            temp->l = p->l;
            p->l = temp;
            p->leftTh = false;
        }
    }
    void inorder()
    { //print the tree
        Node *temp = root, *p;
        for (;;)
        {
            p = temp;
            temp = temp->r;
            if (!p->rightTh)
            {
                while (!temp->leftTh)
                {
                    temp = temp->l;
                }
            }
            if (temp == root)
                break;
            cout << temp->k << " ";
        }
        cout << endl;
    }
};
int main()
{
    ThreadedBinaryTree tbt;
    cout << "Threaded Binary Tree InOrder\n";
    tbt.insert(56);
    tbt.insert(23);
    tbt.insert(89);
    tbt.insert(85);
    tbt.insert(20);
    tbt.insert(30);
    tbt.insert(12);
    tbt.inorder();
    cout << "\n";
}