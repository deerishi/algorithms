#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)

int ans[1001];
void bfs(){
    int i,j,k,cur,n,m,e1,e2,start;
    memset(ans,-1,sizeof(ans));
    cin>>n>>m;
    vector<int> arr[1001];
    For(i,0,m){
            cin>>e1>>e2;
            arr[e1].push_back(e2);arr[e2].push_back(e1);
        }
    cin>>start;
    
    bool visited[1001];
    
    memset(visited,false,sizeof(visited));
    queue<int> queue1;
    
    queue1.push(start);
    queue1.push(-1);
    int counter=0;
    while(!queue1.empty()){
        cur=queue1.front();
        //cout<<"cur is "<<cur<<"\n";
        queue1.pop();
        if(cur==-1) {
            counter++;
            if(!queue1.empty())
            queue1.push(-1);
            continue;
        }
        if(visited[cur]) continue;
        visited[cur]=true;
        ans[cur]=counter*6;
        For(i,0,arr[cur].size()){
            if(!visited[arr[cur][i]]){
                queue1.push(arr[cur][i]);
            }
        }
    }
    
    For(i,1,n+1){
        if(i==start){
            continue;
        } 
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::ios::sync_with_stdio(false);
    int q,i;
    cin>>q;
    while(q--){
    bfs();    
    
    }
    return 0;
}

