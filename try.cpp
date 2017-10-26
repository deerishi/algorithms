#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;

class Solution {
    void reverse(int i,int j,string &s){
        char ch;
        while(i<j){
            ch=s[i];s[i]=s[j];s[j]=ch;
            i++;j--;
        }

    }
public:
    void reverseWords(string &s) {
        int i=0,j,n=s.length();
        j=n-1;
        char ch;
        reverse(0,n-1,s);
        i=0;
        while(i<n){
            while(s[i]==' ')i++;
            j=i;
            while(s[j]!=' ')j++;
            j--;
            reverse(i,j,s);
            i=j+1;
        }
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str="the sky is blue";
    Solution ob1;
    ob1.reverseWords(str);
    cout<<"str is "<<str<<"\n";
    return 0;
}
