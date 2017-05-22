#include <iostream>
using namespace std;

#define INF 999
#define NINF -999

struct state {
    int xo[3][3];
    int x_i, o_i;
    int value;
    int human;
    int x_w, o_w;
};

void ini(state &s) {
    int i, j;
    for (i = 0; i<3; i++)
        for (j = 0; j<3; j++)
            s.xo[i][j] = 0;
}

void sup(state &s) {
    s.x_i = 0;
    s.o_i = 0;
    if ((s.xo[0][0] == 0 || s.xo[0][0] == 1) && (s.xo[0][1] == 0 || s.xo[0][1] == 1) && (s.xo[0][2] == 0 || s.xo[0][2] == 1))
        s.x_i++;
    if ((s.xo[1][0] == 0 || s.xo[1][0] == 1) && (s.xo[1][1] == 0 || s.xo[1][1] == 1) && (s.xo[1][2] == 0 || s.xo[1][2] == 1))
        s.x_i++;
    if ((s.xo[2][0] == 0 || s.xo[2][0] == 1) && (s.xo[2][1] == 0 || s.xo[2][1] == 1) && (s.xo[2][2] == 0 || s.xo[2][2] == 1))
        s.x_i++;
    if ((s.xo[0][0] == 0 || s.xo[0][0] == 1) && (s.xo[1][0] == 0 || s.xo[1][0] == 1) && (s.xo[2][0] == 0 || s.xo[2][0] == 1))
        s.x_i++;
    if ((s.xo[0][1] == 0 || s.xo[0][1] == 1) && (s.xo[1][1] == 0 || s.xo[1][1] == 1) && (s.xo[2][1] == 0 || s.xo[2][1] == 1))
        s.x_i++;
    if ((s.xo[0][2] == 0 || s.xo[0][2] == 1) && (s.xo[1][2] == 0 || s.xo[1][2] == 1) && (s.xo[2][2] == 0 || s.xo[2][2] == 1))
        s.x_i++;
    if ((s.xo[0][0] == 0 || s.xo[0][0] == 1) && (s.xo[1][1] == 0 || s.xo[1][1] == 1) && (s.xo[2][2] == 0 || s.xo[2][2] == 1))
        s.x_i++;
    if ((s.xo[0][2] == 0 || s.xo[0][2] == 1) && (s.xo[1][1] == 0 || s.xo[1][1] == 1) && (s.xo[2][0] == 0 || s.xo[2][0] == 1))
        s.x_i++;

    if ((s.xo[0][0] == 0 || s.xo[0][0] == -1) && (s.xo[0][1] == 0 || s.xo[0][1] == -1) && (s.xo[0][2] == 0 || s.xo[0][2] == -1))
        s.o_i++;
    if ((s.xo[1][0] == 0 || s.xo[1][0] == -1) && (s.xo[1][1] == 0 || s.xo[1][1] == -1) && (s.xo[1][2] == 0 || s.xo[1][2] == -1))
        s.o_i++;
    if ((s.xo[2][0] == 0 || s.xo[2][0] == -1) && (s.xo[2][1] == 0 || s.xo[2][1] == -1) && (s.xo[2][2] == 0 || s.xo[2][2] == -1))
        s.o_i++;
    if ((s.xo[0][0] == 0 || s.xo[0][0] == -1) && (s.xo[1][0] == 0 || s.xo[1][0] == -1) && (s.xo[2][0] == 0 || s.xo[2][0] == -1))
        s.o_i++;
    if ((s.xo[0][1] == 0 || s.xo[0][1] == -1) && (s.xo[1][1] == 0 || s.xo[1][1] == -1) && (s.xo[2][1] == 0 || s.xo[2][1] == -1))
        s.o_i++;
    if ((s.xo[0][2] == 0 || s.xo[0][2] == -1) && (s.xo[1][2] == 0 || s.xo[1][2] == -1) && (s.xo[2][2] == 0 || s.xo[2][2] == -1))
        s.o_i++;
    if ((s.xo[0][0] == 0 || s.xo[0][0] == -1) && (s.xo[1][1] == 0 || s.xo[1][1] == -1) && (s.xo[2][2] == 0 || s.xo[2][2] == -1))
        s.o_i++;
    if ((s.xo[0][2] == 0 || s.xo[0][2] == -1) && (s.xo[1][1] == 0 || s.xo[1][1] == -1) && (s.xo[2][0] == 0 || s.xo[2][0] == -1))
        s.o_i++;

    s.value = s.x_i - s.o_i;

    if ((s.xo[0][0] + s.xo[0][1] + s.xo[0][2] == 3) || (s.xo[1][0] + s.xo[1][1] + s.xo[1][2] == 3) || (s.xo[2][0] + s.xo[2][1] + s.xo[2][2] == 3) ||
        (s.xo[0][0] + s.xo[1][0] + s.xo[2][0] == 3) || (s.xo[0][1] + s.xo[1][1] + s.xo[2][1] == 3) || (s.xo[0][2] + s.xo[1][2] + s.xo[2][2] == 3) ||
        (s.xo[0][0] + s.xo[1][1] + s.xo[2][2] == 3) || (s.xo[0][2] + s.xo[1][1] + s.xo[2][0] == 3))
        s.value = INF;
    if ((s.xo[0][0] + s.xo[0][1] + s.xo[0][2] == -3) || (s.xo[1][0] + s.xo[1][1] + s.xo[1][2] == -3) || (s.xo[2][0] + s.xo[2][1] + s.xo[2][2] == -3) ||
        (s.xo[0][0] + s.xo[1][0] + s.xo[2][0] == -3) || (s.xo[0][1] + s.xo[1][1] + s.xo[2][1] == -3) || (s.xo[0][2] + s.xo[1][2] + s.xo[2][2] == -3) ||
        (s.xo[0][0] + s.xo[1][1] + s.xo[2][2] == -3) || (s.xo[0][2] + s.xo[1][1] + s.xo[2][0] == -3))
        s.value = NINF;
}

int waitfor(state &s) {
    int x, y;
    x = 0;
    y = 0;
    cin >> x >> y;
    x = x - 1;
    y = y - 1;
    if (x<0 || x>2 || y<0 || y>2) {
        printf("我们的棋盘是3x3的，您不能把棋子下到棋盘外面，请重新落子\n");
        printf("x=%d  y=%d (x,y)=%d\n", x, y, s.xo[x][y]);
        waitfor(s);
    }
    else if (s.xo[x][y] == 1 || s.xo[x][y] == -1) {
        printf("此处已有棋子，请重新落子\n");
        printf("x=%d  y=%d (x,y)=%d\n", x, y, s.xo[x][y]);
        waitfor(s);
    }
    else
        s.xo[x][y] = s.human;
    return 0;
}

int chooseorder(state &s) {
    int c;
    printf("选择由谁先下：\n1.人先落子\n2.电脑先落子\n");
    cin >> c;
    if (c == 1)	s.human = 1;
    else if (c == 2)	s.human = -1;
    else {
        printf("输入了不正确的值，请重新输入");
        chooseorder(s);
    }
    return 0;
}

int max1(state &s) {
    int i, j;
    int max = NINF;
    for (i = 0; i<3; i++) {
        for (j = 0; j<3; j++) {
            if (s.xo[i][j] == 0) {//该位置可下
                s.xo[i][j] = s.human;
                sup(s);
                if (s.value == NINF) {
                    s.xo[i][j] = 0;
                    return NINF;
                }
                if (s.value>max)
                    max = s.value;
                s.xo[i][j] = 0;
            }
            else
                continue;
        }
    }
    return max;
}

int min1(state &s) {
    int i, j;
    int min = INF;
    int best;
    for (i = 0; i<3; i++) {
        for (j = 0; j<3; j++) {
            if (s.xo[i][j] == 0) {//该位置可下
                s.xo[i][j] = -s.human;
                sup(s);
                s.value = max1(s);
                if (min >= s.value) {
                    min = s.value;
                    best = i * 10 + j;
                }
                s.xo[i][j] = 0;
            }
            else
                continue;
        }
    }
    s.xo[best / 10][best % 10] = -s.human;
    return 0;
}

int min2(state &s) {
    int i, j;
    int min = INF;
    for (i = 0; i<3; i++) {
        for (j = 0; j<3; j++) {
            if (s.xo[i][j] == 0) {//该位置可下
                s.xo[i][j] = s.human;
                sup(s);
                if (s.value == INF) {
                    s.xo[i][j] = 0;
                    return INF;
                }
                if (s.value<min)
                    min = s.value;
                s.xo[i][j] = 0;
            }
            else
                continue;
        }
    }
    return min;
}

int max2(state &s) {
    int i, j;
    int max = NINF;
    int best;
    for (i = 0; i<3; i++) {
        for (j = 0; j<3; j++) {
            if (s.xo[i][j] == 0) {//该位置可下
                s.xo[i][j] = -s.human;
                sup(s);
                s.value = min2(s);
                if (max <= s.value) {
                    max = s.value;
                    best = i * 10 + j;
                }
                s.xo[i][j] = 0;
            }
            else
                continue;
        }
    }
    s.xo[best / 10][best % 10] = -s.human;
    return 0;
}

void printstate(state s) {
    int i, j;
    for (i = 0; i<3; i++) {
        for (j = 0; j<3; j++) {
            if (s.xo[i][j] == 1)
                printf("x  ");
            else if (s.xo[i][j] == -1)
                printf("o  ");
            else
                printf("*  ");
        }
        printf("\n");
    }
}

int tic_tac_toe(state &s) {
    printf("initial state\n");
    ini(s);
    sup(s);
    printstate(s);
    if (s.human == 1) {
        while (s.x_i != 0 && s.o_i != 0) {
            printf("\nyour turn\n");
            waitfor(s);
            sup(s);
            printstate(s);
            if (s.value == INF) {
                printf("EXECELLENT!\nYOU WIN\n");
                return 0;
            }
            if (s.x_i == 0 && s.o_i == 0) {
                printf("DRAW\n");
                return 0;
            }
            printf("\ncomputer turn\n");
            min1(s);
            sup(s);
            printstate(s);
            if (s.value == NINF) {
                printf("YOU LOSE\n");
                return 0;
            }
            if (s.x_i == 0 && s.o_i == 0) {
                printf("DRAW\n");
                return 0;
            }
        }
    }
    else if (s.human == -1) {
        while (s.x_i != 0 && s.o_i != 0) {
            printf("\ncomputer turn\n");
            max2(s);
            sup(s);
            printstate(s);
            if (s.value == INF) {
                printf("YOU LOSE\n");
                return 0;
            }
            if (s.x_i == 0 && s.o_i == 0) {
                printf("DRAW\n");
                return 0;
            }
            printf("\nyour turn\n");
            if (waitfor(s) == -1)
                return -1;
            sup(s);
            printstate(s);
            if (s.value == NINF) {
                printf("EXECELLENT!\nYOU WIN\n");
                return 0;
            }
            if (s.x_i == 0 && s.o_i == 0) {
                printf("DRAW\n");
                return 0;
            }
        }
    }
    return 0;
}

int main()
{
    state s;
    chooseorder(s);
    if (tic_tac_toe(s) == -1)
        return -1;
    return 0;
}
