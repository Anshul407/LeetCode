class Solution {
public:
    bool check(int a){
        auto cur=to_string(a);
        for(auto i:cur){
            if(i=='0')return 0;
        }return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        int f=1;
        while(true){
            if(check(f)&&check(n-f))return {f,n-f};
            f++;
        }return {-1,-1};
    }
};