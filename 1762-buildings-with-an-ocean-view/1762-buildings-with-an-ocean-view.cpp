class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> out;
        stack<int> build;
       for(int j=heights.size()-1;j>=0;j--){
          while(!build.empty() && build.top()<heights[j]){
             build.pop();
          }
           if(build.empty()){
               out.push_back(j);
           } 
           build.push(heights[j]);   
       }
        
       reverse(out.begin(),out.end());
        return out;
    }
};