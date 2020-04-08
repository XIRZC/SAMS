#include<stdio.h>
#include "operation.h"
#include "calculate.h"
#include<string.h>
#include<stdlib.h> 
#include<ctype.h> 

extern int count;
extern stu stus[50],zero;

void IDCorrect(long long *IDpt)   //学号纠正函数 
{
	int num=IDCount(*IDpt);
	while(*IDpt<=0||num!=12)
	{
		if(*IDpt<=0) 
			printf("所输入的学号小于等于0 !!!\n");
		if(num!=12)
			printf("所输入的学号位数不为12位 !!!\n");
		printf("请重新输入："); 
		scanf("%lld",IDpt);
	 	num=IDCount(*IDpt);
	}
	return;
}
void scoreSegment(void)
{
	int i,length,num=0,judge=1,j;
	char order[10];
	int sign[4]={0,0,0,0};
	if(count==0)
		finalCount();
	//read();
	orderSegment();
	getchar();
	gets(order);
	length=strlen(order);
	for(i=0;i<length;i++)
	{
		if(!isdigit(order[i]))
			continue;
		else
			scoreSegmentOne(order[i],sign);
	}
	printf("%-14s%-12s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-10s\n",
	"学号","姓名","性别","年级","数学","英语","体育","c语言","GPA","当前排名");
	for(i=0;i<count;i++)
	{
		judge=1;
		for(j=0;j<4;j++)
		{
			if(sign[j])
				judge=judge&&(stus[i].flag[j]);
		}
		if(judge)
		{
 			printf("%-14lld%-12s%-8s%-8d%-8.2f%-8.2f%-8.2f%-8.2f%-8.5f%-10d\n",stus[i].ID, stus[i].name, stus[i].sex, stus[i].grade, stus[i].math,
			stus[i].english, stus[i].sports, stus[i].cScore, stus[i].GPA, stus[i].rank);
			num++;
		}
	}
	if(num==0)
		printf("无符合该分数段的学生信息！！！\n");
	return;
} 
void scoreSegmentOne(char order,int *sign)
{
	int lowLim,highLim,i;
	printf("请输入需要筛选出的分数段的下上限：");
	scanf("%d %d",&lowLim,&highLim);
	switch(order)
	{
		case '1':
			sign[0]=1;
			for(i=0;i<count;i++) 
			{
				if(stus[i].math>=lowLim&&stus[i].math<=highLim)
					stus[i].flag[0]=1;
			}
			break;
		case '2':
			sign[1]=1;
			for(i=0;i<count;i++) 
			{
				if(stus[i].english>=lowLim&&stus[i].english<=highLim)
					stus[i].flag[1]=1;
			}
			break;
		case '3':
			sign[2]=1;
			for(i=0;i<count;i++) 
			{
				if(stus[i].sports>=lowLim&&stus[i].sports<=highLim)
					stus[i].flag[2]=1;
			}
			break;
		case '4':
			sign[3]=1;
			for(i=0;i<count;i++) 
			{
				if(stus[i].cScore>=lowLim&&stus[i].cScore<=highLim)
					stus[i].flag[3]=1;
			}
			break;	
	}	
	return;
}
 
void scoreInsert(void)
{
	if(count==0)
		finalCount();
	count++;
	//read();
	printf("请输入一个学生的学号、姓名、性别、年级、高等数学、英语读写、体育、以及c语言成绩：\n");
	scanf("%lld %s %s %d %f %f %f %f", &stus[count-1].ID, stus[count-1].name, stus[count-1].sex,&stus[count-1].grade, &stus[count-1].math,
		&stus[count-1].english, &stus[count-1].sports,  &stus[count-1].cScore);
	IDCorrect(&stus[count-1].ID);
	stus[count - 1].GPA = calGPA(stus[count - 1].math, stus[count - 1].english, stus[count - 1].sports, stus[count - 1].cScore);
	stus[count-1].flag[0]=stus[count-1].flag[1]=stus[count-1].flag[2]=stus[count-1].flag[3]=0;
	//write();
	printf("该学生信息已添加\n"); 
	return;
}

void scoreEdit(void)
{
	long long ID;
	int i,num,length;
	char order[10];
	if(count==0)
		finalCount();
	//read();
	num=find();
	while(num<0)
	{
		printf("学生信息不存在，请重新输入，");
		num=find();
	}
	printf("你要修改的");
	outputOne(num); 
	orderEdit();
	getchar();
	gets(order);
	length=strlen(order);
	for(i=0;i<length;i++)
	{
		if (!isdigit(order[i]))
			continue;
		else
		{
			switch (order[i])
			{
				case '0':
					printf("请输入所有学生信息（不包括学号）：");
					scanf("%s %s %d %f %f %f %f", stus[num].name, &stus[num].sex, &stus[num].grade, &stus[num].math,
						&stus[num].english, &stus[num].sports, &stus[num].cScore);
					break;
				case '1':
					scanf("%s", stus[num].name);
					break;
				case '2':
					scanf("%s", &stus[num].sex);
					break;
				case '3':
					scanf("%d", &stus[num].grade);
					break;
				case '4':
					scanf("%f", &stus[num].math);
					break;
				case '5':
					scanf("%f", &stus[num].english);
					break;
				case '6':
					scanf("%f", &stus[num].sports);
					break;
				case '7':
					scanf("%f", &stus[num].cScore);
					break;
			}
		}
	}
	stus[num].GPA=calGPA(stus[num].math,stus[num].english,stus[num].sports,stus[num].cScore);
	//write();
	return;
}

void scoreDelete(void)
{
	int num, i;
	if(count==0)
		finalCount();
	//read();
	num=find();
	while(num<0)
	{			
		printf("不存在该学生的信息，请重新输入,");
		num=find();
	}
	stus[num].ID = stus[num].grade = stus[num].math = stus[num].math = stus[num].english = stus[num].sports = stus[num].cScore = stus[num].GPA = stus[num].rank = 0;
	strcpy(stus[num].name, "\000\000\000\000\000\000\000\000\000");
	strcpy(stus[num].sex,"\000\000\000\000");
	sort(7,0);
	count--;
	//write();
	printf("该学生信息已成功删除\n"); 
	return;
}

int find(void)
{
	long long ID;
	int num, i;
	if(count==0)
		finalCount();
	//read();
	printf("请输入该学生的学号：");
	scanf("%lld", &ID);
	IDCorrect(&ID);
	for (i = 0; i < count; i++)
	{
		if (stus[i].ID == ID)
		{
			num = i;
			break;
		}
		else if(i==count-1)
			return -1;
	}
	return num;
}
int *find_name(void)
{
	char name[10];
	static int num[10]={0};   //相同名称的数组下标存储的数组 
	int i,order=0,flag=0;
	if(count==0)
		finalCount();
	//read();
	printf("请输入要查找的学生的姓名：");
	gets(name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name,stus[i].name)==0)
		{
			num[order+1] = i;
			order++;
			flag=1;
		}
		else if(i==count-1&&flag==0)  //未找到 
			return NULL;
	}
	num[0]=order;
	return num;
} 
void order(void)
{
	printf("\n");
	printf(
		"---------------功能选项菜单-----------------\n"
		"0.  退出\n"
		"1.  查看一个学号对应的学生信息\n"
		"2.  编辑一个学号对应的学生信息\n"
		"3.  删除一个学号对应的学生信息\n"
		"4.  添加一个学号对应的学生信息\n"
		"5.  查看该专业下的学生信息表\n"
		"6.  以四科分数段筛选学生信息\n"
		"7.  按不同数据进行升降排序\n" 
		"8.  设置当前文件存取数据的文件类型\n"
		"------------------------------------------\n");
	printf("请输入要进行的操作序号：");
	return;
}
void orderEdit(void)
{
	printf("\n");
	printf(
		"-----------------编辑选项卡------------------\n"
		"0.  全部\n"
		"1.  姓名\n"
		"2.  性别\n"
		"3.  年级\n"
		"4.  高等数学成绩\n"
		"5.  英语读写成绩\n"
		"6.  体育成绩\n"
		"7.  c语言成绩\n"
		"-------------------------------------------\n");
	printf("请输入要修改的选项,以空格隔开,ENTER后续再依次输入要修改的信息：\n");
	return;
}
void orderSegment(void)
{
	printf("\n");
	printf(
		"----------提取分数菜单----------\n"
		"1. 高等数学分数提取\n"
		"2. 英语读写分数提取\n"
		"3. 体育分数提取\n"
		"4. c语言分数提取\n"
		"---------------------------------\n");
	printf("请输入要提取分数的科目，可多选：");
	return;
 }
 void orderSort(void)
{
	printf("\n");
	printf(
		"--------------排序菜单-------------\n" 
		"1. 按学号排序\n"
		"2. 按GPA排序\n"
		"3. 按高等数学成绩排序\n"
		"4. 按英语读写成绩排序\n"
		"5. 按体育成绩排序\n" 
		"6. 按c语言成绩排序\n"
		"提示：输入排序菜单选项后，再输入0：降序，1：升序\n"
		"-----------------------------------\n");
	printf("请输入要选择的排序选项："); 
	return;
}
void orderFind(void)
{
	printf("\n");
	printf(
		"--------------查找菜单-------------\n" 
		"1. 按学号查找\n"
		"2. 按姓名查找\n"
		"-----------------------------------\n");
	printf("请输入查找选项：");
	return; 
}
void orderFile(void)
{
	printf("\n");
	printf(
	"-------------文件类型选项卡--------------\n" 
	"1. 以二进制文件存取数据：存取快，运行速度快\n"
	"2. 以字符串文件存取数据：存取满，但可在编辑器中编辑和查看所有数据\n"
	"-----------------------------------------\n");
	printf("请输入文件类型选项：");
	return;
}
void clear(void)
{
	printf("-----按任意键返回菜单-----\n");
	getch();
	system("cls");
}
void outputOne(int num)
{
	//read();
	//sort(1); 
	printf("学生相关信息为：\n");
	printf("%-14s%-12s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-10s\n","学号","姓名","性别","年级","数学","英语","体育","c语言","GPA","当前排名");
 	printf("%-14lld%-12s%-8s%-8d%-8.2f%-8.2f%-8.2f%-8.2f%-8.5f%-10d\n",stus[num].ID, stus[num].name, stus[num].sex, stus[num].grade, stus[num].math,
			stus[num].english, stus[num].sports, stus[num].cScore, stus[num].GPA, stus[num].rank);
	return;
}
void outputAll()
{
	int i;
	if(count==0)
		finalCount();
	//read();
	//sort(1);
	printf("%-14s%-12s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-10s\n","学号","姓名","性别","年级","数学","英语","体育","c语言","GPA","当前排名");
	for (i = 0; i < count; i++)
	{
		printf("%-14lld%-12s%-8s%-8d%-8.2f%-8.2f%-8.2f%-8.2f%-8.5f%-10d\n",
			stus[i].ID, stus[i].name, stus[i].sex, stus[i].grade, stus[i].math,
			stus[i].english, stus[i].sports, stus[i].cScore, stus[i].GPA, stus[i].rank);
	}
	//write();
	return;
}
