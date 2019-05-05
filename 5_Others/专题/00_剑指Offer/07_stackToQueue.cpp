class Solution
{
public:
    void push(int node) {
        stack1.push(node);//追加的元素都放在stack1后面
    }
    int pop() {
        if(stack1.empty()&&stack2.empty())throw new exception("queue is empty!");//没有任何元素
        if(stack2.empty()){//反向栈中为空，将stack1中元素“倒”入stack2中
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();//取反向栈顶元素
        stack2.pop();
        return res;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};