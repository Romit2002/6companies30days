// dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),0);
        int sum=0;
        int maxi=nums[0];
        multiset<int>ms;
        for(int i=0;i<k;i++){
            sum=(sum>0?sum:0)+nums[i];
            maxi=max(sum,maxi);
            
            // if(sum!=maxi)
            //     dp[i]=sum+nums[i];
            // else
                dp[i]=sum;
            sum=maxi;
            ms.insert(dp[i]);
        }

        for(int i=k;i<nums.size();i++){
           dp[i]=nums[i]+(*ms.rbegin()>0?*ms.rbegin():0);
           ms.erase(ms.find(dp[i-k]));
           ms.insert(dp[i]);

           
        }
        int ans=dp[0];
        for(auto i:dp){ //as -ve elements are there we have to check the whole array for max
            ans=max(i,ans);
        }
        return ans;


    }
};