
/**
 * 字符串逆序输出
 */ 
#include <iostream>
#include <cstring>
using namespace std;

/**
 * 说明：
 *    这里使用异或操作，交换两个字符的位置
 *    其中a^b是a异或b而不是a的b次方
 */ 
void swap(char &a, char &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

/**
 * 注：
 *    这里是使用 引用的方式交换两个字符位置
 */ 
void reverse2(char *s)
{
    int n = strlen(s);
    for(int i=0; i<n/2; ++i)
        swap(s[i], s[n-i-1]);
}

/**
 * 注：
 *    这里是使用指针方式，交换两个字符的位置
 */ 
void reverse(char *s)
{
    char *end = s;
    char tmp;
    if(s)
    {
        while(*end)
            ++end;
        --end;	//字符串最后一个字符的指针
        while(s < end)
        {
            tmp = *s;
            *s++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    char s[] = "1234567890";
	cout<<"原字符串："<<s<<endl;

    reverse2(s);
	cout<<"使用引用交换："<<s<<endl;

	reverse(s);
	cout<<"使用指针交换："<<s<<endl;
    return 0;
}
