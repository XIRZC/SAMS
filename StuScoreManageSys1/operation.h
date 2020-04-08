/* operation.h--该头文件包含结构体和学生成绩增加、编辑、删除、排序、查找函数声明以及一些宏定义 */
#ifndef OPERATION_H   //防止头文件二次添加，导致多定义错误
#define OPERATION_H

/* 菜单函数、学生成绩增加、编辑、删除、排序、查找函数、绩点计算函数声明 */
//功能函数声明 
void scoreInsert(void);
void scoreEdit(void);
void scoreDelete(void);
int find(void);
int *find_name(void);
void scoreSegment(void);
void scoreSegmentOne(char order,int *sign);

//输出和菜单函数声明 
void outputOne(int num);
void outputAll(void);
void order(void);
void orderEdit(void);
void orderSegment(void);
void orderSort(void);
void orderFind(void);
void orderFile(void);

//学号纠正函数声明
void IDCorrect(long long *IDpt); 
//清屏函数声明
void clear(void); 
#endif
