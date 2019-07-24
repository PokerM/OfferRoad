class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==nullptr)return;
        int _num = 0;//空格个数
        int old = 0;//总字符数，未计'\0'
        int i=0;
        while(str[i]!='\0'){
            old++;
            if(str[i]==' ')_num++;
            i++;
        }
        if(_num==0)return;            //没有空格，直接返回
        int len = old + 2 * _num;     //移动游标至尾部
        if(len > length-1)return;     //给出的空间长度不够，直接返回
        str[len+1]='\0';              //末尾添加'\0'
        //倒着替换
        for(int i=old;i>=0;i--){        
            if(str[i]==' '){
                str[len]='0';
                len--;
                str[len]='2';
                len--;
                str[len]='%';
                len--;
            }
            else{
                str[len]=str[i];
                len--;
            }
        }
        return;
	}
};