#
# Copyright (C) 2007-2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mpcs
PKG_VERSION:=09e
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
define Package/mpcs
  SECTION:=custom
  CATEGORY:=Custom Packages
  TITLE:=Cardsharing software
endef

define Package/mpcs/description
	Cardsharing software 
endef

define Package/mpcs/prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)
endef

define Package/mpcs/conffiles
	/etc/mpcs/mpcs.conf
	/etc/mpcs/mpcs.guess
	/etc/mpcs/mpcs.server
	/etc/mpcs/mpcs.sid
	/etc/mpcs/mpcs.user
endef

define Package/mpcs/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mpcs $(1)/ust/sbin/
	$(INSTALL_DIR) $(1)/etc/mpcs
	$(INSTALL_CONF) ./files/mpcs.{conf,guess,server,sid,user} $(1)/etc/mpcs/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/mpcs.init $(1)/etc/init.d/mpcs
endef

$(eval $(call BuildPackage,mpcs))
