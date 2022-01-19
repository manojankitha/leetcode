class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto it= max_element(nums.begin(),nums.end());
        return (it-nums.begin());
    }
};