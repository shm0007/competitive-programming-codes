class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>ct;
        for(auto num: nums){
            ct[num]++;
        }
        int prev = -1;
        int ans = 0;
        for(auto kv: ct){
            int num = kv.first;
            int same = (kv.second-1);
            ans += (( same)* (same+1)/2);

            if(num <= prev){
                ans += (( prev +1- num)* kv.second);
                prev = prev + kv.second;
            }else
                prev = num + (kv.second-1);            
        }
        return ans;
    }
};