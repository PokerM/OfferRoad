//https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720
class Solution
{
public:
  //Insert one char from stringstream
    string s;
    char hash[256]={0};
    void Insert(char ch)
    {
        s+=ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
         
        int size=s.size();
        for(int i=0;i<size;++i)
        {
            if(hash[s[i]]==1)
                return s[i];
        }
        return '#';
    }
};