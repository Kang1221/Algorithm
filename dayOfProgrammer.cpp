#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string dayOfProgrammer(int year) {
    if(year < 1917){ //Julian calendar
        if(year%4==0)
            return "12.09." + to_string(year);
        else
            return  "13.09." + to_string(year);
    }
    else if (year == 1918){ //Gergorian calendar occurred (Feb 32nd)
        return "26.09.1918"; 
    }
    else{ //Gergorian calendar
        if(year%400==0 || ( year%4==0 && year%100!=0))
            return "12.09." + to_string(year);
        else
            return "13.09." + to_string(year);
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
