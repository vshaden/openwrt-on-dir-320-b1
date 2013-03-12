
/* Generated data (by glib-mkenums) */

#include "mbim-errors.h"
#include "mbim-error-types.h"

#include <gio/gio.h>

/* enumerations from "../../libmbim-glib/mbim-errors.h" */

#define ERROR_PREFIX MBIM_CORE_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_core_error_entries[] = {
    { MBIM_CORE_ERROR_FAILED, ERROR_PREFIX ".Failed" },
    { MBIM_CORE_ERROR_WRONG_STATE, ERROR_PREFIX ".WrongState" },
    { MBIM_CORE_ERROR_TIMEOUT, ERROR_PREFIX ".Timeout" },
    { MBIM_CORE_ERROR_INVALID_ARGS, ERROR_PREFIX ".InvalidArgs" },
    { MBIM_CORE_ERROR_INVALID_MESSAGE, ERROR_PREFIX ".InvalidMessage" },
    { MBIM_CORE_ERROR_UNSUPPORTED, ERROR_PREFIX ".Unsupported" },
    { MBIM_CORE_ERROR_ABORTED, ERROR_PREFIX ".Aborted" },
};
#undef ERROR_PREFIX

GQuark
mbim_core_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_core_error_quark",
                                            &quark_volatile,
                                            mbim_core_error_entries,
                                            G_N_ELEMENTS (mbim_core_error_entries));

    return (GQuark) quark_volatile;
}


#define ERROR_PREFIX MBIM_PROTOCOL_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_protocol_error_entries[] = {
    { MBIM_PROTOCOL_ERROR_INVALID, ERROR_PREFIX ".Invalid" },
    { MBIM_PROTOCOL_ERROR_TIMEOUT_FRAGMENT, ERROR_PREFIX ".TimeoutFragment" },
    { MBIM_PROTOCOL_ERROR_FRAGMENT_OUT_OF_SEQUENCE, ERROR_PREFIX ".FragmentOutOfSequence" },
    { MBIM_PROTOCOL_ERROR_LENGTH_MISMATCH, ERROR_PREFIX ".LengthMismatch" },
    { MBIM_PROTOCOL_ERROR_DUPLICATED_TID, ERROR_PREFIX ".DuplicatedTid" },
    { MBIM_PROTOCOL_ERROR_NOT_OPENED, ERROR_PREFIX ".NotOpened" },
    { MBIM_PROTOCOL_ERROR_UNKNOWN, ERROR_PREFIX ".Unknown" },
    { MBIM_PROTOCOL_ERROR_CANCEL, ERROR_PREFIX ".Cancel" },
    { MBIM_PROTOCOL_ERROR_MAX_TRANSFER, ERROR_PREFIX ".MaxTransfer" },
};
#undef ERROR_PREFIX

GQuark
mbim_protocol_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_protocol_error_quark",
                                            &quark_volatile,
                                            mbim_protocol_error_entries,
                                            G_N_ELEMENTS (mbim_protocol_error_entries));

    return (GQuark) quark_volatile;
}


#define ERROR_PREFIX MBIM_STATUS_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_status_error_entries[] = {
    { MBIM_STATUS_ERROR_NONE, ERROR_PREFIX ".none" },
    { MBIM_STATUS_ERROR_BUSY, ERROR_PREFIX ".busy" },
    { MBIM_STATUS_ERROR_FAILURE, ERROR_PREFIX ".failure" },
    { MBIM_STATUS_ERROR_SIM_NOT_INSERTED, ERROR_PREFIX ".sim-not-inserted" },
    { MBIM_STATUS_ERROR_BAD_SIM, ERROR_PREFIX ".bad-sim" },
    { MBIM_STATUS_ERROR_PIN_REQUIRED, ERROR_PREFIX ".pin-required" },
    { MBIM_STATUS_ERROR_PIN_DISABLED, ERROR_PREFIX ".pin-disabled" },
    { MBIM_STATUS_ERROR_NOT_REGISTERED, ERROR_PREFIX ".not-registered" },
    { MBIM_STATUS_ERROR_PROVIDERS_NOT_FOUND, ERROR_PREFIX ".providers-not-found" },
    { MBIM_STATUS_ERROR_NO_DEVICE_SUPPORT, ERROR_PREFIX ".no-device-support" },
    { MBIM_STATUS_ERROR_PROVIDER_NOT_VISIBLE, ERROR_PREFIX ".provider-not-visible" },
    { MBIM_STATUS_ERROR_DATA_CLASS_NOT_AVAILABLE, ERROR_PREFIX ".data-class-not-available" },
    { MBIM_STATUS_ERROR_PACKET_SERVICE_DETACHED, ERROR_PREFIX ".packet-service-detached" },
    { MBIM_STATUS_ERROR_MAX_ACTIVATED_CONTEXTS, ERROR_PREFIX ".max-activated-contexts" },
    { MBIM_STATUS_ERROR_NOT_INITIALIZED, ERROR_PREFIX ".not-initialized" },
    { MBIM_STATUS_ERROR_VOICE_CALL_IN_PROGRESS, ERROR_PREFIX ".voice-call-in-progress" },
    { MBIM_STATUS_ERROR_CONTEXT_NOT_ACTIVATED, ERROR_PREFIX ".context-not-activated" },
    { MBIM_STATUS_ERROR_SERVICE_NOT_ACTIVATED, ERROR_PREFIX ".service-not-activated" },
    { MBIM_STATUS_ERROR_INVALID_ACCESS_STRING, ERROR_PREFIX ".invalid-access-string" },
    { MBIM_STATUS_ERROR_INVALID_USER_NAME_PWD, ERROR_PREFIX ".invalid-user-name-pwd" },
    { MBIM_STATUS_ERROR_RADIO_POWER_OFF, ERROR_PREFIX ".radio-power-off" },
    { MBIM_STATUS_ERROR_INVALID_PARAMETERS, ERROR_PREFIX ".invalid-parameters" },
    { MBIM_STATUS_ERROR_READ_FAILURE, ERROR_PREFIX ".read-failure" },
    { MBIM_STATUS_ERROR_WRITE_FAILURE, ERROR_PREFIX ".write-failure" },
    { MBIM_STATUS_ERROR_NO_PHONEBOOK, ERROR_PREFIX ".no-phonebook" },
    { MBIM_STATUS_ERROR_PARAMETER_TOO_LONG, ERROR_PREFIX ".parameter-too-long" },
    { MBIM_STATUS_ERROR_STK_BUSY, ERROR_PREFIX ".stk-busy" },
    { MBIM_STATUS_ERROR_OPERATION_NOT_ALLOWED, ERROR_PREFIX ".operation-not-allowed" },
    { MBIM_STATUS_ERROR_MEMORY_FAILURE, ERROR_PREFIX ".memory-failure" },
    { MBIM_STATUS_ERROR_INVALID_MEMORY_INDEX, ERROR_PREFIX ".invalid-memory-index" },
    { MBIM_STATUS_ERROR_MEMORY_FULL, ERROR_PREFIX ".memory-full" },
    { MBIM_STATUS_ERROR_FILTER_NOT_SUPPORTED, ERROR_PREFIX ".filter-not-supported" },
    { MBIM_STATUS_ERROR_DSS_INSTANCE_LIMIT, ERROR_PREFIX ".dss-instance-limit" },
    { MBIM_STATUS_ERROR_INVALID_DEVICE_SERVICE_OPERATION, ERROR_PREFIX ".invalid-device-service-operation" },
    { MBIM_STATUS_ERROR_AUTH_INCORRECT_AUTN, ERROR_PREFIX ".auth-incorrect-autn" },
    { MBIM_STATUS_ERROR_AUTH_SYNC_FAILURE, ERROR_PREFIX ".auth-sync-failure" },
    { MBIM_STATUS_ERROR_AUTH_AMF_NOT_SET, ERROR_PREFIX ".auth-amf-not-set" },
    { MBIM_STATUS_ERROR_SMS_UNKNOWN_SMSC_ADDRESS, ERROR_PREFIX ".sms-unknown-smsc-address" },
    { MBIM_STATUS_ERROR_SMS_NETWORK_TIMEOUT, ERROR_PREFIX ".sms-network-timeout" },
    { MBIM_STATUS_ERROR_SMS_LANG_NOT_SUPPORTED, ERROR_PREFIX ".sms-lang-not-supported" },
    { MBIM_STATUS_ERROR_SMS_ENCODING_NOT_SUPPORTED, ERROR_PREFIX ".sms-encoding-not-supported" },
    { MBIM_STATUS_ERROR_SMS_FORMAT_NOT_SUPPORTED, ERROR_PREFIX ".sms-format-not-supported" },
};
#undef ERROR_PREFIX

GQuark
mbim_status_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_status_error_quark",
                                            &quark_volatile,
                                            mbim_status_error_entries,
                                            G_N_ELEMENTS (mbim_status_error_entries));

    return (GQuark) quark_volatile;
}


/* Generated data ends here */

