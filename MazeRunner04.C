#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int X[3],Y[3],x,y;                        // Track the positions of 3 trolls and the player
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
{"# X #####################################################################"} };   //Hardcoded maze
void Exit(){                                  //Function to execute the exit operation as in a regular game
   char c;
   int i,j;
   clrscr();
   printf("\n\n\n\n\n\n\n\n\n\n\n\t\t         Are u sure u want to quit ???");
   printf("\n\t\t  Press 0 for exit or any other key to continue: ");
   c=getch();
   if(c=='0')   exit(0);                       //Exit the game if user confirms
   else{                                       //Else display the maze as it was   
      clrscr();
      for(i=0;i<23;i++){
	for(j=0;j<73;j++){
	    printf("%c",maze[i][j]);
	}
	printf("\n");
      }
   }
}
void troll(){                                 //Function to change the positons of the troll
    int i,j,flag,k=0;
    while(k<3){                               //Make changes to all the trolls
	                                          //Check if the player is near to any troll
        if(maze[Y[k]-1][X[k]]=='@')    Y[k]=Y[k]-1;
        else if(maze[Y[k]+1][X[k]]=='@')    Y[k]=Y[k]+1;
        else if(maze[Y[k]][X[k]+1]=='@')    X[k]=X[k]+1;
        else if(maze[Y[k]][X[k]-1]=='@')    X[k]=X[k]-1;
        else{
	      flag=0;
	      while(flag==0){                        //Make a random troll movement
	        i=rand()%3;    i=i-1;
	        j=rand()%2;
	        if(j==1){   j=i;   i=0;   }
	        if(maze[Y[k]+i][X[k]+j]==' ') {  maze[Y[k]+i][X[k]+j]='*';  maze[Y[k]][X[k]]=' ';
                                       flag=1;  Y[k]=Y[k]+i;   X[k]=X[k]+j;   }
          }   
        }
        k++;
    }
}
void setup(){                       //Function to set the position of the player and trolls for the first time
    int i,j,k=0,flag=0;
    clrscr();
    while(flag==0){                          //Set the postion of the player in random
  	   y=rand()%23;
	   x=rand()%73;
	   if(maze[y][x]==' ') {  maze[y][x]='@';   flag=1;   }
    }
    while(k<3){                                          //Now trolls turn :P
        flag=0;
        while(flag==0){                         //Set the postion of the trolls in random
	        Y[k]=rand()%23;
	        X[k]=rand()%73;
	        if(maze[Y[k]][X[k]]==' ') {  maze[Y[k]][X[k]]='*';   flag=1;   }
        }
        k++;
    }
    for(i=0;i<23;i++){                   //Display the maze after fixing the position of player and trolls
	  for(j=0;j<73;j++){
	    printf("%c",maze[i][j]);
	  }
	  printf("\n");
    }
}
void game_loop(){                                    //Function to start the real game:)
    char ch;
    int i,j,flag=0,posx=x,posy=y;
    while(maze[y][x]!='X'&&(flag!=2)){               //To run the game till the player wins or loses
      flag=0;                                        //To check if the player has won or not
	                                              // flag=1  WIN,   flag=2  LOSE, flag=0 CONTINUE the game
	  while(flag==0){
	      ch=getch();                     //Take the users response for the player's move
	      posx=x;
	      posy=y;
	      if(ch=='a'){   posx--;}
	      else if(ch=='w'){   posy--;  }
	      else if(ch=='d'){   posx++;  }
	      else if(ch=='s'){   posy++;  }
	      else if(ch=='0'){   Exit(); }         //Call the exit function if the user wants to exit the game
	      else continue;                //Take the response again if the user didn't enter a valid input
	      if(posx>=0 && posx<73 && posy>=0 && posy<23){    //Check if the move was a valid one
		      if(maze[posy][posx]==' '){
			      maze[y][x]=' ';  y=posy;   x=posx;
			      flag=1;   maze[y][x]='@';  }
		      else if(maze[posy][posx]=='X')  { flag=1;  maze[y][x]=' '; x=posx;  y=posy; }
              else flag=2;
		      if(flag!=2){ 
                troll();             //Check if the troll has eaten the player :P
                if((x==X[0] &&y==Y[0])||(x==X[1] &&y==Y[1])||(x==X[2] &&y==Y[2]))   flag=2;
              }
          }
		}
      clrscr();                    //Clear the screen and display the updated maze
      for(i=0;i<23;i++){
	    for(j=0;j<73;j++){
	       printf("%c",maze[i][j]);
	    }
	    printf("\n");
      }
    }
    clrscr();                           //Clear the screen 
                                        //Display the message if the player lost or won
    if(flag==2)   printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  YOU LOSE");
    else  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  YOU WIN");
}
int main(){
   char c;
   clrscr();
   srand(time(0));              //Make random() function return new value each time it is called
   printf("\n\n\n\n\n\n\n\n\n\t\t     Are you ready for the MAZE RUN ???\n");
   printf("\n\t INSTRUCTIONS:");
   printf("\n\t     Your goal is to move the player @ to the finish point X.");
   printf("\n\t    But beware of wall #, striking to which you lose the game; and");
   printf("\n\t  also of the 3 hungry moving trolls which will eat up your player.");
   printf("\n\t           Moves: up=w  down=s  left=a  right=d  exit=0");
   printf("\n\n\t\t     Press any key to start the game !!!");
   c=getch();
   clrscr();
   if(c=='0') Exit();              //Exit the game if the player wants to
   setup();
   game_loop();
   getch();
   return 0;
}