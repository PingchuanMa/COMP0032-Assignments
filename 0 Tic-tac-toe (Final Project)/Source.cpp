#include <iostream>
using namespace std;

class Tic_tac_toe {

private:
    int board[3][3];
    int x_value, o_value;
    int value;
    int turn;

public:
    static const int MAX_VALUE = 999;
    static const int MIN_VALUE = -999;
    static const int X = 1;
    static const int O = -1;

    Tic_tac_toe() {
        memset(board, 0, sizeof(board));
        x_value = 0;
        o_value = 0;
        value = 0;
        choose_order();
        start_game();
    }

    void compute_value() {
        x_value = 0;
        o_value = 0;
        if ((board[0][0] != O) && (board[0][1] != O) && (board[0][2] != O))
            x_value++;
        if ((board[1][0] != O) && (board[1][1] != O) && (board[1][2] != O))
            x_value++;
        if ((board[2][0] != O) && (board[2][1] != O) && (board[2][2] != O))
            x_value++;
        if ((board[0][0] != O) && (board[1][0] != O) && (board[2][0] != O))
            x_value++;
        if ((board[0][1] != O) && (board[1][1] != O) && (board[2][1] != O))
            x_value++;
        if ((board[0][2] != O) && (board[1][2] != O) && (board[2][2] != O))
            x_value++;
        if ((board[0][0] != O) && (board[1][1] != O) && (board[2][2] != O))
            x_value++;
        if ((board[0][2] != O) && (board[1][1] != O) && (board[2][0] != O))
            x_value++;

        if ((board[0][0] != X) && (board[0][1] != X) && (board[0][2] != X))
            o_value++;
        if ((board[1][0] != X) && (board[1][1] != X) && (board[1][2] != X))
            o_value++;
        if ((board[2][0] != X) && (board[2][1] != X) && (board[2][2] != X))
            o_value++;
        if ((board[0][0] != X) && (board[1][0] != X) && (board[2][0] != X))
            o_value++;
        if ((board[0][1] != X) && (board[1][1] != X) && (board[2][1] != X))
            o_value++;
        if ((board[0][2] != X) && (board[1][2] != X) && (board[2][2] != X))
            o_value++;
        if ((board[0][0] != X) && (board[1][1] != X) && (board[2][2] != X))
            o_value++;
        if ((board[0][2] != X) && (board[1][1] != X) && (board[2][0] != X))
            o_value++;

        value = x_value - o_value;

        if ((board[0][0] + board[0][1] + board[0][2] == 3) ||
            (board[1][0] + board[1][1] + board[1][2] == 3) ||
            (board[2][0] + board[2][1] + board[2][2] == 3) ||
            (board[0][0] + board[1][0] + board[2][0] == 3) ||
            (board[0][1] + board[1][1] + board[2][1] == 3) ||
            (board[0][2] + board[1][2] + board[2][2] == 3) ||
            (board[0][0] + board[1][1] + board[2][2] == 3) ||
            (board[0][2] + board[1][1] + board[2][0] == 3)) {
            value = MAX_VALUE;
        }

        if ((board[0][0] + board[0][1] + board[0][2] == -3) ||
            (board[1][0] + board[1][1] + board[1][2] == -3) ||
            (board[2][0] + board[2][1] + board[2][2] == -3) ||
            (board[0][0] + board[1][0] + board[2][0] == -3) ||
            (board[0][1] + board[1][1] + board[2][1] == -3) ||
            (board[0][2] + board[1][2] + board[2][2] == -3) ||
            (board[0][0] + board[1][1] + board[2][2] == -3) ||
            (board[0][2] + board[1][1] + board[2][0] == -3)) {
            value = MIN_VALUE;
        }
    }

    void input() {
        int x, y;
        cin >> x >> y;
        if (x < 1 || x > 3 || y < 1 || y > 3) {
            cout << "咱井字棋棋盘小，您朝里边儿下。" << endl;
            input();
        }
        else if (board[x - 1][y - 1] == 1 || board[x - 1][y - 1] == -1) {
            cout << "这儿有子儿了，您别处请吧。" << endl;
            input();
        }
        else { board[x - 1][y - 1] = turn; }
    }

    void choose_order() {
        int turn_;
        cout << "按1: 您先请。" << endl;
        cout << "按2: 我就不客气了。" << endl;
        cin >> turn_;
        if (turn_ == 1) { turn = 1; }
        else if (turn_ == 2) { turn = -1; }
        else {
            cout << "您这是让谁下呢？" << endl;
            choose_order();
        }
    }


    int max2() {
        int i, j;
        int max = MIN_VALUE;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) {//该位置可下
                    board[i][j] = turn;
                    compute_value();
                    if (value == MIN_VALUE) {
                        board[i][j] = 0;
                        return MIN_VALUE;
                    }
                    if (value > max)
                        max = value;
                    board[i][j] = 0;
                }
            }
        }
        return max;
    }

    int min1() {
        int i, j;
        int min = MAX_VALUE;
        int best;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) {//该位置可下
                    board[i][j] = -turn;
                    compute_value();
                    value = max2();
                    if (min >= value) {
                        min = value;
                        best = i * 10 + j;
                    }
                    board[i][j] = 0;
                }
            }
        }
        board[best / 10][best % 10] = -turn;
        return 0;
    }

    int min2() {
        int i, j;
        int min = MAX_VALUE;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) {//该位置可下
                    board[i][j] = turn;
                    compute_value();
                    if (value == MAX_VALUE) {
                        board[i][j] = 0;
                        return MAX_VALUE;
                    }
                    if (value < min)
                        min = value;
                    board[i][j] = 0;
                }
            }
        }
        return min;
    }

    int max1() {
        int max = MIN_VALUE;
        int best = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {//该位置可下
                    board[i][j] = -turn;
                    compute_value();
                    value = min2();
                    if (max <= value) {
                        max = value;
                        best = i * 10 + j;
                    }
                    board[i][j] = 0;
                }
            }
        }
        board[best / 10][best % 10] = -turn;
        return 0;
    }

    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1)
                    cout << "X ";
                else if (board[i][j] == -1)
                    cout << "O ";
                else
                    cout << "* ";
            }
            cout << endl;
        }
    }

    int start_game() {
        printf("您棋盘长这样：\n");
        compute_value();
        print();
        if (turn == 1) {
            while (x_value != 0 && o_value != 0) {
                cout << endl << "轮您下子儿：" << endl;
                input();
                compute_value();
                print();
                if (value == MAX_VALUE) {
                    cout << "哇心态爆炸！" << endl;
                    return 0;
                }
                if (x_value == 0 && o_value == 0) {
                    cout << "平局嘿！" << endl;
                    return 0;
                }
                cout << endl << "我的嘞：" << endl;
                min1();
                compute_value();
                print();
                if (value == MIN_VALUE) {
                    cout << endl << "输了吧略略略！" << endl;
                    return 0;
                }
                if (x_value == 0 && o_value == 0) {
                    cout << "平局嘿！" << endl;
                    return 0;
                }
            }
        }
        else if (turn == -1) {
            while (x_value != 0 && o_value != 0) {
                cout << endl << "我的嘞：" << endl;
                max1();
                compute_value();
                print();
                if (value == MAX_VALUE) {
                    cout << endl << "输了吧略略略！" << endl;
                    return 0;
                }
                if (x_value == 0 && o_value == 0) {
                    cout << "平局嘿！" << endl;
                    return 0;
                }
                cout << endl << "轮您下子儿：" << endl;
                compute_value();
                print();
                if (value == MIN_VALUE) {
                    cout << "哇心态爆炸！" << endl;
                    return 0;
                }
                if (x_value == 0 && o_value == 0) {
                    cout << "平局嘿！" << endl;
                    return 0;
                }
            }
        }
        return 0;
    }
};


int main()
{
    Tic_tac_toe game;
    return 0;
}
