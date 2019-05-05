class Solution {
private:
    stack<int> s;
    int min_num;
public:
    void push(int value) {
        if(s.empty()){
            min_num = value;
        }
        else{
            min_num = min_num<value?min_num:value;
        }
        s.push(value);
    }
    void pop() {
        if(s.empty())return;
        if(s.top()==min_num){
            s.pop();
            if(!s.empty()){
                stack<int> t(s);
                min_num = t.top();
                t.pop();
                while(!t.empty()){
                    min_num = min_num<t.top()?min_num:t.top();
                    t.pop();
                }
            }
        }
        else{
            s.pop();
        }
    }
    int top() {
        return s.top();
    }
    int min() {
        return min_num;
    }