#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
   int subarrayBitwiseORs(vector<int>& A) {
      vector<int> c;
      for (auto i = 0, st = 0, en = 0; i < A.size(); ++i, st = en, en = c.size()) {
        c.push_back(A[i]);
        cout<<A[i]<<" ";
        for (auto j = st; j < en; ++j){
            if (c.back() != (c[j] | A[i])) c.push_back(c[j] | A[i]);
            cout<<(c[j] | A[i])<<" ";
        }
        cout<<endl;
      }
      return unordered_set<int>(begin(c), end(c)).size();
    }
};

int main(){
    int a[] = {1,2,4};
    vector<int> ve;
    for(int i=0;i<3;i++){
        ve.push_back(a[i]);
    }
    Solution so;
    int res = so.subarrayBitwiseORs(ve);
    cout<<res<<endl;
    return 0;
}