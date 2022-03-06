class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start,end;
        int stringLen = s.length();
        unordered_set<char> uniqueSet;
        int lenLongestSubString=0;
        if(stringLen<=1){
            return stringLen;
        }
        for (start=0,end=0;(start<=end && end<s.length());end++){
            while(uniqueSet.find(s[end])!=uniqueSet.end()){
              
                uniqueSet.erase(s[start]);
                start++;
            }
            uniqueSet.insert(s[end]);
            if(end-start+1 >=lenLongestSubString){
                lenLongestSubString = end-start+1;
            }
            
        }
        return lenLongestSubString; 
        
    }
};