#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int dirn=1;
int flag=0;
int food_val=0;
int i=1;
char w;
bool running=true;
class parts
{
   public:
        int x;
        int y;
        void init(int a, int b)
        {
            x=a;
            y=b;
        }
        void update_pos(int dx, int dy)
        {
            x+=dx;
            y+=dy;
        }
};
class food
{
    public:
        int x;
        int y;
        void init(int a, int b)
        {
            x=a;
            y=b;
        }
};
void update()
{

    flag=0;
    if(_kbhit())
        {
            w=getch();
            flag=1;
        }

}
void direction(char ch)
{
    switch(ch)
    {
    case 'w': if(dirn!=3){dirn=1;}
              break;

    case 'a': if(dirn!=2){dirn=4;}
              break;

    case 's': if(dirn!=1){dirn=3;}
              break;

    case 'd': if(dirn!=4){dirn=2;}
              break;
    }
}

int main()
{
   parts body[200];
   food food_store;
   int num;
   int sleep;
   std::cout<<"Avoid the walls and avoid the snake from eating itself"<<std::endl;
   std::cout<<"Controls are as follows."<<std::endl<<"  "<<'W'<<std::endl<<'A'<<"   "<<'D'<<std::endl<<"  "<<'S'<<std::endl;
   std::cout<<"Select your difficulty to start game. Press 1, 2 or 3."<<std::endl;
   std::cout<<"1. Easy"<<std::endl<<"2. Normal"<<std::endl<<"3. Hard"<<std::endl;
   std::cin>>num;
   switch(num)
   {
       case 1: sleep=500;
       break;
       case 2: sleep=300;
       break;
       case 3: sleep=200;
       break;
   }
   system("cls");

   for(i;i<2;i++)
    {
        body[0].init(25,13);
        body[1].init(25,14);
        body[2].init(25,15);
        body[3].init(25,16);
        body[4].init(25,17);

    }

    int xRan;
        int yRan;
        A:
        {
            srand(time(0));
            xRan=rand()%27+1;
            yRan=rand()%47+1;
        };

    while(running)
    {

        Sleep(sleep);
        system("cls");
        update();

        int d;
        d=(food_val+4);
        int c=d-1;
        for(d,c;c>-1;--d,--c)
        {
            body[d].init(body[c].x,body[c].y);

        }


        for(int u=0;u<(food_val+5);u++)
        {
            if((body[u].x)==xRan&&(body[u].y)==yRan)
                goto A;
        }

        food_store.init(xRan,yRan);

        if(flag==1)
        {
            direction(w);
        }

        switch(dirn)
        {

            case 1: body[0].update_pos(0,-1);
            break;
            case 2: body[0].update_pos(1,0);
            break;
            case 3: body[0].update_pos(0,1);
            break;
            case 4: body[0].update_pos(-1,0);
            break;

        }

        if((body[0].x)==0||(body[0].x)==48||(body[0].y)==0||(body[0].y)==28)
        {
           B:
            {std::cout<<"GAME OVER"<<std::endl<<"Your score is "<<food_val<<std::endl<<"Press any key to exit";
            getch();
            exit(0);};
        }
        if((body[0].y)==(food_store.x)&&(body[0].x)==(food_store.y))
        {
            ++food_val;
            body[4+food_val].init(body[3+food_val].x,body[3+food_val].y);
            goto A;
        }
        for(int w=1;w<4+food_val;w++)
        {
            if((body[0].x)==body[w].x&&(body[0].y)==body[w].y)
                goto B;
        }

        char main_array[30][50];
        for(int m=0;m<30;m++)
        {
            for(int n=0;n<50;n++)
            {
                if((m==0)||(n==0)||(m==28)||(n==48))
                    main_array[m][n]='*';
                else
                    main_array[m][n]=' ';
            }
            main_array[m][49]='\0';
        }
        main_array[29][49]=main_array[29][48]=main_array[29][0]='\0';
        for(int y=1;y<5+food_val;y++)
        {
                main_array[body[y].y][body[y].x]='o';
        }

        main_array[body[0].y][body[0].x]='X';
        main_array[food_store.x][food_store.y]='@';
        for(int j=0;j<30;j++)
        {
            for(int k=0;k<50;k++)
            {
                std::cout<<main_array[j][k];
            }
            std::cout<<std::endl;
        }
   }
}

