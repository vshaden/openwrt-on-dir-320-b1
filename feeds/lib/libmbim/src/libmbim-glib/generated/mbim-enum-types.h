
/* Generated data (by glib-mkenums) */

#ifndef __LIBMBIM_GLIB_ENUM_TYPES_H__
#define __LIBMBIM_GLIB_ENUM_TYPES_H__
#include "mbim-uuid.h"
#include "mbim-cid.h"
#include "mbim-message.h"
#include "mbim-enums.h"

#include <glib-object.h>

G_BEGIN_DECLS

/* enumerations from "../../libmbim-glib/mbim-uuid.h" */
GType mbim_service_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_SERVICE (mbim_service_get_type ())

/* Define type-specific symbols */
#define __MBIM_SERVICE_IS_ENUM__

#if defined __MBIM_SERVICE_IS_ENUM__
const gchar *mbim_service_get_string (MbimService val);
#endif

#if defined __MBIM_SERVICE_IS_FLAGS__
gchar *mbim_service_build_string_from_mask (MbimService mask);
#endif


/* enumerations from "../../libmbim-glib/mbim-cid.h" */
GType mbim_cid_basic_connect_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_BASIC_CONNECT (mbim_cid_basic_connect_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_BASIC_CONNECT_IS_ENUM__

#if defined __MBIM_CID_BASIC_CONNECT_IS_ENUM__
const gchar *mbim_cid_basic_connect_get_string (MbimCidBasicConnect val);
#endif

#if defined __MBIM_CID_BASIC_CONNECT_IS_FLAGS__
gchar *mbim_cid_basic_connect_build_string_from_mask (MbimCidBasicConnect mask);
#endif

GType mbim_cid_sms_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_SMS (mbim_cid_sms_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_SMS_IS_ENUM__

#if defined __MBIM_CID_SMS_IS_ENUM__
const gchar *mbim_cid_sms_get_string (MbimCidSms val);
#endif

#if defined __MBIM_CID_SMS_IS_FLAGS__
gchar *mbim_cid_sms_build_string_from_mask (MbimCidSms mask);
#endif

GType mbim_cid_ussd_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_USSD (mbim_cid_ussd_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_USSD_IS_ENUM__

#if defined __MBIM_CID_USSD_IS_ENUM__
const gchar *mbim_cid_ussd_get_string (MbimCidUssd val);
#endif

#if defined __MBIM_CID_USSD_IS_FLAGS__
gchar *mbim_cid_ussd_build_string_from_mask (MbimCidUssd mask);
#endif

GType mbim_cid_phonebook_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_PHONEBOOK (mbim_cid_phonebook_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_PHONEBOOK_IS_ENUM__

#if defined __MBIM_CID_PHONEBOOK_IS_ENUM__
const gchar *mbim_cid_phonebook_get_string (MbimCidPhonebook val);
#endif

#if defined __MBIM_CID_PHONEBOOK_IS_FLAGS__
gchar *mbim_cid_phonebook_build_string_from_mask (MbimCidPhonebook mask);
#endif

GType mbim_cid_stk_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_STK (mbim_cid_stk_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_STK_IS_ENUM__

#if defined __MBIM_CID_STK_IS_ENUM__
const gchar *mbim_cid_stk_get_string (MbimCidStk val);
#endif

#if defined __MBIM_CID_STK_IS_FLAGS__
gchar *mbim_cid_stk_build_string_from_mask (MbimCidStk mask);
#endif

GType mbim_cid_auth_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_AUTH (mbim_cid_auth_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_AUTH_IS_ENUM__

#if defined __MBIM_CID_AUTH_IS_ENUM__
const gchar *mbim_cid_auth_get_string (MbimCidAuth val);
#endif

#if defined __MBIM_CID_AUTH_IS_FLAGS__
gchar *mbim_cid_auth_build_string_from_mask (MbimCidAuth mask);
#endif

GType mbim_cid_dss_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CID_DSS (mbim_cid_dss_get_type ())

/* Define type-specific symbols */
#define __MBIM_CID_DSS_IS_ENUM__

#if defined __MBIM_CID_DSS_IS_ENUM__
const gchar *mbim_cid_dss_get_string (MbimCidDss val);
#endif

#if defined __MBIM_CID_DSS_IS_FLAGS__
gchar *mbim_cid_dss_build_string_from_mask (MbimCidDss mask);
#endif


/* enumerations from "../../libmbim-glib/mbim-message.h" */
GType mbim_message_type_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_MESSAGE_TYPE (mbim_message_type_get_type ())

/* Define type-specific symbols */
#define __MBIM_MESSAGE_TYPE_IS_ENUM__

#if defined __MBIM_MESSAGE_TYPE_IS_ENUM__
const gchar *mbim_message_type_get_string (MbimMessageType val);
#endif

#if defined __MBIM_MESSAGE_TYPE_IS_FLAGS__
gchar *mbim_message_type_build_string_from_mask (MbimMessageType mask);
#endif

GType mbim_message_command_type_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_MESSAGE_COMMAND_TYPE (mbim_message_command_type_get_type ())

/* Define type-specific symbols */
#define __MBIM_MESSAGE_COMMAND_TYPE_IS_ENUM__

#if defined __MBIM_MESSAGE_COMMAND_TYPE_IS_ENUM__
const gchar *mbim_message_command_type_get_string (MbimMessageCommandType val);
#endif

#if defined __MBIM_MESSAGE_COMMAND_TYPE_IS_FLAGS__
gchar *mbim_message_command_type_build_string_from_mask (MbimMessageCommandType mask);
#endif


/* enumerations from "../../libmbim-glib/mbim-enums.h" */
GType mbim_device_type_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_DEVICE_TYPE (mbim_device_type_get_type ())

/* Define type-specific symbols */
#define __MBIM_DEVICE_TYPE_IS_ENUM__

#if defined __MBIM_DEVICE_TYPE_IS_ENUM__
const gchar *mbim_device_type_get_string (MbimDeviceType val);
#endif

#if defined __MBIM_DEVICE_TYPE_IS_FLAGS__
gchar *mbim_device_type_build_string_from_mask (MbimDeviceType mask);
#endif

GType mbim_cellular_class_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CELLULAR_CLASS (mbim_cellular_class_get_type ())

/* Define type-specific symbols */
#define __MBIM_CELLULAR_CLASS_IS_FLAGS__

#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
const gchar *mbim_cellular_class_get_string (MbimCellularClass val);
#endif

#if defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
gchar *mbim_cellular_class_build_string_from_mask (MbimCellularClass mask);
#endif

GType mbim_voice_class_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_VOICE_CLASS (mbim_voice_class_get_type ())

/* Define type-specific symbols */
#define __MBIM_VOICE_CLASS_IS_ENUM__

#if defined __MBIM_VOICE_CLASS_IS_ENUM__
const gchar *mbim_voice_class_get_string (MbimVoiceClass val);
#endif

#if defined __MBIM_VOICE_CLASS_IS_FLAGS__
gchar *mbim_voice_class_build_string_from_mask (MbimVoiceClass mask);
#endif

GType mbim_sim_class_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_SIM_CLASS (mbim_sim_class_get_type ())

/* Define type-specific symbols */
#define __MBIM_SIM_CLASS_IS_FLAGS__

#if defined __MBIM_SIM_CLASS_IS_ENUM__
const gchar *mbim_sim_class_get_string (MbimSimClass val);
#endif

#if defined __MBIM_SIM_CLASS_IS_FLAGS__
gchar *mbim_sim_class_build_string_from_mask (MbimSimClass mask);
#endif

GType mbim_data_class_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_DATA_CLASS (mbim_data_class_get_type ())

/* Define type-specific symbols */
#define __MBIM_DATA_CLASS_IS_FLAGS__

#if defined __MBIM_DATA_CLASS_IS_ENUM__
const gchar *mbim_data_class_get_string (MbimDataClass val);
#endif

#if defined __MBIM_DATA_CLASS_IS_FLAGS__
gchar *mbim_data_class_build_string_from_mask (MbimDataClass mask);
#endif

GType mbim_sms_caps_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_SMS_CAPS (mbim_sms_caps_get_type ())

/* Define type-specific symbols */
#define __MBIM_SMS_CAPS_IS_FLAGS__

#if defined __MBIM_SMS_CAPS_IS_ENUM__
const gchar *mbim_sms_caps_get_string (MbimSmsCaps val);
#endif

#if defined __MBIM_SMS_CAPS_IS_FLAGS__
gchar *mbim_sms_caps_build_string_from_mask (MbimSmsCaps mask);
#endif

GType mbim_ctrl_caps_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_CTRL_CAPS (mbim_ctrl_caps_get_type ())

/* Define type-specific symbols */
#define __MBIM_CTRL_CAPS_IS_FLAGS__

#if defined __MBIM_CTRL_CAPS_IS_ENUM__
const gchar *mbim_ctrl_caps_get_string (MbimCtrlCaps val);
#endif

#if defined __MBIM_CTRL_CAPS_IS_FLAGS__
gchar *mbim_ctrl_caps_build_string_from_mask (MbimCtrlCaps mask);
#endif

GType mbim_subscriber_ready_state_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_SUBSCRIBER_READY_STATE (mbim_subscriber_ready_state_get_type ())

/* Define type-specific symbols */
#define __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__

#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_ENUM__
const gchar *mbim_subscriber_ready_state_get_string (MbimSubscriberReadyState val);
#endif

#if defined __MBIM_SUBSCRIBER_READY_STATE_IS_FLAGS__
gchar *mbim_subscriber_ready_state_build_string_from_mask (MbimSubscriberReadyState mask);
#endif

GType mbim_ready_info_flag_get_type (void) G_GNUC_CONST;
#define MBIM_TYPE_READY_INFO_FLAG (mbim_ready_info_flag_get_type ())

/* Define type-specific symbols */
#define __MBIM_READY_INFO_FLAG_IS_FLAGS__

#if defined __MBIM_READY_INFO_FLAG_IS_ENUM__
const gchar *mbim_ready_info_flag_get_string (MbimReadyInfoFlag val);
#endif

#if defined __MBIM_READY_INFO_FLAG_IS_FLAGS__
gchar *mbim_ready_info_flag_build_string_from_mask (MbimReadyInfoFlag mask);
#endif

G_END_DECLS

#endif /* __LIBMBIM_GLIB_ENUM_TYPES_H__ */

/* Generated data ends here */

