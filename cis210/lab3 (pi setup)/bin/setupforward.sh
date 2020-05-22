#!/bin/bash

GATEWAY=go.eecis.udel.edu # default if nothing set in .cisc210
[ -r ~/.cisc210 ] && source ~/.cisc210
[ -n "$1" ] && EECIS=$1
[ -n "$2" ] && PINAME=$2
KEY=${HOME}/.ssh/piforward_${EECIS}_${PINAME}
[ -r $KEY ] || exit 0
SSH="/usr/bin/ssh -i ${KEY} -o ForwardX11=no"
tmppipe=$(mktemp -u)
mkfifo -m 600 "$tmppipe"
while /bin/true
do
    if [ -z "${NOGIT}" ]
    then
	    $SSH -L 4567:cisc210.cis.udel.edu:22 -R 0:localhost:22 ${EECIS}@${GATEWAY} ${PINAME} 3>&1 1>&2 2>&3 < ${tmppipe} | cat > ${tmppipe}
    else
	    $SSH -R 0:localhost:22 ${EECIS}@${GATEWAY} ${PINAME} 3>&1 1>&2 2>&3 < ${tmppipe} | cat > ${tmppipe}
    fi
	sleep 5
done
