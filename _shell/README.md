# Shell in a nutshell :chestnut:
Shell basics for Linux

### Config (Linux)

`/usr/<username>/config/cshrc.csh`

### Command-line Snippets
```shell
# Commands
ls # List Directories
cd # Change Directories
cd ../ # up 1 Directories
source # Source a script

# Flags
-h # History
-l # long list

# making alias
alias <aliasname> '<command>'

# Variables
$VAR
alias comp `cd /jobs/$JOB/$SHOT/nuke/comp/scene/$USER/`

# Enviroment
setenv ENV_NAME value
printenv ENV_NAME
```

### Shell Script Snippets
```Shell
# Command-line arguments, input variables
$[1-9]

# Set Enviroment Variables
export KU_STUDIO_ENV=$1

# Print statement
echo "job in to $KU_STUDIO_ENV"
```
