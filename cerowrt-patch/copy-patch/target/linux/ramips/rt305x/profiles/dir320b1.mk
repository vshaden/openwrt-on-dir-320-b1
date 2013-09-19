define Profile/DIR320B1
	NAME:=D-Link DIR-320/NRU
	PACKAGES:=\
		kmod-usb-core kmod-usb-rt305x-dwc_otg \
		kmod-ledtrig-usbdev kmod-mppe kmod-rt2800-pci \
		kmod-usb2 kmod-usb-ohci kmod-ledtrig-netdev
endef

define Profile/DIR320B1/Description
	Package set for DIR-320/NRU board
endef

$(eval $(call Profile,DIR320B1))
