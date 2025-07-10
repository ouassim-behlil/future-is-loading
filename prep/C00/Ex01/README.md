La fonction `write` en C est une fonction système (appel système) utilisée pour écrire des données vers un descripteur de fichier, généralement un fichier, un terminal, ou une socket.

---

### 📌 Prototype

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```

---

### 📥 Paramètres

| Paramètre | Description                                                       |
| --------- | ----------------------------------------------------------------- |
| `fd`      | Descripteur de fichier (ex: `1` pour `stdout`, `2` pour `stderr`) |
| `buf`     | Pointeur vers le buffer contenant les données à écrire            |
| `count`   | Nombre d'octets à écrire                                          |

---

### 📤 Valeur de retour

* Retourne le **nombre d'octets effectivement écrits**.
* Retourne **-1** en cas d’erreur (et `errno` est défini).

---

### ✅ Exemple simple

```c
#include <unistd.h>

int main() {
    const char *message = "Hello, world!\n";
    write(1, message, 14); // 1 = stdout
    return 0;
}
```

---

### ⚠️ Notes importantes

* `write` n’ajoute pas automatiquement de caractère nul (`'\0'`), contrairement à `printf`.
* Elle fonctionne à bas niveau, sans formattage.
* Utilisée souvent avec `open`, `read`, `close`, etc.

---

### 📚 Exemple avec gestion d'erreur

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char *text = "Ceci est un test.\n";
    ssize_t bytes_written = write(fd, text, 18);
    if (bytes_written == -1) {
        perror("write");
        return 1;
    }

    close(fd);
    return 0;
}
```

