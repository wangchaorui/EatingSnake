
#include"YuZhou.h"
ExMessage msg;
int score;//����
int sleepTime;//���ټ���
int x;//�ж�ʳ���Ƿ����
int i;
int jige;//�ʵ��ĳ��ִ���
int gametime;//��Ϸʱ��
Snake snake;
Food food1, food2;
record rec[10];

//�˵�����
void MenuView()
{
    mciSendString("play ../Happy.mp3 repeat", NULL, 0, NULL);
    initgraph(800, 500);
    setbkcolor(WHITE);
    cleardevice();
    IMAGE im;
    loadimage(&im, "../��.png");
    putimage(0, 0, &im);

    settextstyle(40, 0, "����");
    setbkmode(TRANSPARENT);
    settextcolor(YELLOW);
    outtextxy(50, 320, "1.��ʼ��Ϸ");
    settextcolor(BLUE);
    outtextxy(320, 320, "2.���а�");
    settextcolor(RED);
    outtextxy(590, 320, "3.�����Ŷ�");
    settextcolor(BLACK);
    outtextxy(50, 420, "4.���λ");
    settextcolor(GREEN);
    outtextxy(320, 420, "5.��Ϸ˵��");
    settextcolor(WHITE);
    outtextxy(590, 420, "6.�˳���Ϸ");
}

//���ѡ��
int choice()
{
    while (1)
    {
        ExMessage m;
        m = getmessage(EX_KEY | EX_MOUSE);
        settextcolor(BLACK);
        settextstyle(15, 0, "����");
        switch (m.message)
        {
        case WM_LBUTTONDOWN:
            if (m.lbutton)
            {
                if (m.x > 30 && m.x < 250 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(15, 335, "==>");
                    Sleep(500);
                    return 1;

                }
                else if (m.x > 300 && m.x < 520 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(285, 335, "==>");
                    Sleep(500);
                    return 2;
                }
                else if (m.x > 570 && m.x < 750 && m.y>320 && m.y < 370)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(555, 335, "==>");
                    Sleep(500);
                    return 3;
                }
                else if (m.x > 30 && m.x < 250 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(15, 435, "==>");
                    Sleep(500);
                    return 4;

                }
                else if (m.x > 300 && m.x < 520 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(285, 435, "==>");
                    Sleep(500);
                    return 5;
                }
                else if (m.x > 570 && m.x < 750 && m.y>420 && m.y < 470)
                {
                    mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                    outtextxy(555, 435, "==>");
                    Sleep(500);
                    return 6;

                }
            }
        case WM_KEYDOWN:
            if (m.vkcode == '1')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(15, 335, "==>");
                Sleep(500);
                return 1;
            }
            else if (m.vkcode == '2')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(285, 335, "==>");
                Sleep(500);
                return 2;

            }
            else if (m.vkcode == '3')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(555, 335, "==>");
                Sleep(500);
                return 3;

            }
            else if (m.vkcode == '4')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(15, 435, "==>");
                Sleep(500);
                return 4;

            }
            else if (m.vkcode == '5')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(285, 435, "==>");
                Sleep(500);
                return 5;
            }
            else if (m.vkcode == '6')
            {
                mciSendString("play ../��ͷ.mp3", NULL, 0, NULL);
                outtextxy(555, 435, "==>");
                Sleep(500);
                return 6;
            }
            else if (m.vkcode == '7')
            {
                //�ڲ���Ա���֣�
                mciSendString("play ../ji.mp3", NULL, 0, NULL);
                return 7;
            }
            break;
        }
    }
}

//��ͣ����
void pausemenu()
{
    setfillcolor(RGB(85, 177, 85));
    fillrectangle(200, 150, 550, 350);
    settextcolor(RED);
    char a[] = "���Ѿ���ͣ��Ϸ";
    settextstyle(23, 0, "����");
    outtextxy(300, 180, a);
    settextcolor(RED);
    char b[] = "1. ������Ϸ    ";
    char c[] = "2. �˳���Ϸ    ";
    settextstyle(17, 0, "����");
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

//��Ϸ˵��
void GameDescription()
{
    cleardevice();
    IMAGE shuo;
    loadimage(&shuo, "../ˮī.jfif");
    putimage(0, 0, &shuo);
    settextstyle(80, 0, "����");
    settextcolor(BLACK);
    outtextxy(10, 10, "��Ϸ˵��");
    settextstyle(25, 0, "����");
    outtextxy(50, 150, "1.�˵���������������������ֽ���ѡ��");
    outtextxy(50, 200, "2.�ɡ�W����S����A����D���ֱ�����ϡ��¡����ҵķ���");
    outtextxy(50, 250, "3.V�����٣�K�����٣��ո���ͣ");
    outtextxy(50, 300, "4.С��ÿ�Ե�һ��ʳ������ͻ����ӡ���ʼ����Ϊ�㡣");
    outtextxy(50, 350, "5.������ײǽ����ҧ������ʱ����ʱ��Ϊ�㣬��Ϸ������");
    outtextxy(50, 400, "6.��ϷĿ�����ڹ涨��ʱ���ﾡ���ܶ�ĵ÷֣����Ƽ�¼��");
   
   // outtextxy(50, 300, "6.Esc����Ϸ�˳���������ҳ�档");

    outtextxy(50, 470, "�����������......");
   
}
//���λ
void Guang()
{
    IMAGE img;
    loadimage(&img, "../�Ƽ�.jfif");
    putimage(0, 0, &img);
    //setbkcolor(RGB(300, 115, 119));   
    //cleardevice();
    settextstyle(100, 0, "���Ĳ���");
    settextcolor(RED);
    outtextxy(130, 50, "���λ����");
    settextstyle(40, 0, "���Ĳ���");
    outtextxy(200, 180, "������Ҫ����ϵAQ");
    outtextxy(200, 230, "QQ2353338292");
    outtextxy(240, 280, "�ǳ�����");
    settextstyle(20, 0, "����");
    settextcolor(WHITE);
    outtextxy(40, 470, "�����������......");


}

//��ʼ��
void Initialize()
{
    cleardevice();
    Init_snake();	   //��ʼ����
    score = 0;	//��ʼ������
    sleepTime = 100;
    gametime = 1800;
    x = 0;
    i =0;
    jige = 0;
}

//��ʼ����
void Init_snake()
{
    //��ʼ����ͷ����
    snake.len = 2;//�����ߵĽ���(������ͷ��
    snake.x = WIDTH / 2;	//400
    snake.y = HEIGHT / 2;	//250
    snake.speed = 10;
    snake.dir = RIGHT;
   

    //��ʼ����������
    for (int i = 0; i < snake.len; i++)
    {
        snake.body[i].x = WIDTH / 2  - 10*(i+1);
        snake.body[i].y = HEIGHT / 2;
    }
    setfillcolor(GREEN);
    fillrectangle(snake.x, snake.y, snake.x + 10, snake.y + 10);
    //�������
    int a, b, c;
    for (int i = 0; i <snake.len; i++)
    {
         a = rand() % 36 * 10;
         b = rand() % 36 * 10;
         c= rand() % 36 * 10;
        
        setfillcolor(RGB(a,b,c));
        fillrectangle(snake.body[i].x, snake.body[i].y, snake.body[i].x + 10, snake.body[i].y + 10);	//ÿһ�ڶ���10*10�ľ���
    }
}

//����
void DrawSnake()
{
    
    //���ý��汳����ɫ
   setbkcolor(RGB(28,115,119));
    cleardevice();
    settextstyle(30, 0, "���Ĳ���");
    setcolor(YELLOW);
    TCHAR sco[5], snlong[6],stime[5];
    _stprintf_s(sco, _T("%d"), score);		//  _stprintf_s ����
    _stprintf_s(snlong, _T("%d"), snake.len+1); 
    _stprintf_s(stime, _T("%d"), (gametime--) / 10);       
    outtextxy(10, 450, "�÷֣�");
    outtextxy(100, 450, sco);
    outtextxy(250, 450, "�߳���");
    outtextxy(350, 450, snlong);
    outtextxy(500, 450, "ʣ��ʱ�䣺");
    outtextxy(650, 450, stime);
    setfillcolor(GREEN);//��ͷ����ɫ
    fillrectangle(snake.x, snake.y, snake.x + 10, snake.y + 10);
    int a, b, c;
    for (int i = 0; i < snake.len; i++)
    {
        a = rand() % 36 * 10;
        b = rand() % 36 * 10;
        c = rand() % 36 * 10;
        setfillcolor(RGB(a, b, c));     
        fillrectangle(snake.body[i].x, snake.body[i].y, snake.body[i].x + 10, snake.body[i].y + 10);	//ÿһ�ڶ���10*10�ľ���
    }
    
    
}

//�ƶ���
void MoveSnake()
{
    //���������ͷ�ƶ�
    for (int i = snake.len - 1; i > 0; i--)
    {
        snake.body[i] = snake.body[i - 1];
    }
    snake.body[0].x = snake.x;
    snake.body[0].y = snake.y;
    //�ƶ��Ƿ������ı�
   
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

//ͨ�������ı��ߵ��ƶ�����
void keyControl()
{  
      if(peekmessage(&msg, EX_KEY))
        switch (msg.vkcode)
        {
        case 'w':
        case 'W':
            //�ı䷽��
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
    if (sleepTime > 20)//�����ٶ�˯��ʱ�䲻�ܳ���50ms�����ӳ�ʼ�ٶȼ������
    {
        mciSendString("play ../ji.mp3", NULL, 0, NULL);
        sleepTime = sleepTime - 20;

    }
}
void speeddown()
{
    if (sleepTime < 180)//�������ٶ�˯��ʱ�䲻�ܳ���50ms�����ӳ�ʼ�ٶȼ�������
    {
        mciSendString("play ../ji.mp3", NULL, 0, NULL);
        sleepTime = sleepTime + 20;
    }
}

//�ʵ�
void setEgg()//���òʵ�
{
    if (jige <= 20)
    {
        if (snake.x >= 100 && snake.x <= 150 && snake.y >= 100 && snake.y <= 150)
        {
            IMAGE egg;
            loadimage(&egg, "../������.jpg");
            putimage(50, 50, &egg);
            settextstyle(25, 0, "����");
            settextcolor(RGB(245, 204, 132));
            setbkmode(TRANSPARENT);
            outtextxy(50, 150, "������һֻ������");
            mciSendString("play ../���˰�.mp3 ", NULL, 0, NULL);
            score += 5;
            snake.len += 1;
            jige++;
        }


    }
}

//����ʳ��
void setFood()
{
    if (x ==0)
    {
            food1.x = rand() % 780 + 3;
            food1.y = rand() % 480 + 3;
            food2.x = rand() % 770 + 3;
            food2.y = rand() % 470 + 3;
            //���ʳ�����������������������
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

//��ͷ����ʳ���ʳ�����ʧ,�ӷ֣��߳�������
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

//�ж����Ƿ�����
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
        char a[] = "��ײ��ǽ�ˣ�";
        settextstyle(23, 0, "����");
        outtextxy(280, 200, a);
        Sleep(2000);    
        settextcolor(YELLOW);
        outtextxy(290, 250, "�÷� : ");
        settextstyle(30, 0, "���Ĳ���");
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
            char a[] = "��ҧ�����Լ���β��";
            settextstyle(23, 0, "����");
            outtextxy(240, 200, a);
            Sleep(2000);
            settextcolor(YELLOW);
            outtextxy(290, 250, "�÷� : ");
            settextstyle(30, 0, "���Ĳ���");
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
        char a[] = "��Ϸ����";
        settextstyle(23, 0, "����");
        outtextxy(300, 200, a);
        Sleep(2000);
        settextcolor(YELLOW);
        outtextxy(290, 250, "�÷� : ");
        settextstyle(30, 0, "���Ĳ���");
        outtextxy(380, 250, sco);
        Sleep(2000);
        MenuView();
       
        return 1;
    }
        
    return 0;
}

//����ʳ��
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

//����洢����
int writerank()
{
    const time_t t=time(NULL);
    struct tm systemtime;
    localtime_s(&systemtime,&t);
    record* temp = (record*)malloc(sizeof(record) * 100);//����һ���ռ�
    int n = 0;
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, "../rank.txt", "ab");//����ɼ���׷�Ӷ�д 
    if (err)
    {
        char a[] = "cannot open the file";
        outtextxy(20, 20, a);
        Sleep(1000);
        return -1;//����ļ����ִ��󷵻�-1  
    }
    temp->score = score;//����
    temp->year = systemtime.tm_year + 1900;//��
    temp->mon = systemtime.tm_mon + 1;  //��
    temp->day = systemtime.tm_mday; //��
    temp->hour = systemtime.tm_hour;//ʱ
    temp->min = systemtime.tm_min;  //��
    temp->sec = systemtime.tm_sec;  //��
    fwrite(temp, sizeof(record), 1, fp);
    fclose(fp);
    free(temp);
    return 0;
}

//չʾ����
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
    if (fp == NULL)//���ò��û��ʲô�ô�
    {
     char a[] = "��Ҳû���������ȥ������";
     outtextxy(20, 20, a);

        return 0;
    }
    rewind(fp);
    while (!feof(fp))
    {
        fread(&rec[i], sizeof(record), 1, fp);
    }
    for (int j = 0; j < i; j++)//������
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
    loadimage(&bkgrd, "../���а�.png");
    putimage(0, 0, &bkgrd);
    settextcolor(BLACK);
    settextstyle(80, 0, "������κ");
    outtextxy(300 , 20, "���а�");
    settextstyle(50 , 0, "���Ŀ���");
    outtextxy(50, 130 , "�� ��");
    outtextxy(250 , 130 , "��   ��   ��           ʱ   ��   ��");
    settextstyle(30, 0, "����Ҧ��");
    int UNIT = 10;
    settextcolor(RED);
    for (int j = 0; j < i; j++)
    {
        TCHAR s1[6];
        
            _stprintf_s(s1, _T("%d"), rec[j].score);//����
            outtextxy(90, j * 25 + 200, s1);
            TCHAR s2[6];
            _stprintf_s(s2, _T("%d"), rec[j].year);//��
            outtextxy(260, j * 25 + 200, s2);
            TCHAR s3[6];
            _stprintf_s(s3, _T("%d"), rec[j].mon);//��
            outtextxy(340, j * 25 + 200, s3);
            TCHAR s4[6];
            _stprintf_s(s4, _T("%d"), rec[j].day);//��
            outtextxy(420, j * 25 + 200, s4);
            TCHAR s5[6];
            _stprintf_s(s5, _T("%d"), rec[j].hour);//ʱ
            outtextxy(590, j * 25 + 200, s5);
            TCHAR s6[6];
            _stprintf_s(s6, _T("%d"), rec[j].min);//��
            outtextxy(670, j * 25 + 200, s6);
            TCHAR s7[6];
            _stprintf_s(s7, _T("%d"), rec[j].sec);//��
            outtextxy(745, j * 25 + 200, s7);
        
    }
    settextcolor(BLACK);
    settextstyle(20,0, "����");
    outtextxy(5, 470 , "����������ء���");
    fclose(fp);
    return 0;
}

//�Ŷ�
void TuanDui()
{
   
    IMAGE shuo;
    loadimage(&shuo, "../�Ŷ�.jpg");
    putimage(0, 0, &shuo);
    settextstyle(80, 0, "������κ");
    settextcolor(BLACK);
    outtextxy(250, 20, "�����Ŷ�");
    settextstyle(40, 0, "����Ҧ��");
    settextcolor(BLACK);
    outtextxy(20, 150, "ָ����Ա �� ");
    outtextxy(100, 200, "  �ƺ�ѧ��   ");
    outtextxy(100, 250, "  ��PСѧ��   ");
    outtextxy(100, 300, "  ����ѧ��     ");
    outtextxy(100, 350, "  ����ѧ��    ");
    outtextxy(350, 150, "�鳤      ��  AQ   ");
    outtextxy(350, 200, "���鳤   �� ���    ������  ");
    outtextxy(350, 250, "������   �� ikun   ");
    outtextxy(350, 300, "��Ʒ���� ����   �����׸�˹  ");
    outtextxy(350, 350, "��Ϣ��   �� QQ   ��Ȼ   ");
    outtextxy(350, 400, "�ල��   �� �Ӻ�   С��   ");
    settextstyle(20, 0, "����");
    outtextxy(5, 470, "����������ء���");


}
