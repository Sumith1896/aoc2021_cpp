#include <bits/stdc++.h>

using namespace std;

class bingo_board {
    public:
        int board[5][5];
        bool filled[5][5];
        bool solved;

        bingo_board(vector<vector<int>> vec_board) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    board[i][j] = (vec_board.at(i)).at(j);
                    filled[i][j] = false;
                }
            }
            solved = false;
            return;
        }

        void add_num(int num) {
            int curr_i, curr_j;
            bool found_num = false;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (this->board[i][j] == num) {
                        this->filled[i][j] = true;
                        curr_i = i;
                        curr_j = j;
                        found_num = true;
                    }
                }
            }
            if (!found_num)
                return;
            bool i_solved = true;
            for (int j = 0; j < 5; j++) {
                i_solved = i_solved && this->filled[curr_i][j];
            }
            bool j_solved = true;
            for (int i = 0; i < 5; i++) {
                j_solved = j_solved && this->filled[i][curr_j];
            }
            if (i_solved || j_solved) {
                this->solved = true;
            }
            return;
        }

        int find_score(void) {
            int curr_score = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (!this->filled[i][j]) {
                        curr_score += this->board[i][j];
                    }
                }
            }
            return curr_score;
        }
};

vector<int> extract_num(string raw_num, char delim) {
    vector<int> result;
    stringstream raw_stream(raw_num);
    while(raw_stream.good()) {
        string substr;
        getline(raw_stream, substr, delim);
        if (substr.length() != 0)
            result.push_back(stoi(substr));
    }
    return result;
}

int main() {
    ifstream inp; 
    inp.open("input.txt");

    string bitstring;
    getline(inp, bitstring);
    vector<int> bingo_num = extract_num(bitstring, ',');
    getline(inp, bitstring);

    vector<vector<int>> temp_board;
    vector<bingo_board> all_boards;
    while (getline(inp, bitstring)) {
        if (bitstring.compare("") == 0) {
            all_boards.push_back(bingo_board(temp_board));
            temp_board = {};
        } else {
            temp_board.push_back(extract_num(bitstring, ' '));
        }
    }
    all_boards.push_back(bingo_board(temp_board));

    // for (auto it = bingo_num.begin(); it < bingo_num.end(); it++) {
    //     for (auto bt = all_boards.begin(); bt < all_boards.end(); bt++) {
    //         (*bt).add_num(*it);
    //         if ((*bt).solved) {
    //             cout << (*bt).find_score() * (*it) << endl;
    //             return 0;
    //         }
    //     }
    // }

    int max_num = 0;
    int best_score = 0;
    for (auto bt = all_boards.begin(); bt < all_boards.end(); bt++) {
        int temp_max_num = 0;
        for (auto it = bingo_num.begin(); it < bingo_num.end(); it++) {
            (*bt).add_num(*it);
            temp_max_num += 1;
            if ((*bt).solved) {
                if (temp_max_num > max_num) {
                    max_num = temp_max_num;
                    best_score = (*bt).find_score() * (*it);
                }
                break;
            }
        }
    }

    cout << best_score << endl;
    return 0;
}
