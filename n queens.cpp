/*  Author: William G.
    Date : 11/10/14
    Pupose: To solve N queens problem
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int dr[] = {-1,-1};
int dc[] = {-1,1};
int N,R,C,cnt;
string g[100];
vector< pair<int,int> >queens;

void print_arr(){
    for(int r = 0; r < R;r++){
        for(int c = 0; c < C;c++){
            printf("%c",g[r][c]);
        }
        printf("\n");
    }printf("\n");
}
bool axis_check(pair<int,int>lft, pair<int,int>rht){
    return lft.first == rht.first || lft.second == rht.second;
}
bool check(int r,int c, int d){
    r+=dr[d];c+=dc[d];
    while(r >= 0 && c >=0 && r < R && c < C){
        if(g[r][c] == '1')return true;
        r+=dr[d];
        c+=dc[d];
    }
    return false;
}
bool diag_check(pair<int,int>lft){
    int r = lft.first,c = lft.second;
    for(int d =0; d < 2;d++)
        if(check(r,c,d))return true;
    return false;
}
void rec(int n){
    if(n == N){
        cnt++;
        return;
    }
    int r = n;
    for(int c = 0; c < C;c++){
        bool pos = true;
        for(int i = 0; i < queens.size();i++){
            if(axis_check(queens[i],make_pair(r,c)) || diag_check(make_pair(r,c))){
                pos = false;
                break;
            }
        }
        if(pos){
            queens.push_back(make_pair(r,c));
            g[r][c] = '1';
            rec(n+1);
            g[r][c] = '0';
            queens.pop_back();
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&N,&R,&C);
    for(int r = 0; r < R;r++)
        for(int c = 0; c < C;c++)
            g[r]+="0";
    rec(0);
    printf("There are %d solutions for a board of size %d by %d with %d queens.\n",cnt,R,C,N);
    return 0;
}
