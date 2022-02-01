class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> merged;
            for(int row=0;row<intervals.size();row++){
                if(merged.empty() || merged.back()[1]<intervals[row][0]){
                    merged.push_back(intervals[row]);
                    
                }else{
                      
                    merged.back()[1] = max(intervals[row][1], merged.back()[1]);
                    
                }
            }
        return merged;
        
    }
};