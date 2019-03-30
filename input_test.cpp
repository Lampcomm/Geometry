#include "input_test.h"

int circle(string str)
{
    string cr = "circle";
    string temp;
    int cp = 0, a, cz = 0;
    size_t i = 0, j = 0;
    while (str[i] != '(' && i < str.size()) {
        temp.push_back(str[i]);
        i++;
        j++;
    }
    if (i == str.size())
        return 3;
    if (temp.size() != cr.size())
        return 3;
    else {
        i = 1;
        while (cr[i] == temp[i] && i < str.size() && i < temp.size())
            i++;
        if (i != cr.size())
            return 3;
    }
    j++;
    temp.clear();
    while (str[j] != ')' && j < str.size()) {
        temp.push_back(str[j]);
        j++;
    }
    if (j == str.size())
        return 3;
    if (temp.size() < 6)
        return 2;
    for (size_t i = 0; i < temp.size(); i++) {
        if (temp[i] == ' ')
            cp++;
        else if (temp[i] == ',') {
            cz++;
            j = i;
        } else {
            a = temp[i] - '0';
            if ((a < 0 || a > 9) && temp[i] != '.' && temp[i] != ',') {
                return 2;
            }
        }
    }
    if (cp < 2)
        return 2;
    if (cz < 1)
        return 2;
    string te;
    j += 2;
    while (j < temp.size()) {
        te.push_back(temp[j]);
        j++;
    }
    istringstream iss(te, istringstream::in);
    int t;
    iss >> t;
    if (t <= 0)
        return 2;
    return 1;
}

int triangle(string str)
{
    string tr = "triangle";
    string temp;
    size_t i = 0, j = 0;
    while (str[i] != '(' && i < str.size()) {
        temp.push_back(str[i]);
        i++;
        j++;
    }
    if (i == str.size())
        return 3;
    if (temp.size() != tr.size())
        return 3;
    else {
        for (size_t i = 1; str[i] != '('; i++) {
            if (str[i] != temp[i])
                return 3;
        }
    }
    j++;
    temp.clear();
    if (str[j] != '(')
        return 2;
    if (str[str.size() - 1] != ')')
        return 2;
    if (str[str.size() - 2] != ')')
        return 2;
    j++;
    while (str[j] != ')') {
        temp.push_back(str[j]);
        j++;
    }
    if (temp.size() < 18)
        return 2;
    int a;
    size_t cp = 0, cz = 0;
    for (size_t i = 0; i < temp.size(); i++) {
        if (temp[i] == ' ')
            cz++;
        else if (temp[i] == ',')
            cp++;
        else {
            a = temp[i] - '0';
            if ((a < 0 || a > 9) && temp[i] != '.' && temp[i] != ','
                && temp[i] != '-') {
                return 2;
            }
        }
    }
    set<pair<int, int>> se;
    pair<int, int> t;
    i = 10;
    temp.clear();
    stringstream ss;
    while (str[i] != ')') {
        while (str[i] != ',' && str[i] != ')') {
            temp.push_back(str[i]);
            i++;
        }
        ss << temp;
        ss >> t.first;
        ss >> t.second;
        se.insert(t);
        temp.clear();
        ss.clear();
        i++;
    }
    if (se.size() != 3)
        return 2;
    return 1;
}