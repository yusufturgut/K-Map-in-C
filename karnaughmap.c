#include <stdio.h>
#include <conio.h>


int main(){

    int y, i, mod_y, index[8];
    printf("\t************ HOSGELDINIZ ************     (CREATE BY YUSUF TURGUT / 1180505055)\n");
     printf("  Lutfen Tum Durumlari 'SADECE' 1(bir) ya da 0(sifir) Olarak Giriniz.  \n");
     printf("\n");

    for (y=0;y<8;y++){
        printf("  m%d= ",y);
        scanf("  %d",&index[y]);
    }
   printf("\t\t\t Karnough Haritasi Indirgeme \n\n\t");
    printf(" \t  A / BC  \t00\t01\t11\t10\n");
    printf(" \t                  \t__\t__\t__\t__\n");
   printf("\t....................................................\n\t\t");

    for(i=1;i<=8;i++){
        mod_y=i%4;

        if(i==1){
    int temp1;
    temp1=index[2];
    index[2]=index[3];
    index[3]=temp1;
            printf("   0||  \t");
        }
        else if(i==5) {

            printf("   1||  \t");
        }

        printf("%d\t",index[i-1]);
       if (mod_y==0){



    int temp;
    temp=index[7];
    index[7]=index[6];
    index[6]=temp;




            printf("\n\t....................................................\n\t\t");
        }
    }


    printf("\n Sonuc f(A,B,C)= ");
    sonuc(index-1);

    printf("\n");

}

int tek (int a){

      switch(a){

        case 1:
            printf("A'B'C'");
            break;
        case 2:
            printf("A'B'C");
            break;
        case 3:
            printf("A'BC'");
            break;
        case 4:
            printf("A'BC'");
            break;
        case 5:
            printf("AB'C'");
            break;
        case 6:
            printf("AB'C");
            break;
        case 7:
            printf("ABC");
            break;
        case 8:
            printf("ABC'");
            break;


      }
    return 0;
}

int cift(int a,int b){

    if((a==1) && (b==2) ) {
        printf("A'B'");
        return 1;
    }
    else if((a==1) && (b==5) ) {
        printf("B'C'");
        return 1;
    }
    else if((a==1) && (b==4) ) {
        printf("A'C'");
        return 1;
    }
    else if((a==2) && (b==3) ) {
        printf("AC'");
        return 1;
    }
    else if((a==2) && (b==6) ) {
        printf("B'C");
        return 1;
    }
    else if((a==3) && (b==7) ) {
        printf("BC");
        return 1;
    }
    else if((a==4) && (b==8) ) {
        printf("BC'");
        return 1;
    }
    else if((a==5) && (b==8) ) {
        printf("ABC'");
        return 1;
    }
    else if((a==6) && (b==7) ) {
        printf("AC'");
        return 1;
    }
    else{
        tek(a);
        printf(" + ");
        tek(b);
    }
}

int dorder(int a, int b, int c, int d){

    if( (a==1) && (b==2) && (c==3) && (d==4) ) printf("A'");
else if( (a==5) && (b==6) && (c==7) && (d==8) ) printf("A");
else if( (a==1) && (b==2) && (c==5) && (d==6) ) printf("B'");
else if( (a==3) && (b==4) && (c==7) && (d==8) ) printf("B");
else if( (a==1) && (b==3) && (c==5) && (d==7) ) {


    cift(a,c);
    printf(" + ");
    cift(b,d);
}
else if( (a==2) && (b==4) && (c==6) && (d==8) ) {


    cift(a,c);
    printf(" + ");
    cift(b,d);
}
else if( (a==1) && (b==3) && (c==7) && (d==8) ) {


    cift(a,d);
    printf(" + ");
    cift(b,c);
}
else if( (a==1) && (b==3) && (c==5) && (d==7) ) {


    cift(a,c);
    printf(" + ");
    cift(b,d);
}
else {
    cift(a,b);
    printf(" + ");
    cift(c,d);
}

}

int sonuc(int deger[]){
    int toplam=0, i, a[8], n=0;

    for(i=1;i<8;i++){
        if(deger[i]==1){
            toplam++;
            n++;
            a[n]=i;

        }
    }

    switch(toplam){
        case 0:
             printf("Tum degerler 0(sifir) olamaz!");
            break;
        case 1:
            tek(a[1]);
            break;
        case 2:
            cift(a[1],a[2]);
            break;
        case 3:
            cift(a[1],a[2]);
             printf(" = ");
            tek(a[3]);
            break;
        case 4:
            dorder(a[1],a[2],a[3],a[4]);
            break;
        case 5:
            dorder(a[1],a[2],a[3],a[4]);
             printf(" + ");
            tek(a[5]);
            break;
        case 6:
            dorder(a[1],a[2],a[3],a[4]);
            printf(" + ");
            cift(a[5],a[6]);
            break;
        case 7:
            dorder(a[1],a[2],a[3],a[4]);
             printf(" + ");
            cift(a[5],a[6]);
             printf(" + ");
            tek(a[1]);
            break;
        case 8:
             printf("B' + B");
            break;


    }
getch();
}

