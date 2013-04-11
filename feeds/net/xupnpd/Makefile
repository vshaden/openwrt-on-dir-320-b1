include $(TOPDIR)/rules.mk

PKG_NAME:=xupnpd
PKG_SOURCE_URL:=http://tsdemuxer.googlecode.com/svn/trunk/xupnpd/src/
PKG_REV:=$(shell svn info ${PKG_SOURCE_URL} | sed -ne's/^Last Changed Rev: //p')
PKG_VERSION:=$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=xupnpd-$(PKG_VERSION)
PKG_SOURCE:=$(PKG_SOURCE_SUBDIR).tar.gz


include $(INCLUDE_DIR)/package.mk


TARGET_CFLAGS += -fno-exceptions -fno-rtti -DWITH_URANDOM

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/luaxcore.o $(PKG_BUILD_DIR)/luaxcore.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/luaxlib.o $(PKG_BUILD_DIR)/luaxlib.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/main.o $(PKG_BUILD_DIR)/main.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/mem.o $(PKG_BUILD_DIR)/mem.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/soap.o $(PKG_BUILD_DIR)/soap.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/mcast.o $(PKG_BUILD_DIR)/mcast.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/md5c.o $(PKG_BUILD_DIR)/md5c.c
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/luajson.o $(PKG_BUILD_DIR)/luajson.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(PKG_BUILD_DIR) -I$(STAGING_DIR)/usr/include -o $(PKG_BUILD_DIR)/luajson_parser.o $(PKG_BUILD_DIR)/luajson_parser.cpp
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/xupnpd -L$(STAGING_DIR)/usr/lib \
	$(PKG_BUILD_DIR)/main.o $(PKG_BUILD_DIR)/soap.o $(PKG_BUILD_DIR)/luaxcore.o \
	$(PKG_BUILD_DIR)/mem.o $(PKG_BUILD_DIR)/luaxlib.o $(PKG_BUILD_DIR)/mcast.o \
	$(PKG_BUILD_DIR)/md5c.o $(PKG_BUILD_DIR)/luajson.o $(PKG_BUILD_DIR)/luajson_parser.o -llua -lm -ldl
endef

define Package/xupnpd
  SECTION:=multimedia
  CATEGORY:=Multimedia
  DEPENDS:=+liblua +libuuid
  TITLE:=eXtensible UPnP agent
  URL:=http://xupnpd.org/
endef

define Package/xupnpd/conffiles
/etc/xupnpd/xupnpd.lua
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	mv $(PKG_BUILD_DIR)/xupnpd_main.lua $(PKG_BUILD_DIR)/xupnpd_main_sample.lua
endef

define Package/xupnpd/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/xupnpd $(1)/usr/bin
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/xupnpd.init $(1)/etc/init.d/xupnpd
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_BIN) ./files/xupnpd.config $(1)/etc/config/xupnpd	
	$(INSTALL_DIR) $(1)/etc/xupnpd
	$(CP) $(PKG_BUILD_DIR)/*.lua $(1)/etc/xupnpd
	$(INSTALL_DIR) $(1)/etc/xupnpd/ui
	$(CP) $(PKG_BUILD_DIR)/ui/* $(1)/etc/xupnpd/ui
	$(INSTALL_DIR) $(1)/etc/xupnpd/www
	$(CP) $(PKG_BUILD_DIR)/www/* $(1)/etc/xupnpd/www
	$(INSTALL_DIR) $(1)/etc/xupnpd/plugins
	$(CP) $(PKG_BUILD_DIR)/plugins/* $(1)/etc/xupnpd/plugins
	$(INSTALL_DIR) $(1)/etc/xupnpd/config
	$(INSTALL_DIR) $(1)/etc/xupnpd/playlists
	$(CP) $(PKG_BUILD_DIR)/playlists/* $(1)/etc/xupnpd/playlists
	$(INSTALL_DIR) $(1)/etc/xupnpd/profiles
	$(CP) $(PKG_BUILD_DIR)/profiles/* $(1)/etc/xupnpd/profiles
	$(INSTALL_DIR) $(1)/etc/xupnpd/localmedia
endef

$(eval $(call BuildPackage,xupnpd))
