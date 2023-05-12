# Learncpp
Going through the learncpp.com tutorials to brush up on the latest C++ development

## Toolchain
Source code is build using GCC-MINGW. 

## Installation
Download the CGG binaries from https://github.com/mmozeiko/build-gcc-mingw.
In general any GCC distribution will work, but that specific one was chosen for its size and portibilty.
Once downloaded, extract to `${workspaceFolder}/toolchain/gcc-mingw`, so that the `g++.exe` is located in the `gcc-mingw/bin` folder.

### Set C++ environment
Hit `CTRL+SHIFT+P` and choose `C/C++: Edit Configurations (UI)` and adjust the following settings

* `includePath` => `"${workspaceFolder}/**"`
* `"compilerPath"` => `"${workspaceFolder}/toolchain/gcc-mingw/bin/g++.exe"`
* `"intelliSenseMode"` => `"windows-gcc-x64"`
* `"cppStandard"` => `"c++17"`

### Configure compiler
In the `Terminal` menu choose `Configure Tasks...` and use the following template. 
The configuration is based on recommendations of learncpp.com and the [vscode](https://code.visualstudio.com/docs/cpp/config-mingw) documentation.

```json
{
	// See https://go.microsoft.com/fwlink/?LinkId=733558
	// for the documentation about the tasks.json format
	"version": "2.0.0",
	"tasks": [
		{
			"label": "C/C++: g++.exe build active file",
			"detail": "Build with clang++",
			"type": "shell",
			"command": "${workspaceFolder}\\toolchain\\gcc-mingw\\bin\\g++.exe",
			"args": [
				"-std=c++17",
				"-ggdb",
				"-static",
				"-fdiagnostics-color=always",
				"-pedantic-errors",
				"-Wall",
				"-Weffc++",
				"-Wextra",
				"-Wsign-conversion",
				"-Werror",
				"-g",
				"${file}",
				"-o",
				"${workspaceFolder}\\debug\\application.exe",
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true,
			},
		}
	]
}
```

### Congigure debugger
Choose the `Run` menu and then `Start Debugging`. Use the template below the configure `gdb`.

```json
{
	// Use IntelliSense to learn about possible attributes.
	// Hover to view descriptions of existing attributes.
	// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
	"version": "0.2.0",
	"configurations": [
		{
			"name": "C/C++: g++.exe build and debug active file",
			"type": "cppdbg",
			"request": "launch",
			"preLaunchTask": "C/C++: g++.exe build active file",
			"program": "${workspaceFolder}\\debug\\application.exe",
			"args": [],
			"stopAtEntry": false,
			"cwd": "${fileDirname}",
			"environment": [],
			"externalConsole": false,
			"MIMode": "gdb",
			"miDebuggerPath": "${workspaceFolder}\\toolchain\\gcc-mingw\\bin\\gdb.exe",
			"setupCommands": [
				{
					"description": "Enable pretty-printing for gdb",
					"text": "-enable-pretty-printing",
					"ignoreFailures": true,
				}
			],
		},		
	]
}
```