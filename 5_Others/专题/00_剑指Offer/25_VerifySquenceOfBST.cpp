class Solution {
    bool judge(vector<int>& ve,int lhs,int rhs){
        if(lhs>=rhs)return true;
        int i = rhs;//rhs应该为该子树的根节点            
        while(i>lhs&&ve[i-1]>ve[rhs])--i;//找到属于左右子树分界点
        for(int j=lhs;j<i;j++)if(ve[j]>=ve[rhs])return false;//左子树的每个节点都应该比根节点小
        return judge(ve,lhs,i-1)&&judge(ve,i,rhs-1);//递归判断左右子树是否满足条件
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())return false;
        return judge(sequence,0,sequence.size()-1);
    }
};
