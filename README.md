# Generala
Un proyecto de programación en C  de pequeña escala para la clase de TAI 2024 ,diseñado para facilitar un juego de Generala para dos jugadores directamente en un entorno de consola. 
Cuenta con una representación dinámica de los dados , mejorando la experiencia visual con cada lanzamiento. 
El programa está diseñado para monitorear meticulosamente qué combinaciones han sido utilizadas previamente, evitando su repetición. Automáticamente verifica cada tirada para confirmar 
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

### Resumen de la lógica utilizada para verificar el cumplimiento de las reglas del juego

La lógica del juego se basa en varios componentes que garantizan el cumplimiento de las reglas:

1. **Control de Turnos**: Cada jugador tiene 13 turnos en los que puede lanzar los dados hasta tres veces para intentar lograr la mejor combinación posible.
2. **Selección de Combinaciones**: Después de cada lanzamiento, el jugador elige qué combinación usar para esa ronda, si es que no ha sido seleccionada previamente.
3. **Cálculo de Puntuaciones**: Cada combinación tiene una lógica específica para calcular los puntos basados en los valores de los dados, implementada en funciones como `unos()`, `doses()`, `treses()`, etc.
4. **Verificación de Combinaciones**: Antes de asignar puntos, se verifica si la combinación elegida ya ha sido utilizada por el jugador para asegurar que cada combinación se use solo una vez.
