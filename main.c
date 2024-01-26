/*Student Information Management*/
/*Author:LiRuize*/

/*可视层源代码*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//引入各个功能函数所在的头文件
#include"global.h"

#include"stu_file.h"
#include"stu_service.h"
//定义头尾指针
struct data *head = NULL;
struct data *tail = NULL;

/*用户界面*/
int main() {
	int choice;
	while (1) {
		printf("******************************\n"
		       "Student Information Management\n"
		       "******************************\n"
		       "******************************\n"
		       "**************Menu************\n"
		       "1 Add student info\n"
		       "2 Display student info\n"
		       "3 Sort by student ID\n"
		       "4 Search student info\n"
		       "5 Save student info to file\n"
		       "6 Read student info to file\n"
		       "7 Modify student info\n"
		       "8 Exit system\n"
		       "******************************\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				addInfo();
				getchar();
				break;
			case 2:
				displayInfo();
				getchar();
				break;
			case 3:
				sortByID();
				getchar();
				break;
			case 4:
				searchInfo();
				getchar();
				break;
			case 5:
				saveToFile();
				getchar();
				break;
			case 6:
				readInfo();
				getchar();
				break;
			case 7:
				modify();
				break;
			case 8:
				exit(0);
				break;
            default:
                printf("Your input is invalid!\n");
                break;
		}
	}
	return 0;
}
