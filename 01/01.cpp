#include <bits/stdc++.h>

using namespace std;

int sum(int array[3]) {
    float sum = 0.0;
    for (int i = 0; i < 3; ++i) {
        sum += array[i];
    }
    return sum;
}

int main() {
    ifstream inp; 
    inp.open("input.txt");
    
    // int total_incr = 0;
    // int prev_depth = -1;
    // string curr_depth;
    // while (getline(inp, curr_depth)) {
    //     int curr_depth_int = stoi(curr_depth);
    //     if (prev_depth != -1 and curr_depth_int > prev_depth) {
    //         total_incr += 1;
    //     } 
    //     prev_depth = curr_depth_int;
    // }
    // cout << total_incr << '\n';
    // return 0;

    int total_incr = 0;
    int prev_depth[3] = {-1, -1, -1};
    string curr_depth;
    while (getline(inp, curr_depth)) {
        int curr_depth_int = stoi(curr_depth);
        if (prev_depth[0] != -1) {
            float prev_res = sum(prev_depth);
            prev_depth[0] = prev_depth[1];
            prev_depth[1] = prev_depth[2];
            prev_depth[2] = curr_depth_int;
            float curr_res = sum(prev_depth);
            if (curr_res > prev_res) {
                total_incr += 1;
            }
        } else {
            prev_depth[0] = prev_depth[1];
            prev_depth[1] = prev_depth[2];
            prev_depth[2] = curr_depth_int;
        }
    }
    cout << total_incr << '\n';
    return 0;
}
