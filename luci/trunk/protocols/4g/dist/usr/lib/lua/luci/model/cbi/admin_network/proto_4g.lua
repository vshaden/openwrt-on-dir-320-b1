local map, section, net = ...

local ifname, apn, essid, service, nspid, use_pkm,
	eap_type, use_nv, anonymous_identity, identity,
	password, ca_cert_null, dev_cert_null, cert_nv,
	ca_cert, client_cert, private_key, private_key_passwd,
	log_file, event_script

local maxwait, defaultroute, metric, peerdns, dns,
	keepalive_failure, keepalive_interval, demand


service = section:taboption("general", Value, "service", translate("Service Type"))
service:value("", translate("-- Please choose (look into kernel log) --"))
service:value("qmi","QMI")
service:value("ncm","NCM")
service:value("wimaxU200","Samsung U200 modem")
service:value("gctwimax", "GCTWIMAX manual setup")


ifname = section:taboption("general", Value, "ifname", translate("Modem device"))
ifname.rmempty = false
ifname:depends("service", "qmi")
ifname:depends("service", "ncm")
ifname:depends("service", "gctwimax")
ifname:value("", "-- Please choise --")

local device_suggestions = nixio.fs.glob("/dev/cdc-wdm*")
	or nixio.fs.glob("/dev/ttyUSB*")

if device_suggestions then
	local node
	for node in device_suggestions do
		ifname:value(node)
	end
end

apn = section:taboption("general", Value, "apn", translate("APN"))
apn:depends("service", "qmi")
apn:depends("service", "ncm")

essid = section:taboption("general", Value, "essid", translate("ESSID"))
essid:depends("service", "wimaxU200")

nspid = section:taboption("general", Value, "nspid", translate("0 to get H-NSPID from modem memory or set it manual in decimal format"))
nspid:depends("service", "gctwimax")

use_pkm = section:taboption("general", Flag, "use_pkm", translate("Use PKM"))
use_pkm:depends("service", "gctwimax")
use_pkm.enabled  = "1"
use_pkm.disabled = "0"

eap_type = section:taboption("general", Value, "eap_type", translate("EAP type"))
eap_type:value("", "-- Please choise --")
eap_type:value("3", "EAP TLS")
eap_type:value("4", "EAP TTLS/MD5")
eap_type:value("5", "EAP TTLS/MSCHAPV2")
eap_type:value("6", "EAP TTLS/CHAP")
eap_type:depends("service", "gctwimax")

use_nv = section:taboption("general", Flag, "use_nv", translate("Do not get anonymous_identity, identity, password, private_key_passwd from modem memory"))
use_nv:depends("service", "gctwimax")
use_nv.enabled  = "0"
use_nv.disabled = "1"

anonymous_identity = section:taboption("general", Value, "anonymous_identity", translate("Anonymous identity"))
anonymous_identity:depends("use_nv", use_nv.enabled)

identity = section:taboption("general", Value, "identity", translate("Identity"))
identity:depends("use_nv", use_nv.enabled)

password = section:taboption("general", Value, "password", translate("Password"))
password:depends("use_nv", use_nv.enabled)

ca_cert_null = section:taboption("general", Flag, "ca_cert_null", translate("Skip CA cert check"))
ca_cert_null:depends("service", "gctwimax")
ca_cert_null.enabled = "1"
ca_cert_null.disabled = "0"

dev_cert_null = section:taboption("general", Flag, "dev_cert_null", translate("Skip device cert check"))
dev_cert_null:depends("service", "gctwimax")
dev_cert_null.enabled = "1"
dev_cert_null.disabled = "0"

cert_nv = section:taboption("general", Flag, "cert_nv", translate("Do not get cert files from modem memory"))
cert_nv:depends("service", "gctwimax")
cert_nv.enabled = "0"
cert_nv.disabled = "1"

ca_cert = section:taboption("general", Value, "ca_cert", translate("Path to CA cert"))
ca_cert:depends("cert_nv", cert_nv.enabled)

client_cert = section:taboption("general", Value, "client_cert", translate("Path to client cert"))
client_cert:depends("cert_nv", cert_nv.enabled)

private_key = section:taboption("general", Value, "private_key", translate("Path to private key"))
private_key:depends("cert_nv", cert_nv.enabled)

private_key_passwd = section:taboption("general", Value, "private_key_passwd", translate("Private key password"))
private_key_passwd:depends("use_nv", use_nv.enabled)

log_file = section:taboption("general", Value, "log_file", translate("Path to log file"))
log_file:depends("service", "gctwimax")
log_file.default = "/var/log/gctwimax.log"

event_script = section:taboption("general", Value, "event_script", translate("Path to event script"))
event_script:depends("service", "gctwimax")
event_script.default = "/etc/gctwimax/event.sh"

defaultroute = section:taboption("advanced", Flag, "defaultroute",
	translate("Use default gateway"),
	translate("If unchecked, no default route is configured"))

defaultroute.default = defaultroute.enabled


metric = section:taboption("advanced", Value, "metric",
	translate("Use gateway metric"))

metric.placeholder = "0"
metric.datatype    = "uinteger"
metric:depends("defaultroute", defaultroute.enabled)


peerdns = section:taboption("advanced", Flag, "peerdns",
	translate("Use DNS servers advertised by peer"),
	translate("If unchecked, the advertised DNS server addresses are ignored"))

peerdns.default = peerdns.enabled


dns = section:taboption("advanced", DynamicList, "dns",
	translate("Use custom DNS servers"))

dns:depends("peerdns", "")
dns.datatype = "ipaddr"
dns.cast     = "string"


keepalive_failure = section:taboption("advanced", Value, "_keepalive_failure",
	translate("LCP echo failure threshold"),
	translate("Presume peer to be dead after given amount of LCP echo failures, use 0 to ignore failures"))

function keepalive_failure.cfgvalue(self, section)
	local v = m:get(section, "keepalive")
	if v and #v > 0 then
		return tonumber(v:match("^(%d+)[ ,]+%d+") or v)
	end
end

function keepalive_failure.write() end
function keepalive_failure.remove() end

keepalive_failure.placeholder = "0"
keepalive_failure.datatype    = "uinteger"


keepalive_interval = section:taboption("advanced", Value, "_keepalive_interval",
	translate("LCP echo interval"),
	translate("Send LCP echo requests at the given interval in seconds, only effective in conjunction with failure threshold"))

function keepalive_interval.cfgvalue(self, section)
	local v = m:get(section, "keepalive")
	if v and #v > 0 then
		return tonumber(v:match("^%d+[ ,]+(%d+)"))
	end
end

function keepalive_interval.write(self, section, value)
	local f = tonumber(keepalive_failure:formvalue(section)) or 0
	local i = tonumber(value) or 5
	if i < 1 then i = 1 end
	if f > 0 then
		m:set(section, "keepalive", "%d %d" %{ f, i })
	else
		m:del(section, "keepalive")
	end
end

keepalive_interval.remove      = keepalive_interval.write
keepalive_interval.placeholder = "5"
keepalive_interval.datatype    = "min(1)"


demand = section:taboption("advanced", Value, "demand",
	translate("Inactivity timeout"),
	translate("Close inactive connection after the given amount of seconds, use 0 to persist connection"))

demand.placeholder = "0"
demand.datatype    = "uinteger"

