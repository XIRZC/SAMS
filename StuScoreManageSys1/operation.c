#include<stdio.h>
#include "operation.h"
#include "calculate.h"
#include<string.h>
#include<stdlib.h> 
#include<ctype.h> 

extern int count;
extern stu stus[50],zero;

void IDCorrect(long long *IDpt)   //ѧ�ž������� 
{
	int num=IDCount(*IDpt);
	while(*IDpt<=0||num!=12)
	{
		if(*IDpt<=0) 
			printf("�������ѧ��С�ڵ���0 !!!\n");
		if(num!=12)
			printf("�������ѧ��λ����Ϊ12λ !!!\n");
		printf("���������룺"); 
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
	"ѧ��","����","�Ա�","�꼶","��ѧ","Ӣ��","����","c����","GPA","��ǰ����");
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
		printf("�޷��ϸ÷����ε�ѧ����Ϣ������\n");
	return;
} 
void scoreSegmentOne(char order,int *sign)
{
	int lowLim,highLim,i;
	printf("��������Ҫɸѡ���ķ����ε������ޣ�");
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
	printf("������һ��ѧ����ѧ�š��������Ա��꼶���ߵ���ѧ��Ӣ���д���������Լ�c���Գɼ���\n");
	scanf("%lld %s %s %d %f %f %f %f", &stus[count-1].ID, stus[count-1].name, stus[count-1].sex,&stus[count-1].grade, &stus[count-1].math,
		&stus[count-1].english, &stus[count-1].sports,  &stus[count-1].cScore);
	IDCorrect(&stus[count-1].ID);
	stus[count - 1].GPA = calGPA(stus[count - 1].math, stus[count - 1].english, stus[count - 1].sports, stus[count - 1].cScore);
	stus[count-1].flag[0]=stus[count-1].flag[1]=stus[count-1].flag[2]=stus[count-1].flag[3]=0;
	//write();
	printf("��ѧ����Ϣ�����\n"); 
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
		printf("ѧ����Ϣ�����ڣ����������룬");
		num=find();
	}
	printf("��Ҫ�޸ĵ�");
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
					printf("����������ѧ����Ϣ��������ѧ�ţ���");
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
		printf("�����ڸ�ѧ������Ϣ������������,");
		num=find();
	}
	stus[num].ID = stus[num].grade = stus[num].math = stus[num].math = stus[num].english = stus[num].sports = stus[num].cScore = stus[num].GPA = stus[num].rank = 0;
	strcpy(stus[num].name, "\000\000\000\000\000\000\000\000\000");
	strcpy(stus[num].sex,"\000\000\000\000");
	sort(7,0);
	count--;
	//write();
	printf("��ѧ����Ϣ�ѳɹ�ɾ��\n"); 
	return;
}

int find(void)
{
	long long ID;
	int num, i;
	if(count==0)
		finalCount();
	//read();
	printf("�������ѧ����ѧ�ţ�");
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
	static int num[10]={0};   //��ͬ���Ƶ������±�洢������ 
	int i,order=0,flag=0;
	if(count==0)
		finalCount();
	//read();
	printf("������Ҫ���ҵ�ѧ����������");
	gets(name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(name,stus[i].name)==0)
		{
			num[order+1] = i;
			order++;
			flag=1;
		}
		else if(i==count-1&&flag==0)  //δ�ҵ� 
			return NULL;
	}
	num[0]=order;
	return num;
} 
void order(void)
{
	printf("\n");
	printf(
		"---------------����ѡ��˵�-----------------\n"
		"0.  �˳�\n"
		"1.  �鿴һ��ѧ�Ŷ�Ӧ��ѧ����Ϣ\n"
		"2.  �༭һ��ѧ�Ŷ�Ӧ��ѧ����Ϣ\n"
		"3.  ɾ��һ��ѧ�Ŷ�Ӧ��ѧ����Ϣ\n"
		"4.  ���һ��ѧ�Ŷ�Ӧ��ѧ����Ϣ\n"
		"5.  �鿴��רҵ�µ�ѧ����Ϣ��\n"
		"6.  ���ĿƷ�����ɸѡѧ����Ϣ\n"
		"7.  ����ͬ���ݽ�����������\n" 
		"8.  ���õ�ǰ�ļ���ȡ���ݵ��ļ�����\n"
		"------------------------------------------\n");
	printf("������Ҫ���еĲ�����ţ�");
	return;
}
void orderEdit(void)
{
	printf("\n");
	printf(
		"-----------------�༭ѡ�------------------\n"
		"0.  ȫ��\n"
		"1.  ����\n"
		"2.  �Ա�\n"
		"3.  �꼶\n"
		"4.  �ߵ���ѧ�ɼ�\n"
		"5.  Ӣ���д�ɼ�\n"
		"6.  �����ɼ�\n"
		"7.  c���Գɼ�\n"
		"-------------------------------------------\n");
	printf("������Ҫ�޸ĵ�ѡ��,�Կո����,ENTER��������������Ҫ�޸ĵ���Ϣ��\n");
	return;
}
void orderSegment(void)
{
	printf("\n");
	printf(
		"----------��ȡ�����˵�----------\n"
		"1. �ߵ���ѧ������ȡ\n"
		"2. Ӣ���д������ȡ\n"
		"3. ����������ȡ\n"
		"4. c���Է�����ȡ\n"
		"---------------------------------\n");
	printf("������Ҫ��ȡ�����Ŀ�Ŀ���ɶ�ѡ��");
	return;
 }
 void orderSort(void)
{
	printf("\n");
	printf(
		"--------------����˵�-------------\n" 
		"1. ��ѧ������\n"
		"2. ��GPA����\n"
		"3. ���ߵ���ѧ�ɼ�����\n"
		"4. ��Ӣ���д�ɼ�����\n"
		"5. �������ɼ�����\n" 
		"6. ��c���Գɼ�����\n"
		"��ʾ����������˵�ѡ���������0������1������\n"
		"-----------------------------------\n");
	printf("������Ҫѡ�������ѡ�"); 
	return;
}
void orderFind(void)
{
	printf("\n");
	printf(
		"--------------���Ҳ˵�-------------\n" 
		"1. ��ѧ�Ų���\n"
		"2. ����������\n"
		"-----------------------------------\n");
	printf("���������ѡ�");
	return; 
}
void orderFile(void)
{
	printf("\n");
	printf(
	"-------------�ļ�����ѡ�--------------\n" 
	"1. �Զ������ļ���ȡ���ݣ���ȡ�죬�����ٶȿ�\n"
	"2. ���ַ����ļ���ȡ���ݣ���ȡ���������ڱ༭���б༭�Ͳ鿴��������\n"
	"-----------------------------------------\n");
	printf("�������ļ�����ѡ�");
	return;
}
void clear(void)
{
	printf("-----����������ز˵�-----\n");
	getch();
	system("cls");
}
void outputOne(int num)
{
	//read();
	//sort(1); 
	printf("ѧ�������ϢΪ��\n");
	printf("%-14s%-12s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-10s\n","ѧ��","����","�Ա�","�꼶","��ѧ","Ӣ��","����","c����","GPA","��ǰ����");
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
	printf("%-14s%-12s%-8s%-8s%-8s%-8s%-8s%-8s%-8s%-10s\n","ѧ��","����","�Ա�","�꼶","��ѧ","Ӣ��","����","c����","GPA","��ǰ����");
	for (i = 0; i < count; i++)
	{
		printf("%-14lld%-12s%-8s%-8d%-8.2f%-8.2f%-8.2f%-8.2f%-8.5f%-10d\n",
			stus[i].ID, stus[i].name, stus[i].sex, stus[i].grade, stus[i].math,
			stus[i].english, stus[i].sports, stus[i].cScore, stus[i].GPA, stus[i].rank);
	}
	//write();
	return;
}
