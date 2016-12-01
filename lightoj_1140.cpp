/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#include<sstream>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};


struct data
{
   ll int arr[10], sol;
    data() {}
    data(int a)
    {
        sol = a;
        for(int i = 0; i < 10; i++)
            arr[i] = 0;
    }
};
char str[100];
data dp[19][2][2];
int len;

data func(int pos, int hi, int di)
{
    if(pos == len) return data(1);
    data & res = dp[pos][hi][di];
    if(res.sol != -1) return res;
    res = data(0);
    int high = (hi == 1)? str[pos]-'0':9;
    for(int i = 0; i <= high; i++)
    {
        data tem = func(pos+1,((hi == 1) && (i+'0' == str[pos])),((di == 1)||(i != 0)));
        for(int j = 0; j < 10; j++)
            res.arr[j] += tem.arr[j];
        res.sol += tem.sol;
        if(di == 0 && i == 0) continue;
        res.arr[i] += tem.sol;
    }
    return res;
}
#include<assert.h>
int main()
{
   ll int n,m;
   int t;
//   scanf("%d",&t);
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==-1 && m==-1)
            return 0;
        sprintf(str,"%lld",m);
        len=strlen(str);
        memset(dp,-1,sizeof dp);
        data ans = func(0,1,0);
         int an[50];
        for(int i=0; i<10; i++)
            an[i]=ans.arr[i];
        sprintf(str,"%lld",n-1);
        len=strlen(str);
        memset(dp,-1,sizeof dp);
        data ans2 = func(0,1,0);

        for(int i=0; i<10; i++)
            an[i]-=ans2.arr[i];


        printf("%lld\n",an[0]);


    }

    return 0;
}

