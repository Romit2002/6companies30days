class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0,curr=0;
        int st=0;
        for(int i=0;i<s.size();i++){
            int diff=abs(s[i]-t[i]);

            curr+=diff;
            if(curr>maxCost){
                while(st<=i && curr>maxCost){
                    int d=abs(s[st]-t[st]);
                    curr-=d;
                    st++;
                }
            }
            ans=max(ans,i-st+1);
        }

        return ans;
    }
};

// Normal sliding window use