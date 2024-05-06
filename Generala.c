/*************************************************************************
 * Programado por: Sebastian Rojas y Mateo Rios                          *
 * Clase: TAI                                        					 *
 * Tarea: Juego de generala								                 *
 * Fecha: 10/05/24                                                       *
 *                                                                       *
 *																		 *
 ************************************************************************/


#include "Yahtzee.h"



/************************************************************
 * Función: juego_principal                                 *
 * Fecha de creación: 10/05/24                              *
 * Fecha de última modificación: 10/05/24                   *
 * Descripción: Ejecuta el juego principal de Yahtzee.      *
 * Parámetros de entrada: ninguno                           *
 * Retorna: ninguno                                         *
 * Precondiciones: Inicio del programa                      *
 * Postcondiciones: ninguna                                 *
 *************************************************************/
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

		end_game(p1_puntuaciones, p2_puntuaciones);
	}
	printf("¡Adiós!\n\n");
}


/***************************************************************
 * Función: menu_juego                                         *
 * Fecha de creación: 10/23/15                                 *
 * Fecha de última modificación: 10/23/15                      *
 * Descripción: Muestra el menú principal del juego Yahtzee.   *
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
 * Fecha de creación: 10/23/15                                 *
 * Fecha de última modificación: 10/23/15                      *
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
 * Fecha de creación: 10/23/15                                 *
 * Fecha de última modificación: 10/23/15                      *
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
	print_combos(combos_c);
}


/***************************************************************
 * Función: relanzar                                           *
 * Fecha de creación: 10/23/15                                 *
 * Fecha de última modificación: 10/23/15                      *
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


 /************************************************************
 * Función: elegir_combo (int dado[5], int tamano,			 *
 *			 int combo_c[13], int puntuaciones[13],				 *
 *			 int jugador, int ronda)							 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Asks user to choose a combo, checks if used	 *
 * Parámetros de entrada: dado array, array tamano, combo array	     *
 *					 jugador, and ronda						 *
 * Devuelve: ninguno									         *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates combo array					     *
 *************************************************************/
void elegir_combo (int dado[5], int tamano, int combo_c[13], int puntuaciones[13], int jugador, int ronda)
{
	int selection = 0, index = 0, is_combo_valid = 0;


	system("cls");
	printf("************************************************** PLAYER %d ********************************************************\n", jugador);
	printf("************************************************** ROUND %d ********************************************************\n\n", ronda);
	imprimir_dado(dado, 5, combo_c);
	
	// Asks user for combination, repeat if combo has been used before
	do
	{
		printf("Enter the combination you would like to use: ");
		scanf("%d", &selection);

		switch(selection)
		{
		case 1:
			is_combo_valid = ones(dado,combo_c,puntuaciones);
			break;
		case 2:
			is_combo_valid = twos(dado,combo_c,puntuaciones);
			break;
		case 3:
			is_combo_valid = threes(dado,combo_c,puntuaciones);
			break;
		case 4:
			is_combo_valid = fours(dado,combo_c,puntuaciones);
			break;
		case 5:
			is_combo_valid = fives(dado,combo_c,puntuaciones);
			break;
		case 6:
			is_combo_valid = sixes(dado,combo_c,puntuaciones);
			break;
		case 7:
			is_combo_valid = three_of_a_kind(dado,combo_c,puntuaciones);
			break;
		case 8:
			is_combo_valid = four_of_a_kind(dado,combo_c, puntuaciones);
			break;
		case 9:
			is_combo_valid = full_house(dado,combo_c, puntuaciones);
			break;
		case 10:
			is_combo_valid = sm_straight(dado, combo_c, puntuaciones);
			break;
		case 11:
			is_combo_valid = lg_straight(dado, combo_c, puntuaciones);
			break;
		case 12:
			is_combo_valid = yahtzee(dado, combo_c, puntuaciones);
			break;
		case 13:
			is_combo_valid = chance(dado, combo_c, puntuaciones);
			break;
		default:
			printf("Please enter a valid selection.\n\n");
			break;
		}

	}
	while(!is_combo_valid);

		

}

 /************************************************************
 * Función: print_combos (int combo_c[13])					 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: prints combo choices, with X if used    	 *
 * Parámetros de entrada: combo array							 *
 * Devuelve: ninguno									         *
 * Precondiciones: Start of program                           *
 * Postcondiciones:										     *
 *************************************************************/
void print_combos (int combo_c[13])
{
	// Prints all the combinations, or an X if it's been used
	if (combo_c[0] == 0)
	{printf ("1. Sum of 1s\n");}
	else {printf ("X. Sum of 1s\n");}

	if (combo_c[1] == 0)
	{printf ("2. Sum of 2s\n");}
	else {printf ("X. Sum of 2s\n");}

	if (combo_c[2] == 0)
	{printf ("3. Sum of 3s\n");}
	else {printf ("X. Sum of 3s\n");}

	if (combo_c[3] == 0)
	{printf ("4. Sum of 4s\n");}
	else {printf ("X. Sum of 4s\n");}

	if (combo_c[4] == 0)
	{printf ("5. Sum of 5s\n");}
	else {printf ("X. Sum of 5s\n");}

	if (combo_c[5] == 0)
	{printf ("6. Sum of 6s\n");}
	else {printf ("X. Sum of 6s\n");}

	if (combo_c[6] == 0)
	{printf ("7. Three of a kind\n");}
	else {printf ("X. Three of a kind\n");}

	if (combo_c[7] == 0)
	{printf ("8. Four of a kind\n");}
	else {printf ("X. Four of a kind\n");}

	if (combo_c[8] == 0)
	{printf ("9. Full house\n");}
	else {printf ("X. Full house\n");}

	if (combo_c[9] == 0)
	{printf ("10. Small Straight\n");}
	else {printf ("X. Small Straight\n");}

	if (combo_c[10] == 0)
	{printf ("11. Large Straight\n");}
	else {printf ("X. Large Straight\n");}

	// Can be used an unlimited amount of times
	printf ("12. YAHTZEE\n");

	if (combo_c[12] == 0)
	{printf ("13. Chance\n\n");}
	else {printf ("X. Chance\n\n");}
}

 /************************************************************
 * Función: imprimir_puntuacion (int puntuaciones[13], int jugador)		 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: prints jugador score					    	 *
 * Parámetros de entrada: puntuaciones array, jugador					 *
 * Devuelve: ninguno									         *
 * Precondiciones: Start of program                           *
 * Postcondiciones:										     *
 *************************************************************/
void imprimir_puntuacion (int puntuaciones[13], int jugador)
{
	int sum = 0, index = 0;
	for (index= 0; index<13; index++)
	{
		sum = puntuaciones[index] + sum;
	}
	printf("Player %d's score is now %d.\n", jugador, sum);
}

 /************************************************************
 * Función: ones (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 1s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int ones (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[0] == 0)
	{
		combo_c[0] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 1)
			{sum = sum + 1;}
		}
		points[0] = sum;
	}
	return value;
}

 /************************************************************
 * Función: twos (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 2s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int twos (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[1] == 0)
	{
		combo_c[1] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 2)
			{sum = sum + 1;}
		}
		points[1] = sum*2;
	}
	return value;
}

 /************************************************************
 * Función: threes (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 3s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int threes (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[2] == 0)
	{
		combo_c[2] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 3)
			{sum = sum + 1;}
		}
		points[2] = sum*3;
	}
	return value;
}

 /************************************************************
 * Función: fours (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 4s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int fours (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[3] == 0)
	{
		combo_c[3] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 4)
			{sum = sum + 1;}
		}
		points[3] = sum*4;
	}
	return value;
}

 /************************************************************
 * Función: fives (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 5s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int fives (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[4] == 0)
	{
		combo_c[4] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 5)
			{sum = sum + 1;}
		}
		points[4] = sum*5;
	}
	return value;
}

 /************************************************************
 * Función: sixes (int dado[5], int combo_c[13], int points[13])
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds sum of 6s, adds to puntuaciones array		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int sixes (int dado[5], int combo_c[13], int points[13])
{
	int index = 0, sum = 0, value = 0;

	if (combo_c[5] == 0)
	{
		combo_c[5] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(dado[index] == 6)
			{sum = sum + 1;}
		}
		points[5] = sum*6;
	}
	return value;
}

 /************************************************************
 * Función: three_of_a_kind (int dado[5],					 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if 3OAK, then adds sum of dado		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int three_of_a_kind (int dado[5], int combo_c[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	// Checks if combo has been used before
	if (combo_c[6] == 0)
	{
		result = 1;
		combo_c[6] = 1; // Sets combo to used
		for (number = 1; number<7; number++)
		{
			sum = 0;

			if (dado[0] == number)
			{sum = sum +1;}
			if (dado[1] == number)
			{sum = sum +1;}
			if (dado[2] == number)
			{sum = sum +1;}
			if (dado[3] == number)
			{sum = sum +1;}
			if (dado[4] == number)
			{sum = sum +1;}
			
			// Adds points if three of a kind
			if (sum>= 3)
			{
				points[6] = dado [0] + dado[1] + dado[2] + dado[3] + dado[4];
				break;
			}		
		}
		
	}
	return result;
}

 /************************************************************
 * Función: four_of_a_kind (int dado[5],					 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if 4OAK, then adds sum of dado		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int four_of_a_kind (int dado[5], int combo_c[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	// Check if combo has been used before
	if (combo_c[7] == 0)
	{
		combo_c[7] = 1; // Sets combo to used
		// Checks if a dado matches a number, if it does then adds to a variable "sum". If sum = 3, then it breaks. Otherwise repeat with number+1. 
		for (number = 1; number>5; number++)
		{
			sum = 0;

			if (dado[0] == number)
			{sum = sum +1;}
			if (dado[1] == number)
			{sum = sum +1;}
			if (dado[2] == number)
			{sum = sum +1;}
			if (dado[3] == number)
			{sum = sum +1;}
			if (dado[4] == number)
			{sum = sum +1;}

			if (sum>= 4)
			{
				points[7] = dado [0] + dado[1] + dado[2] + dado[3] + dado[4];
				break;
			}
		}
		result = 1;
	}

	return result;
}

 /************************************************************
 * Función: full_house	 (int dado[5],			    		 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if FH, then gives 25 points			 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int full_house (int dado[5], int combo_c[13], int points[13])
{
	int number = 0, result = 0, sum1 = 0, sum2 = 0, three=0, two=0, number2 = 0;

	// Checks if combo has been used before
	if (combo_c[8] == 0)
	{
		combo_c[8] = 1; // Sets combo to used

		// Sets return value (if used or not) to 1
		result = 1;

		//Checks for a three of a kind
		for (number = 1; number<7; number++)
		{
			sum1 = 0;

			if (dado[0] == number)
			{sum1 = sum1 +1;}
			if (dado[1] == number)
			{sum1 = sum1 +1;}
			if (dado[2] == number)
			{sum1 = sum1 +1;}
			if (dado[3] == number)
			{sum1 = sum1 +1;}
			if (dado[4] == number)
			{sum1 = sum1 +1;}
			
			if (sum1== 3)
			{
				break;
			}	
		}

		// Checks for a two of a kind
		for (number2 = 1; number2<7; number2++)
		{
			sum2 = 0;

			if (dado[0] == number2)
			{sum2 = sum2 +1;}
			if (dado[1] == number2)
			{sum2 = sum2 +1;}
			if (dado[2] == number2)
			{sum2 = sum2 +1;}
			if (dado[3] == number2)
			{sum2 = sum2 +1;}
			if (dado[4] == number2)
			{sum2 = sum2 +1;}

			// If the two of the kind is the same number as three of a kind, ignore it
			if (number2 == number)
			{sum2 = 0;}
			
			if (sum2== 2)
			{
				if (sum2 + sum1 == 5)
				{points[8] = 25;} 
				break;
			}	
		}
	}
	return result;
	
}

 /************************************************************
 * Función: sm_straight	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if sm straight, then gives 30 points	 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int sm_straight (int dado[5], int combo_c[13], int points [13])
{
	int index = 0, temp = 0, passes = 0, sum=0, result=0;
	
	// Checks if combo has been used
	if (combo_c[9] == 0)
	{
		result = 1;
		
		combo_c[9] = 1;
		// Sort by ascending order (taken from Andy's code)
		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (dado[index] > dado[index + 1])
					{// swap
					temp = dado[index];
					dado[index] = dado[index+1];
					dado[index+1] = temp;
				}
			}
		}
 
	// Check for small straight
	for (index = 4; index>0; index--)
		{
			if (dado[index] == dado[index -1] + 1)
			{sum++;}

		}

	// Give points
	if (sum>=3)
	{points[9] = 30;}
	}

	return result;
}

 /************************************************************
 * Función: lg_straight	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if sm straight, then gives 40 points	 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int lg_straight (int dado[5], int combo_c[13], int points [13])
{
	int index = 0, temp = 0, passes = 0, sum=0, result=0;
	
	// Checks if combo has been used
	if (combo_c[10] == 0)
	{
		result = 1;
		combo_c[10]=1;
		// Sort by ascending order (taken from Andy's code)
		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (dado[index] > dado[index + 1])
					{// swap
					temp = dado[index];
					dado[index] = dado[index+1];
					dado[index+1] = temp;
				}
			}
		}
 
	// Check for small straight
	for (index = 4; index>0; index--)
		{
			if (dado[index] == dado[index -1] + 1)
			{sum++;}

		}

	// Give points
	if (sum>=4)
	{points[10] = 30;}
	}

	return result;
}

 /************************************************************
 * Función: lg_straight	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Checks if yahtzee, then gives 50 points		 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int yahtzee (int dado[5], int combo_c[13], int points[13])
{
	int number = 0, result = 0, sum = 0;

	// Check if combo has been used before
	if (combo_c[11] == 0)
	{
		combo_c[11] = 1; // Sets combo to used
			
		for (number=0;number<5;number++)
		{	
			sum =0;
			
			if (dado[0] == number)
			{sum = sum +1;}
			if (dado[1] == number)
			{sum = sum +1;}
			if (dado[2] == number)
			{sum = sum +1;}
			if (dado[3] == number)
			{sum = sum +1;}
			if (dado[4] == number)
			{sum = sum +1;}

			if (sum== 5)
			{
				points[11] = 50;
			}
		}
		result = 1;
	}

	return result;
}

 /************************************************************
 * Función: lg_straight	 (int dado[5],			    	 *
 *		 	 int combo_c[13], int points[13])				 *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds up sum of all dado as points			 *
 * Parámetros de entrada: dado array, combo array, points array	 *
 * Devuelve: 1 if combo has been used, 0 if not			     *
 * Precondiciones: Start of program                           *
 * Postcondiciones: updates points and combo arrays		     *
 *************************************************************/
int chance (int dado[5], int combo_c[13], int points[13])
{
	int result = 0, sum =0;

	if (combo_c[12] == 0)
	{
		combo_c[12] = 1;
		result = 1;
		sum = dado[0] + dado[1] + dado[2] + dado[3] + dado[4];
	
		points[12] = sum;
	}



	return result;
}

 /************************************************************
 * Función: end_game (int p1_points[13], int p2_points[13]) *
 * Fecha Created: 10/23/15                                    *
 * Fecha Last Modified: 10/23/15                              *
 * Descripción: Adds extra 35 points if applicable, shows winner
 * Parámetros de entrada: jugador 1 and 2 point arrays			 *
 * Devuelve:												     *
 * Precondiciones: Start of program                           *
 * Postcondiciones:										     *
 *************************************************************/
void end_game (int p1_points[13], int p2_points[13])
{
	int sum1 = 0, sum2 = 0, winner = 0, index=0;

	printf("************************************************ GAME OVER ******************************************************\n");
	
	for (index = 0; index<5; index++)
	{
		sum1 = p1_points[index] + sum1;
	}
	for (index = 0; index<5; index++)
	{
		sum2 = p2_points[index] + sum2;
	}


	if ((p1_points[0]+p1_points[1]+p1_points[2]+p1_points[3]+p1_points[4]+p1_points[5])>63)
	{sum1 = sum1+35;}
	if ((p2_points[0]+p2_points[1]+p2_points[2]+p2_points[3]+p2_points[4]+p1_points[5])>63)
	{sum2 = sum2+35;}

	if (sum2>sum1)
	{
		winner=2;
	}

	if (sum1>sum2)
	{
		winner =1;
	}
	
	if (sum1 == sum2)
	{
		winner = -1;
	}

	switch (winner)
	{
	case 1:
		printf("\n\nPlayer 1 wins with %d points!\nPlayer 2 has %d points.\n\n", sum1, sum2);
		break;
	case 2:
		printf("\n\nPlayer 2 wins with %d points!\nPlayer 1 has %d points.\n\n", sum2, sum1);
		break;
	case -1:
		printf("It's a tie! Both jugadors have %d points.\n\n", sum1);
		break;
	default:
		printf("Error");
	}

	system("pause");
	system("cls");

}


