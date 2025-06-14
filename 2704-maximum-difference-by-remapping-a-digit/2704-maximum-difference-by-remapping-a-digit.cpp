class Solution {
public:
    int minMaxDifference(int num) {
        int i=0;
        string x=to_string(num);
        string y=x;
        while(i<x.size()&&x[i]=='9')i++;
        
        if(i<x.size()){
        auto cur=x[i];
        for(int i=0;i<x.size();i++){
            if(x[i]==cur)x[i]='9';
        }
        }
        auto cur=y[0];
        for(int i=0;i<x.size();i++){
            if(y[i]==cur)y[i]='0';
        }
        cout<<x<<" "<<y;
        return stoi(x)-stoi(y);
    }
};