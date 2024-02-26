#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 35
#define LEN  10
struct student {
	char name[SIZE];
	int age;
	char gender[LEN];
	long number;
	float Chinese;
	float Mathematics;
	float English;
	float close;
};
struct student2 {
	char name[SIZE];
	int age;
	char gender[LEN];
	long number;
	float Chinese;
	float Mathematics;
	float English;
};
typedef struct student2 Student2;

typedef struct student Student;

void total(int);//输入学生信息

char* s_gets(char* st, int);//姓名

void AgeStudent(int*);//年龄

void GenderStudent(char*);//性别 

void StudentID(long*);//学号

void ScoreStudent(float*);//成绩

void EnterStudent(int);//查询学生信息
void Print();//查询学生信息
void query();//选择界面

void del();//删除信息

void whole();//所有学生信息

void update();//修改信息

void count();//统计学生人数

void ranking();//按成绩排行

void Del_all();//删除所用信息

int ShowStudent();