class Solution {
public:
    
    int minimizeXor(int num1, int num2) {
        string a,b;
        bitset<32>binary(num1);
        a=binary.to_string();
        cout<<a;
        int tot=__builtin_popcount(num2);
        for(int i=0;i<a.size();i++){
            if(a[i]=='1'){
                if(tot){
                    tot--;
                    b+='1';
                }else b+='0';
            }else {
                b+='0';
            }
        }
        if(tot){
            for(int i=b.size()-1;i>=0;i--){
                if(b[i]=='0'){
                    if(tot){
                        tot--;
                        b[i]='1';
                    }
                    if(!tot)break;
                }
            }
        }
        int x=stoi(b,0,2);
        return x;

    }
};