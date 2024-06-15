class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
          vector<pair<int, int>> projects;
    for (int i = 0; i < profits.size(); ++i) {
        projects.emplace_back(capital[i], profits[i]);
    }
    
    // Step 2: Sort projects by the capital required in ascending order
    priority_queue<int>q;
    int iterator=0;
    sort(projects.begin(), projects.end());
    for(int i=0;i<k;i++){
        
        while(iterator<projects.size()&&projects[iterator].first<=w){
            q.push(projects[iterator].second);
            iterator++;
        }
     
        
        
        if(q.size()==0)break;
        w+=q.top();
        q.pop();
    }
    return w;
    
    }
};