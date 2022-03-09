class Solution {
public:
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        unordered_map<string,vector<string>> mp;
        for (string str:strs){
            string temp = str;
            sort(str.begin(),str.end());
            mp[str].push_back(temp);
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            out.push_back(it->second);
        }
       return out;
    }
  
};