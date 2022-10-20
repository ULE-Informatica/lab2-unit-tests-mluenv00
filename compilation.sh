#!/bin/bash

DIRECTORY=build
RUNFILE=testExec

compile () 
{
	
	if [ -d "./$DIRECTORIO" ]
	then
   		if [ $option = "-d" ] || [ "$1" = "--delete" ]
		then
			cd ${DIRECTORY}
   			rm -rf *
   			echo "Directory \"${DIRECTORY}\" cleared"
   		fi

   		if [ "$1" = "-c" ] || [ "$1" = "--compile" ]
		then
			echo "Programa compilado en \"${DIRECTORY}\" compilado"
   			cd "./$DIRECTORY"
			cmake ..
			make
   		fi

	else
   		echo "Directory \"${DIRECTORY}\" not found"
   		echo "Aborting ..."
   		exit -1
	fi
}

run() {
	if [ -d "./$DIRECTORY" ]
	then
   		echo "Directory \"${DIRECTORY}\" found"
   		cd ${DIRECTORY}
   		ls
   		if [ -f "$RUNFILE" ]; then
   			chmod +x ${RUNFILE}
   			./${RUNFILE}
   		else
   			echo "File \"${RUNFILE}\" not found"

   		fi
	else
   		echo "Directory \"${DIRECTORY}\" not found"
   		echo "Aborting ..."
   		exit -1
	fi
}

help() {
	echo "Usage: ./compilation.sh [option]"
	echo " -d or --delete -> clear compilation directory"
	echo " -c or --compile -> compile the program"
	echo " -r or --runtest -> runtest if exists"
	exit -1
}

if [ "$#" -eq 1 ]; then
	option=$1
	if [ "$1" = "-d" ] || [ "$1" = "--delete" ] || [ "$1" = "-c" ] || [ "$1" = "--compile" ];
	then
		compile $option
	elif [ "$1" = "-r" ]; then
		run
	elif [ "$1" = "-h" ]; then
		help
	else
	    help
	fi
else
	help
fi
