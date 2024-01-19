class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans=0;
        for(auto l:mp){
            int i=l.first;
            if(mp.find(i-k)!=mp.end()){
                if(i==(i-k)){
                    if(mp[i]>1){
                        ans++;
                    }
                }else{
                    ans++;
                }
                
            }

            // if(mp.find(k-i)!=mp.end()){
            //     if(i==(k-i)){
            //         if(mp[i]>1){
            //             ans++;
            //         }
            //     }else{
            //         ans++;
            //     }
                
            // }
            
                
            
        }

        return ans;
    }
};