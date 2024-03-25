#include <stdio.h>
#include <string.h>
struct student
{
    char ad[20];
    char soyad[20];
    int ogrno;
    char bolum[20];
};
int main(){
    FILE* cfptr;
    cfptr= fopen("newtext.txt","w");//Dosyaya yazma bölümü
    struct student liste[5];
    strcpy(liste[0].ad,"Ali");
    strcpy(liste[0].soyad,"Yildirim");
    liste[0].ogrno=120;
    strcpy(liste[0].bolum,"Endustri");    
    strcpy(liste[1].ad,"Muhibbi");
    strcpy(liste[1].soyad,"Suleyman");
    liste[1].ogrno=121;
    strcpy(liste[1].bolum,"Bilgisayar");
    strcpy(liste[2].ad,"Veli");
    strcpy(liste[2].soyad,"Kara");
    liste[2].ogrno=122;
    strcpy(liste[2].bolum,"Insaat");
    strcpy(liste[3].ad,"Zeki");
    strcpy(liste[3].soyad,"Yalin");
    liste[3].ogrno=123;
    strcpy(liste[3].bolum,"Makine");
    strcpy(liste[4].ad,"Fikri");
    strcpy(liste[4].soyad,"Yilmaz");
    liste[4].ogrno=124;
    strcpy(liste[4].bolum,"Isletme");


    if(cfptr!=NULL){
        fprintf(cfptr,"%-10s%-10s%-15s%-10s\n","Ad","Soyad","Ogrenci No","Bolum");
        for(int i=0;i<5;i++){
        fprintf(cfptr,"%-10s%-10s%-15d%-10s\n",liste[i].ad,liste[i].soyad,liste[i].ogrno,liste[i].bolum);
        }
    }
    else{
        printf("Dosya açılamadı");
    }
    fclose(cfptr);
    printf("Dosyaya yazma tamamlandı\n");

    //Dosyada öğrenci numarası ile sorgulama bölümü
    int arananNo;
    printf("Ogrenci numarası ile sorgu:\n");
    scanf("%d",&arananNo);
    cfptr=fopen("newtext.txt","r");
    if(cfptr==NULL){
        printf("dosya acilamadi\n");
    }
    char ad[10],soyad[10],bolum[20];
    int ogrno2;
    char baslik[100];
    fscanf(cfptr,"%s",baslik);//ilk satırdan kurtulma
    while(!feof(cfptr)){
        fscanf(cfptr,"%s%s%d%s",ad,soyad,&ogrno2,bolum);
        if(ogrno2==arananNo){
            printf("%-20s\n%-10s%-10s%-10d%-10s\n","Aradiginiz ogrencinin bilgileri:",ad,soyad,ogrno2,bolum);
        }      
    }
    fclose(cfptr);
    return 0;
}