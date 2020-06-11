#include<stdio.h>
#include<time.h>
#include<conio.h>
#define h 25
#define w 45
typedef enum dir{stop=0,down=1,downleft=2,downright=3,up=4,upleft=5,upright=6}direction;
direction d;
int bar1_1=w-29,bar1_2=w-20,bar2_1=w-29,bar2_2=w-20,x=20,y=13,score1=0,score2=0,flag=0;
void reset()
{
        bar1_1=w-29;bar1_2=w-20;
        bar2_1=w-29;bar2_2=w-20;
        x=20;y=13;
        flag=0;
}
void ball_logic()
{
  if(x>=bar1_1&&x<=bar1_2&&y==2)//for upper paddle
  d=(direction)((rand()%3)+1);
  else if(x>=bar2_1&&x<=bar2_2&&y==23)//for lower paddle
  d=(direction)((rand()%3)+4);
    else if(x==w-5)//for right wall
    {
        if(d==upright)
         d=upleft;
         else
        d=downleft;
    }
    else if(x==1)//for left wall
    {
        if(d==upleft)
            d=upright;
        else
            d=downright;
    }
    else if(!(x>=bar1_1&&x<=bar1_2)&&y==2)//for upper wall
    {
        reset();
        score2=score2+1;
    }
    else if(!(x>=bar2_1&&x<=bar2_2)&&y==23)//for lower wall
    {
        reset();
        score1=score1+1;
    }
    else{}
}
void ballmove()
{
    switch(d)
    {
    case stop:
        d=(direction)((srand(time)%6)+1);
        break;
    case down:
        y=y+1;
        break;
    case downleft:
        y=y+1; x=x-1;
        break;
    case downright:
        y=y+1; x=x+1;
        break;
    case up:
        y=y-1;
        break;
    case upleft:
        y=y-1; x=x-1;
        break;
    case upright:
        y=y-1; x=x+1;
        break;
        default:break;
    }
}
void move()
{
    ball_logic();
    ballmove();
   if(kbhit()){
        switch(getch())
        {
        case 'a':if(bar1_1>1)
        {bar1_1=bar1_1-2;
         bar1_2=bar1_2-2;}
        break ;
        case 'd':if(bar1_2<w-3)
        {bar1_1=bar1_1+2;
        bar1_2=bar1_2+2;}
        break ;
         case '4':if(bar2_1>1)
         {bar2_1=bar2_1-2;
          bar2_2=bar2_2-2;}
        break ;
        case '6':if(bar2_2<w-3)
        {bar2_1=bar2_1+2;
        bar2_2=bar2_2+2;}
        break ;
        }
    }
}
void disp()
{
        system("cls");
    int i=0,j=0;
    for(j=0;j<w-1;j++)
        printf("=");
        printf("\n");
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(j==0)
                printf("+");
                else if(x==j&&y==i)
                    printf("0");
                else if(j>=bar1_1&&j<=bar1_2&&i==0)
                    printf("~");
                else if(j>=bar2_1&&j<=bar2_2&&i==h-1)
                    printf("~");
            else
                printf(" ");

            if(j==w-3)
                printf("+");
        }
        printf("\n");
    }
      for(j=0;j<w-1;j++)
        printf("=");
        printf("\nPlayer1:%d      Player2:%d",score1,score2);

}
void main()
{
    while(1){
      disp();
       if(flag==0)
            {
                flag=1;
                _sleep(1000);
            }
      move();
     _sleep(35);
      }
}
