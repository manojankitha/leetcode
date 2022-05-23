class Solution {
public:
    bool search(vector<int>& nums, int target) {
         
        int start=0;
        int end = nums.size()-1;
        while(start<=end){
          
            while(start< end && nums[start]==nums[start+1]) {start++;}
            while( start < end && nums[end]==nums[end-1]) {end--;}
          
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            else if (nums[mid]>= nums[start]){
                // first section
                if(target > nums[mid] || target<nums[start]){
                    start=mid+1;
                } else {
                    end=mid-1;
                }    
            } else {
               if(target < nums[mid] || target> nums[end]){
                    end=mid-1;
                } else {
                    start=mid+1;
                }  
            }
        }   
        return false;
        
    }
};