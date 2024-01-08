// dp with binary search
// LIS Dp

class Solution {
public:
    static bool comp(vector<int>&v1,vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }

        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),comp);
        vector<int>temp,ans;
        int maxi=1;
        for(int i=0;i<e.size();i++){
            temp.push_back(e[i][1]);
        }
        // for(int i=1;i<e.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(e[j][0]<e[i][0] && e[j][1]<e[i][1]){
        //             dp[i]=max(dp[i],dp[j]+1);
        //             maxi=max(maxi,dp[i]);
        //         }
        //     }
        // }
        ans.push_back(temp[0]);

        for(int i=1;i<temp.size();i++){
            if(ans.back()<temp[i]){
                ans.push_back(temp[i]);
            }
            else{
                int pos=lower_bound(ans.begin(),ans.end(),temp[i])-ans.begin();
                ans[pos]=temp[i];
            }
        }

        return ans.size();
    }
};