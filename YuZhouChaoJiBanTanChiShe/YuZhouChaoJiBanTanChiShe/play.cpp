#include"YuZhou.h"
int main()
{
	ExMessage m;
	int flag;        //�ж����ѡ�����ĸ�����   
	srand((unsigned int)time(NULL));
    loop: //goto 
	MenuView();

	while (1)
	{
		flag = choice();
		switch (flag)
		{
		case 1:  //��ʼ��Ϸ				
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
		case 2:    //���а�			
			showrank();
			m = getmessage(EX_KEY);
			goto loop;
			//չʾ����
	   // writerank();
		 showrank();
		  
			break;
		case 3:    //�����Ŷ�		
			TuanDui();
			m = getmessage(EX_KEY);
			goto loop;
			break;
		case 4:  Guang();
			m = getmessage(EX_KEY);
			goto loop;
			break;
		case 5: //��Ϸ˵��		
			GameDescription();
				m = getmessage(EX_KEY);
				goto loop;				
			break;
		case 6:    //�˳���Ϸ
			mciSendString("play ../gan.mp3", NULL, 0, NULL);
			Sleep(2000);
			exit(0);
			break;
		}
	}
}