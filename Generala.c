/*************************************************************************
 * Programado por: Sebastian Rojas y Mateo Rios                          *
 * Clase: TAI                                                            *
 * Tarea: Juego de generala                                              *
 * Fecha: 22/04/24                                                       *
 ************************************************************************/

#include "Generala.h"

/************************************************************
 * Función: juego_principal                                 *
 * Fecha de creación: 22/05/24                              *
 * Fecha de última modificación: 6/05/24                   *
 * Descripción: Ejecuta el juego principal de Generala.     *
 * Parámetros de entrada: ninguno                           *
 * Retorna: ninguno                                         *
 * Precondiciones: Inicio del programa                      *
 * Postcondiciones: ninguna                                 *
 ************************************************************/
void juego_principal(void)
{
    // Declaración de variables
    int dado[5] = {0}, p1_puntuaciones[13] = {0}, p1_combinaciones[13] = {0}, p2_puntuaciones[13] = {0}, p2_combinaciones[13] = {0}, jugador = 1, turno = 0;

    // Inicialización del generador de números aleatorios
    srand((unsigned int)time(NULL));

    while(menu_juego())
    {
        while(turno < 14)
        {
            // JUGADOR 1
            system("cls");
            printf("--- JUGADOR 1 - RONDA %d ---\n\n", turno);
            tirar_dado(dado, 5);
            imprimir_dado(dado, 5, p1_combinaciones);
            relanzar(dado, 5, p1_combinaciones, 1, turno);
            elegir_combo(dado, 5, p1_combinaciones, p1_puntuaciones, 1, turno);
            
            system("cls");
            printf("--- JUGADOR 1 - RONDA %d ---\n\n", turno);
            imprimir_puntuacion(p1_puntuaciones, 1);

            printf("\nPresiona cualquier tecla para cambiar al jugador 2.");
            system("pause > nul");
            system("cls");

            // JUGADOR 2
            system("cls");
            printf("--- JUGADOR 2 - RONDA %d ---\n\n", turno);
            tirar_dado(dado, 5);
            imprimir_dado(dado, 5, p2_combinaciones);
            relanzar(dado, 5, p2_combinaciones, 2, turno);
            elegir_combo(dado, 5, p2_combinaciones, p2_puntuaciones, 2, turno);
            
            system("cls");
            printf("--- JUGADOR 2 - RONDA %d ---\n\n", turno);
            imprimir_puntuacion(p2_puntuaciones, 2);

            system("pause\n");
            system("cls");

            turno++;
        }

        finalizar_juego(p1_puntuaciones, p2_puntuaciones);
    }
    printf("¡Adiós!\n\n");
}

/***************************************************************
 * Función: menu_juego                                         *
 * Fecha de creación: 26/04/24                                 *
 * Fecha de última modificación: 06/05/24                      *
 * Descripción: Muestra el menú principal del juego Generala.  *
 * Parámetros de entrada: ninguno                              *
 * Retorna: entero indicando si se juega o no (1 o 0)          *
 * Precondiciones: Inicio del programa                         *
 * Postcondiciones: Define si se inicia o no el juego          *
 ***************************************************************/
int menu_juego(void)
{
    int opcion = 0, jugar = 0;

    printf("-- Generala! --\n\n");
    
    do
    {
        do
        {
            printf("Elija una opción ingresando el número correspondiente:\n1. Imprimir las reglas del juego\n2. Iniciar un juego de Generala\n3. Salir\n");
            scanf("%d", &opcion);
        }
        while (opcion != 1 && opcion != 2 && opcion != 3);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("-- Generala! --\n");
            printf("\nReglas del juego:\n\n");
            printf("La tarjeta de puntuación consta de dos secciones, una superior y una inferior. Un total de trece casillas o combinaciones de puntuación se dividen entre las secciones. La sección superior se puntúa sumando el valor de los dados que coinciden con las caras de la casilla. Por ejemplo, si se lanzan cuatro 3's, la puntuación es 12. Una vez puntuada una casilla, no puede cambiarse. Si la suma en la sección superior es igual o superior a 63, se añaden 35 puntos de bonificación al total del jugador. La sección inferior contiene combinaciones de tipo póker.\n\n");
            break;
        case 2: 
            jugar = 1;
            break;
        case 3:
            jugar = 0;
            break;
        default:
            printf("Por favor, escriba una opción válida.\n");
        }
    }
    while (opcion != 2 && opcion != 3);
    system("cls");
    
    return jugar;
}

/***************************************************************
 * Función: tirar_dado                                         *
 * Fecha de creación: 26/04/24                                 *
 * Fecha de última modificación: 1/05/24                      *
 * Descripción: Lanza los dados de forma aleatoria.            *
 * Parámetros de entrada: Array de dados y tamaño del array.   *
 * Retorna: ninguno                                            *
 * Precondiciones: Inicio del programa                         *
 * Postcondiciones: Actualiza el array de dados                *
 ***************************************************************/
void tirar_dado(int dado[5], int tamano)
{
    char continuar = 0;
    int indice = 0;

    printf("Presione cualquier tecla para lanzar los dados.\n\n");
    system("pause > nul");
    
    for (indice = 0; indice < tamano; ++indice)
    {
        dado[indice] = rand() % 6 + 1;
    }
}

/***************************************************************
 * Función: imprimir_dado                                      *
 * Fecha de creación: 27/04/24                                 *
 * Fecha de última modificación: 28/04/24                      *
 * Descripción: Imprime los dados en formato ASCII.            *
 * Parámetros de entrada: array de dados, tamaño del array y   *
 * array de combinaciones de combos.                           *
 * Retorna: ninguno                                            *
 * Precondiciones: Inicio del programa                         *
 * Postcondiciones: ninguna                                    *
 ***************************************************************/
void imprimir_dado(int dado[5], int tamano, int combos_c[13])
{
    int indice = 0;
    int linea = 1;

    // Imprime cada línea del dado 
    while (linea <= 5)
    {
        switch (linea)
        {
            case 1:
                // Imprime la parte superior de cada dado
                for (indice = 0; indice < tamano; ++indice)
                {
                    printf("-----\t");
                }
                printf("\n");
                break;
            case 2:
                // Imprime la segunda línea con representación de los puntos del dado
                for (indice = 0; indice < tamano; ++indice)
                {
                    switch(dado[indice])
                    {
                        case 1:
                            printf("|   |\t");
                            break;
                        case 2:
                        case 3:
                            printf("|o  |\t");
                            break;
                        case 4:
                        case 5:
                        case 6:
                            printf("|o o|\t");
                            break;
                    }
                }
                printf("\n");
                break;
            case 3:
                // Imprime la línea central de cada dado
                for (indice = 0; indice < tamano; ++indice)
                {
                    switch(dado[indice])
                    {
                        case 1:
                        case 3:
                        case 5:
                            printf("| o |\t");
                            break;
                        case 2:
                        case 4:
                            printf("|   |\t");
                            break;
                        case 6:
                            printf("|o o|\t");
                            break;
                    }
                }
                printf("\n");
                break;
            case 4:
                // Imprime la cuarta línea con representación de los puntos del dado
                for (indice = 0; indice < tamano; ++indice)
                {
                    switch(dado[indice])
                    {
                        case 1:
                            printf("|   |\t");
                            break;
                        case 2:
                        case 3:
                            printf("|  o|\t");
                            break;
                        case 4:
                        case 5:
                        case 6:
                            printf("|o o|\t");
                            break;
                    }
                }
                printf("\n");
                break;
            case 5:
                // Imprime la base de cada dado
                for (indice = 0; indice < tamano; ++indice)
                {
                    printf("-----\t");
                }
                printf("\n\n");
                break;
        }
        linea++;
    }

    // Imprime las combinaciones de puntuaciones disponibles
    imprimir_combos(combos_c);
}


/***************************************************************
 * Función: relanzar                                           *
 * Fecha de creación: 26/04/24                                 *
 * Fecha de última modificación: 2/05/24                      *
 * Descripción: Pide al usuario si desea y cuántos dados        *
 *              relanzar, luego actualiza el array de dados.    *
 * Parámetros de entrada: array de dados, tamaño del array,     *
 *                        array de combinaciones, jugador y     *
 *                        ronda actual.                         *
 * Devuelve: ninguno                                            *
 * Precondiciones: Inicio del programa                         *
 * Postcondiciones: actualiza el array de dados                 *
 ***************************************************************/
void relanzar(int dado[5], int tamano, int combo_c[13], int jugador, int ronda)
{
    int cantidad = 0;  // Cantidad de dados a relanzar
    int indice = 0;    // Índice para iteraciones

    for (indice = 0; indice < 2; indice++)  // Permite hasta dos oportunidades para relanzar dados
    {
        do
        {
            printf("¿Cuántos dados desea relanzar? Ingrese un número de 0 a 5 (0 para mantener la tirada actual): ");
            scanf("%d", &cantidad);
        } while (cantidad < 0 || cantidad > 5);

        if (cantidad == 0)
        {
            break;  // Si el jugador no desea relanzar, se rompe el ciclo
        }

        for (int i = 0; i < cantidad; i++)
        {
            int dadoRelanzar;
            do
            {
                printf("Ingrese el número de dado que desea relanzar (1-5): ");
                scanf("%d", &dadoRelanzar);
            } while (dadoRelanzar < 1 || dadoRelanzar > 5);  // Asegura que el número de dado sea válido

            dado[dadoRelanzar - 1] = rand() % 6 + 1;  // Actualiza el valor del dado seleccionado
        }

        system("cls");
        printf("--- JUGADOR %d - RONDA %d ---\n\n", jugador, ronda);
        imprimir_dado(dado, tamano, combo_c);  // Reimprime los dados después de relanzar
    }
}


/***************************************************************
 * Función: elegir_combo                                      *
 * Fecha de creación: 27/04/24                                *
 * Fecha de última modificación: 1/05/24                     *
 * Descripción: Solicita al usuario que elija una combinación *
 *              y verifica si ya ha sido utilizada.           *
 * Parámetros de entrada: array de dados, tamaño del array,   *
 *                        array de combinaciones, array de    *
 *                        puntuaciones, jugador y ronda.       *
 * Devuelve: ninguno                                          *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza el array de combinaciones       *
 ***************************************************************/
void elegir_combo(int dado[5], int tamano, int combo_c[13], int puntuaciones[13], int jugador, int ronda)
{
    int seleccion = 0, es_combo_valido = 0;

    system("cls");
    printf("--- JUGADOR %d - RONDA %d ---\n\n", jugador, ronda);
    imprimir_dado(dado, tamano, combo_c);
    
    // Solicita al usuario que elija una combinación y repite si la combinación ya ha sido usada
    do
    {
        printf("Ingrese la combinación que desea utilizar (1-13): ");
        scanf("%d", &seleccion);

        switch (seleccion)
        {
            case 1:
                es_combo_valido = unos(dado, combo_c, puntuaciones);
                break;
            case 2:
                es_combo_valido = doses(dado, combo_c, puntuaciones);
                break;
            case 3:
                es_combo_valido = treses(dado, combo_c, puntuaciones);
                break;
            case 4:
                es_combo_valido = cuatros(dado, combo_c, puntuaciones);
                break;
            case 5:
                es_combo_valido = cincos(dado, combo_c, puntuaciones);
                break;
            case 6:
                es_combo_valido = seises(dado, combo_c, puntuaciones);
                break;
            case 7:
                es_combo_valido = trio(dado, combo_c, puntuaciones);
                break;
            case 8:
                es_combo_valido = poker(dado, combo_c, puntuaciones);
                break;
            case 9:
                es_combo_valido = full(dado, combo_c, puntuaciones);
                break;
            case 10:
                es_combo_valido = escalera_corta(dado, combo_c, puntuaciones);
                break;
            case 11:
                es_combo_valido = escalera_larga(dado, combo_c, puntuaciones);
                break;
            case 12:
                es_combo_valido = generala(dado, combo_c, puntuaciones);
                break;
            case 13:
                es_combo_valido = azar(dado, combo_c, puntuaciones);
                break;
            default:
                printf("Por favor, ingrese una selección válida.\n\n");
                es_combo_valido = 0;
                break;
        }
    } while (!es_combo_valido);
}


 /************************************************************
 * Función: imprimir_combos                                  *
 * Fecha de creación: 27/04/24                               *
 * Fecha de última modificación: 2/05/24                    *
 * Descripción: Imprime las opciones de combos, con X si ya  *
 *              se han utilizado.                            *
 * Parámetros de entrada: array de combos                    *
 * Devuelve: ninguno                                         *
 * Precondiciones: Inicio del programa                       *
 * Postcondiciones:                                          *
 *************************************************************/
void imprimir_combos(int combo_c[13])
{
    // Imprime todas las combinaciones, o una X si ya se han utilizado
    if (combo_c[0] == 0)
    {printf("1. Suma de unos\n");}
    else {printf("X. Suma de unos\n");}

    if (combo_c[1] == 0)
    {printf("2. Suma de doses\n");}
    else {printf("X. Suma de doses\n");}

    if (combo_c[2] == 0)
    {printf("3. Suma de treses\n");}
    else {printf("X. Suma de treses\n");}

    if (combo_c[3] == 0)
    {printf("4. Suma de cuatros\n");}
    else {printf("X. Suma de cuatros\n");}

    if (combo_c[4] == 0)
    {printf("5. Suma de cincos\n");}
    else {printf("X. Suma de cincos\n");}

    if (combo_c[5] == 0)
    {printf("6. Suma de seises\n");}
    else {printf("X. Suma de seises\n");}

    if (combo_c[6] == 0)
    {printf("7. Trio\n");}
    else {printf("X. Trio\n");}

    if (combo_c[7] == 0)
    {printf("8. Poker\n");}
    else {printf("X. Poker\n");}

    if (combo_c[8] == 0)
    {printf("9. Full\n");}
    else {printf("X. Full\n");}

    if (combo_c[9] == 0)
    {printf("10. Escalera corta\n");}
    else {printf("X. Escalera corta\n");}

    if (combo_c[10] == 0)
    {printf("11. Escalera larga\n");}
    else {printf("X. Escalera larga\n");}

    // Se puede usar un número ilimitado de veces
    printf("12. GENERALA\n");

    if (combo_c[11] == 0)
    {printf("13. Azar\n\n");}
    else {printf("X. Azar\n\n");}
}

 /************************************************************
 * Función: imprimir_puntuacion                             *
 * Fecha de creación: 29/04/24                               *
 * Fecha de última modificación: 30/04/24                    *
 * Descripción: Imprime la puntuación del jugador            *
 * Parámetros de entrada: array de puntuaciones, jugador     *
 * Devuelve: ninguno                                         *
 * Precondiciones: Inicio del programa                       *
 * Postcondiciones:                                          *
 *************************************************************/
void imprimir_puntuacion(int puntuaciones[13], int jugador)
{
    int suma = 0, indice = 0;
    for (indice= 0; indice<13; indice++)
    {
        suma = puntuaciones[indice] + suma;
    }
    printf("El puntaje del jugador %d es ahora %d.\n", jugador, suma);
}

 /************************************************************
 * Función: unos (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 27/04/24                                *
 * Fecha de última modificación: 27/04/24                     *
 * Descripción: Suma los unos y lo añade al array de puntos   *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int unos(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[0] == 0)
    {
        combo_c[0] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 1)
            {suma = suma + 1;}
        }
        puntos[0] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: doses (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 27/04/24                                *
 * Fecha de última modificación: 29/04/24                     *
 * Descripción: Suma los doses y lo añade al array de puntos  *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int doses(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[1] == 0)
    {
        combo_c[1] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 2)
            {suma = suma + 2;}
        }
        puntos[1] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: treses (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 29/04/24                                *
 * Fecha de última modificación: 1/05/24                     *
 * Descripción: Suma los treses y lo añade al array de puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int treses(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[2] == 0)
    {
        combo_c[2] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 3)
            {suma = suma + 3;}
        }
        puntos[2] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: cuatros (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 1/05/24                                *
 * Fecha de última modificación: 1/05/24                     *
 * Descripción: Suma los cuatros y lo añade al array de puntos*
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int cuatros(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[3] == 0)
    {
        combo_c[3] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 4)
            {suma = suma + 4;}
        }
        puntos[3] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: cincos (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 1/05/24                                *
 * Fecha de última modificación: 1/05/24                     *
 * Descripción: Suma los cincos y lo añade al array de puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int cincos(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[4] == 0)
    {
        combo_c[4] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 5)
            {suma = suma + 5;}
        }
        puntos[4] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: seises (int dado[5], int combo_c[13], int puntos[13])
 * Fecha de creación: 1/05/24                                *
 * Fecha de última modificación: 1/05/24                     *
 * Descripción: Suma los seises y lo añade al array de puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int seises(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, suma = 0, valor = 0;

    if (combo_c[5] == 0)
    {
        combo_c[5] = 1;
        valor = 1;
        for (indice = 0; indice<5; indice++)
        {
            if(dado[indice] == 6)
            {suma = suma + 6;}
        }
        puntos[5] = suma;
    }
    return valor;
}

 /************************************************************
 * Función: trio (int dado[5],					             *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 3/05/24                                *
 * Fecha de última modificación: 3/05/24                     *
 * Descripción: Verifica si hay un trío y luego suma los dados*
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int trio(int dado[5], int combo_c[13], int puntos[13])
{
    int numero = 0, resultado = 0, suma = 0;

    // Verifica si el combo ha sido utilizado anteriormente
    if (combo_c[6] == 0)
    {
        resultado = 1;
        combo_c[6] = 1; // Establece el combo como utilizado
        for (numero = 1; numero<7; numero++)
        {
            suma = 0;

            if (dado[0] == numero)
            {suma = suma +1;}
            if (dado[1] == numero)
            {suma = suma +1;}
            if (dado[2] == numero)
            {suma = suma +1;}
            if (dado[3] == numero)
            {suma = suma +1;}
            if (dado[4] == numero)
            {suma = suma +1;}
            
            // Añade puntos si hay un trío
            if (suma>= 3)
            {
                puntos[6] = dado[0] + dado[1] + dado[2] + dado[3] + dado[4];
                break;
            }       
        }
        
    }
    return resultado;
}

 /************************************************************
 * Función: poker (int dado[5],					             *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 3/05/24                                *
 * Fecha de última modificación: 3/05/24                     *
 * Descripción: Verifica si hay un poker y luego suma los dados*
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int poker(int dado[5], int combo_c[13], int puntos[13])
{
    int numero = 0, resultado = 0, suma = 0;

    // Verifica si el combo ha sido utilizado anteriormente
    if (combo_c[7] == 0)
    {
        combo_c[7] = 1; // Establece el combo como utilizado
        // Verifica si un dado coincide con un número, si lo hace, se añade a una variable "suma". Si suma = 4, se rompe el ciclo. De lo contrario, se repite con número+1. 
        for (numero = 1; numero<=6; numero++)
        {
            suma = 0;

            if (dado[0] == numero)
            {suma = suma +1;}
            if (dado[1] == numero)
            {suma = suma +1;}
            if (dado[2] == numero)
            {suma = suma +1;}
            if (dado[3] == numero)
            {suma = suma +1;}
            if (dado[4] == numero)
            {suma = suma +1;}

            if (suma>= 4)
            {
                puntos[7] = dado[0] + dado[1] + dado[2] + dado[3] + dado[4];
                break;
            }
        }
        resultado = 1;
    }

    return resultado;
}

 /************************************************************
 * Función: full	 (int dado[5],			    	         *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 4/05/24                                *
 * Fecha de última modificación: 4/05/24                     *
 * Descripción: Verifica si hay un full y luego otorga 25 puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int full(int dado[5], int combo_c[13], int puntos[13])
{
    int numero = 0, resultado = 0, suma1 = 0, suma2 = 0, tres=0, dos=0, numero2 = 0;

    // Verifica si el combo ha sido utilizado anteriormente
    if (combo_c[8] == 0)
    {
        combo_c[8] = 1; // Establece el combo como utilizado

        // Establece el valor de retorno (si se ha utilizado o no) a 1
        resultado = 1;

        // Verifica si hay un trío
        for (numero = 1; numero<7; numero++)
        {
            suma1 = 0;

            if (dado[0] == numero)
            {suma1 = suma1 +1;}
            if (dado[1] == numero)
            {suma1 = suma1 +1;}
            if (dado[2] == numero)
            {suma1 = suma1 +1;}
            if (dado[3] == numero)
            {suma1 = suma1 +1;}
            if (dado[4] == numero)
            {suma1 = suma1 +1;}
            
            if (suma1== 3)
            {
                tres = numero;  // Guarda el número del trío
                break;
            }   
        }

        // Verifica si hay un par
        for (numero2 = 1; numero2<7; numero2++)
        {
            suma2 = 0;

            if (dado[0] == numero2)
            {suma2 = suma2 +1;}
            if (dado[1] == numero2)
            {suma2 = suma2 +1;}
            if (dado[2] == numero2)
            {suma2 = suma2 +1;}
            if (dado[3] == numero2)
            {suma2 = suma2 +1;}
            if (dado[4] == numero2)
            {suma2 = suma2 +1;}

            // Si el par es el mismo número que el trío, se ignora
            if (numero2 == tres)
            {suma2 = 0;}
            
            if (suma2== 2)
            {
                if (suma2 + suma1 == 5)
                {puntos[8] = 25;} 
                break;
            }   
        }
    }
    return resultado;
    
}

 /************************************************************
 * Función: escalera_corta	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 4/05/24                                *
 * Fecha de última modificación: 5/05/24                     *
 * Descripción: Verifica si hay una escalera corta y otorga 30 puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int escalera_corta(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, temporal = 0, pasadas = 0, suma=0, resultado=0;
    
    // Verifica si el combo ha sido utilizado
    if (combo_c[9] == 0)
    {
        resultado = 1;
        
        combo_c[9] = 1;
        // Ordena de menor a mayor (tomado del código de Andy)
        for (pasadas = 1; pasadas < 5; pasadas++)
        {
            for (indice = 0; indice < 5 - pasadas; indice++)
            {
                if (dado[indice] > dado[indice + 1])
                    {// intercambio
                    temporal = dado[indice];
                    dado[indice] = dado[indice+1];
                    dado[indice+1] = temporal;
                }
            }
        }
 
    // Verifica si hay una escalera corta
    for (indice = 4; indice>0; indice--)
        {
            if (dado[indice] == dado[indice -1] + 1)
            {suma++;}

        }

    // Otorga puntos
    if (suma>=3)
    {puntos[9] = 30;}
    }

    return resultado;
}

 /************************************************************
 * Función: escalera_larga	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 5/05/24                                *
 * Fecha de última modificación: 5/05/24                     *
 * Descripción: Verifica si hay una escalera larga y otorga 40 puntos *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int escalera_larga(int dado[5], int combo_c[13], int puntos[13])
{
    int indice = 0, temporal = 0, pasadas = 0, suma=0, resultado=0;
    
    // Verifica si el combo ha sido utilizado
    if (combo_c[10] == 0)
    {
        resultado = 1;
        combo_c[10]=1;
        // Ordena de menor a mayor (tomado del código de Andy)
        for (pasadas = 1; pasadas < 5; pasadas++)
        {
            for (indice = 0; indice < 5 - pasadas; indice++)
            {
                if (dado[indice] > dado[indice + 1])
                    {// intercambio
                    temporal = dado[indice];
                    dado[indice] = dado[indice+1];
                    dado[indice+1] = temporal;
                }
            }
        }
 
    // Verifica si hay una escalera larga
    for (indice = 4; indice>0; indice--)
        {
            if (dado[indice] == dado[indice -1] + 1)
            {suma++;}

        }

    // Otorga puntos
    if (suma>=4)
    {puntos[10] = 40;}
    }

    return resultado;
}

 /************************************************************
 * Función: generala	 (int dado[5],			    	     *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 5/05/24                                *
 * Fecha de última modificación: 5/05/24                     *
 * Descripción: Verifica si hay una generala y otorga 50 puntos*
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int generala(int dado[5], int combo_c[13], int puntos[13])
{
    int numero = 0, resultado = 0, suma = 0;

    // Verifica si el combo ha sido utilizado anteriormente
    if (combo_c[11] == 0)
    {
        combo_c[11] = 1; // Establece el combo como utilizado
            
        for (numero=1; numero<=6; numero++)
        {   
            suma =0;
            
            if (dado[0] == numero)
            {suma = suma +1;}
            if (dado[1] == numero)
            {suma = suma +1;}
            if (dado[2] == numero)
            {suma = suma +1;}
            if (dado[3] == numero)
            {suma = suma +1;}
            if (dado[4] == numero)
            {suma = suma +1;}

            if (suma== 5)
            {
                puntos[11] = 50;
            }
        }
        resultado = 1;
    }

    return resultado;
}

 /************************************************************
 * Función: azar	 (int dado[5],			    	         *
 *		 	 int combo_c[13], int puntos[13])				 *
 * Fecha de creación: 5/05/24                                *
 * Fecha de última modificación: 10/23/15                     *
 * Descripción: Suma todos los dados como puntos              *
 * Parámetros de entrada: array de dados, array de combos,    *
 *                        array de puntos                     *
 * Devuelve: 1 si el combo ha sido utilizado, 0 si no         *
 * Precondiciones: Inicio del programa                        *
 * Postcondiciones: actualiza los arrays de puntos y combos   *
 *************************************************************/
int azar(int dado[5], int combo_c[13], int puntos[13])
{
    int resultado = 0, suma =0;

    if (combo_c[12] == 0)
    {
        combo_c[12] = 1;
        resultado = 1;
        suma = dado[0] + dado[1] + dado[2] + dado[3] + dado[4];
    
        puntos[12] = suma;
    }

    return resultado;
}

 /************************************************************
 * Función: finalizar_juego (int p1_puntos[13], int p2_puntos[13]) *
 * Fecha de creación: 6/05/24                                *
 * Fecha de última modificación: 6/05/24                     *
 * Descripción: Añade 35 puntos extra si es aplicable, muestra el ganador *
 * Parámetros de entrada: arrays de puntos de los jugadores 1 y 2 *
 * Devuelve:                                                   *
 * Precondiciones: Inicio del programa                         *
 * Postcondiciones:                                            *
 *************************************************************/
void finalizar_juego(int p1_puntos[13], int p2_puntos[13])
{
    int suma1 = 0, suma2 = 0, ganador = 0, indice=0;

    printf("************************************************ FIN DEL JUEGO ******************************************************\n");
    
    for (indice = 0; indice<13; indice++)
    {
        suma1 = p1_puntos[indice] + suma1;
    }
    for (indice = 0; indice<13; indice++)
    {
        suma2 = p2_puntos[indice] + suma2;
    }


    if ((p1_puntos[0]+p1_puntos[1]+p1_puntos[2]+p1_puntos[3]+p1_puntos[4]+p1_puntos[5])>63)
    {suma1 = suma1+35;}
    if ((p2_puntos[0]+p2_puntos[1]+p2_puntos[2]+p2_puntos[3]+p2_puntos[4]+p2_puntos[5])>63)
    {suma2 = suma2+35;}

    if (suma2>suma1)
    {
        ganador=2;
    }

    if (suma1>suma2)
    {
        ganador =1;
    }
    
    if (suma1 == suma2)
    {
        ganador = -1;
    }

    switch (ganador)
    {
    case 1:
        printf("\n\nEl jugador 1 gana con %d puntos!\nEl jugador 2 tiene %d puntos.\n\n", suma1, suma2);
        break;
    case 2:
        printf("\n\nEl jugador 2 gana con %d puntos!\nEl jugador 1 tiene %d puntos.\n\n", suma2, suma1);
        break;
    case -1:
        printf("¡Es un empate! Ambos jugadores tienen %d puntos.\n\n", suma1);
        break;
    default:
        printf("Error");
    }

    system("pause");
    system("cls");

}
