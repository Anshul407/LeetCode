class Solution {
public:
    bool dif(int x,int y){
       
        if(x>0&&y<0)return 1;
        return 0;
    }
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        for(auto i:ast){
            if(!st.empty()&&dif(st.top(),i)){
                int flag=1;
                while(!st.empty()&&abs(i)>=abs(st.top())&&dif(st.top(),i)){
                    if(abs(i)==abs(st.top())){
                        st.pop();
                        flag=0;
                        break;
                    }else
                    st.pop();
                }
                if(st.empty()&&flag)st.push(i);

                else if(!st.empty()&&!dif(st.top(),i)&&flag)st.push(i);
            }else{
                st.push(i);
            }
            
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};