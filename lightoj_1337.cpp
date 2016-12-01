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
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int vis[510][510];
char grid[510][510];
int cost[1010],m,n;

int bfs(int sti,int stj,int in)
{
    if(vis[sti][stj]!=0)
    {
        return cost[in]=cost[vis[sti][stj]];
    }
    if(grid[sti][stj]=='#')
    return cost[in]=0;
    queue<int>Q;
    vis[sti][stj]=in;
        int crystal=0;

    Q.push(sti);
    Q.push(stj);
    while(!Q.empty())
    {
        int tx=Q.front();
        Q.pop();
        int ty=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {

            int nx=tx+X[i];
            int ny=ty+Y[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && vis[nx][ny]==0)
            {
                Q.push(nx);
                Q.push(ny);
                vis[nx][ny]=in;
                if(grid[nx][ny]=='C')
                {
//                  printf("ij %d %d(%d %d)\n",nx,ny,tx,ty);
                    crystal++;

                }
            }
        }

    }
    return cost[in]=crystal;
}
int main()
{
    int t,q,u,v;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
//        memset(cost,0,sizeof(cost));
            printf("Case %d:\n",cs);
        memset(vis,0,sizeof(vis));
        scanf("%d %d %d",&n,&m,&q);
        for(int i=0;i<n;i++)
        scanf("%s",grid[i]);

        for(int i=1;i<=q;i++)
        {
            scanf("%d %d",&u,&v);
            int ans=bfs(u-1,v-1,i);
        printf("%d\n",ans);
        }

    }
    return 0;
}


