/*数据传输层源代码*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*引入全局变量*/
#include"global.h"

/*引入外部定义的全局变量*/
extern struct data *head;
extern struct data *tail;

/*从文件中读取数据*/
void readInfo() {

	head = (struct data *)malloc(sizeof(struct data));
	if (head == NULL) {
		printf("Address assignment failed!\n");
		exit(1);
	}

	FILE *outFile = fopen("students.dat", "r");

	struct data *tmpPre = (struct data *)malloc(sizeof(struct data));
	if (tmpPre == NULL) {
		printf("Address assignment failed!\n");
		exit(1);
	}

	struct data *studentData = (struct data *)malloc(sizeof(struct data));
	if (studentData == NULL) {
		printf("Address assignment failed!\n");
		exit(1);
	}

	struct data *cur = head;
	//读入数据
	while (fscanf(outFile, "%d %s %c %d %f %f %f\n", &(studentData->id), studentData->name, &(studentData->gender),
	              &(studentData->age), &(studentData->CSco), &(studentData->mathSco), &(studentData->englishSco)) == 7) {
		struct data *newnode = (struct data *)malloc(sizeof(struct data));
		if (newnode == NULL) {
			printf("Address assignment failed!\n");
			exit(1);
		}
		/*将数据赋给链表*/
		cur->id = studentData->id;
		strcpy(cur->name, studentData->name);
		cur->gender = studentData->gender;
		cur->age = studentData->age;
		cur->CSco = studentData->CSco;
		cur->mathSco = studentData->mathSco;
		cur->englishSco = studentData->englishSco;

		cur->next = newnode;
		tmpPre = cur;
		cur = cur->next;
	}
	tail=tmpPre;//将尾指针指向最后一个数据
	tmpPre->next = NULL;
	fclose(outFile);
	free(studentData);
}

/*将数据保存至文件中*/
void saveToFile() {
	FILE *saveFile = fopen("students.dat", "w");
	struct data *cur = head;

	while (cur != NULL) {
		fprintf(saveFile, "%d ", cur->id);
		fprintf(saveFile, "%s ", cur->name);
		fprintf(saveFile, "%c ", cur->gender);
		fprintf(saveFile, "%d ", cur->age);
		fprintf(saveFile, "%.1f ", cur->CSco);
		fprintf(saveFile, "%.1f ", cur->mathSco);
		fprintf(saveFile, "%.1f\n", cur->englishSco);

		cur = cur->next;
	}
	fclose(saveFile);
}
