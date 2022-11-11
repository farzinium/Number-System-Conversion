#include <stdio.h>
#include <string.h>
#define pf printf
#define sf scanf

long long int Convert_to_num(char ch){
	if('0' <= ch && ch <= '9'){
		return ch - '0';
	}
	if('A' <= ch && ch <= 'Z'){
		return ch - 'A' + 10;
	}
	if('a' <= ch && ch <= 'z'){
		return ch - 'a' + 10;
	}
}

char Convert_to_char(int a){
	if(a < 10){
		return '0' + a;
	}
	else{
		return 'A' + a - 10;
	}
}

int main(){
	int s = 0, b = 10;
	char a[1000] = "";
	while(1){
		pf("%s", "Enter a Number: ");
		sf("%s", a);
		s = strlen(a);
		pf("%s", "Enter the base of the number: ");
		sf("%d", &b);
		if(b > 36){
			pf("%s", "This program does not support bases greater than 36.\nDo you want to enter another number?[Y/n]\n");
			sf("%1s", &a[0]);
			if(a[0] == 'Y'){
				continue;
			}
			return -0;
		}
		if(b < 2){
			pf("%s%d%s", "The base of a number can not be ", b, ".\nDo you want to enter another number?[Y/n]\n");
			sf("%1s", &a[0]);
			if(a[0] == 'Y'){
				continue;
			}
			return -0;
		}
		break;
	}
	long long int p = 0, q = 1;
	for(int i = s - 1; i >= 0; i--){
		p += Convert_to_num(a[i]) * q;
		q *= b;
	}
	while(1){
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
	while(p){
		a[q++] = Convert_to_char(p % b);
		p /= b; 
	}
	pf("%s%d%s", "Your number in base ", b, " is: ");
	for(int i = q - 1; i >= 0; i--){
		pf("%c", a[i]);
	}
	pf("%c", '\n');
	return -0;
}
