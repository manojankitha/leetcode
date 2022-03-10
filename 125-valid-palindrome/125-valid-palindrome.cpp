#include<regex>
class Solution {
public:
    
    // TC: O(N)
    // SC:O(1)
        bool isPalindrome(string s) {
         int start=0,end=s.length()-1;
            while(start<end){
                while(start<end && isalnum(s[start])==false){
                    start++;
                }
                while(start<end && isalnum(s[end])==false){
                    end--;
                }
                if(start>end){
                    return false;
                }
                if(tolower(s[start])!=tolower(s[end])){
                    return false;
                }
                start++;
                end--;
                
            }
          
             return true;
          
        }
    
  

};