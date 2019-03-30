#include "area_and_perimeter_calculation.h"
#define PI 3.1415926

double perimeter(string s)
{
    pair<int, int> t;
    pair<int, int> a[4];
    double ans = 0;
    string temp;
    stringstream ss;
    if (s[0] == 'c') {
        size_t i = s.size() - 2;
        while (s[i] != ' ') {
            temp.insert(0, 1, s[i]);
            i--;
        }
        ss << temp;
        ss >> ans;
        ans *= 2 * PI;
    } else {
        size_t i = 10;
        size_t j = 0;
        while (s[i] != ')') {
            while (s[i] != ',' && s[i] != ')') {
                temp.push_back(s[i]);
                i++;
            }
            ss << temp;
            ss >> t.first;
            ss >> t.second;
            ss.clear();
            a[j] = t;
            temp.clear();
            j++;
            i++;
        }
        for (int i = 1; i < 4; i++) {
            ans
                    += sqrt((a[i].first - a[i - 1].first)
                                    * (a[i].first - a[i - 1].first)
                            + (a[i].second - a[i - 1].second)
                                    * (a[i].second - a[i - 1].second));
        }
    }
    return ans;
}

double area(string s)
{
    pair<int, int> t;
    pair<int, int> a[4];
    string temp;
    stringstream ss;
    double ans = 1, p = 0, b[3];
    if (s[0] == 'c') {
        size_t i = s.size() - 2;
        while (s[i] != ' ') {
            temp.insert(0, 1, s[i]);
            i--;
        }
        ss << temp;
        ss >> ans;
        ans *= ans * PI;
    } else {
        size_t i = 10;
        size_t j = 0;
        while (s[i] != ')') {
            while (s[i] != ',' && s[i] != ')') {
                temp.push_back(s[i]);
                i++;
            }
            ss << temp;
            ss >> t.first;
            ss >> t.second;
            a[j] = t;
            j++;
            i++;
            ss.clear();
            temp.clear();
        }
        for (int i = 1, j = 0; i < 4; i++, j++) {
            b[j]
                    = sqrt((a[i].first - a[i - 1].first)
                                   * (a[i].first - a[i - 1].first)
                           + (a[i].second - a[i - 1].second)
                                   * (a[i].second - a[i - 1].second));
            p += b[j];
        }
        p /= 2;
        for (int i = 0; i < 3; i++) {
            ans *= (p - b[i]);
        }
        ans = sqrt(ans * p);
    }
    return ans;
}