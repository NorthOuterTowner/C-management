/*ȫ�ֱ�����ͷ�ļ�*/
#include <stdio.h>

/*�����ظ�����*/
#ifndef  _GLOBAL_H_

//��Ķ���
#define MAX 15

#define TRUE 1
#define FALSE 0

//�ṹ�Ķ���
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
