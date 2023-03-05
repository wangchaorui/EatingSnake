#include"YuZhou.h"
int main()
{
	ExMessage m;
	int flag;        //判断玩家选择了哪个功能   
	srand((unsigned int)time(NULL));
    loop: //goto 
	MenuView();

	while (1)
	{
		flag = choice();
		switch (flag)
		{
		case 1:  //开始游戏				
			Initialize();		
			BeginBatchDraw();
			while (1)
			{		
			    DrawSnake();								
				setFood();
				drawfood();
				keyControl();
				MoveSnake();			
				foodDisap();
				setEgg();
				if (SnakeDie())
				{
					writerank();
					goto loop;
				}
				EndBatchDraw();
			}
			
			
			break;
		case 2:    //排行榜			
			showrank();
			m = getmessage(EX_KEY);
			goto loop;
			//展示排名
	   // writerank();
		 showrank();
		  
			break;
		case 3:    //制作团队		
			TuanDui();
			m = getmessage(EX_KEY);
			goto loop;
			break;
		case 4:  Guang();
			m = getmessage(EX_KEY);
			goto loop;
			break;
		case 5: //游戏说明		
			GameDescription();
				m = getmessage(EX_KEY);
				goto loop;				
			break;
		case 6:    //退出游戏
			mciSendString("play ../gan.mp3", NULL, 0, NULL);
			Sleep(2000);
			exit(0);
			break;
		}
	}
}