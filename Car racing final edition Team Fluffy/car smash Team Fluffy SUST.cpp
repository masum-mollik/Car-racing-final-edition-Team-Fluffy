#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include<mmsystem.h>
using namespace std;

int x=300,y=350,x1 , x2 , y1 , y2 , ch,life=3,score=-10,level = 1,tim,t,initial_x,initial_y , flag= 0 , road_strip_y = 0 ,smiley_y = 0 , smiley_x = 280 ,smiley_timer = 0 ,smiley_count = 555 , game_mode  = 3 ;
int mode_pointer_y = 145 ;
int mode_pointer_x = 110;
int road_strip_timer = 0 ,love_x= 280 ,love_y=0 ,love_timer = 0;
int points,points_prev;
int cursor_pointer_x = 110 ;
int cursor_pointer_y = 75 ;
int remainig_love_x = 440,remaining_love_y = 400 , life_3 ,life_2,life_1 ; //440,380,10,14
int side_screen_counter , rectangle_x1 , rectangle_x2 , rectangle_y1 , rectangle_y2;
clock_t start,stop;
char choice,lives[100],scores[100],levels[100],times[100];
int up_tire = 0 ,down_tire = 0, step_up =0  , step_down = 0; //here,tire variables are used for tire strips
                                                             // 'step_up = 1 ' means car moved forward // but step_up was not necessary to use :-)
int leftt=440,r88=410,midd=470, color_pointer_treee=440 ,tree_count =0,fuck = 333;
void record();
void road_strips();
void road_side_tree();
void Instructions();
void save();
void load();
void high_score();
void mode();
void main_menu();
void smiley();

void love();
void boxoffice(){

    if(life==1 || life == 2 || life == 3){
        life_1 = 4 ;
    }
    else life_1 = 0 ;

    if(life == 2  || life == 3){
        life_2 = 4 ;
    }
    else life_2 = 0 ;

    if(life == 3){
        life_3 = 4 ;
    }
    else life_3 = 0 ;

            //life:
            setcolor(GREEN);

            settextstyle(3,0,2);
            sprintf(lives,"Remaining lives : ");
            outtextxy(430,360,lives);
//last life
            setcolor(life_1);



            setfillstyle(SOLID_FILL,life_1);





    fillellipse(remainig_love_x,remaining_love_y,10,14);     //x = 200 , y = 200
    fillellipse(remainig_love_x+10,remaining_love_y,10,14);
    //line(205,202,205,225);
    line(remainig_love_x+5,remaining_love_y+2,remainig_love_x+19,remaining_love_y+5);
    //right triangle of the love:
    line(remainig_love_x+10,remaining_love_y,remainig_love_x-11,remaining_love_y+6);
    line(remainig_love_x+5,remaining_love_y+25,remainig_love_x-10,remaining_love_y+5);

    //left triangle of the love:
    line(remainig_love_x+19,remaining_love_y+5,remainig_love_x+5,remaining_love_y+25);

    setfillstyle(SOLID_FILL,life_1);
    floodfill(remainig_love_x+4,remaining_love_y+12,life_1);
//2nd life
    if(life == 2 || life == 3){
        setcolor(life_2);



            setfillstyle(SOLID_FILL,life_2);





    fillellipse(remainig_love_x+35,remaining_love_y,10,14);     //x = 200 , y = 200
    fillellipse(remainig_love_x+10+35,remaining_love_y,10,14);
    //line(205,202,205,225);
    line(remainig_love_x+5+35,remaining_love_y+2,remainig_love_x+19+35,remaining_love_y+5);
    //right triangle of the love:
    line(remainig_love_x+10+35,remaining_love_y,remainig_love_x-11+35,remaining_love_y+6);
    line(remainig_love_x+5+35,remaining_love_y+25,remainig_love_x-10+35,remaining_love_y+5);

    //left triangle of the love:
    line(remainig_love_x+19+35,remaining_love_y+5,remainig_love_x+5+35,remaining_love_y+25);

    setfillstyle(SOLID_FILL,life_2);
    floodfill(remainig_love_x+4+35,remaining_love_y+12,life_2);
    }

//full life
        if(life == 3){
        setcolor(life_3);



            setfillstyle(SOLID_FILL,life_3);





    fillellipse(remainig_love_x+35+35,remaining_love_y,10,14);     //x = 200 , y = 200
    fillellipse(remainig_love_x+10+35+35,remaining_love_y,10,14);
    //line(205,202,205,225);
    line(remainig_love_x+5+35+35,remaining_love_y+2,remainig_love_x+19+35+35,remaining_love_y+5);
    //right triangle of the love:
    line(remainig_love_x+10+35+35,remaining_love_y,remainig_love_x-11+35+35,remaining_love_y+6);
    line(remainig_love_x+5+35+35,remaining_love_y+25,remainig_love_x-10+35+35,remaining_love_y+5);

    //left triangle of the love:
    line(remainig_love_x+19+35+35,remaining_love_y+5,remainig_love_x+5+35+35,remaining_love_y+25);

    setfillstyle(SOLID_FILL,life_2);
    floodfill(remainig_love_x+4+35+35,remaining_love_y+12,life_2);
    }





            //score:
            setcolor(GREEN);

            settextstyle(3,0,2);
            sprintf(scores,"Score :           %d    ",score);
            outtextxy(430,260,scores);

            setcolor(GREEN);

            settextstyle(3,0,2);
            sprintf(levels,"Level :            %d       ",level);
            outtextxy(430,140,levels);

            setcolor(GREEN);

            settextstyle(3,0,2);
            sprintf(times,"Time Elapsed:%d Sec.",tim);
            outtextxy(25,80,times);


            outtextxy(25,210,"Press ESC To Exit    ");

            outtextxy(25,310,"Press  [SPACE]   ");
            outtextxy(25,350,">> Start Menu... ");


}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}




void clear_car(int x,int y)
 {
     setcolor(8);
     rectangle(x+9 , y , x + 45 , y + 34);
    rectangle(x+9 , y + 35, x + 45 , y + 75);
    rectangle(x+9 , y + 75, x + 45 , y + 100);
     setfillstyle(SOLID_FILL,8);
     rectangle(x+3,y+10,x+7,y+20); // wheel left-front
     rectangle(x+47,y+10,x+49+1,y+20); // wheel right-front
     rectangle(x+3,y+65,x+7,y+75); // // wheel left-back
     rectangle(x+47,y+65,x+49+1,y+75); // wheel right-bac
     floodfill((x+x+48)/2,(y+y+46)/2,8);
     setcolor(11);


 }

 void makecar(int x, int y)
 {
     /*if(step_up == 1) {
            left_up_tire_1 = left_up_tire_1-50 ;
            step_up = 0 ;
     }*/
     //up_tire_strips
     if(up_tire== 0) up_tire = y+20 ;
     if(up_tire <= y+10 ) up_tire = y+20 ;
     if(up_tire > y+20) up_tire = y + 20 ;

     up_tire = up_tire - 1 ;
     line(x+3, up_tire + 2, x+7 , up_tire + 2);
     line(x+47 , up_tire , x+49+1 , up_tire);

     line(x+3, up_tire  , x+7 , up_tire );
     line(x+47 , up_tire +2 , x+49+1 , up_tire + 2);

     //down_tire_strips
     if(down_tire== 0) down_tire = y + 75 ;
     if(down_tire <= y+65 ) down_tire = y+75 ;
     if(down_tire > y+75) down_tire = y + 75 ;

     down_tire = down_tire - 1 ;
     //frst strip :
     line(x+3, down_tire  , x+7 , down_tire );
     line(x+47 , down_tire , x+49+1 , down_tire);
     //scnd strip :
     line(x+3, down_tire + 2, x+7 , down_tire + 2);
     line(x+47, down_tire + 2, x+49+1 , down_tire + 2);


 //setfillstyle(SOLID_FILL,8);
    rectangle(x+3,y+10,x+7,y+20); // // wheel left-front
    rectangle(x+47,y+10,x+49+1,y+20); // wheel right-front
    rectangle(x+3,y+65,x+7,y+75); // // wheel left-back
    rectangle(x+47,y+65,x+49+1,y+75); // wheel right-back

    rectangle(x+9 , y , x + 45 , y + 34);
    rectangle(x+9 , y + 35, x + 45 , y + 75);
    rectangle(x+9 , y + 75, x + 45 , y + 100);
    //setfillstyle(SOLID_FILL,8);
    // floodfill((x+20),(y+10),13);
    setcolor(11);
    road_strip_timer++;
    if(road_strip_timer == 4){
    road_strips();
    road_strip_timer= 0 ;
    love();

    }

  }


 void clear_car_enemy(int x,int y)
 {
 setcolor(8);
    rectangle(x+9 , y , x + 45 , y + 34);
    rectangle(x+9 , y + 35, x + 45 , y + 75);
    rectangle(x+9 , y + 75, x + 45 , y + 100);
 setfillstyle(SOLID_FILL,8);
rectangle(x+3,y+10,x+7,y+20); // wheel left-front
rectangle(x+47,y+10,x+49+1,y+20); // wheel right-front
rectangle(x+3,y+65,x+7,y+75); // // wheel left-back
rectangle(x+47,y+65,x+49+1,y+75); // wheel right-bac
 floodfill((x+x+48)/2,(y+y+98)/2,8);
 //setcolor(15);



 }

   void make_enemy(int x, int y)
 {
     setcolor(11);
 //setfillstyle(SOLID_FILL,8);
rectangle(x+3,y+10,x+7,y+20); // // wheel left-front
rectangle(x+47,y+10,x+49+1,y+20); // wheel right-front
rectangle(x+3,y+65,x+7,y+75); // // wheel left-back
rectangle(x+47,y+65,x+49+1,y+75); // wheel right-back
    setcolor(11);
    rectangle(x+9 , y , x + 45 , y + 34);
    rectangle(x+9 , y + 35, x + 45 , y + 75);
    rectangle(x+9 , y + 75, x + 45 , y + 100);
  //setfillstyle(SOLID_FILL,8);
 // floodfill((x+x+50)/2,(y+y+100)/2,15);

  }


int main()
 {
  int driver,mode;
  driver = DETECT;
  initgraph(&driver,&mode,"..\bgi");







  FILE *info;



    info=fopen("new_record.txt","r");


    fscanf(info,"%d",&points_prev);


     fclose(info);








   cleardevice();
   PlaySoundA(TEXT("loading.wav"),NULL,SND_ASYNC);

 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 //setbkcolor(rand());
 setcolor(4);
 int c=150;
for(int e=0;e<20;e++) //Change 15 to your desired value
 {
  for(int m=50;m<400;m++)
  {
    setcolor(3);
    settextstyle(SMALL_FONT, HORIZ_DIR, 10);
    outtextxy(315,233,"Loading...");
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(315+5,233+5,"Please Wait... ");
    circle(315,233,m);
    circle(315,233,c);
    c--;
    outtextxy(200,300,"Team FLUFFY(MASUM & WASIF)");
    cleardevice();
  }
  }
  setcolor(6);
  settextstyle(SMALL_FONT, HORIZ_DIR, 10);
  //settextjustify(315,233);
  outtextxy(315-70,233-60,"WELCOME");
  delay(200);
  outtextxy(315-70,233-20,"TO");
  delay(250);
  outtextxy(315-5,233-20,"  THE");
  delay(350);
  outtextxy(315-50,240+15,"CAR");
  delay(300);
  outtextxy(315-50, 280 +15 ,"SMASH");
  delay(350);
  outtextxy(315-10,320+15,"2 !!!");
  delay(1200);
  cleardevice();
  cleardevice();

    main_menu() ;
    start=clock();

  for(int m=1;m<25;m++)
	for(int n=1;n<80;n++) {

		}






  for(level=1;(level<=5)&&(life>0);level++){
	if(level==1){

	 delay(500);

	 }
	else {

	    delay(400);

	    }
  for(int i=0;(i<15)&&(life>0);i++) {



	int accident=0;
    y1=1,x1=250+((rand()%3)*50);
    y2=1,x2=250+((rand()%3)*50);


    if(flag == 0){
        initial_x = x;
        initial_y = y;
        flag = 1 ;
    }


	score += 10;
	while(y1<getmaxy()-1)
	{
    stop=clock();
    t=(stop-start)/CLK_TCK;
    tim=t;

    floodfill(10,10,WHITE);
    boxoffice();

    setcolor(BLUE);
    rectangle(420,125,600,175);
    setcolor(RED);

    rectangle(15,60,220,120);
    rectangle(15,300,220,420);
    rectangle(249,0,401,getmaxy());
    setfillstyle(SOLID_FILL,8);
    floodfill(325,getmaxy()/2,RED);
    setcolor(RED);
    rectangle(15,200,220,250);
    rectangle(420,250,600,300);
    rectangle(420,350,600,450);
    if(tim ==30) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==60) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==90) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==120) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==150) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==180) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==210) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==240) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==270) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==300) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==330) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==360) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
    if(tim ==390) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);

		clear_car_enemy(x1,y1);
		makecar(x,y);
		clear_car_enemy(x2,y2);
		makecar(x,y);
		if(game_mode == 1){
            y1++;
            y2++;
		}
		if(game_mode == 2){
            y1 += 3;
            y2 += 3;
		}
		if(game_mode == 3){
            y1 += 4 ;
            y2 += 4 ;
		}
		make_enemy(x1,y1);
		make_enemy(x2,y2);
		makecar(x,y);
		delay(6-(2*level));
		if(kbhit())
		{
			makecar(x,y);
			ch=getch();
			if((smiley_x == x+30 )){
                if((smiley_y == y || (smiley_y > y && smiley_y < y+100))  ){
                    score = score+50 ;
                    smiley_y = 0 ;
                    smiley_timer = 0;

                }


			}
        if (smiley_y == 400 ) {
                smiley_y = 0 ;
                smiley_x = 280+((rand()%3)*50);
                smiley_timer = 0 ;



        }
			switch(ch) {
			case 27: exit(0);
			break;
			case 75:clear_car(x,y);
				if(x>250)
					x=x-50;
				makecar(x,y);
			break;
			case 77:clear_car(x,y);
				if(x<350)
					x=x+50;
				makecar(x,y);

			break;
			case 72:clear_car(x,y);

					y= y-50;
					if(y<=0) {
                            y = y+50 ;
                            step_down = 1 ;
					}
                    makecar(x,y);

			break;
			case 80:clear_car(x,y);

					y= y+50;
					if(y>=400) {
                            y = y-50 ;
                            makecar(x,y);
                            step_up =1 ;
				}
				 makecar(x,y);

			break;

			case  32:{
			cleardevice();
			main_menu();

			}

			}
		}

        road_side_tree();
		//smiley();
		smiley();
		if((x==x1)||(x==x2))
			if( ( ((y-y1)<=100)&&((y-y1)>=0) ) || ( ((y-y2)<=100)&&((y-y2)>=0) ) || ((y+100) >= y1 && y+100 <= y1+100 ) || (y+100 >= y2 && y+100 <= y2+100 ) ){
				accident=1;
				PlaySoundA(TEXT("car_crash2.wav"),NULL,SND_ASYNC);
				goto dead ;

           // else if()
			}
	 }
	 dead:
	 if(accident==1){
	   life =life-1;
	   score -= 10;

	   for(int k = 0 ; k<=15;k++){
        setcolor(k);
            settextstyle(3,0,6);
            outtextxy(150,130,"CRUSHED!!!");
            x = initial_x;
                y = initial_y;
            delay(100);
	   }
            delay(1500);
            cleardevice();

PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);

	   }
	   if(life==0) {



	    break;
	    }
  }
  }
  PlaySoundA(TEXT("Game_over.wav"),NULL,SND_ASYNC);
  int  w = 0 , r = 1;

  for( ; w <16 ; w++, r++ ){
    setcolor(w);
    if(r >= 5) r = 1 ;
    settextstyle(3,0,r);
    outtextxy(200,200,"GAME OVER!!!");
    delay(400);
    cleardevice();
  }
if(score > points_prev) {
        PlaySoundA(TEXT("clapping.wav"),NULL,SND_ASYNC);

        for(int i = 0 ; i < 16 ; i++){
            setcolor(i);

            settextstyle(3,0,3);
            outtextxy(200 , 200 ,"NEW HIGH SCORE!!!");
            settextstyle(3,0,4);
            sprintf(scores,"Score :  %d  ",score);
            outtextxy(230,260,scores);
            delay(400);
        }



   }

    getch();
    record();

 getch();
 }

void Menu()
{
    setcolor(13);
    settextstyle(3,0,8);
    outtextxy(100,100,"Car Smash !!!");
    getch();
    cleardevice();
}


void main_menu() // for highlighting Start Game
{

    cleardevice() ;
    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;

   if(cursor_pointer_y == 75){
        PlaySoundA(TEXT("beep.wav"),NULL,SND_ASYNC);

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(RED) ;
    settextstyle(3 , 0 , 4);

    outtextxy(130 , 60 , "Start Game") ;
    rectangle(130,65,292,90);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
   outtextxy(130 , 100 , "Instructions") ;

   outtextxy(130 , 135 , "Mode") ;

   outtextxy(130 , 170 , "Best Score") ;

   outtextxy(130 , 205 ,"Save Game") ;

   outtextxy(130 , 240 , "Load Game");
setcolor(RED);
rectangle(310,65,600,400);
outtextxy(320,70,"Press [ENTER] to Start...");


setcolor(WHITE);

line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

}
else if(cursor_pointer_y == 110){ //for highlighting Instructions
    cleardevice();

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(GREEN) ;
   settextstyle(3 , 0 , 4);
   outtextxy(130 , 90 , "Instructions") ;
    rectangle(130,92,292,120);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
    outtextxy(130 , 60 , "Start Game") ;
    outtextxy(130 , 135 , "Mode") ;

   //outtextxy(130 , 130 , "Mode") ;

   outtextxy(130 , 170 , "Best Score") ;

   outtextxy(130 , 205 ,"Save Game") ;

   outtextxy(130 , 240 , "Load Game");
setcolor(WHITE);

   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

    setcolor(GREEN);
    rectangle(310,65,600,400);
    outtextxy(320,70,"Don't you want to know the");
    outtextxy(320,100,"rules?!! then, press [Enter]");
}


else if(cursor_pointer_y == 145){
    PlaySoundA(TEXT("beep.wav"),NULL,SND_ASYNC);

    cleardevice();

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(CYAN) ;
   settextstyle(3 , 0 , 4);
   outtextxy(130 , 135 , "Mode") ;
    rectangle(130,137,207,165);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
    outtextxy(130 , 60 , "Start Game") ;
   outtextxy(130 , 90 , "Instructions") ;

   //outtextxy(130 , 130 , "Mode") ;

   outtextxy(130 , 170 , "Best Score") ;

   outtextxy(130 , 205 ,"Save Game") ;

   outtextxy(130 , 240 , "Load Game");

   setcolor(WHITE);

   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y) ;

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

    setcolor(CYAN);
    rectangle(310,65,600,400);
    outtextxy(320,70,"Do you think yourself a 'Perfect");
    outtextxy(320,105,"RACER'?!!,Then Play At higher");
    outtextxy(320,140,"Level...");


}


else if(cursor_pointer_y == 180){

    cleardevice();

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(12) ;
   settextstyle(3 , 0 , 4);
   outtextxy(130 , 170 , "Best Score") ;
    rectangle(130,172,285,200);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
    outtextxy(130 , 60 , "Start Game") ;
   outtextxy(130 , 90 , "Instructions") ;

   //outtextxy(130 , 130 , "Mode") ;
    outtextxy(130 , 135 , "Mode") ;


   outtextxy(130 , 205 ,"Save Game") ;

   outtextxy(130 , 240 , "Load Game");

   setcolor(WHITE);

    line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

    setcolor(12);
    rectangle(310,65,600,400);
    outtextxy(320,70,"Press Enter to See Best Score");
}


else if(cursor_pointer_y == 215){
    PlaySoundA(TEXT("beep.wav"),NULL,SND_ASYNC);

    cleardevice();

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(7) ;
   settextstyle(3 , 0 , 4);
   outtextxy(130 , 205 ,"Save Game") ;

    rectangle(130,207,295,235);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
    outtextxy(130 , 60 , "Start Game") ;
   outtextxy(130 , 90 , "Instructions") ;

   //outtextxy(130 , 130 , "Mode") ;
    outtextxy(130 , 135 , "Mode") ;

    outtextxy(130 , 170 , "Best Score") ;

   outtextxy(130 , 240 , "Load Game");

   setcolor(WHITE);

   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

    setcolor(7);
    rectangle(310,65,600,400);
    outtextxy(320,70,"Are you feeling tired after a ");
    outtextxy(320,105,"long Race?! then, Save the ");
    outtextxy(320,140,"Game at here...");
    outtextxy(320,210,"Press [ENTER] to approach");

}

else if(cursor_pointer_y == 250){

    cleardevice();

    setcolor(BLUE) ;
    settextstyle(3 , 0 , 5) ;
   outtextxy(140 , 2 , "CAR SMASH V 2.0 ") ;
    setcolor(6) ;
   settextstyle(3 , 0 , 4);
   outtextxy(130 , 240 , "Load Game");
    rectangle(130,242,297,270);

    setcolor(WHITE);
    settextstyle(3 , 0 , 2);
    outtextxy(130 , 60 , "Start Game") ;
   outtextxy(130 , 90 , "Instructions") ;

   //outtextxy(130 , 130 , "Mode") ;
    outtextxy(130 , 135 , "Mode") ;

    outtextxy(130 , 170 , "Best Score") ;
    outtextxy(130 , 205 ,"Save Game") ;
    setcolor(WHITE);

    line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x  + 15 +185,cursor_pointer_y );
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 5 +185, cursor_pointer_y , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x +185, cursor_pointer_y - 7 , cursor_pointer_x + 5 +185, cursor_pointer_y ) ;
   line(cursor_pointer_x +185, cursor_pointer_y + 7 , cursor_pointer_x + 15 +185, cursor_pointer_y) ;
   line(cursor_pointer_x + 185, cursor_pointer_y + 7 , cursor_pointer_x + 5+185 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 +185, cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5+185 , cursor_pointer_y + 3 , WHITE) ;

    setcolor(6);
    rectangle(310,65,600,400);
    outtextxy(320,70,"Accept Your Incomplete ");
    outtextxy(320,105,"Challenge...");
    outtextxy(320,210,"Press [ENTER] to approach");



}
    setcolor(WHITE);

   line(cursor_pointer_x , cursor_pointer_y - 7 , cursor_pointer_x  + 15 ,cursor_pointer_y );
   line(cursor_pointer_x , cursor_pointer_y + 7 , cursor_pointer_x + 15 , cursor_pointer_y) ;
   line(cursor_pointer_x + 5 , cursor_pointer_y , cursor_pointer_x + 15 , cursor_pointer_y) ;
   line(cursor_pointer_x , cursor_pointer_y - 7 , cursor_pointer_x + 5 , cursor_pointer_y ) ;
   line(cursor_pointer_x , cursor_pointer_y + 7 , cursor_pointer_x + 15 , cursor_pointer_y) ;
   line(cursor_pointer_x , cursor_pointer_y + 7 , cursor_pointer_x + 5 , cursor_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(cursor_pointer_x + 5 , cursor_pointer_y - 3 , WHITE) ;
    floodfill(cursor_pointer_x + 5 , cursor_pointer_y + 3 , WHITE) ;
    //start game animation

    char ch = getch();
    if(cursor_pointer_y < 245 && ch == 80) {
            cursor_pointer_y =  cursor_pointer_y  + 35 ;

    }
    if(cursor_pointer_y > 75 && ch == 72) {
            cursor_pointer_y =  cursor_pointer_y  - 35 ;

    }
    if(ch != 13 ) {
        main_menu() ;
    }
    else {
        if(cursor_pointer_y == 75) {
                cleardevice();
                PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
                if(tim ==30) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
                if(tim ==60) PlaySoundA(TEXT("running_car.wav"),NULL,SND_ASYNC);
                return ;
        }
        else if(cursor_pointer_y == 110){
            Instructions();
        }

        else if(cursor_pointer_y == 145)
            mode();
        else if(cursor_pointer_y == 180)
            high_score();
        else if(cursor_pointer_y == 215)
            save();
        else if(cursor_pointer_y == 250)
            load();
             }

}

void Instructions()
{
    cleardevice();
    setcolor(WHITE);
    settextstyle(3 , 0 , 4) ;
    outtextxy(100,100 ,"Instructions:");

    setcolor(11);
    settextstyle(3 , 0 , 3);
    outtextxy(100,150,"*use arrow key to move the car...");
    outtextxy(100,180,"*saving yourself from the enemies");
    outtextxy(100,210,"  coming from the opposite side will");
    outtextxy(100,240,"  get you 10 points...");
    outtextxy(100,270,"*collect smiley to get 50 bonus points!!!");
    outtextxy(100,300,"  You will get 3 lives. so,be away from clash!!!");
    outtextxy(100,330,"*collect rare life token to get bonus life!!!");

    outtextxy(150,370,"press [SPACE] >> Sart Menu");

    char ch = getch();
    if(ch == 32) {
            cleardevice();
        main_menu();
    }
    else Instructions();
    cleardevice();
}
void mode()
{

    cleardevice();
    setcolor(WHITE);
    //settextstyle(3 , 0 , 4) ;
    //outtextxy(100,200 ,"Mode");

    line(mode_pointer_x , mode_pointer_y - 7 , mode_pointer_x  + 15 ,mode_pointer_y );
   line(mode_pointer_x , mode_pointer_y + 7 , mode_pointer_x + 15 , mode_pointer_y) ;
   line(mode_pointer_x + 5 , mode_pointer_y , mode_pointer_x + 15 , mode_pointer_y) ;
   line(mode_pointer_x , mode_pointer_y - 7 , mode_pointer_x + 5 , mode_pointer_y ) ;
   line(mode_pointer_x , mode_pointer_y + 7 , mode_pointer_x + 15 , mode_pointer_y) ;
   line(mode_pointer_x , mode_pointer_y + 7 , mode_pointer_x + 5 , mode_pointer_y  );

    setfillstyle(SOLID_FILL ,WHITE) ;
    floodfill(mode_pointer_x + 5 , mode_pointer_y - 3 , WHITE) ;
    floodfill(mode_pointer_x + 5 , mode_pointer_y + 3 , WHITE) ;

    if(mode_pointer_y == 145){
        setcolor(CYAN);
        settextstyle(3,0,4);
        outtextxy(130 , 125 ,"Easy");

        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(130,180,"Normal");
        outtextxy(130,215,"Hard");
    }

    if(mode_pointer_y == 180){
        setcolor(RED);
        settextstyle(3,0,4);
        outtextxy(130 , 170 ,"Normal");

        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(130,135,"Easy");
        outtextxy(130,215,"Hard");
    }

    if(mode_pointer_y == 215){
        setcolor(YELLOW);
        settextstyle(3,0,4);
        outtextxy(130 , 205 ,"Hard");

        setcolor(WHITE);
        settextstyle(3,0,3);
        outtextxy(130,135,"Easy");
        outtextxy(130,170,"Normal");
    }
    setcolor(WHITE);
    outtextxy(300,300,"Press B >> Main Menu");
char ch ;
ch = getch();

    if(ch == 72 ){
            mode_pointer_y -= 35 ;
        if(mode_pointer_y < 145) mode_pointer_y = 145 ;
        mode();

    }
    if(ch == 80){
        mode_pointer_y += 35 ;
        if(mode_pointer_y > 215) mode_pointer_y = 215 ;
        mode();
    }



    if(ch == 13){
        if(mode_pointer_y == 145){
            game_mode = 1 ;
            //printf("%d",game_mode);
            mode();
        }

        if(mode_pointer_y == 180){
            game_mode = 2;
            //printf("%d",game_mode);
            mode();
        }
        if(mode_pointer_y == 215){
            game_mode = 3 ;
            //printf("%d",game_mode);
            mode();
        }

    }
    if(ch == 'b' || ch == 'B') {
            main_menu();
            cleardevice();
            }
    if(ch != 72 && ch != 80 && ch != 13 && ch != 'b' && ch!= 'B' ){
        setcolor(RED);
        outtextxy(300,300,"Press [ENTER] to select...");
        delay(200);
        mode();
    }





    cleardevice();

}

void save()
{
    int lines[1000] = { x,y,x1 , x2 , y1 , y2 , ch,life,score,level ,tim,t,initial_x,initial_y , flag , road_strip_y  ,smiley_y , smiley_x  ,smiley_timer  ,smiley_count ,game_mode ,road_strip_timer ,love_x ,love_y ,love_timer , points,points_prev,cursor_pointer_x ,cursor_pointer_y ,remainig_love_x ,remaining_love_y , life_3 ,life_2,life_1 ,side_screen_counter , rectangle_x1 , rectangle_x2 , rectangle_y1 , rectangle_y2, up_tire  ,down_tire , step_up  , step_down ,leftt,r88,midd, color_pointer_treee,tree_count,9};
    cleardevice();
    setcolor(CYAN);
    settextstyle(3 , 0 , 4) ;
    outtextxy(100 , 200 , "Press [ENTER] to Save Game Data");
    settextstyle(3,0,3);
    outtextxy(300,300,"Press B >> Start Menu");
    char ch = getch();
    if(ch == 'b' || ch == 'B'){
        main_menu();
    }
    else if(ch == 13){
        FILE *fp_in;
    char *input_file = "saved game.txt" ;
    fp_in = fopen(input_file , "w");
    for(int i= 0 ; i <48 ; i++){


        fprintf(fp_in, "%d ",lines[i]);
    }

    fclose(fp_in);
    setcolor(GREEN);
    outtextxy(300,300,"DATA SAVED !!!..........");
    delay(700);
    save();

    }

    else{
            setcolor(CYAN);
            settextstyle(3,0,3);
        outtextxy(300,300,"Press [ENTER] to save!!!");
        delay(400);
        save();
    }





    cleardevice();

}
void load()
{

    cleardevice();
    setcolor(CYAN);
    settextstyle(3 , 0 , 3) ;
    outtextxy(50, 200 , "Press [ENTER] to load Saved Game To Load");
    outtextxy(300,400,"Press B >> Start Menu");
    char ch;
    ch = getch();


    if(ch == 13){
            cleardevice();
        int variables[100];
        FILE *fp_in;
        char *input_file = "saved game.txt" ;

        fp_in = fopen(input_file , "r");
        for(int i= 0 ; i <48 ; i++){


            fscanf(fp_in, "%d",&variables[i]);
        }

        for(int i=0 ; i < 48 ; i++) printf("%d " , variables[i]);
        x = variables[0];
        y =variables[1];
        x1 = variables[2];
        x2 = variables[3];
        y1 = variables[4];
        y2 = variables[5];
        ch = variables[6];
        life = variables[7];
        score = variables[8];
        level = variables[9];
        tim = variables[10];
        t = variables[11];
        initial_x = variables[12];
        initial_y = variables[13];
        flag = variables[14];
        road_strip_y = variables[15];
        smiley_y = variables[16];
        smiley_x = variables[17];
        smiley_timer = variables[18];
        smiley_count = variables[19];
        game_mode = variables[20];
        road_strip_timer = variables[21];
        love_x = variables[22];
        love_y = variables[23];
        love_timer = variables[24];
        points = variables[25];
        //points_prev = variables[26];
        cursor_pointer_x = variables[27];
        cursor_pointer_y = variables[28];
        remainig_love_x = variables[29];
        remaining_love_y = variables[30];
        life_3 = variables[31];
        life_2  = variables[32];
        life_1 = variables[33];
        side_screen_counter = variables[34];
        rectangle_x1 = variables[35];
        rectangle_x2 = variables[36];
        rectangle_y1 = variables[37];
        rectangle_y2 = variables[38];
        up_tire = variables[39];
        down_tire = variables[40];
        step_up = variables[41];
        step_down = variables[42];
        leftt = variables[43];
        r88 = variables[44];
        midd = variables[45];
        color_pointer_treee = variables[46];
        tree_count = variables[47];


        fclose(fp_in);
    }
    else if(ch == 'b' || ch == 'B') {
            cleardevice();
            main_menu();

    }
    else if(ch != 13) {
            cleardevice();
            outtextxy(50, 200 , "Press [ENTER] to load Saved Game To Load");
            setcolor(RED);

            outtextxy(300,400,"Press [ENTER] to load");
            delay(500);
            load();
    }

    cleardevice();
}

void road_strips()
{
    //1st
    setcolor(WHITE);
    rectangle(300,road_strip_y,305,road_strip_y + 20);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5,WHITE);
    //2nd
    rectangle(300 , road_strip_y + 40 , 305 , road_strip_y +  20 + 40);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 40 , WHITE);
    //3rd
    rectangle(300,road_strip_y + 80 ,305,road_strip_y + 100);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 80 , WHITE);
   //4th
    rectangle(300,road_strip_y + 120 ,305,road_strip_y + 140);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 120 , WHITE);
    //5th
    rectangle(300,road_strip_y + 160 ,305,road_strip_y + 180);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 160 , WHITE);
    //6th
    rectangle(300,road_strip_y + 200 ,305,road_strip_y + 220);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 200 , WHITE);
    //7th
    rectangle(300,road_strip_y + 240 ,305,road_strip_y + 260);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 240 , WHITE);
    //8th
    rectangle(300,road_strip_y + 280 ,305,road_strip_y + 300);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 280 , WHITE);
    //9th
    rectangle(300,road_strip_y + 320 ,305,road_strip_y + 340);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 320 , WHITE);
    //10th
    rectangle(300,road_strip_y + 360 ,305,road_strip_y + 380);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 360 , WHITE);
    //11th
    rectangle(300,road_strip_y + 400 ,305,road_strip_y + 420);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(303,road_strip_y + 5 + 400 , WHITE);
//1st right
    rectangle(350,road_strip_y,355,road_strip_y + 20);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(354,road_strip_y + 5,WHITE);
    //2nd
    rectangle(350 , road_strip_y + 40 , 355 , road_strip_y +  20 + 40);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 40 , WHITE);
    //3rd
    rectangle(350,road_strip_y + 80 ,355,road_strip_y + 100);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 80 , WHITE);
   //4th
    rectangle(350,road_strip_y + 120 ,355,road_strip_y + 140);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 120 , WHITE);
    //5th
    rectangle(350,road_strip_y + 160 ,355,road_strip_y + 180);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 160 , WHITE);
    //6th
    rectangle(350,road_strip_y + 200 ,355,road_strip_y + 220);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 200 , WHITE);
    //7th
    rectangle(350,road_strip_y + 240 ,355,road_strip_y + 260);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 240 , WHITE);
    //8th
    rectangle(350,road_strip_y + 280 ,355,road_strip_y + 300);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 280 , WHITE);
    //9th
    rectangle(350,road_strip_y + 320 ,355,road_strip_y + 340);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 320 , WHITE);
    //10th
    rectangle(350,road_strip_y + 360 ,355,road_strip_y + 380);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 360 , WHITE);
    //11th
    rectangle(350,road_strip_y + 400 ,355,road_strip_y + 420);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(353,road_strip_y + 5 + 400 , WHITE);



    road_strip_y = road_strip_y + 2 ;
    if (road_strip_y == 40) road_strip_y = 0 ;

}

void smiley()
{
    smiley_timer++;

    if(smiley_timer >500 ){
        setfillstyle(SOLID_FILL , YELLOW) ;
        fillellipse(smiley_x ,  smiley_y , 13 ,13 ) ;
        line(smiley_x-5 , smiley_y+6,smiley_x+5,smiley_y+6);
        line(smiley_x-6, smiley_y,smiley_x-1,smiley_y);
        line(smiley_x+1,smiley_y,smiley_x+6,smiley_y);


        setfillstyle(SOLID_FILL , YELLOW) ;
        fillellipse(smiley_x ,  smiley_y , 13 ,13 ) ;
        line(smiley_x-5 , smiley_y+6,smiley_x+5,smiley_y+6);
        line(smiley_x-6, smiley_y,smiley_x-1,smiley_y);
        line(smiley_x+1,smiley_y,smiley_x+6,smiley_y);



        setfillstyle(SOLID_FILL , YELLOW) ;
        fillellipse(smiley_x ,  smiley_y , 13 ,13 ) ;
        line(smiley_x-5 , smiley_y+6,smiley_x+5,smiley_y+6);
        line(smiley_x-6, smiley_y,smiley_x-1,smiley_y);
        line(smiley_x+1,smiley_y,smiley_x+6,smiley_y);



        setfillstyle(SOLID_FILL , YELLOW) ;
        fillellipse(smiley_x ,  smiley_y , 13 ,13 ) ;
        line(smiley_x-5 , smiley_y+6,smiley_x+5,smiley_y+6);
        line(smiley_x-6, smiley_y,smiley_x-1,smiley_y);
        line(smiley_x+1,smiley_y,smiley_x+6,smiley_y);



        setfillstyle(SOLID_FILL , YELLOW) ;
        fillellipse(smiley_x ,  smiley_y , 13 ,13 ) ;
        line(smiley_x-5 , smiley_y+6,smiley_x+5,smiley_y+6);
        line(smiley_x-6, smiley_y,smiley_x-1,smiley_y);
        line(smiley_x+1,smiley_y,smiley_x+6,smiley_y);

        smiley_y += 1;
        //printf("(x,y)=(%d,%d)  (smiley_x,smiley_x) = (%d,%d)\n",x ,y ,smiley_x, smiley_y);
        if((smiley_x == x+30 )){
			if((smiley_y == y || (smiley_y > y-5 && smiley_y < y+100))  ){
				score = score+50 ;
				smiley_y = 0 ;
				smiley_timer = 0;

			}


			}
        if (smiley_y == 400 ) {
                smiley_y = 0 ;
                smiley_x = 280+((rand()%3)*50);
                smiley_timer = 0 ;



        }
    }
}

void road_side_tree()
{
    int mid = midd ,r8 = r88 ,left = leftt ,color_pointer_tree =color_pointer_treee;
    setcolor(GREEN);
//1st triangle
    line(230,left,248,mid);
    line(230,left,248,r8);
    line(248,410,248,470);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree,GREEN);
//2nd triangle
    line(230,left-30,240,mid-45);
    line(230,left-30,248,r8-35);
    line(248,375,248,410);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-25,GREEN);
//3rd triangle
    line(230,left-60,240,mid-80);
    line(230,left-60,248,r8-70);
    line(248,375,248,340);
    line(248,340,248,-20);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-55,GREEN);
//4th triangle
    line(230,left-95,240,mid-113);
    line(230,left-95,248,r8-105);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-35,GREEN);

//5th triangle
    line(230,left-130,240,mid-148);
    line(230,left-130,248,r8-140);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-70,GREEN);

//6th triangle
    line(230,left- 165,240,mid-183);
    line(230,left-165,248,r8-175);

    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-105,GREEN);

//7th
    line(230,left-200,240,mid-218);
    line(230,left-200,248,r8-210);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-140,GREEN);

//8th
    line(230,left-235,240,mid-253);
    line(230,left-235,248,r8-245);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-175,GREEN);

    line(230,left-270,240,mid-288);
    line(230,left-270,248,r8-280);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-210,GREEN);

    line(230,left-305,240,mid-323);
    line(230,left-305,248,r8-315);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-245,GREEN);


    line(230,left-340,240,mid-358);
    line(230,left-340,248,r8-350);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-280,GREEN);


    line(230,left-375,240,mid-393);
    line(230,left-375,248,r8-385);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-315,GREEN);


    line(230,left-410,240,mid-428);
    line(230,left-410,248,r8-420);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-350,GREEN);

    line(230,left-445,240,mid-463);
    line(230,left-445,248,r8-455);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-385,GREEN);

    line(230,left-480,240,mid-498);
    line(230,left-480,248,r8-490);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-420,GREEN);

    line(230,left-515,240,mid-533);
    line(230,left-515,248,r8-525);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(235,color_pointer_tree-455,GREEN);
    tree_count++;
    if(tree_count>=5){
        leftt=440;
        r88=410;
        midd=470;
        color_pointer_treee=440;
        tree_count =0;
    }
    else{
        leftt = leftt +2;
        r88 = r88+2;
        midd;
        color_pointer_tree++;

    }
    setfillstyle(SOLID_FILL,WHITE); //here ,this logic remains the background color white :-P
    floodfill(5,4,WHITE);
}

void love()
{

    love_timer++;
    if(love_timer > 1000){
        setcolor(RED);

    setfillstyle(SOLID_FILL,RED);
    fillellipse(love_x,love_y,10,14);     //x = 200 , y = 200
    fillellipse(love_x+10,love_y,10,14);
    //line(205,202,205,225);
    line(love_x+5,love_y+2,love_x+19,love_y+5);
//right triangle of the love:
    line(love_x+10,love_y,love_x-11,love_y+6);
    line(love_x+5,love_y+25,love_x-10,love_y+5);

//left triangle of the love:
    line(love_x+19,love_y+5,love_x+5,love_y+25);

    setfillstyle(SOLID_FILL,RED);
    floodfill(love_x+4,love_y+12,RED);
    love_y = love_y +2 ;
    love_timer++;
//printf("(love_x,love_y) = (%d,%d) , (x,y) = ((%d,%d)\n", love_x , love_y , x , y);
        if((love_x >= x && love_x <= x+80 )){
			if((love_y == y || (love_y > y && love_y < y+100))  ){


        setcolor(8);
        setfillstyle(SOLID_FILL,8);
        floodfill(love_x+4,love_y+12,8);
        setfillstyle(SOLID_FILL,8);
    fillellipse(love_x,love_y,10,14);
    fillellipse(love_x+10,love_y,10,14);

                life = life+1 ;
                if(life>3) life= 3 ;
				love_y = 0 ;
				love_timer = 0;
				cleardevice();
			}


			}
        if (love_y == 400 ) {
                love_y = 0 ;
                love_x = 280+((rand()%3)*50);
                love_timer = 0 ;
                setcolor(8);
                setfillstyle(SOLID_FILL,8);
                floodfill(love_x,love_y,8);

                setfillstyle(SOLID_FILL,8);
                fillellipse(love_x,love_y,10,14);     //x = 200 , y = 200
                fillellipse(love_x+10,love_y,10,14);

                love_y = 0 ;
                love_x = 280+((rand()%3)*50);
                love_timer = 0 ;

        }
        if(love_timer%5 == 0){
                setcolor(8);
            setfillstyle(SOLID_FILL,8);
        floodfill(love_x+4,love_y+12,8);
        setfillstyle(SOLID_FILL,8);
        fillellipse(love_x,love_y,10,14);
        fillellipse(love_x+10,love_y,10,14);
        }
    }
}









void record()
{
    cleardevice();
    clearviewport();
    char plname[20],nplname[20],cha,c;
   int i,j= 0,px;
   FILE *info;

   system("cls");
   if(score > points_prev) {
        info=fopen("new_record.txt","w");
        fprintf(info,"%d\n",score);


    //printf("Enter your name\n");
    //scanf("%[^\n]",plname);
   //************************
a:
    cleardevice();
    setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
   char ch = getch();
   if(ch>= 'a' && ch<= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
        if(ch == 13) goto name_process;
       plname[j] = ch;
       plname[j+1] = '\0';
       outtextxy(200,300,plname);
    }
   else {
    outtextxy(300,300,"Insert only Alphanumeric symbol:-(");
    delay(500);
    goto a;
   }


 b:

    setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
    ch = getch();
    if(ch>='a' && ch<='z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
        if(ch == 13) goto name_process;
       plname[1] = ch;
       plname[2] = '\0';
       outtextxy(200,300,plname);
    }
   else {
    outtextxy(300,300,"Insert only Alphanumeric symbol:-(");
    delay(500);
    cleardevice();
    plname[1] = '\0';
    outtextxy(200,300,plname);
    goto b;
   }



c:
    setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
    ch = getch();
    if(ch>='a' && ch<='z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
            delay(200);
        if(ch == 13) goto name_process;
        plname[2] = ch ;
        plname[3] = '\0';
        outtextxy(200,300,plname);
    }

    else{
        outtextxy(300,300,"Insert only Alphanumeric symbol:-(");
        delay(500);
        cleardevice();
        plname[2] = '\0';
        outtextxy(200,300,plname);
        goto c;
    }


d:
     setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
    ch = getch();
    if(ch>='a' && ch<='z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
            delay(200);
        if(ch == 13) goto name_process;
        plname[3] = ch ;
        plname[4] = '\0';
        outtextxy(200,300,plname);
    }

    else{
         outtextxy(200,400,"Insert only Alphanumeric symbol:-(");
        delay(500);
        cleardevice();
        plname[3] = '\0';
        outtextxy(200,300,plname);
        goto d;
    }

e:
     setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
    if(ch>='a' && ch<='z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
            delay(200);
        ch = getch();
        if(ch == 13) goto name_process;
        plname[4] = ch ;
        plname[5] = '\0';
        outtextxy(200,300,plname);
    }
    else{
        outtextxy(300,300,"Insert only Alphanumeric symbol:-(");
        delay(500);
        cleardevice();
        plname[4] = '\0';
        outtextxy(200,300,plname);
        goto e;

    }
f:
     setcolor(3);
    settextstyle(3,0,3);
    outtextxy(200,200,"Enter Your Name");
    if(ch>='a' && ch<='z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' ){
            delay(200);
    ch = getch();
    if(ch == 13) goto name_process;
    plname[5] = ch ;
    plname[6] = '\0';
    outtextxy(200,300,plname);
    }
    else{

        outtextxy(300,300,"Insert only Alphanumeric symbol:-(");
        delay(500);
        cleardevice();
        plname[5] = '\0';
        outtextxy(200,300,plname);
        goto f;
    }

    ch = getch();
    if(isalnum(ch) == 0) printf("error");

name_process:
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';

//   sdfprintf(info,"\t\t\tPlayers List\n");
  fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));

char lvl[100];

     //call score to display score
    fprintf(info,"Level:%d\n",level);//call level to display level
    fprintf(info,"Time Elapsed:%d\n",tim);


   fclose(info);
   }
   cleardevice();
}

void high_score()
{

    cleardevice();
    PlaySoundA(TEXT("high_hopes.wav"),NULL,SND_ASYNC);
    FILE *info;
    char plname[20],nplname[20],cha,c;

    int i,j,px;
    info=fopen("new_record.txt","r");


    fscanf(info,"%d ",&points);
    char player_name[100];
    char date[100];
    char level_data[100];
    char time_data[100];
fgets(player_name,80,info);
fgets(date,80,info);
fgets(level_data,80,info);
fgets(time_data,80,info);


     fclose(info);
setcolor(CYAN);
     char arr[1000];
    outtextxy(150,230,player_name);
    sprintf(arr,"  HIGH SCORE: %d ",points);
    outtextxy(150,200,arr);
    outtextxy(150,260,date);
    outtextxy(150,290,level_data);
    outtextxy(150,320,time_data);
    setcolor(RED);
    outtextxy(300,380," Start Menu >> Press B !!!");
    char ch = getch();
    if(ch == 'b' || ch == 'B') main_menu();
    if(ch!= 'b' && ch!='B') high_score();


}


