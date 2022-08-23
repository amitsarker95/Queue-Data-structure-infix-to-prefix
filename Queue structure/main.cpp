#include<bits/stdc++.h>
#include"MyQueue.h"
using namespace std;
typedef pair<char,int> mytype;
int main(){
MyQueue<mytype> q;
int n;
cin>>n;
for(int i=0;i<n;i++){
    char a;
    int val;
    cin>>a>>val;
    q.push(make_pair(a,val));
}
mytype x;
x = q.Front();
mytype y;
y = q.Back();
cout<<"Length : "<<q.length()<<endl;
cout<<"Front : "<<x.first<<" | "<<x.second<<endl;
cout<<"Rear : "<<y.first<<" | "<<y.second<<endl;
while(!q.Empty()){
    mytype chk;
    chk = q.pop();
    cout<<chk.first<<" | "<<chk.second<<endl;
}
return 0;
}
