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
    getchar();
    for(int cs=1; cs<=t; cs++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        char grid[150][110];
        for(int i=0; i<n; i++)
            scanf("%s",grid[i]);
        int ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    int tem=0;
                    for(int k=0; k<n; k++)
                    {
                        if(grid[k][j]=='1')
                            tem++;
                    }
                    for(int k=0; k<m; k++)
                    {
                        if(grid[i][k]=='1')
                            tem++;
                    }

                    HopcroftKarp G(n,m);
                    for(int k=0; k<n; k++)
                    {
                        if(grid[k][j]=='1')
                            for(int l=0; l<m; l++)
                            {
                                if(grid[i][l]=='1' && grid[k][l]=='0')
                                {
                                    G.AddEdge(k+1,l+1);

                                }
                            }
                    }


                    ans=max(ans,tem-G.Match());
                }

            }

        printf("Case %d: %d\n",cs,ans);
    }

    return 0;
}
