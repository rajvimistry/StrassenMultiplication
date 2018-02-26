#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

int n = 0;
static void strassensMultiplication(int size,float matrixA[size][size], float matrixB[size][size],int original_size);
static void multiplication(int size,float matrixA[size][size], float matrixB[size][size], float matrixC[size][size], int count,int original_size);
static void standardMultiplication(int size,float mA[size][size], float mB[size][size],int original_size);
void main(int argc, char *argv[])
{
	bool isPowerof2=true;
	n = atoi(argv[1]);
	float a[n][n], b[n][n];
	int n1 = atoi(argv[1]);
	if(n != 0 && (n & (n-1)) == 0) {isPowerof2 = true;}
  	else {isPowerof2 = false;}
	int i=0, temp2;
	srand((int)time(NULL));

	//Random Number Generation
	for(i=0;i<n1;i++)
	{	int j;
		for(j=0;j<n1;j++)
		{	
			float random = -5.0+2.0f * ((float)rand()/(float)RAND_MAX * 5);
			a[i][j] = random;
			random = -5.0+2.0f * ((float)rand()/(float)RAND_MAX * 5);
			b[i][j] = random;
		}
	}
	
	//print the randomaly generated matrix	
	printf("\nA:\n");
	for(i=0;i<n1;i++)
	{int j;
		for(j=0;j<n1;j++){printf("%0.2f ",a[i][j]);}printf("\n");
	}
	printf("\nB:\n");
	for(i=0;i<n1;i++)
	{int j;
		for(j=0;j<n1;j++){printf("%0.2f ",b[i][j]);}printf("\n");
	}

	//if k is power of 2 apply multiplication
	if(isPowerof2 == true){
	strassensMultiplication(n1,a,b,n1);
	printf("\nStandard Multiplication Output: \n");
	standardMultiplication(n1,a,b,n1);}
	
	//if k is not power of 2 than append 0 and apply multiplication
	if(isPowerof2==false)
	{
		int temp,i,j;
		temp2=n1;
		l1: n1++;temp=n1;
		if(n1 != 0 && (n1 & (n1-1)) == 0) {}
		else{n1=temp;goto l1;}
	
	float a1[n1][n1],b1[n1][n1];
	for(i=0;i<n1;i++)
	{int j;
		for(j=0;j<n1;j++)
		{a1[i][j] = 0.000000;b1[i][j]=0.000000;}
	}
	for(i=0;i<temp2;i++)
	{int j;
		for(j=0;j<temp2;j++)
		{a1[i][j] = a[i][j];b1[i][j]=b[i][j];}
	}
	strassensMultiplication(n1,a1,b1,temp2);

	printf("\nStandard Multiplication Output: \n");
	standardMultiplication(n1,a1,b1,temp2);
	}
}


//strassenMultiplication
void strassensMultiplication(int s,float matA[s][s], float matB[s][s],int original_size)
{
	float matC[s][s];
	printf("\nStrassen's Multiplication output:\n");int count = 0;

	//multiplication function that recursively calls and perform multiplication based on strassen's algorithm
	multiplication(s,matA,matB,matC,count,original_size);
}
void multiplication(int size,float matrixA[size][size], float matrixB[size][size], float matrixC[size][size],int count,int original_size)
{
	float result[size][size];
	count++;

	if(size==1)
	{result[0][0] = matrixA[0][0]*matrixB[0][0];}

	else
	{
		//devide the matrix into n/2

		//matrix A11
		int i1,j1;
		float A11[size/2][size/2];
		int i2=0;
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=0;
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				A11[i1][j1] = matrixA[i2][j2];
			}
		}

		//matrix A12
		float A12[size/2][size/2];
		i2=0;
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=(size/2);
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				A12[i1][j1] = matrixA[i2][j2];
			}
		}

		//matrix A21
		float A21[size/2][size/2];
		i2=(size/2);
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=0;
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				A21[i1][j1] = matrixA[i2][j2];
			}
		}


		//matrix A22
		float A22[size/2][size/2];
		i2=(size/2);
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=(size/2);
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				A22[i1][j1] = matrixA[i2][j2];
			}
		}
			
		//Matrix B11
		float B11[size/2][size/2];
		i2=0;
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=0;
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				B11[i1][j1] = matrixB[i2][j2];
			}
		}

		//Matrix B12
		float B12[size/2][size/2];
		i2=0;
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=(size/2);
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				B12[i1][j1] = matrixB[i2][j2];
			}
		}

		//Matrix B21
		float B21[size/2][size/2];
		i2=(size/2);
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=0;
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				B21[i1][j1] = matrixB[i2][j2];
			}
		}


		//Matrix B22
		float B22[size/2][size/2];
		i2=(size/2);
		for(i1=0;i1<(size/2);i1++,i2++)
		{int j2=(size/2);
			for(j1=0;j1<(size/2);j1++,j2++)
			{
				B22[i1][j1] = matrixB[i2][j2];
			}
		}


		//compute M1
		float temp1[size/2][size/2], temp2[size/2][size/2], M1[size/2][size/2], M2[size/2][size/2], M3[size/2][size/2], M4[size/2][size/2], M5[size/2][size/2], M6[size/2][size/2], M7[size/2][size/2];


		float temp3[size/2][size/2],temp4[size/2][size/2], temp5[size/2][size/2], temp6[size/2][size/2], temp7[size/2][size/2], temp8[size/2][size/2], temp9[size/2][size/2], temp10[size/2][size/2];
		int k,l,m; float sum=0;
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp1[k][l] = A11[k][l] + A22[k][l];
				temp2[k][l] = B11[k][l] + B22[k][l];
			}
		}
	
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + temp1[k][m] * temp2[m][l];
				}M1[k][l] = sum;sum=0;
			}
		}
		sum = 0;

		//compute M2
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp3[k][l] = A21[k][l] + A22[k][l];
			}
		}

		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + temp3[k][m] * B11[m][l];
				}M2[k][l] = sum;sum=0;
			}
		}
		sum = 0;
		//compute M3
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp4[k][l] = B12[k][l] - B22[k][l];
			}
		}
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + A11[k][m] * temp4[m][l];
				}M3[k][l] = sum;sum=0;
			}
		}
		sum=0;
		//compute M4
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp5[k][l] = B21[k][l] - B11[k][l];
			}
		}
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + A22[k][m] * temp5[m][l];
				}M4[k][l] = sum;sum=0;
			}
		}sum=0;
		//compute M5
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp6[k][l] = A11[k][l] + A12[k][l];
			}
		}sum=0;
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + temp6[k][m] * B22[m][l];
				}M5[k][l] = sum;sum=0;
			}
		}sum=0;
		//compute M6
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp7[k][l] = A21[k][l] - A11[k][l];
				temp8[k][l] = B11[k][l] + B12[k][l];
			}
		}
	
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + temp7[k][m] * temp8[m][l];
				}M6[k][l] = sum;sum=0;
			}
		}
		sum=0;
		//compute M7
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp9[k][l] = A12[k][l] - A22[k][l];
				temp10[k][l] = B21[k][l] + B22[k][l];
			}
		}
	
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				for(m=0;m<(size/2);m++)
				{
					sum = sum + temp9[k][m] * temp10[m][l];
				}M7[k][l] = sum;sum=0;
			}
		}

		//Recursive Calls
		multiplication((size/2),temp1,temp2,M1,count,original_size);
		multiplication((size/2),temp3,B11,M2,count,original_size);
		multiplication((size/2),A11,temp4,M3,count,original_size);
		multiplication((size/2),A22,temp5,M4,count,original_size);
		multiplication((size/2),temp6,B22,M5,count,original_size);
		multiplication((size/2),temp7,temp8,M6,count,original_size);
		multiplication((size/2),temp9,temp10,M7,count,original_size);

		//compute c11
		float temp11[size/2][size/2], temp12[size/2][size/2], c11[size/2][size/2], c12[size/2][size/2], c21[size/2][size/2], c22[size/2][size/2];
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp11[k][l] = M1[k][l] + M4[k][l];
				temp12[k][l] = temp11[k][l] - M5[k][l];
				c11[k][l] = temp12[k][l] + M7[k][l];
			}
		}

		//compute c22
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				temp11[k][l] = M1[k][l] + M3[k][l];
				temp12[k][l] = temp11[k][l] - M2[k][l];
				c22[k][l] = temp12[k][l] + M6[k][l];
			}
		}

		//compute c12
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				c12[k][l] = M3[k][l] + M5[k][l];
			}
		}

		//compute c21
		for(k=0;k<(size/2);k++)
		{
			for(l=0;l<(size/2);l++)
			{
				c21[k][l] = M2[k][l] + M4[k][l];
			}
		}

		//join C11, C12, C21, C22
		int j2;
		for(i1=0,i2=0;i1<size/2;i1++,i2++)
		{
			for(j1=0,j2=0;j1<size/2;j1++,j2++)
			{
				result[i2][j2] = c11[i1][j1];
			}
		}

		for(i1=0,i2=0;i1<size/2;i1++,i2++)
		{
			for(j1=0,j2=size/2;j1<size/2;j1++,j2++)
			{
				result[i2][j2] = c12[i1][j1];
			}
		}
		
		for(i1=0,i2=size/2;i1<size/2;i1++,i2++)
		{
			for(j1=0,j2=0;j1<size/2;j1++,j2++)
			{
				result[i2][j2] = c21[i1][j1];
			}
		}

		for(i1=0,i2=size/2;i1<size/2;i1++,i2++)
		{
			for(j1=0,j2=size/2;j1<size/2;j1++,j2++)
			{
				result[i2][j2] = c22[i1][j1];
			}
		}

		//print the resultant matrix
		if(count == 1){
		for(i1=0;i1<original_size;i1++)
		{for(j1=0;j1<original_size;j1++){printf("%.2f ",result[i1][j1]);}printf("\n");}}
	}
	
}


//Standard Multiplication
void standardMultiplication(int size,float mA[size][size], float mB[size][size],int original_size)
{
	float mC[original_size][original_size];
	int i,j,k;
	float sum=0.000000;

	//Multiplication
	for(i=0;i<original_size;i++)
	{
		for (j=0;j<original_size;j++)
		{
        		for(k=0;k<original_size;k++)
		        {
          			sum = sum + mA[i][k]*mB[k][j];
        		}
			mC[i][j] = sum;
		        sum = 0;
      		}
	}

	//print the matrix
	for(i=0;i<original_size;i++)
	{
		for(j=0;j<original_size;j++)
		{printf("%.2f ",mC[i][j]);}printf("\n");
	}

}
