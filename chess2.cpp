#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;


class ChessMetric
{
	public:
	long howMany(int size, int start[2], int end[2], int numMoves);
	long dp[101][101][51];
	
	
};
long count1=0;
long ChessMetric :: howMany(int size, int start[2], int end[2], int numMoves)
{
	int temp[2];long x;long left,right,up,down,diagonal_rightup,diagonal_rightdown,diagonal_leftdown,diagonal_leftup,l_leftdown,l_downleft,l_leftup,l_upleft,l_rightdown,l_downright,l_rightup,l_upright;
	temp[0]=start[0];temp[1]=start[1];
	//cout<<"\n start is "<<start[0]<<" ,"<<start[1]<<" and end is "<<end[0]<<", "<<end[1]<<" nummoves ="<<numMoves;
	if(numMoves==0 && start[0]==end[0] && start[1]==end[1])
	{
		
		return 1;
	}
	else if(numMoves==0)
		return 0;
	//cout<<"\ndp[start[0]][start[1]] is"<<dp[start[0]][start[1]];
	if(dp[start[0]][start[1]][numMoves]!=-1)
	{//cout<<"\t\treturning from start "<<start[0]<<","<<start[1]<<" with val="<<dp[start[0]][start[1]]+1;
	count1+dp[start[0]][start[1]][numMoves]+1;return dp[start[0]][start[1]][numMoves];}

	if(start[0]-1 >=0) temp[1]=start[1],temp[0]=start[0]-1,left=howMany(size,temp,end,numMoves-1);
	else left=0;
	
	if(start[0]+1<=size)temp[1]=start[1], temp[0]=start[0]+1,right=howMany(size,temp,end,numMoves-1);
	else right=0;
	
	if(start[1]-1 >=0) temp[0]=start[0],temp[1]=start[1]-1,down=howMany(size,temp,end,numMoves-1);
	else down=0;
	
	if(start[1]+1<=size)temp[0]=start[0], temp[1]=start[1]+1,up=howMany(size,temp,end,numMoves-1);
	else up=0;
	
	if(start[0]+1<=size and start[1]+1<=size) temp[0]=start[0]+1,temp[1]=start[1]+1,diagonal_rightup=howMany(size,temp,end,numMoves-1);
	else diagonal_rightup=0;
	
	if(start[0]+1<=size and (start[1]-1)>=0) temp[0]=start[0]+1,temp[1]=start[1]-1,diagonal_rightdown=howMany(size,temp,end,numMoves-1);
	else diagonal_rightdown=0;
	
	if(start[0]-1>=0 and (start[1]-1)>=0) temp[0]=start[0]-1,temp[1]=start[1]-1,diagonal_leftdown=howMany(size,temp,end,numMoves-1);
	else diagonal_leftdown=0;
	
	if((start[0]-1)>=0 and start[1]+1<=size) temp[0]=start[0]-1,temp[1]=start[1]+1,diagonal_leftup=howMany(size,temp,end,numMoves-1);
	else diagonal_leftup=0;
	
	if(((start[0]+1)<=size) and ((start[1]+2)<=size)){ temp[0]=start[0]+1;temp[1]=start[1]+2; l_upright=howMany(size,temp,end,numMoves-1);}
	else l_upright=0;
	
	
	if(((start[0]+2)<=size) and ((start[1]+1)<=size)) temp[0]=start[0]+2,temp[1]=start[1]+1,l_rightup=howMany(size,temp,end,numMoves-1);
	else l_rightup=0;
	
	if(((start[0]+1)<=size) and ((start[1]-2)>=0)) temp[0]=start[0]+1,temp[1]=start[1]-2, l_downright=howMany(size,temp,end,numMoves-1);
	else l_downright=0;
	
	if(((start[0]+2)<=size) and ((start[1]-1)>=0)) temp[0]=start[0]+2,temp[1]=start[1]-1, l_rightdown=howMany(size,temp,end,numMoves-1);
	else l_rightdown=0;
	
	if(((start[0]-1)>=0) and ((start[1]+2)<=size)) temp[0]=start[0]-1,temp[1]=start[1]+2, l_upleft=howMany(size,temp,end,numMoves-1);
	else l_upleft=0;
	
	if(((start[0]-2)>=0) and ((start[1]+1)<=size)) temp[0]=start[0]-2,temp[1]=start[1]+1,l_leftup=howMany(size,temp,end,numMoves-1);
	else l_leftup=0;
	
	if(((start[0]-1)>=0) and ((start[1]-2)>=0)) temp[0]=start[0]-1,temp[1]=start[1]-2, l_downleft=howMany(size,temp,end,numMoves-1);
	else l_downleft=0;
	
	if(((start[0]-2)>=0) and ((start[1]-1)>=0)) temp[0]=start[0]-2,temp[1]=start[1]-1, l_leftdown=howMany(size,temp,end,numMoves-1);
	else
	l_leftdown=0;
	/*cout<<"\n till now start= "<<start[0]<<","<<start[1]<<" and numMoves="<<numMoves;
	cout<<" \nl_leftdown is "<<l_leftdown;
	cout<<" \nl_downleft is "<<l_downleft;
	cout<<"\n l_leftup is "<<l_upleft;
	cout<<" \nl_rightdown is "<<l_rightdown ;
	cout<<"\n down is "<<l_downright;
	cout<<"\n l_rightup is "<<l_rightup;
	cout<<"\n l_upright is "<<l_upright;
	cout<<"\n diagonal_leftup is "<<diagonal_leftup;
	cout<<"\n diagonal_leftdown is "<<diagonal_leftdown;
	cout<<"\n diagonal_rightdown is "<<diagonal_rightdown;
	cout<<"\n diagonal_rightup is "<<diagonal_rightup;
	cout<<"\n up is "<<up;
	cout<<"\n down is "<<down;
	cout<<" \nright is "<<right;
	cout<<" \nleft is "<<left;*/
	x=left+right+up+down+diagonal_rightup+diagonal_rightdown+diagonal_leftdown+diagonal_leftup+l_leftdown+l_downleft+l_leftup+l_rightdown+l_downright+l_rightup+l_upright+l_upleft;
	dp[start[0]][start[1]][numMoves]=x;
	cout<<" \nand returning "<<x<<" for start "<<start[0]<<" "<<start[1]<<" and numMoves "<<numMoves;
	count1+=x;
	return x;
}
int main()
{
	ChessMetric ob1;
	int i,j,size=2,k,numMoves=1;
	for(i=0;i<=size;i++)
		for(j=0;j<=size;j++)
			for(k=0;k<=numMoves;k++)
				ob1.dp[i][j][k]=-1;
	int start[2]={0,0},end[2]={0,0};
	long res=ob1.howMany(size,start,end,numMoves);
	cout<<"\n res is "<<res<<"\n";
	return 0;
}
	

