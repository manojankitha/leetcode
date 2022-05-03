class Solution {
public:
    // TC:O(N) 
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,stringLen = s.length();
        int lenLongestSub = 0;
        unordered_set<char> uniqueSet;
        unordered_map<char,int> freq;
        
        for(start=0,end=0;start<=end && end<stringLen;end++){
            while (uniqueSet.find(s[end])!=uniqueSet.end()){
              // repeat char
                if(freq[s[start]]==1){
                    freq[s[start]]=0;
                    uniqueSet.erase(s[start]);
                } else {
                    freq[s[start]]--;
                }
                start++;
                
            } 
                 // new unique char
                uniqueSet.insert(s[end]);
                freq[s[end]]++;
            
            
            
            if(end-start+1 > lenLongestSub){
                lenLongestSub = end-start+1;
            }
        }
        return lenLongestSub;
    }
};