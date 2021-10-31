//MSSV: 6151071041 Truong Ngoc De
//MSSV: 6151071043 Le Viet Duc
#include<stdio.h>
#include<conio.h>
#include<math.h>

float y(float x){
	float a=4/(1+x*x);
	return (a);
}
int main(){
	int i,n;
	float a, b, x, h, e, x2, y2, x4, y4, tp;

//	clrscr();
	printf("Tinh tich phan theo phuong phap Simpson\n");
	printf("Cho can duoi a= ");
	scanf("%f", &a);
	printf("\nCho can tren b= ");
	scanf("%f", &b);
	printf("Cho so diem tinh n= ");
	scanf("%d", n);
	h=(b-a)/n;
	x2=a+h;
	x4=a+h/2;
	y4=y(x4);
	y2=y(x2);
	for(i=1; i<=n-2; i++){
		x2+=h;
		x4+=h;
		y4+=y(x4);
		y2+=y(x2);
	}
	y2=2*y2;
	y4=4*(y4+y(x4+h));
	tp=h*(y4+y2+y(a)+y(b))/6;
	printf("Gia tri cua tich phan la: %f \n", tp);
	getch();
	
}
