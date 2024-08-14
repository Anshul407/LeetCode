class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long>ind(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            ind[edges[i]]+=i;
        }
        long long sc=0;
        int e=-1;
        for(int i=0;i<edges.size();i++){
            if(sc<ind[i]){
                sc=ind[i];
                e=i;
            }
        }
        return e;

    }
};