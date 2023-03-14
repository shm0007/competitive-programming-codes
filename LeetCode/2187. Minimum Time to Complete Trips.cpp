class Solution {
public:
    // Calculate how many trips can be completed in tm time
    long long int getTotalTrips(vector<int>&time,long long int tm){
        long long int ans = 0;
        for(auto t: time){
            ans+= tm/t;
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long int  hi = (long long )time[0] * totalTrips;
        long long int lo = 0;
        long long int ans = 0;
        while(lo<=hi){
            long long int mid = (lo + hi) / 2;

            long long int currentTrips = getTotalTrips(time,mid);
            if(currentTrips < totalTrips)
                lo = mid+1;
            else{
                ans = mid;
                hi = mid-1;
                
            }
                
        }
        return ans;
    }


};