class Solution {
public:
    vector<int> bit;
    int n;
    void updateBit( int pos,int val){
        pos++;
        while(pos<=n){
            bit[pos]+=val;
            pos+= (pos& (-pos)); 
        }
        
    }

    int getSum(int pos){
        int sum = 0;
        pos++;
        while(pos>0){
            sum+=bit[pos];
            pos-=(pos & (-pos));
        }
        return sum;
    }

    int kBigIndices(vector<int>& nums, int k) {
        n = nums.size();
        vector<bool>ans(nums.size(),false);
        bit.clear();
        //Initialize BIT with nums.size()
	for(int num: nums)
            bit.push_back(0);
        bit.push_back(0);

	//For each number, increment counter for nums[i]-1 in the BIT
        for(int i = 0; i< nums.size(); i++){
            updateBit( nums[i]-1, 1);
            int lessThanNum = getSum(nums[i] -2);
            if(lessThanNum >=k )
                ans[i] = true;
        }

        // Do same thing backwards
        bit.clear();
        for(int num: nums)
            bit.push_back(0);
        bit.push_back(0);
        int an = 0;
        for(int i = nums.size()-1; i>=0 ; i--){
            updateBit( nums[i]-1, 1);
            int lessThanNum = getSum(nums[i] -2);
            if(lessThanNum >=k  && ans[i])
                ans[i] = true;
            else
                ans[i] = false;            
        }
        for(int i =0; i< nums.size(); i++)
        {
            cout<<ans[i];
                if(ans[i])
                an++;
        
        }
        return an;
        
    }
};