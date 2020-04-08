#include<stdio.h>
#include<stdlib.h>
#include "file.h" 
#include "operation.h"
#include "calculate.h"

FILE *fpt;
extern int count;
extern stu stus[50];

void read(void)
{
	fpt = fopen("scoreInfo.txt", "rb");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！");
		exit(0);
	}
	fread(stus, LEN, count, fpt);
	fclose(fpt);
	return;
}
void write(void)
{
	fpt = fopen("scoreInfo.txt", "wb");
	if (fpt == NULL)
	{
		printf("打开文件失败！！！");
		exit(0);
	}
	fwrite(stus,LEN,count,fpt);
	fclose(fpt);
	return;
}

