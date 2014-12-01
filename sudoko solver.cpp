#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
using std::cin;

const int R = 9,C = 9;
int dd;
int g[R][C] = {0};
bool v[R][C],row[R][C] = {0},col[R][C]={0};

void print_arr(){
    for(int r = 0; r < R;r++){
        for(int c = 0;c < C;c++){
            printf("%d",g[r][c]);
        }
        printf("\n");
    }printf("\n");
}
bool chk_sqr(int r,int c,int n){
    for(int i = 0;i<3;i++)
        for(int j=0;j<3;j++)
            if(g[r+i][c+j]==n)return true;
    return false;
}
void rec(int d){
    if(d==81){
        print_arr();
        exit(0);
    }
    int r = d/9;
    int c = d%9;
    if(!v[r][c]){
        for(int k = 1; k <= 9;k++){
            if(!row[r][k-1] && !col[c][k-1] && !chk_sqr(r-r%3,c-c%3,k)){
                g[r][c]=k;
                row[r][k-1]=col[c][k-1]=true;
                rec(d+1);
                g[r][c]=0;
                row[r][k-1]=col[c][k-1]=false;
            }
        }
    }
    else{
        rec(d+1);
    }
}
int main(){
    for(int r = 0; r < R;r++){
        char in;
        for(int c = 0; c < C;c++){
            cin >> in;
            if(isdigit(in)){
                g[r][c]=(int)(in-'0');
                v[r][c]=true;
                row[r][g[r][c]-1]=true;
                col[c][g[r][c]-1]=true;
            }
            else
                g[r][c] = 0;
        }
    }
    rec(0);
    return 0;
}
