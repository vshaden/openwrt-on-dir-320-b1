#
# Copyright (C) 2007 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# $Id$

include $(TOPDIR)/rules.mk

PKG_NAME:=oscam
PKG_RELEASE:=1

PKG_SOURCE_URL:=http://www.streamboard.tv/svn/oscam/trunk
PKG_REV:=$(shell svn info ${PKG_SOURCE_URL} | sed -ne's/^Last Changed Rev: //p')
PKG_VER:=$(shell svn info ${PKG_SOURCE_URL} | grep -oE [0-9]{4}-[0-9]{2}-[0-9]{2})
PKG_VERSION:=$(PKG_VER)-$(PKG_REV)

PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_SOURCE_SUBDIR).tar.bz2
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/oscam
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Open Source Conditional Access Module
  URL:=http://www.streamboard.tv/oscam/wiki/BuildingOscam
  DEPENDS:=+libopenssl +libusb-1.0
  MENU:=1
endef

define Package/oscam/config
  source "$(SOURCE)/Config.in"
endef

define Package/list-smargo
  $(call Package/oscam)
  TITLE:=Smargo reader support
  DEPENDS:=oscam @OSCAM_CARDREADER_SMARGO
  MENU:=0
endef

###################### CONFIGURE FEATURES ########################################
ADDONS_LIST:=WEBIF \
		TOUCH \
		HAVE_DVBAPI \
		IRDETO_GUESSING \
		CS_ANTICASC \
		WITH_DEBUG \
		MODULE_MONITOR \
		WITH_SSL \
		WITH_LB \
		CS_CACHEEX \
		CW_CYCLE_CHECK \
		LCDSUPPORT \
		LEDSUPPORT \
		IPV6SUPPORT

ADDONS_ENABLED:=
define addons
	ifeq ($(CONFIG_OSCAM_ADDON_$(1)),y)
		ADDONS_ENABLED += $(1)
	endif
endef
$(foreach addon,$(ADDONS_LIST),$(eval $(call addons,$(addon))))

PROTOCOLS_LIST:=CAMD33 \
		CAMD35 \
		CAMD35_TCP \
		NEWCAMD \
		CCCAM \
		CCCSHARE \
		GBOX \
		RADEGAST \
		SERIAL \
		CONSTCW \
		PANDORA \
		GHTTP

PROTOCOLS_ENABLED:=
define protocols
	ifeq ($(CONFIG_OSCAM_MODULE_$(1)),y)
		PROTOCOLS_ENABLED += MODULE_$(1)
	endif
endef
$(foreach protocol,$(PROTOCOLS_LIST),$(eval $(call protocols,$(protocol))))

READERS_LIST:=NAGRA \
		IRDETO \
		CONAX \
		CRYPTOWORKS \
		SECA \
		VIACCESS \
		VIDEOGUARD \
		DRE \
		TONGFANG \
		BULCRYPT \
		GRIFFIN \
		DGCRYPT

READERS_ENABLED:=
define readers
	ifeq ($(CONFIG_OSCAM_READER_$(1)),y)
		READERS_ENABLED += READER_$(1)
	endif
endef
$(foreach reader,$(READERS_LIST),$(eval $(call readers,$(reader))))

CARDREADERS_LIST:=HOENIX \
		NTERNAL \
		SC8IN1 \
		MP35 \
		SMARGO \
		DB2COM \
		STAPI

CARDREADERS_ENABLED:=
define cardreaders
	ifeq ($(CONFIG_OSCAM_CARDREADER_$(1)),y)
		CARDREADERS_ENABLED += CARDREADER_$(1)
	endif
endef
$(foreach cardreader,$(CARDREADERS_LIST),$(eval $(call cardreaders,$(cardreader))))

ifneq ($(CARDREADERS_ENABLED),)
	MAKE_FLAGS += USE_LIBUSB=1
endif

ifeq ($(CONFIG_OSCAM_ADDONS_WITH_SSL),y)
	MAKE_FLAGS += USE_LIBCRYPTO=1 USE_SSL=1
endif

ifneq ($(CONFIG_PACKAGE_list-smargo),)
	MAKE_FLAGS += LIST_SMARGO_BIN=Distribution/list-smargo
endif
######################################################################################

define Build/Prepare
	$(call Build/Prepare/Default)
	cd $(PKG_BUILD_DIR); \
		$(PKG_BUILD_DIR)/config.sh --disable all		
		$(PKG_BUILD_DIR)/config.sh --enable $(ADDONS_ENABLED) $(PROTOCOLS_ENABLED) $(READERS_ENABLED) $(CARDREADERS_ENABLED)
endef

MAKE_FLAGS += OSCAM_BIN=Distribution/oscam

define Package/oscam/conffiles
	/etc/oscam/oscam.conf
	/etc/oscam/oscam.server
	/etc/oscam/oscam.user
endef

define Package/oscam/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/Distribution/oscam $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/etc/oscam
	$(INSTALL_CONF) ./files/oscam.conf $(1)/etc/oscam/
	$(INSTALL_CONF) ./files/oscam.server $(1)/etc/oscam/
	$(INSTALL_CONF) ./files/oscam.user $(1)/etc/oscam/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/oscam.init $(1)/etc/init.d/oscam
endef

define Package/list-smargo/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/Distribution/list-smargo $(1)/usr/bin/list-smargo
endef

$(eval $(call BuildPackage,oscam))
$(eval $(call BuildPackage,list-smargo))
