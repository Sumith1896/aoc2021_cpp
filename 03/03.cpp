#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp; 
    inp.open("input.txt");

    string bitstring;
    getline(inp, bitstring);
    int len = bitstring.size();
    int z_cnt[len] = {0};
    int o_cnt[len] = {0};

    for (int i = 0; i < len; i++) {
        if (bitstring[i] == '0') {
            z_cnt[i] += 1;
        } else {
            o_cnt[i] += 1;
        }
    }
    while (getline(inp, bitstring)) {
        for (int i = 0; i < len; i++) {
            if (bitstring[i] == '0') {
                z_cnt[i] += 1;
            } else {
                o_cnt[i] += 1;
            }
        }
    }

    string gamma = "";
    string alpha = "";
    for (int i = 0; i < len; i++) {
        if (z_cnt[i] < o_cnt[i]) {
            gamma += '1';
            alpha += '0';
        } else {
            gamma += '0';
            alpha += '1';
        }
    }

    cout << bitset<12>(gamma).to_ulong() * bitset<12>(alpha).to_ulong() << endl;
    return 0;
}
