/* [10,J,Q,K,A] =
 * [A
 * K
 * Q
 * J
 * 10]
 * p -> pull roba o quita la carta superior (el ultimo elemento del arreglo) -> Done
 * d -> pone la carta robada, en la mano y la descarta para siempre -> Done
 * b -> pone la carta robada, de regreso en el arreglo pero en la parte inferior (primer elemento del arreglo)
 * e -> termina el juego -> Done
 * t -> pone la carta robada, de regreso en el arreglo pero en la parte superior (ultimo elemento del arreglo)
 * s -> guarda el juego como esta, el arreglo y la mano
 * L -> se carga el juego previamente guardado
 * Deck_state, hand_state, Cmd.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_function(int i){
    /*int generator = 0, aux = i;
    int random[5];
    generator = (rand() % 5);
    random [aux] = generator;
    for (int j = 0; j < aux; ++j) {
        while (random [j] == generator){
            generator = (rand() % 5);
        }
        random [aux] = generator;
    }
    printf("%i\n",generator );
    return generator;*/
    int random[5];
    int generator = 0, aux = i;
    generator = (rand() % 5);
    for (int j = 0; j < aux; ++j) {
        if (generator == random[j]){
            generator = (rand() % 5);
            j = -1;
        }
    }
    random [aux] = generator;
    //printf("%i\n",generator );
    return generator;
}

void print_status(char* deck_p[], int counter_aux, char opcion_aux,char* hand_p[]){
    for (int i = 0; i < counter_aux; ++i) {
        printf("%s ",deck_p[i]);
    }
    printf(", <%s>, %c\n",hand_p[0],opcion_aux);
}

int main() {
    time_t t;
    srand((unsigned )time(&t));
    char opcion;
    char* in [5] = {"10","J","Q","K","A"};
    char* deck[5], *hand[1], *stolen[1];
    int aux, counter =5;
    //Inicializar deck
    for (int i = 0; i < 5; ++i) {
        aux = random_function(i);
        deck [i] = in [aux];
    }
    printf("Deck inicial>");
    //Imprimir deck inicial
    for (int i = 0; i < 5; ++i) {
        printf("%s ",deck[i]);
    }
    printf("\n");
    //Empieza el juego
    while (1){
        printf("Select one option: \np>pull\nd>discard\nb>bottom\ne>exit\nt>top\ns>save\nl>load\nLetter>");
        scanf("%s",&opcion);
        switch (opcion) {
            case 'p':
                --counter;
                //stolen [0] = deck [counter];
                if (counter == 0){
                    printf("Ya no  hay mas cartas para retirar");
                }
                else {
                    hand[0] = deck [counter];
                    print_status(deck,counter,opcion,hand);
                }
                break;
            case 'd':
                --counter;
                hand[0] = deck [counter];
                print_status(deck,counter,opcion,hand);
                break;
            case 'b':
                hand [0] = deck [counter];
                for (int i = 1; i < counter; ++i) {
                    deck [i] = deck [i+1];
                }
                int i = 0;
                deck [i] = hand[0];
                print_status(deck,counter,opcion,hand);
                break;
            case 'e':
                printf("End of the game");
                return 0;
                break;
            case 't':

                break;
            case 's':

                break;
            case 'l':

                break;
            default:
                printf("invalid letter");
        }

    }
    return 0;
}
