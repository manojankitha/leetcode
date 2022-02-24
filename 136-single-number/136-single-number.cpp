class Solution {
public:
    int singleNumber(vector<int>& nums) {
      
        
        int xord = nums[0] ;
            if (nums.size() == 1){
                return xord;
            }
        for(int i=1;i<nums.size();i++){
            xord^=nums[i];
        }
        return xord;
        
    }
};