/*逻辑层头文件*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*避免重复定义*/
#ifndef  _GLOBAL_H_
#define _GLOBAL_H_
#endif

/*函数原型声明*/
void addInfo();
void displayInfo();
struct data *searchInfo();
void sortByID();
void modify();
