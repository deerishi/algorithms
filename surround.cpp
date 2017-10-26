#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

    vector<vector<int> > dp;
    int m,n;
    vector<vector<bool> >visited;

    bool onEdge(int i,int j){
        if(i==0 or i==m-1 or j==0 or j==n-1){
            return true;
        }
        return false;
    }
    bool isValid(int x,int y){
        if(x>=0 and x<m and y>=0 and y<n ){
            return true;
        }
        return false;
    }
    int dfs(int x,int y,vector<vector<char>>& board){
        int i,j;
        if(dp[x][y]!=0){
            return dp[x][y];
        }
        if(onEdge(x,y)){
            return dp[x][y]=-1;
        }
        visited[x][y]=true;
        int r1=0,r2=0,r3=0,r4=0;
        if(isValid(x+1,y) and board[x+1][y]=='O' and !visited[x+1][y])
            r1=dfs(x+1,y,board);

        if(isValid(x-1,y) and board[x-1][y]=='O' and !visited[x-1][y])
            r2=dfs(x-1,y,board);

        if(isValid(x,y+1) and board[x][y+1]=='O' and !visited[x][y+1])
            r3=dfs(x,y+1,board);

        if(isValid(x,y-1) and board[x][y-1]=='O' and !visited[x][y-1])
            r4=dfs(x,y-1,board);

        if(r1==-1 or r2==-1 or r3==-1 or r4==-1){
            return dp[x][y]=-1;
        }

        return dp[x][y]=1;

    }
    void solve(vector<vector<char>>& board) {
        int i,j,k;
        if(board.size()<3){
            return;
        }
        m=board.size();n=board[0].size();
        for(i=0;i<=m;i++){
            dp.push_back(vector<int>(n+2,0));
            visited.push_back(vector<bool>(n+2,false));
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='O'){
                    cout<<"calling dfs for "<<i<<","<<j<<"\n";
                    int temp=dfs(i,j,board);
                    if(dp[i][j]==1){
                        board[i][j]='X';
                    }
                }
            }
        }
    }

int  main(){
    std::ios::sync_with_stdio(false);
    int i,j,k;
    char ch;
    vector<vector<char> > board;
    m=200;n=200;
    For(i,0,m){
        board.push_back(vector<char>());
        For(j,0,n){
            cin>>ch;
            board[i].push_back(ch);
        }
    }
    solve(board);
    return 0;
}
