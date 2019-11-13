#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void nacitanie(char *p_povodny);
void vypis(char *p_povodny);
void uprava(char *p_povodny, char *p_upraveny);

int main() {
    int end=0,right,i;
    char prikaz, povodny[1000], upraveny[1000];

    while(1){
        prikaz = getchar();
        prikaz=tolower(prikaz);



        switch(prikaz) {
            case 'n' :
                nacitanie(povodny);
                break;


            case 'v'  :
                vypis(povodny);
                break;


            case 'u'  :
                uprava(povodny,upraveny);
                break;


            case 's'  :
                printf("Vypis");
                break;


            case 'd'  :
                printf("Vypis");
                break;


            case 'h'  :
                printf("Vypis");
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

    printf("\n===============\nUspesne nacitane\n===============\n\n");

}

void vypis(char *p_povodny){
    printf("\n===============\nObsah povodneho pola\n===============\n\n");
    printf("%s\n",p_povodny);
    printf("\n===============\n");
    return 0;
}

void uprava(char *p_povodny, char *p_upraveny){
    int i, empty=1,j=0,lenght;
    char help=0;
    lenght = sizeof(*p_povodny);
    printf("%d",lenght);


    for(i=0;i<strlen(p_povodny);i++){
        ;
    }
}
