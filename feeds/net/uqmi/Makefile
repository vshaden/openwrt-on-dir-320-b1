#
# Copyright (C) 2011-2013 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=uqmi
PKG_VERSION:=20130305
PKG_REV:=b61b3e8ff2b29e08b53eabc7b813c1c87c734947
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=git://nbd.name/uqmi.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_BUILD_DIR=$(BUILD_DIR)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/uqmi/default
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:= $(3)
	VARIANT:=$(2)
	TITLE:=Standalone QMI Utility ( using $(1) )
	URL:=http://nbd.name/gitweb.cgi?p=uqmi.git
endef

Package/uqmi-dynamic=$(call Package/uqmi/default, dynamic linking, dynamic, +libubox)
Package/uqmi-static=$(call Package/uqmi/default, static linking, static)

define Package/uqmi/description
 uqmi is a small QMI utility
endef

ifeq ($(BUILD_VARIANT),dynamic)
	CONFIG_UQMI_DYNAMIC:=y
	include $(INCLUDE_DIR)/cmake.mk
	CMAKE_OPTIONS += -DOPTIONAL_INCLUDE_DIR=$(STAGING_DIR)/opt/include
endif

ifeq ($(BUILD_VARIANT),static)
	CONFIG_UQMI_STATIC:=y
#	define Build/Prepare
#		mkdir -p $(PKG_BUILD_DIR)
#		$(CP) ./src-static/* $(PKG_BUILD_DIR)
#		$(MAKE) -C $(PKG_BUILD_DIR)/libuboxm \
#		$(MAKE_ARGS) \
#			CC="$(TARGET_CC)" CFLAGS="$(TARGET_CFLAGS)" \
#			LDFLAGS="$(TARGET_LDFLAGS)"
#	endef
endif

define Build/Prepare
	$(if $(CONFIG_UQMI_STATIC),
		mkdir -p $(PKG_BUILD_DIR); \
		$(CP) ./src-static/* $(PKG_BUILD_DIR); \
		$(MAKE) -C $(PKG_BUILD_DIR)/libuboxm \
		$(MAKE_ARGS) \
			CC="$(TARGET_CC)" CFLAGS="$(TARGET_CFLAGS)" \
			LDFLAGS="$(TARGET_LDFLAGS)";
	)
	$(if $(CONFIG_UQMI_DYNAMIC),
		$(call Build/Prepare/Default)
	)
endef

define Package/uqmi-$(BUILD_VARIANT)/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/uqmi $(1)/sbin/
endef

$(eval $(call BuildPackage,uqmi-dynamic))
$(eval $(call BuildPackage,uqmi-static))