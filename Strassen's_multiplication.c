#include<stdio.h>
void add(int n,int a[n][n],int b[n][n],int result[][n])
{
int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        result[i][j] = a[i][j] + b[i][j];
    }
}
}
void sub(int n,int a[n][n],int b[n][n],int result[][n])
{
int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        result[i][j] = a[i][j] - b[i][j];
    }
}
}
void divide(int n,int a[n][n],int c[n/2][n/2],int i,int j)
{
int i1,i2,j1,j2;
for(i1=0,i2=i;i1<n/2;i1++,i2++)
{
    for(j1=0,j2=j;j1<n/2;j1++,j2++)
    {
        c[i1][j1] = a[i2][j2];
    }
}
}
void join(int n,int a[][n],int c[][n/2],int i,int j)      
{
int i1,i2,j1,j2;
for(i1=0,i2=i;i1<(n/2);i1++,i2++)
{
    for(j1=0,j2=j;j1<(n/2);j1++,j2++)
    {
        a[i2][j2] = c[i1][j1];
    }
}
}
void multiply(int n,int a[][n],int b[][n],int result[][n])
{
int i,j;

if(n==2)
{
    int p1 = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    int p2 = (a[1][0]+a[1][1])*b[0][0];
    int p3 = a[0][0]*(b[0][1]-b[1][1]);
    int p4 = a[1][1]*(b[1][0]-b[0][0]);
    int p5 = (a[0][0]+a[0][1])*b[1][1];
    int p6 = (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    int p7 = (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

    int c11 = p1 + p4 - p5 + p7;
    int c12 = p3 + p5;
    int c21 = p2 + p4;
    int c22 = p1 + p3 - p2 + p6;

    result[0][0] = c11;
    result[0][1] = c12;
    result[1][0] = c21;
    result[1][1] = c22;
}
else
{
    int a11[n/2][n/2];
    int a12[n/2][n/2];
    int a21[n/2][n/2];
    int a22[n/2][n/2];

    int b11[n/2][n/2];
    int b12[n/2][n/2];
    int b21[n/2][n/2];
    int b22[n/2][n/2];

    //divide matrices A & B into four parts
    divide(n,a,a11,0,0);
    divide(n,a,a12,0,n/2);
    divide(n,a,a21,n/2,0);
    divide(n,a,a22,n/2,n/2);

    divide(n,b,b11,0,0);
    divide(n,b,b12,0,n/2);
    divide(n,b,b21,n/2,0);
    divide(n,b,b22,n/2,n/2);

    //partial products

    int p1[n/2][n/2],p2[n/2][n/2],p3[n/2][n/2],p4[n/2][n/2],p5[n/2][n/2],p6[n/2][n/2],p7[n/2][n/2];

    int c11[n/2][n/2],c12[n/2][n/2],c21[n/2][n/2],c22[n/2][n/2];

    int i1[n/2][n/2],i2[n/2][n/2];
    add(n/2,a11,a22,i1);
    add(n/2,b11,b22,i2);
    multiply(n/2,i1,i2,p1);

    int i3[n/2][n/2];
    add(n/2,a21,a22,i3);
    multiply(n/2,i3,b11,p2);

    int i4[n/2][n/2];
    sub(n/2,b12,b22,i4);
    multiply(n/2,a11,i4,p3);

    int i5[n/2][n/2];
    sub(n/2,b21,b11,i5);
    multiply(n/2,a22,i5,p4);

    int i6[n/2][n/2];
    add(n/2,a11,a12,i6);
    multiply(n/2,i6,b22,p5);

    int i7[n/2][n/2];
    int i8[n/2][n/2];
    sub(n/2,a21,a11,i7);
    add(n/2,b11,b12,i8);
    multiply(n/2,i7,i8,p6);

    int i9[n/2][n/2];
    int i10[n/2][n/2];
    sub(n/2,a12,a22,i9);
    add(n/2,b21,b22,i10);
    multiply(n/2,i9,i10,p7);

    //for c11
    int r1[n/2][n/2];
    int r2[n/2][n/2];

    add(n/2,p1,p4,r1);        //sub operation
    sub(n/2,r1,p5,r2);        //sub operation
    add(n/2,r2,p7,c11);        //main operation

    //for c12
    add(n/2,p3,p5,c12);

    //for c21
    add(n/2,p2,p4,c21);

    //for c22
    int r3[n/2][n/2];
    int r4[n/2][n/2];

    add(n/2,p1,p3,r3);       //sub operation
    sub(n/2,r3,p2,r4);       //sub operation
    add(n/2,r4,p6,c22);       //main operation


    join(n,result,c11,0,0);
    join(n,result,c12,0,n/2);
    join(n,result,c21,n/2,0);
    join(n,result,c22,n/2,n/2);

}
}
main()
{
int n;
printf("Enter the order of the matrices(power of 2):\n");
scanf("%d",&n);

int i,j;
int a[n][n],b[n][n];

printf("Enter first matrix:\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&a[i][j]);
    }
}
printf("Enter second matrix:\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&b[i][j]);
    }
}
printf("First matrix is \n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf("%d\t",a[i][j]);
    }
    printf("\n");
}
printf("Second matrix is \n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf("%d\t",b[i][j]);
    }
    printf("\n");
}
int r[n][n];
multiply(n,a,b,r);
printf("---RESULT OF MULTIPLICATION---\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf("%d\t",r[i][j]);
    }
    printf("\n");
}
}
