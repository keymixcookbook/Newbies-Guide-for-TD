# Shell in a nutshell :chestnut:
Shell basics

### Config (Linux, C Shell)

`/usr/<username>/config/cshrc.csh`

### Config (Mac, BASH Shell)

`/Users/<username>/.bash_profile`

```shell
alias nuke='/Applications/Nuke11.3v6/Nuke11.3v6/Contents/MacOS/Nuke11.3v6'
alias job='source  <path.sh>' # run a shell script using command-line
```

### Config (BASH in Windows)
Why use shell in windows? cuz bash-ishly cool XD

[How to setup `Bash` shell in windows 10](https://www.howtogeek.com/265900/everything-you-can-do-with-windows-10s-new-bash-shell/)

`/home/<username>/.bashrc` or `.bash_aliases`

`C` Drive location: `/mnt/c/`

```Shell
alias nuke='/mnt/c/Program\ Files/Nuke11.3v6/nuke11.3.exe'
alias nuke='/mnt/c/Program\ Files/Autodesk/Maya2019/bin/maya.exe'
```


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

# making alias
alias <aliasname> '<command>'

# Variables
$VAR
alias comp `cd /jobs/$JOB/$SHOT/nuke/comp/scene/$USER/`

# Enviroment
setenv ENV_NAME value
printenv ENV_NAME
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
