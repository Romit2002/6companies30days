// Take Consequitive maximum of v and h.
// ans=min(h,v)^2
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int cnt=1,prev=1,maxiH=1;
        for(int i=1;i<h.size();i++){
            
            if(h[i-1]+1==h[i]){
                cnt++;
                prev=h[i];
                maxiH=max(cnt,maxiH);
                continue;
            }
            maxiH=max(cnt,maxiH);
            prev=h[i];
            cnt=1;
        }
        cout<<maxiH<<endl;
        cnt=1;
        prev=1;
        int maxiV=1;
        for(int i=1;i<v.size();i++){
            
            if(v[i-1]+1==v[i]){
                cnt++;
                prev=v[i];
                maxiV=max(cnt,maxiV);

                continue;
            }
            maxiV=max(cnt,maxiV);
            prev=v[i];

            cnt=1;
        }
        cout<<maxiV<<endl;

        int ans=min(maxiH+1,maxiV+1);

        return ans*ans;


        
    }
};