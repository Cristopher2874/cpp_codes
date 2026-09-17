# Miniwin en VS Code

Revisa el tutorial completo en [MiniWin + VS Code en Windows: tasks.json, launch.json y tu primera ventana gráfica](https://youtu.be/vVF_ITeqdrA)

La guia oficial para el uso de miniwin está en su [documentación oficial](https://miniwin.readthedocs.io/en/latest/Instalacion.html)

Esta guía explica cómo ejecutar un programa de C++ que utiliza la biblioteca MiniWin con **Run and Debug** de VS Code.

Para la configuración solo se requieren dos archivos:

- `.vscode/tasks.json`: indica a VS Code cómo compilar el programa.
- `.vscode/launch.json`: indica a VS Code qué programa iniciar y qué tarea de compilación ejecutar primero.

## Principios sobre los archivos

El compilador también debe compilar `miniwin.cpp`. Por ello es necesario añadir una nueva tarea de compilación y enlazar las bibliotecas de Windows necesarias.

La configuración utiliza variables genéricas de VS Code:

- `${file}` significa el archivo C++ abierto actualmente en el editor.
- `${fileBasenameNoExtension}` significa el nombre del archivo actual sin `.cpp`.
- `${workspaceFolder}` significa la carpeta del proyecto abierta en VS Code.

Esto para que la misma configuración funcione en cualquier programa

## 1. Añadir la tarea de MiniWin a `tasks.json`

Abre `.vscode/tasks.json`. Conserva la tarea existente llamada `C/C++: g++.exe build active file`. Dentro del arreglo `"tasks"`, añade una coma después de esa tarea y luego agrega este objeto:

```json
{
    "label": "MiniWin: Build active file",
    "type": "shell",
    "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
    "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${file}",
        "${workspaceFolder}\\miniwin.cpp",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe",
        "-lgdi32",
        "-luser32",
        "-lkernel32"
    ],
    "options": {
        "cwd": "${workspaceFolder}"
    },
    "problemMatcher": [
        "$gcc"
    ],
    "group": "build"
}
```

Las partes importantes son:

- `${file}` compila el programa abierto actualmente en VS Code.
- `${workspaceFolder}\\miniwin.cpp` añade la implementación de MiniWin.
- `-lgdi32`, `-luser32` y `-lkernel32` conectan el programa con las funciones de Windows utilizadas por MiniWin.
- `-o ...exe` crea un ejecutable con el mismo nombre que el archivo de programa activo.

No abras `miniwin.cpp` como archivo activo al ejecutar esta tarea. La tarea ya lo añade por separado.

## 2. Crear `launch.json`

Crea un archivo nuevo exactamente en `.vscode/launch.json`.

Añade este contenido:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "MiniWin: Run active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
            "preLaunchTask": "MiniWin: Build active file"
        }
    ]
}
```

`preLaunchTask` conecta los dos archivos. Antes de iniciar el depurador, VS Code ejecuta `MiniWin: Build active file`. Solo si la compilación termina correctamente se inicia el archivo `.exe` generado.

## 3. Ejecutar el programa

1. Abre la carpeta del proyecto, que debe contener `miniwin.cpp`, `miniwin.h` y `.vscode`.
2. Abre tu archivo de programa, por ejemplo `use_miniwin.cpp`.
3. Abre **Run and Debug** en la barra lateral de VS Code.
4. Selecciona **MiniWin: Run active file** en el menú de configuraciones.
5. Pulsa **F5** o haz clic en el botón verde de ejecución.

## Problemas frecuentes

### `undefined reference to miniwin::...`

El programa se compiló sin `miniwin.cpp`. Comprueba que seleccionaste **MiniWin: Run active file** y no la tarea original de C/C++.

### `launch.json` does not exist

Confirma que el archivo está ubicado aquí:

```text
your-project/.vscode/launch.json
```

También confirma que VS Code abrió `tu-proyecto`, y no solamente la carpeta `.vscode`.
