#include <iostream>
#include <sstream>
#include <string>

using namespace std;

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