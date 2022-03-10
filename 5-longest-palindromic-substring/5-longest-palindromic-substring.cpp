class Solution {
public:
    
    
//     // TC: O(N)
//     // SC:O(1)
//         bool isValidPalindrome(string s) {
//          int start=0,end=s.length()-1;
//             while(start<end){
//                 while(start<end && isalnum(s[start])==false){
//                     start++;
//                 }
//                 while(start<end && isalnum(s[end])==false){
//                     end--;
//                 }
//                 if(start>end){
//                     return false;
//                 }
//                 if(tolower(s[start])!=tolower(s[end])){
//                     return false;
//                 }
//                 start++;
//                 end--;
                
//             }
          
//              return true;
          
//         }
//     // TC: O(N^3)
//     // SC:O(1)
//      string longestPalindrome(string s) {
//          string longestPalindrome="";
//          if(s.length()<=1){
//              longestPalindrome = s;
//              return longestPalindrome;
//          }
//          int longestLen = 0;
         
//        int start=0;
//          while(start<=s.length()){
//              int end=start;
//              while(end<s.length()){
//                  if(isValidPalindrome(s.substr(start,end-start+1))){
//                      if(end-start+1 >longestLen){
//                          longestLen = end-start+1;
//                          longestPalindrome = s.substr(start,end-start+1);
//                      }
//                  }
//                  end++;
//              }
//              start++;
//          }
//          return longestPalindrome;
         
//      }
    
    
        // TC: O(N^2)
        // SC: O(1)
         string longestPalindrome(string s) {
            string sub = "";
             
             if(s=="" || s.length()<=1){
                 return s;
             }
             for(int i=0;i<s.length();i++){
                string case1 = expandFromMiddle(s,i,i);
                 string case2 = expandFromMiddle(s,i,i+1);
                  string longStr = case1.length() > case2.length() ? case1 : case2;
                if (longStr.length() > sub.length()) {
                    sub = longStr;
                }
             }
       return sub;
             
             
         }
    
        string expandFromMiddle(string s, int left, int right){
            if(left>right || s==""){
                return 0;
            }
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            
            int begIndex = left+1;
            int length = right-left+1-2;
            return s.substr(begIndex,length);
            
        }
    
        
             

};

