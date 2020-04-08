#ifndef CALCULATE_H
#define CALCULATE_H   //防止头文件二次添加，导致多定义错误
#define LEN sizeof(stu)

/* 学生结构体定义 */
typedef struct student {
	long long ID;  //学号
	char name[10];   //姓名
	char sex[5];   //性别
	int grade;  //年级
	char major[20];  //专业    computer  economics law history等,年级和专业组成文件名 
	float math;  //高等数学成绩，满绩点4.0，学分占5
	float english;  //英语读写成绩，满绩点4.0，学分占2
	float sports;   //体育成绩，满绩点4.0，学分占1
	float cScore;  //c语言程序设计成绩，满绩点4.0，学分占3
	float GPA;  //平均绩点
	int rank;   //专业排名
	int flag[4];//各科目分数段标志 
}stu;

void sort(int num,int flag);  //排序函数声明 
void swap(stu *pt1,stu *pt2);
void finalCount(void);
float calGPA(float math, float english, float sports, float cScore);
int IDCount(long long ID);
void toZero(void);
// GPA算法：该学生学分与绩点乘积之和除以学分总和
//0-59    0.0
//60-64   1.2
//65-69   1.7
//70-74   2.2
//75-79   2.7
//80-84  3.2
//85-89   3.7
//90-100  4.0
// 读写函数声明 
void read(void);
void write(void); 
void read_bin(void);
void write_bin(void);
void read_str(void);
void write_str(void); 
#endif
