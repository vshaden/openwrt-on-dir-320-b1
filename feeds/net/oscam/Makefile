include $(TOPDIR)/rules.mk

PKG_BRANCH:=trunk
PKG_SOURCE_URL:=http://www.streamboard.tv/svn/oscam/trunk
#PKG_REV:=$(shell LC_ALL=C svn info ${PKG_SOURCE_URL} | sed -ne's/^Last Changed Rev: //p')
PKG_REV:=5339

PKG_NAME:=oscam
PKG_VERSION:=svn$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_SOURCE_SUBDIR).tar.gz
PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)

#PKG_BUILD_DEPENDS:=libpthread

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_INSTALL_DIR:=$(PKG_BUILD_DIR)



include $(INCLUDE_DIR)/package.mk

define Package/oscam
SECTION:=custom
CATEGORY:=Custom packages
DEPENDS:=+libusb +libopenssl +libpthread +librt
TITLE:=Open Source Conditional Access Module software
URL:=http://streamboard.tv/oscam/
#SUBMENU:=
endef

define Package/oscam/description
	An Open Source Conditional Access Module software,
	based on the very good MpCS version 0.9d created by dukat.
endef

CONFIGURE_ARGS += --with-ssl=openssl

define Build/Prepare
	$(call Build/Prepare/Default)
	sed -i "s/mips-linux-gcc/$(TARGET_CC)/g" $(PKG_BUILD_DIR)/toolchains/toolchain-mips-dir825.cmake
	sed -i "s/DIR-825/DIR-320-NRU/g" $(PKG_BUILD_DIR)/toolchains/toolchain-mips-dir825.cmake 		
	#cd $(PKG_BUILD_DIR) && sh config.sh	
	mkdir -p $(PKG_BUILD_DIR)/build
	cd $(PKG_BUILD_DIR)/build;
endef
	
define Package/oscam/conffiles
endef

define Build/Compile
	cd $(PKG_BUILD_DIR)/build; \
	cmake \
		-DWEBIF=1 \
		-DHAVE_DVBAPI=1 \
		-DHAVE_LIBUSB=1 \
		-DWITH_SSL=1 \
		-DLIBUSBDIR=$(STAGING_DIR)/usr \
		-DCMAKE_TOOLCHAIN_FILE=$(PKG_BUILD_DIR)/toolchains/toolchain-mips-dir825.cmake ..; \
	make
endef

define Package/oscam/conffiles
	/etc/config/epg
	/etc/oscam/oscam.conf
	/etc/oscam/oscam.server
	/etc/oscam/oscam.user
endef

define Package/oscam/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/oscam $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/etc/oscam
	$(INSTALL_CONF) ./files/oscam.conf $(1)/etc/oscam/
	$(INSTALL_CONF) ./files/oscam.server $(1)/etc/oscam/
	$(INSTALL_CONF) ./files/oscam.user $(1)/etc/oscam/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/oscam.init $(1)/etc/init.d/oscam
endef
	
$(eval $(call BuildPackage,oscam)) 
