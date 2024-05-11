#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_LEN 26

void E_codificar()
{
    char cadena[1000];
    int giros;

    printf("Texto: ");
    scanf("%d", &cadena);
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = 0;

    printf("Caras de la escitala: ");
    scanf("%d", &giros);

    int len = strlen(cadena);

    int filas = (len + giros - 1) / giros;

    char cadena_codif[1000] = "";

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < giros; j++)
        {
            int index = j * filas + i;
            if (index < len)
                strncat(cadena_codif, &cadena[index], 1);
            else
                strcat(cadena_codif, " ");
        }
    }

    printf("\nCadena codificada: %s\n", cadena_codif);
}

void E_decodificar()
{
    char cadena_codif[1000];
    int giros;

    printf("Texto: ");
    scanf("%d", &cadena_codif);
    fgets(cadena_codif, sizeof(cadena_codif), stdin);

    cadena_codif[strcspn(cadena_codif, "\n")] = 0;

    printf("Caras de la escitala: ");
    scanf("%d", &giros);

    int len = strlen(cadena_codif);

    int filas = (len + giros - 1) / giros;

    printf("\nCadena decodificada: ");
    for (int i = 0; i < giros; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            int index = j * giros + i;
            if (index < len)
                printf("%c", cadena_codif[index]);
        }
    }
    printf("\n");
}

void C_codificar()
{
    char cadena[1000];
    int pos;

    printf("Texto: ");
    scanf("%d", &cadena);
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = 0;

    int len = strlen(cadena);

    char cadena_codif[1000] = "";

    for (int i = 0; i < len; i++)
    {
        int ascii = cadena[i];
        int newAscii = ascii + 3;
        if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
        {
            if ((ascii >= 65 && ascii <= 90 && newAscii <= 90) || (ascii >= 97 && ascii <= 122 && newAscii <= 122))
            {
                cadena_codif[i] = newAscii;
            }
            else
            {
                cadena_codif[i] = newAscii - 26;
            }
        }
        else
        {
            cadena_codif[i] = cadena[i];
        }
    }

    printf("\nCadena codificada: %s\n", cadena_codif);
}

void C_decodificar()
{
    char cadena[1000];
    int pos;

    printf("Texto: ");
    scanf("%d", &cadena);
    fgets(cadena, sizeof(cadena), stdin);

    cadena[strcspn(cadena, "\n")] = 0;

    int len = strlen(cadena);

    char cadena_codif[1000] = "";

    for (int i = 0; i < len; i++)
    {
        int ascii = cadena[i];
        int newAscii = ascii - 3;
        if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122))
        {
            if ((ascii >= 65 && ascii <= 90 && newAscii >= 65) || (ascii >= 97 && ascii <= 122 && newAscii >= 97))
            {
                cadena_codif[i] = newAscii;
            }
            else
            {
                cadena_codif[i] = newAscii + 26;
            }
        }
        else
        {
            cadena_codif[i] = cadena[i];
        }
    }

    printf("\nCadena codificada: %s\n", cadena_codif);
}

void V_codificar()
{
    char clave[100];
    char cadena[1000];

    printf("Ingrese palabra clave: ");
    scanf("%d", &clave);
    fgets(clave, sizeof(clave), stdin);
    clave[strcspn(clave, "\n")] = '\0';

    printf("Texto: ");
    scanf("%d", &cadena);
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    int clave_len = strlen(clave);
    int cadena_len = strlen(cadena);

    char *cifrado = (char *)malloc((cadena_len + 1) * sizeof(char));
    
    if (!cifrado) 
    {
        printf("Hubo un error en texto.\n");
        exit(1);
    }
    
    int clave_pos = 0;

    for (int i = 0; i < cadena_len; i++) 
    {
        char letra = cadena[i];
        int letra_pos = strchr(ALPHABET, toupper(letra)) - ALPHABET;
        
        if (letra_pos == -1) 
        {
            cifrado[i] = letra;
        } 
        else 
        {
            char clave_letra = toupper(clave[clave_pos % clave_len]);
            int clave_letra_pos = strchr(ALPHABET, clave_letra) - ALPHABET;

            cifrado[i] = ALPHABET[(letra_pos + clave_letra_pos) % ALPHABET_LEN];
            clave_pos++;
        }
    }
    
    cifrado[cadena_len] = '\0';
    printf("Cadena codificada: %s\n", cifrado);
    free(cifrado);
}

void V_decodificar()
{
    char clave[100];
    char cadena[1000];

    printf("Ingrese palabra clave: ");
    scanf("%d", &clave);
    fgets(clave, sizeof(clave), stdin);
    clave[strcspn(clave, "\n")] = '\0';

    printf("Texto: ");
    scanf("%d", &cadena);
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    int clave_len = strlen(clave);
    int cadena_len = strlen(cadena);
    char *texto = (char *)malloc((cadena_len + 1) * sizeof(char));

    if (!texto) 
    {
        printf("Hubo un error en texto.\n");
        exit(1);
    }
    
    int clave_pos = 0;

    for (int i = 0; i < cadena_len; i++) 
    {
        char letra = cadena[i];
        int letra_pos = strchr(ALPHABET, toupper(letra)) - ALPHABET;

        if (letra_pos == -1) 
        {
            texto[i] = letra;
        } 
        else 
        {
            char clave_letra = toupper(clave[clave_pos % clave_len]);
            int clave_letra_pos = strchr(ALPHABET, clave_letra) - ALPHABET;

            texto[i] = ALPHABET[(letra_pos - clave_letra_pos + ALPHABET_LEN) % ALPHABET_LEN];
            clave_pos++;
        }
    }

    texto[cadena_len] = '\0';
    printf("Cadena decodificada: %s\n", texto);
    free(texto);
}

int main()
{
    int menu;
    int sub_menu;

    do
    {
        printf("\n--- CIFRADOS ---\n");
        printf("1. Espartano\n");
        printf("2. Caesar\n");
        printf("3. Vigenere\n");
        printf("0. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &menu);
        getchar();

        switch (menu)
        {
        case 1:
            do
            {
                printf("\n-- ESPARTANO --\n");
                printf("1. Codificar\n");
                printf("2. Decodificar\n");
                printf("0. Salir...\n");
                printf("Seleccione opcion: ");
                scanf("%d", &sub_menu);

                switch (sub_menu)
                {
                case 1:
                    printf("\n- CODIFICAR -\n");
                    E_codificar();
                    break;

                case 2:
                    printf("\n- DECODIFICAR -\n");
                    E_decodificar();
                    break;

                case 0:
                    break;

                default:
                    printf("Opcion no valida.\n");
                }

            } while (sub_menu != 0);
            break;

        case 2:
            do
            {
                printf("\n-- CAESAR --\n");
                printf("1. Codificar\n");
                printf("2. Decodificar\n");
                printf("0. Salir...\n");
                printf("Seleccione opcion: ");
                scanf("%d", &sub_menu);

                switch (sub_menu)
                {
                case 1:
                    printf("\n- CODIFICAR -\n");
                    C_codificar();
                    break;

                case 2:
                    printf("\n- DECODIFICAR -\n");
                    C_decodificar();
                    break;

                case 0:
                    break;

                default:
                    printf("Opcion no valida.\n");
                }

            } while (sub_menu != 0);
            break;

        case 3:
            do
            {
                printf("\n-- VIGENERE --\n");
                printf("1. Codificar\n");
                printf("2. Decodificar\n");
                printf("0. Salir...\n");
                printf("Seleccione opcion: ");
                scanf("%d", &sub_menu);

                switch (sub_menu)
                {
                case 1:
                    printf("\n- CODIFICAR -\n");
                    V_codificar();
                    break;

                case 2:
                    printf("\n- DECODIFICAR -\n");
                    V_decodificar();
                    break;

                case 0:
                    break;

                default:
                    printf("Opcion no valida.\n");
                }

            } while (sub_menu != 0);
            break;

        case 0:
            break;

        default:
            printf("Opcion no valida.\n");
        }
    } while (menu != 0);

    return 0;
}