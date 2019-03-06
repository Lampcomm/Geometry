#include "Test.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
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
        } else {
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
        }
    }
    if (flgc) {
        cout << "\n\n\n";
        for (const auto& i : out)
            cout << i << endl;
        cout << "\n\n\n";
        for (auto& i : er)
            cout << i.first << i.second << "\n\n";
    } else {
        for (const auto& i : out)
            fout << i << endl;
        fout << "\n\n\n";
        for (auto& i : er)
            fout << i.first << i.second << "\n\n";
    }
    return 0;
}