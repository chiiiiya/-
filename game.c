#include<stdio.h>
#include<windows.h>  //Sleep��system����
#include<string.h>  //memset ����
#include<conio.h>  //�����̺���getch
#include<stdlib.h> //rand����
int main(){
    int lose=0;
    int Fx;
    int move;
    int board[100]={0};             //�������̣�ʵ�ַ���Ϊ����Ϊ100���ַ���
    memset(board,32,sizeof(board));  //��ʼ������
    int place=55;
    int l=0; //̰���߳���
    int body[100]={0};
    int lengthadd=0;
    int i1;    
    int ppl;
    ppl=rand()%100;
    for(;;){       
    system("cls"); 
    if(lose){                   //�ж��Ƿ�ʧ��
        printf("you lose\n��R�����¿�ʼ,������˳�");
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
        printf("y=You Win!\n��R�����¿�ʼ,������˳�");
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
        for(int i=0;i<100;i++){                 //�����������
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
    if(_kbhit()){                   //�����̰���
            Fx=_getch();            
             switch (Fx)
            {
            case 119 : if(move==2){move=2;}else{move=8;};break;    //���ݷ���ֵ��move��ֵ,���Ҳ��ܷ�����
            case 115 : if(move==8){move=8;}else{move=2;};break;
            case 97 : if(move==6){move=6;}else{move=4;};break;
            case 100 : if(move==4){move=4;}else{move=6;};break;
            default :break;
            }
                                    //printf("%d",Fx);
        }
    switch (move)
        {
        case 8:place -=10;break;   //ͨ���ַ���λ������ʾ��ͷλ��
        case 2:place +=10;break;
        case 4:place -=1 ;break;
        case 6:place +=1 ;break;    
        default:
            break;
        }
        if(place<-1){                                   //ʵ��Խ���߽�ʱ�Ĵ�ԽЧ��
            place += 100;
        }
        else if(place>100){                                 //ÿ��λ�õ��߽��ҷ���Ϊ��Խ�߽�ʱ��λ���ƶ�����һ��
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
        for(int i=l;i>=0;i--){                  //�������λ�ö�Ӧ��������
            board[body[i]]=79;      
        }
        for(int i=0;i<l;i++){                       //����һ������洢�����λ��
            body[i]=body[i+1];           
        }
        board[ppl]=111; //ʳ���ascii��                     //����ʳ��λ��
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
    


