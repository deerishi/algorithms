#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;


class ChessMetric
{
	public:long left,right,up,down,diagonal_rightup,diagonal_rightdown,diagonal_leftdown,diagonal_leftup,l_leftdown,l_downleft,l_leftup,l_upleft,l_rightdown,l_downright,l_rightup,l_upright;
	long howMany(int size, int start[2], int end[2], int numMoves);
	long dp[101][101];
};

long ChessMetric :: howMany(int size, int start[2], int end[2], int numMoves)
{
	int temp[2];
	temp[0]=start[0];temp[1]=start[1];
	cout<<"\n start is "<<start[0]<<" ,"<<start[1]<<" and end is "<<end[0]<<", "<<end[1]<<" nummoves ="<<numMoves;
	if(numMoves==0 && start[0]==end[0] && start[1]==end[1])
	{
		
		return 1;
	}
	else if(numMoves==0)
		return 0;
	//cout<<"\ndp[start[0]][start[1]] is"<<dp[start[0]][start[1]];
	//if(dp[start[0]][start[1]]!=-1)
		//return dp[start[0]][start[1]]+1;

	if(start[0]-1 >=0) temp[1]=start[1],temp[0]=start[0]-1,left=howMany(size,temp,end,numMoves-1);
	else left=0;
	cout<<" left is "<<left;
	if(start[0]+1<=size)temp[1]=start[1], temp[0]=start[0]+1,right=howMany(size,temp,end,numMoves-1);
	else right=0;
	cout<<" right is "<<right;
	if(start[1]-1 >=0) temp[0]=start[0],temp[1]=start[1]-1,down=howMany(size,temp,end,numMoves-1);
	else down=0;
	cout<<" down is "<<down;
	if(start[1]+1<=size)temp[0]=start[0], temp[1]=start[1]+1,up=howMany(size,temp,end,numMoves-1);
	else up=0;
	cout<<" up is "<<up;
	if(start[0]+1<=size and start[1]+1<=size) temp[0]=start[0]+1,temp[1]=start[1]+1,diagonal_rightup=howMany(size,temp,end,numMoves-1);
	else diagonal_rightup=0;
	cout<<" diagonal_rightup is "<<diagonal_rightup;
	if(start[0]+1<=size and start[1]-1>=0) temp[0]=start[0]+1,temp[1]=start[1]-1,diagonal_rightdown=howMany(size,temp,end,numMoves-1);
	else diagonal_rightdown=0;
	cout<<" diagonal_rightdown is "<<diagonal_rightdown;
	if(start[0]-1>=0 and start[1]-1>=0) temp[0]=start[0]-1,temp[1]=start[1]-1,diagonal_leftdown=howMany(size,temp,end,numMoves-1);
	else diagonal_leftdown=0;
	cout<<" diagonal_leftdown is "<<diagonal_leftdown;
	if(start[0]-1>=0 and start[1]+1<=size) temp[0]=start[0]-1,temp[1]=start[1]+1,diagonal_leftup=howMany(size,temp,end,numMoves-1);
	else diagonal_leftup=0;
	cout<<" diagonal_leftup is "<<diagonal_leftup<<"\n start is "<<start[0]<<","<<start[1];
	if(start[0]+1<=size and start[1]+2<=size) temp[0]=start[0]+1,temp[1]=start[1]+2, l_upright=(size,temp,end,numMoves-1);
	else l_upright=0,cout<<"\n\t in else\n\t";
	cout<<" l_upright is "<<l_upright;
	
	if(start[0]+2<=size and start[1]+1<=size) temp[0]=start[0]+2,temp[1]=start[1]+1,l_rightup=(size,temp,end,numMoves-1);
	else l_rightup=0;
	cout<<" l_rightup is "<<l_rightup;
	if(start[0]+1<=size and start[1]-2>=0) temp[0]=start[0]+1,temp[1]=start[1]-2, l_downright=(size,temp,end,numMoves-1);
	else l_downright=0;
	cout<<" down is "<<l_downright;
	if(start[0]+2<=size and start[1]-1>=0) temp[0]=start[0]+2,temp[1]=start[1]-1, l_rightdown=(size,temp,end,numMoves-1);
	else l_rightdown=0;
	cout<<" l_rightdown is "<<l_rightdown ;
	if(start[0]-1>=0 and start[1]+2<=size) temp[0]=start[0]-1,temp[1]=start[1]+2, l_upleft=(size,temp,end,numMoves-1);
	else l_upleft=0;
	cout<<" l_leftup is "<<l_upleft;
	if(start[0]-2>=0 and start[1]+1<=size) temp[0]=start[0]-2,temp[1]=start[1]+1,l_leftup=(size,temp,end,numMoves-1);
	else l_leftup=0;
	
	if(start[0]-1>=0 and start[1]-2>=0) temp[0]=start[0]-1,temp[1]=start[1]-2, l_downleft=(size,temp,end,numMoves-1);
	else l_downleft=0;
	cout<<" l_downleft is "<<l_downleft;
	if(start[0]-2>=0 and start[1]-1>=0) temp[0]=start[0]-1,temp[1]=start[1]-2, l_leftdown=(size,temp,end,numMoves-1);
	else
	l_leftdown=0;
	cout<<" l_leftdown is "<<l_leftdown;
	
	dp[start[0]][start[1]]+=left+right+up+down+diagonal_rightup+diagonal_rightdown+diagonal_leftdown+diagonal_leftup+l_leftdown+l_downleft+l_leftup+l_rightdown+l_downright+l_rightup+l_upright+l_upleft;
	cout<<"\n till now dp["<<start[0]<<"]["<<start[1]<<"] is "<<dp[start[0]][start[1]];
	return dp[start[0]][start[1]];
}
int main()
{
	ChessMetric ob1;
	int i,j,size=2;
	for(i=0;i<=size;i++)
		for(j=0;j<=size;j++)
			ob1.dp[i][j]=0;
	int start[2]={0,0},end[2]={2,2};
	long res=ob1.howMany(size,start,end,2);
	cout<<"\n res is "<<res<<"\n";
	return 0;
}
	

