#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int p = 1e9+7;
        vector<pair<int,int> > tmp;
        int res = 0;
        int tmp_sum=0;
        for(int i=0;i<A.size();i++){
            tmp.push_back(pair<int,int>(A[i],i));
            bool tf = BinarySearch(tmp,A[i],i);
            if(tf){
                tmp_sum = getSum(tmp);
            }
            else{
                tmp_sum = (tmp_sum + A[i])%p;
            }
            res=(res+tmp_sum)%p;
            cout<<"res="<<res<<" ";
            for(int i=0;i<tmp.size();i++)
                cout<<"["<<tmp[i].first<<","<<tmp[i].second<<"] ";
            cout<<endl;
        }
        return res;
    }
private:
    bool BinarySearch(vector<pair<int,int> > &tmp,int p,int q){
        int s=0,e=tmp.size()-2;
        if(tmp.empty())return false;
        if(tmp[0].first>=p){
            tmp.clear();
            tmp.push_back(pair<int,int>(p,q));
            return true;
        }
        if(tmp[e].first<p){
            return false;
        }
        if(tmp[e].first==p){
            tmp.erase(tmp.end()-1);
            tmp[e].second=q;
            return true;
        }
        int m;
        while(s<e-1){
            m = (e+s)>>1;
            if(tmp[m].first==p){
                tmp.erase(tmp.begin()+m+1,tmp.end());
                tmp[m].second=q;
                return true;
            }
            if(tmp[m].first<p)s = m;
            else e = m;
        }
        cout<<"s="<<s<<",e="<<e<<endl;
        tmp.erase(tmp.begin()+s+1,tmp.end());
        tmp.push_back(pair<int,int>(p,q));
        return true;
    }
    int getSum(vector<pair<int,int> > &tmp){
        if(tmp.empty())return 0;
        int sum = tmp[0].first*(tmp[0].second+1);
        for(int i=1;i<tmp.size();i++){
            sum+=tmp[i].first*(tmp[i].second-tmp[i-1].second);
        }
        return sum;
    }
};

int main(){
    Solution so;
    int a[]={85,93,93,90};
    vector<int> ve;
    for(int i=0;i<4;i++)ve.push_back(a[i]);
    so.sumSubarrayMins(ve);
    return 0;
}