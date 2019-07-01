#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;



//1 求阶乘（非递归） 
int fn1(int n)
{
    if(n < 0)
        return -1; //错误
    if(n == 0)
        return 1;
        
    int multi = 1;    
    for(int i = 1;i <= n;i++)
    {
        multi *= i;
    }
    return multi;
}

//1 求阶乘（递归）
int fn2(int n)
{
    if(n < 0)
        return -1; //错误
        
    if((n == 0)||(n == 1))
        return 1;
        
    return fn2(n-1)*n;
}


//2 判断是否是闰年 
int IsLeapYear(int iYear)
{
    if ((iYear & 3) != 0)  //不能被4整除 
    {//(iYear % 4 != 0)
        return 0;
    }
    else if (iYear % 100 != 0)  //能被4整除，不能被100整除 
    {
        return 1;
    }
    else if (iYear % 400 == 0)   //能被400整除
    {
        return 1;
    }
    else   //能被100整除，不能被400整除
    {
        return 0;
    }
}

//3 斐波那契数列第n项的值（递归） 
int fibonacci1(int n)
{
    if(n < 1)
        return 0;
    else if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    else
        return fibonacci1(n - 1) + fibonacci1(n - 2);
} 
//3 斐波那契数列第n项的值（非递归）  
int fibonacci2(int n)
{  
    if(n < 1)
        return 0;
    else if(n == 1)
        return 1;
    else if(n == 2)
        return 1;
    else
    {
        int f1 = 1;
        int f2 = 1;
        int sum = 0; 
        int i = 3;
        
        for(;i <= n;i++)
        {    
            sum = f2 + f1;
            f1 = f2;
            f2 = sum;
        }
        return sum; 
    }               
} 


//4 判断一个自然数是不是素数（质数）  
int IsPrime(int n)
{//算法：从2开始，到k=对n开方（下取整），因为若是能被一个数整除，在k之下就一定可以  
    if(n < 1)
        return 0;  //不合要求不是素数 
        
    int i,k;
    k = int(sqrt(n));
    for(i=2;i<=k;i++)
        if((n%i)== 0)break;
    if(i>k)
        return 1; //不是素数
    else
        return 0; //是素数     
} 

//5 判筛法求n以内的所有素数  
void GetPrime(int n)
{//算法：从2开始，若当前数是素数，{将n以内的所有当前数的倍数筛掉，下一个数}  
 //      若当前数的标志，为1则必然是素数（因为当前元素相当于被以前的所有元素试除过）        
    int *sieve = new int[n+1];
    int i,j;
    
    for(i=0;i<=n;i++)
        sieve[i] = 1;
    sieve[0] = sieve[1] = 0;//0和1不是素数
    
    int count = 0;
 
    for(i=2;i<=n;i++) 
        if(sieve[i] == 1)//i是素数
        {
            printf("%5d",i);//输出素数
            count ++;
            if(count % 8 == 0)//每行输出8个值
                printf("\n");
            for(j = i;j <= n; j += i)
                sieve[j] = 0;//筛去i的倍数
        }
    printf("\n");
    printf("\n\n\nprime num = %d\n",count);
    delete [] sieve;
} 


//Greatest Common Divisor, 最大公约数，辗除法求解
uint32_t gcd1(uint32_t a, uint32_t b) {
	while(b) {
		uint32_t temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

//Greatest Common Divisor, 最大公约数，辗除法递归求解
uint32_t gcd2(uint32_t a, uint32_t b) {
    if (b == 0) {
        return a;
    } else {
        return gcd2(b, a % b);
    }
}

//Greatest Common Divisor, 最大公约数，相减法，递归求解
uint32_t gcd3(uint32_t a, uint32_t b) {
    if(b == 0)
        return a;
    else if(a < b)
        return gcd3(b - a, a);
    else
        return gcd3(a - b, b);
}
// gcd使用移位操作，编程之美：https://blog.csdn.net/a45872055555/article/details/34963315

//最小公倍数,Least Common Multiple（借助最大公约数）
uint32_t lcm(uint32_t a, uint32_t b) {
    uint32_t gcd = gcd1(a, b);
    return a * b / gcd;
}

#if 1
int main() {
    uint32_t a = 8;
    uint32_t b = 12;
    //uint32_t c = gcd1(a, b);
    //uint32_t c = gcd2(a, b);
    uint32_t c = gcd3(a, b);
    cout << "gcd1: " << c << endl;

    uint32_t num = lcm(a, b);
    cout << "lcm: " << num << endl;
    return 0;
}
#endif

// 整数溢出判断：https://zhidao.baidu.com/question/268233026615793765.html

//8 求水仙花数（三位数满足个位数字立方和等于本身如：153=1立方+5立方+3立方）
//共四个：153、370、371、407 
void ShuiXianHua(void)
{//遍历100---999 
	
	int i,low = 0,ten = 0,hundred = 0;
	
	for(i=100;i<1000;i++)
	{
        low = i % 10;
        ten = i / 10 % 10;
        hundred = i/100;
        
        int sum = low*low*low + ten*ten*ten + hundred*hundred*hundred;
        
        if(i == sum)
            printf("%-5d",sum);        
    }
	printf("\n");
	return;
}


//9 求n以内的完数（一个数恰好等于他的各个因子之和，则称为完数（完美数），
//  如6的因子是1、2、3，6=1+2+3，所有6是完数）
//共三个：6、28、496 
void WanShu(int n)
{//遍历1---1000 
	
	int i,k;	
	int count = 0;
	for(i=1;i<=n;i++) 
	{
        k = int(sqrt(i));
        int sum = 0;
        int j;
        for(j=1;j<=k;j++)
        {
            if((i%j)==0)
            {
                if(j<i)
                    sum += j;
                if(i/j < i)
                    sum += i/j;
            }
        }
        
        if(sum == i)
        {
            count++;
            printf("%-5d",i);
            if(count%5 == 0)
                printf("\n");
        }        
    }
    
    printf("\n\n");
    printf("count=%d\n",count);
	return;
}


//10  迭代法求x=根号下a（迭代公式是：x(n+1)=(x(n)+a/x(n))/2）
//    要求两次求出的x(n+1)-x(n)的差的绝对值小于10的-5次方 
double mysqrt(double a)
{
  double x = a/2;
  double d = 10000;
  while ( d>1e-5 || d<-1e-5)
  {
    d = x;
    x = (x + a/x) /2 ;
    d -= x;
  }
  return x;
}


//11  数组逆序
void reverse(int sum[],int n)
{
    int i;
    
    for(i=0;i<n;i++)
        printf("%-5d",sum[i]);
    printf("\n");
    
    int temp;
    for(i=0;i<n/2;i++)
    {
        temp = sum[i];
        sum[i] = sum[n-i-1];
        sum[n-i-1] = temp;
    }

    for(i=0;i<n;i++)
        printf("%-5d",sum[i]);
    printf("\n");
    return;
}



//12  打印杨辉三角 
void PrintYangHui(int n)
{
    int *array = new int[(n+1)*(n+1)];
    
    int i;
    for(i=0;i<=n;i++)
    {
        *(array+i) = 0;
        //*(array+i*n+j) = 0;
        //array[0][i] = 0;
        *(array+i*(n+1)) = 0;
        //array[i][0] = 0;
    }
    *array = 1;
    
    for(i=1;i<=n;i++)
    {
        int j;
        for(j=1;j<=i;j++)
        {
            *(array+i*(n+1)+j) = *(array+(i-1)*(n+1)+j-1) + *(array+(i-1)*(n+1)+j);
            //a[i][j] = a[i-1][j-1] + a[i-1][j];
            printf("%-4d",*(array+i*(n+1)+j));
        }
        
        if(j<=n)
            *(array+i*(n+1)+j) = 0;
        printf("\n");         
    }
    delete [] array;    
    return;
}



//13  打印二维数组鞍点 
//数组每行的最大值，是同列的最小值的元素称为鞍点
//一个二维数组可能有多个鞍点，也可能没有鞍点



//14  N*N方阵，行列互换




//15  汉诺塔问题（用递归求解，C语言课本174页） 
//寺院有三个座子，A座有64个盘子，大盘在下，小盘在上，欲将A盘上的座子全部挪到C
//座子上，可以用B座子暂存，全部座子必须大盘在下，问步骤
void move(char x,char y)
{
    printf("%c-->%c\n",x,y);
}

void hanoi(int n,char one,char two,char three) 
{//将n个盘子从one座借助two座，移动到three座上 
 //共需2^n - 1次移动
    if(n == 1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }    
}

//16  M个人围成一圈（顺序）循环报数，报到N出局，问最后一个是哪个人？（C语言课本278页）
int getLastQuit(int array[], int totalNum, int outNum)
{
    int count = 0;

    for (int i = 0, quitNum = 0; quitNum < totalNum - 1; i = (i + 1) % totalNum) {
        if (array[i] != 0) {
            count = (count + 1) % outNum;
            if(count == 0) {
                array[i] = 0;
                quitNum++;
            }
        }        
    }

    for (int i = 0; i < totalNum; ++i) {
        if (array[i] != 0) {
            return array[i];
        }
    }
    return 0;
}


#if 0

int main() {
    
    const int kTotalNum = 4;
    const int kOutNum = 2;
    int array[kTotalNum];
    for (int i = 0; i < kTotalNum; i++) {
        array[i] = i + 1;
    }

    int num = getLastQuit(array, kTotalNum, kOutNum);
     
    printf("num = %d\n",num);

    return 0;
}

#endif

#if 0

int main() {

    int sum = 0;
    int n = 6;

    sum = getLastQuit(4, 3);
    //hanoi(4,'A','B','C');
    //PrintYangHui(10);
    //int a[9] = {1,2,3,4,5,6,7,8,9};
    //reverse(a,9);
    //double f = mysqrt(9.0);
    //WanShu(1000);
    //ShuiXianHua();
    //sum = GongBeiShu(3,4);
    //sum = GongYueShu(14,30);
    //sum = IsPrime(n);
    //GetPrime(200);
    //printf("fn2(5) = %d\n",sum);

    printf("sum = %d\n",sum);
    //printf("f = %f\n",f);

    return 0;
}

#endif
