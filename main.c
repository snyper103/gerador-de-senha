#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char* passwordGenerator( unsigned long size, short chvCont, char* strCont )
{
    char* strPassword = ( char* )malloc( sizeof( char ) * size + 1 ),  strAux[43], strNum[43];
    long num;
    short aux, bol;
    register unsigned long i, j = 0, l;
    FILE* fp = fopen("senha.txt", "w");

    srand( time(NULL) );

    if( chvCont == 2)
        aux = 2;

    else
        aux = 1;

    for( i = 0; i < 15; ++i )
        strNum[i] = 33 + i;

    for( j = 0; j < 7; ++i, ++j )
        strNum[i] = 58 + j;

    for( j = 0; j < 6; ++i, ++j )
        strNum[i] = 91 + j;

    for( j = 0; j < 4; ++i, ++j )
        strNum[i] = 123 + j;

    for( j = 0; j < 10; ++i, ++j)
        strNum[i] = 166 + j;

    strNum[i] = '\0';

    if(strCont)
    {
        for( j = 0, l = 0; strNum [l] != '\0';  ++l)
        {
            for(i = 0, bol = 1; strCont[i] != '\0'; ++i)
                if(strNum[l] == strCont[i])
                {
                    bol = 0;
                    break;
                }

                if(bol == 1)
                {
                    strAux[j] = strNum[l];
                    ++j;
                }
        }

        strAux[j] = '\0';
    }

    else
    {
        for(j = 0; j < 42; ++j)
            strAux[j] = strNum[j];

        strAux[j] = strNum[j];
    }

    for( i = 0; i < size; ++i )
    {
        num = rand() % chvCont + aux;

        switch( num )
        {
            case 1:
                num = '0' + (rand() % 10);
                strPassword[i] = num;
            break;

            case 2:
                num = 'a' + (rand() % 26);
                strPassword[i] = num;
            break;

            case 3:
                num = 'A' + (rand() % 26);
                strPassword[i] = num;
            break;

            case 4:
                num = rand() % j;
                strPassword[i] = strAux [num];
            break;
        }
    }

    strPassword[i] = '\0';

    fprintf(fp, "%s", strPassword);

    fclose(fp);

    return strPassword;
}

void display()
{
    short op = 1;
    unsigned long size;
    char* strPass,* strAux, strOp[4];

    setlocale( LC_ALL, "" );

    while( op != 0 )
    {
        system("cls || clear");
        printf("\t##### ... Menu ... #####\n"
                         "[1] - Deseja gerar sua senha.\n"
                         "[0] - Deseja sair do programa.\n"
                         "Digite o numero que representa a opção desejada: ");
        scanf(" %hi", &op);

        switch( op )
        {
            case 1:
                volta :
                system("cls || clear");
                printf("\t##### ... Menu ... #####\n"
                                 "[1] - Deseja gerar senha apenas com numeros.\n"
                                 "[2] - Deseja gerar senha apenas com letras.\n"
                                 "[3] - Deseja gerar senha com letras e numeros.\n"
                                 "[4] - Deseja gerar senha com letras, numeros e caracteres especiais.\n"
                                 "[0] - Deseja Voltar.\n"
                                 "Digite o numero que representa a opção desejada: ");
                scanf(" %hi", &op);

                switch( op )
                {
                    case 1:
                        system("cls || clear");
                        printf("Qual o tamanho da senha desejada: ");
                        scanf(" %lu", &size);

                        strPass = passwordGenerator(size, op, NULL);

                        printf("\nSua senha é: %s"
                                         "\n\n\tPressione enter para voltar ao menu.\n", strPass);

                        free(strPass);
                        getchar();
                        getchar();
                    break;

                    case 2:
                        system("cls || clear");
                        printf("Qual o tamanho da senha desejada: ");
                        scanf(" %lu", &size);

                        strPass = passwordGenerator(size, op, NULL);

                        printf("\nSua senha é: %s"
                                         "\n\n\tPressione enter para voltar ao menu.\n", strPass);

                        free(strPass);
                        getchar();
                        getchar();
                        break;

                    case 3:
                        system("cls || clear");
                        printf("Qual o tamanho da senha desejada: ");
                        scanf(" %lu", &size);

                        strPass = passwordGenerator(size, op, NULL);

                        printf("\nSua senha é: %s"
                                         "\n\n\tPressione enter para voltar ao menu.\n", strPass);

                        free(strPass);
                        getchar();
                        getchar();
                    break;

                    case 4:
                        system("cls || clear");
                        printf("Tem algum caracter que não pode ir na senha (S/N): ");
                        scanf(" %[^\n]s", strOp);

                        if( (strOp[0] == 's') || (strOp[0] == 'S') )
                        {
                            system("cls || clear");
                            printf("Quantos: ");
                            scanf(" %lu", &size);

                            strAux = (char*)malloc(size * sizeof(char));

                            printf("Quais são (digite todos juntos ex: !'@): ");
                            scanf(" %s", strAux);
                        }
                        else
                            strAux = NULL;

                        system("cls || clear");
                        printf("Qual o tamanho da senha desejada: ");
                        scanf(" %lu", &size);

                        strPass = passwordGenerator(size, op, strAux);

                        printf("\nSua senha é: %s"
                                         "\n\n\tPressione enter para voltar ao menu.\n", strPass);

                        free(strAux);
                        free(strPass);
                        getchar();
                        getchar();
                    break;

                    case 0:
                        op = 1;
                        break;

                    default :
                        system("cls || clear");
                        printf("Opção invalida, porfavor digite algo valido."
                                         "\n\tPressione enter para voltar ao menu.\n");
                        getchar();
                        getchar();
                        goto volta;
                }
            break;

            case 0:
                system("cls || clear");
                printf("\tThats all folks..."
                       "\nPressione enter para fechar o programa.\n");
                getchar();
                getchar();
            break;

            default :
                system("cls || clear");
                printf("Opção invalida, porfavor digite algo valido."
                                 "\n\tPressione enter para voltar ao menu.\n");

                getchar();
                getchar();
        }
    }
}

int main()
{
    display();

    return 0;
}
