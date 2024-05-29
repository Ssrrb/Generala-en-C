#ifndef GENERALA_H
#define GENERALA_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inicia y ejecuta el juego principal de Generala.
void juego_principal(void);

// Muestra y gestiona el menú principal del juego.
int menu_juego(void);

// Lanza un número especificado de dados de forma aleatoria.
void tirar_dado(int dado[5], int tamano, int quien_juega);

// Imprime el estado actual de los dados en formato ASCII.
void imprimir_dado(int dado[5], int tamano, int combos_c[13]);

// Imprime los dados del juego de la computadora
void imprimir_dado_compu(int dado[5], int tamano);

// Permite al jugador decidir qué dados quiere volver a lanzar.
void relanzar(int dado[5], int tamano, int combo_c[13], int jugador, int ronda);

// Permite a a la computadora decidir si quiere volver a lanzar
void relanzar_compu(int dado[5], int tamano, int combo_c[13], int jugador, int ronda);

// Permite al jugador seleccionar una combinación de puntuación basada en el resultado de los dados.
void elegir_combo(int dado[5], int tamano, int combo_c[13], int puntuaciones[13], int jugador, int ronda);

// Imprime la puntuación actual del jugador.
void imprimir_puntuacion(int puntuaciones[13], int jugador);

// Devuelve la puntuacion del jugador 1
int devolver_puntuacion(int puntuaciones[13], int jugador);

// Muestra las combinaciones disponibles y marca las que ya se han utilizado.
void imprimir_combos(int combo_c[13]);

// Calcula y actualiza la puntuación basada en la cantidad de unos.
int unos(int dado[5], int combo_c[13], int puntos[13]);

// Calcula y actualiza la puntuación basada en la cantidad de doses.
int doses(int dado[5], int combo_c[13], int puntos[13]);

// Calcula y actualiza la puntuación basada en la cantidad de treses.
int treses(int dado[5], int combo_c[13], int puntos[13]);

// Calcula y actualiza la puntuación basada en la cantidad de cuatros.
int cuatros(int dado[5], int combo_c[13], int puntos[13]);

// Calcula y actualiza la puntuación basada en la cantidad de cincos.
int cincos(int dado[5], int combo_c[13], int puntos[13]);

// Calcula y actualiza la puntuación basada en la cantidad de seises.
int seises(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa un trío de dados iguales.
int trio(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa cuatro dados iguales.
int poker(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa un full house (un trío y un par).
int full(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa una escalera corta (cuatro en secuencia).
int escalera_corta(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa una escalera larga (cinco en secuencia).
int escalera_larga(int dado[5], int combo_c[13], int puntos[13]);

// Evalúa y puntúa una generala (cinco dados iguales).
int generala(int dado[5], int combo_c[13], int puntos[13]);

// Permite sumar la puntuación de todos los dados sin condiciones específicas.
int azar(int dado[5], int combo_c[13], int puntos[13]);

// Finaliza el juego y muestra el ganador basado en la puntuación total.
void finalizar_juego(int p1_puntos[13], int p2_puntos[13]);

// Finaliza el juego con la computadora
void finalizar_juego_compu(int puntosJug1, int puntosJug2);

#endif // !GENERALA_H
