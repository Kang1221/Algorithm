#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int gcd(int x, int y){
    int X = max(x,y);
    int Y = min(x,y);
    int R = 0;
    while (X%Y!=0) {
        R = X%Y;
        X = Y;
        Y = R;
    }
    return Y;
}

int lcm(vector<int> a){
    int result = a[0];
    for(size_t i=1; i<a.size(); i++){
        int gcpA = gcd(result, a[i]);
        int lcm = result*a[i]/gcpA;
        result = lcm;
    }
    return result;
}

int getTotalX(vector<int> a, vector<int> b) {
    int A = lcm(a); 
    int B = b[0];
    for(size_t i=1; i<b.size(); i++){
        B = gcd(B, b[i]);
    }
    
    int result = 0;
    for(int i =A; i<=B; i+=A){
        if(B%i==0)
            result++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
