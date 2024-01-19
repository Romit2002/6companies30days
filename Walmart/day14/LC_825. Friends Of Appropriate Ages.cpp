class Solution {
public:
    int numFriendRequests(vector<int>& age) {
        map<int,int>mp;
        for(auto i:age){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            int x=i.first;
            for(auto j:mp){
                int y=j.first;
                bool flag=0;
                if(y<=((0.5*x)+7) || (y>x) || ((y>100)&&x<100)){
                    flag=1;
                }
                if(flag==0){
                    if(x==y){
                        if(j.second>1)
                            ans+=(j.second*(i.second-1)); //banda apne apko frnd req send nehi kar shakta so baki jitne bhi same age k ha. So -1 karna padega
                    }
                    else
                    ans+=(j.second*i.second);

                }

                if(x==y){
                    break;
                }
                
                if(y==x){
                    break;
                }
            }
        }
        return ans;
    }
};