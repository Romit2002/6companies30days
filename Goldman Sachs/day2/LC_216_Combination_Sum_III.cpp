class Solution {
public:

    vector<vector<int>>res;

    void helper(int idx,int k, int sum, int n, vector<int>ans){
        if(sum==n && k==0){
            res.push_back(ans);
            return;
        }

        if(sum>n){
            return;
        }

        for(int i=idx;i<=9;i++){
            ans.push_back(i);
            helper(i+1,k-1,sum+i,n,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        helper(1,k,0,n,ans);
        return res;
    }
};