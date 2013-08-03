
/**
 *	程序说明：
 *		给出一个字符串，指出字符串中每个字符是否唯一
 */ 
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 说明：
 *		一个字符char 占用一个字节（8bit），转换成整数对应256个数值
 *		现在通过一个256个元素的bool数组，标示字符串是否出现重复
 */ 
bool isUnique1(string s)
{
    bool a[256];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i<len; ++i)
    {
        int v = (int)s[i];
        if(a[v]) return false;
        a[v] = true;
    }
    return true;
}

/**
 * 说明：
 *     字符串中每个字符对应8bit，转换为整数为0-255，共有256种数值
 *     现在使用8个元素的整型数组，每个整数有32位，通过32*8=256位来标示256种数值
 */ 
bool isUnique2(string s)
{
    int a[8];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for(int i=0; i<len; ++i)
    {
        int v = (int)s[i];
        int idx = v/32, shift=v%32;
        if(a[idx] & (1<<shift)) return false;
        a[idx] |= (1<<shift);
    }
    return true;
}

bool isUnique3(string s)
{
    int check = 0;
    int len = s.length();
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if(check & (1<<v)) return false;
        check |= (1<<v);
    }
    return true;
}

int main()
{
    string s1 = "luosongchao.";
    string s2 = "abcdefghijklmnopqrstuvwxyz1234567890";
	cout<<"s1 is:"<<s1<<endl;
	cout<<"s2 is:"<<s2<<endl;
	cout<<"s1/s2是否不存在重复字符："<<isUnique1(s1)<<" "<<isUnique1(s2)<<endl;
    cout<<"s1/s2是否不存在重复字符："<<isUnique2(s1)<<" "<<isUnique2(s2)<<endl;
	return 0;
}
