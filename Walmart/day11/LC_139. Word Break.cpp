class TrieNode{
    public:
        char ch;
        TrieNode* children[26];
        bool isFinal=0;
        
        TrieNode(char c){
            ch=c;
            isFinal=0;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};

class Trie{
    public:
        TrieNode *root;
        Trie(){
            root=new TrieNode('\0');
        }
        void addWord(string s){
            TrieNode *p=root;
            for(int i=0;i<s.size();i++){
                if(p->children[s[i]-'a']==NULL){
                    
                    p->children[s[i]-'a']=new TrieNode(s[i]);
                    
                    
                }
                if(i==s.size()-1){
                    p->children[s[i]-'a']->isFinal=1;
                    break;
                }
                p=p->children[s[i]-'a'];
                
            }  
        }
        bool fnd=0;
        void solve(string s){
            if(s==""){
                fnd=fnd|1;
                return;
            }
            TrieNode *p=root;

            for(int i=0;i<s.size();i++){
                if(fnd){
                    return;
                }
                if(p->children[s[i]-'a']){
                    p=p->children[s[i]-'a'];
                    if(p->isFinal && i==s.size()-1){
                        fnd=fnd|1;
                        return;
                    }
                    if(p->isFinal){
                        solve(s.substr(i+1));
                    }
                    if(fnd){
                        return;
                    }
                }
                else{
                    return;
                }
            }
        }

        bool solveTab(string s){
            vector<bool>dp(s.size(),0);
            for(int i=0;i<s.size();i++){
                if(i==0||dp[i-1]){
                    TrieNode *p=root;
                    for(int j=i;j<s.size();j++){
                        if(!p->children[s[j]-'a']){
                            break;
                        }
                        p=p->children[s[j]-'a'];
                        if(p->isFinal){
                            dp[j]=1;
                        }
                    }
                }
            }

            return dp.back();
        }
    };



class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        Trie root;
        for(auto i:w){
            root.addWord(i);
        }

        return root.solveTab(s);
        // return root.fnd;
    }
};