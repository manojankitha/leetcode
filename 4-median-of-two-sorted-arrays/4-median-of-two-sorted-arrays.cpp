#include <math.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i =0,j=0;
        vector<int> out;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                out.push_back(nums1[i]);
                i++;
            }else{
                 out.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            out.push_back(nums1[i]);
            i++;
        }
         while(j<n2){
            out.push_back(nums2[j]);
            j++;
        }
        for(int i = 0;i<n1+n2;i++){
            cout <<out[i]<<" ";
        } 
        int m = out.size();
        if(m%2==1){
            return out[floor(m/2)];
        }else{
            return double((out[floor(m/2)]+out[floor(m/2)-1]))/2;
        }
        
    }
};