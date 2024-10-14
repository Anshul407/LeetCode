class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
      
        unordered_map<int,int>mp;
        for(int i=1;i<=matrix.size();i++){
            mp[i]=0;
        }
        for(int i=0;i<matrix.size();i++){
            
            int cur=0;
            for(int j=0;j<matrix[0].size();j++){
                if(mp.find(matrix[i][j])!=mp.end())mp[matrix[i][j]]++;
                else return 0;
               
            }
            for(auto &ii:mp){
                if(ii.second==0)return 0;
                ii.second=0;
            }
            if(cur!=0)return 0;
        }
         for(int i=0;i<matrix[0].size();i++){
            int cur=0;
            for(int j=0;j<matrix.size();j++){
               if(mp.find(matrix[j][i])!=mp.end())mp[matrix[j][i]]++;
                else return 0;
               
            }
            for(auto &ii:mp){
                if(ii.second==0)return 0;
                ii.second=0;
            }
        }
        return 1;

    }
};