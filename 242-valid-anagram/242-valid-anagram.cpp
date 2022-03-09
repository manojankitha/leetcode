class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpS;
        unordered_map<char,int> mpT;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            mpS[s[i]]++;
            mpT[t[i]]++;
                
        }

        if(mpS!=mpT){
            return false;
        }
        return true;
        
    }
};