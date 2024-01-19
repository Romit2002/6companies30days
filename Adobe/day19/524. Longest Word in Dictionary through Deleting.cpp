class Solution {
public:
    static bool comp(string s1,string s2){
        if(s1.size()==s2.size()){
            return s1<s2;
        }
        return s1.size()>s2.size();
    }
    static bool solve(string s,string w){
        if(w.size()>s.size()){
            return 0;
        }

        int i=0;int j=0;

        while(i<s.size() && j<w.size()){
            if(s[i]==w[j]){
                j++;
            }
            i++;
        }

        return j==w.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),comp); //length wise sort karo, length equal ha toh jo lexicographically smaller

        for(auto i:d){
            if(solve(s,i)){ //check if subsequence of s or not
                return i;

            }
        }

        return "";
    }
};