class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        
        for(auto &x:p){
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        int count = 0;
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
           
        }
        for(auto x:indegree){
            cout<<x<<endl;
        }
        if(q.size()==0){
            return false;
        }
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            count++;
            for(auto child:graph[x]){
                 indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                     
                }
                   
            }
        }
        
        if(count==numCourses){
            return true;
        }
        return false;
        
        
        
    }
};