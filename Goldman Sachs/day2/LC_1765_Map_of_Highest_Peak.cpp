class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        vector<vector<int>> ans(w.size(),vector<int>(w[0].size(),INT_MAX));
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q,pq,nq,em;

        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[0].size();j++){
                if(w[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<dir.size();i++){
                int x=p.first+dir[i][0];
                int y=p.second+dir[i][1];

                if(x<ans.size() && y<ans[0].size() && ans[x][y]==INT_MAX){

                    q.push({x,y});
                    ans[x][y]=ans[x-dir[i][0]][y-dir[i][1]]+1;
                }
            }
        }
        int cnt=1;
        
        return ans;
    }
};