#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
    while (num2!=0) {
        int temp = num1^num2;//取其不同部分
        num2 = (num1&num2)<<1;//相同部分乘以2
        num1 = temp;
        cout<<"num1 = "<<num1<<" num2 = "<<num2<<endl;
    }
    return num1;
}
int main(){
    int res = Add(16,16);
    return 0;
}