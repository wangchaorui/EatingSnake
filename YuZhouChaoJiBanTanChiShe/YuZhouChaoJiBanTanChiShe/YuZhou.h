
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���ؾ�̬��
#define WIDTH 800
#define HEIGHT 500
#define SNAKE_NUM 500//�ߵ�������
struct Body
{
    int x;  //���������
    int y;  //����������
};    //�����㹻��Ŀռ�
struct Snake
{
    int len;  //�ߵĳ���
    int x;     //��ͷ������
    int y;     //��ͷ������
    int dir; //�ߵķ���
    int speed;//�ƶ��ٶ�
    Body body[SNAKE_NUM];
};
struct Food //ʳ������
{
    int x;
    int y;//ʳ������
    int flag;     //ʳ���Ƿ����
};
struct record
{
    int score;
    int hour;
    int min;
    int sec;
    int year;
    int mon;
    int day;

};
enum DIR
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};
//�˵�����
void MenuView();

//���ѡ��
int choice();

//��ͣ����
void pausemenu();

//��Ϸ˵��
void GameDescription();

//��ʼ��
void Initialize();

//��Ϸ˵��
void GameDescription();

//��ʼ����
void Init_snake();

//����
void DrawSnake();

//�ƶ���
void MoveSnake();

void speedup();
void speeddown();

//ͨ�������ı��ߵ��ƶ�����
void keyControl();

//�ʵ�
void setEgg();

//����ʳ��
void setFood();

//��ͷ����ʳ���ʳ�����ʧ
void foodDisap();

//����ʳ��
void drawfood();


int showrank();
//����洢����
int writerank();
//���λ
void Guang();
//�Ŷ�
void TuanDui();
int SnakeDie();

