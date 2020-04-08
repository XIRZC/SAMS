#ifndef CALCULATE_H
#define CALCULATE_H   //��ֹͷ�ļ�������ӣ����¶ඨ�����
#define LEN sizeof(stu)

/* ѧ���ṹ�嶨�� */
typedef struct student {
	long long ID;  //ѧ��
	char name[10];   //����
	char sex[5];   //�Ա�
	int grade;  //�꼶
	char major[20];  //רҵ    computer  economics law history��,�꼶��רҵ����ļ��� 
	float math;  //�ߵ���ѧ�ɼ���������4.0��ѧ��ռ5
	float english;  //Ӣ���д�ɼ���������4.0��ѧ��ռ2
	float sports;   //�����ɼ���������4.0��ѧ��ռ1
	float cScore;  //c���Գ�����Ƴɼ���������4.0��ѧ��ռ3
	float GPA;  //ƽ������
	int rank;   //רҵ����
	int flag[4];//����Ŀ�����α�־ 
}stu;

void sort(int num,int flag);  //���������� 
void swap(stu *pt1,stu *pt2);
int finalCount(char *fileName);
float calGPA(float math, float english, float sports, float cScore);
int IDCount(long long ID);
void toZero(void);
void calCountF(void);
// GPA�㷨����ѧ��ѧ���뼨��˻�֮�ͳ���ѧ���ܺ�
//0-59    0.0
//60-64   1.2
//65-69   1.7
//70-74   2.2
//75-79   2.7
//80-84  3.2
//85-89   3.7
//90-100  4.0
// ��д�������� 
void readFpt(void);
void read(char *fileName);
void write(char *fileName); 
void read_bin(char *fileName);
void write_bin(char *fileName);
void read_str(char *fileName);
void write_str(char *fileName); 
//�ļ�����غ�������
char *getFileName(int grade,char *major);
int hasFileAdded(char *fileName); 
#endif
