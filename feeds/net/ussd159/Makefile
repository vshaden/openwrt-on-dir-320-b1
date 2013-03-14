include $(TOPDIR)/rules.mk

PKG_NAME:=ussd159
PKG_VERSION:=1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/ussd159
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Small program for sending USSD requests.
endef

define Package/ussd159/description
 Small program for sending USSD requests.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Configure/Default
endef

define Package/ussd159/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ussd159 $(1)/usr/sbin
endef

$(eval $(call BuildPackage,ussd159))
