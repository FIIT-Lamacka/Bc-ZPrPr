#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void nacitanie(char *p_povodny);
void vypis(char *p_povodny);
void uprava(char *p_povodny, char *p_upraveny, int povodny_l, int *p_bola_upravena);
void vypis_upravena(char povodny[], int upraveny);
void dana_dlzka(char povodny[], int dlzka);
void histogram(char upraveny[], int upraveny_l, int bola_upravena);

int main() {
    int end=0,right,i,povodny_l,upraveny_l,bola_upravena=0;
    char prikaz, povodny[1000], upraveny[1000];

    for(i=0;i<1000;i++){
        upraveny[i]='\0';
        povodny[i]='\0';
    }
    while(1){
        prikaz = getchar();
        prikaz=tolower(prikaz);
        povodny_l =strlen(povodny);
        upraveny_l =strlen(upraveny);



        switch(prikaz) {
            case 'n' :
                nacitanie(povodny);
                break;


            case 'v'  :
                vypis(povodny);
                break;


            case 'u'  :
                uprava(povodny,upraveny,povodny_l,&bola_upravena);
                break;


            case 's'  :
                vypis_upravena(upraveny,bola_upravena);
                break;


            case 'd'  :
                dana_dlzka(povodny,povodny_l);
                break;


            case 'h'  :
                histogram(upraveny, upraveny_l, bola_upravena);
                break;


            case 'c'  :
                printf("Vypis");
                break;


            case 'k'  :
                printf("Ukoncujem program...");
                return 0;
                break;
        }



        if(prikaz != '\n' && prikaz != 'n' && prikaz != 'v' && prikaz != 'u' && prikaz != 's' && prikaz != 'd' && prikaz != 'h' && prikaz != 'c'){
            printf("Zadali ste zle pismeno\n");
        }
    }
    return 0;
}

void nacitanie(char *p_povodny){
    FILE *fr;
    int i=0;
    char c;

    if ((fr = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}

	while (c = getc(fr), feof(fr) == 0 && i<1000){
      *p_povodny=c;
        p_povodny++;
    }

    if (fclose(fr) == EOF)
      printf("Subor vstup.txt sa nepodarilo zatvorit.\n");



}

void vypis(char *p_povodny){
    printf("%s\n",p_povodny);
}

void uprava(char p_povodny[], char *p_upraveny, int povodny_lenght, int *p_bola_upravena){
    int i,j=0,lenght;
    char help=0;

    for(i=0;i<povodny_lenght;i++){
       if(p_povodny[i]>='a'&&p_povodny[i]<='z'||p_povodny[i]>='A'&&p_povodny[i]<='Z'){
            *p_bola_upravena=1;
            *(p_upraveny+j)=toupper(p_povodny[i]);
            j++;
       }
    }
}
void vypis_upravena(char povodny[], int upraveny){
    if(upraveny==1){
        printf("%s\n",povodny);
    }
    else{
        printf("Nie je k dispozicii upravena sprava\n");
    }
}
void dana_dlzka(char povodny[],int dlzka){
    int num,i=0,j=0,count=0,k;
    char vypis[dlzka];
    scanf("%d",&num);

    while(i<(dlzka+1)){
        vypis[j]=povodny[i];

        if(povodny[i]=='\0' || povodny[i]==' ' || povodny[i]=='\n' ){

            if(count==num){
                printf("%s\n",vypis);
            }

            count=-1;
            for(k=0;k<dlzka+1;k++){
                vypis[k]='\0';

            }

            j=-1;
        }
        count++;


        j++;
        i++;
    }

}

void histogram(char upraveny[], int upraveny_l,int bola_upravena){
    int pocet[26], total,i,j, highest_zaok=0;
    float priemer[26],highest=0;

    if(bola_upravena==0){
        printf("Nie je k dispozicii upravena sprava\n");
        return;
    }
    //NULOVANIE POLA
    for(i=0;i<26;i++){
        pocet[i]=0;
        priemer[i]=0;
    }
    //NACITANIE HODNOT Z UPRAVENEHO DO POLA POCET
    for(i=0;i<upraveny_l;i++){
        pocet[(upraveny[i]-'A')]++;
    }
    //VYPOCET PERCENT
    for(i=0;i<26;i++){
        priemer[i]=((float)pocet[i]/(float)upraveny_l)*100;
    }


    for(i=0;i<26;i++){
        if(priemer[i]>highest){
            highest=priemer[i];
        }
    }
    if(highest<10){
        highest=11;
    }
    highest/=10;
    highest=floor(highest);


    for(i=0;i<(highest)+1;i++){

        for(j=0;j<26;j++){
            if(priemer[j]/10>(highest-i)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");

    }

    printf("\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
}
