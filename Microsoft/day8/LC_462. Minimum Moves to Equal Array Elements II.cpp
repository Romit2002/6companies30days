class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        // if(nums.size()&1){
            for(int i=0;i<nums.size();i++){
                cnt+=abs(nums[nums.size()/2]-nums[i]);
            }
            // return cnt;
        // }

        // else{
        //     for(int i=0;i<nums.size();i++){
        //         cnt+=abs(nums[nums.size()/2]-nums[i]);
        //     }
        //     int cnt1=0;
        //     for(int i=0;i<nums.size();i++){
        //         cnt1+=abs(nums[nums.size()/2-1]-nums[i]);
        //     }

        //     return min(cnt1,cnt);


        // }

        return cnt;
    }
};