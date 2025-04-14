// HedgehogRabbit Code
// licensed under +WTFPL 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mem.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>






void play_note(int frequency, int duration) {
    Beep(frequency, duration);  // Beep: Tonhöhe (Frequenz) und Dauer (in ms)
}

void melodie(){

    
    // Melodie der Super Mario Titelmelodie (einfach)
    // Vereinfachte Frequenzen der Super Mario Melodie (Oktavwerte in Hertz)
    int C4 = 261;  // Mittleres C
    int E4 = 329;  // E
    int G4 = 392;  // G
    int G3 = 196;  // G tiefer Oktave
    int A4 = 440;  // A
    int B4 = 493;  // B
    int F4 = 349;  // F
    int D4 = 293;  // D
    int C5 = 523;  // Höheres C
    
    // Melodie der Super Mario Titelmelodie (einfach)
    play_note(E4, 150);  // E
    Sleep(150);          // Pause 150ms
    play_note(E4, 150);  // E
    Sleep(300);          // Pause 300ms
    play_note(E4, 150);  // E
    Sleep(300);          // Pause 300ms
    play_note(C4, 150);  // C
    Sleep(150);          // Pause 150ms
    play_note(E4, 150);  // E
    Sleep(300);          // Pause 300ms
    play_note(G4, 150);  // G
    Sleep(600);          // Pause 600ms
    play_note(G3, 150);  // Tiefer G
    Sleep(600);          // Pause 600ms

    // Fortsetzung der Melodie
    play_note(C4, 150);  // C
    Sleep(150);          // Pause 150ms
    play_note(G3, 150);  // Tiefer G
    Sleep(150);          // Pause 150ms
    play_note(E4, 150);  // E
    Sleep(150);          // Pause 150ms
    play_note(A4, 150);  // A
    Sleep(150);          // Pause 150ms
    play_note(B4, 150);  // B
    Sleep(150);          // Pause 150ms
    play_note(B4, 150);  // B
    Sleep(150);          // Pause 150ms
    play_note(A4, 150);  // A
    Sleep(150);          // Pause 150ms
    play_note(G4, 150);  // G
    Sleep(150);          // Pause 150ms
    play_note(F4, 150);  // F
    Sleep(150);          // Pause 150ms
    play_note(E4, 150);  // E
    Sleep(150);          // Pause 150ms
    play_note(C5, 150);  // Höheres C
    Sleep(150);          // Pause 150ms
    play_note(C5, 150);  // Höheres C
    Sleep(150);          // Pause 150ms
}

void tutorial(){
    int ZeitTut;
    ZeitTut = 1500;
     printf("In dem Hase und Igel Spiel tritts du gegen zwei \n");
    Sleep(ZeitTut);
    printf("computergesteuerte Spieler an, den Hasen H \n");
    Sleep(ZeitTut);
    printf("und den Igel I. \n");
    Sleep(ZeitTut);
    printf("\n");
    Sleep(ZeitTut);
    printf("Du spielst als Spieler P, dein Ziel ist es zuerst and der Ziellinie zu sein\n");
    Sleep(ZeitTut);
    printf("Du kannst eine Zahl von 1 bis 10 eingeben \n");
    Sleep(ZeitTut);
    printf("Die Zahl die du eingibst gibt an, wieviele Schritte du nach vorne gehst\n");
    Sleep(ZeitTut);
    printf("Doch sei gewarnt ! Je hoeher die Zahl die du eingibst \n");
    Sleep(ZeitTut);
    printf("desto hoeher ist die Gefahr das du diese Zahl nach hinten faellst.\n");
    Sleep(ZeitTut);
    printf("Also sei sehr Vorsichtig mit deiner Taktik\n");
    Sleep(ZeitTut);
    printf("\n");
    Sleep(ZeitTut);
    printf("Viel Spass :)");
    Sleep(10000);
    system("cls");
}



int draw(int hedgehog, int rabbit,int player, int event){            // Funktion die das Feld zeichnet, Herzstück des Codes
    int a;
    char screen[70][5] = {' '};

    if(event == 1){                                        // ungenutzt aber im code für Erweiterungen später
        printf("ouch\n");
    }

    if(event == 2){                                        // Zeichnet das Event 
        printf("AUA! \n");
    }
    a=0;

    for(;a<5;a++){                                          // füllt die Matrix mit Leerzeichen > kein uninitialized memeory + Leerzeichen
        int b;
        b=0;
        for(;b<70;b++){
            screen[b][a] = ' ';
        }
    }

    a=0;
    for(;a<5;a++){                                          // Anfang des Zeichnungsprogrammes
      //  printf("first loop \n ");                         // für debugging
        if(a==0||a==4){                                     // gibt den oberen und unteren Rand in die Matrix
      //      printf("first if \n ");                       // für debugging
            int b;
            for(b = 0; b < 70; b++){
                screen[b][a] = '-';
            }
            screen[70][a] = '\n';
        }

        if(a==1){                                            // gibt die Position des Igels in die Matrix 
      //      printf("second if \n ");                       // für debugging
            screen[0][1] = '-';
            screen[69][1] = '-';
            screen[hedgehog][1] = 'I';
            screen[70][1] = '\n';

        }

                if(a==2){                                   // gibt  die Position des Hasens in die Matrix
      //              printf("third if \n ");               // für debugging
            screen[0][2] = '-';
            screen[69][2] = '-';
            screen[rabbit][2] = 'H';
            screen[70][2] = '\n';                           // \n and die letzte Stelle damit das Zeichnungsprogramm einen Zeilenumbruch macht

        }
                if(a==3){
            screen[0][3] = '-';
            screen[69][3] = '-';
            screen[player][3] = 'P';
            screen[70][3] = '\n'; 
                }


    }
    
    for(int a=0; a < 5; a++){                                   // Zeichnet die Matrix

        for(int b=0;b<70;b++){

            printf("%c", screen[b][a]);
        }

        printf("\n");
    }
    return 1; 
}

int eingabecheck(char eingabe[20]){
    int h;
    h = strlen(eingabe)-1;
    char comma=',';
    char point='.';
    char minus='-';
    char *stop="stop";
    int j = 1;
    int ausgabe;
    int fail = 0;
    int Komma = 0;

    for(;h>-1;h--){
        
        j = j * isdigit(eingabe[h]);
        if(eingabe[h] == comma || eingabe[h] == point){
            printf("Keine Kommazahlen erlaubt");
            Komma = 1;
            Sleep(1000);
            return fail;
        }
        if(eingabe[h]==minus){
            printf("keine Minuszahlen erlaubt");
        }
        if(eingabe[h]=='\n'){
            j = 1;
            h = -1;
        }
        if(strcmp(eingabe,stop)==0){
            break;
        }

    }
    if(j>0 && eingabe != stop){
        sscanf(eingabe,"%d",&ausgabe);
        if(ausgabe > 10){
            printf("Die Zahl ist zu gross");
            Sleep(1000);
            return fail;
        }
        else{
        return ausgabe;
        }
    }
    if(strcmp(eingabe,stop)==0){
        return 1;
    }
    else if(Komma != 1){
        printf("Keine Buchstaben eingeben :(");
        Sleep(1000);
        return fail;
        Komma = 0;
    }
}



int rabbitrules(int random, int rabbitposition){                    // das Regelwerk des Hasens, nimmt die Zufallszahl und die Position des Hasens ein und gibt die neue Position des Hasens Aus

        if(random < 3){
            rabbitposition = rabbitposition;
        }

        if(random > 2 && random < 5){
            rabbitposition = rabbitposition + 9;
        }

        if(random == 5){
            rabbitposition = rabbitposition -12;
        }

        if(random > 5 && random < 9){
            rabbitposition = rabbitposition +1;
        }

        if(random > 8){
            rabbitposition = rabbitposition -2; 
        }

        if(rabbitposition < 1){
            rabbitposition = 2;
        }

        if(rabbitposition > 69){
            rabbitposition = 69;
        }
    
    return rabbitposition;
}


int hedgehogrules(int random, int hedgehogposition){                        // Das selbe wie beim Hasen nur für den Igel

        if(random < 6){
            hedgehogposition = hedgehogposition +3;
        }
        if(random > 8){
            hedgehogposition = hedgehogposition -6;
        }
        if(random > 5 && random < 9){
            hedgehogposition = hedgehogposition +1;
        }

        if(hedgehogposition < 1){
            hedgehogposition = 2;
        }

        if(hedgehogposition > 69){
            hedgehogposition = 69;
        }


    return hedgehogposition;
}


int playerrules(int input,int random, int playerposition){


    if (input <= random)
    {
        playerposition = playerposition + input;
        
    }
    else{
        playerposition = playerposition - input/2;
        
    }
    
    if(playerposition < 1){
        playerposition = 1; 
    }

    if(playerposition > 69){
        playerposition =69;
    }

    return playerposition; 
}

int main(int argc, char *argv[]){                           // Anfang des Main programmes, ließt die Anzahl der eingaben und schreibt sie in argv



int end = 0;

int event = 0;                                              // Event, ob AUA ausgegeben wird oder nicht
int AnfangIgel;                                             // Anfangsposition des Igels   
int AnfangHase;                                             // Anfangsposition des Hasens
int hedgehogposition = AnfangIgel;                          // Position des Igels während das Programm läuft
int rabbitposition = AnfangHase;   
int playerposition = 1;                                      // Position des Hasens während das Programm läuft

int os;                                                     // Speichert welches OS verwendet wird

#ifdef _WIN32                                               // checkt das OS denn für die Zeitfunktion werden andere Befehle verwendet in Windows/unix
    os = 1;

#elif  
    os = 2;

#endif



srand(time(NULL));                                          // setzt den SEED für den Zufallsgenerator auf die momentane Zeit 

//printf("%d", argc);

if(argc == 1){                                              // überprüft die Anfangsbedingungen 
    AnfangIgel=1;
    AnfangHase=1;
}

if(argc == 2 || argc > 3){                                 // wenn die Anfangsbedingungen Fehlerhaft sind muss man sie richtig eingeben , noch keine Funktionalität für falsche Eingaben             
    printf("Bitte die Anfangsbedingungen richtig eingeben \n");
    printf("Anfangsbedingung Hase: ");
    scanf("%d%*c", &AnfangHase);
    printf("Anfangsbedingung Igel: ");
    scanf("%d%*c", &AnfangIgel);
}                                                          

if(argc == 3){                                              // scannt die Anfangsbedingungen ein
    int g;                                                  // temporäre Variable und Variabeln zu speichern
    int h;                                                  // ^

    sscanf(argv[1],"%d",&g);
    sscanf(argv[2],"%d",&h);
    if(g<1 || g>70){
        g = 1;
    }

    if(h<1 || h > 70){
        h = 1; 
    }

    AnfangIgel = g;
    AnfangHase = h;
}

int starteins;
starteins = 0;
for(;starteins == 0;){
    melodie(1);
    tutorial(1);
    starteins = 1;
}

int start;                                                // start bedingung, entweder 0 oder 1
char b[2];                                                // Char in den eine Eingabe geschrieben wird
char *c="Y";                                              // char mit dem die Eingabe verglichen wird
int d;                                                    // wegwerf Variabel 
start = 0;

for(;start == 0;){                                       // start frage
    draw(AnfangIgel,AnfangHase,1,0);
    printf("\n");
    printf("Starten ? Y/N \n");                          
    scanf("%s%*c", &b);                                   // ließt die Eingabe in b
    d = strcmp(b, c);                                     // vergleicht die Eingabe mit c

    if(d == 0){                                             // startet das Programm wenn b und c gleich sind
        start = 1;
    }

    else{                                                  // beendet das Programm wenn die Eingabe nicht gleich ist
        return 0;
    }
}

system("cls");
draw(AnfangIgel,AnfangHase,playerposition,0);                   // zeichnet die Anfangsposition
printf("LOS GEHT ES ! \n");                                     // los geht es


hedgehogposition=AnfangIgel;                                    // setzt hedgehogposition auf AnfangIgel
rabbitposition=AnfangHase;                                      // ^ nur rabbit/Hase

//int timer = 5;
//for(;timer > 0; timer--){
//    printf("%d !", timer);
//    Sleep(1000);
//}

if(os = 1){                                                     // wartet für 1 sekunde  windows/unix
    Sleep(1000);
}
else{
    sleep(1000);
}


if(os = 1){                                                    // cleart den Screen windows/unix
system("cls");
}
else{
system("clear");
}

int realend = 0;

    for(;realend == 0;){
            end = 0;

    for(;end == 0;){                                           // startet den wichtigen Teil im Programm
       // printf("inside loop");
        char schritte[20];
        int random;
        char *stop="stop";
        int b;
        int eingabe;
        int zwischen; 
        int schrotte;

        random = rand() % 10 + 1;     
        
        draw(hedgehogposition,rabbitposition,playerposition,event);                         // generiert eine Zufallszahl

       
        
            int l=1;
            for(;l==1;){
                printf("Wieviele Schritte ? : ");
                 scanf("%s%*c", &schritte);
                    if(strcmp(schritte, stop)==0){
                        break;
                    }
                 b = strcmp(stop,schritte);
                if(b == 0){
                     end = 1;
                    l == 0;
                }
        
                schrotte = eingabecheck(schritte);
                 if(schrotte == 0 && b != 0){
                system("cls");
                draw(hedgehogposition,rabbitposition,playerposition,event); 
                 }
                else{   
                  eingabe = schrotte;
                  l = 0;                 
            }
            

            
        }
        if(strcmp(schritte,stop)==0){
                break;
            }

        if(os =1){
            
            system("cls");
        }
        else{
            
            system("clear");
        }
        zwischen = playerposition;
        playerposition = playerrules(eingabe,random,playerposition);
        draw(hedgehogposition,rabbitposition,playerposition,event); 
        if(zwischen < playerposition){
            printf("JA!");
            Beep(800, 800);
        }
        else{
            printf("MIST!");
            Beep(600, 600);
        }

        if(os =1){
            Sleep(1000);
            system("cls");
        }
        else{
            sleep(1000);
            system("clear");
        }
        hedgehogposition = hedgehogrules(random,hedgehogposition);      // berechnet die Position des Igels
        rabbitposition = rabbitrules(random,rabbitposition);            // ^ aber für den Hasen



        if(hedgehogposition == rabbitposition){                         // wenn beide Tiere auf der selben position sind wird event auf 2 gesetzt und "aua" ausgegeben
            if(hedgehogposition > 2 && hedgehogposition < 70){
            event = 2;
            }
        }

        if(hedgehogposition > 68 || rabbitposition > 68 || playerposition > 68){              // beendet das Programm 
            end = 1;
        }

        draw(hedgehogposition,rabbitposition,playerposition,event);                    // Zeichnet das Feld 

        if(os = 1){                                                     // wartet 1 sekunde windows
              system("cls");
        }

        else{                                                           // wartet 1 sekunde unix
            sleep(1000);
            system("clear");
        }
        event = 0;
    }

    if(hedgehogposition >= 68 && rabbitposition < 69){   // Win condition 1 , Igel gewinnt
        printf("Der Igel bekommt einen Korb Salat\n");
        draw(69,rabbitposition,playerposition,0);
    }

    if(rabbitposition >= 68 &&  hedgehogposition < 69){     // win condition 2, Hase Gewinnt
        printf("Der Hase bekommt einen Sack Karotten\n");
        draw(hedgehogposition,69,playerposition,0);
    }

    if(rabbitposition > 68 && hedgehogposition > 68){                             // win condition 3, unentschieden
        printf("Unentschieden!\n");
        draw(69,69,playerposition,0);
    }

    if(playerposition > 68){
        draw(hedgehogposition,rabbitposition,69,0);
        printf("Gewonnen! \n");
    }

    char *end = "end";
    char *again = "again";
    char mama[20];
    int ending;
    int againing;

    int endingend = 0;
   
   // printf("test");
    for(;endingend == 0;){
        printf("Play again ?:  (again/end) ");
            scanf("%s%*c", &mama);
        ending = strcmp(mama, end);
        againing = strcmp(mama, again);
        if(ending == 0){
            system("cls");
            printf("Thanks for playing! :)");
            Sleep(1000);
            realend = 1;
            endingend = 1;
        }
        if(againing == 0){
            realend = 0;
            endingend = 1;
        }
        if(ending != 0 && againing !=0){
            printf("Falsche Eingabe, bitte erneut eingeben.");
            Sleep(2000);
            system("cls");
            endingend = 0;
        }
        //printf("%d", endingend);
        }

        rabbitposition = 1;
        hedgehogposition = 1;
        playerposition = 1;
        event = 0;
        end = 0;

    }
    return 0;                                                           // ende
}



// als Idee diese Simulation als ein Spiel zu gestallten würde ich einen weiteren Character hinzufügen
// der vom Spieler gesteuert wird, er kann eine Zahl eingeben die seiner Schrittzahl entspricht,
// doch je höher die Zahl ist desto höher ist die Wahrscheinlichkeit dass der Schritt in die Falsche richtung
// geht. 

// es wird gegen entweder noch einen weiteren Spieler gespielt oder gegen den Computer. Und Musik :)

// Code in Englisch weil Kopf = Englisch 

// Deine Mutter

