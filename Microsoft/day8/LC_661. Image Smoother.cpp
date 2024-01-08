class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> ans(img.size(),vector<int>(img[0].size(),0));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                int temp=img[i][j];
                int cnt=1;
                for(int k=0;k<dir.size();k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(x<img.size() && x>=0 && y<img[0].size() && y>=0){
                        temp+=img[x][y];
                        cnt++;
                    }
                }
                if(cnt>0)
                ans[i][j]=floor(temp/cnt);
            }
        }
        return ans;
    }
};