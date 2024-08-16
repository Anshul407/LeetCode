class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> ind(n, 0);
        map<int, vector<int>> mp;

        // Build the adjacency list and calculate the degree of each city
        for (auto i : roads) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
            ind[i[0]]++;
            ind[i[1]]++;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int cur=ind[i]+ind[j];
                for(auto v:mp[i])if(v==j){
                    cur--;
                    break;
                }
                maxi=max(maxi,cur);
            }
        }

        return maxi;
    }
};
