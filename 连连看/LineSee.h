#pragma once
#include <Windows.h>
#include <vector>

#ifndef LINESEE_H
#define LINESEE_H

//������ϵͳ
class LineSee
{
private:
	int *map = NULL;	//��ͼ
	int size;		//ͼƬ����
	int col, row;		//����������
	int img_num;		//ͼƬ������Ŀ
	bool isWin;		//�Ƿ����
	bool hint;		//�Ƿ���ʾ
	RECT rect;		//ͼƬ�������
	POINT lastImg;	//��һ�ε��е�ͼƬ����
	int hintPoint1, hintPoint2;	//��ʾ������������ͼƬ����
public:
	LineSee(){ };
	void InitGame(int rank); //��ʼ��
	~LineSee();
	void PutImage();	//��ͼ
	void PlayGame();	//��ʼ��Ϸ
private:
	void _JudgeIsWin();	//�ж��Ƿ�ʤ��
	void _InitMap();		//��ʼ����ͼ
	void _Celebrate();	//��ףʤ��
	bool _NoWayOut(bool hint);	//�Ƿ�û�п���������ͼƬ
	bool _JudgeMenu(int x, int y);	//�жϲ˵������Ƿ��а�ť������
	void _JudgeImg(int x, int y);	//�ж�ͼƬ����
	void _EraseImg(std::vector<POINT> track);	//����ͼƬ
	int _GetTwoDimensionMap(int y, int x);	//�õ���ά��ͼ�����ֵ
	bool _Link(POINT p1, POINT p2);	//�ж�p1��p2�Ƿ����ϰ���ͨ
	bool _FindPoint(POINT obj, std::vector<POINT> vtr);	//�ж�vtr���Ƿ���obj
	void _GetClosePoint(POINT at, bool x, std::vector<POINT> &close);//�õ���Χ�յ�
	bool _JudgeDeep(int y, int x, std::vector<POINT> &track);//�ж�����ͼƬ�Ƿ�����������������
};

#endif