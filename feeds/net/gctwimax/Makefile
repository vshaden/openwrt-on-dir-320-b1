#
# Copyright (C) 2007-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gctwimax
PKG_VERSION:=0.0.3rc4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://gctwimax.googlecode.com/files/
PKG_MD5SUM:=41fa646c1491c2fe4514adc2e63ca112e6992ce1
PKG_BUILD_DEPENDS:=dbus libdbus dbus-glib-fixed glib2 libeap libusb-1.0

include $(INCLUDE_DIR)/package.mk

define Package/gctwimax
  SECTION:=net
  CATEGORY:=Network
  TITLE:=gctwimax user space wimax driver and connection manager
  DEPENDS:=+kmod-tun +libdbus +libusb-1.0 +libopenssl +libeap +zlib
  URL:=http://code.google.com/p/gctwimax/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) $(MAKE_ARGS) \
		CC="$(TARGET_CC)" CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

TARGET_CFLAGS := -I$(STAGING_DIR)/usr/include \
		 -I$(STAGING_DIR)/usr/include/eap_peer \
		 -I$(STAGING_DIR)/usr/include/dbus-1.0 \
		 -I$(STAGING_DIR)/usr/include/glib-2.0 \
		 -DEAP_TLS -DEAP_TTLS -DEAP_MD5 -DEAP_CHAP -DEAP_MSCHAPv2 \
		 -DCONFDIR="/etc/gctwimax" -DIEEE8021X_EAPOL \
		 -MMD -O2 -g -Wall

TARGET_LDFLAGS := \
		-Wl,-rpath=$(STAGING_DIR)/usr/lib \
		-L$(STAGING_DIR)/usr/lib \
		-lssl \

define Package/gctwimax/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/gctwimax $(1)/usr/sbin/
	$(INSTALL_DIR) $(1)/etc/gctwimax
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/event.sh $(1)/etc/gctwimax
	$(INSTALL_BIN) ./files/event.sh $(1)/etc/gctwimax
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/src/gctwimax.conf $(1)/etc/gctwimax
#	$(INSTALL_DIR) $(1)/etc/hotplug.d/usb
#	$(INSTALL_BIN) ./files/25-gctwimax $(1)/etc/hotplug.d/usb
#	$(INSTALL_DIR) $(1)/etc/hotplug.d/net
#	$(INSTALL_BIN) ./files/25-wimax $(1)/etc/hotplug.d/net
endef

$(eval $(call BuildPackage,gctwimax))
