#include<stdio.h>
#include<windows.h>  //Sleep和system函数
#include<string.h>  //memset 函数
#include<conio.h>  //检测键盘函数getch
#include<stdlib.h> //rand函数
int main(){
    int lose=0;
    int Fx;
    int move;
    int board[100]={0};             //设置棋盘，实现方法为长度为100的字符组
    memset(board,32,sizeof(board));  //初始化棋盘
    int place=55;
    int l=0; //贪吃蛇长度
    int body[100]={0};
    int lengthadd=0;
    int i1;    
    int ppl;
    ppl=rand()%100;
    for(;;){       
    system("cls"); 
    if(lose){                   //判断是否失败
        printf("you lose\n按R键重新开始,任意键退出");
        int r=_getch();
        if(r==114){
            lose=0;
            int board[100]={0};
            l=0;
        }
        else{
            break;
        }       
    }
    else if(lose==2){
        printf("y=You Win!\n按R键重新开始,任意键退出");
        int r=_getch();
        if(r==114){
            lose=0;
            int board[100]={0};
            l=0;
        }
        else{
            break;
        }
        
    }                                           
        for(int i=0;i<100;i++){                 //输出完整棋盘
        if(i%10==0){
            printf("\n%c  ",board[i]);
        }
        else{
            printf("%c  ",board[i]);
        }
        
    }
    printf("\nyour score:%d\n",l);
                                    //printf("%d",place);
    memset(board,32,sizeof(board));
    Sleep(500);
    if(_kbhit()){                   //检测键盘按下
            Fx=_getch();            
             switch (Fx)
            {
            case 119 : if(move==2){move=2;}else{move=8;};break;    //根据返回值给move赋值,并且不能反方向
            case 115 : if(move==8){move=8;}else{move=2;};break;
            case 97 : if(move==6){move=6;}else{move=4;};break;
            case 100 : if(move==4){move=4;}else{move=6;};break;
            default :break;
            }
                                    //printf("%d",Fx);
        }
    switch (move)
        {
        case 8:place -=10;break;   //通过字符的位置来表示蛇头位置
        case 2:place +=10;break;
        case 4:place -=1 ;break;
        case 6:place +=1 ;break;    
        default:
            break;
        }
        if(place<-1){                                   //实现越过边界时的穿越效果
            place += 100;
        }
        else if(place>100){                                 //每当位置到边界且方向为穿越边界时，位置移动到另一边
            place -=100;
        }
        else if((place+1) %10 ==0 &move==4){
            place += 10;
        }
        else if(place %10 ==0 &move==6){
            place -=10;
        }
        for(int i=1;i<l;i++){
            if(place==body[i-1]){
                lose=1;
            }
        }
        
        body[l]=place;
        for(int i=l;i>=0;i--){                  //将蛇身的位置对应到棋盘上
            board[body[i]]=79;      
        }
        for(int i=0;i<l;i++){                       //用另一个数组存储蛇身的位置
            body[i]=body[i+1];           
        }
        board[ppl]=111; //食物的ascii码                     //设置食物位置
        int pplg=0;
        if(place==ppl){
            l +=1;
            ppl=rand()%100;
            for(int i=0;i<l;i++){
                if(ppl==body[i]){
                    ppl=rand()%100;
                }
            }    
        }
        if(l>99){
            lose=2;
        }
        }
    }
    


