# 
# Copyright (C) 2012 OpenWrt.org
# Copyright (C) 2013 Rusink <rzrusink@qmail.com>
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=uqmi
PKG_VERSION:=0.0.1-rz
PKG_RELEASE:=1

PKG_BUILD_PARALLEL:=1


PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_MAINTAINER:=Felix Fietkau <nbd@openwrt.org>

include $(INCLUDE_DIR)/package.mk

define Package/uqmi
   SECTION:=utils
   CATEGORY:=Utilities
   DEPENDS:=
   TITLE:= QMI CLI Interface Configuration Manager
endef

define Package/uqmi/description
	Small QMI CLI Interface Configuration Manager for QMI modems,
	like Huawei E392, E398 made by Felix Fietkau aka nbd 
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR)/libuboxm \
	 $(MAKE_ARGS) \
		CC="$(TARGET_CC)" CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)"
	$(call Build/Prepare/Default)
endef

define Package/uqmi/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/uqmi $(1)/sbin/

endef

$(eval $(call BuildPackage,uqmi))
