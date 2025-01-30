#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int n;
string a, b;
map <string, vector <string> > m;
map <string, string> up;
map <string, bool> seen;
int vis = -1;

void find_ancestor(string x, string compare, int count){
    if(up[x].size() <= 0) return;
    if(up[x] == compare){
        vis = count;
        return;
    } 
    find_ancestor(up[x], compare, count+1);
}

void print_direct_ancestor(int vis, string a, string b){
    if(vis == 1) cout << a << " is the mother of " << b << endl;
    else if(vis == 2) cout << a << " is the grand-mother of " << b << endl;
    else{
        string str = "";
        while(vis > 2){
            str += "great-";
            vis--;
        }
        cout << a << " is the " << str << "grand-mother of " << b << endl;
    }
}

void find_aunt_ancestor(string x, string compare, int count){
    if(count == 0) find_aunt_ancestor(up[x], compare, count+1);
    else{
        for(int k = 0; k < m[x].size(); k++){
            if(m[x][k] == compare){
                vis = count;
                return;
            }
        }
        if(up[x].size() > 0) find_aunt_ancestor(up[x], compare, count + 1);
    }
}

void print_aunt_ancestor(int vis, string a, string b){
    if(vis == 1) cout << a << " is the aunt of " << b << endl;
    else{
        string str = "";
        while(vis > 1){
            str += "great-";
            vis--;
        }
        cout << a << " is the " << str << "aunt of " << b << endl;
    }
}

void find_them(string x, string compare){
    seen[x] = true;
    if(x == compare){
        vis = 345;
        return;
    }
    for(int k = 0; k < m[x].size(); k++){
        if(seen[m[x][k]]) continue;
        find_them(m[x][k], compare);
    }
}

void find_cousin(string x, string compare, int count){
    seen[x] = true;
    if(count == 0) find_cousin(up[x], compare, count+1);
    for(int k = 0; k < m[x].size(); k++){
        for(int j = 0; j < m[m[x][k]].size(); j++){
            find_them(m[m[x][k]][j], compare);
            if(vis != -1) return;
        }
    }
    if(up[x].size() > 0) find_cousin(up[x], compare, count+1);
}

int main()
{
    freopen("family.in", "r", stdin); freopen("family.out", "w", stdout);
    fast;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        m[x].push_back(y);
        up[y] = x;
    }
    //check siblings
    if(up[a] == up[b]){
        cout << "SIBLINGS" << endl;
        return 0;
    }
    //A is a direct descendant of B or vis versa
    find_ancestor(a, b, 1);
    if(vis != -1){
        print_direct_ancestor(vis, b, a);
        return 0;
    } 
    if(vis == -1) find_ancestor(b, a, 1);
    if(vis != -1){
        print_direct_ancestor(vis, a, b);
        return 0;
    }
    //A is a child of an ancestor of B or vis versa... vis is still equal to -1
    find_aunt_ancestor(up[a], b, 0);
    if(vis != -1){
        print_aunt_ancestor(vis, b, a);
        return 0;
    }
    if(vis == -1) find_aunt_ancestor(up[b], a, 0); 
    if(vis != -1){
        print_aunt_ancestor(vis, a, b);
        return 0;
    }
    //Check if A is a cousin of B or vis versa... vis is still equal to -1
    find_cousin(up[a], b, 0);
    if(vis != -1){
        cout << "COUSINS" << endl;
        return 0;
    }
    if(vis == -1) find_cousin(up[b], a, 0); 
    if(vis != -1){
        cout << "COUSINS" << endl;
        return 0;
    }
    cout << "NOT RELATED" << endl;
}
