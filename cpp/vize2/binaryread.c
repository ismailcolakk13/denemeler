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
    cfptr= fopen("binarytest.txt","rb+");
    struct student ogr1={"İsmail","Colak",24,"CENG"};
    struct student ogr2={"Mehmet","Caliskan",25,"CENG"};
    struct student ogr3={"Yusuf","Aykurt",26,"CENG"};
    if(cfptr!=NULL){
        fwrite(&ogr1,sizeof(struct student),1,cfptr);
        fwrite(&ogr2,sizeof(struct student),1,cfptr);
        fwrite(&ogr3,sizeof(struct student),1,cfptr);
        printf("Yazma tamamlandı\n");
        rewind(cfptr);
        struct student temp[3];
        for(int i=0;i<3;i++){
            fread(&temp[i],sizeof(struct student),1,cfptr);
        }
        printf("%s %s %s \n",temp[0].ad,temp[1].ad,temp[2].ad);
        rewind(cfptr);
        fseek(cfptr,2*sizeof(struct student),SEEK_SET);
        struct student temp2;
        fread(&temp2,sizeof(struct student),1,cfptr);
        printf("%s",temp2.ad);

    }
    else{
        printf("Dosya aciliminda hata!");
    }
    fclose(cfptr);
    return 0;
}