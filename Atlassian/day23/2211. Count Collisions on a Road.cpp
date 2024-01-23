class Solution {
public:
    int countCollisions(string d) {
        int cnt=0;
        stack<int>st;
        for(auto i:d){
            if(st.empty()){
                st.push(i);
                continue;
            }

            if(st.top()=='S' && i=='L'){
                cnt++;
                continue;
            }

            if(st.top()=='R' && i=='S'){
                while(!st.empty() && st.top()=='R')
                        
                    {
                        cnt++;
                        st.pop();
                    }
                // st.pop();
                st.push(i);
                continue;
            }

            if(st.top()=='R' && i=='L'){
                cnt+=2;
                st.pop();
                while(!st.empty() && st.top()=='R'){
                    cnt++;
                    st.pop();
                }
                st.push('S');
                continue;
            }

            st.push(i);
        }
        return cnt;
    }
};