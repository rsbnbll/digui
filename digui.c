#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
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
//2.�ݹ�ʵ����n�Ľ׳�
int mul(int n){
	if (n <= 1){
		return 1;
	}
	return n*mul(n - 1);
}
//3.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
int mPow(int m, int n){
	if (n == 1){
		return m;
	}
	return m*mPow(m, n - 1);
}
//4. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int n){
	if (n == 0){
		return 0;
	}
	return n % 10 + DigitSum(n / 10);
}
//5.�ݹ�ʵ��strlen
int myStrlen(const char* str){
	if (*str == '\0'){
		return 0;
	}
	return 1 + myStrlen(str + 1);
}
//6.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void printNum(int n){
	if (n == 0){
		return;
	}
	printNum(n / 10);
	putchar(n % 10 + '0');     //printf����̫��,������putchar
}
void printNum1(int n, int m)    //������Ƶ���ʵ�ִ�ӡÿһ��������ÿһλ
{
	if (n == 0)
	{
		return;
	}

	printNum1(n / m, m);
	putchar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % m]);
}
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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