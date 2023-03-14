#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
vector<int>grid[1000];
map<string , int> MP;
map<int , string> mp;
int indegree[1000];
int main()
{
//   freopen("ta.txt","w",stdout);
    int cs=1;
    int n,m;
    char t1[500],t2[500];
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        string str;
        memset(indegree,0,sizeof(indegree));
        int in=1;

        for(int i=0;i<n-1;i++)
        {
            scanf("%s %s",t1,t2);
            if(MP.find(t1)==MP.end())
            {MP[t1] =in;
            mp[in++]=t1;
            }
            if(MP.find(t2)==MP.end())
            {MP[t2] =in;
            mp[in++]=t2;
            }




            grid[MP[t1]].push_back(MP[t2]);
            indegree[MP[t2]]++;
        }

        int work=0;
        printf("Case %d:\n",cs);
        while(work!=n)
        {
            for(int i=1;i<=n;i++)
            {
                if(indegree[i]==0)
                {

                    cout<<mp[i]<<endl;
                    indegree[i]=-1;
                    work++;
                    for(int j=0;j<grid[i].size();j++)
                    indegree[grid[i][j]]--;
                    break;
                }
            }
        }
        printf("\n");
    for(int i=0;i<=n;i++)
    grid[i].clear();
    mp.clear();
    MP.clear();
    }
return 0;
}

