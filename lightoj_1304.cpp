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
    int t,n,m,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        char grid[110][110];
        memset(grid,0,sizeof(grid));
        scanf("%d %d",&n,&m);
        getchar();
        for(int i=0; i<n; i++)
            scanf("%s",grid[i]);
        int row_grd[109][105];
        memset(row_grd,0,sizeof(row_grd));
        int col_grd[109][105];
        memset(col_grd,0,sizeof(row_grd));
        int ROW=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]!='W')
                    row_grd[i][j]=ROW;
                else
                    ROW++;

                if(j==m-1)
                    ROW++;
            }
        }
        int COL=1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[j][i]!='W')
                    col_grd[j][i]=COL;
                else
                    COL++;

                if(j==n-1)
                    COL++;
            }
        }
        HopcroftKarp H(ROW-1,COL-1);
        int u,v;
        map<pair<int,int>, pair<int,int> >mp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='.')
                {
                    H.AddEdge(row_grd[i][j],col_grd[i][j]);
//                    printf("asd->%d %d\n",row_grd[i][j],col_grd[i][j]);
                    mp[make_pair(row_grd[i][j],col_grd[i][j])]=make_pair(i,j);
                }
            }
        }
        int x,y;
        printf("Case %d: %d\n",cs++,H.Match());
        for(int i=1; i<COL; i++)
        {
            if(H.left[i]!=0)
            {
                x=mp[make_pair(H.left[i],i)].first;
                y=mp[make_pair(H.left[i],i)].second;
            grid[x][y]='T';
            }

        }
        for(int i=0;i<n;i++)
        puts(grid[i]);

    }

    return 0;
}
