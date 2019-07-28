#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > pre;
        vector<int> height(numCourses,0);
        int len = prerequisites.size();
        if(numCourses<2||len<2)return true;
        for(int i=0;i<prerequisites.size();i++){
            pair<int,int> pr = prerequisites[i];
            pre[pr.second].push_back(pr.first);
            height[pr.first]++;
        }
        vector<int> u,v;
        for(int i=0;i<numCourses;i++){
            if(height[i] == 0)u.push_back(i);
        }
        while(!u.empty()){
            for(int i=0;i<u.size();i++){
                int num = u[i];
                vector<int> node = pre[num];
                for(int j=0;j<node.size();j++){
                    int k = node[j];
                    if(--height[k]==0)v.push_back(k);
                }
            }
            swap(u,v);
            v.clear();
        }
        for(int i=0;i<numCourses;i++)if(height[i]!=0)return false;
        return true;
    }
};