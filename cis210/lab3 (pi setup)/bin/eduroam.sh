#!/bin/bash -e

# Script to setup eduroam on the raspberry pi

WPADIR=/etc/wpa_supplicant
CERTDIR=/etc/ssl/certs/eduroam
CERTS=(20 21 22 30 31 32 40 41 42 50 51 52)

uduname=$1

while [ -z "$uduname" ] 
do
    echo "What is your @udel email address? Include the @udel.edu"
	read udemail
	uduname="${udemail%@udel.edu}"
	if [ "$udemail" = "$uduname" ]
	then
		echo "Don't forget the @udel.edu"
		unset uduname
		continue
	fi
	echo "Please enter it again just to make sure."
	read udemail1
	[ "$udemail" = "$udemail1" ] ||\
		{ echo "Those weren't the same."; unset uduname ; }
done

section=$(md5sum <<< "$uduname")
section=$((0x${section%% *} % ${#CERTS[@]}))
section=${CERTS[$section]}
echo "Using $section"

cd $WPADIR

# Create config file
cat > wpa_supplicant.conf << EOF
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=US

network={
ssid="eduroam"
key_mgmt=WPA-EAP
eap=TTLS
phase2="autheap=TLS"
identity="${uduname}@udel.edu"
ca_cert="/etc/ssl/certs/eduroam/ca.pem"
client_cert2="/etc/ssl/certs/eduroam/client.crt.pem"
private_key2="/etc/ssl/certs/eduroam/client.key.pem"
}
EOF

mkdir -p ${CERTDIR}
cd ${CERTDIR}

# Create server certificate
cat > ca.pem <<EOF
-----BEGIN CERTIFICATE-----
MIIDXzCCAkegAwIBAgILBAAAAAABIVhTCKIwDQYJKoZIhvcNAQELBQAwTDEgMB4G
A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjMxEzARBgNVBAoTCkdsb2JhbFNp
Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDkwMzE4MTAwMDAwWhcNMjkwMzE4
MTAwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMzETMBEG
A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI
hvcNAQEBBQADggEPADCCAQoCggEBAMwldpB5BngiFvXAg7aEyiie/QV2EcWtiHL8
RgJDx7KKnQRfJMsuS+FggkbhUqsMgUdwbN1k0ev1LKMPgj0MK66X17YUhhB5uzsT
gHeMCOFJ0mpiLx9e+pZo34knlTifBtc+ycsmWQ1z3rDI6SYOgxXG71uL0gRgykmm
KPZpO/bLyCiR5Z2KYVc3rHQU3HTgOu5yLy6c+9C7v/U9AOEGM+iCK65TpjoWc4zd
QQ4gOsC0p6Hpsk+QLjJg6VfLuQSSaGjlOCZgdbKfd/+RFO+uIEn8rUAVSNECMWEZ
XriX7613t2Saer9fwRPvm2L7DWzgVGkWqQPabumDk3F2xmmFghcCAwEAAaNCMEAw
DgYDVR0PAQH/BAQDAgEGMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYEFI/wS3+o
LkUkrk1Q+mOai97i3Ru8MA0GCSqGSIb3DQEBCwUAA4IBAQBLQNvAUKr+yAzv95ZU
RUm7lgAJQayzE4aGKAczymvmdLm6AC2upArT9fHxD4q/c2dKg8dEe3jgr25sbwMp
jjM5RcOO5LlXbKr8EpbsU8Yt5CRsuZRj+9xTaGdWPoO4zzUhw8lo/s7awlOqzJCK
6fBdRoyV3XpYKBovHd7NADdBj+1EbddTKJd+82cEHhXXipa0095MJ6RMG3NzdvQX
mcIfeg7jLQitChws/zyrVQ4PkX4268NXSb7hLi18YIvDQVETI53O9zJrlAGomecs
Mx86OyXShkDOOyyGeMlhLxS67ttVb9+E7gUJTb0o2HLO02JQZR7rkpeDMdmztcpH
WD9f
-----END CERTIFICATE-----
EOF

wget -O certificate.p12 http://www.eecis.udel.edu/~roosen/pisetup/eduroam/${section}.p12 
echo "Enter the 'eduroam key' password your TA announces."
read SSLPASS
export SSLPASS
until openssl pkcs12 -in certificate.p12 -out client.crt.pem -clcerts -nokeys -passin env:SSLPASS
do
	read SSLPASS
done
openssl pkcs12 -in certificate.p12 -out client.key.pem -nocerts -nodes -passin env:SSLPASS

cat >> /etc/dhcpcd.conf << EOF

# Workaround for broken wifi driver
interface wlan0
env ifwireless=1
env wpa_supplicant_driver=wext
EOF

# Turn on WiFi
rfkill unblock 0
echo "Switching to eduroam"
sudo systemctl daemon-reload
sudo systemctl restart dhcpcd
sleep 1
while ! ping -c 1 -q www.eecis.udel.edu > /dev/null 2>&1
do
     sleep 1
done    

echo "Eduroam setup complete!"
