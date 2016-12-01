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

int X[]= {0,0,1,-1};
int Y[]= {-1,1,0,0};
using namespace std;

int  arr[420];
bool col[420];
vector<int>adj[420];
int M,N;
bool dfs(int now)
{
    if(col[now]) return false;
    col[now]=true;
    int i, end;
    for(i=0; i<adj[now].size(); i++)
    {
        end = adj[now][i];
        if((arr[end]==-1) || (dfs(arr[end])))
        {
            arr[end] = now;
            return true;
        }
    }
    return false;
}

int match()
{
    memset(arr, -1, sizeof arr);
    int i, cnt=0;
    for(i=0; i<M; i++)
    {
        memset(col, false, sizeof col);
        if(dfs(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    char grid[50][50];
    int t,n,m;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%s",grid[i]);
        map<pair<int,int> , int >ODD;
        map<pair<int,int> ,int >EVEN;
        M=0;
        N=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
//                putchar(grid[i][j]);
                if(grid[i][j]=='*')
                {

                    if(((i+j)%2)==1)
                    {
                        ODD[make_pair(i,j)]=M++;
                    }
                    else
                        EVEN[make_pair(i,j)]=N++;

                }
            }
//            printf("%d %d\n",M,N);
        for(int i=0; i<=M; i++)
            adj[i].clear();
//            if(M+N==0)
//            {
//            printf("Case %d: 0\n",cs);
//            continue;
//            }
int ck=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(((i+j)%2)==1 && grid[i][j]=='*')
                {
                    pair<int ,int>pr;
                    pr=make_pair(i,j);
//                    printf("map%d\n",ODD[pr]);
                    if(i-1>=0 && grid[i-1][j]=='*')
                    {
                        ck++;

//                            printf("%d %d\n",ODD[make_pair(i,j)],EVEN[make_pair(i-1,j)]);
                        adj[ODD[pr]].pb(EVEN[make_pair(i-1,j)]);
                    }
                    if(j-1>=0 && grid[i][j-1]=='*')
                    {
                        ck++;
                        adj[ODD[pr]].pb(EVEN[make_pair(i,j-1)]);
                    }
                    if(i+1<n && grid[i+1][j]=='*')
                    {
                        ck++;
//                            puts("a");
//                            printf("%d %d\n",ODD[make_pair(i,j)],EVEN[make_pair(i-1,j)]);
                        adj[ODD[pr]].pb(EVEN[make_pair(i+1,j)]);
                    }
                    if(j+1<m && grid[i][j+1]=='*')
                    {
                        ck++;
                        adj[ODD[pr]].pb(EVEN[make_pair(i,j+1)]);
                    }
//                printf("%d\n",ck);
                }
            }

        }
        int mt=match();
        printf("Case %d: %d\n",cs,M+N-mt);
    }


    return 0;
}
