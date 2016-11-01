#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string str;
int n,k;
vector<bool> map1(100005,false);
int findLargestPalindrome()
{
    int i,j;
    char ch;
    int len=str.length();
    for(i=0,j=str.length()-1;i<=j;i++,j--)
    {
        if(str[i]!=str[j]){
            if(k==0){
                return -1;
            }
            (str[i]>str[j])?(str[j]=str[i],map1[j]=true):(str[i]=str[j],map1[i]=true);
            k--;
            
        }
    }
    //This will make it a palindrome. 
    i=0;j=len-1;
    while(k>0 and i<=j){
        if(k>0 and str[i]!='9'){
            if(map1[i]==true or map1[j]==true){
                str[i]='9';str[j]='9';k--;
            }
            else if(k>=2 and str[i]!='9')
            {
                str[i]='9';
                str[j]='9';k-=2;
            }
            else if(i==j and str[i]!='9' and k>0){
                str[i]='9';
                k--;
            }
        }
        i++;j--;
    }
    return 0;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    cin>>str;
    int res=findLargestPalindrome();
    if(res==-1)
    cout<<-1<<"\n";
    else
    cout<<str<<"\n";
    return 0;
}

