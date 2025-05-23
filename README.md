# Laboratorio 5 – Sistemas Operativos 2025
### Universidad Del Valle de Guatemala  
**Nombre:** Cindy Gualim  
**Curso:** Sistemas Operativos  
**Fecha de entrega:** 23 de mayo de 2025

---

##  Descripción general

Este laboratorio tiene como objetivo simular el consumo controlado de un recurso compartido entre múltiples hilos utilizando mecanismos de sincronización como **semáforos** y **monitores**. Se desarrollaron dos programas independientes que cumplen con lo solicitado en el documento oficial del laboratorio.

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
