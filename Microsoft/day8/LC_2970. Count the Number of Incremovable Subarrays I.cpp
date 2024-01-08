class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt=0;
        
        // }
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                bool flag=1;
                int prev=-1;
                for(int k=0;k<nums.size();k++){
                    if(((k<i)&&(k<j))||((k>i)&&(k>j)) ){
                        if(prev==-1){
                            prev=nums[k];
                            continue;
                        }
                        // else{
                            if(prev>=nums[k]){
                                flag=0;
                                break;
                            }
                            else{
                                prev=nums[k];
                            }
                        // }
                    }
                    
                }
                if(flag){
                        cnt++;
                    }
            }
        }

        // for(int i=nums.size()-1;i>=0;i--){
        //     bool flag=0;
        //     for(int j=0;j<i-1;j++){
        //         if(nums[j]>nums[j+1]){
        //             flag=1;
        //         }
        //     }
        //     if(flag){
        //         cnt++;
        //     }
        // }
        return cnt;
    }
};