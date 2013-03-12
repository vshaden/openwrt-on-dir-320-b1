
/* GENERATED CODE... DO NOT EDIT */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 Aleksander Morgado <aleksander@gnu.org>
 */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "mbim-message.h"
#include "mbim-device.h"
#include "mbim-enums.h"

#ifndef __LIBMBIM_GLIB_MBIM_BASIC_CONNECT__
#define __LIBMBIM_GLIB_MBIM_BASIC_CONNECT__

G_BEGIN_DECLS

/*****************************************************************************/
/* Struct: MbimDeviceServiceElement */

typedef struct {
    MbimUuid device_service_id;
    guint32 dss_payload;
    guint32 max_dss_instances;
    guint32 cids_count;
    guint32 *cids;
} MbimDeviceServiceElement;

void mbim_device_service_element_free (MbimDeviceServiceElement *var);
void mbim_device_service_element_array_free (MbimDeviceServiceElement **array);

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Device Caps */

MbimMessage *mbim_message_basic_connect_device_caps_query_request_new (guint32 transaction_id);

/* Query response */
MbimDeviceType mbim_message_basic_connect_device_caps_query_response_get_device_type (
    const MbimMessage *self);

MbimCellularClass mbim_message_basic_connect_device_caps_query_response_get_cellular_class (
    const MbimMessage *self);

MbimVoiceClass mbim_message_basic_connect_device_caps_query_response_get_voice_class (
    const MbimMessage *self);

MbimSimClass mbim_message_basic_connect_device_caps_query_response_get_sim_class (
    const MbimMessage *self);

MbimDataClass mbim_message_basic_connect_device_caps_query_response_get_data_class (
    const MbimMessage *self);

MbimSmsCaps mbim_message_basic_connect_device_caps_query_response_get_sms_caps (
    const MbimMessage *self);

MbimCtrlCaps mbim_message_basic_connect_device_caps_query_response_get_ctrl_caps (
    const MbimMessage *self);

guint32 mbim_message_basic_connect_device_caps_query_response_get_max_sessions (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_device_caps_query_response_get_custom_data_class (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_device_caps_query_response_get_device_id (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_device_caps_query_response_get_firmware_info (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_device_caps_query_response_get_hardware_info (
    const MbimMessage *self);

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Subscriber Ready Status */

MbimMessage *mbim_message_basic_connect_subscriber_ready_status_query_request_new (guint32 transaction_id);

/* Query response */
MbimSubscriberReadyState mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_state (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_subscriber_ready_status_query_response_get_subscriber_id (
    const MbimMessage *self);

gchar * mbim_message_basic_connect_subscriber_ready_status_query_response_get_sim_iccid (
    const MbimMessage *self);

MbimReadyInfoFlag mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_info (
    const MbimMessage *self);

gchar ** mbim_message_basic_connect_subscriber_ready_status_query_response_get_telephone_numbers (
    const MbimMessage *self,
    guint32 *size);

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Device Services */

MbimMessage *mbim_message_basic_connect_device_services_query_request_new (guint32 transaction_id);

/* Query response */
guint32 mbim_message_basic_connect_device_services_query_response_get_max_dss_sessions (
    const MbimMessage *self);

MbimDeviceServiceElement ** mbim_message_basic_connect_device_services_query_response_get_device_services (
    const MbimMessage *self,
    guint32 *size);

G_END_DECLS

#endif /* __LIBMBIM_GLIB_MBIM_BASIC_CONNECT__ */
