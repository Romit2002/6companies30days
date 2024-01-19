/*formula based
4 3 2 6
0 1 2 3
25

6 4 3 2
0 1 2 3
25-6+sumof_all_array element except last one-(lastidx*6(bcz 6 was at 0th pos initially))*/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(i*nums[i]);
        }
        int prevSum=ans;
        int n=nums.size();
        for(int i=nums.size()-1;i>=1;i--){
            prevSum+=(sum-(nums[i]*n));
            ans=max(prevSum,ans);
        }

        return ans;
    }
};