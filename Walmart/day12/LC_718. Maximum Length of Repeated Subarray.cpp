class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int cnt=0;
        int maxi=0;
        int m=nums1.size();
        int n=nums2.size();
        for(int i=(1-n);i<m;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(i+j<0){
                    continue;
                }
                if(i+j>=m){
                    break;
                }
                if(nums1[i+j]==nums2[j]){
                    cnt++;
                    maxi=max(cnt,maxi);
                }
                else{
                    cnt=0;
                }


            }
        }

        return maxi;
    }
};


/*
suppose two array 1 2 3 4 and 3 4

so main idea is to traverse like outer loop 1-nums2.size() to nums1.size()
                                inner loop 0 to nums2.size();
                                i+j should be>0
                                i+j>m break;
                                check both arrays i+j indx and increase cnt acc/to
traverse like 1 2 3 4
            3 4

            1 2 3 4
            3 4
            
            1 2 3 4
              3 4

            1 2 3 4
                3 4

            1 2 3 4
                  3 4
*/