class ThroneInheritance {
public:
    string king="";
    map<string,vector<string>> mp;
    map<string,bool> d;
    
    ThroneInheritance(string kingName) {
        king=kingName;
        d[king]=1;
    }

    void solve(string PName, vector<string>& ans) {
    if (d[PName]) {
        ans.push_back(PName);
    }

    for (int i = 0; i < mp[PName].size(); i++) {
        string child = mp[PName][i];
        // if (mp.find(child) != mp.end()) {
            solve(child, ans);
        // }
    }
}

    
    void birth(string pName, string ch) {
       mp[pName].push_back(ch); 
       d[ch]=1;
    }
    
    void death(string name) {
        d[name]=0;
    }
    
    vector<string> getInheritanceOrder() {
        // for(auto i:mp){
        //     cout<<i.first<<" Childs are ";
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }cout<<endl;
        // }
        vector<string> ans;
        solve(king,ans);
        for(auto i:ans){
            cout<<i<<" ";
        }
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */