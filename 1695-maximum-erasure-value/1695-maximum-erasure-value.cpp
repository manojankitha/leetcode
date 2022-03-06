class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
    unordered_set<int> uniqueSet;
        
        int curSum=0;
       int maxSum=0;
        int start,end;
        for(start=0,end=0;start<=end && end<nums.size();end++){
            if (uniqueSet.find(nums[end])==uniqueSet.end()){
                // insert
                uniqueSet.insert(nums[end]);
                curSum+=nums[end];
                if(maxSum<curSum){
                    maxSum=curSum;
                }
            } else {
                while(nums[start]!=nums[end]){
                    uniqueSet.erase(nums[start]);
                    curSum-=nums[start];
                    start++;
                }
                start++;
            }
        }
        return maxSum;
        
        
    }
};