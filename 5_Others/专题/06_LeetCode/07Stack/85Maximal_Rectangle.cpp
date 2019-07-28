#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        vector<pair<int,int> > tmpLH;
        vector<pair<int,int> > tmpLH1;
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        int res = 0;
        if(matrix[0][0]=='1'){
            tmpLH.push_back(pair<int,int>(1,1));
            tmpLH1.push_back(pair<int,int>(1,1));
            res = 1;
        }
        else {
            tmpLH1.push_back(pair<int,int>(0,0));
            tmpLH.push_back(pair<int,int>(0,0));
        }
        for(int i=1;i<matrix[0].size();i++){
            if(matrix[0][i]=='0'){
                tmpLH.push_back(pair<int,int>(0,0));
                tmpLH1.push_back(pair<int,int>(0,0));
            }
            else {
                tmpLH1.push_back(pair<int,int>(1,1));
                tmpLH.push_back(pair<int,int>(tmpLH[i-1].first+1,1));  
                if(tmpLH[i].first>res)res=tmpLH[i].first;
                if(tmpLH1[i].first>res)res=tmpLH1[i].first;
            }
        }
        for(int k=0;k<tmpLH.size();k++)cout<<"("<<tmpLH[k].first<<","<<tmpLH[k].second<<")"<<" ";
            cout<<endl;
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]=='0'){
                tmpLH[0]=pair<int,int>(0,0);
                tmpLH1[0]=pair<int,int>(0,0);
            }
            else{
                tmpLH1[0].first=1;
                tmpLH1[0].second++;
                if(tmpLH1[0].second>res)res=tmpLH[0].second;
                tmpLH[0].first=1;
                tmpLH[0].second=1;
            }
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')tmpLH[j]=pair<int,int>(0,0);
                else{                    
                    int l1 = min(tmpLH[j-1].first+1,max(tmpLH[j].first,1));
                    int h1 = min(max(tmpLH[j-1].second,1),tmpLH[j].second+1);
                    int l2 = min(tmpLH1[j-1].first+1,max(tmpLH1[j].first,1));
                    int h2 = min(max(tmpLH1[j-1].second,1),tmpLH1[j].second+1);
                    tmpLH[j].first = l1;tmpLH[j].second = h1;
                    tmpLH[j].first = l1;tmpLH[j].second = h1;
                    res = max(max(l1*h1,res),l2*h2);
                    // if(tmpLH[j].first * tmpLH[j].second > res)
                    //     res = tmpLH[j].first * tmpLH[j].second;
                }
            }
            for(int k=0;k<tmpLH.size();k++)cout<<"("<<tmpLH[k].first<<","<<tmpLH[k].second<<")"<<" ";
            cout<<endl;
            //for(int k=0;k<tmpLH1.size();k++)cout<<"("<<tmpLH1[k].first<<","<<tmpLH1[k].second<<")"<<" ";
            //cout<<endl;
        }
        return res;
    }
};

int main(){
    char a[4][6] = {"10100","10111","11111","10010"};
    vector<vector<char> > ve;
    for(int i=0;i<4;i++){
        vector<char> tmp;
        for(int j=0;j<5;j++){
            tmp.push_back(a[i][j]);
        }
        ve.push_back(tmp);
        tmp.clear();
    }
    Solution so;
    int res = so.maximalRectangle(ve);
    cout<< res <<endl;
    return 0;
}