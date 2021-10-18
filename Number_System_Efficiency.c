#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

int romantodecimal(char roman[35]){
    int r1[20], rs=0, z=0; // roman to decimal numbers
    for (int i = 0; i <= strlen(roman); i++)
    {
        if     (roman[i]=='M') {r1[i]=1000;}
        else if(roman[i]=='D') {r1[i]=500;}
        else if(roman[i]=='C') {r1[i]=100;}
        else if(roman[i]=='L') {r1[i]=50;}
        else if(roman[i]=='X') {r1[i]=10;}
        else if(roman[i]=='V') {r1[i]=5;}
        else                    {r1[i]=1;}
    }
    for (int i = 1; i < strlen(roman); i++)
    {
        z=i;
        if(r1[i]>r1[i-1] ){rs-=r1[i-1];}
        else { rs+=r1[i-1];}
    }
    rs+=r1[z];
    printf("%s = %d     ", roman, rs);
    return rs;
}

int main()
{
    printf("__________ C PROGRAM TO CHECK EFFICIENCY OF 4 NUMBER SYSTEMS IN ADDITION AND SUBTRACTION __________\n");

    long long int n1, n2;
    char roman1[35], roman2[35], roman3[35]="", roman4[35]="";
    char unary1[30], unary2[30];
    char binary1[30]="", binary2[30]="", binary3[62]="", binary4[62]="";

    ////// DECIMAL //////////////////////////////////////////////////////

    printf("\nDECIMAL NUMBERS !\n     Enter decimal numbers : ");
    scanf("%lld %lld", &n1, &n2);
    printf("    Decimal : %lld %lld\n", n1, n2);

    long long t1;
    clock_t start1,end1;
        start1=clock();
            printf("    n1+n2 = %lld", n1+n2);
        end1=clock();
        t1=end1-start1;
        printf("\n    Total time elapsed for Decimal Addition : %.3f    milli_seconds\n",1000*(double)t1/(double)CLOCKS_PER_SEC);
 
        start1=clock();
            printf("    n1*n2 = %lld", n1*n2);
        end1=clock();
        t1=end1-start1;
        printf("\n    Total time elapsed for Decimal Multiplication       : %.3f    milli_seconds\n",1000*(double)t1/(double)CLOCKS_PER_SEC);

    ////// ROMAN //////////////////////////////////////////////////////

    printf("\nROMAN NUMBERS !\n     Enter roman numbers (I V X L C D M) (upto 20 digits only !) : ");
    scanf("%s %s", roman1, roman2);
    printf("    Roman : %s %s\n", roman1, roman2);
    clock_t start2,end2;
    long long t2;
        start2=clock();
            int d1=-10, d2=-10;
            d1=romantodecimal(roman1);
            d2=romantodecimal(roman2);
            printf("%s + %s = %d", roman1, roman2, d1+d2);
        end2=clock();
        t2=end2-start2;
        printf("\n    Total time elapsed for Roman addition : %.03f milli_seconds\n",1000*(double)t2/(double)CLOCKS_PER_SEC);
        
        start2=clock();
            d1=-10, d2=-10;
            d1=romantodecimal(roman1);
            d2=romantodecimal(roman2);
            printf("%s * %s = %d", roman1, roman2, d1*d2);
        end2=clock();
        t2=end2-start2;
        printf("\n    Total time elapsed for Roman multiplication : %.03f milli_seconds\n",1000*(double)t2/(double)CLOCKS_PER_SEC);
    

    ////// UNARY //////////////////////////////////////////////////////

    printf("\nUNARY NUMBERS !\n     Enter unary numbers ( use 'I' only ! ) : ");
    scanf("%s %s", unary1, unary2);
    printf("    Unary : %s %s\n", unary1, unary2);

    long long t3;
    clock_t start3,end3;
        start3=clock();
            printf("    %s + %s = %s%s\n", unary1, unary2, unary1, unary2);
        end3=clock();
        t3=end3-start3;
        printf("    Total time elapsed for Unary Addition       : %.3f milli_seconds\n\n", 1000*(double)t3/(double)CLOCKS_PER_SEC);

        start3=clock();
            printf("    %s * %s = ", unary1, unary2);
            for (int i = 0; i < strlen(unary1)*strlen(unary2); i++)
            {
                printf("I");
            } printf("\n");
        end3=clock();
        t3=end3-start3;
        printf("    Total time elapsed for Unary Multiplication : %.3f milli_seconds\n\n", 1000*(double)t3/(double)CLOCKS_PER_SEC);

    ////// BINARY //////////////////////////////////////////////////////

    printf("\nBINARY NUMBERS !\n     Enter binary numbers : ");
    scanf("%s %s", binary1, binary2);
    long long int b1=0, b2=0, var2=1, sum=0, pro=1;
        
    long long tbd, t4_1, t4_2;
    clock_t start4,end4;
        start4=clock();
            for (int i = strlen(binary1)-1; i >= 0; i--)
            {
                if(binary1[i]=='1'){ b1+= var2;}
                var2*=2;
            }
            var2=1;
            for (int i = strlen(binary2)-1; i >= 0; i--)
            {
                if(binary2[i]=='1'){ b2+= var2;}
                var2*=2;
            }
        end4=clock();
        tbd=start4-end4; // time for conversion only        

        start4=clock();
            sum=b1+b2;
            printf("    %lld + %lld  =  %lld -> ", b1, b2, sum);
            int x=0;
            while(sum>0){
                binary3[x++] = 48 + sum%2; sum/=2;
            }
            printf("%s\n",strrev(binary3));
        end4=clock();
        t4_1=end4-start4 + tbd;  // time for conversion and addition
        printf("    Total time elapsed for Binary addition: %.3f milli_seconds\n\n", 1000*(double)t4_1/ (double)CLOCKS_PER_SEC);
        
        start4=clock();
            pro=b1*b2;
            printf("    %lld * %lld  =  %lld -> ", b1, b2, pro);
            x=0;
            while(pro>0){
                binary4[x++] = 48 + pro%2; pro/=2;
            }
            printf("%s\n", strrev(binary4));
        end4=clock();
        t4_2=end4-start4 + tbd;  // time for conversion and multiplication
        printf("    Total time elapsed for Binary multiplication: %.3f milli_seconds\n\n", 1000*(double)t4_2/ (double)CLOCKS_PER_SEC);

    return 0 ;
}
