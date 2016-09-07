#include "bits/stdc++.h"
using namespace std;
string str;

int main()
{
    //std::ios::sync_with_stdio(false);
   

        unordered_map<int,int> maps[10];
        maps[1].insert(make_pair(1,1234));
        cout<<maps[1].find(1)->second<<"\n";
       

    
    return 0;
    
}
