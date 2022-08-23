#include<bits/stdc++.h>
using namespace std;
template<typename N>
class Node
{
public:
    N val;
    Node * next;
    Node(N val)
    {
        this->val = val;
        this->next = NULL;

    }
};
template<typename Q>
class MyQueue
{
public:
    Node<Q> * fast;
    Node<Q> * rear;
    int counter;
    MyQueue()
    {

        this->fast = NULL;
        this->rear = NULL;
        this->counter = 0;
    }

    void push(Q val)
    {
        Node<Q> * newNode = new Node<Q>(val);
        if(fast == NULL)
        {
            fast = newNode;
            rear = newNode;
            counter++;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
        counter++;
    }

    Q pop()
    {
        Q delValue;
        if(rear == NULL) return delValue;
        Node <Q> * delNode;
        delNode = fast;
        fast= fast->next;
        if(fast == NULL)
        {
            rear = NULL;
        }
        delValue = delNode->val;
        delete delNode;
        return delValue;
    }

    Q Front()
    {
        Q val;
        if(!Empty())
        {
            Q frontVal = fast->val;
            return frontVal;
        }
        else
        {
            cout<<"Queue is empty there is no element."<<endl;
            return val;
        }
    }
    Q Back()
    {
        Q backVal = rear->val;
        return backVal;
    }
    bool Empty()
    {

        if(fast == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    int length()
    {

        return counter;
    }


};
