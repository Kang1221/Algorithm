#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    map<string, int> index;
    for(int i=0; i<n;i++)
        index[friends[i]] = i;
    
    vector<vector<int>> g_table (n,vector<int>(n,0));
    vector<int> g_score(n,0);
    vector<int> g_total(n,0);
    
    for(string gift: gifts){
    
        string a,b;
        stringstream ss (gift);
        ss >> a >> b;
        
        g_table[index[a]][index[b]]++;
        g_score[index[a]]++;
        g_score[index[b]]--;
    }
    
    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(g_table[i][j]>g_table[j][i])
                g_total[i]++;
            else if(g_table[i][j] == g_table[j][i]){
                if(g_score[i]> g_score[j])
                    g_total[i]++;
            }
        }
    }
    
    int max_gift = g_total[0];
    for(int i=1; i<n; i++){
        if(max_gift<g_total[i])
            max_gift = g_total[i];
    }
    return max_gift;
    
}
