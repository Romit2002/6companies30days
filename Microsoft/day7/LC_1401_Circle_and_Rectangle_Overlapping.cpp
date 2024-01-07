class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {

        if(x>=x1 && y>=y1 && y<=y2 && x<=x2){
            return 1;
        }
        long long disL=abs(x1-x)*abs(x1-x)+abs(y1-y)*abs(y1-y);
        long long disR=abs(x2-x)*abs(x2-x)+abs(y2-y)*abs(y2-y);

        if(disL<disR){
            for(int i=x1;i<=x2;i++){
                long long d=abs(i-x)*abs(i-x)+abs(y1-y)*abs(y1-y);
                if(d<=(r*r)){
                    return 1;
                }
            }
            for(int i=y1;i<=y2;i++){
                long long d=abs(x1-x)*abs(x1-x)+abs(i-y)*abs(i-y);
                if(d<=(r*r)){
                    return 1;
                }
            }
        }
        else{
            for(int i=x2;i>=x1;i--){
                long long d=abs(i-x)*abs(i-x)+abs(y2-y)*abs(y2-y);
                if(d<=(r*r)){
                    return 1;
                }
            }
            for(int i=y1;i<=y2;i++){
                long long d=abs(x2-x)*abs(x2-x)+abs(i-y)*abs(i-y);
                if(d<=(r*r)){
                    return 1;
                }
            }
        }

        return 0;
    }
};