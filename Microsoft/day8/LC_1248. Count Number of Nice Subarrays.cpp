class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int odd=0;
        int cnt=0;
        int st=0;
        int prev=0;
        vector<int>odd;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                odd.push_back(i);
            }
            if(odd.size()-st>k){
                prev=odd[st]+1;
                st++;
                
            }

            if(odd.size()-st==k){
                cnt+=(odd[st]-prev);
                cnt++;
            }

            


        }

        return cnt;
    }
};