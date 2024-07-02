class Solution {
public:
    int find(int x,vector<int>&p){
        if(x==p[x])return x;

        return p[x]=find(p[x],p);
    }
    void unionn(int x,int y,vector<int>&p,vector<int>&r){
        int x_p=find(x,p);
        int y_p=find(y,p);
        if(r[x_p]>r[y_p]){
            p[y_p]=x_p;
        }
        else if(r[x_p]<r[y_p]){
            p[x_p]=y_p;
        }else{
            p[x_p]=y_p;
            r[y_p]+=1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        
        vector<int>rank(26,0);
        for(auto it:equations){
            int a=it[0]-'a';
            int b=it[3]-'a';
            char sign=it[1];
            if(sign=='!'){
                if(find(a,parent)==find(b,parent))return false;
            }
            else{
                char parent_a=find(a,parent);
                char parent_b=find(b,parent);
                if(parent_a!=parent_b){
                    unionn(parent_a,parent_b,parent,rank);
                }
            }
        }

        return true;
    }
};