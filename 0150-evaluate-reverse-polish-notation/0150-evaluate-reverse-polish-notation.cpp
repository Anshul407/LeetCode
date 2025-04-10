class Solution {
public:
    int solve(int a,int b,string x){
        if(x=="+")return a+b;
        else if(x=="-")return a-b;
        if(x=="*")return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i][0]-'0'>=0&&tokens[i][0]-'0'<=9||(tokens[i][0]=='-'&&tokens[i].size()>1)){
                st.push(stoi(tokens[i]));
            }else{
                auto cur1=st.top();
                st.pop();
                auto cur2=st.top();
                st.pop();
                st.push(solve(cur2,cur1,tokens[i]));
                cout<<st.top()<<" ";
            }
        }return st.top();
    }
};