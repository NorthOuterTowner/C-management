/*全局变量的头文件*/
#include <stdio.h>

/*避免重复定义*/
#ifndef  _GLOBAL_H_

//宏的定义
#define MAX 15

#define TRUE 1
#define FALSE 0

//结构的定义
struct data {
	int id;
	char name[MAX];
	char gender;
	int age;
	float CSco;
	float mathSco;
	float englishSco;
	struct data *next;
};

#endif
