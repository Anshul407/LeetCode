class Solution {
public:
    bool isBalanced(string num) {
        int odd=0;
        int ev=0;
        for(int i=0;i<num.size();i+=2){
            ev+=(num[i]-'0');
        }
        for(int i=1;i<num.size();i+=2){
            odd+=(num[i]-'0');
        }
        return odd==ev;
    }
};