class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;
        if(x==y){
            ans=x+y+z;
        }
        else if(x<y){
            ans=x+x+1+z;
        }
        else{
            ans=y+y+1+z;
        }
        return ans*2;
    }
};