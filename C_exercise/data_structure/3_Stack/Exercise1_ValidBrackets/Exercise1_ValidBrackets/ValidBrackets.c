#define _CRT_SECURE_NO_WARNINGS 1
//【判断有效括号】
//给出一个只包括'('、')'、'{'、'}'、'['、']'的字符串s，判断字符串是否有效
//有效字符串需满足：
//1、左括号必须用相同类型的右括号闭合
//2、左括号必须以正确的顺序闭合
//3、每个右括号都有一个对应的相同类型的左括号
//示例：
//输入：s = "()[]{}({})"
//输出：true
//输入：s = "([)]"
//输出：false

#include"StackFunc.h"

bool isValid(char* s)
{
	ST stmp;
	ST* ps = &stmp;
	STinit(ps);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			STpush(ps, *s);
			s++;
		}
		if (*s == ')' || *s == ']' || *s == '}')
		{
			if (STempty(ps))
			{
				STdestroy(ps);
				return false;
			}
			char top = STtop(ps);
			if (((top == '(') && (*s == ')')) ||
				((top == '[') && (*s == ']')) ||
				((top == '{') && (*s == '}')))
			{
				STpop(ps);
				s++;
			}
			else
			{
				STdestroy(ps);
				return false;
			}
		}
	}
	bool isempty = STempty(ps);
	STdestroy(ps);
	return isempty;
}

void test(char* s)
{
	if (isValid(s)) printf("true\n\n");
	else printf("false\n\n");
}

int main()
{
	char s1[] = "()[]{}({})";
	char s2[] = "([)]";
	char s3[] = "]";
	char s4[] = "[[]";

	test(s1);
	test(s2);
	test(s3);
	test(s4);

	return 0;
}