//ѧ���ɼ�����ϵͳ-main()����
#include<stdio.h>
#include<stdlib.h>
#include "calculate.h"
extern stu stus[50];
int file=1;  //�洢���ݵ��ļ�����,Ĭ���Զ�������ʽ�������� 
extern int count; 
int main(void)
{
	int choice,num,sortOrder,sortInverse,byName,*Num,i;  
	//�˵���ţ����Һ�������±꣬����ѡ��������� ,�Ƿ�ʹ���������� ,������ͬ���Ƶ������±�ָ��,
	char same,fileName[15]={'\0'};   //�Ƿ����ִ����ͬ�Ĺ���,Ҫ�򿪵��ļ��� 
	printf("-------------ѧ���ɼ�΢����ϵͳ---------------\n");
	order();
	scanf("%d", &choice);
	while (choice!=0)
	{
		switch (choice)
		{
			case 1:
				//��Ϊ�����Ҫ����������ʱ��Ҫ��ǰ�ź���
				orderFind();
				scanf("%d",&byName); 
				getchar();   //�Ի��з����Է�ֹӰ��������� 
				if(byName==2)
				{
					Num=find_name();
					while(Num==NULL)
					{
						printf("�����ڸ�ѧ������Ϣ������������,");
						Num=find_name();
					}
					printf("%-14s%-12s%-8s%-8s%-10s%-8s%-8s%-8s%-8s%-8s%-10s\n","ѧ��","����","�Ա�","�꼶","רҵ","��ѧ","Ӣ��","����","c����","GPA","��ǰ����");
					for(i=1;i<=Num[0];i++)
					{
						printf("%-14lld%-12s%-8s%-8d%-10s%-8.2f%-8.2f%-8.2f%-8.2f%-8.5f%-10d\n",stus[Num[i]].ID, stus[Num[i]].name, stus[Num[i]].sex, stus[Num[i]].grade, 
						stus[Num[i]].major,stus[Num[i]].math,stus[Num[i]].english, stus[Num[i]].sports, stus[Num[i]].cScore, stus[Num[i]].GPA, stus[Num[i]].rank);
					}
				}
				else if(byName==1)
				{
					num=find();
					while(num<0)
					{
						printf("�����ڸ�ѧ������Ϣ������������,");
						num=find();
					}
					outputOne(num);
				}
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=1;
					continue;
				}
				clear();
				break;
			case 2:
				scoreEdit();
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=2;
					continue;
				}
				clear();
				break;
			case 3:
				scoreDelete();
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=3;
					continue;
				}
				clear();
				break;
			case 4:
				scoreInsert();
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=4;
					continue;
				}
				clear();
				break;
			case 5: 
				outputAll();
				clear(); 
				break;
			case 6:
				scoreSegment();
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=6;
					continue;
				}
				clear();
				break;
			case 7:
				printf("������Ҫ���������Ϊ��\n");
				outputAll();
				orderSort();
				scanf("%d",&sortOrder); 
				printf("������������ѡ�");
				scanf("%d",&sortInverse);
				sort(sortOrder,sortInverse);
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=7;
					continue;
				}
				clear();
				break;
			case 8:
				write(fileName);
				toZero();
				orderFile();
				count=0;   //�൱�����´򿪳�������һ���ļ�������踳ֵΪ0 
				scanf("%d",&file);
				printf("�Ƿ���Ҫ����ִ�иù���,0������1�˳���");
				same=getche();
				printf("\n");
				if(same=='0')
				{
					choice=8;
					continue;
				}
				clear();
				break;
			case 9:
				printf("������Ҫ�򿪵��ļ�����");
				if(fileName[0]!='\0')
					write(fileName);
				toZero();
				getchar();
				gets(fileName);
				while(!finalCount(fileName))
				{
					printf("����������Ҫ�򿪵��ļ�����");
					gets(fileName);
				}
				read(fileName);
				clear();
				break;	
		}
		printf("\n"); 
		order();
		scanf("%d", &choice);
	}
	return 0;
}
