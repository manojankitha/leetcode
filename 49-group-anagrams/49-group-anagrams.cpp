class Solution {
public:
    
    // TC: O(NKlogK) where N is strs.size(), K is length of longest string
    // SC: O(NK)
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> out;
//         unordered_map<string,vector<string>> mp;
//         for (string str:strs){
//             string temp = str;
//             sort(str.begin(),str.end());
//             mp[str].push_back(temp);
//         }
        
//         for(auto it=mp.begin();it!=mp.end();it++){
//             out.push_back(it->second);
//         }
//        return out;
//     }
  
     // TC: O(NK) where N is strs.size(), K is length of longest string
     // SC: O(NK)
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> out;
            unordered_map<string,vector<string>> mp;
            for (string str:strs){
                string s="";
                string temp = str;
                int arr[26]={0};
                for(int i=0;i<str.length();i++){
                    arr[str[i]-'a']++;
                }
                for(int j=0;j<26;j++){
                    s+='0'+arr[j];
                    s+='#';
                }
                cout<<s<<endl;
                mp[s].push_back(temp);
              
        }
               for(auto it=mp.begin();it!=mp.end();it++){
            out.push_back(it->second);
        }
       return out;
            
    }
};