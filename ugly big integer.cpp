#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;

const int MAXN = (int)1e5+2,POS = 1,NEG = -1;
string s1,s2,s3 = "0";

class bignum{
    public:
        char c[MAXN];
        int end,signbit;
    public:
        bignum(string&s){
             if(s[0] == '-'){
                signbit = -1;
                for(int i = s.size()-1, j = 0;i>=1;i--)
                    c[j++] = s[i];
                end = s.size()-2;
            }
            else{
                signbit = 1;
                for(int i = s.size()-1, j = 0;i>=0;i--)
                    c[j++] = s[i];
                end = s.size()-1;
            }
        }
        void add(bignum a,bignum b);
        void sub(bignum a,bignum b);
        void print(){
            if(signbit==NEG)printf("-");
            for(int i = end;i>=0;i--)
                printf("%c",c[i]);
            printf("\n");
        }
    bool operator < (const bignum&num)const{
       if(end < num.end)
        return true;
       else if(end > num.end)
        return false;
       else{
           int e = min(end,num.end);
           for(int i = 0;i <= e;i++){
                if(c[i]==num.c[i])continue;
                return c[i] < num.c[i];
           }
       }
    }
    bool operator >  (const bignum&num)const{return !(*this < num);}
    bool operator >= (const bignum&num)const{return !(*this < num);}
    bool operator <= (const bignum&num)const{return !(num < *this);}
    bool operator != (const bignum&num)const{return (*this< num || num < *this);}
    bool operator == (const bignum&num)const{return !(*this!=num);}
};
void bignum::add(bignum a,bignum b){
    // simply increasing magnitude
    int e = max(a.end,b.end),carry = 0;
    for(int i = 0, sum = 0; i <= e+1;i++){
        sum = carry;
        carry = 0;
        if(isdigit(a.c[i]))
            sum+=a.c[i]-'0';
        if(isdigit(b.c[i]))
            sum+=b.c[i]-'0';
        if(!isdigit(a.c[i]) && !isdigit(b.c[i])&& sum==0)
            break;
        if(sum >= 10){
            sum%=10;
            carry = 1;
        }
        c[i] = sum+'0';
        end=i;
    }
}
void bignum::sub(bignum a,bignum b){
    int e = max(a.end,b.end), burrow = 0;
    for(int i = 0;i <= e;i++){
        int d = a.c[i]-'0' - burrow;
        burrow = 0;
        if(isdigit(b.c[i])){
            if(d-(b.c[i]-'0') < 0){
                d+=10;
                burrow = 1;
                d-=b.c[i]-'0';
            }else
                d-=b.c[i]-'0';
        }
        if(!isdigit(b.c[i])){
            if(d < 0){
                d+=10;
                burrow = 1;
            }
        }
        c[i] = d+'0';
        end = i;
    }
    while(c[end] == '0' && end !=0)
        end--;
}
int main(){
    //freopen("input.txt","r",stdin);
    cin >> s1 >> s2;
    bignum a(s1),b(s2),c(s3);
    if(a.signbit == POS && b.signbit == POS){
        c.add(a,b);
        c.print();
    }
    else if(a.signbit == NEG && b.signbit == NEG){
        c.add(a,b);
        c.signbit = NEG;
        c.print();
    }
    else if(a.signbit == POS && b.signbit == NEG){
        if(a >= b){
            c.sub(a,b);
            c.print();
        }else{
            c.sub(b,a);
            c.signbit = NEG;
            c.print();
        }
    }
    else if(a.signbit == NEG && b.signbit == POS){
        if(a >= b){
            c.sub(a,b);
            c.signbit = NEG;
            if(c.c[c.end] == 0 && c.c[0] == 0)
                c.signbit = POS;
            c.print();
        }else{
            c.sub(b,a);
            c.signbit = POS;
            c.print();
        }
    }
    return 0;
}

