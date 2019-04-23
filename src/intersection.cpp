#include "intersection.h"

bool intersection(string a, string b)
{
    stringstream ss;
    if (a[0] == 'c' && b[0] == 'c') {
        size_t i = 7, j = 0;
        double ac[3], bc[3];
        while (i < a.length()) {
            while (a[i] != ')' && a[i] != ',' && a[i] != ' ') {
                ss << a[i];
                i++;
            }
            ss >> ac[j];
            j++;
            if (a[i] == ' ') {
                i++;
            } else {
                i += 2;
            }
            ss.clear();
        }
        i = 7;
        j = 0;
        while (i < b.length()) {
            while (b[i] != ')' && b[i] != ',' && b[i] != ' ') {
                ss << b[i];
                i++;
            }
            ss >> bc[j];
            j++;
            if (a[i] == ' ') {
                i++;
            } else {
                i += 2;
            }
            ss.clear();
        }
        double l
                = sqrt((bc[0] - ac[0]) * (bc[0] - ac[0])
                       + (bc[1] - ac[1]) * (bc[1] - ac[1]));
        if (l == 0 && abs(ac[2] - bc[2]) < numeric_limits<double>::epsilon()) {
            return false;
        }
        if (l < ac[2] + bc[2]
            && l - max(ac[2], bc[2]) + min(ac[2], bc[2]) >= 0) {
            return true;
        }
        return false;
    }
    if (a[0] == 't' && b[0] == 't') {
        size_t i = 10, j = 0;
        pair<double, double> ac[3], bc[3];
        while (j < 3) {
            while (a[i] != ',') {
                ss << a[i];
                i++;
            }
            ss >> ac[j].first >> ac[j].second;
            j++;
            i += 2;
            ss.clear();
        }
        i = 10;
        j = 0;
        while (j < 3) {
            while (b[i] != ',') {
                ss << b[i];
                i++;
            }
            ss >> bc[j].first >> bc[j].second;
            j++;
            i += 2;
            ss.clear();
        }
        for (size_t i = 0; i < 2; i++) {
            for (size_t j = i + 1; j < 3; j++) {
                for (size_t q = 0; q < 2; q++) {
                    for (size_t o = q + 1, f = 0; o < 3; o++, f = 0) {
                        double t, d;
                        t = (ac[j].first - ac[i].first)
                                        * (bc[o].second - ac[i].second)
                                - (ac[j].second - ac[i].second)
                                        * (bc[o].first - ac[i].first);
                        d = (ac[j].first - ac[i].first)
                                        * (bc[q].second - ac[i].second)
                                - (ac[j].second - ac[i].second)
                                        * (bc[q].first - ac[i].first);
                        if ((t < 0 && d > 0) || (t > 0 && d < 0)) {
                            f++;
                        }
                        t = (bc[o].first - bc[q].first)
                                        * (ac[j].second - bc[q].second)
                                - (bc[o].second - bc[q].second)
                                        * (ac[j].first - bc[q].first);
                        d = (bc[o].first - bc[q].first)
                                        * (ac[i].second - bc[q].second)
                                - (bc[o].second - bc[q].second)
                                        * (ac[i].first - bc[q].first);
                        if ((t < 0 && d > 0) || (t > 0 && d < 0)) {
                            f++;
                        }
                        if (f == 2) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    if (a[0] == 't') {
        string temp = a;
        a = b;
        b = temp;
    }
    size_t i = 7, j = 0;
    double ac[3];
    pair<double, double> bc[3];
    while (i < a.length()) {
        while (a[i] != ')' && a[i] != ',' && a[i] != ' ') {
            ss << a[i];
            i++;
        }
        ss >> ac[j];
        j++;
        if (a[i] == ' ') {
            i++;
        } else {
            i += 2;
        }
        ss.clear();
    }
    i = 10;
    j = 0;
    ss.clear();
    while (j < 3) {
        while (b[i] != ',') {
            ss << b[i];
            i++;
        }
        ss >> bc[j].first >> bc[j].second;
        j++;
        i += 2;
        ss.clear();
    }
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            double k = (bc[j].second - bc[i].second)
                    / (bc[j].first - bc[i].first),
                   b = (bc[i].second * bc[j].first - bc[i].first * bc[j].second)
                    / (bc[j].first - bc[i].first),
                   a = (1 + k * k),
                   bu = (-2 * ac[0] + 2 * k * b - 2 * ac[1] * k),
                   c = ac[0] * ac[0] + b * b - ac[1] * ac[1] - 2 * ac[1] * b
                    - ac[2] * ac[2],
                   d = bu * bu - 4 * a * c;
            if (d > 0) {
                double x1 = (-bu + sqrt(d)) / (2 * a),
                       x2 = (-bu - sqrt(d)) / (2 * a), y1 = k * x1 + b,
                       y2 = k * x2 + b;
                if (x1 >= min(bc[i].first, bc[j].first)
                    && x1 <= max(bc[i].first, bc[j].first)
                    && y1 >= min(bc[i].second, bc[j].second)
                    && y1 <= max(bc[i].second, bc[j].second)) {
                    return true;
                }
                if (x2 >= min(bc[i].first, bc[j].first)
                    && x2 <= max(bc[i].first, bc[j].first)
                    && y2 >= min(bc[i].second, bc[j].second)
                    && y2 <= max(bc[i].second, bc[j].second)) {
                    return true;
                }
            }
        }
    }
    return false;
}