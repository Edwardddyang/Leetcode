#include <iostream>
#include <vector>
#include <string>
using namespace std;

// b[i] = a[i-1] + a[i] + a[i+1], treating out-of-bounds as 0.
vector<long long> neighborSum(const vector<long long>& a) {
    int size = a.size(); 
    if(size == 0)
        return {}; 
    if(size == 1)
        return {a[0]};
    vector<long long> answer(size, 0);
    
    for(int i = 1; i < size - 1; i++){
        answer[i] = a[i] + a[i - 1] + a[i + 1];
    }
    answer[0] = a[0] + a[1];
    answer[size - 1] = a[size - 2] + a[size - 1];
    return answer; 
}

// ---------------- test harness ----------------
string show(const vector<long long>& v) {
    string s = "[";
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0) s += ", ";
        s += to_string(v[i]);
    }
    return s + "]";
}

int passed = 0, failed = 0;

void check(const string& name, const vector<long long>& a, const vector<long long>& expected) {
    vector<long long> got = neighborSum(a);
    if (got == expected) {
        ++passed;
        cout << "[PASS] " << name << "\n";
    } else {
        ++failed;
        cout << "[FAIL] " << name << "\n"
             << "   input:    " << show(a) << "\n"
             << "   expected: " << show(expected) << "\n"
             << "   got:      " << show(got) << "\n";
    }
}

int main() {
    check("empty",            {},                 {});
    check("single element",   {5},                {5});
    check("two elements",     {1, 2},             {3, 3});
    check("three elements",   {1, 2, 3},          {3, 6, 5});
    check("basic",            {1, 2, 3, 4, 5},    {3, 6, 9, 12, 9});
    check("all zeros",        {0, 0, 0, 0},       {0, 0, 0, 0});
    check("all same",         {7, 7, 7, 7},       {14, 21, 21, 14});
    check("negatives",        {-1, -2, -3},       {-3, -6, -5});
    check("mixed signs",      {3, -3, 3, -3},     {0, 3, -3, 0});
    check("single negative",  {-9},               {-9});
    check("large values",     {2000000000, 2000000000, 2000000000},
                              {4000000000LL, 6000000000LL, 4000000000LL});
    check("spike in middle",  {0, 0, 10, 0, 0},   {0, 10, 10, 10, 0});

    cout << "\n" << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}