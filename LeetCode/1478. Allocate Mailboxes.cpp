class Solution {
public:
    int rec(int pos,vector<int>& houses, int k,vector<vector<int>>& cost,vector<vector<int>>& dp){
        if(pos == houses.size())
            return 0;
        if(dp[pos][k] != -1)
            return dp[pos][k];
        if( k == 0)
            return dp[pos][k] =  cost[pos][houses.size()-1];
        int ans = INT_MAX;
        for(int i = pos; i<houses.size();  i++){
            int cs = cost[pos][i] + rec(i+1,houses,k-1,cost,dp);
            ans = min(ans,cs);
        }
        return dp[pos][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        vector<vector<int>>cost(houses.size(), vector<int>(houses.size(),0));
        sort(houses.begin(),houses.end());
        int n = houses.size();
        for(int i =0 ; i< n; i++ ){
            for(int j = i; j<n; j++){
                int med = houses[(i+j)/2];
                for(int k = i; k<=j; k++){
                    cost[i][j] += abs(med- houses[k]);
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(k,-1));
        return rec(0,houses,k-1,cost,dp);
        
    }
};