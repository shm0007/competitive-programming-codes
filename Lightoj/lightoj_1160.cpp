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
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
//ll int MOD = 1LL<<32;
typedef struct
{
       unsigned int mat[36][36];
	int r,c;
}martix;

martix mul_martix(martix a, martix b)
{
	martix ans;
	for(int i=0;i<36;i++)
	for(int j=i;j<36;j++)
	{
	    ans.mat[i][j]=0;
	ans.mat[j][i]=0;

	}
	int r1,r2,c2,c1;
	r1=a.r;
	c1=a.c;
	r2=b.r;
	c2=b.c;
	for(int i=0; i<r1; i++)
        for(int k=0; k<c2; k++)
            {
                for(int j=0;j<c2;j++)
                {
                    ans.mat[i][j]+=(a.mat[i][k] * b.mat[k][j]);
//                    ans.mat[i][j]%=MOD;
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
		for(int i=0;i<36;i++)
		for(int j=0;j<36;j++)
		ans.mat[i][j]=0;
		for(int i=0;i<36;i++)
		ans.mat[i][i]=1;
        ans.r=ans.c=36;
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
    vector<string>v;
bool check(int i,int j)
{

    int X=str[0];
    int Y=str[1];
    int Z=str[2];
    int Q=str[3];

    return true;
}
int main()
{
//    freopen("in.txt","w",stdout);
	int t,cs=1;
    ll	int a,b,m,mod,c;
	int n;
	martix tmp,st,ans;
            int in=0;
    for(int i=0;i<36;i++)
        for(int j=0;j<36;j++)
        st.mat[i][j]=0;
    string sttr;

//    sttr=1+'A';cout<<sttr;
    for(int i=0;i<7;i++)
        for(int j=i+1;j<7;j++)
        {
            for(int k=j+1;k<7;k++)
                for(int l=k+1;l<7;l++)
                {
                    sttr=i;
                    sttr+=j;
                    sttr+=k;
                    sttr+=l;
                    if(mp.find(sttr)==mp.end())
                    mp[sttr]=in++;
                check(sttr);
                }

         }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v.size();j++)
                {
                    if(check(i,j))
                    {
                        st.mat[i][j]=1;
                    }
                }
        }
//		printf("%d\n",v.size());
unsigned int sum=0;
st.r=35;
st.c=35;

	scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
//	            for(int i=0;i<36;i++)
//           {
//               for(int j=0;j<36;j++)
//               printf("%u ",st.mat[i][j]);
//               puts("");
//           }
            int man,F=0;
            string mat;
            for(int i=0;i<7;i++)
            {
                scanf("%d",&man);
                if(man!=0)
                    {
                        if(F!=0)
                        mat+=i;
                        else
                        {
                            mat=i;
                            F=1;
                        }
                    }
            }
            cout<<mat;
            for(int i=0;i<35;i++)
            {
                if(v[i]==mat)
                {
                    F=i;
                    ;
                    printf("%d",i);
                    break;
                }
            }
            printf("Case %d: ",cs++);
            if(t==1)
            {
                printf("36\n");
                continue;

            }
            sum=0;
			ans = pow_mod(st,t-1);
			for(int i=0;i<ans.c;i++)
                {
                    sum+=ans.mat[F][i];
//                sum%=MOD;

                }
//                cout<<sum<<endl;
	printf("%u\n",sum);//,ans.mat[1][0]%MOD);


	}
	return 0;
}

