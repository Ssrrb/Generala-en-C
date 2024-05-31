# Generala
Un proyecto de programación en C  de pequeña escala para la clase de TAI 2024 ,diseñado para facilitar un juego de Generala para un jugador vs la maquina en un entorno de consola. 
Cuenta con una representación dinámica de los dados , mejorando la experiencia visual con cada lanzamiento. 
El programa está diseñado para monitorear las combinaciones que han sido utilizadas previamente, evitando su repetición. Automáticamente verifica cada tirada para confirmar 
si el jugador ha logrado la combinación requerida y asigna puntos basados en estos logros.
### Descripción de la manera en que se planeó inicialmente el desarrollo del programa

Inicialmente con Mateo, planeamos el desarrollo del programa de Generala en varias etapas clave. Primero, definimos en papel los objetivos del juego y cómo queríamos que sea el juego con cada funcion. Establecimos durante el planeamiento que usaríamos arrays para representar los dados y las puntuaciones de cada jugador, así como para controlar las combinaciones utilizadas.

Identificamos las funciones principales necesarias para el funcionamiento del juego:
- `juego_principal()`: Gestiona el flujo del juego, alternando entre los jugadores y controlando el número de turnos.
- `menu_juego()`: Muestra las opciones al usuario y controla la entrada.
- `tirar_dado()`, `imprimir_dado()`, `relanzar()`: Manejan los lanzamientos de los dados.
- `elegir_combo()`: Permite al jugador elegir una combinación de puntuación y verifica si ya ha sido utilizada.
- `imprimir_puntuacion()`, `finalizar_juego()`: Presentan las puntuaciones y determinan el ganador del juego.


### Informe final de cómo efectivamente se realizó el desarrollo del programa

El desarrollo del programa se llevó a cabo siguiendo el plan inicial con algunos ajustes necesarios a traves de incontables horas de trabajo, investigacion de la documentacion, inspiracion en videos de youtube correcciones de la inteligencia artificial y muchos commits fallidos en nuestro repositorio. Revisamos nuestro planteamiento en papel y luego implementamos todas las funciones planificadas y fuimos ajustando la logica probando y probando con el tiempo.

#### Dificultades encontradas:
1.  **Implementación de la Jugada Automática de la Máquina**: Una de las dificultades más grandes que enfrentamos fue implementar la lógica para que la máquina pudiera jugar automáticamente.
2. **Validación de Entradas**: Asegurar que las entradas del usuario fueran robustas y manejar errores de entrada incorrecta. Esta es una de nuestras debilidades en el proyecto
3. **Lógica de Puntuación**: Cada combinación tiene su propia lógica específica para calcular los puntos basados en los valores de los dados. Además, una vez utilizada una combinación, debía ser marcada como usada para evitar su reutilización. Esto tardo un monton de tiempo y trabajo


### Descripción de las estructuras de datos utilizadas para resolver el problema

Para resolver el problema y manejar la lógica del juego de Generala, utilizamos varias estructuras de datos clave:

- **Arrays de enteros**:
  - `int dado[5]`: Representa los valores de los cinco dados lanzados en cada turno.
  - `int p1_puntuaciones[13], p2_puntuaciones[13]`: Almacenan las puntuaciones para cada una de las trece combinaciones posibles por jugador.
  - `int p1_combinaciones[13], p2_combinaciones[13]`: Indican si una combinación ha sido ya utilizada por los jugadores (0 no usada, 1 usada).

Estas estructuras de datos nos permitieron mantener un seguimiento eficiente del estado del juego, las puntuaciones de cada jugador y las combinaciones utilizadas, facilitando la implementación de la lógica del juego y la verificación del cumplimiento de las reglas.

- **Implementación de la Jugada Automática de la Máquina**:
La solucion de este problema luego de mucha prueba y error, fue la creacion de una matriz con jugadas precargadas para jugar de manera automatica contra la computadora.

### Resumen de la lógica utilizada para verificar el cumplimiento de las reglas del juego

En el juego de Generala, Mateo y yo utilizamos varias estructuras de datos y funciones para asegurar que las reglas se cumplan correctamente.

#### Estructuras de Datos Clave

- **`int dado[5]`**: Representa los valores de los cinco dados lanzados en cada turno.
- **`int p1_puntuaciones[13]`, `int p2_puntuaciones[13]`**: Almacenan las puntuaciones para cada una de las trece combinaciones posibles por jugador.
- **`int p1_combinaciones[13]`, `int p2_combinaciones[13]`**: Indican si una combinación ha sido ya utilizada por los jugadores (0 no usada, 1 usada).

#### Funciones Principales

1. **Inicio y Control del Juego**:
   - **`juego_principal()`**: Gestiona el flujo principal del juego, alternando entre los jugadores y controlando el número de turnos.
   - **`menu_juego()`**: Muestra el menú principal del juego y permite al usuario iniciar una nueva partida o salir.

2. **Lanzamiento y Relanzamiento de Dados**:
   - **`tirar_dado(int dado[], int tamano, int quien_juega)`**: Lanza los dados de forma aleatoria.
   - **`relanzar(int dado[], int tamano, int combo_c[], int jugador, int ronda)`**: Permite al jugador relanzar dados seleccionados hasta dos veces.
   - **`relanzar_compu(int dado[], int tamano, int combo_c[], int jugador, int ronda)`**: Permite a la computadora decidir si quiere relanzar dados.

3. **Selección de Combinaciones y Puntuaciones**:
   - **`elegir_combo(int dado[], int tamano, int combo_c[], int puntuaciones[], int jugador, int ronda)`**: Permite al jugador seleccionar una combinación de puntuación y actualiza la puntuación si la combinación no ha sido utilizada previamente.
   - **`imprimir_combos(int combo_c[])`**: Muestra las combinaciones disponibles y marca las que ya se han utilizado.

4. **Cálculo y Verificación de Combinaciones**:
   - **Combinaciones Simples**:
     - **`unos(int dado[], int combo_c[], int puntos[])`**
     - **`doses(int dado[], int combo_c[], int puntos[])`**
     - **`treses(int dado[], int combo_c[], int puntos[])`**
     - **`cuatros(int dado[], int combo_c[], int puntos[])`**
     - **`cincos(int dado[], int combo_c[], int puntos[])`**
     - **`seises(int dado[], int combo_c[], int puntos[])`**
   - **Combinaciones Complejas**:
     - **`trio(int dado[], int combo_c[], int puntos[])`**
     - **`poker(int dado[], int combo_c[], int puntos[])`**
     - **`full(int dado[], int combo_c[], int puntos[])`**
     - **`escalera_corta(int dado[], int combo_c[], int puntos[])`**
     - **`escalera_larga(int dado[], int combo_c[], int puntos[])`**
     - **`generala(int dado[], int combo_c[], int puntos[])`**

5. **Impresión y Finalización del Juego**:
   - **`imprimir_dado(int dado[], int tamano, int combos_c[])`**: Imprime el estado actual de los dados.
   - **`imprimir_puntuacion(int puntuaciones[], int jugador)`**: Imprime la puntuación acumulada del jugador.
   - **`finalizar_juego(int p1_puntos[], int p2_puntos[])`**: Finaliza el juego y muestra el ganador basado en la puntuación total.
   - **`finalizar_juego_compu(int puntosJug1, int puntosJug2)`**: Finaliza el juego cuando uno de los jugadores es la computadora y muestra el ganador.

### Resumen de la Lógica de Verificación

1. **Control de Turnos**: Cada jugador tiene 13 turnos en los que puede lanzar los dados hasta tres veces.
2. **Selección de Combinaciones**: Los jugadores eligen combinaciones para puntuar, verificando si ya han sido usadas.
3. **Cálculo de Puntuaciones**: Cada combinación tiene su lógica específica para calcular los puntos.
4. **Actualización y Comparación de Puntuaciones**: Al finalizar el juego, se comparan las puntuaciones totales de ambos jugadores para determinar el ganador.

## Estructura del Proyecto
Para este proyecto de Generala, organizamos nuestro código en varios archivos diferentes: generala.h, generala.c, main.c, y readme.md.
1. Archivo generala.h
Propósito: Este archivo se conoce como un archivo de encabezado (header file).
Contenido: Contiene las declaraciones de las funciones y las definiciones de las constantes que utilizamos en el programa.

2. Archivo generala.c
Propósito: Este archivo contiene la implementación de las funciones declaradas en generala.h.
Contenido: Aquí se define la lógica detallada del juego, incluyendo cómo se lanzan los dados, cómo se imprimen los resultados, cómo se gestionan los relanzamientos y cómo se calculan y actualizan las puntuaciones.

3. Archivo main.c
Propósito: Este archivo contiene la función main(), que es el punto de entrada del programa.

4. Archivo readme.md
Propósito: Este archivo de documentación proporciona una descripción general del proyecto, instrucciones de compilación y ejecución, y cualquier otra información relevante.

Este proyecto no solo permitió poner en práctica conceptos de programación en C, sino también desarrollar habilidades en planificación, resolución de problemas y trabajo en equipo con mi compa la maquina de programacion Mateo Rios y yo Sebastian Rojas un humilde debugeador, muchas gracias.
