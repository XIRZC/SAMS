#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "calculate.h"

stu stus[50],zero,temp; 
int count=0; 
FILE *fpt;
char fName[20][15]; //用来读取文件名的实际存储地址 
char *filePt[20];   //存文件名的指针数组 
int countF=0;   //已添加的文件数 
char filename[15]; 
extern int file; 

char *getFileName(int grade,char *major)
{
	char gradeC=grade+'0';
	int length=strlen(major);
	strcpy(filename,major);
	filename[length]=gradeC;
	filename[length+1]='\0';
	return filename;
} 
int hasFileAdded(char *fileName)
{
	int i;
	FILE *npt;
	if(countF==0)
		calCountF();
	else
		readFpt();
	for(i=0;i<countF;i++)
	{
		if(strcmp(fileName,filePt[i])==0)
			return 1;
		else if(i==countF-1)   //循环结束时还未找到,代表未添加 
		{
			npt=fopen("fileName.txt","w");
			if(npt==NULL)
			{
				printf("打开文件失败！！！\n");
				exit(0); 
			}
			filePt[countF]=fileName;
			for(i=0;i<=countF;i++)
			{
				fprintf(npt,"%s\n",filePt[i]);
			}
			countF++;
			fclose(npt);
			return 0;	
		}
	}
	npt=fopen("fileName.txt","w");
	if(npt==NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0); 
	}
	filePt[0]=fileName;   //第一次添加文件名时 
	fprintf(npt,"%s\n",filePt[0]);
	countF++;
	fclose(npt);
	return 0;
}
void calCountF(void)
{
	int i=0;
	FILE *npt;
	npt=fopen("fileName.txt","r");
	if(npt==NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0); 
	}
	while(!feof(npt))
	{
		fscanf(npt,"%s",fName[i]);
		filePt[i]=fName[i];
		fgetc(npt);
		countF++;
		i++;
	}
	countF-=1;
	fclose(npt);
	return;
}
void toZero(void)
{
	int i;
	for(i=0;i<50;i++)
	{
		stus[i]=zero;
	}
}
int IDCount(long long ID)  //计算学号位数 
{
	int num=0;
	while(ID!=0)  
	{
		num++;
		ID/=10;
	}
	return num;
}
float calGPA(float math, float english, float sports, float cScore)
{
	float gpa[4];
	float score[4] = { math,english,sports,cScore };
	float point[4] = { 5,1,2,3 };
	int i;
	float sum=0;
	for (i = 0; i < 4; i++)
	{
		if (score[i] < 60)
			gpa[i] = point[i] = 0.0;
		else if (score[i] >= 60 && score[i] <= 64)
			gpa[i] = 1.2;
		else if (score[i] >= 65 && score[i] <= 69)
			gpa[i] = 1.7;
		else if (score[i] >= 70 && score[i] <= 74)
			gpa[i] = 2.2;
		else if (score[i] >= 75 && score[i] <= 79)
			gpa[i] = 2.7;
		else if (score[i] >= 80 && score[i] <= 84)
			gpa[i] = 3.2;
		else if (score[i] >= 85 && score[i] <= 89)
			gpa[i] = 3.7;
		else
			gpa[i] = 4.0;
		sum += gpa[i] * point[i];
	}
	return sum / (point[0] + point[1] + point[2] + point[3]);
}

void sort(int num,int flag)
{
	int i, j;
	//if(num!=7)  //防止对删除操作未存文件且需排序时读取而导致不能成功删除 
	//	read();
	for (i = count-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			switch(num)
			{
				case 1:
					if(flag==0)
					{
						if (stus[j].ID < stus[j + 1].ID)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].ID > stus[j + 1].ID)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;
				case 2:
					if(flag==0)
					{
						if (stus[j].GPA < stus[j + 1].GPA)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].GPA > stus[j + 1].GPA)
					{
						swap(&stus[j], &stus[j + 1]);
					}
					}
					break;
				case 3:
					if(flag==0)
					{
						if (stus[j].math < stus[j + 1].math)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].math > stus[j + 1].math)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;
				case 4:
					if(flag==0)
					{
						if (stus[j].english < stus[j + 1].english)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].english > stus[j + 1].english)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;
				case 5:
					if(flag==0)
					{
						if (stus[j].sports < stus[j + 1].sports)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].sports > stus[j + 1].sports)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;
				case 6:
					if(flag==0)
					{
						if (stus[j].cScore < stus[j + 1].cScore)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					else if(flag==1)
					{
						if (stus[j].cScore > stus[j + 1].cScore)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;
				case 7:
					if(flag==0)
					{
						if (stus[j].GPA < stus[j + 1].GPA)
						{
							swap(&stus[j], &stus[j + 1]);
						}
					}
					break;		
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		stus[i].rank = i+1;
	}
	return;
}
void swap(stu *pt1,stu *pt2)
{
	stu temp;
	temp=*pt1;
	*pt1=*pt2;
	*pt2=temp;
	return;  
}

int finalCount(char *fileName)  /*在下一次打开该程序时能得知count的值*/ 
{
	int i,j=0;
	if(file==1)
		fpt=fopen(fileName,"rb");
	else if(file==2)
		fpt = fopen(fileName, "r");
	if (fpt == NULL)
	{
		printf("不存在该专业下该班级的任何学生信息！！！\n");
		return 0;  //不存在该班级信息 
	}
	if(file==1)
	{
		fread(stus,LEN,50,fpt);
		for(i=0;i<50;i++)
		{
			if(stus[i].ID==0)
			{
				count=i;
				break;
			}
		}
	}
	else if(file==2)
	{
		count=0;
		while(!feof(fpt))
		{
			fscanf(fpt,"%lld %s %s %d %s %f %f %f %f",&stus[j].ID,stus[j].name,stus[j].sex,
			&stus[j].grade,stus[j].major,&stus[j].math,&stus[j].english,&stus[j].sports,&stus[j].cScore);
			j++;
			count++;
			fgetc(fpt);
		}
		count-=1;  //防止两种情况的发生：
		//当一次打开该文件即还未添加数据时，有一个空行，此时会导致count为1，然后在程序中只在count为0时才计算，因此在第一次read时就会一直多1 
	}	//当第二次打开该文件即已有数据时在最后一行数据后会添加一个空行，导致也多计算了一个，因此也要减1，这两种情况不冲突 
	fclose(fpt);
	return 1;  //存在该班级信息 
}

void readFpt(void)
{
	FILE *npt;
	int i;
	npt=fopen("fileName.txt","r");
	if(npt==NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0); 
	}
	for(i=0;i<countF;i++)
	{
		fscanf(npt,"%s",fName[i]);
		filePt[i]=fName[i]; 
		fgetc(npt);
	}
	fclose(npt);
	return; 
}
void read(char *fileName)
{
	if(file==1)
		read_bin(fileName);
	else if(file==2)
		read_str(fileName);
	return;
}
void write(char *fileName)
{
	if(file==1)
		write_bin(fileName);
	else if(file==2)
		write_str(fileName);
	return;
}
void read_bin(char *fileName)
{
	fpt = fopen(fileName, "rb");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0);
	}
	fread(stus, LEN, count, fpt);
	fclose(fpt);
	return;
}
void write_bin(char *fileName)
{
	fpt = fopen(fileName, "wb");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！");
		exit(0);
	}
	fwrite(stus,LEN,count,fpt);
	fclose(fpt);
	return;
}
void read_str(char *fileName)
{
	int i;
	fpt = fopen(fileName, "r");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0);
	}
	for(i=0;i<count;i++)
	{
		fscanf(fpt,"%lld %s %s %d %s %f %f %f %f",&stus[i].ID,stus[i].name,stus[i].sex,
		&stus[i].grade,stus[i].major,&stus[i].math,&stus[i].english,&stus[i].sports,&stus[i].cScore);
		stus[i].GPA=calGPA(stus[i].math,stus[i].english,stus[i].sports,stus[i].cScore);
		fgetc(fpt);
	}
	fclose(fpt);
	return;
}
void write_str(char *fileName)
{
	int i;
	fpt = fopen(fileName, "w");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！\n");
		exit(0);
	}
	for(i=0;i<count;i++)
	{
		fprintf(fpt,"%lld %s %s %d %s %.2f %.2f %.2f %.2f",stus[i].ID,stus[i].name,stus[i].sex,
		stus[i].grade,stus[i].major,stus[i].math,stus[i].english,stus[i].sports,stus[i].cScore);
		fputc('\n',fpt);
	}
	fclose(fpt);
	return;
}
