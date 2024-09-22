class Solution {
public:
    int maximumSwap(int num) {
        string x=to_string(num);
        int maxi=-1;
        int ind=-1;
        string ans="";
        for(int i=x.size()-1;i>=0;i--){
            if(maxi<x[i]-'0'){
                maxi=x[i]-'0';
                ind=i;
            }
            swap(x[i],x[ind]);
            ans=max(ans,x);
            swap(x[i],x[ind]);

        }

        return stoi(ans);
        
        
    }
};