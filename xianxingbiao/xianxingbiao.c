//ch2-1.c  学生成绩统计
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define MAXSIZE 30							//成绩表最大长度

//定义结构体类型
typedef struct								
{
	char no[10];								//学号
	char name[10];							//姓名
	int score[5];								//各科成绩
	int total;									//总成绩
}student;
typedef struct									//定义线性表类型
{
	student stu[MAXSIZE];						//用数组存储每个学生的成绩信息
	int len;									//线性表的实际长度
}SeqList;

//建立学生成绩统计表
SeqList create (SeqList L, int n)
{	
	int i, j;
	printf ("输入学生的学号、姓名、数学、英语、政治、专业课1和专业课2成绩：\n");
	for (i = 0; i < n; i ++)
	{
		scanf ("%s", L.stu[i].no);					//录入学号
		scanf ("%s", L.stu[i].name);				//录入姓名
		L.stu[i].total = 0;
		for ( j = 0; j < 5; j ++)
			{
			scanf ("%d", &L.stu[i].score[j]);		//录入各科目的成绩
			L.stu[i].total = L.stu[i].total + L.stu[i].score[j];//计算总成绩
    			}	
			printf ("您输入的第%d个学生的总成绩为：%d\n",i+1, L.stu[i].total);
		}
			return L;
}
//按照学号查询学生成绩信息
void search (SeqList L, int n)
{	
	int i, j, k=0;
	char *sno[10];
	printf ("输入要查询学生的学号：");
	while(k<3)
	{
        scanf ("%s", sno);
		for (i = 0; i < n; i ++)
		if (strcmp(sno, L.stu[i].no) == 0)			//字符串比较
		{
			printf ("查询结果：\n");
			printf ("%s  %s  ", L.stu[i].no, L.stu[i].name);
			for (j =0; j < 5; j ++)
			printf ("%d  ", L.stu[i].score[j]);
			printf ("%d  ", L.stu[i].total);
			return;
		}
		if ( i= n)	{ printf ("您输入的学号不对，请重新输入\n");k++; }
	}
	
						//查询失败，提示出错
}

//按照某个科目成绩升序排序
void sort (SeqList L, int n, int k)
{	
	int i, j;
	student p;	
	if (k >= 0 && k < n)
	{
		printf ("按照第[%d]门课程进行排序：", k);
		for (i = 0; i < n; i ++)					
			for (j = i + 1; j < n; j ++)
				if (L.stu[i].score[k] >= L.stu[j].score[k])
				{
					p = L.stu[i];
					L.stu[i] = L.stu[j];
					L.stu[j] = p;
				}
	}
	else
	{
		printf ("按照total进行排序，");
		for (i = 0; i < n - 1; i ++)
			for (j = i + 1; j < n; j ++)
				if (L.stu[i].total >= L.stu[j].total)
				{
					p = L.stu[i];
					L.stu[i] = L.stu[j];
					L.stu[j] = p;
				}
	}
printf ("排序后的成绩表如下：\n");
	for (i = 0; i < n; i ++)
	{
		printf ("%s  %s  ", L.stu[i].no, L.stu[i].name);
		for (j =0; j < 5; j ++)
			printf ("%d  ", L.stu[i].score[j]);
		printf ("%d\n", L.stu[i].total);
	}
}


SeqList insert (SeqList L, int n)           //插入
{	
	int i, j;
	printf ("输入要插入的学生的学号、姓名、数学、英语、政治、专业课1和专业课2成绩：\n");
	for (i = L.len; i < L.len+n; i++)
	{
		scanf ("%s", L.stu[i].no);					//录入学号
		scanf ("%s", L.stu[i].name);				//录入姓名
		L.stu[i].total = 0;
		for ( j = 0; j < 5; j ++)
			{
			scanf ("%d", &L.stu[i].score[j]);		//录入各科目的成绩
			L.stu[i].total = L.stu[i].total + L.stu[i].score[j];//计算总成绩
    		}	
			printf ("您输入的第%d个学生的总成绩为：%d\n",i+1, L.stu[i].total);
            printf ("此时表长度为：%d\n",i+1);
	}
	return L;
}

void show(SeqList L)
{
    int i, j;
    for (i = 0; i < L.len; i ++)
	{
		printf ("%s  %s  ", L.stu[i].no, L.stu[i].name);
		for (j =0; j < 5; j ++)
			printf ("%d  ", L.stu[i].score[j]);
		printf ("%d\n", L.stu[i].total);
	}
}
void main ()
{
	SeqList List;
	int num;
	printf ("输入学生人数：");
	scanf ("%d", &List.len);
	List = create (List, List.len);
	search (List, List.len);
	printf ("\n将学生成绩按照第几门成绩进行排序：");
	scanf ("%d", &num);
	printf ("将学生成绩排序\n");
	printf ("输入要排序的科目序号：");
	sort (List, List.len, num);
    printf ("请输入要插入的学生个数\n");
    scanf ("%d", &num);
    insert (List, num);
    List.len=List.len+num;
    printf ("\n显示所有表数据\n");
    show (List);    //显示所有表数据
}
