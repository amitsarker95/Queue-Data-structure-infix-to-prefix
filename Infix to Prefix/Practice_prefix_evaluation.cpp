#include<bits/stdc++.h>
#include"template.h"
using namespace std;
int precisionCalc(char s)
{

    if(s == '^')
    {
        return 3;
    }
    else if(s == '*' || s == '/')
    {
        return 2;
    }
    else if (s == '+' || s == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPrefix(string str)
{
    reverse(str.begin(),str.end());
    Stack<char> st;
    string result;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            result+=str[i];
        }
        else if(str[i] == ')')
        {
            st.push(str[i]);
        }
        else if(str[i] == '(')
        {
            while(!st.Empty() && st.Top()!=')')
            {
                result+=st.pop();
            }
            if(!st.Empty())
            {
                st.pop();
            }

        }
        else
        {
            while(!st.Empty()&&precisionCalc(st.Top())>=precisionCalc(str[i]))
            {
                result+=st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.Empty())
    {
        result+=st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}

int prefixEvaluation(string str)
{
    Stack   <char> st;
    string result;
    for(int i = str.length()-1; i>=0; i--)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            st.push(str[i]-'0');
        }
        else
        {

            int a = st.pop();
            int b = st.pop();
            switch(str[i])
            {
            case  '^':
                st.push(pow(a,b));
                break;
            case  '*':
                st.push(a*b);
                break;
            case  '/':
                st.push(a/b);
                break;
            case  '-':
                st.push(a-b);
                break;
            case  '+':
                st.push(a+b);
                break;
            default:
                break;
            }

        }
    }
    return st.Top();
}
int main()
{
    string str;
    cin>>str;
    string convertPrefix;
    convertPrefix = infixToPrefix(str);
    cout<<convertPrefix<<endl;
    int pref ;
    pref = prefixEvaluation(convertPrefix);
    cout<<"prefix : "<<pref<<endl;



    return 0;
}
