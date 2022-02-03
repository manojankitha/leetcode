class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void sortColors(vector<int>& nums) {
        
        int p0=0,p2=nums.size()-1,curr=0;
        while(curr<=p2){
            if(nums[curr]==2){
                swap(nums[curr], nums[p2]);
                p2-=1;
              
            } else if(nums[curr]==0){
                swap(nums[curr],nums[p0]);
                p0++;
                curr++;
            } else if(nums[curr]==1){
                curr++;
            }
        }
        
        
    }
};