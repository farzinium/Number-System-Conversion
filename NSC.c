#include <stdio.h>
#include <string.h>				//this library alows us to use strlen() to get the size of a string
#define pf printf				//defining macro pf to printf, making it easier to type :)
#define sf scanf				//same as pf, but for scanf

long long int Convert_to_num(char ch){		//a function that returns the value of ch to long long int
	if('0' <= ch && ch <= '9'){ 		//if ch is a number (i.e 0 to 9)
		return ch - '0';
	}
	if('A' <= ch && ch <= 'Z'){ 		//if ch is an uppercase letter (i.e A to Z)
		return ch - 'A' + 10;
	}
	if('a' <= ch && ch <= 'z'){ 		//if ch is a lowercase letter (i.e a to z)
		return ch - 'a' + 10;
	}
}

char Convert_to_char(int a){			//a function that returns the character representing number a
	if(a < 10){ 				//if a is less than 10 (i.e 0 to 9)
		return '0' + a;
	}
	else{					//if a is more than 9 (i.e A to Z)
		return 'A' + a - 10;
	}
}

int main(){
	int s = 0, b = 10;
	char a[1000] = "";
	while(1){				//the loop is infinite, until user enters the right number and base or does not want to continue
		pf("%s", "Enter a Number: ");
		sf("%s", a);			//recives the number as string
		s = strlen(a);			//saves the length of string in s
		pf("%s", "Enter the base of the number: ");
		sf("%d", &b);
		if(b > 36){
			pf("%s", "This program does not support bases greater than 36.\nDo you want to enter another number?[Y/n]\n");
			sf("%1s", &a[0]);
			if(a[0] == 'Y'){ 	//user wants to enter another number
				continue;	//goes to line 31
			}
			return -0;		//user does not want to enter another number, so the program ends
		}
		if(b < 2){
			pf("%s%d%s", "The base of a number can not be ", b, ".\nDo you want to enter another number?[Y/n]\n");
			sf("%1s", &a[0]);	
			if(a[0] == 'Y'){	//user wants to enter another number
				continue;	//goes to line 31
			}
			return -0;		//user does not want to enter another number, so the program ends
		}
		break;				//if nothing wrong happens, the loop breaks (goes to line 54)
	}
	long long int p = 0, q = 1;
	for(int i = s - 1; i >= 0; i--){	//this loop makes p equal to the actual value of user's input
		p += Convert_to_num(a[i]) * q;
		q *= b;
	}
	while(1){				//another infinite loop, same as before
		pf("%s", "Enter the base you want to convert the number: ");
		sf("%d", &b);
		if(b > 36){
			pf("%s", "This program does not support bases greater than 36.\nDo you want to enter another base?[Y/n]\n");
			sf("%1s", &a[0]);
			if(a[0] == 'Y'){
				continue;
			}
			return -0;
		}
		if(b < 2){
			pf("%s%d%s", "The base of a number can not be ", b, ".\nDo you want to enter another base?[Y/n]\n");
			sf("%1s", &a[0]);
			if(a[0] == 'Y'){
				continue;
			}
			return -0;
		}
		break;
	}
	q = 0;
	while(p){					//converts the actual value (i.e p) to user's base and store it as a string
		a[q++] = Convert_to_char(p % b);
		p /= b; 
	}
	pf("%s%d%s", "Your number in base ", b, " is: ");	
	for(int i = q - 1; i >= 0; i--){		//prints the number in the base user wanted 
		pf("%c", a[i]);
	}
	pf("%c", '\n');
	return -0;
}
