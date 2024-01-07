class Solution {
public:
    string getHint(string s, string g) {
        map<char,set<int>>mp;
        map<char,int>c;

        for(int i=0;i<s.size();i++){
            mp[s[i]].insert(i);
        }
        int cow=0;
        int bull=0;
        for(int i=0;i<g.size();i++){
            if(mp.find(g[i])!=mp.end()){
                set<int>sp=mp[g[i]];
                if(sp.size()==0){
                    continue;
                }
                if(sp.find(i)!=sp.end()){
                    sp.erase(sp.find(i));
                    mp[g[i]]=sp;
                    bull++;
                }
                else{
                    int tp=-1;
                    for(auto j:sp){
                        if(j<i){
                            tp=j;
                            break;
                        }
                    }
                    if(tp!=-1){
                    sp.erase(sp.find(tp));
                    cow++;
                        mp[g[i]]=sp;
                    }
                    else
                    c[g[i]]++;
                }
            }
        }
        
        for(auto i:c){
            if(mp.find(i.first)!=mp.end()){
                set<int>kk=mp[i.first];
                int k=kk.size();
                cow+=min(i.second,k);
            }
        }


        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};