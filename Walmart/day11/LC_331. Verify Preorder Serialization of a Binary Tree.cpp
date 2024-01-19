class Solution {
public:
    // Logic is number aye toh push to stack numbers 2-3digit ho shakte ha, so stack of strings
    // # aye toh top check karo, jab tak top # ha do do pop karo stack se. Then # push karo
    // Last me stack size==1 && st.top()=="#" hona chahiye..

    bool isValidSerialization(string p) {
        stack<string>st;

        for(int i=0;i<p.size();i++){
            string temp="";
            while(i<p.size() && p[i]!=','){
                temp+=p[i];
                i++;
            }


            if(temp!="#"){
                st.push(temp);
            }
            else{
                
                while(st.size()>=2 && st.top()=="#"){
                    st.pop();
                    st.pop();
                }
                if(!st.empty() && st.top()=="#"){
                    return 0;
                }
                st.push("#");
            }
        }
        return st.size()==1 && st.top()=="#";
    }
};