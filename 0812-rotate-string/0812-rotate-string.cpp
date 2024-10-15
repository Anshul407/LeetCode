class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return 0;
        if(s==goal)return 1;
        for(int i=0;i<s.length();i++){
            if(s[i]==goal[0]){
                int p=i,q=0;
                while(p<s.length()&&q<s.length()&&s[p]==goal[q]){
                    p++;
                    q++;
                }

                cout<<s.substr(0,i+1)<<" "<<goal.substr(q+1);
                if(s.substr(0,i)==goal.substr(q))return 1;
            }
        }
        return 0;
    
    }
};