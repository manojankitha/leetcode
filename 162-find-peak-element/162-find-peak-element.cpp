class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      return binarySearch(nums,0,nums.size()-1);
    }
    
   int binarySearch(vector<int>& nums, int left,int right){
       if(left==right){
           return left;
       }
    
           int mid = left+(right-left)/2;
           if(nums[mid]>nums[mid+1]){
               return binarySearch(nums,left,mid);
           } 
        return binarySearch(nums,mid+1,right);
           
       
   }
    
    // Linear solution O(N)
     // int findPeakElement(vector<int>& nums) {
     //    for(int i=0;i<nums.size()-1;i++){
     //        if(nums[i]>nums[i+1]){
     //            return i;
     //        }
     //    }
     //     return nums.size()-1;
     // }
};