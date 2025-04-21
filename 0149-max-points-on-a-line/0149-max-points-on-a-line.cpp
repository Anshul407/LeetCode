class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            int s=1;
            unordered_map<double,int>mp;
            int v=0;
            for(int j=i+1;j<points.size();j++){
                double up=points[j][0]-points[i][0];
                double down=points[j][1]-points[i][1];
                if(up==0&&down==0)s++;
                else{
                    if(up!=0){
                        mp[down/up]++;
                    }else v++;
                }    
            }int maxi=v;
        for(auto &i:mp){
            maxi=max(i.second,maxi);
        }ans=max(ans,maxi+s);
            
        }return ans;
        
    }
};