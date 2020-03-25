# Shell in a nutshell :chestnut:
Shell basics for Linux

### Config (Linux)

`/usr/<username>/config/cshrc.csh`

### Config (Bash/Mac)

`/Users/<username>/.bash_profile`

### Command-line Snippets
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
