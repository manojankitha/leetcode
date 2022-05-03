class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int,int> mp;
        vector<int> out;
        for(int i=0;i<nums.size();i++){
            if (mp.find(nums[i])!=mp.end()){
                out.push_back(i);
                out.push_back(mp[nums[i]]);
            } else {
                mp[target-nums[i]] = i; 
            }
        }
        return out;
        
    }
};