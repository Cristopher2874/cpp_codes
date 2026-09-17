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