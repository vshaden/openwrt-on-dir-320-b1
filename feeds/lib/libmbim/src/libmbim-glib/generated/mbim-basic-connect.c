
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


#include <string.h>

#include "mbim-basic-connect.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimDeviceServiceElement */

/**
 * mbim_device_service_element_free:
 * @var: a #MbimDeviceServiceElement.
 *
 * Frees the memory allocated for the #MbimDeviceServiceElement.
 */
void
mbim_device_service_element_free (MbimDeviceServiceElement *var)
{
    g_free (var->cids);
    g_free (var);
}

/**
 * mbim_device_service_element_array_free:
 * @array: a #NULL-terminated array of #MbimDeviceServiceElement structs.
 *
 * Frees the memory allocated for the array of #MbimDeviceServiceElements.
 */
void
mbim_device_service_element_array_free (MbimDeviceServiceElement **array)
{
    guint32 i;

    for (i = 0; array[i]; i++)
        mbim_device_service_element_free (array[i]);
    g_free (array);
}

static MbimDeviceServiceElement *
_mbim_device_service_element_read (
    const MbimMessage *self,
    guint32 relative_offset)
{
    MbimDeviceServiceElement *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new (MbimDeviceServiceElement, 1);

    memcpy (&out->device_service_id, _mbim_message_read_uuid (self, offset), 16);
    offset += 16;

    out->dss_payload = _mbim_message_read_guint32 (self, offset);
    offset += 4;

    out->max_dss_instances = _mbim_message_read_guint32 (self, offset);
    offset += 4;

    out->cids_count = _mbim_message_read_guint32 (self, offset);
    offset += 4;

    out->cids = _mbim_message_read_guint32_array (self, out->cids_count, offset);
    offset += (4 * out->cids_count);

    return out;
}

static MbimDeviceServiceElement **
_mbim_device_service_element_read_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start)
{
    MbimDeviceServiceElement **out;
    guint32 i;
    guint32 offset;

    out = g_new (MbimDeviceServiceElement *, array_size + 1);
    offset = relative_offset_array_start;
    for (i = 0; i < array_size; i++, offset += 8)
        out[i] = _mbim_device_service_element_read (self, _mbim_message_read_guint32 (self, offset));
    out[array_size] = NULL;

    return out;
}

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Device Caps */

/**
 * mbim_message_basic_connect_device_caps_query_request_new:
 * @transaction_id: the transaction ID to use in the request.
 *
 * Create a new request for the 'Device Caps' command in the 'Basic Connect' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 */
MbimMessage *
mbim_message_basic_connect_device_caps_query_request_new (guint32 transaction_id)
{
    return mbim_message_command_new (transaction_id,
                                     MBIM_SERVICE_BASIC_CONNECT,
                                     MBIM_CID_BASIC_CONNECT_DEVICE_CAPS,
                                     MBIM_MESSAGE_COMMAND_TYPE_QUERY);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_device_type:
 * @self: a #MbimMessage.
 *
 * Get the 'Device Type' field from the 'device_caps' query response
 *
 * Returns: a #MbimDeviceType.
 */
MbimDeviceType
mbim_message_basic_connect_device_caps_query_response_get_device_type (
    const MbimMessage *self)
{
    guint32 offset = 0;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimDeviceType) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_cellular_class:
 * @self: a #MbimMessage.
 *
 * Get the 'Cellular Class' field from the 'device_caps' query response
 *
 * Returns: a #MbimCellularClass.
 */
MbimCellularClass
mbim_message_basic_connect_device_caps_query_response_get_cellular_class (
    const MbimMessage *self)
{
    guint32 offset = 4;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimCellularClass) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_voice_class:
 * @self: a #MbimMessage.
 *
 * Get the 'Voice Class' field from the 'device_caps' query response
 *
 * Returns: a #MbimVoiceClass.
 */
MbimVoiceClass
mbim_message_basic_connect_device_caps_query_response_get_voice_class (
    const MbimMessage *self)
{
    guint32 offset = 8;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimVoiceClass) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_sim_class:
 * @self: a #MbimMessage.
 *
 * Get the 'Sim Class' field from the 'device_caps' query response
 *
 * Returns: a #MbimSimClass.
 */
MbimSimClass
mbim_message_basic_connect_device_caps_query_response_get_sim_class (
    const MbimMessage *self)
{
    guint32 offset = 12;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimSimClass) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_data_class:
 * @self: a #MbimMessage.
 *
 * Get the 'Data Class' field from the 'device_caps' query response
 *
 * Returns: a #MbimDataClass.
 */
MbimDataClass
mbim_message_basic_connect_device_caps_query_response_get_data_class (
    const MbimMessage *self)
{
    guint32 offset = 16;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimDataClass) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_sms_caps:
 * @self: a #MbimMessage.
 *
 * Get the 'Sms Caps' field from the 'device_caps' query response
 *
 * Returns: a #MbimSmsCaps.
 */
MbimSmsCaps
mbim_message_basic_connect_device_caps_query_response_get_sms_caps (
    const MbimMessage *self)
{
    guint32 offset = 20;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimSmsCaps) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_ctrl_caps:
 * @self: a #MbimMessage.
 *
 * Get the 'Ctrl Caps' field from the 'device_caps' query response
 *
 * Returns: a #MbimCtrlCaps.
 */
MbimCtrlCaps
mbim_message_basic_connect_device_caps_query_response_get_ctrl_caps (
    const MbimMessage *self)
{
    guint32 offset = 24;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimCtrlCaps) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_max_sessions:
 * @self: a #MbimMessage.
 *
 * Get the 'Max Sessions' field from the 'device_caps' query response
 *
 * Returns: a #guint32.
 */
guint32
mbim_message_basic_connect_device_caps_query_response_get_max_sessions (
    const MbimMessage *self)
{
    guint32 offset = 28;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (guint32) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_custom_data_class:
 * @self: a #MbimMessage.
 *
 * Get the 'Custom Data Class' field from the 'device_caps' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_device_caps_query_response_get_custom_data_class (
    const MbimMessage *self)
{
    guint32 offset = 32;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_device_id:
 * @self: a #MbimMessage.
 *
 * Get the 'Device ID' field from the 'device_caps' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_device_caps_query_response_get_device_id (
    const MbimMessage *self)
{
    guint32 offset = 40;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_firmware_info:
 * @self: a #MbimMessage.
 *
 * Get the 'Firmware Info' field from the 'device_caps' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_device_caps_query_response_get_firmware_info (
    const MbimMessage *self)
{
    guint32 offset = 48;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/**
 * mbim_message_basic_connect_device_caps_query_response_get_hardware_info:
 * @self: a #MbimMessage.
 *
 * Get the 'Hardware Info' field from the 'device_caps' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_device_caps_query_response_get_hardware_info (
    const MbimMessage *self)
{
    guint32 offset = 56;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Subscriber Ready Status */

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_request_new:
 * @transaction_id: the transaction ID to use in the request.
 *
 * Create a new request for the 'Subscriber Ready Status' command in the 'Basic Connect' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 */
MbimMessage *
mbim_message_basic_connect_subscriber_ready_status_query_request_new (guint32 transaction_id)
{
    return mbim_message_command_new (transaction_id,
                                     MBIM_SERVICE_BASIC_CONNECT,
                                     MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS,
                                     MBIM_MESSAGE_COMMAND_TYPE_QUERY);
}

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_state:
 * @self: a #MbimMessage.
 *
 * Get the 'Ready State' field from the 'subscriber_ready_status' query response
 *
 * Returns: a #MbimSubscriberReadyState.
 */
MbimSubscriberReadyState
mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_state (
    const MbimMessage *self)
{
    guint32 offset = 0;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimSubscriberReadyState) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_response_get_subscriber_id:
 * @self: a #MbimMessage.
 *
 * Get the 'Subscriber ID' field from the 'subscriber_ready_status' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_subscriber_ready_status_query_response_get_subscriber_id (
    const MbimMessage *self)
{
    guint32 offset = 4;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_response_get_sim_iccid:
 * @self: a #MbimMessage.
 *
 * Get the 'SIM ICCID' field from the 'subscriber_ready_status' query response
 *
 * Returns: a newly allocated string, which should be freed with g_free().
 */
gchar *
mbim_message_basic_connect_subscriber_ready_status_query_response_get_sim_iccid (
    const MbimMessage *self)
{
    guint32 offset = 12;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    return (gchar *) _mbim_message_read_string (self, offset);
}

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_info:
 * @self: a #MbimMessage.
 *
 * Get the 'Ready Info' field from the 'subscriber_ready_status' query response
 *
 * Returns: a #MbimReadyInfoFlag.
 */
MbimReadyInfoFlag
mbim_message_basic_connect_subscriber_ready_status_query_response_get_ready_info (
    const MbimMessage *self)
{
    guint32 offset = 20;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (MbimReadyInfoFlag) _mbim_message_read_guint32 (self, offset);
}

static guint32
_mbim_message_basic_connect_subscriber_ready_status_query_response_get_telephone_numbers_count (
    const MbimMessage *self)
{
    guint32 offset = 24;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (guint32) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_subscriber_ready_status_query_response_get_telephone_numbers:
 * @self: a #MbimMessage.
 * @size: (out) (allow-none): number of items in the output array.
 *
 * Get the 'Telephone Numbers' field from the 'subscriber_ready_status' query response
 *
 * Returns: a newly allocated array of strings, which should be freed with g_strfreev().
 */
gchar **
mbim_message_basic_connect_subscriber_ready_status_query_response_get_telephone_numbers (
    const MbimMessage *self,
    guint32 *size)
{
    guint32 offset = 28;
    guint32 tmp;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    tmp = _mbim_message_basic_connect_subscriber_ready_status_query_response_get_telephone_numbers_count (self);
    if (size)
        *size = tmp;
    return (gchar **) _mbim_message_read_string_array (self, tmp, offset)
;}

/*****************************************************************************/
/* Message (Query): MBIM Message Basic Connect Device Services */

/**
 * mbim_message_basic_connect_device_services_query_request_new:
 * @transaction_id: the transaction ID to use in the request.
 *
 * Create a new request for the 'Device Services' command in the 'Basic Connect' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 */
MbimMessage *
mbim_message_basic_connect_device_services_query_request_new (guint32 transaction_id)
{
    return mbim_message_command_new (transaction_id,
                                     MBIM_SERVICE_BASIC_CONNECT,
                                     MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES,
                                     MBIM_MESSAGE_COMMAND_TYPE_QUERY);
}

static guint32
_mbim_message_basic_connect_device_services_query_response_get_device_services_count (
    const MbimMessage *self)
{
    guint32 offset = 0;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (guint32) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_services_query_response_get_max_dss_sessions:
 * @self: a #MbimMessage.
 *
 * Get the 'Max DSS Sessions' field from the 'device_services' query response
 *
 * Returns: a #guint32.
 */
guint32
mbim_message_basic_connect_device_services_query_response_get_max_dss_sessions (
    const MbimMessage *self)
{
    guint32 offset = 4;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, 0);
    return (guint32) _mbim_message_read_guint32 (self, offset);
}

/**
 * mbim_message_basic_connect_device_services_query_response_get_device_services:
 * @self: a #MbimMessage.
 * @size: (out) (allow-none): number of items in the output array.
 *
 * Get the 'Device Services' field from the 'device_services' query response
 *
 * Returns: a newly allocated array of #MbimDeviceServiceElement, which should be freed with mbim_device_service_element_free_array().
 */
MbimDeviceServiceElement **
mbim_message_basic_connect_device_services_query_response_get_device_services (
    const MbimMessage *self,
    guint32 *size)
{
    guint32 offset = 8;
    guint32 tmp;

    g_return_val_if_fail (MBIM_MESSAGE_GET_MESSAGE_TYPE (self) == MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL);
    tmp = _mbim_message_basic_connect_device_services_query_response_get_device_services_count (self);
    if (size)
        *size = tmp;
    return (MbimDeviceServiceElement **) _mbim_device_service_element_read_array (self, tmp, offset)
;}
