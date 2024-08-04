#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>
#include<time.h>
#include<windows.h>
#define LL  218
#define RL 191
#define  IN_T 193
#define  V  179
#define  LBL  192
#define  T 194
#define LT 195
#define H 196
#define  PS 197
#define RBL  217
#define RT 180


 int random(int num,int val,int row,int col);
  void SetPosition(int X, int Y)
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={X, Y};

SetConsoleCursorPosition(Screen, Position);
}

void create_box(int dim){
 int x=(80-((dim*5)+dim+1))/2;
  int y =(25-(2*dim+1))/2;
         SetPosition(x,y++);
         printf("%c",218);
         for(int box=0;box<dim;box++){
         for(int h=0;h<5;h++){
	     printf("%c",H);         
         }
         printf("%c",T);
         if(box==dim-1){
	         printf("%c%c",'\b',RL);
	         printf("\n");
         }
         }
         
        
         
         for(int extend_box=0;extend_box<dim;extend_box+=1){
         		SetPosition(x,y++);
         		 for(int v=0;v<dim+1;v++){
         		
	        printf("%c",V);     
		  for(int v_place=0;v_place<5;v_place+=1){
	                   printf(" ");		 
		 }
         }
         SetPosition(x,y++);
         printf("%c",LT);
       
         		
         for(int rt=0;rt<dim;rt++){
	     for(int h=0;h<5;h++){
	     printf("%c",H);         
         }         
         printf("%c",PS);
         }
         printf("%c%c",'\b',RT);
        printf("\n");
         }
         SetPosition(x,--y);
         printf("%c",LBL);
         int mov;
         for(mov=0;mov<dim-1;mov++){
         		SetPosition(x+(5*mov)+mov+6,y);
	               printf("%c",IN_T);         
         }
         SetPosition(x+5*dim+mov+1,y);
         printf("%c",RBL);
         
}
//random game_num mulitples generator

void create_numbers(int number,int dim,int game_num,int random_num,int max[dim][dim]){
	 int x=(80-((dim*5)+dim+1))/2;
   int y =(25-(2*dim+1))/2;
  
for(int row=0;row<dim;row++){
	for(int col=0;col<dim;col++){ 
			SetPosition(x+(2*col)+(4*col)+1,y+(2*row)+1);
			max[row][col]=random(1000,random_num,row,col);
		printf("%d",max[row][col] );
		 }
		 
	}	
	
}

int main()
{
	
	clock_t start_t,end_t;
	start_t=clock();
	int dim=9;
	int points=0;
	int game_num;
scanf("%d",&game_num);
create_box(dim);
int max[dim][dim];
 end_t=clock();
 int random_num=(end_t-start_t);
create_numbers(1000,dim,game_num,random_num,max);
printf("\n\nVIEW THE TABLE AND PRINT THE GIVEN MULTIPLES:");
printf("\n\n0 to quit the game\n");
SetPosition(0,25);
printf("Points  : ");
while(1){
		int x=0;
int y=27;
		int val=0;
		SetPosition(x,y++);
		printf("%c",LL);
		for(int i=0;i<8;i++){
		printf("%c",H);
		}
		printf("%c",RL);
		SetPosition(x,y++);
		printf("%c",V);
		
		for(int i=0;i<8;i++){
		printf(" ");
		}
		printf("%c",V);
		
		SetPosition(x,y++);
		printf("%c",LBL);
		for(int i=0;i<8;i++){
		printf("%c",H);
		}
		printf("%c",RBL);
			
	SetPosition(x+2,y-2);
				
				int flag=0;
	scanf("%d",&val);
	SetPosition(9,25);
	for(int row=0;row<dim;row++){
	for(int col=0;col<dim;col++){ 
			if(val==max[row][col])
			flag=1;
	}
	}
	if(val%game_num==0){
		if(flag==0){
	SetPosition(9,25);
	
	points--;		
	
	printf("%d",points);
		}else{
	points++;
printf("%d",points);
		}
		}
	else if(val==0){
			printf("\n\n\n\n\n");
			break;}
	else{
			printf("\n\n\n\n\n");
	break;
	}
	
}

     
    return 0;
}

int random(int num,int random_num,int row,int col){
	int x=sqrt(rand()%10);
	 return ((row+col)*x+(random_num*x)*x)%1000;
	
	
}
