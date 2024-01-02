class Solution {
public:
    static bool comp(vector<string>&v1,vector<string>&v2){
        // int p1=stoi(v1[1]);
        // int p2=stoi(v2[1]);

        // return p1<p2;
        return v1[1]<v2[1];
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& ac) {
        sort(ac.begin(),ac.end(),comp);
        set<string>s;
        map<string,int>ans;
        map<string,deque<int>>mp;
        for(int i=0;i<ac.size();i++){
            if(mp.find(ac[i][0])==mp.end()){
                mp[ac[i][0]].push_back(stoi(ac[i][1]));
                ans[ac[i][0]]=1;
            }
            else{
                int prev=mp[ac[i][0]].front();
                int diff=stoi(ac[i][1])-prev;
                if(diff<100){
                    ans[ac[i][0]]++;
                    if(ans[ac[i][0]]>=3){
                        s.insert(ac[i][0]);
                    }
                }
                else
                {
                    mp[ac[i][0]].pop_front();
                    // bool flag=0;
                    ans[ac[i][0]]=1;
                    while(!mp[ac[i][0]].empty()){
                        int prev=mp[ac[i][0]].front();
                        int diff=stoi(ac[i][1])-prev;
                        if(diff<100){
                            ans[ac[i][0]]=2;
                            // flag=1;
                            break;
                        }
                        mp[ac[i][0]].pop_front();
                    }
                    
                }
                    mp[ac[i][0]].push_back(stoi(ac[i][1]));
            }
        }
        vector<string>res;
        for(auto i:ans){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i:s){
            res.push_back(i);
        }
        // for(auto i:ans){
        //     if(i.second>=3){
        //         res.push_back(i.first);
        //     }
        // }
        return res;
    }
};