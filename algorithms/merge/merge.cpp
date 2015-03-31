#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge_sort_iter(
    vector<int>::iterator v_s, vector<int>::iterator v_e,
    vector<int>::iterator t_s, vector<int>::iterator t_e)
{
    size_t n = distance(v_s, v_e);
    if (n < 20) {
        auto v_s_copy = v_s;
        for (size_t i = 1; i < n; ++i) {
            int minimum = *v_s;
            auto minimum_i = v_s;
            for (auto it = v_s+1; it != v_e; ++it) {
                if (*it < minimum) {
                    minimum = *it;
                    minimum_i = it;
                }
            }
            swap(*v_s, *minimum_i);
            ++v_s;
        }
        while (v_s_copy != v_e) {
            *t_s = *v_s_copy;
            ++t_s;
            ++v_s_copy;
        }

        return;
    }

    vector<int>::iterator v_m = v_s + n / 2;
    vector<int>::iterator t_m = t_s + n / 2;
    merge_sort_iter(t_s, t_m, v_s, v_m);
    merge_sort_iter(t_m, t_e, v_m, v_e);

    vector<int>::iterator v_m_e = v_m;
    while (v_s != v_m_e && v_m != v_e) {
        if (*v_s < *v_m) {
            *t_s = *v_s;
            ++v_s;
        } else {
            *t_s = *v_m;
            ++v_m;
        }
        ++t_s;
    }
    while (v_s != v_m_e) {
        *t_s = *v_s;
        ++v_s;
        ++t_s;
    }
    while (v_m != v_e) {
        *t_s = *v_m;
        ++v_m;
        ++t_s;
    }
}
void merge_sort(vector<int>& values) {
    vector<int> temporary = values;
//    vector<int> temporary(values.size());
//    merge_sort_iter(values.begin(), values.end(), temporary.begin(), temporary.end());
    merge_sort_iter(temporary.begin(), temporary.end(), values.begin(), values.end());
}
int main() {
    int n;
    cin >> n;

    vector<int> values;
    for (int i = 0; i < n; ++i) {
        values.push_back(rand() % n);
    }

    vector<int> values2 = values;

    cerr << '?';
    merge_sort(values);
    cerr << '!';
    sort(values2.begin(), values2.end());
    cerr << '.';
    cerr << endl;
    if (values != values2) {
        cerr << "WRONG" << endl;
    }
    return 0;
    for (const auto& i : values)
        cout << i << ' ';
    cout << endl;
    for (const auto& i : values2)
        cout << i << ' ';
    cout << endl;


}
