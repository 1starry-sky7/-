#define _CRT_SECURE_NO_WARNINGS
#include"源1.h"
Student names[10];
Student names2[10];
int main(void)
{
	int a1;
	int a2 = 0;
	query();
	while (scanf("%d", &a1) == 1)
	{


		getchar();
		switch (a1)
		{
		case 1:
		{
			total(a2);//输入信息
			a2++;
			break;
		}
		case 2:Print();//输出信息
			break;
		case 3:del();//删除信息
			break;
		case 4:whole();//显示所用信息
			break;
		case 5:update();//修改信息
			break;
		case 6:count();//学生人数
			break;
		case 7:ranking();//成绩排行
			break;
		case 8:Del_all();//删除全部
			break;
		case 9://结束程序
			return 0;
		}
		query();
	}
	puts("输入错误，请重新进入");
	return 0;
}


//选择界面
void query()
{
	printf("*********************************\n");
	printf("*\t学生成绩管理系统\t*\n");
	printf("*********************************\n");
	printf("*\t1:添加学生信息\t\t*\n");
	printf("*\t2:查询学生信息\t\t*\n");
	printf("*\t3:删除学生信息\t\t*\n");
	printf("*\t4:显示学生信息\t\t*\n");
	printf("*\t5:修改学生信息\t\t*\n");
	printf("*\t6:统计学生人数\t\t*\n");
	printf("*\t7:学生成绩排行\t\t*\n");
	printf("*\t8:清空学生信息\t\t*\n");
	printf("*\t9:退出程序\t\t*\n");
	printf("*********************************\n");
}



//录入信息
void total(int n)
{
	int n1 = ShowStudent();
	printf("Enter %d student information\n\n", n1);
	printf("Pleases enter your name:");
	s_gets(names[n].name, SIZE);
	printf("Pleases enter your age:");
	AgeStudent(&names[n].age);
	printf("Pleases enter your gender:");
	GenderStudent(names[n].gender);
	printf("Pleases enter your student id:");
	StudentID(&names[n].number);
	printf("Pleases enter your Chinese:");
	ScoreStudent(&names[n].Chinese);
	printf("Pleases enter your Mathematics:");
	ScoreStudent(&names[n].Mathematics);
	printf("Pleases enter your English:");
	ScoreStudent(&names[n].English);

	FILE* fp;
	fp = fopen("学生成绩管理系统.txt", "ab+");//在末尾读写
	if (fp == NULL)
	{
		fputs("Can't open file\n", stderr);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		fwrite(&names[n], sizeof(Student), 1, fp);
		break;
	}
	fclose(fp);
}


//学生信息个数
int ShowStudent()
{
	int show = 0;
	FILE* fs = fopen("学生成绩管理系统.txt", "ab+");
	if (fs == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}
	while (!feof(fs))
	{
		fread(&names[show], sizeof(Student), 1, fs);
		show++;
	}
	if (show == 0)
		show += 1;
	fclose(fs);
	return show;
}

//输出信息
void Print()
{
	long num;
	printf("Please enter your number:");
	scanf("%ld", &num);
	while (num < 100000 || num>999999)
	{
		printf("Student ID eroe,rre_enter:");
		scanf("%ld", &num);

	}
	EnterStudent(num);


}

void EnterStudent(int n)
{
	int a1 = 0;
	FILE* fp1;
	fp1 = fopen("学生成绩管理系统.txt", "rb");
	if (fp1 == NULL)
	{
		fputs("Can;t open file\n", stderr);
	}
	while (!feof(fp1))
	{
		fread(&names[a1], sizeof(Student), 1, fp1);
		if (names[a1].number == n)
		{
			printf("Name:%s\n", names[a1].name);
			printf("Gender:%s\n", names[a1].gender);
			printf("Age:%d\n", names[a1].age);
			printf("Student ID:%ld\n", names[a1].number);
			printf("Chinese score:%.2f\n", names[a1].Chinese);
			printf("Englsh score:%.2f\n", names[a1].English);
			printf("Mathematics score:%.2f\n", names[a1].Mathematics);
			break;
		}
	}

	fclose(fp1);
}


//成绩
void ScoreStudent(float* n)
{
	scanf("%f", n);
	while (*n < 0 || *n>100)
	{
		printf("Grade error re_enter:");
		scanf("%f", n);

	}
}

//学号
void StudentID(long* n2)
{
	int sd = 0;
	int tu;

	FILE* fs = fopen("学生成绩管理系统.txt", "ab+");
	if (fs == NULL)
	{
		printf("文件读取打开失败");
		exit(EXIT_FAILURE);
	}

	while (1)
	{

		fread(&names2[sd], sizeof(Student), 1, fs);
		if (feof(fs) != 0)
			break;
		sd++;
	}

	while (1)
	{
		int de;
		de = scanf("%ld", n2);
		if (de == 1 && *n2 >= 100000 && *n2 <= 999999)
		{
			for (tu = 0; tu <= sd; tu++)
			{
				if (names2[tu].number == *n2)
				{
					printf("学号重复请重新输入：");
					break;
				}
				else if (tu == sd)
					return;
			}

		}
		else
			printf("输入错误，重新输入");
		getchar();
	}
	fclose(fs);
}

//年龄
void AgeStudent(int* n)
{

	scanf("%d", n);
	while (*n < 10 || *n>45)
	{
		getchar();
		printf("Age error,re_enter:");
		scanf("%d", n);
	}
	getchar();
}


//姓名
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

//性别
void GenderStudent(char* st)
{
	int gs;

	while (1)
	{
		printf("\n1:男      2:女：");
		scanf("%d", &gs);
		getchar();
		if (gs == 1)
		{
			char gen[10] = { "男" };
			strcpy(st, gen);
			return;
		}
		else if (gs == 2)
		{
			char gen[10] = { "女" };
			strcpy(st, gen);
			return;
		}
		else
		{
			printf("请重新输入");
		}
	}
}


//删除信息
void del()
{
	long n;
	int dw = 0;//统计学生个数
	printf("输入要删除的学号：");
	while (scanf("%ld", &n) && (n < 100000 || n>999999))
	{
		getchar();
		if (n >= 100000 && n <= 999999)
			break;
		printf("学号错误，重新输入");
	}

	FILE* fp = fopen("学生成绩管理系统.txt", "rb");
	if (fp == NULL)
	{
		printf("文件打开失败，无法读出\n");
		exit(EXIT_FAILURE);
	}
	else if (fp != NULL)
	{
		while (!feof(fp))
		{
			fread(&names[dw], sizeof(Student), 1, fp);
			dw++;
		}
	}
	else if (dw == 1)
	{
		puts("没有存储学生信息\n");
		return;
	}
	dw = dw - 1;//减去第一次循环
	fclose(fp);


	int wr;
	FILE* fw = fopen("学生成绩管理系统.txt", "w");
	if (fw == NULL)
	{
		printf("文件打开失败，无法写入\n");
		exit(EXIT_FAILURE);
	}

	for (wr = 0; wr <= dw; wr++)
	{

		if (n == names[wr].number)
		{

			break;
		}
		else if (wr == dw && names[dw].number != n)
		{
			printf("学号不存在");
			return;
		}
	}

	for (wr; wr <= dw; wr++)
	{
		names[wr] = names[wr + 1];
	}


	for (wr = 0; wr < dw; wr++)
	{
		if (names[wr].number != 0)
			fwrite(&names[wr], sizeof(Student), 1, fw);
	}
	printf("删除成功\n");
	getchar();
	fclose(fw);
}


//查询所用信息
void whole()
{
	int wh = 0;
	int wh1;
	FILE* fw;
	fw = fopen("学生成绩管理系统.txt", "rb");
	if (fw == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		fread(&names[wh], sizeof(Student), 1, fw);
		if (feof(fw) != 0)
			break;
		wh++;
	}

	if (wh == 0)
	{
		puts("没有学生信息");
		return;
	}
	else
	{

		for (wh1 = 0; wh1 < wh; wh1++)
		{

			printf("第%d位学生信息\n", wh1 + 1);
			printf("姓名：%s ", names[wh1].name);
			printf("性别：%s ", names[wh1].gender);
			printf("年龄：%d ", names[wh1].age);
			printf("学号：%ld\n", names[wh1].number);
			printf("语文成绩：%.2f  ", names[wh1].Chinese);
			printf("数学成绩：%.2f  ", names[wh1].Mathematics);
			printf("语言成绩：%.2f  \n\n", names[wh1].English);

		}
	}
	fclose(fw);
}

//修改信息
void update()
{
	long n;
	int da = 0;//存储下标
	int te;//核对信息下标
	printf("输入要修改学生信息的学号：");
	scanf("%ld", &n);
	while (n < 100000 && n>999999)
	{
		printf("学号格式错误，请重新输入:");
		int up = scanf("%ld", &n);
		if (up != 1)
		{
			printf("请输入6位数字学号\n");
			getchar();
		}
	}
	getchar();
	FILE* fu = fopen("学生成绩管理系统.txt", "rb");
	if (fu == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}

	while (!feof(fu))
	{
		fread(&names[da], sizeof(Student), 1, fu);
		da++;
	}
	da = da - 1;

	for (te = 0; te <= da; te++)
	{
		if (names[te].number == n)
		{
			break;
		}
		else if (te == da && names[te].number != n)
		{
			printf("没有该学生信息\n");
			return;
		}
	}

	fclose(fu);
	printf("开始修改信息\n");
	printf("Pleases enter your name:");
	s_gets(names[te].name, SIZE);
	printf("Pleases enter your age:");
	AgeStudent(&names[te].age);
	printf("Pleases enter your gender:");
	GenderStudent(names[te].gender);
	printf("Pleases enter your Chinese:");
	ScoreStudent(&names[te].Chinese);
	printf("Pleases enter your Mathematics:");
	ScoreStudent(&names[te].Mathematics);
	printf("Pleases enter your English:");
	ScoreStudent(&names[te].English);

	FILE* ft = fopen("学生成绩管理系统.txt", "wb");
	if (ft == NULL)
	{
		printf("无法打开文件,写入失败");
		exit(EXIT_FAILURE);
	}

	for (te = 0; te <= da; te++)
	{
		if (names[te].number != 0)
			fwrite(&names[te], sizeof(Student), 1, ft);
	}
	fclose(ft);
	printf("更改成功\n");

}


//统计学生人数
void count()
{
	int co = 0;
	FILE* fc = fopen("学生成绩管理系统.txt", "rb");
	if (fc == NULL)
	{
		printf("文件只读失败");
		exit(EXIT_FAILURE);
	}
	while (!feof(fc))
	{
		fread(&names[co], sizeof(Student), 1, fc);
		co++;
	}
	co = co - 1;
	if (co == 0)
	{
		puts("没有学生信息");
		return;
	}
	else
	{
		printf("学生总人数：%d\n", co);

	}
}

//按成绩排行
void ranking()
{
	int ing = 0;//下标
	int ran;//匹配下标
	FILE* fr = fopen("学生成绩管理系统.txt", "rb");
	if (fr == NULL)
	{
		printf("文件只读失败");
		exit(EXIT_FAILURE);
	}
	while (!feof(fr))
	{
		fread(&names[ing], sizeof(Student), 1, fr);
		ing++;
	}
	ing = ing - 1;

	if (ing == 0)
	{
		printf("没有学生信息\n");
		return;
	}
	else
	{
		for (ran = 0; ran < ing; ran++)
		{
			names[ran].close = names[ran].Chinese + names[ran].Mathematics + names[ran].English;
		}
	}


	int ae;
	int meb = 1;
	for (ae = 0; ae < ran - 1; ae++)
	{

		if (ran == 1)
		{
			printf("排名：1\n");
			printf("姓名：%s ", names[ae].name);
			printf("性别：%s ", names[ae].gender);
			printf("年龄：%d ", names[ae].age);
			printf("学号：%ld\n", names[ae].number);
			printf("语文成绩：%.1f  ", names[ae].Chinese);
			printf("数学成绩：%.1f  ", names[ae].Mathematics);
			printf("语言成绩：%.1f  \n", names[ae].English);
			printf("总成绩：%.1f\n", names[ae].close);
			return;
		}
		else
		{
			while (1)
			{

				if (meb == ran)
				{
					meb = ae + 1;
					meb += 1;
					break;
				}
				else if (names[ae].close < names[meb].close)
				{

					names2[ae] = names[ae];
					names[ae] = names[meb];
					names[meb] = names2[ae];

				}
				++meb;

			}
		}
	}

	for (ae = 0; ae < ran; ae++)
	{
		printf("排名：%d\n", ae + 1);
		printf("姓名：%s ", names[ae].name);
		printf("性别：%s ", names[ae].gender);
		printf("年龄：%d ", names[ae].age);
		printf("学号：%ld\n", names[ae].number);
		printf("语文成绩：%.1f  ", names[ae].Chinese);
		printf("数学成绩：%.1f  ", names[ae].Mathematics);
		printf("语言成绩：%.1f  \n", names[ae].English);
		printf("总成绩：%.1f\n\n", names[ae].close);

	}
	fclose(fr);
}


//删除所用信息
void Del_all()
{
	int all = 0;
	int remove;
	int tion;
	FILE* fe = fopen("学生成绩管理系统.txt", "rb");
	if (fe == NULL)
	{
		printf("文件打开失败\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		fread(&names[all], sizeof(Student), 1, fe);
		if (feof(fe) != 0)
			break;
		all++;
	}

	tion = all;
	for (remove = 0; remove <= all; remove++)
	{
		tion = tion + 1;
		names[remove] = names[tion];
	}

	fclose(fe);



	FILE* fa = fopen("学生成绩管理系统.txt", "w");
	if (fa == NULL)
	{
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}
	for (remove = 0; remove <= all; remove++)
	{
		if (names[remove].number != 0)
			fwrite(&names[remove], sizeof(Student), 1, fe);
	}
	fclose(fe);
	puts("清空完成");
}

