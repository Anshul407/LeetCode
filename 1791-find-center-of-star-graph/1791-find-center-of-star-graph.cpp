class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int size=mp.size();
        vector<int>ind(size+1,0);
        vector<int>out(size+1,0);
        for(auto i:edges){
            ind[i[0]]++;
            ind[i[1]]++;
            out[i[0]]++;
            out[i[1]]++;
        }
        for(int i=1;i<=size;i++){
            if(ind[i]==size-1&&out[i]==size-1)return i;
        }
        return -1;
    }
};