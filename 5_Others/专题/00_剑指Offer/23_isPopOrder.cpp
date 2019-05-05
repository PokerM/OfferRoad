class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int i=0;
        for(auto const p : pushV){//按照push的顺序，加到stack中(除中途pop出来的外)
            if(p == popV[i]){
                i++;
            }
            else{
                s.push(p);
            }
        }
        while(!s.empty()){//剩下的数字应该按顺序pop出来，若顺序不对，则返回false
            if(popV[i]==s.top()){
                i++;
                s.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};