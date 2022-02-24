class Solution {
public:
    int singleNumber(vector<int>& nums) {
      
        
        int xord = 0 ;
           
        for(int i=0;i<nums.size();i++){
            xord^=nums[i];
        }
        return xord;
        
    }
};