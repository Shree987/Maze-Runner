#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int x,y;
int X,Y;
char maze[24][74]={
{"#########################################################################"},
{"#   #               #               #           #                   #   #"},
{"#   #   #########   #   #####   #########   #####   #####   #####   #   #"},
{"#               #       #   #           #           #   #   #       #   #"},
{"#########   #   #########   #########   #####   #   #   #   #########   #"},
{"#       #   #               #           #   #   #   #   #           #   #"},
{"#   #   #############   #   #   #########   #####   #   #########   #   #"},
{"#   #               #   #   #       #           #           #       #   #"},
{"#   #############   #####   #####   #   #####   #########   #   #####   #"},
{"#           #       #   #       #   #       #           #   #           #"},
{"#   #####   #####   #   #####   #   #########   #   #   #   #############"},
{"#       #       #   #   #       #       #       #   #   #       #       #"},
{"#############   #   #   #   #########   #   #####   #   #####   #####   #"},
{"#           #   #           #       #   #       #   #       #           #"},
{"#   #####   #   #########   #####   #   #####   #####   #############   #"},
{"#   #       #           #           #       #   #   #               #   #"},
{"#   #   #########   #   #####   #########   #   #   #############   #   #"},
{"#   #           #   #   #   #   #           #               #   #       #"},
{"#   #########   #   #   #   #####   #########   #########   #   #########"},
{"#   #       #   #   #           #           #   #       #               #"},
{"#   #   #####   #####   #####   #########   #####   #   #########   #   #"},
{"#   #                   #           #               #               #   #"},
{"# X #####################################################################"} };
void Exit(){
   char c;
   int i,j;
   clrscr();
   printf("\n\n\n\n\n\n\n\n\n\n\n\t\t         Are u sure u want to quit ???");
   printf("\n\t\t  Press 0 for exit or any other key to continue: ");
   c=getch();
   if(c=='0')   exit(0);
   else{
      clrscr();
      for(i=0;i<23;i++){
	for(j=0;j<73;j++){
	    printf("%c",maze[i][j]);
	}
	printf("\n");
      }
   }
}
void troll(){
    int i,j,flag;
    if(maze[Y-1][X]=='@')    Y=Y-1;
    else if(maze[Y+1][X]=='@')    Y=Y+1;
    else if(maze[Y][X+1]=='@')    X=X+1;
    else if(maze[Y][X-1]=='@')    X=X-1;
    else{
	flag=0;
	while(flag==0){
	    i=rand()%3;    i=i-1;
	    j=rand()%2;
	    if(j==1){   j=i;   i=0;   }
	    if(maze[Y+i][X+j]==' ') {  maze[Y+i][X+j]='*';  maze[Y][X]=' ';  flag=1;  Y=Y+i;   X=X+j;   }
    }   }

}
void setup(){
    int i,j,flag=0;
    clrscr();
    while(flag==0){
	   y=rand()%23;
	   x=rand()%73;
	   if(maze[y][x]==' ') {  maze[y][x]='@';   flag=1;   }
    }
    flag=0;
    while(flag==0){
	   Y=rand()%23;
	   X=rand()%73;
	   if(maze[Y][X]==' ') {  maze[Y][X]='*';   flag=1;   }
    }
    for(i=0;i<23;i++){
	  for(j=0;j<73;j++){
	    printf("%c",maze[i][j]);
	  }
	  printf("\n");
    }
}
void game_loop(){
    char ch;
    int i,j,flag=0,posx=x,posy=y;
    while(maze[y][x]!='X'&&(flag!=2)){
      flag=0;
	  while(flag==0){
	      ch=getch();
	      posx=x;
	      posy=y;
	      if(ch=='a'){   posx--;}
	      else if(ch=='w'){   posy--;  }
	      else if(ch=='d'){   posx++;  }
	      else if(ch=='s'){   posy++;  }
	      else if(ch=='0'){   Exit(); }
	      else continue;
	      if(posx>=0 && posx<73 && posy>=0 && posy<23){
		      if(maze[posy][posx]==' '){
			      maze[y][x]=' ';  y=posy;   x=posx;
			      flag=1;   maze[y][x]='@';  }
		      else if(maze[posy][posx]=='X')  { flag=1;  maze[y][x]=' '; x=posx;  y=posy; }
              else flag=2;
		      if(flag!=2){ 
                troll();
                if(x==X&&y==Y)   flag=2;
              }
          }
		}
      clrscr();
      for(i=0;i<23;i++){
	    for(j=0;j<73;j++){
	       printf("%c",maze[i][j]);
	    }
	    printf("\n");
      }
    }
    clrscr();
    if(flag==2)   printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  YOU LOSE");
    else  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  YOU WIN");
}
int main(){
   char c;
   clrscr();
   srand(time(0));
   printf("\n\n\n\n\n\n\n\n\n\t\t     Are you ready for the MAZE RUN ???");
   printf("\n\t     INSTRUCTIONS: up=w  down=s  left=a  right=d  exit=0");
   printf("\n\n\t\t     Press any key to start the game !!!");
   c=getch();
   clrscr();
   if(c=='0') Exit();
   setup();
   game_loop();
   getch();
   return 0;
}