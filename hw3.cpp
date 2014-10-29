#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
char max(char *input, int left, int right);
char *mergesort(char *input, int left, int right);

int main(){

char Max[] = {'T', 'I', 'N', 'Y', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
char Merge[]= {'A', 'S', 'O', 'R', 'T', 'I', 'N','G','E','X','A','M','P','L','E'};
int maxlen = sizeof(Max);
int mergelen= sizeof(Merge);
char maxOut  = max(Max, 0, maxlen-1);
char *mergeOut= mergesort(Merge, 0, mergelen-1);
cout<<maxOut<<endl;
cout<<mergelen<<endl;
cout<<mergeOut<<endl;

return(0);
}

char max(char *input, int left, int right){
	if (left < right){
		int mid = (left+right)/2;
		//setup
		char leftout = max(input,left, mid);
		char rightout= max(input, mid+1, right);
		if (leftout> rightout){
			cout<<leftout<<" is the max of:"<<left<<":"<<right<<endl;
			return(leftout);
			}
		else{
			cout<<rightout<<" is the max of:"<<left<<":"<<right<<endl;
			return(rightout);
			}	
		}
	else{ //base case
		cout<<input[left]<<" is the max of:"<<left<<":"<<right<<endl;
		return(input[left]);
		}
}

char *mergesort(char *input, int left, int right){
	char *output;
	if (left< right){//setup
		int mid = (left+right)/2;
		int leftsize = mid-left;
		int rightsize= right-mid+1;
		char *leftout = mergesort(input, left, mid); //recursive left and right
		char *rightout = mergesort(input, mid+1, right);
		cout<<leftsize+rightsize<<": "<<leftout<<":"<<rightout<<endl; //show which strings
		output= new char [leftsize + rightsize];
		left = right = 0;
		//Merge
		for (int index =0; index < leftsize+rightsize; index++){
			if(((leftout[left] < rightout[right])&&(leftout[left] != '\0'))||(rightout[right] == '\0')){
				output[index] = leftout[left];
				left++;
				}
			else{
				output[index] = rightout[right];
				right++;
				}
			}
		//cout<<output<<endl;
		return(output);
		} //end merge
	else //base case
		{
		output = new char [1];
		output[0] = input[left];
		return(output);
		}
}
