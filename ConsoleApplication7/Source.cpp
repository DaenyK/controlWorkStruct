#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>

#define max30 30



enum spec
{
	������, �������, �������
};

struct age {
	int year;
	int month;
	int day;
};

void generateAge(age *t)
{
	t->day = 1 + rand() % 30;
	t->month = 1 + rand() % 11;
	t->year = 1950 + rand() % 60;
}

void generateName(char *name, int type = 0)
{
	if (type == 0)
		strcpy(name, "person #");
	else
		strcpy(name, "kurs #");

	int a = 1 + rand() % 30;

	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}
void generateSpec(char *name)
{
	int a = 0 + rand() % 3;

	if (a == 0)
	name = "tokar";
	else if (a == 1)
		name = "slesar";
	else if (a == 1)
		name = "rabochiy";
}



struct zavodNames
{
	char* name;
};

struct group
{
	char *name;
	age * Age;
	int * ses;
};

struct student
{
	int id;
	char * name;
	age * Age;
	int * ses;
	char *kurs;
	double srBal;
};

void sortSES(int* a, int r)
{
	int temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

void sortName(student* a, int r)
{
	student temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->id > (a + j)->id)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}

struct blacknote {
	char *name;
	char*phone;
	age age;
};

void signs(int*a, char *b)
{
	//int count5 = 0, count4 = 0, count3 = 0, count2 = 0;
	int sum = 0;
	for (int i = 0;i < 10; i++)
	{
		sum += a[i];
	}

	if (sum / 10 >= 9)
	{
		b = (char*)calloc(10, sizeof(char));
		b = "��������";
		printf("%s", b);
	}

	else if (sum / 10 >= 6)
	{
		b = (char*)calloc(10, sizeof(char));
		b = "��������";
		printf("%s", b);
	}

	else if (sum / 10 >= 4)
	{
		b = (char*)calloc(10, sizeof(char));
		b = "��������";
		printf("%s", b);
	}

	else	if (sum / 10 >= 1)
	{
		b = (char*)calloc(15, sizeof(char));
		b = "������������";
		printf("%s", b);
	}
}


int assessments(int *a, int srOc)
{
	int sum = 0;
	for (int i = 0;i < 10; i++)
	{
		a[i] = 1 + rand() % 10;
		sum += a[i];
		printf("%d ", a[i]);
	}
	srOc = sum / 10;
	return srOc;
}

struct learn
{
	char *name;
	int * rating;
	char* sign;
	int srb;
};


void sortStudentsLearn(learn *a, int r)
{
	learn temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->srb < (a + j)->srb)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}

		}
	}
}

struct zavod
{
	char*name;
	int age;
	char *spec;
	int  oklad;
};

void main()
{

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int n, exit;

	do
	{
		printf("please enter exemple: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*2.	������������ ������ ��������, ������ ������� �������� �������� ��������� ��� ���� :
			a.�������, ��� �������� ��������(������);
			b.������ ������ � �������������� �������(������);
			c.�������

				��� ������� �������� �������� ���� �� ��������� �������� �������� : 5 � ��������(������ 9 �(���) 10),
				4 � ��������(��� ������, ������ 6, �� �� ��� 9 ��� 10, � ���� 6 �(���) 7 �(���) 8), 3 � ��������(��� ������, ������ 4, �� ���� 4
					�(���) 5), 2 � ������������(���� 1 �(���) 2 �(���) 3).
				�������������� ������ �������� �� �������� ����������� ��������.*/

				//�������  ��� ������ ��������� ����� �����������, ��� ��� ������� �� �������� ����� ���������
			int a = 1 + rand() % 10;
			printf("���-�� ���������: %d\n", a);

			learn *students = NULL;
			students = (learn*)malloc(a * sizeof(learn));
			int srOcenka[11], sroc = 0;

			if (students == NULL)
			{
				printf("������ �� ��������\n");
				system("exit");
			}
			else
			{
				for (int i = 0;i < a;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name); //�����

					(students + i)->rating = (int*)calloc(10, sizeof(int));
					printf("# %d \t %s, ��� ������ ", i + 1, (students + i)->name);
					sroc = assessments((students + i)->rating, sroc); // ������

					(students + i)->srb = (int)calloc(1, sizeof(int));
					(students + i)->srb = sroc;

					signs((students + i)->rating, (students + i)->sign); // �������
					printf("\n-------------------------------------------------------------\n");
				}

				sortStudentsLearn(students, a);
				printf("\n����� ��������� � ���������� �� ��������\n");
				//������ ������, ��� �������� ���������� ����� :D
				for (int i = 0;i < a;i++)
					printf("# %d \t %s \n", i + 1, (students + i)->name);
			}
		}break;

		case 2:
		{
			//4.	���������� �� N ������� ������ �������� ������� ���������� ���� : �������, ������� �������, �������������, ������� �����.
			//������ ���������� �� �������, ��������� ���������� �������� � �������.���������� ��� ��������.
			int n = 1 + rand() % 5;
			printf("���-�� �������: %d\n", n);

			zavod *zvd = NULL;
			zvd = (zavod*)malloc(n * sizeof(zavod));

			if (zvd == NULL)
			{
				printf("������ �� ��������\n");
				system("exit");
			}
			else
			{
				int k = 1 + rand() % 10;
				printf("���-�� ����� �� ������: %d\n", k);

				for (int i = 0;i < k;i++)
				{
					(zvd + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((zvd + i)->name);

					(zvd + i)->age = (int)malloc(sizeof(int));
					(zvd + i)->age = 25 + rand() % 35;

					(zvd + i)->oklad = (int)malloc(sizeof(int));
					(zvd + i)->oklad = 20000 + rand() % 10000;

					(zvd + i)->spec = (char*)malloc(20 * sizeof(char));
					generateSpec((zvd + i)->spec);

					printf("#%d \t %s; %d ���; %d ��; %s \n", i + 1, (zvd + i)->name, (zvd + i)->age, (zvd + i)->oklad, (zvd + i)->spec);

				}
			}
		}break;



		case 11:
		{
			/*1. ������� ��������� � ������ GROUP, ���������� ���� :
			a.Name � ������� � ��������
			b.DAT � ���� ��������(���, �����, �����)
			c.SES � ������������(������ �� ���� ���������).
			�������� ���������, �����������:
			� ���� � ���������� ������ � ������ GR5, ��������� �� 10 �������� ���� GROUP;
			����� �� ����� �������, ������������� �� ����������� ���� SES;
			� ����� ������ ���������, ������� ������� �� 01.12.2010 ���� �� ��������� 20 ���;
			� ���� ����� ��������� ��� � ������ ���������
			*/
			int a = 1 + rand() % 25;
			printf("���-�� ���������: %d\n", a);

			group *students = NULL;
			students = (group*)malloc(a * sizeof(group));

			if (students == NULL)
			{
				printf("������ �� ��������\n");
				system("exit");
				//exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0;i < a;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name);

					(students + i)->Age = (age*)malloc(1 * sizeof(age));
					generateAge((students + i)->Age);

					int k = (1 + rand() % 10);
					(students + i)->ses = (int*)calloc(k, sizeof(int));

					if ((2018 - (students + i)->Age->year) <= 20)
					{
						printf("# %d \t %s \t %d.%d.%d\n", i + 1, (students + i)->name,
							(students + i)->Age->day, (students + i)->Age->month, (students + i)->Age->year);
						int sum = 0;
						for (int j = 0; j < k; j++)
						{
							(students + i)->ses[j] = 2 + rand() % 4;
							//printf("--> %d\n", (students + i)->ses[j]);
							sum += (students + i)->ses[j];
						}
						printf("����� ����������:\n");
						sortSES((students + i)->ses, k);

						for (int j = 0; j < k; j++)
						{
							printf("--> %d\n", (students + i)->ses[j]);
						}

						if (k != 0)
						{
							printf("----------------------------------------\n");
							printf("������� ���� �������� ����������: %d\n", sum / k);
						}
					}
					else printf("������� %d ������ 20 ���\n", i + 1);
				}
			}


		}break;

		case 22:
		{
			int count = 5 + rand() % 30;
			printf("���-�� ���������: %d\n", count);
			int tSum = 0;
			student*students = NULL;
			students = (student*)malloc(count * sizeof(student));
			if (students != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					(students + i)->id = 5 + rand() % 1000;
					(students + i)->name = (char*)malloc(12 * sizeof(char)); //���
					generateName((students + i)->name);
					//printf("# %d \t %s \n", i + 1, (students + i)->name );

					(students + i)->Age = (age*)malloc(1 * sizeof(age)); //���� ��������
					generateAge((students + i)->Age);

					(students + i)->kurs = (char*)malloc(6 * sizeof(char));
					generateName((students + i)->kurs, 1);

					(students + i)->ses = (int*)malloc(3 * sizeof(int));

					int sum = 0;
					for (int j = 0; j < 5; j++)
					{
						(students + i)->ses[j] = 1 + rand() % 5;
						sum += (students + i)->ses[j];
					}
					(students + i)->srBal = sum / 5;
					tSum = (students + i)->srBal;
				}

				sortName(students, count);
				tSum = tSum / count;
				for (int i = 0; i < count; i++)
				{
					if ((students)->srBal > tSum)
					{

						printf("#%d \t %s \t %d \t (%s) - \t\t %lf\n",
							students->id, students->name, 2018 - (students->Age->year), students->kurs, students->srBal
						);
					}
					students++;
				}
			}

		}break;

		case 33:
		{
			blacknote *human = (blacknote*)malloc(sizeof(blacknote));

			while (exit == 1)
			{
				printf("������� ���: ");
				human->name = (char*)malloc(50 * sizeof(char));
				fgets(human->name, 50, stdin);

				printf("������� �������: ");
				human->phone = (char*)malloc(50 * sizeof(char));
				fgets(human->phone, 50, stdin);

				printf("������� ���� ��������: ");


				printf("����������? 1-Yes 2-No:");
				scanf("%d", &exit);
				printf("\n");
			};
		}break;


		}
		printf("����������? 1-Yes 2-No:");
		scanf("%d", &exit);
		printf("\n");
		system("cls");
	} while (exit == 1);
}
