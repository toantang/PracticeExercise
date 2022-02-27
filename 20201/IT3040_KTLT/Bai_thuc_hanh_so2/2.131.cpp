/*
 *
 */
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include <string>
using namespace std;

struct bigNum {
	char sign;
	string num;

	void set(bigNum a) {
		this->sign = a.sign;
		this->num = a.num;
	}

	bigNum() {
		this->sign = '1';
		this->num = "0";
	}

};

int toInt(char c) {
	return (int) c - 48;
}

char toChar(int i) {
	return (char) (i + 48);
}

int len(bigNum a) {
	return a.num.length();
}

bigNum operator +(bigNum a, bigNum b) {
	bigNum longer = (len(a) >= len(b)) ? a : b;
	bigNum shorter = (len(a) < len(b)) ? a : b;
	//
	bigNum temp;
	temp.num = longer.num;
	bool remember = false;
	int rmb = 0;
	//phase1
	int j = len(longer) - 1;
	for (int i = len(shorter) - 1; i >= 0; i--) {
		int k = toInt(shorter.num[i]) + toInt(longer.num[j]) + rmb;
		if (k >= 10) {
			temp.num[j] = toChar(k - 10);
			remember = true;
			rmb = 1;
		} else {
			temp.num[j] = toChar(k);
			remember = false;
			rmb = 0;
		}
		j--;
	}
	//phase2
	for (int i = j; i >= 0; i--) {
		int k = toInt(longer.num[i]) + rmb;
		if (k >= 10) {
			temp.num[i] = toChar(k - 10);
			rmb = 1;
			remember = true;
		} else {
			temp.num[i] = toChar(k);
			rmb = 0;
			remember = false;
		}
	}
	//Exception
	if (remember) {
		temp.num = "1" + temp.num;
	}
	//
	return temp;
	//sign is 1 always
}

bigNum operator -(bigNum a, bigNum b) {
	bool aIsLonger = true;
	bigNum longer = (len(a) >= len(b)) ? a : b;
	bigNum shorter = (len(a) < len(b)) ? a : b;
	if (len(a) < len(b))
		aIsLonger = false;
	//
	bigNum temp;
	temp.num = longer.num;
	bool remember = false;
	int rmb = 0;
	//phase1
	int j = len(longer) - 1;
	for (int i = len(shorter) - 1; i >= 0; i--) {
		int k = toInt(longer.num[j]) - toInt(shorter.num[i]) - rmb;
		if (k < 0) {
			temp.num[j] = toChar(k + 10);
			remember = true;
			rmb = 1;
		} else {
			temp.num[j] = toChar(k);
			remember = false;
			rmb = 0;
		}
		j--;
	}
	//phase2
	for (int i = j; i >= 0; i--) {
		int k = toInt(longer.num[i]) - rmb;
		if (k < 0) {
			temp.num[i] = toChar(k + 10);
			rmb = 1;
			remember = true;
		} else {
			temp.num[i] = toChar(k);
			rmb = 0;
			remember = false;
		}
	}
	//Exception
	if (!aIsLonger) {
		longer.sign = '0';
	} else if (remember) {
		string tc;
		tc = "1";
		for (int i = 1; i <= len(longer); i++) {
			tc += "0";
		}
		bigNum temp1;
		temp1.sign = '0';
		temp1.num = tc;
		return temp1 - temp;
	}
	//
	temp.sign = longer.sign;
	//reduce zero
	int mark = -1;
	for (int i = 0; i < len(temp); i++) {
		if (isdigit(temp.num[i]) && temp.num[i] != '0') {
			mark = i;
			break;
		}
	}
	if (mark == -1) {
		temp.num = "0";
		return temp;
	}

	temp.num = temp.num.substr(mark, len(temp) - mark);
	//
	return temp;
	//
}

bigNum operator *(int n, bigNum a) {
	bigNum temp;
	for (int i = 0; i < n; i++) {
		temp.set(temp + a);
	}
	return temp;
}

bigNum pls(bigNum a, bigNum b) {
	if (a.sign == '0' && b.sign == '0') {
		bigNum zero;
		a.sign = '1';
		b.sign = '1';
		return zero - (a + b);
	} else if (a.sign == '0' && b.sign == '1') {
		a.sign = '1';
		return b - a;
	} else if (a.sign == '1' && b.sign == '0') {
		b.sign = '1';
		return a - b;
	} else if (a.sign == '1' && b.sign == '1') {
		return a + b;
	}
}

bigNum operator *(bigNum a, bigNum b) {
	bigNum longer = (len(a) >= len(b)) ? a : b;
	bigNum shorter = (len(a) < len(b)) ? a : b;
//
	bigNum result;
	for (int i = len(shorter) - 1; i >= 0; i--) {
		bigNum temp;
		//
		string s;
		for (int j = 0; j < len(shorter) - i - 1; j++)
			s += "0";
		//
		temp.set(toInt(shorter.num[i]) * longer);
		temp.num += s;
		result.set(result + temp);
		//
	}
	if ((a.sign == '1' && b.sign == '0') || (a.sign == '0' && b.sign == '1'))
		result.sign = '0';
	return result;

}

bigNum scanN() {
	bigNum temp;
	cin >> temp.sign >> temp.num;
	return temp;
}

void printN(bigNum temp) {
	cout << temp.sign << temp.num << endl;
}

bigNum result(bigNum a, bigNum b) {
	bigNum result,p1,p2,p3;
	p1.set(a*b);
	p2.set(3*a);
	p3.set(4*b);
	if (a.sign == '0' && b.sign == '0') {
		p2.sign = '1';
		p3.sign = '0';
	}
	if (a.sign == '0' && b.sign == '1') {
		p2.sign = '1';
		p3.sign = '1';
	}
	if (a.sign == '1' && b.sign == '0') {
		p2.sign = '0';
		p3.sign = '0';
	}
	if (a.sign == '1' && b.sign == '1') {
		p2.sign = '0';
		p3.sign = '1';
	}
	result.set(pls(pls(p1,p2),p3));
	return result;
	//
}

int main() {
	bigNum temp = scanN();
	bigNum temp1 = scanN();
	printN(result(temp,temp1));
}

