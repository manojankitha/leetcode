class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start=0,end=0;
        int lenLongestSub = 0;
        int stringLen = s.length();
        if(stringLen<k){
            return stringLen;
        }
        if(k==0){
            return 0;
        }
        
        unordered_set<char> uniqueSet;
        unordered_map<char,int> freq;
        
        for(start=0,end=0;start<=end && end<stringLen;end++){
             if(uniqueSet.find(s[end])==uniqueSet.end()){
                 // new unique character
                 while(uniqueSet.size()==k){
                     if(freq[s[start]]==1){
                         freq[s[start]]=0;
                         uniqueSet.erase(s[start]);
                     } else {
                         freq[s[start]]--;
                     }
                     start++;
                 }
                 uniqueSet.insert(s[end]);
                 freq[s[end]]=1;
             } else {
                 freq[s[end]]++;
             }

             if(end-start+1 >= lenLongestSub){
                 lenLongestSub = end-start+1;
             }    
         }
            return lenLongestSub;
        }  
};