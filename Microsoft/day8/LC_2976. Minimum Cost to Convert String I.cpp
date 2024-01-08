class Solution {
public:
    map<char,long long> solve(char i,map<char,vector<pair<int,char>>>&adj){
        priority_queue<pair<long long,char>,vector<pair<long long,char>>,greater<pair<long long,char>>>pq;
        map<char,long long>mp;
        for(char i='a';i<='z';i++){
            mp[i]=LLONG_MAX;
        }
        pq.push({0,i});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            for(auto j:adj[it.second]){
                if(mp[j.second]>(it.first+j.first)){
                    mp[j.second]=it.first+j.first;
                    pq.push({mp[j.second],j.second});
                }
            }
        }
        return mp;
    }

    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        map<char,vector<pair<int,char>>>adj;
        long long ans=0;
        for(int i=0;i<o.size();i++){
            adj[o[i]].push_back({cost[i],c[i]});
        }

        map<char,map<char,long long>>minCost;
        for(char i='a';i<='z';i++){
            minCost[i]=solve(i,adj);
        }


        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                if(minCost[s[i]][t[i]]==LLONG_MAX){
                    return -1;
                }
                ans+=minCost[s[i]][t[i]];
            }
        }
        return ans;
    }
};
