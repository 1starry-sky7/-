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

void total(int);//����ѧ����Ϣ

char* s_gets(char* st, int);//����

void AgeStudent(int*);//����

void GenderStudent(char*);//�Ա� 

void StudentID(long*);//ѧ��

void ScoreStudent(float*);//�ɼ�

void EnterStudent(int);//��ѯѧ����Ϣ
void Print();//��ѯѧ����Ϣ
void query();//ѡ�����

void del();//ɾ����Ϣ

void whole();//����ѧ����Ϣ

void update();//�޸���Ϣ

void count();//ͳ��ѧ������

void ranking();//���ɼ�����

void Del_all();//ɾ��������Ϣ

int ShowStudent();