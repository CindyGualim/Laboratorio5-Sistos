# Laboratorio 5 – Sistemas Operativos 2025
### Universidad Del Valle de Guatemala  
**Nombre:** Cindy Gualim  
**Curso:** Sistemas Operativos  
**Fecha de entrega:** 23 de mayo de 2025

---

##  Descripción general

Este laboratorio tiene como objetivo simular el consumo controlado de un recurso compartido entre múltiples hilos utilizando mecanismos de sincronización como **semáforos** y **monitores**. Se desarrollaron dos programas independientes que cumplen con lo solicitado en el documento oficial del laboratorio.

# Laboratorio 5 – Sistemas Operativos 2025
**Nombre:** Cindy Gualim  
**Curso:** Sistemas Operativos  
**Fecha de entrega:** 23 de mayo de 2025

---

## 🧠 Descripción general

Este laboratorio consiste en simular el uso compartido de un recurso entre múltiples hilos (threads) en C, utilizando mecanismos de sincronización. Se desarrollaron dos programas: uno con semáforos y otro con monitor, cumpliendo con todos los puntos requeridos por el documento oficial.

---

##  Cumplimiento del PDF – párrafo por párrafo

### . “...gestionar el consumo de un recurso digital... número de threads ajustable... número de iteraciones ajustable...”
- **Cómo se cumple:**  
  Se creó el archivo `config.h` donde se definieron las constantes `N_RECURSOS`, `N_THREADS`, `N_ITER` y `MAX_PETICION`. Esto permite modificar fácilmente el comportamiento de los programas sin tocar su lógica interna.

---

### . “Su primer programa debe usar semáforos de Pthreads para regular el consumo y devolución de recursos por múltiples hilos...”
- **Cómo se cumple:**  
  En el archivo `sem_solo_uno.c`, se utiliza `sem_t`, `sem_init`, `sem_wait` y `sem_post` para implementar un control concurrente con semáforos. Se lanzan `N_THREADS` y cada uno consume y devuelve un recurso en cada iteración.

---

### . “...deberá producir una bitácora con mensajes representando las acciones de los hilos... identificando cada acción por el hilo que la ejecuta y por la iteración...”
- **Cómo se cumple:**  
  Se creó el archivo `bitacora_semaforos.txt`, donde se redirige la salida del programa con semáforos. Cada hilo imprime claramente cuándo consume y cuándo devuelve un recurso, junto con su ID e iteración correspondiente.

---

### . “Su segundo programa mejorará este esquema incluyendo funciones decrease_count e increase_count... usando un monitor...”
- **Cómo se cumple:**  
  En el archivo `monitor_recursos.c` se implementan las funciones `decrease_count(int count)` e `increase_count(int count)` utilizando `pthread_mutex_t` y `pthread_cond_t`. El acceso a los recursos es controlado con un monitor que permite a los hilos esperar si no hay suficientes recursos disponibles.

---

### . “...producir una bitácora con mensajes representando las acciones de los hilos…” (segundo programa)
- **Cómo se cumple:**  
  Se creó el archivo `bitacora_monitor.txt`, que registra detalladamente el comportamiento de los hilos en el segundo programa. Se indica qué hilo pidió cuántos recursos, en qué iteración, y cuándo los devolvió.

---

### . “...número de threads ajustable, número de iteraciones ajustable, recurso representado por una cantidad (int) también ajustable…”
- **Cómo se cumple:**  
  Este requerimiento se cubre completamente mediante el uso del archivo `config.h`, incluido en ambos programas. Cambiar los valores de `N_THREADS`, `N_ITER`, `N_RECURSOS` o `MAX_PETICION` es sencillo y no requiere modificar el resto del código.

---

### . “...la fecha de entrega es el viernes 23 de mayo de 2025…”
- **Cómo se cumple:**  
  Todos los archivos fueron creados, probados, y subidos al repositorio antes de la fecha indicada. El laboratorio está completo y funcional para su evaluación.




---

##  Requisitos y cómo se cumplieron

### 1. Crear un programa usando semáforos
- **Archivo:** `sem_solo_uno.c`
- **Lo que hace:** Crea múltiples hilos (`N_THREADS`) que consumen y devuelven un recurso compartido, controlado con un semáforo POSIX.
- **Cómo se cumple:** Se usa `sem_t`, `sem_init`, `sem_wait` y `sem_post` para controlar el acceso a `N_RECURSOS`.

### 2. Crear un programa usando monitor con funciones `decrease_count()` e `increase_count()`
- **Archivo:** `monitor_recursos.c`
- **Lo que hace:** Crea múltiples hilos que pueden pedir varios recursos a la vez (entre 1 y `MAX_PETICION`). Si no hay suficientes, el hilo espera hasta que los recursos estén disponibles.
- **Cómo se cumple:** Se implementa un monitor con `pthread_mutex_t` y `pthread_cond_t`, y se crean las funciones pedidas en el enunciado (`decrease_count` y `increase_count`).

### 3. Parámetros ajustables
- **Archivo:** `config.h`
- **Lo que hace:** Define parámetros como `N_THREADS`, `N_RECURSOS`, `N_ITER`, `MAX_PETICION`.
- **Cómo se cumple:** Ambos programas incluyen este archivo y usan estas constantes para que sea fácil cambiar los valores sin modificar el código principal.

### 4. Bitácoras detalladas
- **Archivos generados:**
  - `bitacora_semaforos.txt` para el primer programa.
  - `bitacora_monitor.txt` para el segundo programa.
- **Lo que hacen:** Registran cada acción de los hilos: cuándo consumen y devuelven recursos, indicando su ID y número de iteración.
- **Cómo se cumple:** Se utiliza `printf()` en cada punto crítico del código y se redirige la salida a los archivos de bitácora.

---

##  Instrucciones para compilar y ejecutar

```bash
# Compilar programa con semáforos
gcc -pthread sem_solo_uno.c -o sem_solo_uno

# Ejecutar y generar bitácora
./sem_solo_uno > bitacora_semaforos.txt

# Compilar programa con monitor
gcc -pthread monitor_recursos.c -o monitor_recursos

# Ejecutar y generar bitácora
./monitor_recursos > bitacora_monitor.txt
