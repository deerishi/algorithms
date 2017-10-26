


#include "bits/stdc++.h"
#define For(i,start,end) for(i=start;i<end;i++)
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)
int dp[100][100];


class Solution {
  public:
    bool canBeChained(vector<string> &arr){
        unordered_map<char,int> map1;
        vector<int> adj[26];
        vector<int> in(26,0),out(26,0);
        int count=0;
        for(auto s:arr){
            char s1=s[0],s2=s.back();
            if(map1.find(s1)==map1.end()) map1[s1]=count,count++;
            if(map1.find(s2)==map1.end()) map1[s2]=count,count++;
            int n1=map1[s1],n2=map1[s2];
            adj[n1].push_back(n2);
            in[n2]++;out[n1]++;
        }
        int i,j;
        for(i=0;i<26;i++){
            if(in[i]!=out[i]) return false;
        }
        int inDFS=0;
        stack<int> s1;
        vector<bool> visited(26,false);
        s1.push(0);
        while(!s1.empty()){
            int top=s1.top();s1.pop();
            if(visited[top]) continue;
            inDFS++;
            visited[top]=true;
            for(auto neigh:adj[top]){
                if(!visited[neigh])
                s1.push(neigh);
            }
        }
        if(inDFS!=count) return false;
        return true;
    }
};


int main() {
    vector<string> arr{"for", "geek", "rig", "kas"};

    Solution ob1;
    int  res=ob1.canBeChained(arr);
    if(res){
        cout<<"Can be chained\n";
    }else{
        cout<<"Cannot be chained\n";
    }

    return 0;
}
