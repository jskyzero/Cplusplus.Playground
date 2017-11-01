// 
// main.c
// snake
//
// Created by jskyzero on 15-12-06
// Copyright(c) 2015 Sun Yat-sen University. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include <conio.h>

#define snake_max_length 20
#define snake_head 'H'
#define snake_body 'X'
#define blank_cell ' '
#define snake_food '$'
#define wall_cell '*'

void snakeMove(int,int);
void put_money(void);
void output(void);
void gameover(void);

char WhereGoNext(void);
int life(int,int);
char map[12][13]=
	{"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*    **    *",
	"*          *",
	"************"};
	
int snakeX[snake_max_length]={5,4,3,2,1};
int snakeY[snake_max_length]={1,1,1,1,1};
int snakeLength = 5;
int GameOver = 0;
int food_x,food_y;
int ch;


int main(){
	system("mode con: cols=50 lines=13"); 
	srand((unsigned)time(NULL));
	put_money();
	output();                       //输出字符矩阵 
	
	while(GameOver != 1) {			//WHILE not 游戏结束 DO
		
		Sleep(100);
		if(kbhit() != 0) {
		scanf("%c",&ch);            //ch＝等待输入 
		if('\n'==ch)continue;
		}
		else ch = WhereGoNext();
		switch(ch) {                //CASE ch DO 
		case 'w':
		case 'W':snakeMove(-1,0);   // ‘W’:上前进一步，break 
				  break;
		case 'a':
		case 'A':snakeMove(0,-1);   //‘A’:左前进一步，break 
				  break;
		case 's':
		case 'S':snakeMove(1,0);   //‘S’:下前进一步，break
				  break;
		case 'd':
		case 'D':snakeMove(0,1);    //‘D’:右前进一步，break
				  break;
		}
		output();   // 输出字符矩阵
	}
	gameover();    //输出 Game Over!!! 
	return 0;
}


void snakeMove(int y,int x){
	if((wall_cell==map[snakeY[0]+y][snakeX[0]+x])||(snake_body==map[snakeY[0]+y][snakeX[0]+x]))	{
	GameOver = 1;
	return; } // Snake | Head on Wall & BodySnake 
	
	if(snake_food==map[snakeY[0]+y][snakeX[0]+x]){
	snakeLength++;
	put_money();}//Snake | Head on Food 
	else map[snakeY[snakeLength-1]][snakeX[snakeLength-1]]=blank_cell;
	
	int i;
	for(i = snakeLength-1;i >= 1;i--) {
		snakeY[i]=snakeY[i-1];
		snakeX[i]=snakeX[i-1];
	}
	snakeY[0]+=y;
	snakeX[0]+=x;
	
	map[snakeY[0]][snakeX[0]]=snake_head;
	
	for(i = 1;i < snakeLength;i++) {
		map[snakeY[i]][snakeX[i]]=snake_body;
	}
	
}
void put_money(void){
	
	while(1) {
		food_x=rand()%10;
		food_y=rand()%10;
		char ch = map[food_y][food_x];
		if(blank_cell==ch)break;
	}
	map[food_y][food_x]=snake_food;
	
}
void output(void){
	int i;
	for(i = 0;i < 12;i++)
	printf("%s\n",map[i]);
}
void gameover(void){
	system("cls");	
	printf("GAMEOVER\n");
}

char WhereGoNext() {          //计算距离得到最小的移动方向 
	int n[5],n_min,i;
	n[0] = abs(food_y-snakeY[0])+abs(food_x-snakeX[0]);
	n[1] = abs(food_y-snakeY[0]+1)+abs(food_x-snakeX[0]);//w
	n[2] = abs(food_y-snakeY[0])+abs(food_x-snakeX[0]+1);//a
	n[3] = abs(food_y-snakeY[0]-1)+abs(food_x-snakeX[0]);//s
	n[4] = abs(food_y-snakeY[0])+abs(food_x-snakeX[0]-1);//d
	n_min = n[1];
	for(i=2;i<5;i++)
	if(n_min>n[i])n_min=n[i];
	if(n_min==n[1]&&life(-1,0))return'w';
	if(n_min==n[2]&&life(0,-1))return'a';
	if(n_min==n[3]&&life(1,0))return's';
	if(n_min==n[4]&&life(0,1))return'd';
	return 'w';
}
int life(int y,int x){        //辅助判断该次移动会不会炸 
	if((wall_cell==map[snakeY[0]+y][snakeX[0]+x])||(snake_body==map[snakeY[0]+y][snakeX[0]+x]))return 0;
	else return 1;
	
}
