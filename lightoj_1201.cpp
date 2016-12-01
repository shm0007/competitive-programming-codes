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
//struct data
//{
//    int h, e, stat;
//};
//data m[110], w[110];
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w) {
 VI mr = VI(w.size(), -1);
 VI mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
int flag[1110];
int grid[1100][1100],n;
void bfs(int start)
{
    queue<int> Q;

    Q.push(start);
    flag[start]=2;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<n;i++)
        {
            if(grid[u][i]==1)
            {
                if(flag[i]==0)
                Q.push(i);

                if(flag[u]==flag[i])
                {
               return;
                }
                if(flag[u]==1)
                {

                    flag[i]=2;

                }
                else
                flag[i]=1;


            }
        }
    }

}
int main()
{
    int  m,u,v,t;
    scanf("%d", &t);
    for(int cs=1;cs<=t;cs++)
    {
        memset(grid,0,sizeof(grid));
        scanf("%d %d", &n,&m);
    int adj[1010][5];
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            adj[i][0]=u-1;
            adj[i][1]=v-1;
                 grid[u-1][v-1]=grid[v-1][u-1]=1;
//                     lst[v].push_back(u);
        }
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)
            bfs(i);
        }
        int N=0,M=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        if(flag[i]==2)
        {
            mp[i]=M;
            M++;

        }
        else
        {
            mp[i]=N;
            N++;

        }
          VVI w(M,VI(N,0));
        for(int i=0;i<m;i++)
        {
            u=adj[i][0];
            v=adj[i][1];
//            printf("uu%d/n",u);
            if(flag[u]==2)
            {
//                cout<<u;
                w[mp[u]][mp[v]]=1;
//                w[mp[u]][mp[v]]=1;


            }
            else
            w[mp[v]][mp[u]]=1;
        }
        printf("Case %d: %d\n", cs,n- BipartiteMatching(w));
    }
    return 0;
}
