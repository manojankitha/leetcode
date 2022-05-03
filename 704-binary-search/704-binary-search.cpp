class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r=nums.size()-1;
        
        int result = binarySearch(nums,l,r,target);
        return result;
    }
    
    // recursive search
    int binarySearch(vector<int>& nums, int l, int r, int target){
        if(r>=l){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                return binarySearch(nums,mid+1,r,target);
            } else {
                return binarySearch(nums,0,mid-1,target); 
            }
        }
        return -1;
    }
    
    // iterative search
    // int binarySearch(vector<int>& nums, int l, int r, int target){
    //     while(l<=r){
    //         int mid = l+ (r-l)/2;
    //         if(nums[mid]==target){
    //             return mid;
    //         }
    //         if(nums[mid]<target){
    //             l = mid+1;
    //         } else {
    //             r = mid-1;
    //         }
    //     }
    //     return -1;
    // }
    
};