class Solution {
public:
    bool isVowel(char x){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            return true;
        } else{
            return false;
        }
    }
    string reverseVowels(string s) {
        vector<char>x;
        for(int i=0;i<s.length();i++){
            if(isVowel(tolower(s[i]))){
                x.push_back(s[i]);
            }
        }
        reverse(x.begin(),x.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(tolower(s[i]))){
                 s[i]=x[j];
                 j++;
            }
        }
        return s;
    }
};