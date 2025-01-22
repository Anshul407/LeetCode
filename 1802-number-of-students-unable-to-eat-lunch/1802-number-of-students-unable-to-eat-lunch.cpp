class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        stack<int>st;
        for(auto i:students)q.push(i);
        for(int i=sandwiches.size()-1;i>=0;i--)st.push(sandwiches[i]);
        int f=0;
        while(true){
            int size=q.size();
            int t=1;
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(front==st.top()){
                    st.pop();
                    t=0;
                }else{
                    q.push(front);
                }
            }
            f+=t;
            if(f==2)return q.size();
        }

        return 0;
    }
};