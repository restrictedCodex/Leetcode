#include <bits/stdc++.h>
using namespace std;

struct Qnode
{
    int data;
    Qnode *next;
    Qnode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue
{
    Qnode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(int x)
    {
        Qnode *temp = new Qnode(x);
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {
        if (front == NULL)
        {
            return;
        }
        Qnode *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete (temp);
    }
};

int main()
{

    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}