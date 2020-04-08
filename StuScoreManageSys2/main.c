//学生成绩管理系统-main()函数
#include<stdio.h>
#include<stdlib.h>
#include "calculate.h"
extern stu stus[50];
int file=1;  //存储数据的文件类型,默认以二进制形式，可设置 
extern int count; 
int main(void)
{
	int choice,num,sortOrder,sortInverse,byName,*Num,i;  
	//菜单序号，查找后的数组下标，排序选项，排序正反 ,是否使用姓名查找 ,存多个相同名称的数组下标指针,
	char same,fileName[15]={'\0'};   //是否继续执行相同的功能,要打开的文件名 
	printf("-------------学生成绩微管理系统---------------\n");
	order();
	scanf("%d", &choice);
	while (choice!=0)
	{
		switch (choice)
		{
			case 1:
				//因为输出需要排名，查找时需要提前排好序
				orderFind();
				scanf("%d",&byName); 
				getchar();   //吃换行符，以防止影响后续输入 
				if(byName==2)
				{
					Num=find_name();
					while(Num==NULL)
					{
						printf("不存在该学生的信息，请重新输入,");
						Num=find_name();
					}
					printf("%-14s%-12s%-8s%-8s%-10s%-8s%-8s%-8s%-8s%-8s%-10s\n","学号","姓名","性别","年级","专业","数学","英语","体育","c语言","GPA","当前排名");
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
						printf("不存在该学生的信息，请重新输入,");
						num=find();
					}
					outputOne(num);
				}
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("各项需要排序的数据为：\n");
				outputAll();
				orderSort();
				scanf("%d",&sortOrder); 
				printf("请输入升降序选项：");
				scanf("%d",&sortInverse);
				sort(sortOrder,sortInverse);
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				count=0;   //相当于重新打开程序来打开一个文件，因此需赋值为0 
				scanf("%d",&file);
				printf("是否需要继续执行该功能,0继续，1退出：");
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
				printf("请输入要打开的文件名：");
				if(fileName[0]!='\0')
					write(fileName);
				toZero();
				getchar();
				gets(fileName);
				while(!finalCount(fileName))
				{
					printf("请重新输入要打开的文件名：");
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
