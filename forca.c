#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 100

// Define as sequências de escape ANSI para as cores
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

void limpar_tela() {
    // Limpa a tela para ocultar a palavra informada
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void inicializar_palavra_oculta(char* palavra, char* oculta) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i])) {
            oculta[i] = '_';
        } else {
            oculta[i] = palavra[i]; // Mantém caracteres não alfabéticos como estão
        }
    }
    oculta[strlen(palavra)] = '\0'; // Adiciona o caractere nulo no final
}

int adivinhar_letra(char* palavra, char* oculta, char letra) {
    int acerto = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (tolower(palavra[i]) == tolower(letra)) {
            oculta[i] = palavra[i];
            acerto = 1;
        }
    }
    return acerto;
}



void exibir_forca(int tentativas_restantes) {
    switch (tentativas_restantes) {
        case 6:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 5:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 4:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "         ._.                  ._.\n"    
                   "         | |                  | |\n"    
                   "         |_|                  |_|\n"    
                   "         |-|                  |-|\n"    
                   "         | |                  | |\n"    
                   "         |_|                  |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 3:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "      /\\ ._.                  ._.\n"    
                   "     / / | |                  | |\n"    
                   "    / /  |_|                  |_|\n"    
                   "   / /   |-|                  |-|\n"    
                   "  / /    | |                  | |\n"    
                   "  \\/     |_|                  |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 2:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "      /\\ ._. /\\               ._.\n"    
                   "     / / | | \\ \\              | |\n"    
                   "    / /  |_|  \\ \\             |_|\n"    
                   "   / /   |-|   \\ \\            |-|\n"    
                   "  / /    | |    \\ \\           | |\n"    
                   "  \\/     |_|     \\/           |_|\n"    
                   "                              ._.\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   "                              |-|\n"    
                   "                              | |\n"    
                   "                              |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 1:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "      /\\ ._. /\\               ._.\n"    
                   "     / / | | \\ \\              | |\n"    
                   "    / /  |_|  \\ \\             |_|\n"    
                   "   / /   |-|   \\ \\            |-|\n"    
                   "  / /    | |    \\ \\           | |\n"    
                   "  \\/     |_|     \\/           |_|\n"    
                   "        /\\                    ._.\n"    
                   "       / /                    | |\n"    
                   "      / /                     |_|\n"    
                   "     / /                      |-|\n"    
                   "    / /                       | |\n"    
                   "    \\/                        |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
        case 0:
            printf(BLUE"  ____   ___    ____   ___       ___     ____      _____   ___   ____      __   ____ \n"
                   " |    | /   \\  /    | /   \\     |   \\   /    |    |     | /   \\ |    \\    /  ] /    |\n"
                   " |__  ||     ||   __||     |    |    \\ |  o  |    |   __||     ||  D  )  /  / |  o  |\n"
                   " __|  ||  O  ||  |  ||  O  |    |  D  ||     |    |  |_  |  O  ||    /  /  /  |     |\n"
                   "/  |  ||     ||  |_ ||     |    |     ||  _  |    |   _] |     ||    \\ /   \\_ |  _  |\n"
                   "\\  `  ||     ||     ||     |    |     ||  |  |    |  |   |     ||  .  \\\\     ||  |  |\n"
                   " \\____j \\___/ |___,_| \\___/     |_____||__|__|    |__|    \\___/ |__|\\_| \\____||__|__|\n"RESET
                   CYAN"        .__                  .__\n"     
                   "      __|  |___   ______   __|  |___\n" 
                   "     /__    __/  /_____/  /__    __/\n" 
                   "        |__|                 |__|\n"RESET    
                   YELLOW"         ._."RESET"                  ._.\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"    
                   YELLOW"         |-|      "RESET"            |-|\n"    
                   YELLOW"         | |      "RESET"            | |\n"    
                   YELLOW"         |_|      "RESET"            |_|\n"      
                   "  ________                    ._.\n"    
                   "  \\_____  \\                   | |\n"    
                   "   /   |   \\                  |_|\n"    
                   "  /    |    \\                 |-|\n"    
                   "  \\_______  /                 | |\n"    
                   "          \\/                  |_|\n"    
                   "      /\\ ._. /\\               ._.\n"    
                   "     / / | | \\ \\              | |\n"    
                   "    / /  |_|  \\ \\             |_|\n"    
                   "   / /   |-|   \\ \\            |-|\n"    
                   "  / /    | |    \\ \\           | |\n"    
                   "  \\/     |_|     \\/           |_|\n"    
                   "        /\\ /\\                 ._.\n"    
                   "       / / \\ \\                | |\n"    
                   "      / /   \\ \\               |_|\n"    
                   "     / /     \\ \\              |-|\n"    
                   "    / /       \\ \\             | |\n"    
                   "    \\/         \\/             |_|\n"    
                   GREEN"  ______   ______   ______   ______\n"    
                   " /_____/  /_____/  /_____/  /_____/\n"RESET);
            break;
    }
}


int main() {
    char palavra[MAX_PALAVRA];
    char oculta[MAX_PALAVRA];
    int tentativas_restantes = MAX_TENTATIVAS;

    printf("Jogador 1, informe a palavra a ser adivinhada: ");
    fgets(palavra, MAX_PALAVRA, stdin);
    palavra[strcspn(palavra, "\n")] = '\0'; // Remove o caractere de nova linha

    limpar_tela();

    inicializar_palavra_oculta(palavra, oculta);

    while (tentativas_restantes > 0) {
        limpar_tela();
        exibir_forca(tentativas_restantes);
        printf("Palavra: %s\n", oculta);
        printf("Tentativas restantes: %d\n", tentativas_restantes);
        printf("Jogador 2, adivinhe uma letra: ");

        char tentativa[10];
        fgets(tentativa, sizeof(tentativa), stdin);
        
        if (strlen(tentativa) != 2 || !isalpha(tentativa[0])) {
            printf("Entrada inválida. Por favor, digite uma única letra.\n");
            continue;
        }

        char letra = tentativa[0];

        if (!adivinhar_letra(palavra, oculta, letra)) {
            tentativas_restantes--;
        }

        if (strcmp(palavra, oculta) == 0) {
            printf("Parabéns! Você adivinhou a palavra: %s\n", palavra);
            return 0;
        }
    }
    limpar_tela();
    exibir_forca(tentativas_restantes);
    printf("Palavra: %s\n", oculta);
    printf("Tentativas restantes: %d\n", tentativas_restantes);
    printf("Você perdeu! A palavra era: %s\n", palavra);

    return 0;
}
