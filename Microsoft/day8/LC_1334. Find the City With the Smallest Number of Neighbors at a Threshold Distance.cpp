class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for(auto i:edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }

        for(int i=0;i<n;i++) dist[i][i]=0;
        // Floyed Warshell Striver G-42 43 
        for(int i=0;i<n;i++){ //i ke through check karna for j and k pehle j to i then i to k
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]==INT_MAX||dist[i][k]==INT_MAX){
                        continue;
                    }
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        int res=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=th){
                    cnt++;
                }
            }
            if(cnt<=ans){
                ans=cnt;
                res=i;
            }
        }
        return res;
    }
};