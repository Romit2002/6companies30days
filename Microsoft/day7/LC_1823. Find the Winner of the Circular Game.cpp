class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1){
            return 1;
        }
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int st=0;
        int p=k;
        int q=n;
        while(p--)
        {
            if(v[st]==-1){
                p++;
            }
            
            if(p==0){
                v[st]=-1;
                q-=1;
                if(q==1){
                    break;
                }
                p=k;
            }
            st=(st+1)%n;
        }

        for(auto i:v){
            if(i>-1){
                return i;
            }
        }


        return -1;
    
    }
};