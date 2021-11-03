#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void gotoxy(int x, int y);
double intro_game(char team_name);
void display_line(int rand);
void game_control(clock_t start, double* pst);


void gotoxy(int x, int y) {

    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

// 게임에 대한 설명, 제한시간
double intro_game(char team_name) {

    double game_time;

    printf("Tug War\n");
    printf("줄다리기 게임\n\n");
    printf("스페이스를 클릭하여 줄을 당기시오!\n\n");

    printf("이름을 입력하고 Enter>");

    scanf_s("%s", &team_name, 7);


    printf("\n");
    printf("줄다리기 게임의 제한 시간(s)을 입력하고 Enter>");

    scanf_s("%lf", &game_time);
    system("cls");

    gotoxy(1, 1);
    printf("제한시간:%5.1f 초", game_time);
    gotoxy(30, 1);
    printf("경과시간:%4.1F 초", 0.0);

    gotoxy(38, 6);

    printf("기준점");

    gotoxy(40, 7);

    printf("▼");

    gotoxy(40, 9);

    printf("▲");

    return game_time;
}


// 줄다리기 줄을 출력
void display_line(int rnd) {

    int i, line[21] = { 0 };

    line[10] = 1;
    line[4] = 2;
    line[16] = 2;

    gotoxy(1, 8);

    for(i = 0; i < 78; i++) {
        printf(" ");
    }

    gotoxy(rnd, 8);

    for (i = 0; i < 21; i++) {

        if (line[i] == 0) {
            printf("□");
        }

        else if (line[i] == 1) {
            printf("■");
        }

        else {
            printf("◆");
        }
    }
}


// 줄다리기 게임 진행 & 시간제한 구현
void game_control(clock_t start, double* pst) {

    clock_t end;

    end = clock();
    *pst = (double)((double)end - (double)start) / CLK_TCK;
    gotoxy(30, 1);
    printf("경과시간:%4.1f초", *pst);
}



int main(void) {
    char team_name="";
    double pst, game_time;
    clock_t start;

    srand((unsigned)time(NULL));
    game_time = intro_game(team_name);

    start = clock();
    pst = 0;

    gotoxy(1, 15);
    printf("게임을 종료합니다. \n");

    return 0;
}
