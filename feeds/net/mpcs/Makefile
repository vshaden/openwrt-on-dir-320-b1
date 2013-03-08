#
# Copyright (C) 2007-2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mpcs
PKG_VERSION:=0.9e
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
define Package/mpcs
SECTION:=custom
CATEGORY:=Custom packages
TITLE:=Cardsharing software
DEPENDS:= +libpthread
endef

define Package/mpcs/description
	Cardsharing software 
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)
	$(call Build/Prepare/Default)
endef

define Build/Configure
endef

define Package/mpcs/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/Distribution/mpcs-pre_$(PKG_VERSION)_Community_edition-i386-pc-linux $(1)/usr/sbin/mpcs
	$(INSTALL_DIR) $(1)/etc/mpcs
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Distribution/mpcs.{ac,cert,conf,guess,ird,server,services,srvid,user} $(1)/etc/mpcs/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/mpcs.init $(1)/etc/init.d/mpcs
endef

$(eval $(call BuildPackage,mpcs))
