#include <stack>    //stack objects
#include <iostream> //cout printing
#include <cstdlib> //c string to int conversion
//struct to hold the values needed.
struct Step
    {
    char choice;
    int  lastvalue;
    int  currtotal;
    };
    
using namespace std;
void plan(int index, int max, int input[][4], stack<Step>* output);

int main(int argc, char** argv)
	{ 
	//initialize total the matrix, and the decission stack
	int hi_low_mat [2][4] = {{10,  1, 10, 10},
							 { 5, 50,  5, 15}};
	//sets up the temp value fto set upf for the when the stack would be empty
    Step current;
    current.choice = '\0';
    current.lastvalue = 0;
    current.currtotal = 0;
 
	stack<Step> decissions;
	decissions.push(current);
	//sets up the number of steps to do to 
	int index = 0;
	int max = atoi(argv[1]);
	//call plan to start recurssion
	plan(index, max, hi_low_mat, &decissions);
	current = decissions.top();
	//loop to print/calculate what decissions where made
	//if not at the end the list loop though
	while(current.choice != '\0')
		{ //print values at steps
		decissions.pop();
		cout<<"optimal total @ step: ";
		cout<<current.currtotal;
		cout<<" choice @ step: "<<current.choice<<endl;
		current = decissions.top();
		}
	return 1;
	}
	
void plan(int index, int max, int input[][4], stack<Step>* output)
	{
	//allows to check optimal answer at a certain point
	if (index == max) // if index is at the break point return
	    return;
	/*we need to check the solution so far, see if adding low to it is
	greater than a the total minus the last step plus high, basicly 
	if total + low > (total - stack->top) + high.  For our sample matrix
	run to the first place optimal would be 10, however if run to second,
	we would need to reverse one step and add high to get 50, */
	Step curr;  //stack top
	curr = output->top(); 
	output->pop(); //move top
	Step temp; // temp storeage 
	if (curr.currtotal + input[0][index] > (curr.currtotal - curr.lastvalue)+input[1][index])
	    { // if total + low value > total - last value + high value
	    temp.lastvalue = input[0][index];
	    temp.currtotal = curr.currtotal + temp.lastvalue;
	    temp.choice = 'l';  //low picked
	    }
	else if (curr.currtotal+input[0][index]<(curr.currtotal - curr.lastvalue)+input[1][index])
	    {
	    curr.choice = 'd';  //set 
	    curr.currtotal -= curr.lastvalue;
	    curr.lastvalue = 0;
	    temp.choice = 'h';
	    temp.lastvalue = input[1][index];
	    temp.currtotal = curr.currtotal + temp.lastvalue;
	    }
	//push previous and current.
	output->push(curr);
	output->push(temp);
	plan(index+1, max, input, output);
	}
