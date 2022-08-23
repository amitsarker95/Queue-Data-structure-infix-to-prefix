#include<bits/stdc++.h>
using namespace std;
template<typename Tp> class Node
{
public:
    Tp value;
    Node * next;
    Node * prev;
    Node(Tp val)
    {
        this->value = val;
        this->next = NULL;
        this->prev = NULL;


    }

};
template<typename St> class Stack
{
    Node<St> * head;
    Node<St> * top;
    int cnt;
    St chk;
public:
    Stack(){
        head = NULL;
        top = NULL;
        cnt = 0;
    }
      void push(St value){
        Node<St> * newNode = new Node<St>(value);
        if(head == NULL){
            head = newNode;
            top = newNode;
            cnt++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        cnt++;
    };
    St pop()
    {
        Node<St> * delNode;
        delNode = top;
        if(top == head)
        {
            head = NULL;
            top = NULL;
            cnt--;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
            cnt--;
        }
        chk = delNode->value;
        delete delNode;
        return chk;
    }
    int Size(){

        return cnt;
    }
    bool Empty()
    {
       if(head == NULL) return true;
        else return false;
    }
    St Top(){
        St ck;

        if(cnt == 0){
            cout<<"Stack is empty."<<endl;
            return ck;
        }
            return top->value;


    }
     St get_mid_value(){
        int mid = cnt/2+1;
        Node<St>*tmp = head;
        for(int i=1;i<mid;i++) tmp=tmp->next;

    return tmp->value;
    }

};

