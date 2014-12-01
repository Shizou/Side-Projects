/*Finds the zeroes of a given function**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int highest_degree;
int temp_coefficient;
vector<double> coefficients;
vector<double> factors;
set<double> factors_used;

int main() {
	scanf("%d",&highest_degree);
	for(int i = 0; i < highest_degree){
		scanf("%d",&temp_coefficient);
		coefficients.push_back(temp_coefficient);
	}
	if(coeffients[0] == 1){
		for(int i = 1; i <= coefficients[highest_degree-1];i++){
            if(coefficients[highest_degree-1]%i == 0 && factors_used(i) == factors_used.end()){
                factors.push_back(i);
                factors_used.insert(i);
            }
		}
	}
	else{
        for(int i = 1; i <= coefficients[highest_degree-1];i++){
            if(coefficients[highest_degree-1]%i == 0 && factors_used(i) == factors_used.end()){
                factors.push_back(i);
                factors_used.insert(i);
            }
		}
		vector<double> lead_factors;
		for(int i = 1; i <= coefficients[0];i++){
            if(coefficients[0]%i == 0 && factors_used(i) == factors_used.end()){
                lead_factors.push_back(i);
                factors_used.insert(i);
            }
		}
		vector<int>new_coefficients;
		for(int i = 0; i < coeff)
	}
	for(int i = 0; i < high;i++){
		int eqn = arr[i]*arr[i]*arr[i] + 9*arr[i]*arr[i] + 26*arr[i] + 24;
		cout << arr[i] << " " << eqn << endl;
	}
	return 0;
}
