class Solution {
public:
    
    // TC:O(N)
    // SC:O(N) - worst case
//     bool isAnagram(string s, string t) {
//         unordered_map<char,int> mpS;
//         unordered_map<char,int> mpT;
//         if(s.length()!=t.length()){
//             return false;
//         }
//         for(int i=0;i<s.length();i++){
//             mpS[s[i]]++;
//             mpT[t[i]]++;        
//         }

//         if(mpS!=mpT){
//             return false;
//         }
//         return true;
        
//     }
    
    
      bool isAnagram(string s, string t) {
        // since it is mentioned that it is just alphabets - lower case
         int arr[26] = { };
       
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
                 
        }

        for(int count:arr){
            if(count!=0){
                return false;
            }
        }
        
        return true;
        
    }
    
    
    
};