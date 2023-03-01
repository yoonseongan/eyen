
#include<stdio.h>

int *larger(int *, int *);
int main()
{   
   double a = 10.15, b = 20.25;
   int *p;
   
   p = larger(&a, &b);
   printf("%f\n",*p); /// p의 주소값은 int b 선언할때 같이 옆에서 해서 4 간격
   
   return 0;

}
int *larger(int *x, int *y){
    if (*x>*y) return x;
    else return y;

}

///    왜 a,b,p를 같이 선언하는데 메모리 할당순서는 p,b,a 인가? ... 배열이 아닌이상 순서는 상관없을것같다. 
///     *larger의 의미가 뭔가? 위의 문장에서 굳이 쓸 필요는 없는것같다 그냥 larger(int*~~~~) 해도 상관없을것같다.
    /// *을 빼고 실행하니 함수 return 값에서 경고가 난다. 그렇다면 확실히 의미가 있다. 그렇다고 해도 출력에 변화가 있지는 않다. 

    /// 10번째 줄 때문에 함수 리턴값이 경고가 나는것 같다.
    /// warning: return makes integer from pointer without a cast : 형 변환없이 나온다. 라는 뜻
   
    /// 구글링을 해보니 int *fuc()는 포인터를 정수로 리턴한다고 한다. returns a pointer to integer
   
    /// 포인터를 int로 내보낸다. 즉 주소를 받아서 정수로 내보낼수 있게한다.
 
    /// 가설 1. 형변환을 해야하는 이유 : 소수값을 포함한 값에서는 오류가 날 수 있다.
 
    /// a,b에 10.15, 20.25를 넣어보자
    /// 경고는 나지만 오류는 없다. 
    ///20.25 잘 나온다. 왜지 
    ///   p = larger(&a, &b); warning: assignment from incompatible pointer type [-Wincompatible-pointer-types] :호환되지 않는 포인터 유형에서 할당
    /// warning: return from incompatible pointer type [-Wincompatible-pointer-types] if (*x>*y) return x; : 호환되지않는 포인터 유형에서 리턴
    /// int *larger(double *x, double*y) 라고 하지않고 double *larger(double *x, double*y) 라고 하면 경고는 해결
    ///
/*
#include<stdio.h>

int larger(double *, double *);


int main()
{   
   double a = 10.15, b = 20.25, *p;
   p = larger(&a, &b);
   printf("%f\n",*p); /// p의 주소값은 int b 선언할때 같이 옆에서 해서 4 간격
   
   return 0;

}
int larger(double *x, double*y){
    if (*x>*y) return x;
    else return y;

}
int larger로 했을때는 경고는 나지만 실행은 됨
*/

/*
#include<stdio.h>

double *larger(double *, double *);


int main()
{   
   double a = 10.15, b = 20.25, *p;
   p = larger(&a, &b);
   printf("%f\n",*p); /// p의 주소값은 int b 선언할때 같이 옆에서 해서 4 간격
   
   return 0;

}
double *larger(double *x, double*y){
    if (*x>*y) return x;
    else return y;

}
double *larger를 안하는 double larger에서는 형변환 오류가 난다. 

즉 소수점 자리 값을 포함하는 값에서는 형변환을 하지 않으면 오류가 난다. 하지만 int에서는 경고만 난다. int에서 되는 이유는 그냥 컴파일러가 해주는 듯


그러니까 이 함수는 주소를 받아서 함수를 거쳐 실수로 내보내기 위한 함수다. 
소수점값을 포함하는 실수에서는 오류가 날 수 있으니 함수에 포인터로 선언을 해야한다.

*/