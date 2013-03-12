
/* Generated data (by glib-mkenums) */

#include "mbim-errors.h"
#include "mbim-error-types.h"
/* enumerations from "../../libmbim-glib/mbim-errors.h" */
static const GEnumValue mbim_core_error_values[] = {
    { MBIM_CORE_ERROR_FAILED, "MBIM_CORE_ERROR_FAILED", "Failed" },
    { MBIM_CORE_ERROR_WRONG_STATE, "MBIM_CORE_ERROR_WRONG_STATE", "WrongState" },
    { MBIM_CORE_ERROR_TIMEOUT, "MBIM_CORE_ERROR_TIMEOUT", "Timeout" },
    { MBIM_CORE_ERROR_INVALID_ARGS, "MBIM_CORE_ERROR_INVALID_ARGS", "InvalidArgs" },
    { MBIM_CORE_ERROR_INVALID_MESSAGE, "MBIM_CORE_ERROR_INVALID_MESSAGE", "InvalidMessage" },
    { MBIM_CORE_ERROR_UNSUPPORTED, "MBIM_CORE_ERROR_UNSUPPORTED", "Unsupported" },
    { MBIM_CORE_ERROR_ABORTED, "MBIM_CORE_ERROR_ABORTED", "Aborted" },
    { 0, NULL, NULL }
};

/* mbim_core_error_quark() implemented in mbim-errors-quarks.c */

GType
mbim_core_error_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCoreError"),
                                      mbim_core_error_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
const gchar *
mbim_core_error_get_string (MbimCoreError val)
{
    guint i;

    for (i = 0; mbim_core_error_values[i].value_nick; i++) {
        if (val == mbim_core_error_values[i].value)
            return mbim_core_error_values[i].value_nick;
    }

    return NULL;
}

static const GEnumValue mbim_protocol_error_values[] = {
    { MBIM_PROTOCOL_ERROR_INVALID, "MBIM_PROTOCOL_ERROR_INVALID", "Invalid" },
    { MBIM_PROTOCOL_ERROR_TIMEOUT_FRAGMENT, "MBIM_PROTOCOL_ERROR_TIMEOUT_FRAGMENT", "TimeoutFragment" },
    { MBIM_PROTOCOL_ERROR_FRAGMENT_OUT_OF_SEQUENCE, "MBIM_PROTOCOL_ERROR_FRAGMENT_OUT_OF_SEQUENCE", "FragmentOutOfSequence" },
    { MBIM_PROTOCOL_ERROR_LENGTH_MISMATCH, "MBIM_PROTOCOL_ERROR_LENGTH_MISMATCH", "LengthMismatch" },
    { MBIM_PROTOCOL_ERROR_DUPLICATED_TID, "MBIM_PROTOCOL_ERROR_DUPLICATED_TID", "DuplicatedTid" },
    { MBIM_PROTOCOL_ERROR_NOT_OPENED, "MBIM_PROTOCOL_ERROR_NOT_OPENED", "NotOpened" },
    { MBIM_PROTOCOL_ERROR_UNKNOWN, "MBIM_PROTOCOL_ERROR_UNKNOWN", "Unknown" },
    { MBIM_PROTOCOL_ERROR_CANCEL, "MBIM_PROTOCOL_ERROR_CANCEL", "Cancel" },
    { MBIM_PROTOCOL_ERROR_MAX_TRANSFER, "MBIM_PROTOCOL_ERROR_MAX_TRANSFER", "MaxTransfer" },
    { 0, NULL, NULL }
};

/* mbim_protocol_error_quark() implemented in mbim-errors-quarks.c */

GType
mbim_protocol_error_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimProtocolError"),
                                      mbim_protocol_error_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
const gchar *
mbim_protocol_error_get_string (MbimProtocolError val)
{
    guint i;

    for (i = 0; mbim_protocol_error_values[i].value_nick; i++) {
        if (val == mbim_protocol_error_values[i].value)
            return mbim_protocol_error_values[i].value_nick;
    }

    return NULL;
}

static const GEnumValue mbim_status_error_values[] = {
    { MBIM_STATUS_ERROR_NONE, "MBIM_STATUS_ERROR_NONE", "none" },
    { MBIM_STATUS_ERROR_BUSY, "MBIM_STATUS_ERROR_BUSY", "busy" },
    { MBIM_STATUS_ERROR_FAILURE, "MBIM_STATUS_ERROR_FAILURE", "failure" },
    { MBIM_STATUS_ERROR_SIM_NOT_INSERTED, "MBIM_STATUS_ERROR_SIM_NOT_INSERTED", "sim-not-inserted" },
    { MBIM_STATUS_ERROR_BAD_SIM, "MBIM_STATUS_ERROR_BAD_SIM", "bad-sim" },
    { MBIM_STATUS_ERROR_PIN_REQUIRED, "MBIM_STATUS_ERROR_PIN_REQUIRED", "pin-required" },
    { MBIM_STATUS_ERROR_PIN_DISABLED, "MBIM_STATUS_ERROR_PIN_DISABLED", "pin-disabled" },
    { MBIM_STATUS_ERROR_NOT_REGISTERED, "MBIM_STATUS_ERROR_NOT_REGISTERED", "not-registered" },
    { MBIM_STATUS_ERROR_PROVIDERS_NOT_FOUND, "MBIM_STATUS_ERROR_PROVIDERS_NOT_FOUND", "providers-not-found" },
    { MBIM_STATUS_ERROR_NO_DEVICE_SUPPORT, "MBIM_STATUS_ERROR_NO_DEVICE_SUPPORT", "no-device-support" },
    { MBIM_STATUS_ERROR_PROVIDER_NOT_VISIBLE, "MBIM_STATUS_ERROR_PROVIDER_NOT_VISIBLE", "provider-not-visible" },
    { MBIM_STATUS_ERROR_DATA_CLASS_NOT_AVAILABLE, "MBIM_STATUS_ERROR_DATA_CLASS_NOT_AVAILABLE", "data-class-not-available" },
    { MBIM_STATUS_ERROR_PACKET_SERVICE_DETACHED, "MBIM_STATUS_ERROR_PACKET_SERVICE_DETACHED", "packet-service-detached" },
    { MBIM_STATUS_ERROR_MAX_ACTIVATED_CONTEXTS, "MBIM_STATUS_ERROR_MAX_ACTIVATED_CONTEXTS", "max-activated-contexts" },
    { MBIM_STATUS_ERROR_NOT_INITIALIZED, "MBIM_STATUS_ERROR_NOT_INITIALIZED", "not-initialized" },
    { MBIM_STATUS_ERROR_VOICE_CALL_IN_PROGRESS, "MBIM_STATUS_ERROR_VOICE_CALL_IN_PROGRESS", "voice-call-in-progress" },
    { MBIM_STATUS_ERROR_CONTEXT_NOT_ACTIVATED, "MBIM_STATUS_ERROR_CONTEXT_NOT_ACTIVATED", "context-not-activated" },
    { MBIM_STATUS_ERROR_SERVICE_NOT_ACTIVATED, "MBIM_STATUS_ERROR_SERVICE_NOT_ACTIVATED", "service-not-activated" },
    { MBIM_STATUS_ERROR_INVALID_ACCESS_STRING, "MBIM_STATUS_ERROR_INVALID_ACCESS_STRING", "invalid-access-string" },
    { MBIM_STATUS_ERROR_INVALID_USER_NAME_PWD, "MBIM_STATUS_ERROR_INVALID_USER_NAME_PWD", "invalid-user-name-pwd" },
    { MBIM_STATUS_ERROR_RADIO_POWER_OFF, "MBIM_STATUS_ERROR_RADIO_POWER_OFF", "radio-power-off" },
    { MBIM_STATUS_ERROR_INVALID_PARAMETERS, "MBIM_STATUS_ERROR_INVALID_PARAMETERS", "invalid-parameters" },
    { MBIM_STATUS_ERROR_READ_FAILURE, "MBIM_STATUS_ERROR_READ_FAILURE", "read-failure" },
    { MBIM_STATUS_ERROR_WRITE_FAILURE, "MBIM_STATUS_ERROR_WRITE_FAILURE", "write-failure" },
    { MBIM_STATUS_ERROR_NO_PHONEBOOK, "MBIM_STATUS_ERROR_NO_PHONEBOOK", "no-phonebook" },
    { MBIM_STATUS_ERROR_PARAMETER_TOO_LONG, "MBIM_STATUS_ERROR_PARAMETER_TOO_LONG", "parameter-too-long" },
    { MBIM_STATUS_ERROR_STK_BUSY, "MBIM_STATUS_ERROR_STK_BUSY", "stk-busy" },
    { MBIM_STATUS_ERROR_OPERATION_NOT_ALLOWED, "MBIM_STATUS_ERROR_OPERATION_NOT_ALLOWED", "operation-not-allowed" },
    { MBIM_STATUS_ERROR_MEMORY_FAILURE, "MBIM_STATUS_ERROR_MEMORY_FAILURE", "memory-failure" },
    { MBIM_STATUS_ERROR_INVALID_MEMORY_INDEX, "MBIM_STATUS_ERROR_INVALID_MEMORY_INDEX", "invalid-memory-index" },
    { MBIM_STATUS_ERROR_MEMORY_FULL, "MBIM_STATUS_ERROR_MEMORY_FULL", "memory-full" },
    { MBIM_STATUS_ERROR_FILTER_NOT_SUPPORTED, "MBIM_STATUS_ERROR_FILTER_NOT_SUPPORTED", "filter-not-supported" },
    { MBIM_STATUS_ERROR_DSS_INSTANCE_LIMIT, "MBIM_STATUS_ERROR_DSS_INSTANCE_LIMIT", "dss-instance-limit" },
    { MBIM_STATUS_ERROR_INVALID_DEVICE_SERVICE_OPERATION, "MBIM_STATUS_ERROR_INVALID_DEVICE_SERVICE_OPERATION", "invalid-device-service-operation" },
    { MBIM_STATUS_ERROR_AUTH_INCORRECT_AUTN, "MBIM_STATUS_ERROR_AUTH_INCORRECT_AUTN", "auth-incorrect-autn" },
    { MBIM_STATUS_ERROR_AUTH_SYNC_FAILURE, "MBIM_STATUS_ERROR_AUTH_SYNC_FAILURE", "auth-sync-failure" },
    { MBIM_STATUS_ERROR_AUTH_AMF_NOT_SET, "MBIM_STATUS_ERROR_AUTH_AMF_NOT_SET", "auth-amf-not-set" },
    { MBIM_STATUS_ERROR_SMS_UNKNOWN_SMSC_ADDRESS, "MBIM_STATUS_ERROR_SMS_UNKNOWN_SMSC_ADDRESS", "sms-unknown-smsc-address" },
    { MBIM_STATUS_ERROR_SMS_NETWORK_TIMEOUT, "MBIM_STATUS_ERROR_SMS_NETWORK_TIMEOUT", "sms-network-timeout" },
    { MBIM_STATUS_ERROR_SMS_LANG_NOT_SUPPORTED, "MBIM_STATUS_ERROR_SMS_LANG_NOT_SUPPORTED", "sms-lang-not-supported" },
    { MBIM_STATUS_ERROR_SMS_ENCODING_NOT_SUPPORTED, "MBIM_STATUS_ERROR_SMS_ENCODING_NOT_SUPPORTED", "sms-encoding-not-supported" },
    { MBIM_STATUS_ERROR_SMS_FORMAT_NOT_SUPPORTED, "MBIM_STATUS_ERROR_SMS_FORMAT_NOT_SUPPORTED", "sms-format-not-supported" },
    { 0, NULL, NULL }
};

/* mbim_status_error_quark() implemented in mbim-errors-quarks.c */

GType
mbim_status_error_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimStatusError"),
                                      mbim_status_error_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
const gchar *
mbim_status_error_get_string (MbimStatusError val)
{
    guint i;

    for (i = 0; mbim_status_error_values[i].value_nick; i++) {
        if (val == mbim_status_error_values[i].value)
            return mbim_status_error_values[i].value_nick;
    }

    return NULL;
}


/* Generated data ends here */

