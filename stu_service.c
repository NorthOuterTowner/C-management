/*逻辑层源代码*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*引入全局变量*/
#include"global.h"

/*引入外部定义的全局变量*/
extern struct data *head;
extern struct data *tail;

/*添加数据*/
void addInfo() {
    /*暂时存储的数据*/
	char tmpName[MAX];
	int tmpID;
	char tmpGender;
	int tmpAge;
	float tmpCsco;
	float tmpMathSco;
	float tmpEngSco;

	struct data *newaddr = (struct data *)malloc(sizeof(struct data));
	if (newaddr == NULL) {
		printf("Address assignment failed!\n");
		exit(1);
	}
	printf("Input student's ID please:");
	scanf("%d", &tmpID);
	printf("Input student's name please:");
	scanf("%s", tmpName);
	getchar();
	printf("Input student's gender please:");
	scanf("%c", &tmpGender);
	printf("Input student's age please:");
	scanf("%d", &tmpAge);
	printf("Input student's C score please:");
	scanf("%f", &tmpCsco);
	printf("Input student's math score please:");
	scanf("%f", &tmpMathSco);
	printf("Input student's English score please:");
	scanf("%f", &tmpEngSco);
	struct data *cur = head;
	if (head == NULL) {
		newaddr->next = NULL;
		head = newaddr;
		tail = newaddr;
	} else {
		cur = tail;
		tail = newaddr;
		cur->next = newaddr;
		newaddr->next = NULL;
	}
	newaddr->id = tmpID;
	strcpy(newaddr->name, tmpName);
	newaddr->gender = tmpGender;
	newaddr->age = tmpAge;
	newaddr->CSco = tmpCsco;
	newaddr->mathSco = tmpMathSco;
	newaddr->englishSco = tmpEngSco;
	printf("\n");

}

/*输出数据*/
void displayInfo() {
	struct data *cur = head;
	printf("the name list are as follows:\n");
	printf("ID\tname\tgender\tage\tC score\t\tMath score\tEnglish score\n");
	while (cur != NULL) {
		printf("%d\t", cur->id);
		printf("%s\t", cur->name);
		printf("%c\t", cur->gender);
		printf("%d\t", cur->age);
		printf("%.1f\t\t", cur->CSco);
		printf("%.1f\t\t", cur->mathSco);
		printf("%.1f\n", cur->englishSco);
		cur = cur->next;
	}
	printf("\n");
}

/*按照学号进行排序*/
void sortByID() {
    int falsecnt=TRUE;
	struct data *cur = head;
	struct data *tmpNode = (struct data *)malloc(sizeof(struct data));
	while(falsecnt!=FALSE){
            falsecnt=FALSE;
            cur=head;
    /*从第一个数据开始，每个数据冒泡排序*/
	while (cur->next != NULL) {
            /*每个数据与其后的数据id比较*/
		if ((cur->id) > (cur->next->id)) {
		    falsecnt=TRUE;
			tmpNode->id = cur->next->id;
			strcpy(tmpNode->name, cur->next->name);
			tmpNode->gender = cur->next->gender;
			tmpNode->age = cur->next->age;
			tmpNode->CSco = cur->next->CSco;
			tmpNode->mathSco = cur->next->mathSco;
			tmpNode->englishSco = cur->next->englishSco;

			cur->next->id = cur->id;
			strcpy(cur->next->name, cur->name);
			cur->next->gender = cur->gender;
			cur->next->age = cur->age;
			cur->next->CSco = cur->CSco;
			cur->next->mathSco = cur->mathSco;
			cur->next->englishSco = cur->englishSco;

			cur->id = tmpNode->id;
			strcpy(cur->name, tmpNode->name);
			cur->gender = tmpNode->gender;
			cur->age = tmpNode->age;
			cur->CSco = tmpNode->CSco;
			cur->mathSco = tmpNode->mathSco;
			cur->englishSco = tmpNode->englishSco;

		}
		cur = cur->next;
	}
	}
}

struct data *searchInfo() {
	int searchId;
	printf("Input the id you want to search:");
	scanf("%d", &searchId);
	struct data *cur;
	cur = head;
	int cnt = 0;
	while (cur != NULL) {
		if (head->id == searchId) {
			cnt = 1;
			break;
		} else if (cur->id == searchId) {
			cnt = 1;
			break;
		}
		cur = cur->next;
	}
	if (cnt == 0) {
		printf("Not found data!\n");
		return NULL;
	} else {
		printf("The data of this student has been found\n");
		printf("ID\tname\tgender\tage\tC score\t\tMath score\tEnglish score\n");
		printf("%d\t%s\t%c\t%d\t%.1f\t\t%.1f\t\t%.1f\n", cur->id, cur->name, cur->gender, cur->age, cur->CSco, cur->mathSco,
		       cur->englishSco);
		return cur;
	}
}

/*修改数据*/
void modify() {
	int tmpChoice;
	struct data *searchNode = searchInfo();//定位需要修改的数据
	if (searchNode != NULL) {
		printf("Input which data do you want to change:\n"
		       "1 Name\n"
		       "2 Gender\n"
		       "3 Age\n"
		       "4 C score\n"
		       "5 Math Score\n"
		       "6 English Score\n"
		       "Other Return\n"
		      );
		scanf("%d", &tmpChoice);
		/*将链表中需要修改的数据进行更改*/
		switch (tmpChoice) {
			case 1:
				printf("Input the name you want to change to:");
				scanf("%s", searchNode->name);
				break;
			case 2:
				printf("Input the gender you want to change to:");
				getchar();
				scanf("%c", &searchNode->gender);
				break;
			case 3:
				printf("Input the age you want to change to:");
				scanf("%d", &searchNode->age);
				break;
			case 4:
				printf("Input the C score you want to change to:");
				scanf("%f", &searchNode->CSco);
				break;
			case 5:
				printf("Input the math score you want to change to:");
				scanf("%f", &searchNode->mathSco);
				break;
			case 6:
				printf("Input the English you want to change to:");
				scanf("%f", &searchNode->englishSco);
				break;
			default:
				break;
		}
	}
}
