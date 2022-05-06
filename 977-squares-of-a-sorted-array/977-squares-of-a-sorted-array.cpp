class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> result(n);
        
        int left=0;
        int right=n-1;
        for(int i=n-1;i>=0;i--){
        
            if(abs(nums[left])<abs(nums[right])){
                result[i]=nums[right]*nums[right];
                    right--;
            } else {
                result[i]=nums[left]*nums[left];
                left++;
            }
        }
        return result;       
    }
};