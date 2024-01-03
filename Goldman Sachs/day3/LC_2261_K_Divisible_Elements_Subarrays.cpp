class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        map<vector<int>,int>mp;
        
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            vector<int>v;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p==0){
                    cnt++;
                }

                if(cnt>k){
                    mp[v]++;
                    break;
                }
                v.push_back(nums[j]);
                mp[v]++;
            }
        }
        return mp.size();
    }
};