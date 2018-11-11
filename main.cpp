#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator () {
    srand(time(NULL));
}
int karteziehen(){
    int zufall = rand () %9 + 2;
    return zufall;
}
int main() {
    initializegenerator();
    const int erste_Karte=karteziehen();
    printf("Erste Karte: %i\n\n",erste_Karte);
    int kartensumme_spieler=0;
    int kartensumme_dealer=erste_Karte;
    int aktuelle_karte;
    while (true){
        int ja_nein;
        printf("Ihre aktuelle Summe lautet %i.\nWollen sie eine weitere Karte ziehen, so geben sie 1 ein.\n"
        "Wollen sie keine weitere Karte ziehen und den Zug somit beenden, so geben sie 0 ein.\n",kartensumme_spieler);
        scanf("%i",&ja_nein);
        if (ja_nein==0){
            break;
        }
        if(ja_nein!=1) {
            ja_nein=1;
            printf("Bitte geben sie entweder 1 oder 0 ein.\n\n");
            continue;
        }
        aktuelle_karte=karteziehen();
        kartensumme_spieler+=aktuelle_karte;
        printf("Sie haben eine %i gezogen.\n",aktuelle_karte);
        if (kartensumme_spieler>21){
            break;
        }
    }
    printf("Sie haben eine Summe von %i ereicht.\n\n",kartensumme_spieler);
    if (kartensumme_spieler<=21) {
        while (true){
            int weiter;
            printf("Bitte geben sie eine Zahl ein, um zum nächsten Zug zu springen\n\n");
            scanf("%i",&weiter);
            aktuelle_karte = karteziehen();
            kartensumme_dealer+=aktuelle_karte;
            printf("Der Dealer hat eine %i gezogen.\n"
                           "Die aktuelle Summe des Dealers lautet %i.\n",aktuelle_karte,kartensumme_dealer);
            if(kartensumme_dealer>=16) {
                break;
            }
        }
        printf("Der Dealer hat die 16 überschritten.\n\n\n");
        if (kartensumme_dealer>21 || kartensumme_dealer < kartensumme_spieler) {
            printf("Der Spieler gewinnt.\n");
        }
        else if (kartensumme_dealer==kartensumme_spieler){
            printf("Unentschieden.\n");
        }
        else {
            printf("Der Spieler verliert.\n");
        }
    }
    else {
        printf("\nDer Spieler verliert.\n");
    }
    return 0;
}