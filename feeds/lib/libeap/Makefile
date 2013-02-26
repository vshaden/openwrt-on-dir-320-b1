#
# Copyright (C) 2006-2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libeap
DOWNLOAD_NAME:=hostapd
PKG_VERSION:=20110527
PKG_RELEASE:=2
PKG_REV:=ceb34f250af7a7082f18c1e0451dc7fbc0f000f3

PKG_SOURCE:=$(DOWNLOAD_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=git://w1.fi/srv/git/hostap.git
PKG_SOURCE_SUBDIR:=$(DOWNLOAD_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_PROTO:=git
PKG_BUILD_DEPENDS:=openssl
PKG_MIRROR_MD5SUM:=4b98902d782813b41aca1faff613f677

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)/$(DOWNLOAD_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libeap/Default
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=libeap IEEE 802.1x Authenticator
  URL:=http://hostap.epitest.fi/
  MAINTAINER:=Felix Fietkau <nbd@openwrt.org>
endef

define Package/libeap
$(call Package/libeap/Default)
endef

define Package/hostapd/description
 This package contains libeap from hostapd/wpa_supplicant
 Authenticator.
endef

TARGET_CFLAGS += -ffunction-sections -fdata-sections \
		-DCONFIG_NO_RANDOM_POOL=y \
		-I$(STAGING_DIR)/usr/include
TARGET_LDFLAGS += -Wl,--gc-sections

define Build/Compile/libeap
	CFLAGS="$(TARGET_CFLAGS)" \
	$(MAKE) -C $(PKG_BUILD_DIR)/src/eap_peer \
		$(TARGET_CONFIGURE_OPTS) \
		LIBS="$(TARGET_LDFLAGS)"
endef

define Build/Compile
	$(Build/Compile/libeap)
endef

define Install/libeap
	$(INSTALL_DIR) $(1)/usr/lib
	$(MAKE) -C $(PKG_BUILD_DIR)/src/eap_peer install \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		LIBS="$(TARGET_LDFLAGS)"
	$(LN) libeap.so.0.0.0 $(PKG_INSTALL_DIR)/usr/lib/libeap.so.0
	$(CP) $(PKG_INSTALL_DIR)/usr/include/eap_peer $(STAGING_DIR)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libeap.so* $(STAGING_DIR)/usr/lib
endef

define Package/libeap/install
	$(call Install/libeap,$(1))
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libeap.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libeap))
