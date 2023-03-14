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
int X[]= {-2,-2,-1,1,2, 2, 1,-1};
int Y[]= {-1,1 , 2,2,1,-1,-2,-2};

struct HopcroftKarp
{
    int n, m;
    vector <vector <int> > adj;
    vector <int> right, left;
    vector <int> dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void AddEdge (int l, int r)
    {
        adj[l].push_back(r);
    }

    bool BFS ()
    {
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l)
        {
            if (right[l] == 0)
            {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty())
        {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0])
            {

                int sizel=adj[l].size();
                for(int i=0; i<sizel; i++)
                {
                    int r=adj[l][i];
                    if (dist[left[r]] == -1)
                    {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }

                }
            }
        }
        return dist[0] != -1;
    }

    bool DFS (int l)
    {
        if (l != 0)
        {
            int sizel=adj[l].size();
            for(int i=0; i<sizel; i++)
            {
              int  r=adj[l][i];
                if (dist[left[r]] == dist[l] + 1 && DFS(left[r]))
                {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int Match ()
    {
        right = vector <int>(n + 1, 0);
        left = vector <int>(m + 1, 0);
        int ret = 0;
        while (BFS())
        {
            for (int l = 1; l <= n; ++l)
            {
                if (right[l] == 0 && DFS(l))
                {
                    ret++;
                }
            }
        }
        return ret;
    }
};

int main()
{

    int t,n,m,k,tmx,tmy;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {

        map<    pair<int,int>, int >mp;
        scanf("%d %d %d",&n,&m,&k);
        int in=1;
        bool broken[205][205];
        int ulta=0,lef=1,rig=1;
        map<int,int>left;
        map<int,int>right;
        memset(broken,false,sizeof broken);
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&tmx,&tmy);
            broken[tmx-1][tmy-1]=1;
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {

                mp[make_pair(i,j)]=in++;
                if(broken[i][j]==1)
                continue;
                if((i+j)%2==0)
                {
                    left[in-1]=lef++;
                }
                else
                {
                    right[in-1]=rig++;

                }

            }
//        printf("laffffft%d %d\n",lef,rig);
        HopcroftKarp G(lef-1,rig-1);

//        for(int i=1;i<=n*m;i++)
//        printf("mp%d  %d\n",left[i],right[i]);
        int nx,ny;
        map<pair<int,int>,int>take;
        int ctt=0,u,v;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(broken[i][j]==0 && ((i+j)%2==0))
                {
                    for(int K=0; K<8; K++)
                    {
                        nx=i+X[K];
                        ny=j+Y[K];
                        if(nx>=0 && ny>=0 && nx<n && ny<m && broken[nx][ny]==0)
                        {
                            u=mp[make_pair(i,j)];
                            v=mp[make_pair(nx,ny)];
//                            if(take.find(make_pair(v,u))==take.end() )
                            {
//                                printf("%d\n",ctt++);

//                                if(left.find(u)!=left.end())
                                {
//                                    printf("%d %d %d\n",mp[make_pair(nx,ny)],right[mp[make_pair(nx,ny)]],left[mp[make_pair(i,j)]]);
                                    G.AddEdge(left[u],right[v]);
                                }
//                                else
                                {
//                                    printf("%d %d %d\n",mp[make_pair(nx,ny)],right[mp[make_pair(i,j)]],left[mp[make_pair(nx,ny)]]);

//                                    G.AddEdge(left[v],right[u]);
                                }
//                                take[make_pair(u,v)]=1;
                            }
                        }
                    }
                }
            }
        printf("Case %d: %d\n",cs,n*m-k-G.Match());
    }

    return 0;
}
