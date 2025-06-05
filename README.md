# HHK3template
A modern template for HHK3!

## How to Setup
1. Clone to project
2. Enter the devcontainer
3. `make compile_commands.json` or use the vscode task
4. Restart clangd (eg. via CRTL+SHIFT+P in vscode)

## How to build
```sh
make -j
```
Or execute the default vscode build task with CRTL+SHIFT+B

## How to run
Copy `dist/CPapp.hh3` to the root of the calculator when connected in usb storage mode and then select and run from the launcher.

## How to change the file name (recommended)
Open the Makefile and adjust this line to what you want:
```Makefile
APP_ELF := $(OUTDIR)/<your_file_name>.elf
```