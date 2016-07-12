#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
char current[1<<10],ch;

unordered_map<char,int> map1;
class Order
{
    public:
        bool operator()(char a,char b)
        {
            return a>b;
        }
};
priority_queue<char,vector<char>,Order> queue1;
int main()
{
    int i,j,res;
    char str1[1005],str2[1005];
    while(1)
    {
        if(scanf("%s",str1)>0)
        {   
            scanf("%s",str2);
            map1.clear();
            for(i=0;i<strlen(str1);i++)
            {
                if(map1[str1[i]]==0)
                {
                    map1[str1[i]]=1;
                }
                else
                {   
                     map1[str1[i]]++;
                }
            }
            res=0;
            for(i=0;i<strlen(str2);i++)
            {
                if(map1[str2[i]]>0)
                {
                    map1[str2[i]]--;
                    queue1.push(str2[i]);
                }
            }
            while(!queue1.empty())
            {
                putc_unlocked(queue1.top(),stdout);
                queue1.pop();
            }
            blank;
       }
       else
       {
            break;
       }
        
        
    }
    return 0;
}
