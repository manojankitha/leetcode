#include "vector"
#include "set"

using namespace std;

class Solution {
public:
   bool binary_search(int x,vector<int>& nums,int low, int high){
       
       if(high>=low){ 
            int mid = low + (high-low)/2;
           
            if(x<nums[mid]){
                return binary_search(x,nums,low,mid-1);
            } else if (x>nums[mid]){
                return binary_search(x,nums,mid+1,high);
            } else if(nums[mid]==x){
                return true;
            }
       }
       return false;
        
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
       unordered_set<int> out;
        if(n1<n2){
            for(auto x:nums1){
                sort(nums2.begin(),nums2.end());
                cout<<x;
                cout << binary_search(x,nums2,0,n2);
                if(binary_search(x,nums2,0,n2)){
                    out.insert(x);
                }
            }
        } else{
           
             for(auto x:nums2){
                 sort(nums1.begin(),nums1.end());
              
                if(binary_search(x,nums1,0,n1)){
                    out.insert(x);    
                }
            }
            
        }
        
        vector<int> v(out.begin(), out.end());
        return v;
        
    }
};