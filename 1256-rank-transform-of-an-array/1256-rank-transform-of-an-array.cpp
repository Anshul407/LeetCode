class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        set<int>f;
        for(auto i:arr)f.insert(i);
        int j=1;
       for(auto i:f){
           mp[i]=j;
           j++;
       }
        for(auto &i:arr){
            i=mp[i];
        }
        return arr;
    }
};