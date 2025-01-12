class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0)return 0;
        stack<int>st;
        stack<int>temp;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0')temp.push(i);
            else if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }else if(!temp.empty())temp.pop();
                else if(temp.empty())return 0;
            }
        }
        while(!st.empty()&&!temp.empty()){
            auto x= st.top();
            auto y= temp.top();
            if(x<y){
                st.pop();
                temp.pop();
                continue;
            }
            else return 0;
        }
        return st.empty();

    }
};