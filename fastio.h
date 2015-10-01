#include "bits/stdc++.h"
using namespace std;
char TEMP[1<<10];
#define GETC() getc_unlocked(stdin)
class FastIo
{
	public:
		char CH;
		#define defineNumInput(intType)\
		 void operator>>(intType &n)\
		 {\
		 	CH=getc_unlocked(stdin);\
		 	\
		 	while(!isdigit(CH) and CH!='-') CH=getc_unlocked(stdin);\
		 	intType sign=1;\
		 	n=0;\
		 	if(CH=='-') sign=-1,CH=getc_unlocked(stdin);\
		 	while(isdigit(CH)){ \
		 	n=n*10+CH-'0';\
		 	CH=getc_unlocked(stdin);}\
		 	\
		 }
		 
		 defineNumInput(int);
		 defineNumInput(long int);
		 defineNumInput(long long int);
		 
		 void operator>>(char *s)
		 {
		 	char *ptr=s;
		 	CH=getc_unlocked(stdin);
		 	while(CH<=' ') CH=getc_unlocked(stdin);
		 	
		 	while(CH>='-')
		 	{
		 		*ptr++=CH;
		 		CH=getc_unlocked(stdin);
		 	}
		 	*ptr='\0';
		 	//printf("s is %s\n",s);
		 }
		 
		
		 	void operator>>(double &n)
		 	{
		 		(*this)>>TEMP;
		 		//printf("temp is %s\n",TEMP);
		 		sscanf(TEMP,"%lf",&n);
		 	}

		 void operator>>(string &s)
		 {
		 	CH=getc_unlocked(stdin);
		 	while(CH<=' ') CH=getc_unlocked(stdin);
		 	s.clear();
		 	while(CH>='-')
		 	{
		 		s+=CH;
		 		CH=getc_unlocked(stdin);
		 	}
		 	
		 }
		 //Now defining output routines 
		 
		 #define defineOut(intType)\
		 	void operator<<(intType &n){\
		 	intType sign=1;\
		 	if(n<0) sign=-1,n*=-1;\
		 	char *ptr=TEMP+30;\
		 	*ptr--='\0';\
		 	while(n>0){\
		 	*ptr--=n%10+'0';\
		 	n/=10;}\
		 	if(sign==-1) *ptr--='-';\
		 	*ptr++;\
		 	while(*ptr!='\0'){\
		 		putc_unlocked(*ptr++,stdout);}\
		 	}
		 	
		 	defineOut(int);
		 	defineOut(long int);
		 	defineOut(long long int);
		 	
		 	void operator<<(const char *s)
		 	{
		 		const char *ptr=s;
		 		while(*ptr!='\0')
		 		{	
		 			putc_unlocked(*ptr++,stdout);
		 		}
		 	}
		 	
		 	void operator<<(char *s)
		 	{
		 		 char *ptr=s;
		 		while(*ptr!='\0')
		 		{	
		 			putc_unlocked(*ptr++,stdout);
		 		}
		 	}
		 	
		 	void operator<<(string s)
		 	{
		 		int i=0;
		 		while(i<s.length())
		 		{	
		 			putc_unlocked(s[i++],stdout);
		 		}
		 	}
		 	
		 	void operator<<(double d)
		 	{
		 		sprintf(TEMP,"%lf%c",d,'\0');
		 		(*this)<<TEMP;
		 	}
		
}io;

#define cin io		 
#define cout io		 	
		 	
		 	
