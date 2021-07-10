#include <iostream>
#define MAX_VALUE 65536

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int leftThread;
    int rightThread;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class DTBT
{
    Node *root;

public:
    DTBT()
    {
        root = new Node(MAX_VALUE);
        root->left = root->right = root;
        root->leftThread = 0;
        root->rightThread = 1;
    }

    void Insert(int data)
    {
        Node *newNode = new Node(data);
        if (root->left == root && root->right == root)
        {
            root->left = newNode;
            root->leftThread = 1;
            newNode->left = newNode->right = root;
            newNode->leftThread = newNode->rightThread = 0;
        }
        else
        {
            Node *temp = root;
            while (true)
            {
                while (temp->data > data && temp->leftThread == 1)
                {
                    temp = temp->left;
                }
                if (temp->data > data && temp->leftThread == 0)
                {
                    newNode->left = temp->left;
                    temp->left = newNode;
                    temp->leftThread = 1;
                    newNode->right = temp;
                    newNode->leftThread = newNode->rightThread = 0;
                    return;
                }
                while (temp->data < data && temp->rightThread == 1)
                {
                    temp = temp->right;
                }
                if (temp->data < data && temp->rightThread == 0)
                {
                    newNode->right = temp->right;
                    temp->right = newNode;
                    temp->rightThread = 1;
                    newNode->left = temp;
                    newNode->leftThread = newNode->rightThread = 0;
                    return;
                }
            }
        }
    }

    void inorder()
    {
        Node *temp = root;
        do
        {
            while (temp->leftThread != 0)
            {
                temp = temp->left;
            }
            cout << temp->data << " ";
            while (temp->rightThread == 0)
            {
                temp = temp->right;
                cout << temp->data << " ";
            }
            temp = temp->right;

        } while (temp->right != root);
        cout << temp->data << " ";
    }
};
int main()
{
    DTBT tbt;
    cout << "Threaded BT InOrder\n";
    tbt.Insert(56);
    tbt.Insert(23);
    tbt.Insert(89);
    tbt.Insert(20);
    tbt.Insert(30);
    tbt.Insert(12);
    tbt.inorder();
    cout << "\n";
    return 0;
}
