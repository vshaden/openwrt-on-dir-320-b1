#!/bin/sh
INCLUDE_ONLY=1

. /lib/functions.sh
. ../netifd-proto.sh
init_proto "$@"

proto_4g_init_config() {
logger "4G: INIT CONFIG."
	no_device=1
	available=0

	proto_config_add_string "service"
	proto_config_add_string "ifname"
	proto_config_add_string "device"
	proto_config_add_string "apn"
	proto_config_add_string "essid"
	proto_config_add_string "nspid"
	proto_config_add_string "use_pkm"
	proto_config_add_string "eap_type"
	proto_config_add_string "use_nv"
	proto_config_add_string "anonymous_identity"
	proto_config_add_string "identity"
	proto_config_add_string "password"
	proto_config_add_string "ca_cert_null"
	proto_config_add_string "dev_cert_null"
	proto_config_add_string "cert_nv"
	proto_config_add_string "ca_cert"
	proto_config_add_string "client_cert"
	proto_config_add_string "private_key"
	proto_config_add_string "private_key_passwd"
	proto_config_add_string "log_file"
	proto_config_add_string "event_script"

}

proto_4g_setup() {
logger "4G: SETUP INTERFACE."
local interface="$1"
local opt="/etc/gctwimax/gctwimax.conf"

	json_get_var service service
	json_get_var ifname ifname	

	case "$service" in
		qmi)
			json_get_var device device
			json_get_var apn apn
			sleep 10			
			logger "4G: QMI-CLIENT START. DEVICE=$device, APN=$apn"		
#			qmicli -d "$device" --wds-start-network="$apn" --client-no-release-cid &
			uqmi -d "$device" --keep-client-id wds  --start-network $apn &
		;;
		ncm)
			json_get_var device device
			json_get_var apn apn
			sleep 10
			logger "4G: NCM SEND AT COMMANDS FOR START. DEVICE=$device, APN=$apn"
			MODE="AT^NDISDUP=1,0" gcom -d "$device" -s /etc/gcom/setmode.gcom
			sleep 3
			MODE="AT^NDISDUP=1,1,\"$apn\"" gcom -d "$device" -s /etc/gcom/setmode.gcom
			sleep 3
		;;
		wimaxU200)
			logger "4G: WIMAX U200 START. ESSID=$essid"
			json_get_var service essid
			insmod u200 essid="$essid"
			sleep 10
		;;
		gctwimax)
			json_get_var nspid nspid
			json_get_var use_pkm use_pkm
			json_get_var eap_type eap_type
			json_get_var use_nv use_nv
			json_get_var anonymous_identity anonymous_identity
			json_get_var identity identity
			json_get_var password password
			json_get_var ca_cert_null ca_cert_null
			json_get_var dev_cert_null dev_cert_null
			json_get_var cert_nv cert_nv
			json_get_var ca_cert ca_cert
			json_get_var client_cert client_cert
			json_get_var private_key private_key
			json_get_var private_key_passwd private_key_passwd
			json_get_var log_file log_file
			json_get_var event_script event_script

			echo "[common]" > "$opt"
			echo "nspid=$nspid" >> "$opt" 
			echo "" >> "$opt"
			echo "[auth]" >> "$opt"
			echo "use_pkm=$use_pkm" >> "$opt"
			echo "eap_type=$eap_type" >> "$opt"
			echo "use_nv=$use_nv" >> "$opt"
			echo "anonymous_identity=\"$anonymous_identity\"" >> "$opt"
			echo "identity=\"$identity\"" >> "$opt"
			echo "password=\"$password\"" >> "$opt"
			echo "ca_cert_null=$ca_cert_null" >> "$opt"
			echo "dev_cert_null=$dev_cert_null" >> "$opt"
			echo "cert_nv=$cert_nv" >> "$opt"
			echo "ca_cert=\"$ca_cert\"" >> "$opt"
			echo "client_cert=\"$client_cert\"" >> "$opt"
			echo "private_key=\"$private_key\"" >> "$opt"
			echo "private_key_passwd=\"$private_key_passwd\"" >> "$opt"
			echo "" >> "$opt"
			echo "[log]" >> "$opt"
			echo "wimax_verbose_level=1" >> "$opt"
			echo "wpa_debug_level=3" >> "$opt"
			echo "log_file=\"$log_file\"" >> "$opt"
			echo "event_script=\"$event_script\"" >> "$opt"

			sleep 30			
			logger "4G: GCTWIMAX START."
			gctwimax --cfg-file="$opt" &

			while :
			do
				logger "4G: IFNAME NOT FOUND. WAIT..."
				sleep 3
				ifconfig | grep -q "$ifname" && logger "4G: IFNAME FOUND." && break
			done
		;;
	esac
	
	usbwan if-up "$ifname" &
	sleep 5
	ls /var/run | grep -q "udhcpc-$ifname.pid" || usbwan if-up "$ifname"
	
}

proto_4g_teardown() {
logger "4G: TEARDOWN."
	json_get_var service service
	json_get_var device device
	json_get_var ifname ifname

	usbwan if-down "$ifname"

	case "$service" in
		qmi)			
			qmi-network "$device" stop
			logger "4G: QMI-CLIENT STOP."
		;;
		ncm)
			logger "4G: NCM SEND AT COMMANDS FOR STOP."
			MODE="AT^NDISDUP=1,0" gcom -d "$device" -s /etc/gcom/setmode.gcom
		;;
		wimaxU200)
			logger "4G: WIMAX U200 STOP."
			rmmod u200
		;;
		gctwimax)
			logger "4G: GCTWIMAX STOP."
			killall -9 gctwimax
			
		;;
	esac	
}

add_protocol 4g
