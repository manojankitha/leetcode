#include<iostream>

class Solution {
public:
    
    bool arrayMatches (vector<int> patternMap, vector<int>wordMap){
        for(int i=0;i<26;i++){
            if(wordMap[i]!=patternMap[i]){
                return false;
            }
        }
         return true;
     }
    bool checkInclusion(string pattern, string word){  
        // find length of pattern and word 
        int patternLen = pattern.length();
        int wordLen = word.length();
        // if len(word)<len(pattern) -> return false
        if(wordLen<patternLen){
            return false;
        }
        // create array of size 26, create freq array for pattern 
        vector<int> patternMap(26,0);
        vector<int> wordMap(26,0);
        
        for(auto s:pattern){
            patternMap[s-'a']++;
         
        }
        cout<<endl;
        // in for loop for length of pattern, create sliding window freq map
     for(int start=0,end=0;start<=end && end<wordLen; end++){
            wordMap[word[end]-'a']++;
            while(end-start+1 > patternLen){
                wordMap[word[start]-'a']--;
                start++;
            }
         
            if(arrayMatches(wordMap,patternMap)){
                return true;
            }
        
        }
            // if ever there is a match in pattern freq array and word freq array, return true
        
        // return false
        return false;
        
    }

    
};