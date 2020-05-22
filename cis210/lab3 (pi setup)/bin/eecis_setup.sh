#!/bin/bash
SSHCONFIG=".ssh/config"
AUTHKEYS=".ssh/authorized_keys"

if [ "$1" = "stdin" ] 
then
    STDIN_KEY=true
    shift 1
fi
remuser=${1:-pi}
nickname=${2:-pi}
SSHKEY=".ssh/piforward_${nickname}.pub"

cd $HOME
if [ \! -d .ssh ]
then
	echo "Make SSH configuration directory"
	mkdir -m 700 .ssh
fi
if [ \! -d bin ]
then
	echo "Make directory for useful scripts and programs"
	mkdir bin
fi
cd bin
rm -f piforward.sh
wget http://www.eecis.udel.edu/~silber/pisetup/piforward.sh
chmod +x piforward.sh
cd ..

if [ -f ${SSHCONFIG} ] && grep -q "^Host ${nickname}$" ${SSHCONFIG}
then
	echo "Pi config for ${nickname} already found in $SSHCONFIG: no need to add."
else
	echo "Updating SSH config to add virtual host '${nickname}'"
	cat >> .ssh/config << EOF
Host ${nickname}
Port 9999
User ${remuser}
CheckHostIP no
ForwardX11 yes
ForwardX11Trusted yes
HostName localhost
NoHostAuthenticationForLocalhost yes
EOF
	chmod 600 .ssh/config
fi

if [ -n "$STDIN_KEY" ]
then
    cat > ${SSHKEY}
else
    echo "Generating key-pair. You will need to copy ${SSHKEY%.pub} to your thumb drive!"
    ssh-keygen -N "" -f ${SSHKEY%.pub} -t rsa
fi

if [ -s ${SSHKEY} ]
then
    # Deletes any pre-existing forwarding lines
    #[ -n ${AUTHKEYS} ] && sed -i '/piforward.sh/d' ${AUTHKEYS}
	echo "Adding forward.pub public key to authorized_keys file so "
	echo "Raspberri Pi can receive forwarded SSH."
	echo -n "command=\"${HOME}/bin/piforward.sh\",no-pty " >> ${AUTHKEYS}
	cat ${SSHKEY} >> ${AUTHKEYS}
else
	echo "ERROR: No content in ${SSHKEY}! Seek assistance."
fi

chmod 600 ${AUTHKEYS}
