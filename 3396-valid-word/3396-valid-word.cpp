class Solution {
public:
    bool check1(char x){
        x=tolower(x);
        return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
    }
    bool isValid(string word) {
        if(word.size()<3)return 0;
        auto cond1=0,cond2=0;
        for(auto i:word){
            if(!iswalnum(i))return 0;
            if(isalpha(i)==0)continue;
            cond1|=check1(i);
            cond2|=!(check1(i));
        }
        return cond1&&cond2;
    }
};