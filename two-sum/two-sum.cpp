class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        map<int,int> mp;
     
        for(int itr=0;itr<nums.size();++itr){
            if(mp.find(nums[itr])!=mp.end()){
                sol.push_back(mp[nums[itr]]);
                sol.push_back(itr); 
            }
             mp[target-nums[itr]] = itr;
          
        }
        return sol;
        
    }
};