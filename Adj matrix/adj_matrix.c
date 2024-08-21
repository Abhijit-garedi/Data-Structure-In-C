// adj matrix

  #include <stdio.h>

#include <math.h>

#define max 8

int maxi(int v1,int v2,int v3,int v4)
{  if(v1>v2)  { if(v1>v3)    {if(v1>v4) return v1;
				   else return v4;
			      }
		     else    {if(v3>v4) return v3;
				   else return v4;
			      }
		}
    else      {if(v2>v3)    {if(v2>v4) return v2;
				  else return v4;
			      }
		    else    {if(v3>v4) return v3;
				  else return v4;
				}
		}
}

void same(int a[max][max],int c[max][max],int h,int rs,int cs)
{ int i,j,k,l;
  for(i=0;i<h;i++)   for(j=0;j<h;j++)    c[i][j]=a[i+rs*h][j+cs*h];
}
void sum(int a[max][max],int b[max][max],int c[max][max],int h,int fr,int fc,int sr,int sc)
{ int i,j,k,l;
    printf("\n\n  ");
    for(i=0;i<h;i++,printf("||"))     for(j=0;j<h;j++)      printf("%4d",a[i+fr*h][j+fc*h]);
    printf("\n+");
    for(i=0;i<h;i++,printf("||"))     for(j=0;j<h;j++)      printf("%4d",b[i+sr*h][j+sc*h]);
    printf("\n=");
    for(i=0;i<h;i++,printf("||")) for(j=0;j<h;j++)     { c[i][j]=a[i+fr*h][j+fc*h]+b[i+sr*h][j+sc*h];       printf("%4d",c[i][j]);  }
   
}
void dif(int a[max][max],int b[max][max],int c[max][max],int h,int fr,int fc,int sr,int sc)
{ int i,j,k,l;

   //printf("\n\n");    for(i=0;i<h;i++,printf("||")) for(j=0;j<h;j++)    printf("%4d",a[i+fr*h][j+fc*h]);
   //printf("\n-");    for(i=0;i<h;i++,printf("||")) for(j=0;j<h;j++)    printf("%4d",b[i+sr*h][j+sc*h]);
   //printf("\n=");    
   for(i=0;i<h;i++,printf("||")) for(j=0;j<h;j++)    { c[i][j]=a[i+fr*h][j+fc*h]-b[i+sr*h][j+sc*h];    //printf("%4d",c[i][j]);
      }
   
}
int smm(int a[max][max],int b[max][max],int c[max][max],int rw)
{ static int noa=0,nom=0;
  int p,q,r,s,t,u,v;
  int op1[max][max];  int op2[max][max];  int op3[max][max];
  int op4[max][max];  int t1[max][max];  int t2[max][max];
  int m1[max][max];  int m2[max][max];  int m3[max][max];
  int m4[max][max];  int m5[max][max];  int m6[max][max];
  int m7[max][max];

  int i,j,fr,fc,sr,sc,hr,hc,h;  double lr,lc;
  lr=log(rw);  lr=lr/log(2);  lr=ceil(lr);  rw=pow(2,lr);  hr=rw/2;  h=hr;

  if(rw==2)
  { printf("\n\n");
    //for(i=0;i<2;i++,printf("||")) for(j=0;j<2;j++)   printf("%4d",a[i][j]);
    //printf("\n");
    //for(i=0;i<2;i++,printf("||")) for(j=0;j<2;j++)   printf("%4d",b[i][j]);

    p = (a[0][0]+a[1][0])*(b[0][0]+b[0][1]);
    q = (a[0][1]+a[1][1])*(b[1][0]+b[1][1]);
    r = (a[0][0]-a[1][1])*(b[0][0]+b[1][1]);
    s = (a[0][0])*(b[0][1]-b[1][1]);
    t = (a[1][0]+a[1][1])*(b[0][0]);
    u = (a[0][0]+a[0][1])*(b[1][1]);
    v = (a[1][1])*(b[1][0]-b[0][0]);
    nom+=7;
    noa+=10;
    c[0][0]=q+r-u-v;
    c[0][1]=s+u;
    c[1][0]=t+v;
    c[1][1]=p-r-s-t;
    noa+=8;
    printf("\n");
    for(i=0;i<2;i++,printf("||"))
      for(j=0;j<2;j++)
	printf("%4d",c[i][j]);
   }
  else
  {  //  T1 = A+C                     T2 = E+F	      M1= (A+C)*(E+F)
  sum(a,a,t1,h,0,0,1,0);    sum(b,b,t2,h,0,0,0,1);    smm(t1,t2,m1,h);
  //  T1 = B+D                     T2 = G+H	      M2= (B+D)*(G+H)
  sum(a,a,t1,h,0,1,1,1);    sum(b,b,t2,h,1,0,1,1);    smm(t1,t2,m2,h);
  //  T1 = A-D                     T2 = E+H	      M3= (A-D)*(E+H)
  dif(a,a,t1,h,0,0,1,1);    sum(b,b,t2,h,0,0,1,1);    smm(t1,t2,m3,h);
  //  T1 = A                     T2 = F-H	      M4= (A)*(F+H)
  same(a,t1,h,0,0);         dif(b,b,t2,h,0,1,1,1);    smm(t1,t2,m4,h);
  //  T1 = C+D                     T2 = E	      M5= (C+D)*(E)
  sum(a,a,t1,h,1,0,1,1);    same(b,t2,h,0,0);         smm(t1,t2,m5,h);
  //  T1 = A+B                     T2 = H	      M6= (A+B)*(H)
  sum(a,a,t1,h,0,0,0,1);    same(b,t2,h,1,1);         smm(t1,t2,m6,h);
  //  T1 = D                     T2 = G-E	      M7= (D)*(G-E)
  same(a,t1,h,1,1);	    dif(b,b,t2,h,1,0,0,0);    smm(t1,t2,m7,h);


  //  T1 = M2+M3                     T2 = M6+M7	       COO = M2+M3-M6-M7
  sum(m2,m3,t1,h,0,0,0,0);  sum(m6,m7,t2,h,0,0,0,0);  dif(t1,t2,op1,h,0,0,0,0);
  //  CO1 = A+C
  sum(m4,m6,op2,h,0,0,0,0);
  //  C10 = M5+M7
  sum(m5,m7,op3,h,0,0,0,0);
  //  T1 = M1-M3                     T2 = M6+M7	       COO = M1-M3-M4-M5
  dif(m1,m3,t1,h,0,0,0,0); sum(m4,m5,t2,h,0,0,0,0);  dif(t1,t2,op4,h,0,0,0,0);

  for(i=0;i<h;i++)
   for(j=0;j<h;j++)
    {  c[i][j]=op1[i][j];       c[i][j+h]=op2[i][j];
       c[i+h][j]=op3[i][j];     c[i+h][j+h]=op4[i][j];
    }
  }
  return nom;
}
int main()
{  int i,j,n,nm;
   int r1,c1,r2,c2;
   int m3[8][8],m1[8][8],m2[8][8];

   printf("Enter the dim.s of matrix 1 : ");// [both of same dim.s n x n]");
   scanf("%d %d",&r1,&c1);

   for(i=0;i<max;i++)   for(j=0;j<max;j++)
     { m1[i][j]=0; m2[i][j]=0;m3[i][j]=0;}

   printf("Enter the Elements of Matrix 1");
   for(i=0;i<r1;i++)    for(j=0;j<c1;j++)     scanf("%d",&m1[i][j]);

   printf("Enter the dim.s of matrix 2: ");// [both of same dim.s n x n]");
   scanf("%d %d",&r2,&c2);
   printf("Enter the Elements of Matrix 2");
   for(i=0;i<r2;i++)  for(j=0;j<c2;j++)     scanf("%d",&m2[i][j]);

   n=maxi(r1,c1,r2,c2);

   nm=smm(m1,m2,m3,n);

   printf("\nNo. of Mult.s :%d \n",nm);
   printf("\nProd:\n");
   for(i=0;i<n;i++)
    { printf("\n");
      for(j=0;j<n;j++)  printf("%5d",m3[i][j]);
    }
   
    
}