#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
 
using namespace std;
int donations[] = { 836, 100, 274, 931, 632, 817, 951, 992, 17, 349, 189, 99, 77, 316, 698, 10, 732, 3, 2, 445, 524, 343, 953, 513, 459};
int N = sizeof(donations)/ sizeof(donations[0]);
int dp[50];
 
int main(int argc, char const *argv[])
{
/*
There are two main cases to be considered here.
1. Include element at index 0.
- This leads us to not pick the last element since it is cyclic in nature.
2. Include element at index 1.
- In this case, we can pick the last element.
but whether we pick the element at i, depends on the following condition:
dp[i] = max(dp[i-2] + donations[i], dp[i-1])
which basically states, is it in our interest to pick the current donation and
drop the donation offered by the previous neighbor.
We pick the max of both cases stated earlier.
*/
 
memset(dp, 0, sizeof(dp));
dp[0] = donations[0];
for (int i = 2; i < N-1; ++i)
{
dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
}
int ans1 = dp[N-2];
 
memset(dp, 0, sizeof(dp));
dp[1] = donations[1];
 
for (int i = 2; i < N; ++i)
{
dp[i] = max(dp[i-2] + donations[i], dp[i-1]);
}
int ans2 = dp[N-1];
cout << max(ans1, ans2);
cout << endl;
return 0;
} 
