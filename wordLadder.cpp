#include "bits/stdc++.h"
using namespace std;

#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)


class Solution {
public:


int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList){
    int i,j,k,counter=0;bool flag;
    unordered_map<string,bool> map1;
    queue<string> queue1;
    queue1.push(beginWord);
    queue1.push("");
    while(!queue1.empty()){
        string top=queue1.front();
        queue1.pop();
        if(top.compare("")==0){
            counter++;
            if(!queue1.empty()){
                queue1.push("");
            }
            continue;
        }
         if(map1.find(top)!=map1.end()){
            continue;
        }
        if(top.compare(endWord)==0){
            return counter;
        }


        map1.insert(make_pair(top,true));
        for(i=0;i<top.length();i++){
           for(char ch='a';ch<='z';ch++){
               string str3=top;
               if(top[i]!=ch){
                   str3[i]=ch;
                   if(wordList.find(str3)!=wordList.end()){
                       queue1.push(str3);
                       wordList.erase(str3);
                   }
               }

          }
        }

    }
    return 0;
}
};

int main(){
    cout<<"hi";
    return 0;
}
