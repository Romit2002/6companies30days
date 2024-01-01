class Solution {
public:
    long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
    int minimizeSet(int d1, int d2, int u1, int u2) {
        // if(uniqueCnt1>=uniqueCnt2){

        // set<int>s,tp;
        // int temp=0;
        // int cnt=1;
        // for(int i=0;i<uniqueCnt1;i++){
        //     while(1){

        //     if(cnt%divisor1){
        //         if(cnt%divisor2){
        //             temp++;
        //         }
        //         s.insert(cnt);
        //         break;
        //     }
        //     else if(cnt%divisor2){
        //         // tp.insert(cnt);
        //         s.insert(cnt);
        //         uniqueCnt2--;
        //     }
        //     cnt++;
        //     }
        //     cnt++;
        // }
        // // int l=0;
        // // for(auto i:s){
        // //     if(l+1==i){
        // //         l=i;
        // //         continue;
        // //     }
        // //     break;
        // // }
        // // cnt=l+1;
        // // uniqueCnt2-=tp.size();
        // for(int i=0;i<uniqueCnt2;i++){
        //     while(1){
                
        //     if(cnt%divisor2!=0 && s.find(cnt)==s.end()){
        //         s.insert(cnt);
        //         break;
        //     }
        //     else if(cnt%divisor2==0 && s.find(cnt)==s.end()){
        //         if(cnt%divisor1 && temp>0){
        //             s.insert(cnt);
        //             temp--;
        //             break;
        //         }
        //     }
        //     cnt++;
        //     }
        //     cnt++;
        // }


        // return *s.rbegin();
        // }
        // else{
        //     set<int>s;
        //     int temp=0;
        //     int cnt=1;
        //     for(int i=0;i<uniqueCnt2;i++){
        //         while(1){

        //         if(cnt%divisor2){
        //             if(cnt%divisor1){
        //                 temp++;
        //             }
        //             s.insert(cnt);
        //             break;
        //         }
        //         cnt++;
        //         }
        //         cnt++;
        //     }
        //     int l=0;
        //     for(auto i:s){
        //         if(l+1==i){
        //             l=i;
        //             continue;
        //         }
        //         break;
        //     }
        //     cnt=l+1;
        //     for(int i=0;i<uniqueCnt1;i++){
        //         while(1){
                    
        //         if(cnt%divisor1!=0 && s.find(cnt)==s.end()){
        //             s.insert(cnt);
        //             break;
        //         }
        //         else if(cnt%divisor1==0 && s.find(cnt)==s.end()){
        //             if(cnt%divisor2 && temp>0){
        //                 s.insert(cnt);
        //                 temp--;
        //                 break;
        //             }
        //         }
        //         cnt++;
        //         }
        //         cnt++;
        //     }


        //     return *s.rbegin();
        // }
        long long ans=1e10;
        long long l=lcm(d1,d2);
        long long low=1;
        long long high=INT_MAX;

        while(low<=high){
            long long mid=low+(high-low)/2;

            long long a=mid-(mid/d1);
            long long b=mid-(mid/d2);

            long long c=mid-(mid/d1)-(mid/d2)+(mid/l);
            if(a>=u1 && b>=u2 && (a+b-c)>=(u1+u2)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return (int)ans;
    }
};