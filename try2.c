#include "bits/stdc++.h"


int main()
{
  const int x = 10;
  static int y = x;
 
  if(x == y)
     printf("Equal");
  else if(x > y)
     printf("Greater");
  else
     printf("Less");
 
  getchar();
  return 0;
}
