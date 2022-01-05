class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       
        
        
        map<int,int> mp;
        unordered_set<int> s;
        int n = fruits.size();
        if (n <= 2){
            return n ;
        }
        int maxSize = 0;
        for(int start=0,end=0;end<n;end++){
            
            s.insert(fruits[end]);
            mp[fruits[end]]++;
            
            while(s.size()>2){
                if(--mp[fruits[start]] == 0){
                    s.erase(fruits[start]);
                }
                start++;
            }
            if((end-start+1)>=maxSize){
                maxSize = end-start+1;
            }
            
            
        }
        return maxSize;
        
    }
};