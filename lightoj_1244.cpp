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
#define PI (2* acos(0))
#define pb push_back
#define ll long long
#define MOD 10007LL
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};

typedef struct
{
	long long mat[5][5];
	int r,c;
}martix;

martix mul_martix(martix a, martix b)
{
	martix ans;
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	ans.mat[i][j]=0;
	int r1,r2,c2,c1;
	r1=a.r;
	c1=a.c;
	r2=b.r;
	c2=b.c;
	for(int i=0; i<r1; i++)
        for(int j=0; j<c2; j++)
            {
                for(int k=0;k<c1;k++)
                {
                    ans.mat[i][j]+=(a.mat[i][k] * b.mat[k][j])%MOD;
                    ans.mat[i][j]%=MOD;
                 }
            }
            ans.r=r1;
            ans.c=c2;
	return ans;
}

martix pow_mod(martix x , int e)
{
	martix ans, temp;
	if (e == 0)
	{
		ans.mat[0][0] = ans.mat[1][1] =ans.mat[2][2] = ans.mat[3][3] = 1;
		ans.mat[0][1] = ans.mat[0][2] = ans.mat[0][3] = 0;
		ans.mat[1][0] = ans.mat[1][2] = ans.mat[1][3] = 0;
		ans.mat[2][0] = ans.mat[2][1] = ans.mat[2][3] = 0;
		ans.mat[3][0] = ans.mat[3][1] = ans.mat[3][2] = 0;
        ans.r=ans.c=4;
		return ans;
	}
	if (e == 1)
	{
		return x;
	}
	temp = pow_mod(x,e>>1);
	ans = mul_martix(temp,temp);
	if (e&1)
	{
		ans = mul_martix(ans,x);
	}
	return ans;
}

int main()
{
	int t;
    ll	int a,b,m,mod,c;
	long long int n;
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++)
	{
        martix tmp,st,ans;
		scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
			st.mat[0][0] =a;
			st.mat[0][2] =b;
            st.mat[0][3] =1;
            st.mat[1][0] =st.mat[2][1] = st.mat[3][3] = 1;
            st.mat[0][1] =0;
            st.mat[1][1] = st.mat[1][2] = st.mat[1][3] = 0;
            st.mat[2][0] = st.mat[2][2] =st.mat[2][3] =  0;
            st.mat[3][0] = st.mat[3][1] =st.mat[3][2] =  0;
            st.r=4;
            st.c=4;
		if (n <= 2)
		{
		printf("Case %d: 0\n",cs);
        }
		else
		{
			tmp.mat[0][0] = 0;
			tmp.mat[1][0] = 0;
			tmp.mat[2][0] = 0;
			tmp.mat[3][0] = c;
			tmp.r=4;
			tmp.c=1;
			ans = mul_martix(pow_mod(st,n-2),tmp);

		printf("Case %d: %lld\n",cs,ans.mat[0][0]%MOD);

		}

	}
	return 0;
}
