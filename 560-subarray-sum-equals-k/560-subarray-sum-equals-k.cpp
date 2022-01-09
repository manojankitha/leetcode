class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
        
        /* Requirements
        <param name="nums"> vector of integers (negative included) </param>
        <param name="k"> desired sum </param>
        <returns> total number of contiguous subarrays </returns>
        */
        
        /*corner cases: 
        1. nums - empty array, all negative, all positive, all 0
        2. k - negative, positive, 0
        */
        
        /*Analysis:
        Approach 1: Brute Force TC:O(n^2)  SC:O(1)
            1. find all possible subarrays
            2. Check if sum == k
            3. Increment count of totalSubarrays.
        
        Approach 2: Prefix Sum TC:
        
         */
        
        ///<code>
        int totalSubarrays = 0;
        int n = nums.size();
        unordered_map<int,int> mp; int prefix_sum=0;
        mp.insert(make_pair(0,1));
        
        for(int i=0;i<n;i++){
            prefix_sum = prefix_sum + nums[i];
            
            if(mp.find(prefix_sum-k)!=mp.end()){
                totalSubarrays = totalSubarrays + mp[prefix_sum-k];
                
            }
            mp[prefix_sum]++;
            
        }
        return totalSubarrays;
    
        ///</code>
        
    }
};