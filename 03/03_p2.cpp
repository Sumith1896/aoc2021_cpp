#include <bits/stdc++.h>

using namespace std;

set<string> filter_set(set<string> orig_set, int idx, bool most) {
    int num_z = 0;
    int num_o = 0;
    for (auto itr = orig_set.begin(); itr != orig_set.end(); itr++) {
        string bitstring = *itr;
        if (bitstring[idx] == '0') {
            num_z += 1;
        } else {
            num_o += 1;
        }
    }
    
    char match;
    if (most) {
        if (num_o >= num_z) {
            match = '1';
        } else {
            match = '0';
        }
    } else {
        if (num_z <= num_o) {
            match = '0';
        } else {
            match = '1';
        }
    }

    set<string> res_set = {};
    for (auto itr = orig_set.begin(); itr != orig_set.end(); itr++) {
        string bitstring = *itr;
        if (bitstring[idx] == match) {
            res_set.insert(bitstring);
        }
    }
    return res_set;
}

int main() {
    ifstream inp; 
    inp.open("input.txt");

    string bitstring;
    set<string> all_strings = {};

    while (getline(inp, bitstring)) {
        all_strings.insert(bitstring);
    }

    set<string> oxy_set, co2_set;
    int curr_idx;

    oxy_set = all_strings;
    curr_idx = 0;
    while (oxy_set.size() != 1) {
        oxy_set = filter_set(oxy_set, curr_idx, true);
        curr_idx += 1;
    }
    co2_set = all_strings;
    curr_idx = 0;
    while (co2_set.size() != 1) {
        co2_set = filter_set(co2_set, curr_idx, false);
        curr_idx += 1;
    }

    cout << bitset<12>(*oxy_set.begin()).to_ulong() * bitset<12>(*co2_set.begin()).to_ulong() << endl;
    return 0;
}
