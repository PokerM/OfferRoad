#include <iostream>
#include <cstring>

using namespace std;
int next[100];
void getNext(char* p){
    next[0] = -1;
    int i = 0, j = -1;
    while(i < strlen(p)){
        if(j==-1||p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}
int KMP(char* t, char* p){
    int i=0, j=0;
    while(i < strlen(t) && j < strlen(p)){
        if(j == -1 || t[i] == p[j]){
            ++i;
            ++j;
        }
        else j = next[j];
    }
    if(j == strlen(p))return i-j;
    return -1;
}
int main(){
    char* p = "abababca";
    char* t = "abc";
    getNext(p);
    int res = KMP(p, t);
    cout<<res<<endl;
    return 0;
}