class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       return binarySearch(nums,0,nums.size()-1);
    }
    
    int binarySearch(vector<int>& nums, int low, int high){
      if (low==high){
          return low;
      }
            int mid = (low+high)/2;
        
            if(nums[mid]>nums[mid+1]){
               return binarySearch(nums, low,mid);
            }
            return binarySearch(nums,mid+1,high);
           
        
       
    }
};