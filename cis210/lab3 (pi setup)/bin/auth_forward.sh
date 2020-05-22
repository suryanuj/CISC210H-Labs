#!/bin/bash

GATE=go.eecis.udel.edu
FORWARD=setupforward.sh
nickname=$(hostname -s)

function getScript() {
	[ -z "$1" ] && return
	echo "Obtaining ${2:-$1}"
	pushd ${HOME}/bin > /dev/null 2>&1
	if [ \! -f $1 ]
	then
		wget http://www.eecis.udel.edu/~roosen/pisetup/$1
		chmod u+x $1
	fi
	popd > /dev/null 2>&1
}

cd $HOME
if [ \! -d .ssh ]
then
	echo "Make SSH configuration directory"
	mkdir .ssh
fi
if [ \! -d bin ]
then
	echo "Make directory for useful scripts and programs"
	mkdir bin
fi

if [ -z "$1" ] 
then
cat <<EOF
Usage: $0 EECISNAME [nickname]
EECISNAME must be your EECIS user name. The optional 'nickname' is the name
by which to refer to this system from ${GATE} (default ${nickname}).
EOF
fi
EECIS=$1

if [ -n "$2" ]
then
    nickname=$2
fi

getScript ${FORWARD} "the forwarding script."

KEY=.ssh/piforward_${EECIS}_${nickname}
if [ -s $KEY ]
then
    echo "$KEY already exists, not generating new key pair."
else
    echo "Creating new SSH key pair."
    ssh-keygen -N "" -f ${KEY} -t rsa
fi

cat <<EOF
You /may/ be shown an RSA key and asked to continue.
If so, type 'yes' (the whole word).
When prompted, enter your EECIS password.
EOF

ssh ${EECIS}@${GATE} "rm -f eecis_setup.sh; wget http://www.eecis.udel.edu/~roosen/pisetup/eecis_setup.sh; bash ./eecis_setup.sh $USER $nickname" < ${KEY}.pub

echo "You /may/ be asked to enter the password you created for the \"${USER}\" user."
test -s /etc/rc.local || echo "#!/bin/bash" | sudo tee /etc/rc.local > /dev/null
if ! grep -q "${HOME}/bin/${FORWARD} ${EECIS} ${nickname}" /etc/rc.local
then
    sudo chmod +x /etc/rc.local
    sudo sed -i "\$asudo -u ${USER} ${HOME}/bin/${FORWARD} ${EECIS} ${nickname}&" /etc/rc.local
fi
echo "Setup Complete!"
