
#include"YuZhou.h"
ExMessage msg;
int score;//分数
int sleepTime;//加速减速
int x;//判断食物是否存在
int i;
int jige;//彩蛋的出现次数
int gametime;//游戏时间
Snake snake;
Food food1, food2;
record rec[10];

//菜单界面
void MenuView()
{
    mciSendString("play ../Happy.mp3 repeat", NULL, 0, NULL);
    initgraph(800, 500);
    setbkcolor(WHITE);
    cleardevice();
    IMAGE im;
    loadimage(&im, "../蛇.png");
    putimage(0, 0, &im);

    settextstyle(40, 0, "楷体");
    setbkmode(TRANSPARENT);
    settextcolor(YELLOW);
    outtextxy(50, 320, "1.开始游戏");
    settextcolor(BLUE);
    outtextxy(320, 320, "2.排行榜");
    settextcolor(RED);
    outtextxy(590, 320, "3.制作团队");
    settextcolor(BLACK);
    outtextxy(50, 420, "4.广告位");
    settextcolor(GREEN);
    outtextxy(320, 420, "5.游戏说明");
    settextcolor(WHITE);
    outtextxy(590, 420, "6.退出游戏");
}

//玩家选择
int choice()
{
    while (1)
    {
        ExMessage m;
        m = getmessage(EX_KEY | EX_MOUSE);
        settextcolor(BLACK);
        settextstyle(15, 0, "宋体");
        switch (m.message)
        {
        case WM_LBUTTONDOWN:
            if (m.lbutton)
            {
                if (m.x > 30 && m.x < 250 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(15, 335, "==>");
                    Sleep(500);
                    return 1;

                }
                else if (m.x > 300 && m.x < 520 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(285, 335, "==>");
                    Sleep(500);
                    return 2;
                }
                else if (m.x > 570 && m.x < 750 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(555, 335, "==>");
                    Sleep(500);
                    return 3;
                }
                else if (m.x > 30 && m.x < 250 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(15, 435, "==>");
                    Sleep(500);
                    return 4;

                }
                else if (m.x > 300 && m.x < 520 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(285, 435, "==>");
                    Sleep(500);
                    return 5;
                }
                else if (m.x > 570 && m.x < 750 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                    outtextxy(555, 435, "==>");
                    Sleep(500);
                    return 6;

                }
            }
        case WM_KEYDOWN:
            if (m.vkcode == '1')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(15, 335, "==>");
                Sleep(500);
                return 1;
            }
            else if (m.vkcode == '2')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(285, 335, "==>");
                Sleep(500);
                return 2;

            }
            else if (m.vkcode == '3')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(555, 335, "==>");
                Sleep(500);
                return 3;

            }
            else if (m.vkcode == '4')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(15, 435, "==>");
                Sleep(500);
                return 4;

            }
            else if (m.vkcode == '5')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(285, 435, "==>");
                Sleep(500);
                return 5;
            }
            else if (m.vkcode == '6')
            {
                mciSendString("play ../箭头.mp3", NULL, 0, NULL);
                outtextxy(555, 435, "==>");
                Sleep(500);
                return 6;
            }
            else if (m.vkcode == '7')
            {
                //内部人员音乐；
                mciSendString("play ../ji.mp3", NULL, 0, NULL);
                return 7;
            }
            break;
        }
    }
}

//暂停界面
void pausemenu()
{
    setfillcolor(RGB(85, 177, 85));
    fillrectangle(200, 150, 550, 350);
    settextcolor(RED);
    char a[] = "你已经暂停游戏";
    settextstyle(23, 0, "楷体");
    outtextxy(300, 180, a);
    settextcolor(RED);
    char b[] = "1. 继续游戏    ";
    char c[] = "2. 退出游戏    ";
    settextstyle(17, 0, "宋体");
    outtextxy(320, 230, b);
    outtextxy(320, 270, c); 
    while(1)
    {
        msg = getmessage(EX_KEY);                
        if (msg.vkcode == '1')
        {
            return;
        }
        else if (msg.vkcode == '2')
        {
            mciSendString("play ../gan.mp3", NULL, 0, NULL);
            Sleep(1500);
            exit(0);
        }
              
    }  

}

//游戏说明
void GameDescription()
{
    cleardevice();
    IMAGE shuo;
    loadimage(&shuo, "../水墨.jfif");
    putimage(0, 0, &shuo);
    settextstyle(80, 0, "楷体");
    settextcolor(BLACK);
    outtextxy(10, 10, "游戏说明");
    settextstyle(25, 0, "隶书");
    outtextxy(50, 150, "1.菜单界面用鼠标点击或输入数字进行选择");
    outtextxy(50, 200, "2.由“W”“S”“A”“D”分别控制上、下、左、右的方向。");
    outtextxy(50, 250, "3.V键加速，K键减速，空格暂停");
    outtextxy(50, 300, "4.小蛇每吃到一个食物，分数就会增加。初始分数为零。");
    outtextxy(50, 350, "5.当蛇首撞墙，或咬到蛇身时，或时间为零，游戏结束。");
    outtextxy(50, 400, "6.游戏目标是在规定的时间里尽可能多的得分，打破记录！");
   
   // outtextxy(50, 300, "6.Esc键游戏退出，返回主页面。");

    outtextxy(50, 470, "按任意键返回......");
   
}
//广告位
void Guang()
{
    IMAGE img;
    loadimage(&img, "../科技.jfif");
    putimage(0, 0, &img);
    //setbkcolor(RGB(300, 115, 119));   
    //cleardevice();
    settextstyle(100, 0, "华文彩云");
    settextcolor(RED);
    outtextxy(130, 50, "广告位招租");
    settextstyle(40, 0, "华文彩云");
    outtextxy(200, 180, "如有需要请联系AQ");
    outtextxy(200, 230, "QQ2353338292");
    outtextxy(240, 280, "非诚勿扰");
    settextstyle(20, 0, "楷体");
    settextcolor(WHITE);
    outtextxy(40, 470, "按任意键返回......");


}

//初始化
void Initialize()
{
    cleardevice();
    Init_snake();	   //初始化蛇
    score = 0;	//初始化分数
    sleepTime = 100;
    gametime = 1800;
    x = 0;
    i =0;
    jige = 0;
}

//初始化蛇
void Init_snake()
{
    //初始化蛇头坐标
    snake.len = 2;//这是蛇的节数(不包含头）
    snake.x = WIDTH / 2;	//400
    snake.y = HEIGHT / 2;	//250
    snake.speed = 10;
    snake.dir = RIGHT;
   

    //初始化蛇身坐标
    for (int i = 0; i < snake.len; i++)
    {
        snake.body[i].x = WIDTH / 2  - 10*(i+1);
        snake.body[i].y = HEIGHT / 2;
    }
    setfillcolor(GREEN);
    fillrectangle(snake.x, snake.y, snake.x + 10, snake.y + 10);
    //填充蛇身
    int a, b, c;
    for (int i = 0; i <snake.len; i++)
    {
         a = rand() % 36 * 10;
         b = rand() % 36 * 10;
         c= rand() % 36 * 10;
        
        setfillcolor(RGB(a,b,c));
        fillrectangle(snake.body[i].x, snake.body[i].y, snake.body[i].x + 10, snake.body[i].y + 10);	//每一节都是10*10的矩形
    }
}

//画蛇
void DrawSnake()
{
    
    //设置界面背景颜色
   setbkcolor(RGB(28,115,119));
    cleardevice();
    settextstyle(30, 0, "华文彩云");
    setcolor(YELLOW);
    TCHAR sco[5], snlong[6],stime[5];
    _stprintf_s(sco, _T("%d"), score);		//  _stprintf_s 函数
    _stprintf_s(snlong, _T("%d"), snake.len+1); 
    _stprintf_s(stime, _T("%d"), (gametime--) / 10);       
    outtextxy(10, 450, "得分：");
    outtextxy(100, 450, sco);
    outtextxy(250, 450, "蛇长：");
    outtextxy(350, 450, snlong);
    outtextxy(500, 450, "剩余时间：");
    outtextxy(650, 450, stime);
    setfillcolor(GREEN);//蛇头的颜色
    fillrectangle(snake.x, snake.y, snake.x + 10, snake.y + 10);
    int a, b, c;
    for (int i = 0; i < snake.len; i++)
    {
        a = rand() % 36 * 10;
        b = rand() % 36 * 10;
        c = rand() % 36 * 10;
        setfillcolor(RGB(a, b, c));     
        fillrectangle(snake.body[i].x, snake.body[i].y, snake.body[i].x + 10, snake.body[i].y + 10);	//每一节都是10*10的矩形
    }
    
    
}

//移动蛇
void MoveSnake()
{
    //让身体跟着头移动
    for (int i = snake.len - 1; i > 0; i--)
    {
        snake.body[i] = snake.body[i - 1];
    }
    snake.body[0].x = snake.x;
    snake.body[0].y = snake.y;
    //移动是方向发生改变
   
    switch (snake.dir)
    {
    case UP:
        snake.y -= snake.speed;
        Sleep(sleepTime);
        break;
    case DOWN:
        snake.y += snake.speed;
        Sleep(sleepTime);
        break;
    case LEFT:
        snake.x -= snake.speed;
        Sleep(sleepTime);
        break;
    case RIGHT:
        snake.x += snake.speed;
        Sleep(sleepTime);
        break;
    }
}

//通过按键改变蛇的移动方向
void keyControl()
{  
      if(peekmessage(&msg, EX_KEY))
        switch (msg.vkcode)
        {
        case 'w':
        case 'W':
            //改变方向
            if (snake.dir != DOWN)
            {
                snake.dir = UP;
            }
            break;
        case 's':
        case 'S':      
            if (snake.dir != UP)
            {
                snake.dir = DOWN;
            }
            break;
        case 'a':
        case 'A':      
            if (snake.dir != RIGHT)
            {
                snake.dir = LEFT;
            }
            break;
        case 'd':
        case 'D':
            if (snake.dir != LEFT)
            {
                snake.dir = RIGHT;
            }
            break;
        case 'v':
        case 'V':
            speedup();
            break;
        case 'k':
        case 'K':
            speeddown();
            break;
        case ' ':
            pausemenu();
            break;

        default:
            break;

        }
    
}
void speedup()
{
    if (sleepTime > 20)//最快的速度睡眠时间不能超过50ms，最多从初始速度加速五次
    {
        mciSendString("play ../ji.mp3", NULL, 0, NULL);
        sleepTime = sleepTime - 20;

    }
}
void speeddown()
{
    if (sleepTime < 180)//最慢的速度睡眠时间不能超过50ms，最多从初始速度减速两次
    {
        mciSendString("play ../ji.mp3", NULL, 0, NULL);
        sleepTime = sleepTime + 20;
    }
}

//彩蛋
void setEgg()//设置彩蛋
{
    if (jige <= 20)
    {
        if (snake.x >= 100 && snake.x <= 150 && snake.y >= 100 && snake.y <= 150)
        {
            IMAGE egg;
            loadimage(&egg, "../懒羊羊.jpg");
            putimage(50, 50, &egg);
            settextstyle(25, 0, "黑体");
            settextcolor(RGB(245, 204, 132));
            setbkmode(TRANSPARENT);
            outtextxy(50, 150, "发现了一只懒羊羊");
            mciSendString("play ../来了奥.mp3 ", NULL, 0, NULL);
            score += 5;
            snake.len += 1;
            jige++;
        }


    }
}

//生成食物
void setFood()
{
    if (x ==0)
    {
            food1.x = rand() % 780 + 3;
            food1.y = rand() % 480 + 3;
            food2.x = rand() % 770 + 3;
            food2.y = rand() % 470 + 3;
            //如果食物出现在蛇身上则重新生成
            for (int i = 0; i < snake.len; i++)
            {
                if (food1.x == snake.body[i].x && food1.y == snake.body[i].y)
                {
                    food1.x = rand() % 780 + 3;
                    food1.y = rand() % 480 + 3;                 
                }
                else
                {
                    if((snake.x >= food2.x - 10 && snake.x <= food2.x + 10) && (snake.y >= food2.y - 10 && snake.y <= food2.y + 10))
                    {
                        food2.x = rand() % 770 + 3;
                        food2.y = rand() % 470 + 3;
                    }
                }
            }

            x = 1;
        
        i++;

    }
}

//蛇头碰到食物后食物会消失,加分，蛇长度增加
void foodDisap()
{
    if ((snake.x >=food1.x-10&&snake.x<=food1.x+10)&& (snake.y >= food1.y - 10 && snake.y <= food1.y + 10))
    {
        setbkcolor(RGB(28, 115, 119));
        cleardevice();
        DrawSnake();
        x = 0;
        score += 3;
        snake.len += 2;
    }
    else if ((snake.x >= food2.x - 20 && snake.x <= food2.x + 20) && (snake.y >= food2.y - 20 && snake.y <= food2.y + 20))
    {
        setbkcolor(RGB(28, 115, 119));
        cleardevice();
        DrawSnake();
        x = 0;
        score += 10;
        snake.len += 5;
    }
}

//判断蛇是否死亡
int SnakeDie()
{
    TCHAR sco[5];
    _stprintf_s(sco, _T("%d"), score);
    if (snake.x >=795 || snake.x <=-5|| snake.y >= 495|| snake.y <=-5)
    {


        setfillcolor(GREEN);
        fillrectangle(200, 150, 500, 300);
        settextcolor(RED);
        setbkmode(TRANSPARENT);
        char a[] = "你撞到墙了！";
        settextstyle(23, 0, "楷体");
        outtextxy(280, 200, a);
        Sleep(2000);    
        settextcolor(YELLOW);
        outtextxy(290, 250, "得分 : ");
        settextstyle(30, 0, "华文彩云");
        outtextxy(380, 250, sco);
        Sleep(2000);
        MenuView();
       
        return 1;
    }
    for (int i = 0; i < snake.len; i++)
    {
        if (snake.x == snake.body[i].x && snake.y == snake.body[i].y)
        {
            setfillcolor(GREEN);
            fillrectangle(200, 150, 500, 300);
            settextcolor(RED);
            setbkmode(TRANSPARENT);
            char a[] = "你咬到了自己的尾巴";
            settextstyle(23, 0, "楷体");
            outtextxy(240, 200, a);
            Sleep(2000);
            settextcolor(YELLOW);
            outtextxy(290, 250, "得分 : ");
            settextstyle(30, 0, "华文彩云");
            outtextxy(380, 250, sco);
            Sleep(2000);
            MenuView();
            
            return 1;
        }
           
    }
    if (gametime == 0)
    {
        setfillcolor(GREEN);
        fillrectangle(200, 150, 500, 300);
        settextcolor(RED);
        setbkmode(TRANSPARENT);
        char a[] = "游戏结束";
        settextstyle(23, 0, "楷体");
        outtextxy(300, 200, a);
        Sleep(2000);
        settextcolor(YELLOW);
        outtextxy(290, 250, "得分 : ");
        settextstyle(30, 0, "华文彩云");
        outtextxy(380, 250, sco);
        Sleep(2000);
        MenuView();
       
        return 1;
    }
        
    return 0;
}

//绘制食物
void drawfood()
{

       if (x == 1)
        {
           if (i % 5 != 0)
           {
               setfillcolor(RED);
               setlinecolor(BLACK);
               fillrectangle(food1.x, food1.y, food1.x + 10, food1.y + 10);
           }
           else
           {
               setfillcolor(BLUE);
               setlinecolor(BLACK);
               fillcircle(food2.x, food2.y, 20);

           }
       }
}

//输入存储排名
int writerank()
{
    const time_t t=time(NULL);
    struct tm systemtime;
    localtime_s(&systemtime,&t);
    record* temp = (record*)malloc(sizeof(record) * 100);//申请一个空间
    int n = 0;
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, "../rank.txt", "ab");//保存成绩用追加读写 
    if (err)
    {
        char a[] = "cannot open the file";
        outtextxy(20, 20, a);
        Sleep(1000);
        return -1;//如果文件出现错误返回-1  
    }
    temp->score = score;//分数
    temp->year = systemtime.tm_year + 1900;//年
    temp->mon = systemtime.tm_mon + 1;  //月
    temp->day = systemtime.tm_mday; //日
    temp->hour = systemtime.tm_hour;//时
    temp->min = systemtime.tm_min;  //分
    temp->sec = systemtime.tm_sec;  //秒
    fwrite(temp, sizeof(record), 1, fp);
    fclose(fp);
    free(temp);
    return 0;
}

//展示排名
int showrank()
{
    record _temp;
    int j = 0, k = 0;
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, "../rank.txt", "rb");
    if (err)
    {
       char a[]="cannot open the file";
       outtextxy(20, 20, a);
       Sleep(1000);
        return -1;
    }
    if (fp == NULL)//这个貌似没有什么用处
    {
     char a[] = "你也没打过啊，快去玩两把";
     outtextxy(20, 20, a);

        return 0;
    }
    rewind(fp);
    while (!feof(fp))
    {
        fread(&rec[i], sizeof(record), 1, fp);
    }
    for (int j = 0; j < i; j++)//排序用
    {
        for (int k = 0; k < i; k++)
        {
            if (rec[k].score < rec[j].score)
            {
                _temp = rec[k];
                rec[k] = rec[j];
                rec[j] = _temp;
            }
        }
    } 
    cleardevice();
    IMAGE bkgrd;
    loadimage(&bkgrd, "../排行榜.png");
    putimage(0, 0, &bkgrd);
    settextcolor(BLACK);
    settextstyle(80, 0, "华文新魏");
    outtextxy(300 , 20, "排行榜");
    settextstyle(50 , 0, "华文楷体");
    outtextxy(50, 130 , "得 分");
    outtextxy(250 , 130 , "年   月   日           时   分   秒");
    settextstyle(30, 0, "方正姚体");
    int UNIT = 10;
    settextcolor(RED);
    for (int j = 0; j < i; j++)
    {
        TCHAR s1[6];
        
            _stprintf_s(s1, _T("%d"), rec[j].score);//分数
            outtextxy(90, j * 25 + 200, s1);
            TCHAR s2[6];
            _stprintf_s(s2, _T("%d"), rec[j].year);//年
            outtextxy(260, j * 25 + 200, s2);
            TCHAR s3[6];
            _stprintf_s(s3, _T("%d"), rec[j].mon);//月
            outtextxy(340, j * 25 + 200, s3);
            TCHAR s4[6];
            _stprintf_s(s4, _T("%d"), rec[j].day);//日
            outtextxy(420, j * 25 + 200, s4);
            TCHAR s5[6];
            _stprintf_s(s5, _T("%d"), rec[j].hour);//时
            outtextxy(590, j * 25 + 200, s5);
            TCHAR s6[6];
            _stprintf_s(s6, _T("%d"), rec[j].min);//分
            outtextxy(670, j * 25 + 200, s6);
            TCHAR s7[6];
            _stprintf_s(s7, _T("%d"), rec[j].sec);//秒
            outtextxy(745, j * 25 + 200, s7);
        
    }
    settextcolor(BLACK);
    settextstyle(20,0, "楷体");
    outtextxy(5, 470 , "按任意键返回……");
    fclose(fp);
    return 0;
}

//团队
void TuanDui()
{
   
    IMAGE shuo;
    loadimage(&shuo, "../团队.jpg");
    putimage(0, 0, &shuo);
    settextstyle(80, 0, "华文新魏");
    settextcolor(BLACK);
    outtextxy(250, 20, "制作团队");
    settextstyle(40, 0, "方正姚体");
    settextcolor(BLACK);
    outtextxy(20, 150, "指导人员 ： ");
    outtextxy(100, 200, "  云海学长   ");
    outtextxy(100, 250, "  啊P小学长   ");
    outtextxy(100, 300, "  星竹学姐     ");
    outtextxy(100, 350, "  依依学姐    ");
    outtextxy(350, 150, "组长      ：  AQ   ");
    outtextxy(350, 200, "副组长   ： 归客    懒大王  ");
    outtextxy(350, 250, "技术官   ： ikun   ");
    outtextxy(350, 300, "产品经理 ：殇   普罗米改斯  ");
    outtextxy(350, 350, "信息关   ： QQ   毕然   ");
    outtextxy(350, 400, "监督官   ： 子豪   小斑   ");
    settextstyle(20, 0, "楷体");
    outtextxy(5, 470, "按任意键返回……");


}
