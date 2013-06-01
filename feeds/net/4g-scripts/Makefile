include $(TOPDIR)/rules.mk

PKG_NAME:=4g-scripts
PKG_VERSION:=1
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/4g-scripts
  SECTION:=net
  CATEGORY:=Network
  TITLE:=My scripts for 4G/LTE network
  DEPENDS:= uqmi||uqmi-static
endef

define Package/4g-scripts/description
 My scripts for 4G/LTE network.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile/Default

endef

define Package/4g-scripts/install
	$(INSTALL_DIR) $(1)/etc/hotplug.d/usb
	$(INSTALL_BIN) ./files/25-wimax $(1)/etc/hotplug.d/usb
	$(INSTALL_DIR) $(1)/etc/hotplug.d/net
	$(INSTALL_BIN) ./files/25-wwan $(1)/etc/hotplug.d/net
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) ./files/usbwan $(1)/usr/bin
	$(INSTALL_DIR) $(1)/lib/netifd/proto
	$(INSTALL_BIN) ./files/4g.sh $(1)/lib/netifd/proto
endef

$(eval $(call BuildPackage,4g-scripts))

