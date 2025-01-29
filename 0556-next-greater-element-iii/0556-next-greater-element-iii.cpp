class Solution {
public:
    
    int nextGreaterElement(int n) {
        long long ans=LLONG_MAX;
        string x=to_string(n);
        for(int i=x.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(x[i]-'0'>x[j]-'0'){
                    swap(x[i],x[j]);
                    ans=min(ans,stoll(x));
                    swap(x[i],x[j]);
                }
            }
        }
        if(ans==LLONG_MAX)return -1;
        x=to_string(ans);
        for(int i=x.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(x[i]-'0'<x[j]-'0'){
                    swap(x[i],x[j]);
                    if(stoll(x)>n)
                    ans=min(ans,stoll(x));
                    swap(x[i],x[j]);
                }
            }
        }   
        if(ans>INT_MAX)return -1;
        string p=to_string(ans);
        for(int i=0;i<p.size();i++){
            if(p[i]!=x[i]){
                sort(p.begin()+i+1,p.end());
                break;
            }
        }

        return stoi(p);
    }

};