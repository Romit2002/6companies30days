class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int ans=0;
       vector<long long>dp(n+1);
        long long MOD=1000000007;
        long long curr=0;
        dp[1]=1;
        dp[0]=0;
       for(int i=2;i<=n;i++){
           long long newS=dp[max((i-delay)%MOD,0LL)];
           long long newF=dp[max((i-forget)%MOD,0LL)];

            curr+=(newS-newF+MOD)%MOD;
            dp[i]=curr;
       }

       for(int i=max(n-forget+1,0);i<=n;i++){
           ans=(ans+dp[i])%MOD;
       }
       return ans;
    
        // deque<pair<int,int>>dq;
        // dq.push_back({1,1});
        // while(!dq.empty()){
        //     pair<int,int>p=dq.front();
        //     dq.pop_front();

        //     int st=p.first;
        //     int end=p.second;
        //     if(end-st==forget){
        //         ans--;
        //         continue;
        //     }
        //     if(end-st>=delay){
        //         ans+=1;
        //         if(end+delay<=n){
        //             dq.push_back({end,end});
        //         }
        //     }

        //     if(end+1<=n){
        //         dq.push_back({st,end+1});
        //     }
        // }

        // return ans%MOD;
        
    }
};