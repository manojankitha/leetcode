#include<iostream>

class Solution {
public:
    
    bool isEqual(int a[], int b[]){
         for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
        
    }
    bool checkInclusion(string pattern, string s){
        int s1 = s.size();
        int p1  = pattern.size();
        if(s1<p1 || s1==0){
            return false;
        }
        if(p1==0){
            return true;
        }
        int pattern_freq[26] = {0};
        int s_freq[26] = {0};
        
        for(int i=0;i<p1;i++){
           pattern_freq[pattern[i]-'a']++;
            s_freq[s[i]-'a']++;
        }
       
       
        for(int start=0,end=p1;end<s1;start++,end++){
             if(isEqual(s_freq,pattern_freq)){
                return true;
            }
            
            s_freq[s[end]-'a']++;
            s_freq[s[end-p1]-'a']--;
            
       
               
        }
        if(isEqual(s_freq,pattern_freq)){
                return true;
            }
    
        return false;
    }
       

    
};