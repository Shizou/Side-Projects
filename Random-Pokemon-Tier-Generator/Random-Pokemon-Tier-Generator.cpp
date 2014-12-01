/** Name: William Granados
 *  Date: 01/12/14
 *  Purpose: Chooses a random set of pokemon from a specified tier.
 * */
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

int team_size;
string input;

const int UBER = 0, OU = 1, UU = 2, RU = 3, NU = 4, LC = 5;
vector< string > tier[6];// pair< Pokedex number, Pokemon name >
map<string,int>ctier;

/**Reads in pokemon from text file and places them in their respective tiers*/
void init_tier(string text_file,int t){
    try{
        ifstream in_file;
        in_file.open(text_file.c_str());
        string name;
        while(in_file >> name){
            tier[t].push_back(name);
        }
        in_file.close();
    }catch(exception &e){
        printf("%s missing\n",text_file.c_str());
    }
}
/**Initializes objects*/
void init(){
    init_tier("tiers\\Uber tier.txt",UBER);
    init_tier("tiers\\OU tier.txt",OU);
    init_tier("tiers\\UU tier.txt",UU);
    init_tier("tiers\\RU tier.txt",RU);
    init_tier("tiers\\NU tier.txt",NU);
    init_tier("tiers\\LC tier.txt",LC);
    ctier["UBER"] = UBER, ctier["OU"] = OU;
    ctier["UU"] = UU,     ctier["RU"] = RU;
    ctier["NU"] = NU,     ctier["LC"] = LC;
}
/**Makes input non-case sensitive for ease in code*/
void refine_input(){
    for(int i = 0; i < input.size();i++)
        input[i] = toupper(input[i]);
}
int main(){
    init();
    ifstream in_file;
    in_file.open("input.txt");
    in_file >> input;
    refine_input();
    if(ctier.find(input) != ctier.end()){
        in_file >> team_size;
        while(team_size--){
            srand(time(NULL));
            int i = rand() % tier[ctier[input]].size();
            printf("%s\n",tier[ctier[input]][i].c_str());
            tier[ctier[input]].erase(tier[ctier[input]].begin()+i);
        }
    }
    in_file.close();
    return 0;
}
