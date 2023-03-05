
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")//加载静态库
#define WIDTH 800
#define HEIGHT 500
#define SNAKE_NUM 500//蛇的最大节数
struct Body
{
    int x;  //蛇身横坐标
    int y;  //蛇身纵坐标
};    //开辟足够大的空间
struct Snake
{
    int len;  //蛇的长度
    int x;     //蛇头横坐标
    int y;     //蛇头纵坐标
    int dir; //蛇的方向
    int speed;//移动速度
    Body body[SNAKE_NUM];
};
struct Food //食物属性
{
    int x;
    int y;//食物坐标
    int flag;     //食物是否存在
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
//菜单界面
void MenuView();

//玩家选择
int choice();

//暂停界面
void pausemenu();

//游戏说明
void GameDescription();

//初始化
void Initialize();

//游戏说明
void GameDescription();

//初始化蛇
void Init_snake();

//画蛇
void DrawSnake();

//移动蛇
void MoveSnake();

void speedup();
void speeddown();

//通过按键改变蛇的移动方向
void keyControl();

//彩蛋
void setEgg();

//生成食物
void setFood();

//蛇头碰到食物后食物会消失
void foodDisap();

//绘制食物
void drawfood();


int showrank();
//输入存储排名
int writerank();
//广告位
void Guang();
//团队
void TuanDui();
int SnakeDie();

