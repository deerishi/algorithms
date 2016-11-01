//Leetcode decode string
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
void printq(deque<char> d)
{
    for(auto it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" , ";
    }
    cout<<"\n";
}
string decodeString(string s) {
    
    int i,j,k,num;
    string str2;
    deque<char> queue1;
    stack<int> number;
    stack<char> chars;
    For(i,0,s.length())
    {
        //printq(queue1);
        if(s[i]!=']')
        {
            queue1.push_back(s[i]);
        }
        else
        {
            //we pop untill we get the opening bracket
            while(!queue1.empty() and queue1.back()!='[')
            {
                chars.push(queue1.back());
                queue1.pop_back();
                if(queue1.back()=='[')
                {
                    //cout<<"hi\n";
                    queue1.pop_back();
                    break;
                }
            }
            //cout<<"hi2\n";
            //NOw make the srings
            str2.clear();
            while(!chars.empty())
            {
                str2=str2+chars.top();
                chars.pop();
            }
            while(!queue1.empty() and isdigit(queue1.back()))
            {
                number.push(queue1.back()-'0');
                queue1.pop_back();
            }
            num=0;
            while(!number.empty())
            {
                num=num*10+number.top();
                number.pop();
            }
            //Now we have the string and now we need to push it num times in to the queue1
            For(j,0,num)
            {
                For(k,0,str2.length())
                {
                    queue1.push_back(str2[k]);
                }
            }
        }
    }
    str2.clear();
    while(!queue1.empty())
    {
        str2=str2+queue1.front();
        queue1.pop_front();
    }
    return str2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i;
    string str;
    cin>>str;
    cout<<"the result is "<<decodeString(str)<<"\n";
    return 0;
}
