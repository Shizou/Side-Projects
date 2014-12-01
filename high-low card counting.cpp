/** Name: William Granados
 *  Date: 01/12/14
 *  Purpose: Some card tracking for the game high-low
 * */
#include<iostream>
#include<cstdio>
#include<cctype>
#include<map>

using std::map;
using std::string;
using std::cin;

int card[13], card_count;
double pos_high,pos_low,pos_mid;
map< string, int > query;
string input,last_input;

/**Initializes indicies for specified cards in a standard deck.*/
void init(){
    query["A"]  = 12; query["K"] = 11;
    query["Q"]  = 10; query["J"] = 9;
    query["10"] =  8; query["9"] = 7;
    query["8"]  =  6; query["7"] = 5;
    query["6"]  =  4; query["5"] = 3;
    query["4"]  =  2; query["3"] = 1;
    query["2"]  =  0;
}
void tutorial(){
    printf("High-low card counter online!\n");
    printf("Commands for updating the current high-low game goes as follows:\n");
    printf("1. To update current cards in deck, simply input a valid card\n   from a standard deck.\n   sample procedure\n   10\n   Updated.\n\n");
    printf("2. To display current probablity simply input key word \"pos\"\n   without the brackets, then input your current card when prompted.\n   sample input\n   pos\n   Your card?\n   a\n\n");
    printf("3. To reset current game simply input key word \"res\"\n   sample input\n   res\n   Game reset.\n\n");
    printf("4. To terminate program simply input key word \"ter\"\n   sample input\n   ter\n   Terminated.\n\n");
}
/**Resets possibities for the whole game*/
void reset_card_count(){
    card_count = 52;
    pos_high = pos_mid = pos_low = 0.0;
    for(int i = 0; i < 13;i++)
        card[i] = 4;
}
/**Converts input to all uppercase*/
void non_case_sensitive(string&in){
    for(int i = 0; i < in.size();i++)
        in[i] = toupper(in[i]);
}
/**Calculates possibilities for the current game*/
void update_possiblities(int in){
    pos_high = pos_mid = pos_low = 0.0;
    for(int i = 0; i < in;i++)
        pos_low+=card[i];
    pos_mid = card[in];
    for(int i = in+1; i < 13;i++)
        pos_high+=card[i];
    pos_low/=card_count;
    pos_mid/=card_count;
    pos_high/=card_count;
}
/**Checks whether or not the input is a valid card in a deck*/
bool validate_input(string &in){
    return query.find(in) != query.end();
}
int main(){
    init();
  //  tutorial();// can be commented out
    reset_card_count();
    while(getline(cin,input)){
        non_case_sensitive(input);
        //update possiblities
        if(validate_input(input)){
            if(card[query[input]] -1 >= 0){
                card[query[input]]--;
                card_count--;
                printf("Updated.\n");
            }
            else{
                printf("Invalid input.\n");
            }
        }
        // print out possibilities
        else if(input == "POS"){
            printf("Your card?\n");
            getline(cin,input);
            non_case_sensitive(input);
            if(validate_input(input)){
                update_possiblities(query[input]);
                printf("High: %.2f\n",pos_high*100);
                printf("Med:  %.2f\n",pos_mid*100);
                printf("Low:  %.2f\n",pos_low*100);
            }
            else{
                printf("Invalid input.\n");
            }
            continue;
        }
        // reset possiblities
        else if(input == "RES"){
            printf("Game reset.\n");
            reset_card_count();
            continue;
        }
        // terminate program
        else if(input == "TER"){
            printf("Program terminated.\n");
            break;
        }
        // not valid input
        else{
            printf("Invalid input.\n");
            continue;
        }
    }
    return 0;
}
