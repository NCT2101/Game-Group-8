#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include<mmsystem.h>
#include <fstream>
#include <iostream>
#include "VNG.h"

//using namespace std;

void InputKey()
{
    int InputKey;
    int i=0;
    while(InputKey!=27)
    {
        InputKey=getch();
        switch (InputKey)
        {
        case 27: /* escape = abort */
            break;
        default:
            //cleardevice();
            setbkcolor(8);
            printf("%d ",InputKey);
            break;
        }
    }
}
void minigame1()
{
    FILE *f;
    FILE *fd;
    fd=fopen("Dapan.txt","r");
    int *a;
    a=(int*)malloc(7*sizeof(int));
    for(int i=0;i<7;i++)
    {
        fscanf(fd,"%d",&a[i]);
    }
    f=fopen("Cauhoi.txt","r");
    char s[7][20];
    StartConversation("Resources/nam.jpg","Resources/day2-4.1.jpg","","Hãy vượt qua thử thách để đuổi lũ côn trùng đi!!!");
        int i;
        int n;
        printf("                 Tinh nhanh\n");
        for (int i=0; i<7; i++)
			{
			    fscanf(f, "%s", s+i);
			}
        for(int i=0;i<7;i++)
        {
            printf("Cau hoi %d: %s\n",i+1,(s+i));
            printf("Dap an dung la:");
            scanf("%d",&n);
            if(n==a[i])
            {
                printf("Ban da dung!!!\n");
            }
            else{
                printf("Dap an cua ban da sai, hay tinh lai.\n");
                i--;
            }
        }
        fclose(f);
        fclose(fd);
        free(a);
}
void Introduce()
{
    SaveGame("GameData.txt",0);
    //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
}

int main()
{
    InitEverythings("FIND THE TRUTH");

    int menuSelect;
    int gameData=0;

    do
    {
        menuSelect=Menu();
        switch(menuSelect)
        {
        case 1:
            gameData=LoadGame("GameData.txt");
            break;
        case 2:
            NewGame("GameData.txt");
            break;
        case 3:
            system("cls");
            printf("\n\tThoát game");
            return 1;
        default:
            break;
        }
    }while(menuSelect==-1)

    switch(gameData)
    {
    case 0:
        Introduce();
        break;
    case 1:
        break;
    default:
        gameData=0;
        NewGame("GameData.txt");
        system("cls");
        printf("\n\n\tMục lưu game bị lỗi, vui lòng khởi động lại trò chơi.");
        break;
    }
    //StartConversation("Resources/Character/cjpg.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    //StartConversation("","Resources/Menu.jpg","","What !!!");
    //InputKey();
    //SaveData("GameData.txt",2000);
    //printf("%d",LoadData("GameData.txt"));
    //Flicker("Resources/Menu.jpg",20,30,RED);
    //Menu("Resources/Menu.jpg");
    //Shake("Resources/Menu.jpg",1);
    //HardFlicker("Resources/Menu.jpg",1,RED);
    //StartQuestion("","Resources/Menu.jpg","","What !!!",2);
    //StartConversation("Resources/sex.jpg","Resources/cha.jpg","Mia","Có con cặc ý Có coặc ý Có con Có con cặc ý Có con cặc ý");
    getch();
    closegraph();

    return 0;
}


