class Solution {
public:
    int maxDiff(int num) {
        auto x=to_string(num);
        int i=0;
        while(i<x.size()&&x[i]=='9')i++;
        if(i<x.size()){
        auto cur=x[i];
        for(auto &j:x){
            if(j==cur)j='9';
        }
        }
        auto y=to_string(num);
        i=0;
        while(i<y.size()&&(y[i]=='1'||y[i]=='0'))i++;
        
        if(i<y.size()){
            auto cur=y[i];
            for(auto &j:y){
                if(j==cur&&i!=0)j='0';
                else if(j==cur)j='1';
            }
        }
        cout<<stoi(x)<<" "<<stoi(y);
        return stoi(x)-stoi(y);
    }
};