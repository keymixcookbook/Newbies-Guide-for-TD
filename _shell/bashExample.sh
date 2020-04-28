#! /bin/bash
export KP_SHOW=$1
export KP_SCENE=${2::-4}
export KP_SHOT=$2

export WSLENV=$KP_SHOW:$KP_SCENE:$KP_SHOT


SHOTPATH="/<yourProjectsPath>/${KP_SHOW}/${KP_SHOT}"
WINPATH="K:/${SHOTPATH:8}"

if [[ $# -eq 2 ]]
then
    if [[ -d "${SHOTPATH}" ]]
    then
        cd $SHOTPATH
        echo "== GO TO SHOT ========="
        echo "WinDir: $WINPATH"
        echo "Show:   $KP_SHOW"
        echo "Scene:  $KP_SCENE"
        echo "Shot:   $KP_SHOT"
        echo "======================="

        alias cdnuke="cd ${SHOTPATH}/workbench/nuke/"
        alias cdmaya="cd ${SHOTPATH}/workbench/maya/scenes/"

    elif [[ -d "<yourProjectsPath>" ]]
    then
        echo "SHOW or SHOT does not exist"
        echo "...Change dir to <yourProjectsPath>/" && cd "<yourProjectsPath>/"
    else
        echo "server not mounted"
        echo "mounting server..."
    fi
else
    echo "insufficient argument"
    echo "go <show> <shot>"
fi
