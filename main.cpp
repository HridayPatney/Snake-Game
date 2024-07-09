#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;
int tailx[100];
int taily[100];
int length_tail;
int numOfFruits;

void setup(){
    numOfFruits=0;
    length_tail=0;
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=width/2;
    fruitx=rand()%width;
    fruity =rand()%width;
    score=0;



}
void draw(){
    system("cls");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width+2;j++){
            if(j==0){
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruity && j==fruitx){
                cout<<"F";
            }
            else{
                bool p=false;
                for(int k=0;k<length_tail;k++){
                    
                    if(tailx[k]==j && taily[k]==i){
                        cout<<"o";
                        p=true;
                    }
                }
                if(!p){
                cout<<" ";
                }
            }
            if(j==width-1){
                cout<<"#";
            }
        }
       cout<<endl;
    }
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"SCORE:"<<score<<endl;
   


}
void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's': 
                dir=DOWN;
                break;
            case 'x':
                gameOver=true;
                break;



        }
    }

}
void logic(){
    int prevX=tailx[0];
    int prevY=taily[0];
    int pprevx,pprevy;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<length_tail;i++){
        pprevx=tailx[i];
        pprevy=taily[i];
        tailx[i]=prevX;
        taily[i]=prevY;
        prevX=pprevx;
        prevY=pprevy;
    }

    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;

    

    }
    for(int i=0;i<length_tail;i++){
        if(tailx[i]==x && taily[i]==y){
            gameOver=true;
        }
    }
    if(x>width || x<0 || y>height || y<0){
        gameOver=true;
    }
    if(x==fruitx && y==fruity){
        score+=10;
        length_tail++;
        fruitx=rand()%width;
        fruity =rand()%width;

    }


}
void playGame(){
    
    while(!gameOver){
        draw();
        input();
        logic();
        Sleep(100-5*numOfFruits);
    }

}
int main(){
    setup();
    
    while(true){
        if(gameOver==false){
            playGame();
        }
        else{
            system("cls");
            cout<<"GAME OVER"<<endl<<"PRESS ANY KEY TO PLAY AGAIN";
            if(_kbhit()){
                setup();
            }

            
        }
    }

    return 0;
}