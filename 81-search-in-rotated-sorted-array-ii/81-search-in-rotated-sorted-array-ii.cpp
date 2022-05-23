class Solution {
public:
    bool search(vector<int>& nums, int target) {
         
        int start=0;
        int end = nums.size()-1;
         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){// if we find target
                return true;
            }
            else if(nums[mid]==nums[end]&&nums[mid]==nums[start]){// to avoid conflict 
                end--;
                start++;
            }
            else if(nums[mid]>=nums[start]){// if left array is sorted
                if(target>=nums[start]&&target<=nums[mid]){// if target is in the range of start--to--mid
                    end=mid-1;
                }
                else{// else we find in the range of mid---to---end
                    start=mid+1;
                }
            }
            else{// if right array is sorted 
               if(target>=nums[mid]&&target<=nums[end]){// if target is in the of mid---to---right
                   start=mid+1;
                }
                else{// then we search in left range
                    end=mid-1;
                }
            }
        }
//         while(start<=end){
          
//             while(start< end && nums[start]==nums[start+1]) {start++;}
//             while( start < end && nums[end]==nums[end-1]) {end--;}
          
//             int mid = start+(end-start)/2;
//             if(nums[mid]==target){
//                 return true;
//             }
//             else if (nums[mid]>= nums[start]){
//                 // first section
//                 if(target > nums[mid] || target<nums[start]){
//                     start=mid+1;
//                 } else {
//                     end=mid-1;
//                 }    
//             } else {
//                if(target < nums[mid] || target> nums[end]){
//                     end=mid-1;
//                 } else {
//                     start=mid+1;
//                 }  
//             }
//         }   
        return false;
        
    }
};