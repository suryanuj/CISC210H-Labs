#!/bin/bash

SETTINGS=/home/pi/.cisc210
CERTDIR=/etc/ssl/certs/eduroam
GITKEY=/home/pi/.ssh/git
WPA_S_C=/etc/wpa_supplicant/wpa_supplicant.conf
[ -r $SETTINGS ] && source $SETTINGS
tmpfile=$(mktemp /tmp/c210config.XXXXXX) || exit 0
tmpdir=$(mktemp -d /tmp/c210mnt.XXXXXX) || exit 0
showstat=/home/pi/bin/status
[ -x $showstat ] || showstat=/bin/echo
# Finds all USB mass storage devices (considered SCSI)
lsblk -I 8 -o NAME,MOUNTPOINT -n -P > $tmpfile || exit 0
while read -r line
do
    eval $line
    # If not already mounted, see if the device can be
    cfile="$MOUNTPOINT/c210config.txt"
    if [ -z "$MOUNTPOINT" ]
    then
        cfile="$tmpdir/c210config.txt"
        mount "/dev/$NAME" "$tmpdir" || continue
    fi
    # Config file on this file system?
    [ -r "$cfile" ] && break
    [ -z "$MOUNTPOINT" ] && umount "$tmpdir" && rmdir "$tmpdir"
done < "$tmpfile"

# Config file found?
[ -r "$cfile" ] || exit 0

cd $(dirname "$cfile")
statline=
while read -r setting value garbage
do
    stat=g
    case ${setting} in
	\#*)
	    stat=
	;;
        eecis)
            EECIS="${value}"
        ;;
        sshkey)
	    stat=y
            [ -r ssh_key ] && ssh_ch=1 && stat=g
            ;;
        gitkey)
	    stat=r
            if [ -r git_key ] && stat=y && ! diff -q git_key $GITKEY >& /dev/null
	    then
		cp git_key $GITKEY
		chown pi:pi $GITKEY
		chmod 600 $GITKEY
		stat=g
	    fi
            ;;
        piname)
            PINAME=${value}
            ;;
        gateway)
            GATEWAY="${value}"
            ;;
        udel)
	    udel_ch=1
            UDEL="${value}"
            ;;
        eduroam)
            eduroam_ch=1
            EDUROAM="${value}"
            ;;
	home_ssid)
	    home_ssid_ch=1
	    HOME_SSID="${value}"
	    ;;
	home_psk)
	    home_psk_ch=1
	    HOME_PSK="${value}"
	    ;;
	*)
	    echo "Unknown directive: $setting" 1>&2
	    stat='r'
    esac
    statline="${statline}${stat}"
done < ${cfile}
[ -z "$MOUNTPOINT" ] && umount "$tmpdir" && rmdir "$tmpdir"

$showstat "wwwwwwww"
$showstat "$statline" 1
statline=
if [ -n "$eduroam_ch" ]
then
    stat=r
    # Changing eduroam key
    CERTS=(a b c d e f g h i j k l)
    if [ "$EDUROAM" = random ]
    then
        EDUROAM=${CERTS[$(($RANDOM % ${#CERTS[@]}))]}
    fi
    if [ "$EDUROAM" = hash ]
    then
	section=$(md5sum <<< "$UDEL")
	section=$((0x${section%% *} % ${#CERTS[@]}))
	EDUROAM=${CERTS[$section]}
    fi
    if [ -r "${CERTDIR}/all/${EDUROAM}.key.pem" ]
    then
	rm -f "${CERTDIR}/client.key.pem" "${CERTDIR}/client.crt.pem" && \
	ln -s "all/${EDUROAM}.key.pem" "${CERTDIR}/client.key.pem" && \
	ln -s "all/${EDUROAM}.crt.pem" "${CERTDIR}/client.crt.pem" && \
	stat=g
    fi
    statline="${statline}${stat}"
    [ -r "ca.pem" ] &&\
	    cp ca.pem "${CERTDIR}" &&\
	    statline="${statline}${stat}"
fi

[ -n "$udel_ch" ] &&
	sed -i.bak0 "/#EDUROAM_IDENTITY/,/identity=/ s/\".*\"/\"${UDEL}@udel.edu\"/" $WPA_S_C &&\
	statline="${statline}g"

[ -n "$home_ssid_ch" ] &&
	sed -i.bak1 "/#HOME_SSID/,/ssid=/ s/\".*\"/\"${HOME_SSID}\"/" $WPA_S_C &&\
	statline="${statline}g"
[ -n "$home_psk_ch" ] &&
	sed -i.bak2 "/#HOME_PSK/,/ssid=/ s/\".*\"/\"${HOME_PSK}\"/" $WPA_S_C &&\
	statline="${statline}g"

if [ -n "sshkey_ch" ] 
then
    stat=r
    SSH_KEY="/home/pi/.ssh/piforward_${EECIS}_${PINAME:-pi}"
    if [ -r ssh_key ] && stat=y && ! diff -q ssh_key $SSH_KEY >& /dev/null
    then
	[ -f ${SSH_KEY} ] && mv "${SSH_KEY}" "${SSH_KEY}.$(date +%F@%T)"
        cp ssh_key ${SSH_KEY}
	chown pi:pi ${SSH_KEY}
	chmod 600 ${SSH_KEY}
	stat=g
    fi
    statline="${statline}${stat}"
fi

[ -f $SETTINGS ] && mv "${SETTINGS}" "${SETTINGS}.$(date +%F@%T)"
cat > $SETTINGS << EOF
# Configuration file for CISC210 Pi setup
EECIS=$EECIS
UDEL=$UDEL
PINAME=$PINAME
GATEWAY=$GATEWAY
EOF
chown pi:pi $SETTINGS
$showstat "wwwwwwww" 4
$showstat $statline 5

button=/home/pi/bin/button
[ -x ${button} ] || button="sleep 1"
cscr=/home/pi/bin/clear
[ -x ${cscr} ] || cscr=echo
statline=
while [ "$statline" != "wwwwwwwww" ]
do
    statline="w${statline}"
    $showstat $statline 7
    $button || { $cscr && exit 0; }
done
/sbin/reboot
