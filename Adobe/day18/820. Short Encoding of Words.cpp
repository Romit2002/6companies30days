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
        vector<string>pq;
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

        void solveUtil(TrieNode *p,string temp){
            bool flag=0;
            for(int i=0;i<26;i++){
                if(p->children[i]!=NULL){
                    temp.push_back(p->children[i]->ch);
                    solveUtil(p->children[i],temp);
                    temp.pop_back();
                    flag=1;
                }
            }
            if(p->isFinal && !flag){
                pq.push_back(temp);
            }
        }

        void solve(){
            TrieNode *p=root;
            solveUtil(p,"");

        }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        Trie root;
        for(auto i:w){
            string o=i;
            reverse(o.begin(),o.end()); //reverse kiya bcz suffix common match karna tha
            root.addWord(o);
        }
        root.solve();
        int ans=0;
        for(auto i:root.pq){
            cout<<i<<endl;
            ans+=i.size();
            ans++;
        }

        return ans;
    }
};