#include <allegro.h>
#include <cstdlib>
#include <time.h>
#include<iostream>
int x=210,y=140,xx=0,yy=140,xxx=430,yyy=140;
int dir;//
int score1=0,score2=0;
void newGame()
{   clear_keybuf();
    readkey();
    x=210,y=140,xx=0,yy=140,xxx=430,yyy=140;

}
void showScore()
{
    textout_ex( screen, font, "Player 2 Wins!", 160, 120, makecol( 255, 0, 0), makecol( 0, 255, 0));
}
void showWin()
{
  if(x<=5)
    textout_ex( screen, font, "Player 2 Wins!", 160, 120, makecol( 255, 0, 0), makecol( 0, 255, 0));
 if(x>=385)
    textout_ex( screen, font, "Player 1 Wins!", 160, 120, makecol( 255, 0, 0), makecol( 0, 255, 0));
dir = rand() % 4 + 1;
}
void play1()
{
    if(key[KEY_W])yy--;
    if(key[KEY_S])yy++;
}
void play2()
{
    if(key[KEY_UP])yyy--;
    if(key[KEY_DOWN])yyy++;
}
void ball()
{
     if(dir==1)
        if(y<=5)dir=2;
        else if(x>5&&y>5){x--,y--;}
        else if(x==5&&y>=yy-50&&y<=yy+60)  dir=rand()%2+3;//odbij paletka
        else
        {showWin();
        newGame();}
                   //odbicie od gornej krawedzi

     if(dir==2)
        if(x>5&&y<225){x--,y++;}
        else dir=1;
     if(dir==3)
        if(y<=5)dir=4;
        else if(y>5&&x<385){x++,y--;}
        else if(x>=385&&y>=yyy-50&&y<=yyy+60) dir=rand()%2+1;
        else
        {showWin();
        newGame();}
     if(dir==4)
        if(y<225&&x<385){x++,y++;}
        else dir=3;

}

int main(){


    time_t secs;
    time(&secs);
    srand( (unsigned int)secs);

dir = rand() % 4 + 1;
    BITMAP *buffer, *sball, *player1,*player2;
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 440, 280, 0, 0);
    buffer = create_bitmap( 440, 280);
    sball=create_bitmap(50,50);
    player1 = create_bitmap( 10, 60);
    player2 = create_bitmap( 10, 60);
    clear_to_color( sball, makecol( 255, 0, 0 ) );
    clear_to_color( player1, makecol( 0, 255, 0 ) );
    clear_to_color( player2, makecol( 0, 255, 0 ) );
    while( !key[KEY_ESC]){
clear_to_color( buffer, makecol( 0, 0, 255 ) );
ball();
play1();
play2();
//rest(1);
blit(sball,buffer,0,0,x,y,sball->w,sball->h);
blit(player1,buffer,0,0,xx,yy,player1->w,player1->h);
blit(player2,buffer,0,0,xxx,yyy,player2->w,player2->h);
blit(buffer,screen,0,0,0,0,440,280);
std::cout<<"dir"<<dir<<std::endl;
    }

    return 0;

}
END_OF_MAIN();
