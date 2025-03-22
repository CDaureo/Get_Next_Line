# Get Next Line

## 📌 Introducción

El proyecto **Get Next Line** te permitirá profundizar en el manejo de archivos en C y comprender el concepto de **variables estáticas**. Implementarás una función que lee un archivo línea por línea a través de un **file descriptor**, lo que es fundamental en la programación de bajo nivel.

---

## 📜 Instrucciones Generales

✅ El proyecto debe estar escrito en **C**.

✅ Debe seguir la **Norma** de codificación establecida.

✅ No debe producir errores inesperados (*segfault, bus error, double free, etc.*).

✅ La memoria dinámica utilizada debe ser liberada adecuadamente (**no memory leaks**).

✅ Se debe entregar un **Makefile** con las siguientes reglas obligatorias:
   - `$(NAME)`, `all`, `clean`, `fclean`, `re`.

✅ No se permite el uso de **lseek()** ni de **variables globales**.

✅ No se permite el uso de **libft** en este proyecto.

✅ Se recomienda crear programas de prueba para verificar el correcto funcionamiento.

✅ La entrega se realizará en el **repositorio Git** asignado.

---

## 🚀 Parte Obligatoria

### 🏷 Nombre de la función
**get_next_line**

### 📌 Prototipo
```c
char *get_next_line(int fd);
```

### 📂 Archivos a entregar
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

### 📜 Parámetros
- `fd`: **File descriptor** del cual se leerá.

### 🎯 Valor de retorno
- **Devuelve** la línea leída.
- **Retorna NULL** si hay un error o se alcanza el final del archivo.

### 📜 Funciones autorizadas
- `read()`
- `malloc()`
- `free()`

### 📖 Descripción
- **get_next_line()** debe leer y devolver **línea por línea** el contenido del archivo.
- La línea devuelta **debe incluir el salto de línea** (`\n`), excepto si se ha alcanzado el final del archivo.
- Debe manejar correctamente la lectura desde **archivos y entrada estándar (stdin)**.
- La función debe poder **compilarse con diferentes tamaños de buffer** utilizando el flag:
  ```sh
  -D BUFFER_SIZE=<valor>
  ```

Ejemplo de compilación con un buffer de 42:
```sh
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c
```

### ❌ Restricciones
- **Prohibido usar `lseek()`**.
- **No se permiten variables globales**.
- **No leer todo el archivo de una sola vez**, se debe leer línea por línea.

---

## 🏆 Retos Adicionales

🔹 ¿Funciona correctamente tu `get_next_line()` con distintos tamaños de buffer? Pruébalo con valores como **1, 42, 9999, 10000000**.

🔹 ¿Tu implementación es eficiente? Asegúrate de **leer lo mínimo necesario** y devolver la línea **tan pronto como encuentres un salto de línea (`\n`)**.

🔹 ¿Cómo manejarías la lectura de archivos binarios? ¡Piensa en ello!

---

## 🎯 Conclusión
Este proyecto es una excelente oportunidad para mejorar tus habilidades en el manejo de **memoria dinámica, file descriptors y estructuras de datos en C**.

¡Buena suerte con tu implementación de `get_next_line()`! 🚀

