#include "bits/stdc++.h"
using namespace std;
char current[1<<10],ch;
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n1=n1*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n1*sign; 
}
unordered_map<string,int> map1;
unordered_map<int,bool> visited;

void printn(int n) 
{
	char *ptr=current+30;
	*ptr--='\0';
	int flag=1;
	if(n)
	{
		if(n<0) n*=-1,flag=-1;
			
		while(n>0)
		{
			*ptr--=(n%10) +'0';
			n/=10;
		}
		if(flag==-1) *ptr--='-';
	}
	else {*ptr='0';putc_unlocked('0',stdout);return;}
	ptr++;
	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}

void getString(string &s)
{
    s.clear();
    ch=getc_unlocked(stdin);
    //cout<<"in getstring\n";
    while(ch<'-')
    {
        ch=getc_unlocked(stdin);
    }
    while(isalpha(ch) and ch>'-')
    {
        s+=ch;
        ch=getc_unlocked(stdin);
        //cout<<"s is "<<s;
    }
}

vector<pair<int,int> > adjacencyList[10000];
class prioritize{
public:
bool operator()(pair<int,int> a,pair<int,int> b){
return a.second > b.second;
}
};
 //For storing the cities and their current distance

unordered_map<int,int> distances;
int a,s,n,numNeighbours;

int dijkstra(int source,int target)
{
    
    priority_queue<pair<int,int>,vector<pair<int,int> >,prioritize> queue1;
    int i,j,k;
    vector<pair<int,int> >::iterator it;
    for(i=0;i<n;i++)
    {
        distances[i]=INT_MAX;
        visited[i]=false;
    }
    distances[source]=0;
    pair<int,int> current;
    int neighbor,val;
    queue1.push(make_pair(source,distances[source]));
    //check for one more condition that the target has been reached from the source node
    bool targetReached=false;
    while(!queue1.empty() and !targetReached)
    {
        current=queue1.top();
        //cout<<"current is "<<current.first<<" with cost "<<current.second<<"\n";
        queue1.pop();
        if(visited[current.first]==true)
        {
            continue;
        }
        visited[current.first]=true;
        if(current.first==target)
        {
            targetReached=true;
            continue;
        }
        //now we have the minimum unvisited node, so try updating all its neighbors
        for(it=adjacencyList[current.first].begin();it!=adjacencyList[current.first].end();it++)
        {
            neighbor=(*it).first;
            val=(*it).second; //this is the distance from the current node to its neighbour
            //check the condition for the dijkstra distance from the original distance map1
            if(visited[neighbor]==false and current.second + val < distances[neighbor])
            {
                distances[neighbor]=current.second + val;
                queue1.push(make_pair(neighbor,distances[neighbor]));
            }
                        
        }
    }
    //Before that we need to empty the prority queue1
    
    return distances[target];
}

int main()
{
    int i,j,k,r;
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    s=getInt();
    string city,source,target;
    vector<pair<int,int> >:: iterator it2;
    unordered_map<string,int>::iterator it;
    
    while(s--)
    {
        //cout<<"sis is "<<s<<"\n";
        n=getInt();
        //cout<<"enter"<<n;
        for(i=0;i<n;i++)
        {
            getString(city);
            numNeighbours=getInt();
            //cout<<"numNeighbours are "<<numNeighbours<<"\n";
            for(j=0;j<numNeighbours;j++)
            {
                int x=getInt();
                int cost=getInt();
                adjacencyList[i].push_back(make_pair(x-1,cost));
            }
            //cout<<"city is "<<city<<"\n";
            map1[city]=i;
        }
       /* cout<<"the map\n";
        for(it=map1.begin();it!=map1.end();it++)
        {
            cout<<(*it).first<<" : "<<(*it).second<<"\n";
        }
        cout<<"adjacencyList is\n";
        for(i=0;i<n;i++)
        {   
            cout<<"Neighbours of "<<i<<": ";
            for(it2=adjacencyList[i].begin();it2!=adjacencyList[i].end();it2++)
            {
                cout<<(*it2).first<<":"<<(*it2).second<<"   ";
            }
            cout<<"\n";
        }*/
        //Now input is complete, now we can simply take do the dijktra's algorithm '
        r=getInt();
        for(i=0;i<r;i++)
        {
            getString(source);
            getString(target);
            printn(dijkstra(map1[source],map1[target]));
            putc_unlocked('\n',stdout);
            
        }
    }
    return 0;
}
