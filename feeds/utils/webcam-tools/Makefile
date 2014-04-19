#
# Copyright (C) 2008-2013 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=webcam-tools
PKG_VERSION:=0.2.4
PKG_RELEASE:=1

PKG_SOURCE:=libwebcam-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/project/libwebcam/source


include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libwebcam
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libxml2 +libiconv-full
  TITLE:=Webcam library
endef

define Package/uvcdynctrl
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libwebcam
  TITLE:=Manage dynamic controls in uvcvideo
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include -I$(STAGING_DIR)/usr/lib/libiconv-full/include
TARGET_LDFLAGS += -L$(STAGING_DIR)/usr/lib -L$(STAGING_DIR)/usr/lib/libiconv-full/lib

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_BUILD_DIR)/libwebcam/libwebcam.h $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/libwebcam/libwebcam.pc $(1)/usr/lib/pkgconfig
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libwebcam/libwebcam.so* $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libwebcam/libwebcam.a $(1)/usr/lib
endef

define Package/libwebcam/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/libwebcam/libwebcam.so* $(1)/usr/lib/
endef


define Package/uvcdynctrl/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_BUILD_DIR)/uvcdynctrl/uvcdynctrl{,-$(PKG_VERSION)} $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,uvcdynctrl))
$(eval $(call BuildPackage,libwebcam))
