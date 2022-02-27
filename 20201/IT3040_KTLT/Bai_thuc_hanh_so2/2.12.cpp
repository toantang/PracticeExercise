#include<stdio.h>
#include<iostream>

using namespace std;

struct input{
	int key;
	int value;
};

void getI(input i){
	printf("%d %d\n",i.key,i.value);
} 

void sort(input* e,int n){
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(e[j].value>e[i].value){
				input temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}else
				if(e[j].value==e[i].value){
					if(e[j].key>e[i].key){
						input temp = e[i];
				 		e[i] = e[j];
						e[j] = temp;
					}
				}
		}
	}
}

void lambda(void(*get)(input a)){
	input e[1000];
	int i = 0;
	for(int a,b;std::cin >> a>> b;i++){
		e[i].key=a;
		e[i].value=b;
	}
	sort(e,i);
	for(int j=0;j<i;j++)
		get(e[j]);
}

int main(){
	lambda(getI);
}
