class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x)return x;

        return parent[x]=find(parent[x]);
    }
    void unionbyrank(int u,int v){
        if(u>v){
            parent[u]=v;
        }else parent[v]=u;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++)parent[i]=i;
        for(int i=0;i<s1.size();i++){
            char u=s1[i];
            char v=s2[i];
            int ind1=u-'a';
            int ind2=v-'a';
            int up=find(ind1);
            int uv=find(ind2);
            if(up!=uv){
                unionbyrank(up,uv);
            }
        }
        string ans;
        for(auto i:baseStr){
            int x=find(i-'a');
            auto xx='a'+x;
            ans.push_back(xx);
        }
        return ans;
    }
};