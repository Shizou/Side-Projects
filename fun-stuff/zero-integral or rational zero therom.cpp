/* Author: William G.
   Pupose: Implementation of Zero Integral theorem and Rational Zero theorem
   Date  : 11/10/14
   Instructions: Input the highest degree present in your function f(x) then input the respective
   				 coefficients for each term in your functon. Note: if the ith power is not present 
   				 in your function (i.e f(x) does not contain an x^2) then simply set that term's
   				 coefficient to 0.
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

int highestDegree;
double coefficient[100];
bool possible;
vector<double>leadingCoefficientFactors;
vector<double>trailingCoefficientFactors;
vector<double>mergedFactors;
set<double> usedFactors;

void storeFactors(vector<double>&in, int coef){
	printf("Factors of %d are: ", abs(coef));
	coef = abs(coef);
	for(int i = 1; i <= coef;i++){
		if(coef%i == 0){
			printf("± %d ",i);
			in.push_back(i);
			in.push_back(-i);
			usedFactors.insert(i);
		}
	}
	printf("\n");
}
void mergeFactors(vector<double>&in, vector<double>&lc, vector<double>&tc){
	printf("Merged factors of f(x) are: ");
	for(int i = 0; i < tc.size();i++){
		for(int j = 0; j < lc.size();j++){
			if(usedFactors.find(abs(lc[j])/abs(tc[i])) == usedFactors.end()){
				printf("(± %.2f/%.2f) ",lc[j],tc[i]);
				in.push_back(abs(lc[j])/abs(tc[i]));
				in.push_back(-abs(lc[j])/abs(tc[i]));
				usedFactors.insert(abs(lc[j])/abs(tc[i]));
			}
		}
	}
	printf("\n");
}
int main() {
	cin >> highestDegree;
	printf("f(x) = ");
	for(int i = 0; i <= highestDegree;i++){
		cin >> coefficient[i];
		printf("%.2f(x)^%d ",coefficient[i], highestDegree - i);
	}
	printf("\n");
	storeFactors(leadingCoefficientFactors, coefficient[0]);
	storeFactors(trailingCoefficientFactors, coefficient[highestDegree]);
	if(coefficient[0] != 1)
		mergeFactors(mergedFactors,leadingCoefficientFactors, trailingCoefficientFactors);
	
	possible = false;
	// substitute leading coefficient factors
	for(int i = 0; i < leadingCoefficientFactors.size() && !possible;i++){
		double ans = 0;
		for(int j = 0; j < highestDegree;j++)
			ans+= coefficient[j]*pow(leadingCoefficientFactors[i],highestDegree-j);
		
		ans+=coefficient[highestDegree];
		if(ans == 0){
			printf("P(%.2f) -> 0\n",leadingCoefficientFactors[i]);
			possible = true;
		}
	}
	// substitute trailing coefficient factors
	for(int i = 0; i < trailingCoefficientFactors.size() && !possible;i++){
		double ans = 0;
		for(int j = 0; j < highestDegree;j++)
			ans+= coefficient[j]*pow(trailingCoefficientFactors[i],highestDegree-j);
			
		ans+=coefficient[highestDegree];
		if(ans == 0){
			printf("P(%.2f) -> 0\n",trailingCoefficientFactors[i]);
			possible = true;
		}
	}
	// substitute merged coefficient factors
	for(int i = 0; i < mergedFactors.size() && !possible;i++){
		double ans = 0;
		for(int j = 0; j < highestDegree;j++)
			ans+= coefficient[j]*pow(mergedFactors[i],highestDegree-j);
		
		ans+=coefficient[highestDegree];
		if(ans == 0){
			printf("P(%.2f) -> 0\n",mergedFactors[i]);
			possible = true;
		}
	}
	if(!possible)
		printf("No unique solution found\n");
		
	return 0;
}
