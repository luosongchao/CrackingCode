#include <iostream>
#include <cstring>
using namespace std;

/**
 * 注：
 *	删除字符串中重复字符，这里使用了字符于'a'的差值来判断字符是否重复
 *	需要注意的是，这里的移位操作，需要使用非负值，因此该函数适合于比‘a’大的情况
 */ 
string removeDuplicate1(string s)
{
    int check = 0;
    int len = s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v)) == 0)
        {
            str += s[i];
            check |= (1<<v);
        }
    }
    return str;
}

/**
 * 注：
 *    该函数，使用了去除重复字符的常规思维，
 *    将每个字符，与其后的所有字符进行比较，如果其后不存在该字符
 *    则添加字符到待输出字符串   
 */ 
string removeDuplicate2(string s)
{
    int len = s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; ++i)
    {
        if(s[i] != '\0')
        {
            str += s[i];
            for(int j=i+1; j<len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    return str;
}

/**
 * 注：
 *      这里传入的是字符数组，设置s[p++]=s[i]
 *      可以保证最后输出的s[p]字符串就是需要的字符串
 */ 
void removeDuplicate3(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i];
            for(int j=i+1; j<len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}

/**
 * 注：
 *	   该函数判断，是否存在重复字符，使用了一个bool数组，
 *	   标识字符数组中是否存在重复字符
 */ 
void removeDuplicate4(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(!c[s[i]])
        {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';    
}

/**
 * 注：
 *    方法为removeDuplicate1函数
 */ 
void removeDuplicate5(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int check = 0, p = 0;
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v))==0)
        {
            s[p++] = s[i];
            check |= (1<<v);
        }
    }
    s[p] = '\0';
}

int main()
{
    string s1 = "abcde";
    string s2 = "aaabbb";
    string s3 = "";
    string s4 = "abababc";
    string s5 = "ccccc";
    cout<<"原字符为：   "<<s1<<"  去重后：  "<<removeDuplicate1(s1)<<" "<<removeDuplicate2(s1)<<endl;
    cout<<"原字符为：   "<<s2<<"  去重后：  "<<removeDuplicate1(s2)<<" "<<removeDuplicate2(s2)<<endl;
    cout<<"原字符为：   "<<s3<<"  去重后：  "<<removeDuplicate1(s3)<<" "<<removeDuplicate2(s3)<<endl;
    cout<<"原字符为：   "<<s4<<"  去重后：  "<<removeDuplicate1(s4)<<" "<<removeDuplicate2(s4)<<endl;
    cout<<"原字符为：   "<<s5<<"  去重后：  "<<removeDuplicate1(s5)<<" "<<removeDuplicate2(s5)<<endl;

	cout<<"================================================"<<endl;
	cout<<"相同字符，转换为字符数组，去重后为："<<endl;
    char ss1[] = "abcde";
    char ss2[] = "aaabbb";
    char ss3[] = "";
    char ss4[] = "abababc";
    char ss5[] = "ccccc";
    removeDuplicate5(ss1);
    removeDuplicate5(ss2);
    removeDuplicate5(ss3);
    removeDuplicate5(ss4);
    removeDuplicate5(ss5);
    cout<<ss1<<" "<<ss2<<" "<<ss3<<" "<<ss4<<" "<<ss5<<endl;
	return 0;
}
