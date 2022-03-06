class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        // we know that our uniqueSet has to be of max length 2
        int start,end;
        int stringLen = s.length();
        unordered_set<char> uniqueSet;
        int lenLongestSubString=0;
        unordered_map<char,int> freq;
        
       if(stringLen<=2){
           return stringLen;
       }
      
        
        for(start=0,end=0;start<=end && end<stringLen;end++){
            
          if (uniqueSet.find(s[end])==uniqueSet.end()){
                while(uniqueSet.size()==2){
                    // I need to increment start
                    if(freq[s[start]]==1){
                        // if freq is currently one, if we remove this element from sliding window we                           need to remove from freq map and uniqueSet
                        freq.erase(s[start]);
                        uniqueSet.erase(s[start]);
                    }else{
                        // just decrement freq in this case
                        freq[s[start]]--;
                    }
                    start++;
                }      
                uniqueSet.insert(s[end]);
                freq[s[end]]=1;
            } else{
                
                freq[s[end]]++;
            }
            
                       
            if(end-start+1 >=lenLongestSubString){
                lenLongestSubString = end-start+1;
            }
                
        }     
        return lenLongestSubString;  
    }
};