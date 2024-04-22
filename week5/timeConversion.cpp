#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s.substr(0,2));
    //PM
    if(s[8]=='P'){
        if(hour==12){
            return s.substr(0,8);
        }
        string newhour = to_string(hour + 12);
        return newhour + s.substr(2,6);
    }
    //AM
    if(hour!=12)
        return s.substr(0,8);
    else
        return "00" + s.substr(2,6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
