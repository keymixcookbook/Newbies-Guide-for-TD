# Shell in a nutshell :chestnut:

- [Config Files](#Config)
- [Syntax](#Syntax)
- [Commands](#Commands)
- [Setting Aliases](#Setting-Aliases)
- [Scripting](#Scripting)
- [WSL](./WSL.md)

### Config

---
used for saving aliases, setting enviroment variables, etc.


#### Bash
- linux: `/usr/<username>/config/cshrc.csh`
- macOS: `/Users/<username>/.bash_profile`

#### Batch

1. create a `.bat` file with aliases commands, ie. `aliases.bat`
2. in cmd, run `regedit` and go to:
    - before windows 10: `HKEY_CURRENT_USER\Software\Microsoft\Command Processor`
    - in windows 10: `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor`
3. add `String Value` entry, with name `AutoRun`
4. set its value to **full path** of `aliases.bat`

[online ref](https://stackoverflow.com/questions/20530996/aliases-in-windows-command-prompt)


[&#9776;](#Shell-in-a-nutshell)

### Syntax
---

#### Bash
- variables: `NAME="potato"`, `$NAME`, `${NAME:6:7}`
- arguments: `$[1-9]`
    - `$#`: number of arguments
    - `$*`: all arguments (list)
- comments: `#Comments`
- options: `-o`

#### Batch
- variables: `%VARIABLE%`
- argument: `%<1-9>`
- comments: `::` or `Rem`
- switch: `/<a-z>`
- other:
    - `@`: apply command to itself, ie. `@echo off`: to turn off display of commands
    - `>`: redirect output, ie. `dir in > out`

[&#9776;](#Shell-in-a-nutshell)

### Commands

---

#### Bash

- `ls`: list contents of a directory
- `cd`: change directory
- `export`: sets script variables
- `setenv`: sets enviroment variables
- `echo`: prints in shell
- `clear`: clear shell
- `start`: start a program
- `mkdir`: make directory
- `printenv`: display enviroment variables
- `alias`: sets aliases
- `man <cmd>`: prints Manual for `<cmd>`


#### Batch

- `dir`: list contents of a directory
- `cd`: change directory, `d:`: change drive
- `set`: sets variables, or display enviroment variables
- `echo`: prints in shell
- `cls`: clear shell
- `start`: start a program
- `md`: make directory
- `path`: display or sets %PATH% variable
- `rem`: comments
- `doskey`: sets aliases or macros
- `pause`: pause shell from auto-close after successfully execute script

[&#9776;](#Shell-in-a-nutshell)

### Setting Aliases

---


#### Bash

- c-shell: `alias <aliasname> '<command>'`
- bash-shell: `alias <aliasname>='<command>'`

#### Batch

`doskey <aliasname>="command" $[1-9]`

**using command-line argv with doskey aliases** (tricky one)

you have to tell the alias how many argument this doskey macro will have, [doskey documentation](https://ss64.com/nt/doskey.html)

- in `aliases.bat`
    - `doskey aliases="file.bat" $1 $2 $3...`
- in `file.bat`
    - `$[1-9]` = `%[1-9]`


[&#9776;](#Shell-in-a-nutshell)

### Scripting

---


#### Bash

#### Batch

[&#9776;](#Shell-in-a-nutshell)
