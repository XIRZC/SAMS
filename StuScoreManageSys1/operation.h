/* operation.h--��ͷ�ļ������ṹ���ѧ���ɼ����ӡ��༭��ɾ�������򡢲��Һ��������Լ�һЩ�궨�� */
#ifndef OPERATION_H   //��ֹͷ�ļ�������ӣ����¶ඨ�����
#define OPERATION_H

/* �˵�������ѧ���ɼ����ӡ��༭��ɾ�������򡢲��Һ�����������㺯������ */
//���ܺ������� 
void scoreInsert(void);
void scoreEdit(void);
void scoreDelete(void);
int find(void);
int *find_name(void);
void scoreSegment(void);
void scoreSegmentOne(char order,int *sign);

//����Ͳ˵��������� 
void outputOne(int num);
void outputAll(void);
void order(void);
void orderEdit(void);
void orderSegment(void);
void orderSort(void);
void orderFind(void);
void orderFile(void);

//ѧ�ž�����������
void IDCorrect(long long *IDpt); 
//������������
void clear(void); 
#endif
