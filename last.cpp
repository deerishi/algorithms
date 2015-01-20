#include "bits/stdc++.h"
int main()
{
	char s[1005];
	int t,x,a;
	long long int b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		scanf("%llu",&b);
		a=s[strlen(s)-1]-'0';
		if(a==0 and b!=0)
		printf("0\n");
		else if(a==1 or b==0)
		printf("1\n");
		else if(a==6)
		printf("6\n");
		else if(a==5)
		printf("5\n");
		else 
		{
			x=b%4;
			switch(x)
			{
				case 0: if(a==4 or a==2 or a==8) printf("6\n");
						else if(a==3 or a==7 or a==9) printf("1\n");break;
				case 1:  printf("%d\n",a);
						break;
				case 2:printf("%d\n",(a*a)%10);break;
				case 3:printf("%d\n",(a*a*a)%10);break;
			}
		}
	}
	return 0;
}
	
