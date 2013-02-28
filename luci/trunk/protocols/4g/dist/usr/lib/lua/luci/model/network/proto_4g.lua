local proto = luci.model.network:register_protocol("4g")

function proto.get_i18n(self)
	return luci.i18n.translate("4G")
end

function proto.is_installed(self)
	return nixio.fs.access("/lib/netifd/proto/4g.sh")
end

function proto.opkg_package(self)
	return "4g-support"
end

luci.model.network:register_pattern_virtual("^%s-%%w" % "4g")
