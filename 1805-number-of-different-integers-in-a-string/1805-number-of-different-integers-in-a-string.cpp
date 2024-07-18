class Solution {
public:
    int numDifferentIntegers(string wor) {
        unordered_set<string>st;
        string word="";
        int flag=0;
        for(int i=0;i<wor.length();i++){
            if(isdigit(wor[i])){
                if(wor[i]=='0'&&word.length()==0&&i<wor.length()-1&&!isdigit(wor[i+1])){word+='0'; flag=1;continue;}
                if(wor[i]=='0'&&word.length()==0){continue;}
                word+=wor[i];
                flag=1;
                continue;
            }
            else{
                if(flag)
                st.insert(word);
                flag=0;
                word="";
            }
        }
        if(flag){
            st.insert(word);
        }
        return st.size();
    }
};