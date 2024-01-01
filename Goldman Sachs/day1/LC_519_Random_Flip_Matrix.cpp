class Solution {
public:
    int M=0,N=0;
    map<pair<int,int>,int>mp;
    Solution(int m, int n) {
        M=m;
        N=n;
    }
    
    vector<int> flip() {
        while(1){
            int x=rand()%M;
            int y=rand()%N;
            if(mp.find({x,y})==mp.end()){
                mp[{x,y}]++;
                return {x,y};
            }
        }

        
    }
    
    void reset() {
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */