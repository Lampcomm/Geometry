#include "area_and_perimeter_calculation.h"
#include "input_test.h"
#include "intersection.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int flgc = 0;
    string temp;
    vector<string> inp;
    vector<string> out;
    vector<pair<string, string>> er;
    ifstream finp;
    ofstream fout;
    if (argc > 1) {
        if (argc == 2) {
            finp.open(argv[1]);
            if (!finp.is_open()) {
                cout << "Failed to open input file" << endl;
                return -1;
            }
            cout << "Enter the path to the output file or enter 0 to output to "
                    "the console ";
            getline(cin, temp, '\n');
            if (temp.size() == 1 && temp[0] == '0')
                flgc = 1;
            else
                fout.open(argv[2]);
        } else {
            finp.open(argv[1]);
            fout.open(argv[2]);
            if (!finp.is_open()) {
                cout << "Failed to open input file" << endl;
                return -1;
            }
        }
        while (!finp.eof()) {
            getline(finp, temp, '\n');
            inp.push_back(temp);
        }
    } else {
        cout << "Enter the figures in the WKT - format (To exit, enter 0)"
             << endl;
        flgc = 1;
        while (1) {
            getline(cin, temp, '\n');
            if (temp.size() == 1 && temp[0] == '0')
                break;
            else {
                inp.push_back(temp);
            }
        }
    }
    pair<string, string> ans;
    for (const auto& i : inp) {
        if (i[0] == 'c') {
            if (circle(i) == 2) {
                ans.first = i;
                ans.second = "\n\tError: invalid input format";
                er.push_back(ans);
            } else if (circle(i) == 3) {
                ans.first = i;
                ans.second = "\n\n\tError: unknown shape '";
                size_t is = 0;
                temp.clear();
                while (i[is] != '(' && i[is] != ')' && is < i.size()) {
                    temp.push_back(i[is]);
                    is++;
                }
                temp.insert(temp.size(), "'");
                ans.second.insert(ans.second.size(), temp);
                er.push_back(ans);
            } else if (circle(i) == 1)
                out.push_back(i);
        } else if (i[0] == 't') {
            if (triangle(i) == 2) {
                ans.first = i;
                ans.second = "\n\tError: invalid input format";
                er.push_back(ans);
            } else if (triangle(i) == 3) {
                ans.first = i;
                ans.second = "\n\tError: unknown shape '";
                size_t is = 0;
                temp.clear();
                while (i[is] != '(' && i[is] != ')' && is < i.size()) {
                    temp.push_back(i[is]);
                    is++;
                }
                temp.insert(temp.size(), "'");
                ans.second.insert(ans.second.size(), temp);
                er.push_back(ans);
            } else if (triangle(i) == 1)
                out.push_back(i);
        } else {
            ans.first = i;
            ans.second = "\n\tError: unknown shape '";
            size_t is = 0;
            temp.clear();
            while (i[is] != '(' && i[is] != ')' && is < i.size()) {
                temp.push_back(i[is]);
                is++;
            }
            temp.insert(temp.size(), "'");
            ans.second.insert(ans.second.size(), temp);
            er.push_back(ans);
        }
    }
    if (flgc) {
        cout << fixed;
        cout << "\n\n\n";
        for (size_t i; i < out.size(); i++) {
            cout << out[i] << endl;
            cout << setprecision(3) << "\t perimeter = " << perimeter(out[i])
                 << endl;
            cout << setprecision(3) << "\t area = " << area(out[i]) << endl;
            cout << "\t intersects:" << endl;
            for (size_t j = 0; j < out.size(); j++) {
                if (i == j)
                    continue;
                if (intersection(out[i], out[j])) {
                    cout << "\t    " << j + 1 << ". " << out[j] << endl;
                }
            }
            cout << "\n\n";
        }
        cout << "\n\n\n";
        for (auto& i : er)
            cout << i.first << i.second << "\n\n";
    } else {
        for (size_t i = 0; i < out.size(); i++) {
            fout << fixed;
            fout << out[i] << endl;
            fout << setprecision(3) << "\t perimeter = " << perimeter(out[i])
                 << endl;
            fout << setprecision(3) << "\t area = " << area(out[i]) << endl;
            fout << "\t intersects:" << endl;
            for (size_t j = 0; j < out.size(); j++) {
                if (i == j)
                    continue;
                if (intersection(out[i], out[j])) {
                    fout << "\t    " << j + 1 << ". " << out[j] << endl;
                }
            }
            fout << "\n\n";
        }
        fout << "\n\n\n";
        for (auto& i : er)
            fout << i.first << i.second << "\n\n";
    }
    return 0;
}