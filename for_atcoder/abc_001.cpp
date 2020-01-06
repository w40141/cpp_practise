#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sg(int &h1, int &w1, int &h2, int &w2,
        const vector<string> &board){
    int H = board.size();
    int W = board.at(0).size();
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board.at(i).at(j) == 's') {
                h1 = i;
                w1 = j;
            } else if (board.at(i).at(j) == 'g') {
                h2 = i;
                w2 = j;
            }
        }
    }
}

bool is_valid_move(const std::vector<std::string> &board,
                   vector<vector<bool> > &checked, int h, int w) {

    int H = board.size();
    int W = board.at(0).size();
    std::cout << h << ", " << w << std::endl;

    if (h < 0 || H <= h || w < 0 || W <= w) return false;
    if (board.at(h).at(w) == '#') return false;
    if (checked.at(h).at(w)) return false;

    return true;
}

bool reachable(const vector<string> &board, int gorl_h, int gorl_w,
               vector<vector<bool> > &checked, int h, int w) {
    int H = board.size();
    int W = board.at(0).size();

    if (h == gorl_h && w == gorl_w) return true;

    checked.at(h).at(w) = true;
    bool result = false;

    if (is_valid_move(board, checked, h, w-1)
            && reachable(board, gorl_h, gorl_w, checked, h, w-1)) {
        result = true;
    }
    if (is_valid_move(board, checked, h+1, w)
            && reachable(board, gorl_h, gorl_w, checked, h+1, w)) {
        result = true;
    }
    if (is_valid_move(board, checked, h, w+1)
            && reachable(board, gorl_h, gorl_w, checked, h, w+1)) {
        result = true;
    }
    if (is_valid_move(board, checked, h-1, w)
            && reachable(board, gorl_h, gorl_w, checked, h-1, w)) {
        result = true;
    }

    return result;
}

int main(int argc, char *argv[])
{
    int H, W;
    std::cin >> H >> W;
    vector<string> board(H);
    for (int i = 0; i < H; ++i) std::cin >> board.at(i);
    int start_h = 0, start_w = 0, gorl_h = 0, gorl_w = 0;
    sg(start_h, start_w, gorl_h, gorl_w, board);

    vector<vector<bool> > checked(H, vector<bool>(W, false));
    if (reachable(board, gorl_h, gorl_w,
                  checked, start_h, start_w)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
