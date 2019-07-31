#include <iostream>
#include <string>

using namespace std;
int skipValue(string& json, size_t i){
    while(json[i]==' ')i++;
    if(json[i] == '{'){
        int counter = 1;
        ++i;
        while(i<json.size()&&counter!=0){
            if(json[i]=='{')counter++;
            if(json[i]=='}')counter--;
            i++;
        }
        //i++;
        return i;
    }
    while(i<json.size()&&json[i]!=','){
        i++;
    }
    return i;
}
bool isJson(string& s){
    size_t i=0;
    while(i<s.size()&&s[i]==' ')i++;
    return s[i]=='{';
}
string Sub(string json, string key, string value) {
// 给定一个json格式的字符串，替换对应的key的值为value
// e.g. json: "{A:2, GG:44, B: {C:444, A: 333}}", key: “A”, value: "yitu", expected: "{A:yitu, GG:44, B: {C:444, A: yitu}}"
// {AA:2, GG:44, A: {C:444, A: 333}}", key: “A”, value: "yitu", expected: "{AA:2, GG:44, A: {C:444, A: yitu}}

//思路：遍历json字符串，在每一个循环里处理一个kv，首先找到对应mykey和myvalue，
//key与目标key相等，若myvalue是一个json，则调用Sub函数，将返回值append到结果中；若myvalue不是一个json，那么直接用value替代
//key与目标key不等，直接将key与value加入结果中
//注意处理空格与逗号
    string res("{");
    size_t i = 0;
    while(i < json.size()){
        while(i<json.size()&&(json[i]=='{'||json[i] == '}'||json[i]==' ')){
            i++;
        }
        if(i>=json.size())break;
        int s = i;
        while(json[i]==' '||json[i]==','){
            i++;
        }
        string t(json.substr(s, i-s));
        res.append(t);
        
        //找到key
        s = i;
        while(json[i]!=':'){
            //myKey.append(json[i]);
            i++;
        }
        string myKey(json.substr(s, i-s));

        //找到value
        i++;
        s = i;
        i = skipValue(json, i);
        string myValue(json.substr(s, i-s));
        cout<<myKey<<" : "<<myValue<<endl;

        //拼接res
        res.append(myKey);
        res.append(string(": "));
        if(myKey.compare(key) == 0){//找到对应key
            cout<<"find value = "<<myValue<<endl;
            if(isJson(myValue)){
                string t = Sub(myValue, key, value);
                res.append(t);
            }
            else res.append(value);
        }
        else{
            if(isJson(myValue)){//递归json
                string  t = Sub(myValue, key, value);
                cout<<"temp "<<t<<endl;
                res.append(t);
            }
            else{
                res.append(myValue);
            }
        }
        // res.append(json.substr(s, i-s));
        // res.append(":");
        // i++;
        // if(myKey.compare(key)==0){
        //     res.append(value);
        //     i = skipValue(json, i);
        //     //res.append(",");
        // }
        // else{
        //     int j = skipValue(json, i);
        //     cout<<json[i]<<endl;
        //     if(i<json.size()){
        //         if(json[i]=='{'){
        //             string subjson(json.substr(i, j-i+1));
        //             string t = Sub(subjson, key, value);
        //             res.append(t);
        //         }
        //         else{
        //             res.append(json.substr(i, j-i+1));
        //         }
        //     }
        //     else{
        //         if(json[i]=='{'){
        //             string subjson(json.substr(i, json.size()-i+1));
        //             string t = Sub(subjson, key, value);
        //             res.append(t);
        //         }
        //         else{
        //             res.append(json.substr(i, json.size()-i+1));
        //         }
        //     }
        //     i = j;
        // }
        // while(i<json.size()&&json[i]==' ')i++;
        // if(i>=json.size())break;
        // i++;
        //cout<<"i++ "<<json[i]<<endl;
    }
    res.append(string("}"));
    return res;
}
int main() {
    string json("{AA:2, GG:44, A: {C:444, A: 333}}");
    string key("A");
    string value("yitu");
    string res = Sub(json, key, value);
    cout << res << endl;
}
