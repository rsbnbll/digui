#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.递归和非递归分别实现求第n个斐波那契数。
int fib(int n){
	if (n <= 2){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}
int fib2(int n){
	if (n <= 2){
		return 1;
	}
	int an, an_1=1, an_2=1;
	int i;
	for (i = 3; i <= n;i++){
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
	}
	return an;
}
//2.递归实现求n的阶乘
int mul(int n){
	if (n <= 1){
		return 1;
	}
	return n*mul(n - 1);
}
//3.编写一个函数实现n^k，使用递归实现
int mPow(int m, int n){
	if (n == 1){
		return m;
	}
	return m*mPow(m, n - 1);
}
//4. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n){
	if (n == 0){
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}
//5.递归实现strlen
int myStrlen(const char* str){
	if (*str == '\0'){
		return 0;
	}
	return 1 + myStrlen(str + 1);
}
//6.递归方式实现打印一个整数的每一位
void printNum(int n){
	if (n == 0){
		return;
	}
	printNum(n / 10);
	putchar(n % 10 + '0');     //printf消耗太大,可以用putchar
}
void printNum1(int n, int m)    //任意进制的数实现打印每一个整数的每一位
{
	if (n == 0)
	{
		return;
	}

	printNum1(n / m, m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
void reverse_string(char * str)
{
	if (*str)
	{
		int tmp;
		int end = myStrlen(str) - 1;

		tmp = *str;
		*str = str[end];
		str[end] = '\0';
		reverse_string(str + 1);
		str[end] = tmp;
	}
}

int main(){
	/*printf("%d\n", fib(8));
	printf("%d\n", fib2(8));
	printf("%d\n", mul(10));
	printf("%d\n", mPow(5, 2));
	printf("%d\n", DigitSum(2467));
	printf("%d\n", myStrlen("rsbnbll"))*/;
	//printNum(1345);
	//printNum1(23,32);
	char str[] = "bitekeji";
	reverse_string(str);
	puts(str);
	printf("%d\n", str);
	system("pause");
	return 0;
}