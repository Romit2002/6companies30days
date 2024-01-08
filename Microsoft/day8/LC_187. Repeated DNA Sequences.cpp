class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string,int>mp;
        string temp="";
        for(int i=0;i<10;i++){
            temp+=s[i];
        }
        mp[temp]++;

        for(int i=10;i<s.size();i++){
            temp=temp.substr(1);
            temp+=s[i];
            mp[temp]++;
        }

        for(auto i:mp){
            if(i.second>1)
            ans.push_back(i.first);
        }
        return ans;
    }
};