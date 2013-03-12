
/* Generated data (by glib-mkenums) */

#include "mbim-enum-types.h"

/* enumerations from "../../libmbim-glib/mbim-uuid.h" */
static const GEnumValue mbim_service_values[] = {
    { MBIM_SERVICE_INVALID, "MBIM_SERVICE_INVALID", "invalid" },
    { MBIM_SERVICE_BASIC_CONNECT, "MBIM_SERVICE_BASIC_CONNECT", "basic-connect" },
    { MBIM_SERVICE_SMS, "MBIM_SERVICE_SMS", "sms" },
    { MBIM_SERVICE_USSD, "MBIM_SERVICE_USSD", "ussd" },
    { MBIM_SERVICE_PHONEBOOK, "MBIM_SERVICE_PHONEBOOK", "phonebook" },
    { MBIM_SERVICE_STK, "MBIM_SERVICE_STK", "stk" },
    { MBIM_SERVICE_AUTH, "MBIM_SERVICE_AUTH", "auth" },
    { MBIM_SERVICE_DSS, "MBIM_SERVICE_DSS", "dss" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_service_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimService"),
                                      mbim_service_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_SERVICE_IS_ENUM__
/**
 * mbim_service_get_string:
 * @val: a MbimService.
 *
 * Gets the nickname string for the #MbimService specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_service_get_string (MbimService val)
{
    guint i;

    for (i = 0; mbim_service_values[i].value_nick; i++) {
        if (val == mbim_service_values[i].value)
            return mbim_service_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_SERVICE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_SERVICE_IS_FLAGS__
/**
 * mbim_service_build_string_from_mask:
 * @mask: bitmask of MbimService values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimService in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_service_build_string_from_mask (MbimService mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_service_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_service_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_service_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_service_values[i].value) {
            guint c;
            gulong number = mbim_service_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_service_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_SERVICE_IS_FLAGS__ */

/* enumerations from "../../libmbim-glib/mbim-cid.h" */
static const GEnumValue mbim_cid_basic_connect_values[] = {
    { MBIM_CID_BASIC_CONNECT_UNKNOWN, "MBIM_CID_BASIC_CONNECT_UNKNOWN", "unknown" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_CAPS, "MBIM_CID_BASIC_CONNECT_DEVICE_CAPS", "device-caps" },
    { MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS, "MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS", "subscriber-ready-status" },
    { MBIM_CID_BASIC_CONNECT_RADIO_STATE, "MBIM_CID_BASIC_CONNECT_RADIO_STATE", "radio-state" },
    { MBIM_CID_BASIC_CONNECT_PIN, "MBIM_CID_BASIC_CONNECT_PIN", "pin" },
    { MBIM_CID_BASIC_CONNECT_PIN_LIST, "MBIM_CID_BASIC_CONNECT_PIN_LIST", "pin-list" },
    { MBIM_CID_BASIC_CONNECT_HOME_PROVIDER, "MBIM_CID_BASIC_CONNECT_HOME_PROVIDER", "home-provider" },
    { MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS, "MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS", "preferred-providers" },
    { MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS, "MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS", "visible-providers" },
    { MBIM_CID_BASIC_CONNECT_REGISTER_STATE, "MBIM_CID_BASIC_CONNECT_REGISTER_STATE", "register-state" },
    { MBIM_CID_BASIC_CONNECT_PACKET_SERVICE, "MBIM_CID_BASIC_CONNECT_PACKET_SERVICE", "packet-service" },
    { MBIM_CID_BASIC_CONNECT_SIGNAL_STATE, "MBIM_CID_BASIC_CONNECT_SIGNAL_STATE", "signal-state" },
    { MBIM_CID_BASIC_CONNECT_CONNECT, "MBIM_CID_BASIC_CONNECT_CONNECT", "connect" },
    { MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS, "MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS", "provisioned-contexts" },
    { MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION, "MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION", "service-activation" },
    { MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION, "MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION", "ip-configuration" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES, "MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES", "device-services" },
    { MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBER_LIST, "MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBER_LIST", "device-service-subscriber-list" },
    { MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS, "MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS", "packet-statistics" },
    { MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT, "MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT", "network-idle-hint" },
    { MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE, "MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE", "emergency-mode" },
    { MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS, "MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS", "ip-packet-filters" },
    { MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS, "MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS", "multicarrier-providers" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_basic_connect_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidBasicConnect"),
                                      mbim_cid_basic_connect_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_BASIC_CONNECT_IS_ENUM__
/**
 * mbim_cid_basic_connect_get_string:
 * @val: a MbimCidBasicConnect.
 *
 * Gets the nickname string for the #MbimCidBasicConnect specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_basic_connect_get_string (MbimCidBasicConnect val)
{
    guint i;

    for (i = 0; mbim_cid_basic_connect_values[i].value_nick; i++) {
        if (val == mbim_cid_basic_connect_values[i].value)
            return mbim_cid_basic_connect_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_BASIC_CONNECT_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_BASIC_CONNECT_IS_FLAGS__
/**
 * mbim_cid_basic_connect_build_string_from_mask:
 * @mask: bitmask of MbimCidBasicConnect values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidBasicConnect in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_basic_connect_build_string_from_mask (MbimCidBasicConnect mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_basic_connect_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_basic_connect_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_basic_connect_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_basic_connect_values[i].value) {
            guint c;
            gulong number = mbim_cid_basic_connect_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_basic_connect_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_BASIC_CONNECT_IS_FLAGS__ */

static const GEnumValue mbim_cid_sms_values[] = {
    { MBIM_CID_SMS_UNKNOWN, "MBIM_CID_SMS_UNKNOWN", "unknown" },
    { MBIM_CID_SMS_CONFIGURATION, "MBIM_CID_SMS_CONFIGURATION", "configuration" },
    { MBIM_CID_SMS_READ, "MBIM_CID_SMS_READ", "read" },
    { MBIM_CID_SMS_SEND, "MBIM_CID_SMS_SEND", "send" },
    { MBIM_CID_SMS_DELETE, "MBIM_CID_SMS_DELETE", "delete" },
    { MBIM_CID_SMS_MESSAGE_STORE_STATUS, "MBIM_CID_SMS_MESSAGE_STORE_STATUS", "message-store-status" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_sms_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidSms"),
                                      mbim_cid_sms_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_SMS_IS_ENUM__
/**
 * mbim_cid_sms_get_string:
 * @val: a MbimCidSms.
 *
 * Gets the nickname string for the #MbimCidSms specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_sms_get_string (MbimCidSms val)
{
    guint i;

    for (i = 0; mbim_cid_sms_values[i].value_nick; i++) {
        if (val == mbim_cid_sms_values[i].value)
            return mbim_cid_sms_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_SMS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_SMS_IS_FLAGS__
/**
 * mbim_cid_sms_build_string_from_mask:
 * @mask: bitmask of MbimCidSms values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidSms in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_sms_build_string_from_mask (MbimCidSms mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_sms_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_sms_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_sms_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_sms_values[i].value) {
            guint c;
            gulong number = mbim_cid_sms_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_sms_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_SMS_IS_FLAGS__ */

static const GEnumValue mbim_cid_ussd_values[] = {
    { MBIM_CID_UNKNOWN, "MBIM_CID_UNKNOWN", "unknown" },
    { MBIM_CID_USSD, "MBIM_CID_USSD", "ussd" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_ussd_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidUssd"),
                                      mbim_cid_ussd_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_USSD_IS_ENUM__
/**
 * mbim_cid_ussd_get_string:
 * @val: a MbimCidUssd.
 *
 * Gets the nickname string for the #MbimCidUssd specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_ussd_get_string (MbimCidUssd val)
{
    guint i;

    for (i = 0; mbim_cid_ussd_values[i].value_nick; i++) {
        if (val == mbim_cid_ussd_values[i].value)
            return mbim_cid_ussd_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_USSD_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_USSD_IS_FLAGS__
/**
 * mbim_cid_ussd_build_string_from_mask:
 * @mask: bitmask of MbimCidUssd values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidUssd in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_ussd_build_string_from_mask (MbimCidUssd mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_ussd_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_ussd_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_ussd_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_ussd_values[i].value) {
            guint c;
            gulong number = mbim_cid_ussd_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_ussd_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_USSD_IS_FLAGS__ */

static const GEnumValue mbim_cid_phonebook_values[] = {
    { MBIM_CID_PHONEBOOK_UNKNOWN, "MBIM_CID_PHONEBOOK_UNKNOWN", "unknown" },
    { MBIM_CID_PHONEBOOK_CONFIGURATION, "MBIM_CID_PHONEBOOK_CONFIGURATION", "configuration" },
    { MBIM_CID_PHONEBOOK_READ, "MBIM_CID_PHONEBOOK_READ", "read" },
    { MBIM_CID_PHONEBOOK_DELETE, "MBIM_CID_PHONEBOOK_DELETE", "delete" },
    { MBIM_CID_PHONEBOOK_WRITE, "MBIM_CID_PHONEBOOK_WRITE", "write" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_phonebook_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidPhonebook"),
                                      mbim_cid_phonebook_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_PHONEBOOK_IS_ENUM__
/**
 * mbim_cid_phonebook_get_string:
 * @val: a MbimCidPhonebook.
 *
 * Gets the nickname string for the #MbimCidPhonebook specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_phonebook_get_string (MbimCidPhonebook val)
{
    guint i;

    for (i = 0; mbim_cid_phonebook_values[i].value_nick; i++) {
        if (val == mbim_cid_phonebook_values[i].value)
            return mbim_cid_phonebook_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_PHONEBOOK_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_PHONEBOOK_IS_FLAGS__
/**
 * mbim_cid_phonebook_build_string_from_mask:
 * @mask: bitmask of MbimCidPhonebook values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidPhonebook in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_phonebook_build_string_from_mask (MbimCidPhonebook mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_phonebook_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_phonebook_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_phonebook_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_phonebook_values[i].value) {
            guint c;
            gulong number = mbim_cid_phonebook_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_phonebook_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_PHONEBOOK_IS_FLAGS__ */

static const GEnumValue mbim_cid_stk_values[] = {
    { MBIM_CID_STK_UNKNOWN, "MBIM_CID_STK_UNKNOWN", "unknown" },
    { MBIM_CID_STK_PAC, "MBIM_CID_STK_PAC", "pac" },
    { MBIM_CID_STK_TERMINAL_RESPONSE, "MBIM_CID_STK_TERMINAL_RESPONSE", "terminal-response" },
    { MBIM_CID_STK_ENVELOPE, "MBIM_CID_STK_ENVELOPE", "envelope" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_stk_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidStk"),
                                      mbim_cid_stk_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_STK_IS_ENUM__
/**
 * mbim_cid_stk_get_string:
 * @val: a MbimCidStk.
 *
 * Gets the nickname string for the #MbimCidStk specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_stk_get_string (MbimCidStk val)
{
    guint i;

    for (i = 0; mbim_cid_stk_values[i].value_nick; i++) {
        if (val == mbim_cid_stk_values[i].value)
            return mbim_cid_stk_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_STK_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_STK_IS_FLAGS__
/**
 * mbim_cid_stk_build_string_from_mask:
 * @mask: bitmask of MbimCidStk values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidStk in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_stk_build_string_from_mask (MbimCidStk mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_stk_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_stk_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_stk_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_stk_values[i].value) {
            guint c;
            gulong number = mbim_cid_stk_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_stk_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_STK_IS_FLAGS__ */

static const GEnumValue mbim_cid_auth_values[] = {
    { MBIM_CID_AUTH_UNKNOWN, "MBIM_CID_AUTH_UNKNOWN", "unknown" },
    { MBIM_CID_AUTH_AKA, "MBIM_CID_AUTH_AKA", "aka" },
    { MBIM_CID_AUTH_AKAP, "MBIM_CID_AUTH_AKAP", "akap" },
    { MBIM_CID_AUTH_SIM, "MBIM_CID_AUTH_SIM", "sim" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_auth_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidAuth"),
                                      mbim_cid_auth_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_AUTH_IS_ENUM__
/**
 * mbim_cid_auth_get_string:
 * @val: a MbimCidAuth.
 *
 * Gets the nickname string for the #MbimCidAuth specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_auth_get_string (MbimCidAuth val)
{
    guint i;

    for (i = 0; mbim_cid_auth_values[i].value_nick; i++) {
        if (val == mbim_cid_auth_values[i].value)
            return mbim_cid_auth_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_AUTH_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_AUTH_IS_FLAGS__
/**
 * mbim_cid_auth_build_string_from_mask:
 * @mask: bitmask of MbimCidAuth values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidAuth in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_auth_build_string_from_mask (MbimCidAuth mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_auth_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_auth_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_auth_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_auth_values[i].value) {
            guint c;
            gulong number = mbim_cid_auth_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_auth_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_AUTH_IS_FLAGS__ */

static const GEnumValue mbim_cid_dss_values[] = {
    { MBIM_CID_DSS_UNKNOWN, "MBIM_CID_DSS_UNKNOWN", "unknown" },
    { MBIM_CID_DSS_CONNECT, "MBIM_CID_DSS_CONNECT", "connect" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cid_dss_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimCidDss"),
                                      mbim_cid_dss_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CID_DSS_IS_ENUM__
/**
 * mbim_cid_dss_get_string:
 * @val: a MbimCidDss.
 *
 * Gets the nickname string for the #MbimCidDss specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cid_dss_get_string (MbimCidDss val)
{
    guint i;

    for (i = 0; mbim_cid_dss_values[i].value_nick; i++) {
        if (val == mbim_cid_dss_values[i].value)
            return mbim_cid_dss_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CID_DSS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CID_DSS_IS_FLAGS__
/**
 * mbim_cid_dss_build_string_from_mask:
 * @mask: bitmask of MbimCidDss values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCidDss in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cid_dss_build_string_from_mask (MbimCidDss mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cid_dss_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cid_dss_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cid_dss_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cid_dss_values[i].value) {
            guint c;
            gulong number = mbim_cid_dss_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cid_dss_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CID_DSS_IS_FLAGS__ */

/* enumerations from "../../libmbim-glib/mbim-message.h" */
static const GEnumValue mbim_message_type_values[] = {
    { MBIM_MESSAGE_TYPE_INVALID, "MBIM_MESSAGE_TYPE_INVALID", "invalid" },
    { MBIM_MESSAGE_TYPE_OPEN, "MBIM_MESSAGE_TYPE_OPEN", "open" },
    { MBIM_MESSAGE_TYPE_CLOSE, "MBIM_MESSAGE_TYPE_CLOSE", "close" },
    { MBIM_MESSAGE_TYPE_COMMAND, "MBIM_MESSAGE_TYPE_COMMAND", "command" },
    { MBIM_MESSAGE_TYPE_HOST_ERROR, "MBIM_MESSAGE_TYPE_HOST_ERROR", "host-error" },
    { MBIM_MESSAGE_TYPE_OPEN_DONE, "MBIM_MESSAGE_TYPE_OPEN_DONE", "open-done" },
    { MBIM_MESSAGE_TYPE_CLOSE_DONE, "MBIM_MESSAGE_TYPE_CLOSE_DONE", "close-done" },
    { MBIM_MESSAGE_TYPE_COMMAND_DONE, "MBIM_MESSAGE_TYPE_COMMAND_DONE", "command-done" },
    { MBIM_MESSAGE_TYPE_FUNCTION_ERROR, "MBIM_MESSAGE_TYPE_FUNCTION_ERROR", "function-error" },
    { MBIM_MESSAGE_TYPE_INDICATION, "MBIM_MESSAGE_TYPE_INDICATION", "indication" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_message_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimMessageType"),
                                      mbim_message_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_MESSAGE_TYPE_IS_ENUM__
/**
 * mbim_message_type_get_string:
 * @val: a MbimMessageType.
 *
 * Gets the nickname string for the #MbimMessageType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_message_type_get_string (MbimMessageType val)
{
    guint i;

    for (i = 0; mbim_message_type_values[i].value_nick; i++) {
        if (val == mbim_message_type_values[i].value)
            return mbim_message_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_MESSAGE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_MESSAGE_TYPE_IS_FLAGS__
/**
 * mbim_message_type_build_string_from_mask:
 * @mask: bitmask of MbimMessageType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimMessageType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_message_type_build_string_from_mask (MbimMessageType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_message_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_message_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_message_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_message_type_values[i].value) {
            guint c;
            gulong number = mbim_message_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_message_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_MESSAGE_TYPE_IS_FLAGS__ */

static const GEnumValue mbim_message_command_type_values[] = {
    { MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN, "MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN", "unknown" },
    { MBIM_MESSAGE_COMMAND_TYPE_QUERY, "MBIM_MESSAGE_COMMAND_TYPE_QUERY", "query" },
    { MBIM_MESSAGE_COMMAND_TYPE_SET, "MBIM_MESSAGE_COMMAND_TYPE_SET", "set" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_message_command_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimMessageCommandType"),
                                      mbim_message_command_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_MESSAGE_COMMAND_TYPE_IS_ENUM__
/**
 * mbim_message_command_type_get_string:
 * @val: a MbimMessageCommandType.
 *
 * Gets the nickname string for the #MbimMessageCommandType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_message_command_type_get_string (MbimMessageCommandType val)
{
    guint i;

    for (i = 0; mbim_message_command_type_values[i].value_nick; i++) {
        if (val == mbim_message_command_type_values[i].value)
            return mbim_message_command_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_MESSAGE_COMMAND_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_MESSAGE_COMMAND_TYPE_IS_FLAGS__
/**
 * mbim_message_command_type_build_string_from_mask:
 * @mask: bitmask of MbimMessageCommandType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimMessageCommandType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_message_command_type_build_string_from_mask (MbimMessageCommandType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_message_command_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_message_command_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_message_command_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_message_command_type_values[i].value) {
            guint c;
            gulong number = mbim_message_command_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_message_command_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_MESSAGE_COMMAND_TYPE_IS_FLAGS__ */

/* enumerations from "../../libmbim-glib/mbim-enums.h" */
static const GEnumValue mbim_device_type_values[] = {
    { MBIM_DEVICE_TYPE_UNKNOWN, "MBIM_DEVICE_TYPE_UNKNOWN", "unknown" },
    { MBIM_DEVICE_TYPE_EMBEDDED, "MBIM_DEVICE_TYPE_EMBEDDED", "embedded" },
    { MBIM_DEVICE_TYPE_REMOVABLE, "MBIM_DEVICE_TYPE_REMOVABLE", "removable" },
    { MBIM_DEVICE_TYPE_REMOTE, "MBIM_DEVICE_TYPE_REMOTE", "remote" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_device_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimDeviceType"),
                                      mbim_device_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_DEVICE_TYPE_IS_ENUM__
/**
 * mbim_device_type_get_string:
 * @val: a MbimDeviceType.
 *
 * Gets the nickname string for the #MbimDeviceType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_device_type_get_string (MbimDeviceType val)
{
    guint i;

    for (i = 0; mbim_device_type_values[i].value_nick; i++) {
        if (val == mbim_device_type_values[i].value)
            return mbim_device_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_DEVICE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_DEVICE_TYPE_IS_FLAGS__
/**
 * mbim_device_type_build_string_from_mask:
 * @mask: bitmask of MbimDeviceType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimDeviceType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_device_type_build_string_from_mask (MbimDeviceType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_device_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_device_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_device_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_device_type_values[i].value) {
            guint c;
            gulong number = mbim_device_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_device_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_DEVICE_TYPE_IS_FLAGS__ */

static const GFlagsValue mbim_cellular_class_values[] = {
    { MBIM_CELLULAR_CLASS_GSM, "MBIM_CELLULAR_CLASS_GSM", "gsm" },
    { MBIM_CELLULAR_CLASS_CDMA, "MBIM_CELLULAR_CLASS_CDMA", "cdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_cellular_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimCellularClass"),
                                      mbim_cellular_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
/**
 * mbim_cellular_class_get_string:
 * @val: a MbimCellularClass.
 *
 * Gets the nickname string for the #MbimCellularClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_cellular_class_get_string (MbimCellularClass val)
{
    guint i;

    for (i = 0; mbim_cellular_class_values[i].value_nick; i++) {
        if (val == mbim_cellular_class_values[i].value)
            return mbim_cellular_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CELLULAR_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
/**
 * mbim_cellular_class_build_string_from_mask:
 * @mask: bitmask of MbimCellularClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCellularClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_cellular_class_build_string_from_mask (MbimCellularClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_cellular_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_cellular_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_cellular_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_cellular_class_values[i].value) {
            guint c;
            gulong number = mbim_cellular_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_cellular_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CELLULAR_CLASS_IS_FLAGS__ */

static const GEnumValue mbim_voice_class_values[] = {
    { MBIM_VOICE_CLASS_UNKNOWN, "MBIM_VOICE_CLASS_UNKNOWN", "unknown" },
    { MBIM_VOICE_CLASS_NO_VOICE, "MBIM_VOICE_CLASS_NO_VOICE", "no-voice" },
    { MBIM_VOICE_CLASS_SEPARATED_VOICE_DATA, "MBIM_VOICE_CLASS_SEPARATED_VOICE_DATA", "separated-voice-data" },
    { MBIM_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA, "MBIM_VOICE_CLASS_SIMULTANEOUS_VOICE_DATA", "simultaneous-voice-data" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_voice_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimVoiceClass"),
                                      mbim_voice_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_VOICE_CLASS_IS_ENUM__
/**
 * mbim_voice_class_get_string:
 * @val: a MbimVoiceClass.
 *
 * Gets the nickname string for the #MbimVoiceClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_voice_class_get_string (MbimVoiceClass val)
{
    guint i;

    for (i = 0; mbim_voice_class_values[i].value_nick; i++) {
        if (val == mbim_voice_class_values[i].value)
            return mbim_voice_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_VOICE_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_VOICE_CLASS_IS_FLAGS__
/**
 * mbim_voice_class_build_string_from_mask:
 * @mask: bitmask of MbimVoiceClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimVoiceClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_voice_class_build_string_from_mask (MbimVoiceClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_voice_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_voice_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_voice_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_voice_class_values[i].value) {
            guint c;
            gulong number = mbim_voice_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_voice_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_VOICE_CLASS_IS_FLAGS__ */

static const GFlagsValue mbim_sim_class_values[] = {
    { MBIM_SIM_CLASS_LOGICAL, "MBIM_SIM_CLASS_LOGICAL", "logical" },
    { MBIM_SIM_CLASS_REMOVABLE, "MBIM_SIM_CLASS_REMOVABLE", "removable" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_sim_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimSimClass"),
                                      mbim_sim_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_SIM_CLASS_IS_ENUM__
/**
 * mbim_sim_class_get_string:
 * @val: a MbimSimClass.
 *
 * Gets the nickname string for the #MbimSimClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_sim_class_get_string (MbimSimClass val)
{
    guint i;

    for (i = 0; mbim_sim_class_values[i].value_nick; i++) {
        if (val == mbim_sim_class_values[i].value)
            return mbim_sim_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_SIM_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_SIM_CLASS_IS_FLAGS__
/**
 * mbim_sim_class_build_string_from_mask:
 * @mask: bitmask of MbimSimClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimSimClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_sim_class_build_string_from_mask (MbimSimClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_sim_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_sim_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_sim_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_sim_class_values[i].value) {
            guint c;
            gulong number = mbim_sim_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_sim_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_SIM_CLASS_IS_FLAGS__ */

static const GFlagsValue mbim_data_class_values[] = {
    { MBIM_DATA_CLASS_GPRS, "MBIM_DATA_CLASS_GPRS", "gprs" },
    { MBIM_DATA_CLASS_EDGE, "MBIM_DATA_CLASS_EDGE", "edge" },
    { MBIM_DATA_CLASS_UMTS, "MBIM_DATA_CLASS_UMTS", "umts" },
    { MBIM_DATA_CLASS_HSDPA, "MBIM_DATA_CLASS_HSDPA", "hsdpa" },
    { MBIM_DATA_CLASS_HSUPA, "MBIM_DATA_CLASS_HSUPA", "hsupa" },
    { MBIM_DATA_CLASS_LTE, "MBIM_DATA_CLASS_LTE", "lte" },
    { MBIM_DATA_CLASS_1XRTT, "MBIM_DATA_CLASS_1XRTT", "1xrtt" },
    { MBIM_DATA_CLASS_1XEVDO, "MBIM_DATA_CLASS_1XEVDO", "1xevdo" },
    { MBIM_DATA_CLASS_1XEVDO_REVA, "MBIM_DATA_CLASS_1XEVDO_REVA", "1xevdo-reva" },
    { MBIM_DATA_CLASS_1XEVDV, "MBIM_DATA_CLASS_1XEVDV", "1xevdv" },
    { MBIM_DATA_CLASS_3XRTT, "MBIM_DATA_CLASS_3XRTT", "3xrtt" },
    { MBIM_DATA_CLASS_1XEVDO_REVB, "MBIM_DATA_CLASS_1XEVDO_REVB", "1xevdo-revb" },
    { MBIM_DATA_CLASS_UMB, "MBIM_DATA_CLASS_UMB", "umb" },
    { MBIM_DATA_CLASS_CUSTOM, "MBIM_DATA_CLASS_CUSTOM", "custom" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_data_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimDataClass"),
                                      mbim_data_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_DATA_CLASS_IS_ENUM__
/**
 * mbim_data_class_get_string:
 * @val: a MbimDataClass.
 *
 * Gets the nickname string for the #MbimDataClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_data_class_get_string (MbimDataClass val)
{
    guint i;

    for (i = 0; mbim_data_class_values[i].value_nick; i++) {
        if (val == mbim_data_class_values[i].value)
            return mbim_data_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_DATA_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_DATA_CLASS_IS_FLAGS__
/**
 * mbim_data_class_build_string_from_mask:
 * @mask: bitmask of MbimDataClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimDataClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_data_class_build_string_from_mask (MbimDataClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_data_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_data_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_data_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_data_class_values[i].value) {
            guint c;
            gulong number = mbim_data_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_data_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_DATA_CLASS_IS_FLAGS__ */

static const GFlagsValue mbim_sms_caps_values[] = {
    { MBIM_SMS_CAPS_PDU_RECEIVE, "MBIM_SMS_CAPS_PDU_RECEIVE", "pdu-receive" },
    { MBIM_SMS_CAPS_PDU_SEND, "MBIM_SMS_CAPS_PDU_SEND", "pdu-send" },
    { MBIM_SMS_CAPS_TEXT_RECEIVE, "MBIM_SMS_CAPS_TEXT_RECEIVE", "text-receive" },
    { MBIM_SMS_CAPS_TEXT_SEND, "MBIM_SMS_CAPS_TEXT_SEND", "text-send" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_sms_caps_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimSmsCaps"),
                                      mbim_sms_caps_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_SMS_CAPS_IS_ENUM__
/**
 * mbim_sms_caps_get_string:
 * @val: a MbimSmsCaps.
 *
 * Gets the nickname string for the #MbimSmsCaps specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_sms_caps_get_string (MbimSmsCaps val)
{
    guint i;

    for (i = 0; mbim_sms_caps_values[i].value_nick; i++) {
        if (val == mbim_sms_caps_values[i].value)
            return mbim_sms_caps_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_SMS_CAPS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_SMS_CAPS_IS_FLAGS__
/**
 * mbim_sms_caps_build_string_from_mask:
 * @mask: bitmask of MbimSmsCaps values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimSmsCaps in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_sms_caps_build_string_from_mask (MbimSmsCaps mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_sms_caps_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_sms_caps_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_sms_caps_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_sms_caps_values[i].value) {
            guint c;
            gulong number = mbim_sms_caps_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_sms_caps_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_SMS_CAPS_IS_FLAGS__ */

static const GFlagsValue mbim_ctrl_caps_values[] = {
    { MBIM_CTRL_CAPS_REG_MANUAL, "MBIM_CTRL_CAPS_REG_MANUAL", "reg-manual" },
    { MBIM_CTRL_CAPS_HW_RADIO_SWITCH, "MBIM_CTRL_CAPS_HW_RADIO_SWITCH", "hw-radio-switch" },
    { MBIM_CTRL_CAPS_CDMA_MOBILE_IP, "MBIM_CTRL_CAPS_CDMA_MOBILE_IP", "cdma-mobile-ip" },
    { MBIM_CTRL_CAPS_CDMA_SIMPLE_IP, "MBIM_CTRL_CAPS_CDMA_SIMPLE_IP", "cdma-simple-ip" },
    { MBIM_CTRL_CAPS_MULTI_CARRIER, "MBIM_CTRL_CAPS_MULTI_CARRIER", "multi-carrier" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_ctrl_caps_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimCtrlCaps"),
                                      mbim_ctrl_caps_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_CTRL_CAPS_IS_ENUM__
/**
 * mbim_ctrl_caps_get_string:
 * @val: a MbimCtrlCaps.
 *
 * Gets the nickname string for the #MbimCtrlCaps specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_ctrl_caps_get_string (MbimCtrlCaps val)
{
    guint i;

    for (i = 0; mbim_ctrl_caps_values[i].value_nick; i++) {
        if (val == mbim_ctrl_caps_values[i].value)
            return mbim_ctrl_caps_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_CTRL_CAPS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_CTRL_CAPS_IS_FLAGS__
/**
 * mbim_ctrl_caps_build_string_from_mask:
 * @mask: bitmask of MbimCtrlCaps values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimCtrlCaps in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_ctrl_caps_build_string_from_mask (MbimCtrlCaps mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_ctrl_caps_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_ctrl_caps_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_ctrl_caps_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_ctrl_caps_values[i].value) {
            guint c;
            gulong number = mbim_ctrl_caps_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_ctrl_caps_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_CTRL_CAPS_IS_FLAGS__ */

static const GEnumValue mbim_subscriber_ready_state_values[] = {
    { MBIM_SUBSCRIBER_READY_STATE_NOT_INITIALIZED, "MBIM_SUBSCRIBER_READY_STATE_NOT_INITIALIZED", "not-initialized" },
    { MBIM_SUBSCRIBER_READY_STATE_INITIALIZED, "MBIM_SUBSCRIBER_READY_STATE_INITIALIZED", "initialized" },
    { MBIM_SUBSCRIBER_READY_STATE_SIM_NOT_INSERTED, "MBIM_SUBSCRIBER_READY_STATE_SIM_NOT_INSERTED", "sim-not-inserted" },
    { MBIM_SUBSCRIBER_READY_STATE_BAD_SIM, "MBIM_SUBSCRIBER_READY_STATE_BAD_SIM", "bad-sim" },
    { MBIM_SUBSCRIBER_READY_STATE_FAILURE, "MBIM_SUBSCRIBER_READY_STATE_FAILURE", "failure" },
    { MBIM_SUBSCRIBER_READY_STATE_NOT_ACTIVATED, "MBIM_SUBSCRIBER_READY_STATE_NOT_ACTIVATED", "not-activated" },
    { MBIM_SUBSCRIBER_READY_STATE_DEVICE_LOCKED, "MBIM_SUBSCRIBER_READY_STATE_DEVICE_LOCKED", "device-locked" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_subscriber_ready_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("MbimSubscriberReadyState"),
                                      mbim_subscriber_ready_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__
/**
 * mbim_subscriber_ready_state_get_string:
 * @val: a MbimSubscriberReadyState.
 *
 * Gets the nickname string for the #MbimSubscriberReadyState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_subscriber_ready_state_get_string (MbimSubscriberReadyState val)
{
    guint i;

    for (i = 0; mbim_subscriber_ready_state_values[i].value_nick; i++) {
        if (val == mbim_subscriber_ready_state_values[i].value)
            return mbim_subscriber_ready_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_FLAGS__
/**
 * mbim_subscriber_ready_state_build_string_from_mask:
 * @mask: bitmask of MbimSubscriberReadyState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimSubscriberReadyState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_subscriber_ready_state_build_string_from_mask (MbimSubscriberReadyState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_subscriber_ready_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_subscriber_ready_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_subscriber_ready_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_subscriber_ready_state_values[i].value) {
            guint c;
            gulong number = mbim_subscriber_ready_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_subscriber_ready_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_SUBSCRIBER_READY_STATE_IS_FLAGS__ */

static const GFlagsValue mbim_ready_info_flag_values[] = {
    { MBIM_READY_INFO_FLAG_PROTECT_UNIQUE_ID, "MBIM_READY_INFO_FLAG_PROTECT_UNIQUE_ID", "id" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
mbim_ready_info_flag_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("MbimReadyInfoFlag"),
                                      mbim_ready_info_flag_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __MBIM_READY_INFO_FLAG_IS_ENUM__
/**
 * mbim_ready_info_flag_get_string:
 * @val: a MbimReadyInfoFlag.
 *
 * Gets the nickname string for the #MbimReadyInfoFlag specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
mbim_ready_info_flag_get_string (MbimReadyInfoFlag val)
{
    guint i;

    for (i = 0; mbim_ready_info_flag_values[i].value_nick; i++) {
        if (val == mbim_ready_info_flag_values[i].value)
            return mbim_ready_info_flag_values[i].value_nick;
    }

    return NULL;
}
#endif /* __MBIM_READY_INFO_FLAG_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __MBIM_READY_INFO_FLAG_IS_FLAGS__
/**
 * mbim_ready_info_flag_build_string_from_mask:
 * @mask: bitmask of MbimReadyInfoFlag values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #MbimReadyInfoFlag in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
mbim_ready_info_flag_build_string_from_mask (MbimReadyInfoFlag mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; mbim_ready_info_flag_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == mbim_ready_info_flag_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (mbim_ready_info_flag_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & mbim_ready_info_flag_values[i].value) {
            guint c;
            gulong number = mbim_ready_info_flag_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        mbim_ready_info_flag_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __MBIM_READY_INFO_FLAG_IS_FLAGS__ */


/* Generated data ends here */

