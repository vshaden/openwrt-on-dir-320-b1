include $(TOPDIR)/rules.mk

PKG_NAME:=3ginfo
PKG_VERSION:=1
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/3ginfo
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Information about 3g/4g connection
endef

define Package/3ginfo/description
 Web interface with information about your 3g/4g connection
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile/Default

endef

define Package/mrelay/postinst
#!/bin/sh
# check if we are on real system
if [ -z "$${IPKG_INSTROOT}" ]; then
      ln -s /usr/share/3ginfo/cgi-bin/3ginfo.sh /usr/bin/3ginfo
fi
exit 0
endef

define Package/mrelay/prerm
#!/bin/sh
# check if we are on real system
if [ -z "$${IPKG_INSTROOT}" ]; then
	rm /usr/bin/3ginfo
fi
exit 0
endef

define Package/3ginfo/install
	$(INSTALL_DIR) $(1)/etc/hotplug.d/usb
	$(INSTALL_BIN) ./files/99-3ginfo $(1)/etc/hotplug.d/usb/
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) ./files/3ginfo-test $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/3ginfo.init $(1)/etc/init.d/3ginfo
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_CONF) ./files/3ginfo.config $(1)/etc/config/3ginfo
	$(INSTALL_DIR) $(1)/usr/share/3ginfo
	$(CP) ./files/3ginfo/* $(1)/usr/share/3ginfo/
endef

$(eval $(call BuildPackage,3ginfo))

