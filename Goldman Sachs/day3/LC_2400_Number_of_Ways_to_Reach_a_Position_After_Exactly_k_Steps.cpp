class Solution {
public:
    
    int MOD=1000000007;
    int solve(int s, int e, int curr,int k,vector<vector<int>>&dp){
        if(k==0 && curr==e){
            return 1;
        }
        if(k==0){
            return 0;
        }
        if(dp[curr+1000][k]!=-1){
            return dp[curr+1000][k]%MOD;
        }

        int left=solve(s,e,curr-1,k-1,dp)%MOD;
        int right=solve(s,e,curr+1,k-1,dp)%MOD;

        dp[curr+1000][k] = (left+right)%MOD;

        return dp[curr+1000][k];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(4001,vector<int>(1001,-1));
        long long ans=solve(startPos,endPos,startPos,k,dp);
        return ans%MOD;

    }
};