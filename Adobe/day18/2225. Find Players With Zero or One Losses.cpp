class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& match) {
        map<int,vector<int>>mp;
        for(auto i:match){
            if(mp.find(i[0])==mp.end()){
                mp[i[0]]={0,0};
            }
            if(mp.find(i[1])==mp.end()){
                mp[i[1]]={0,1};
            }
            else{
                mp[i[1]][1]++;
            }

        }
        vector<vector<int>> ans(2);
        for(auto i:mp){
            if(i.second[0]==0 && i.second[1]==0){
                ans[0].push_back(i.first);
                continue;
            }
            if(i.second[1]==1){
                ans[1].push_back(i.first);
            }
        }
        return ans;


    }
};