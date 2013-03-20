module("luci.controller.3ginfo", package.seeall)

function index()
	if not nixio.fs.access("/etc/config/3ginfo") then
		return
	end

	local page

	page = entry({"admin", "services", "3ginfo"}, cbi("3ginfo"), _("3ginfo"), 60)
	page.dependent = true
end
