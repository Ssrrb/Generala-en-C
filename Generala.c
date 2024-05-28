/*************************************************************************
 * Programado por: Sebastian Rojas y Mateo Rios                          *
 * Clase: TAI                                                            *
 * Tarea: Juego de generala                                              *
 * Fecha: 22/04/24                                                       *
 ************************************************************************/

#include "Generala.h"

/*
Función: juego_principal                                 
Ejecuta el juego principal de Generala.     
*/
void juego_principal(void)
{
    // Declaración de variables
    int dado[5] = {0}, p1_puntuaciones[13] = {0}, p1_combinaciones[13] = {0}, p2_puntuaciones[13] = {0}, p2_combinaciones[13] = {0}, jugador = 1, turno = 0, jugar_compu = 0, i=0, j=0;
    int pc_jugadas[56][7] = {0}, pc_puntuaciones[13] = {0}, v_generala = 6, jugada = 0, puntosjug1 = 0, puntuacion_compu =0, puntos_tmp =0, ind = 1, cont = 0, valor =0, k=0;

    //Se carga la matriz de jugadas
    //generala
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            if(j==0)
            {
                pc_jugadas[i][j] = 50;
            }
            else{    
                pc_jugadas[i][j] = v_generala;
                
            }  
             
        }
        v_generala = v_generala - 1; 
    }

    v_generala = 6;

    // Poker
    i= 6;
    for(i=6; i<31; i++)
    {
        for(j=1; j<6; j++)
        {
            if(j!=5)
            {
                pc_jugadas[i][j] = v_generala;
            }   
            else
            {
                pc_jugadas[i][j] = v_generala -1;
            }

           
        }
        for(ind=1; ind<6; ind++)
        {
          
            if(pc_jugadas[i][ind] == pc_jugadas[i][ind + 1])
            {
                cont = cont + 1;
                valor = pc_jugadas[i][ind];
            }
            
        }
    

        if(cont + 1 == 4)
        {
            pc_jugadas[i][0] = valor*4;
                
        }
        v_generala = v_generala - 1;
        if(v_generala == 1)
        {
            v_generala = 6;


        }

        cont = 0;
        valor = 0;
      

    }


    v_generala = 6;
    
    // Full
    i= 31;
    for(i=31; i<56; i++)
    {
        for(j=0; j<6; j++)
        {
            if(j==0)
            {
                pc_jugadas[i][j] = 25;
            }
            else
            {
                if(j!=4 && j!=5)
                {
                    pc_jugadas[i][j] = v_generala;
                }   
                else
                {
                    pc_jugadas[i][j] = v_generala -1;
                }
            }
        }
        v_generala = v_generala - 1;
         if(v_generala == 1)
        {
            v_generala = 6;

        }
    }


    // Inicialización del generador de números aleatorios
    srand((unsigned int)time(NULL));

    while(jugar_compu = menu_juego())
    {
       
        while(turno < 6)
        {

            printf("turno %d ---\n\n", turno);
            
            // JUGADOR 1
            system("cls");
            printf("--- JUGADOR 1 - RONDA %d ---\n\n", turno);
            tirar_dado(dado, 5, jugar_compu);
            imprimir_dado(dado, 5, p1_combinaciones);
            relanzar(dado, 5, p1_combinaciones, 1, turno);
            elegir_combo(dado, 5, p1_combinaciones, p1_puntuaciones, 1, turno);
            
            system("cls");
            printf("--- JUGADOR 1 - RONDA %d ---\n\n", turno);
            imprimir_puntuacion(p1_puntuaciones, 1);



            printf("\nPresiona cualquier tecla para cambiar de jugador.");
            system("pause > nul");
            system("cls");

            
            // JUGADOR P2
            if (jugar_compu == 1)
            {
                system("cls");
                printf("--- JUGADOR 2 - RONDA %d ---\n\n", turno);
                tirar_dado(dado, 5, jugar_compu);
                imprimir_dado(dado, 5, p2_combinaciones);
                relanzar(dado, 5, p2_combinaciones, 2, turno);
                elegir_combo(dado, 5, p2_combinaciones, p2_puntuaciones, 2, turno);
            
                system("cls");
                printf("--- JUGADOR 2 - RONDA %d ---\n\n", turno);
                imprimir_puntuacion(p2_puntuaciones, 2);

                turno++;

                system("pause\n");
                system("cls");

            }
            else
            {    


                if (jugar_compu == 2)
                {
                    printf("Dentro de Jugar compu");
                    printf("--- JUGADOR PC - RONDA %d ---\n\n", turno);

                    puntosjug1 = devolver_puntuacion(p1_puntuaciones, 1);
                    printf("Punto jugador 1 %d\n", puntosjug1);

                    do{
                        puntos_tmp = puntuacion_compu;

                        jugada = rand() % 56;
                        
                        puntos_tmp = puntos_tmp + pc_jugadas[jugada][0];
                        
                    }while (puntosjug1 > puntos_tmp && pc_jugadas[jugada][7] == 'X');


                    puntuacion_compu = puntos_tmp;
                 
                    switch (jugada)
                    {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                        
                        for(k=0; k<6; k++)
                        {
                            pc_jugadas[k][7] = 'X';
                        }
                        break;
                    
                    }

                    if (puntuacion_compu > puntosjug1)
                    {
                        i=1; 
                    
                        // Carga la jugada de la compu en el dado                    
                        for(i=1; i<6; i++)
                        {
                            dado[i-1] = pc_jugadas[jugada][i];
                            printf("Imprime dado compu e i  %d\n %d\n", dado[i-1], i);
                        }

                        
                        imprimir_dado_compu(dado, 5);
                        printf("Sale de imprimir dado compu");
                        printf("El puntaje del jugador %d es ahora %d.\n", jugar_compu, puntuacion_compu);


                        system("pause > nul");
                        system("cls");
                        printf("turno %d\n", turno);



                        system("pause\n");


                        i=0;

                        for(i=0; i<6; i++)
                        {
                            dado[i] = 0;
                        }    
                        turno++;


                    }
                
                    
                }
                
                
             }

                

        }

        if(jugar_compu == 2)
        {
            finalizar_juego_compu(puntosjug1, puntuacion_compu);
        }
        else{

            finalizar_juego(p1_puntuaciones, p2_puntuaciones);
        }    
    }
    printf("¡Adiós!\n\n");
}

/*
Función: menu_juego                                         
Muestra el menú principal del juego Generala. 
*/
int menu_juego(void)
{
    int opcion = 0, jugar = 0;

    printf("-- Generala! --\n\n");
    
    do
    {
        do
        {
            printf("Elija una opción ingresando el número correspondiente:\n1. Imprimir las reglas del juego\n2. Iniciar un juego de Generala con la PC\n3. Iniciar un juego de Generala con 2 jugadores\n4.Salir\n");
            scanf("%d", &opcion);
        }
        while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);

        switch (opcion)
        {
        case 1:
            system("cls");
            printf("-- Generala! --\n");
            printf("\nReglas del juego:\n\n");
            printf("La tarjeta de puntuación consta de dos secciones, una superior y una inferior. Un total de trece casillas o combinaciones de puntuación se dividen entre las secciones. La sección superior se puntúa sumando el valor de los dados que coinciden con las caras de la casilla. Por ejemplo, si se lanzan cuatro 3's, la puntuación es 12. Una vez puntuada una casilla, no puede cambiarse. Si la suma en la sección superior es igual o superior a 63, se añaden 35 puntos de bonificación al total del jugador. La sección inferior contiene combinaciones de tipo póker.\n\n");
            break;
        case 2: 
            jugar = 2;
            break;
        case 3:
            jugar = 1;
            break;
        case 4:
            jugar = 0;
            break;    
        default:
            printf("Por favor, escriba una opción válida.\n");
        }
    }
    while (opcion != 2 && opcion != 3 && opcion != 4);
    system("cls");
    
    return jugar;
}

/*
Función: tirar_dado                                         
Lanza los dados de forma aleatoria.            
*/
void tirar_dado(int dado[5], int tamano, int quien_juega)
{
    char continuar = 0;
    int indice = 0;

    if (quien_juega == 1 || quien_juega == 3)
    {
        printf("Presione cualquier tecla para lanzar los dados.\n\n");
        system("pause > nul");
    }    
    
    for (indice = 0; indice < tamano; ++indice)
    {
        dado[indice] = rand() % 6 + 1;
        printf("%d\n\n", dado[indice]);
    }
   

}

/*
Función: compu_tirar_dado                                         
Lanza los dados de forma aleatoria.            
*/
void compu_tirar_dado(int dado[5], int tamano, int quien_juega)
{
    char continuar = 0;
    int indice = 0;

    if (quien_juega == 1 || quien_juega == 3)
    {
        printf("Presione cualquier tecla para lanzar los dados.\n\n");
        system("pause > nul");
    }    
    
    for (indice = 0; indice < tamano; ++indice)
    {

        printf("\n%d\n", dado[indice]);
    }

   

}

/*
Función: imprimir_dado                                      
Imprime los dados en formato ASCII.            
*/
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

/*
Función: imprimir_dado                                      
Imprime los dados en formato ASCII.            
*/
void imprimir_dado_compu(int dado[5], int tamano)
{
    int indice = 0;
    int linea = 1;

    //printf("Estoy imprimir dado");

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


}




/*
Función: relanzar                                                 
Pide al usuario si desea y cuántos dados relanzar, luego actualiza el array de dados.    
*/
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

/*
Función: relanzar                                           
Pide al usuario si desea y cuántos dados relanzar, luego actualiza el array de dados.    
*/
void relanzar_compu(int dado[5], int tamano, int combo_c[13], int jugador, int ronda)
{
    int cantidad = 0;  // Cantidad de dados a relanzar
    int indice = 0;    // Índice para iteraciones
    int suma = 0, i = 0;
    int VaARelanzar = 0;
    int cantRelanzar = 0;
    int cantDadoRelanzar = 0;
    int dadoRelanzar = 0;


    printf("Dentro de relanzar compu");   
    for (indice = 0; indice < 2; indice++)  // Permite hasta dos oportunidades para relanzar dados
    {
       
        // si va a reelanzar el dado
        VaARelanzar = rand() % 6 + 1;
        printf("VaARelanzar %d\n", VaARelanzar);
        
        //Si el valor es 2 o 3 va a relanzar el dado
        if (VaARelanzar == 2 || VaARelanzar == 3)
        {
            
            printf("\nPC decide relanzar el dado.Presiona cualquier tecla para continuar.");
                  
            system("pause > nul");
            system("cls");

            // Cantidad de Dados a relanzar;
            cantDadoRelanzar = rand() % 6 + 1;
            printf("cantDadoRelanzar %d\n", cantDadoRelanzar);

           for(i=0; i < cantDadoRelanzar; i++)
           {
                //Determina randomicamente que nro. de dado quiere relanzar
                dadoRelanzar = rand() % 6 + 1;
                printf("Nro. de dado a relanzar %d\n", dadoRelanzar);
                dado[dadoRelanzar - 1] = rand() % 6 + 1;  // Actualiza el valor del dado seleccionado
                printf("despues de cargar el dado");
                            
           }

           system("cls");
           printf("RELANZA PC--- JUGADOR %d - RONDA %d ---\n\n", jugador, ronda);
           system("pause \n");


           printf("\nPresiona cualquier tecla PARA VER DADO RELANZADO");
           
           system("pause > nul");
           imprimir_dado(dado, tamano, combo_c);  // Reimprime los dados después de relanzar

           system("pause \n");

        }
        else
        {
            if(VaARelanzar != 2 && VaARelanzar != 3)
            {
                printf("Dentro del Else");

                indice = 2;

                printf("\nPC decide no relanzar.Presiona cualquier tecla para continuar.");
                  
                    system("pause > nul");
                    system("cls");
            }    
        }
    }
}



/*
Función: elegir_combo                                               
Solicita al usuario que elija una combinación y verifica si ya ha sido utilizada.           
*/
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

/*
Función: elegir_combo_compu                                                       
Solicita al usuario que elija una combinación y verifica si ya ha sido utilizada.           
*/
void ver_combo_compu(int dado[5], int tamano, int combo_c[13], int puntuaciones[13], int jugador, int ronda)
{
    int seleccion = 0, es_combo_valido_1 = 0, es_combo_valido_2 = 0,  es_combo_valido_3, es_combo_valido_4 = 0,es_combo_valido_5 = 0, es_combo_valido_6 = 0, es_combo_valido_trio = 0;
    int es_combo_valido_poker = 0, es_combo_valido_full = 0, es_combo_valido_escaCorta = 0, es_combo_valido_escaLarga = 0, es_combo_valido_Generala = 0, es_combo_valido_Azar = 0; 
    int i=0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0,ctrio = 0, contador=0, j=0, k=0, contador2=0, contgenerala =0;

    system("cls");
    printf("--- JUGADOR %d - RONDA %d ---\n\n", jugador, ronda);
    imprimir_dado(dado, tamano, combo_c);

                for(i=0; i<5; i++)
                {
                    switch (dado[i])
                        {
                            case 1:
                                cont1 = cont1 + 1;
                                break;
                            case 2:    
                                cont2 = cont2 + 1;
                                break;   
                            case 3:    
                                cont2 = cont3 + 1;
                                break;   
                            case 4:    
                                cont2 = cont4 + 1;
                                break;   
                            case 5:    
                                cont2 = cont5 + 1;
                                break;   
                            case 6:    
                                cont2 = cont6 + 1;
                                break;                        
                                                 
                        }
                        
                   }   

                if(cont1 > 0)
                {
                    es_combo_valido_1 = unos(dado, combo_c, puntuaciones);
                }
                  
                if(cont2 > 0)
                {
                    es_combo_valido_2 = doses(dado, combo_c, puntuaciones);
                }

                if(cont3 > 0)
                {
                    es_combo_valido_3 = treses(dado, combo_c, puntuaciones);
                }   

                if(cont4 > 0)
                {
                    es_combo_valido_4 = cuatros(dado, combo_c, puntuaciones);
                }

                if(cont5 > 0)
                {
                    es_combo_valido_5 = cincos(dado, combo_c, puntuaciones);
                } 
                
                if(cont6 > 0)
                {
                    es_combo_valido_6 = seises(dado, combo_c, puntuaciones);    
                }

                if(cont1 == 3 || cont2 == 3 || cont3 == 3 || cont4 == 3 || cont5 == 3 || cont6 == 3)
                {
                    es_combo_valido_trio = trio(dado, combo_c, puntuaciones);
                    ctrio = 1;
                }

                if(cont1 == 4 || cont2 == 4 || cont3 == 4 || cont4 == 4 || cont5 == 4 || cont6 == 4)
                {
                     es_combo_valido_poker = poker(dado, combo_c, puntuaciones);
                }

                if(ctrio == 1)
                {
                    for(j=0; j<5; j++)
                    {
                        for(k=0; k<5; k++)
                        {
                            dado[j] == dado[j+k+1];
                            contador = contador + 1;
                        }
                        if(contador == 3)
                        {
                            i = 5;
                        }
                        
                    }
                   
                    if(contador == 3)
                    {
                         j = 0;
                         k = 0;

                        for(j=0; j<5; j++)
                        {
                             for(k=0; k<5; k++)
                            {
                                dado[j] == dado[j+k+1];
                                contador2 = contador2 + 1;
                            }
                            if(contador == 2)
                            {
                                 es_combo_valido_full = full(dado, combo_c, puntuaciones);
                                 i = 5;
                            } 

                        }
                        

                    }
                }
                
   
                es_combo_valido_escaCorta = escalera_corta(dado, combo_c, puntuaciones);
      
                es_combo_valido_escaLarga = escalera_larga(dado, combo_c, puntuaciones);


                
        
                es_combo_valido_Azar = azar(dado, combo_c, puntuaciones);


                i=0;
                for(i=0; i<14; i++)
                {
                    printf("puntuaciones %d\n", puntuaciones[i]);
                }   
             
       
}



 /*
Función: imprimir_combos                                                 
Imprime las opciones de combos, con X si ya se han utilizado.                            
*/
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

 /*
Función: imprimir_puntuacion                                           
Imprime la puntuación del jugador            
*/
void imprimir_puntuacion(int puntuaciones[13], int jugador)
{
    int suma = 0, indice = 0;
    for (indice= 0; indice<13; indice++)
    {
        suma = puntuaciones[indice] + suma;
    }
    printf("El puntaje del jugador %d es ahora %d.\n", jugador, suma);
}

/*
Función: imprimir_puntuacion                             
Descripción: Imprime la puntuación del jugador            
*/
int devolver_puntuacion(int puntuaciones[13], int jugador)
{
    int suma = 0, indice = 0;
    for (indice= 0; indice<13; indice++)
    {
        suma = puntuaciones[indice] + suma;
    }
    return suma;
}

 /*
Función: unos (int dado[5], int combo_c[13], int puntos[13])
Suma los unos y lo añade al array de puntos   
*/
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

 /*
Función: doses (int dado[5], int combo_c[13], int puntos[13])                  
Suma los doses y lo añade al array de puntos  
*/
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

 /*
Función: treses (int dado[5], int combo_c[13], int puntos[13])
Suma los treses y lo añade al array de puntos 
*/
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

 /*
Función: cuatros (int dado[5], int combo_c[13], int puntos[13])
Suma los cuatros y lo añade al array de puntos*
*/
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

 /*
Función: cincos (int dado[5], int combo_c[13], int puntos[13])
Suma los cincos y lo añade al array de puntos *
*/
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
Función: seises (int dado[5], int combo_c[13], int puntos[13])
Suma los seises y lo añade al array de puntos 
*/
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

 /*
Función: trio (int dado[5],int combo_c[13], int puntos[13])				 
Verifica si hay un trío y luego suma los dados
*/
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

 /*
 * Función: poker (int dado[5],int combo_c[13], int puntos[13])				 
Descripción: Verifica si hay un poker y luego suma los dados*
*/
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

 /*
Función: full(int dado[5],int combo_c[13], int puntos[13])				 
Verifica si hay un full y luego otorga 25 puntos 
*/
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

 /*
Función: escalera_corta(int dado[5],int combo_c[13], int puntos[13])				                 
Verifica si hay una escalera corta y otorga 30 puntos 
*/
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

 /*
Función: escalera_larga	 (int dado[5],int combo_c[13], int puntos[13])				 
Verifica si hay una escalera larga y otorga 40 puntos 
*/
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

 /*
Función: generala(int dado[5],int combo_c[13], int puntos[13])				 
Verifica si hay una generala y otorga 50 puntos
*/
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

 /*
Función: azar(int dado[5],int combo_c[13], int puntos[13])				                 
Suma todos los dados como puntos              
*/
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

 /*
Función: finalizar_juego (int p1_puntos[13], int p2_puntos[13])             
Añade 35 puntos extra si es aplicable, muestra el ganador 
*/
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

/*
Función: finalizar_juego_compu (int p1_puntos[13], int p2_puntos[13]) *
Añade 35 puntos extra si es aplicable, muestra el ganador 
*/
void finalizar_juego_compu(int puntosJug1, int puntosJug2)
{
    int suma1 = 0, suma2 = 0, ganador = 0, indice=0;

    printf("************************************************ FIN DEL JUEGO ******************************************************\n");
    
    suma1 = puntosJug1;
    suma2 = puntosJug2;

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

