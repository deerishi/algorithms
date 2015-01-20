#include "bits/stdc++.h"
using namespace std;
int main()
{
	char s[205]="a",ch;
	string str;

	int i,num_underscores,num_caps,k,flag;
			
	while(scanf("%s",s)!=EOF)
	{

		
		//cout<<"hi";
		str.clear();
		k=0;
		flag=0;
		num_underscores=0;
		num_caps=0;
		if(strlen(s)==1 and islower(s[0]))
		printf("%s\n",s);
		else if(isupper(s[0]) or s[0]=='_')
		printf("Error!\n");
		else
		{
			for(i=0;i<strlen(s);i++)
			{
					if(isupper(s[i]))
					{	
						
						str+='_';
						str+=tolower(s[i]);
						num_caps++;
					}
					else if(s[i]=='_')
					{
						if(isupper(s[i+1]) or i==(strlen(s)-1) or s[i+1]=='_')
						{
							flag=1;
							printf("Error!\n");
							break;
						}	
						str+=toupper(s[++i]);
						num_underscores++;
					}
					else
					str+=s[i];
					
					if(num_underscores>0 and num_caps>0)
					{
						printf("Error!\n");
						flag=1;
						break;
					}
				
			}
			if(flag==0)
			{
				for(i=0;i<str.length();i++)
				{
					putc_unlocked(str[i],stdout);
				}
				putc_unlocked('\n',stdout);
			}
		}
	}
	return 0;
}
			
			
		
