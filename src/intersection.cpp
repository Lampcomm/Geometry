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
    for (int i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            double c = bc[i].first * bc[j].second - bc[j].first * bc[i].second,
                   a = bc[i].second - bc[j].second,
                   b = bc[j].first - bc[i].first;
            c += a * ac[0] + b * ac[1];
            if (c * c < ac[2] * ac[2] * (a * a + b * b)) {
                double d = ac[2] * ac[2] - c * c / (a * a + b * b);
                double mult = sqrt(d / (a * a + b * b));
                double ax, ay, bx, by;
                double x0 = -a * c / (a * a + b * b),
                       y0 = -b * c / (a * a + b * b);
                ax = x0 + b * mult;
                ay = y0 - a * mult;
                bx = x0 - b * mult;
                by = y0 + a * mult;
                if (ax >= min(bc[i].first, bc[j].first)
                    && ax <= max(bc[i].first, bc[j].first)
                    && ay >= min(bc[i].second, bc[j].second)
                    && ay <= max(bc[i].second, bc[j].second)) {
                    return true;
                } else if (
                        bx >= min(bc[i].first, bc[j].first)
                        && bx <= max(bc[i].first, bc[j].first)
                        && by >= min(bc[i].second, bc[j].second)
                        && by <= max(bc[i].second, bc[j].second)) {
                    return true;
                }
            }
        }
    }
    return false;
}