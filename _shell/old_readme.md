# Shell in a nutshell :chestnut:
Shell basics, include Bash and Batch

### Config (Linux, C Shell)

`/usr/<username>/config/cshrc.csh`

### Config (Mac, BASH Shell)

`/Users/<username>/.bash_profile`

```shell
alias nuke='/Applications/Nuke11.3v6/Nuke11.3v6/Contents/MacOS/Nuke11.3v6'
alias job='source  <path.sh>' # run a shell script using command-line
```

### Config (BASH in Windows or WSL)
Why use shell in windows? cuz bash-ishly cool XD

and I think it deservse its own [page](./WSL.md)


### Config (Windows Command Prompt, cmd)

nuke command-line: `doskey nuke="C:\Program Files\Nuke11.3v6\Nuke11.3.exe"`

### Command-line Snippets (UNIX shells)
```shell
# Directory Commands
ls # List directories
cd # Change to HOME directory
cd <directory> # Change directories
cd ../ # up 1 directories
source # Source a script
pwd # Print current working directory
mkdir # make directory

# File Commands
cp <source file> <destination file> # Copy from source to destination, FILE ONLY
cp -r <source dir> <destination dir> # Copy directory and files inside, recursively copy
rm <file> # Remove file
rm -r <dir>  # Remove directory, recursively remove
mv <source file> <destination file> # Move files, copy and remove original
mv -r <source dir> <destination dir> # Move directory

man <command> # Manual for the command
diff <first file> <second file> # Difference between two files
sudo # Supersuer

# Flags
-h # History
-l # Long list
-f # Forcefully to
-r # Recursively to

# making alias (C Shell)
alias <aliasname> '<command>'

# Variables
$VAR
alias comp `cd /jobs/$JOB/$SHOT/nuke/comp/scene/$USER/`

# Enviroment
setenv ENV_NAME value
printenv ENV_NAME

# Shell Prompt (Default)
PS1="\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ "
```

### Bash Shell Script Snippets
[online example](https://natelandau.com/my-mac-osx-bash_profile/)
```Shell
# Command-line arguments, input variables
$[1-9]

# Set Enviroment Variables
export KU_STUDIO_ENV=$1

# Print statement
echo "job in to $KU_STUDIO_ENV"
```

### Using `vim` for editing in shell

`vim <file>`

Commands
- `i`: insert/edit file
- `ESC`: exist editing mode
- `:wq`: write and quit
- `:q`: quit without wirte


### BATCH basics
Windows command prompt runs of `Batch`, and the syntax are differet than unix shell

**Syntax**
- `::` or `Rem`: comments
- `@`: apply command to itself, ie. `@echo off`: to turn off display of commands
- `%VARIABLE%`: in script variables
- `%<1-9>`: command-line argument variables
- `>`: redirect output, ie. `dir in > out`
- `/<a-z>`: switch to define variable type

**Commands** (common ones)
- `dir`: list contents of a directory
- `set`: sets variables
- `echo`: prints in shell
- `cls`: clear shell
- `start`: start a program
- `md`: make directory
- `path`: display or sets %PATH% variable
- `rem`: comments
- `doskey`: sets aliases or macros
- `pause`: pause shell from auto-close after successfully execute script

**Saving aliases** (saving aliases in windows system)

1. create a `.bat` file with aliases commands, ie. `aliases.bat`
2. in cmd, run `regedit` and go to:
    - before windows 10: `HKEY_CURRENT_USER\Software\Microsoft\Command Processor`
    - in windows 10: `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor`
3. add `String Value` entry, with name `AutoRun`
4. set its value to **full path** of `aliases.bat`

[online ref](https://stackoverflow.com/questions/20530996/aliases-in-windows-command-prompt)

**using command-line argv with doskey aliases** (tricky one)

you have to tell the alias how many argument this doskey macro will have, [doskey documentation](https://ss64.com/nt/doskey.html)

- in `aliases.bat`
    - `doskey aliases="file.bat" $1 $2 $3...`
- in `file.bat`
    - `$[1-9]` = `%[1-9]`

**Conditional Statements**
```shell
if <condition> (
    <true commands>
    ) else (
    <false commands>
    )
```
