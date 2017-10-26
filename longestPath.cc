#include "bits/stdc++.h"
using namespace std;


int lengthLongestPath(string input) {
    stack<pair<int,int> >s1;
        int i,j,start=0,count,max1=0,numTs;
        string str=input;
        //cout<<"str is "<<str.length()<<"\n";
        while(start<input.length()){
            numTs=0; //basically its the level of the node
            //cout<<"start is "<<start<<"\n";
            if(!s1.empty()){
                 pair<int,int> top=s1.top();
                 cout<<"Top is "<<top.first<<","<<top.second<<"\n";
            }
            while(start<str.length() and str[start]=='\t'){
                numTs++;start++;
            }
            count=0;
            while(start<str.length() and input[start]!='\n'){
                cout<<"str["<<start<<"] is "<<str[start]<<"\n";
                count++;start++;
            }
            start++;
            cout<<"Pushing now\n";
            if(s1.empty()){
                s1.push(make_pair(count,numTs));
                if(max1<s1.top().first+count){
                    max1=s1.top().first+count;
                    }
            }
            else{
                pair<int,int> top=s1.top();
                if(numTs>top.second){
                    s1.push(make_pair(top.first+count,numTs));

                }
                else{
                    //This means one path is finished, now check for max1
                    if(max1<top.first+count){
                        max1=top.first+count;
                    }
                    while(!s1.empty() and s1.top().second>numTs){
                        s1.pop();
                    }
                }
            }
         }
        if(!s1.empty() and max1<s1.top().first){
            max1=s1.top().first;
        }
        return max1;
    }

int main(){
    std::ios::sync_with_stdio(false);
    int i,j,k;
    string str="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    //cin>>str;
    int res=lengthLongestPath(str);
    cout<<"res is "<<res<<"\n";
    return 0;
}
