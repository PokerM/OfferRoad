  #include <iostream>
  #include <vector>
  
  using namespace std;

  class Solution {
    public:
        //思路：维持一个高度严格递增的下标数组，其宽度通过当前与前一个下标的差来得到
        int largestRectangleArea(vector<int> &height) {
            
            int ret = 0;
            height.push_back(0);//小技巧：当前
            stack<int> index;//存放当前可能的下标，对应高度为升序排列，其相邻两个下标间对应着横坐标
            
            for(int i = 0; i < height.size(); i++)
            {
                while(index.size() > 0 && height[index.top()] >= height[i])//当前高度不高于之前高度，需要将高于当前高度的值取出来，因为后面不可能用到比当前高度大的值
                {
                    int h = height[index.top()];//将下标数组最后一个元素取出
                    index.pop();
                    
                    int sidx = index.size() > 0 ? index.top() : -1;//sidx为取出元素的前一个元素值
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);//计算高度
                }
                index.emplace_back(i);//当前下标放入数组中，此时数组中所有下标对应高度都比当前高度低，且高度值严格按照升序排列
            }
            return ret;
        }
    };

int main()
{
    int a[]={6,5,4,3,2,1};
    vector<int> ve;
    for(int i=0;i<6;i++)ve.push_back(a[i]);
    Solution so;
    int res = so.largestRectangleArea(ve);
    cout<<res;
//    pair<int,int> a(1,2);
//    cout<<a.first<<" "<<a.second;
    return 0;
}