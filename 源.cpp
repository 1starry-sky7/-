#define _CRT_SECURE_NO_WARNINGS
#include"Դ1.h"
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
			total(a2);//������Ϣ
			a2++;
			break;
		}
		case 2:Print();//�����Ϣ
			break;
		case 3:del();//ɾ����Ϣ
			break;
		case 4:whole();//��ʾ������Ϣ
			break;
		case 5:update();//�޸���Ϣ
			break;
		case 6:count();//ѧ������
			break;
		case 7:ranking();//�ɼ�����
			break;
		case 8:Del_all();//ɾ��ȫ��
			break;
		case 9://��������
			return 0;
		}
		query();
	}
	puts("������������½���");
	return 0;
}


//ѡ�����
void query()
{
	printf("*********************************\n");
	printf("*\tѧ���ɼ�����ϵͳ\t*\n");
	printf("*********************************\n");
	printf("*\t1:���ѧ����Ϣ\t\t*\n");
	printf("*\t2:��ѯѧ����Ϣ\t\t*\n");
	printf("*\t3:ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t4:��ʾѧ����Ϣ\t\t*\n");
	printf("*\t5:�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t6:ͳ��ѧ������\t\t*\n");
	printf("*\t7:ѧ���ɼ�����\t\t*\n");
	printf("*\t8:���ѧ����Ϣ\t\t*\n");
	printf("*\t9:�˳�����\t\t*\n");
	printf("*********************************\n");
}



//¼����Ϣ
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
	fp = fopen("ѧ���ɼ�����ϵͳ.txt", "ab+");//��ĩβ��д
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


//ѧ����Ϣ����
int ShowStudent()
{
	int show = 0;
	FILE* fs = fopen("ѧ���ɼ�����ϵͳ.txt", "ab+");
	if (fs == NULL)
	{
		printf("�ļ���ʧ��");
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

//�����Ϣ
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
	fp1 = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
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


//�ɼ�
void ScoreStudent(float* n)
{
	scanf("%f", n);
	while (*n < 0 || *n>100)
	{
		printf("Grade error re_enter:");
		scanf("%f", n);

	}
}

//ѧ��
void StudentID(long* n2)
{
	int sd = 0;
	int tu;

	FILE* fs = fopen("ѧ���ɼ�����ϵͳ.txt", "ab+");
	if (fs == NULL)
	{
		printf("�ļ���ȡ��ʧ��");
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
					printf("ѧ���ظ����������룺");
					break;
				}
				else if (tu == sd)
					return;
			}

		}
		else
			printf("���������������");
		getchar();
	}
	fclose(fs);
}

//����
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


//����
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

//�Ա�
void GenderStudent(char* st)
{
	int gs;

	while (1)
	{
		printf("\n1:��      2:Ů��");
		scanf("%d", &gs);
		getchar();
		if (gs == 1)
		{
			char gen[10] = { "��" };
			strcpy(st, gen);
			return;
		}
		else if (gs == 2)
		{
			char gen[10] = { "Ů" };
			strcpy(st, gen);
			return;
		}
		else
		{
			printf("����������");
		}
	}
}


//ɾ����Ϣ
void del()
{
	long n;
	int dw = 0;//ͳ��ѧ������
	printf("����Ҫɾ����ѧ�ţ�");
	while (scanf("%ld", &n) && (n < 100000 || n>999999))
	{
		getchar();
		if (n >= 100000 && n <= 999999)
			break;
		printf("ѧ�Ŵ�����������");
	}

	FILE* fp = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��޷�����\n");
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
		puts("û�д洢ѧ����Ϣ\n");
		return;
	}
	dw = dw - 1;//��ȥ��һ��ѭ��
	fclose(fp);


	int wr;
	FILE* fw = fopen("ѧ���ɼ�����ϵͳ.txt", "w");
	if (fw == NULL)
	{
		printf("�ļ���ʧ�ܣ��޷�д��\n");
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
			printf("ѧ�Ų�����");
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
	printf("ɾ���ɹ�\n");
	getchar();
	fclose(fw);
}


//��ѯ������Ϣ
void whole()
{
	int wh = 0;
	int wh1;
	FILE* fw;
	fw = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fw == NULL)
	{
		printf("�ļ���ʧ��");
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
		puts("û��ѧ����Ϣ");
		return;
	}
	else
	{

		for (wh1 = 0; wh1 < wh; wh1++)
		{

			printf("��%dλѧ����Ϣ\n", wh1 + 1);
			printf("������%s ", names[wh1].name);
			printf("�Ա�%s ", names[wh1].gender);
			printf("���䣺%d ", names[wh1].age);
			printf("ѧ�ţ�%ld\n", names[wh1].number);
			printf("���ĳɼ���%.2f  ", names[wh1].Chinese);
			printf("��ѧ�ɼ���%.2f  ", names[wh1].Mathematics);
			printf("���Գɼ���%.2f  \n\n", names[wh1].English);

		}
	}
	fclose(fw);
}

//�޸���Ϣ
void update()
{
	long n;
	int da = 0;//�洢�±�
	int te;//�˶���Ϣ�±�
	printf("����Ҫ�޸�ѧ����Ϣ��ѧ�ţ�");
	scanf("%ld", &n);
	while (n < 100000 && n>999999)
	{
		printf("ѧ�Ÿ�ʽ��������������:");
		int up = scanf("%ld", &n);
		if (up != 1)
		{
			printf("������6λ����ѧ��\n");
			getchar();
		}
	}
	getchar();
	FILE* fu = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fu == NULL)
	{
		printf("�ļ���ʧ��");
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
			printf("û�и�ѧ����Ϣ\n");
			return;
		}
	}

	fclose(fu);
	printf("��ʼ�޸���Ϣ\n");
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

	FILE* ft = fopen("ѧ���ɼ�����ϵͳ.txt", "wb");
	if (ft == NULL)
	{
		printf("�޷����ļ�,д��ʧ��");
		exit(EXIT_FAILURE);
	}

	for (te = 0; te <= da; te++)
	{
		if (names[te].number != 0)
			fwrite(&names[te], sizeof(Student), 1, ft);
	}
	fclose(ft);
	printf("���ĳɹ�\n");

}


//ͳ��ѧ������
void count()
{
	int co = 0;
	FILE* fc = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fc == NULL)
	{
		printf("�ļ�ֻ��ʧ��");
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
		puts("û��ѧ����Ϣ");
		return;
	}
	else
	{
		printf("ѧ����������%d\n", co);

	}
}

//���ɼ�����
void ranking()
{
	int ing = 0;//�±�
	int ran;//ƥ���±�
	FILE* fr = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fr == NULL)
	{
		printf("�ļ�ֻ��ʧ��");
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
		printf("û��ѧ����Ϣ\n");
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
			printf("������1\n");
			printf("������%s ", names[ae].name);
			printf("�Ա�%s ", names[ae].gender);
			printf("���䣺%d ", names[ae].age);
			printf("ѧ�ţ�%ld\n", names[ae].number);
			printf("���ĳɼ���%.1f  ", names[ae].Chinese);
			printf("��ѧ�ɼ���%.1f  ", names[ae].Mathematics);
			printf("���Գɼ���%.1f  \n", names[ae].English);
			printf("�ܳɼ���%.1f\n", names[ae].close);
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
		printf("������%d\n", ae + 1);
		printf("������%s ", names[ae].name);
		printf("�Ա�%s ", names[ae].gender);
		printf("���䣺%d ", names[ae].age);
		printf("ѧ�ţ�%ld\n", names[ae].number);
		printf("���ĳɼ���%.1f  ", names[ae].Chinese);
		printf("��ѧ�ɼ���%.1f  ", names[ae].Mathematics);
		printf("���Գɼ���%.1f  \n", names[ae].English);
		printf("�ܳɼ���%.1f\n\n", names[ae].close);

	}
	fclose(fr);
}


//ɾ��������Ϣ
void Del_all()
{
	int all = 0;
	int remove;
	int tion;
	FILE* fe = fopen("ѧ���ɼ�����ϵͳ.txt", "rb");
	if (fe == NULL)
	{
		printf("�ļ���ʧ��\n");
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



	FILE* fa = fopen("ѧ���ɼ�����ϵͳ.txt", "w");
	if (fa == NULL)
	{
		printf("�ļ���ʧ��");
		exit(EXIT_FAILURE);
	}
	for (remove = 0; remove <= all; remove++)
	{
		if (names[remove].number != 0)
			fwrite(&names[remove], sizeof(Student), 1, fe);
	}
	fclose(fe);
	puts("������");
}

