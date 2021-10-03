#include <stdio.h>

    double file (char file1[20], double x){
    FILE *f;
    
    int n = 0;
    double minimumX;
    double m;
    double c;
    double C;
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;
    
    int bufferX;
    int bufferY;
   
    double numberX[256];
    double numberY[256];
    
	

    f = fopen(file1, "r");
    if(f){
        while(!feof(f)){
            fscanf(f, "%d,%d",&bufferX,&bufferY);
            n ++;
            
            numberX [n] = bufferX;
            numberY [n] = bufferY;
            
        }
        
    }
    fclose(f);
    
    for (int i = 0; i <= n; i++){
        sumX = sumX + numberX[i];
        sumY = sumY + numberY[i];
        sumX2 = sumX2 + (numberX[i] * numberX[i]);
        sumXY = sumXY + (numberX[i] * numberY[i]);
    }
    
    c=((sumX2*sumY-sumX*sumXY)*1/(n*sumX2-sumX*sumX)*1);
    m=((n*sumXY-sumX*sumY)*1.0/(n*sumX2-sumX*sumX)*1.0);
    
    minimumX = (0 - c)/m;
    
    if (x < minimumX){
        
        printf("The x value given is below the minimum x value which is %lf when y = 0\n",minimumX);   
        
    } else {
        
       printf("The x value given is above the minimum x value which is %lf when y = 0\n",minimumX);
    }
    
    
    printf("n = %d\n",n);
    printf("Y = %f", m);
    printf("X + %f", c);
   
}

void main()
{
    double x1;
    char str[20];
printf("Enter a filename to scan:");
scanf("%[^\n]%*c", str);
printf("Enter an x value:");
scanf("%lf", &x1);
  
    file(str ,x1);
    
}

