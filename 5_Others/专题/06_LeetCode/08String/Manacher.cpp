#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
/*
p[i]:代表i为中点的回文串长度
mx:当前回文串最右端点的位置
id:当前最右端回文串的中点位置
 */
void manacher(string& s, int len, vector<int>& p){
	p[0] = 1;
	int mx = 0 , id  = 0;
	for(int i = 1 ;i < len ; i ++){
        if(mx > i){//最右端点是否包含当前点
            if(p[id*2-i] < mx - i){//对称点回文长度小于mx-i, mx - i不用+1，因为最右边的字符不是对称的
                p[i] = p[id*2-i];
            }
            else{
                p[i] = mx - i;
				cout<<"mx = "<<mx<<" i = "<<i<<endl;
            }
        }
        else p[i] = 1;
		//p[i] = mx > i ? min(p[id*2-i], mx - i) : 1;
		while(s[i+p[i]] == s[i-p[i]])p[i]++;//拓展回文长度
		if(i+p[i] > id + p[id]){//更新最长回文子串
			id = i;
			mx = i + p[i];
			cout<<s[id]<<" "<<mx<<endl;
		} 
	}
}
int main(){
    string str;
	while(cin>>str){
		int len = str.size();
		cout<<"len = "<<len<<endl;
        string t(len * 2 + 2, '0');
		for(int i = len; i >= 0; i--){
			t[(i << 1) + 1] = '#';
			t[(i << 1) + 2] = str[i];
		}
		t[0] = '@';
		cout<<t<<endl;
		len = len*2 + 2;
        vector<int> p(len, 0);
		manacher(t , len, p);
		int ans = 0;
		for(int i = 0 ; i < len ; i++){
			ans = max(ans,p[i]-1);
			cout<<p[i]<<" ";
		}
		cout<<endl;	
		printf("ans = %d\n",ans);
	}
	return 0;
}