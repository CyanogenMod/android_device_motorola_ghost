/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MSM_VENC_H_
#define _MSM_VENC_H_
#include <linux/types.h>
#define VENC_MAX_RECON_BUFFERS 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_FLAG_EOS 0x00000001
#define VENC_FLAG_END_OF_FRAME 0x00000010
#define VENC_FLAG_SYNC_FRAME 0x00000020
#define VENC_FLAG_EXTRA_DATA 0x00000040
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_FLAG_CODEC_CONFIG 0x00000080
enum venc_flush_type {
 VENC_FLUSH_INPUT,
 VENC_FLUSH_OUTPUT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_FLUSH_ALL
};
enum venc_state_type {
 VENC_STATE_PAUSE = 0x1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_STATE_START = 0x2,
 VENC_STATE_STOP = 0x4
};
enum venc_event_type_enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_EVENT_START_STATUS,
 VENC_EVENT_STOP_STATUS,
 VENC_EVENT_SUSPEND_STATUS,
 VENC_EVENT_RESUME_STATUS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_EVENT_FLUSH_STATUS,
 VENC_EVENT_RELEASE_INPUT,
 VENC_EVENT_DELIVER_OUTPUT,
 VENC_EVENT_UNKNOWN_STATUS
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum venc_status_code {
 VENC_STATUS_SUCCESS,
 VENC_STATUS_ERROR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_STATUS_INVALID_STATE,
 VENC_STATUS_FLUSHING,
 VENC_STATUS_INVALID_PARAM,
 VENC_STATUS_CMD_QUEUE_FULL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_STATUS_CRITICAL,
 VENC_STATUS_INSUFFICIENT_RESOURCES,
 VENC_STATUS_TIMEOUT
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum venc_msg_code {
 VENC_MSG_INDICATION,
 VENC_MSG_INPUT_BUFFER_DONE,
 VENC_MSG_OUTPUT_BUFFER_DONE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_MSG_NEED_OUTPUT_BUFFER,
 VENC_MSG_FLUSH,
 VENC_MSG_START,
 VENC_MSG_STOP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_MSG_PAUSE,
 VENC_MSG_RESUME,
 VENC_MSG_STOP_READING_MSG
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum venc_error_code {
 VENC_S_SUCCESS,
 VENC_S_EFAIL,
 VENC_S_EFATAL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_S_EBADPARAM,
 VENC_S_EINVALSTATE,
 VENC_S_ENOSWRES,
 VENC_S_ENOHWRES,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_S_EBUFFREQ,
 VENC_S_EINVALCMD,
 VENC_S_ETIMEOUT,
 VENC_S_ENOREATMPT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_S_ENOPREREQ,
 VENC_S_ECMDQFULL,
 VENC_S_ENOTSUPP,
 VENC_S_ENOTIMPL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_S_ENOTPMEM,
 VENC_S_EFLUSHED,
 VENC_S_EINSUFBUF,
 VENC_S_ESAMESTATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_S_EINVALTRANS
};
enum venc_mem_region_enum {
 VENC_PMEM_EBI1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VENC_PMEM_SMI
};
struct venc_buf_type {
 u32 region;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 phys;
 u32 size;
 int offset;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_qp_range {
 u32 min_qp;
 u32 max_qp;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_frame_rate {
 u32 frame_rate_num;
 u32 frame_rate_den;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_slice_info {
 u32 slice_mode;
 u32 units_per_slice;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_extra_data {
 u32 slice_extra_data_flag;
 u32 slice_client_data1;
 u32 slice_client_data2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 slice_client_data3;
 u32 none_extra_data_flag;
 u32 none_client_data1;
 u32 none_client_data2;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 none_client_data3;
};
struct venc_common_config {
 u32 standard;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 input_frame_height;
 u32 input_frame_width;
 u32 output_frame_height;
 u32 output_frame_width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 rotation_angle;
 u32 intra_period;
 u32 rate_control;
 struct venc_frame_rate frame_rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 bitrate;
 struct venc_qp_range qp_range;
 u32 iframe_qp;
 u32 pframe_qp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_slice_info slice_config;
 struct venc_extra_data extra_data;
};
struct venc_nonio_buf_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_buf_type recon_buf1;
 struct venc_buf_type recon_buf2;
 struct venc_buf_type wb_buf;
 struct venc_buf_type cmd_buf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_buf_type vlc_buf;
};
struct venc_mpeg4_config {
 u32 profile;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 level;
 u32 time_resolution;
 u32 ac_prediction;
 u32 hec_interval;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 data_partition;
 u32 short_header;
 u32 rvlc_enable;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_h263_config {
 u32 profile;
 u32 level;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_h264_config {
 u32 profile;
 u32 level;
 u32 max_nal;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 idr_period;
};
struct venc_pmem {
 int src;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int fd;
 u32 offset;
 void *virt;
 void *phys;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 size;
};
struct venc_buffer {
 unsigned char *ptr_buffer;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 size;
 u32 len;
 u32 offset;
 long long time_stamp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 flags;
 u32 client_data;
};
struct venc_buffers {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_pmem recon_buf[VENC_MAX_RECON_BUFFERS];
 struct venc_pmem wb_buf;
 struct venc_pmem cmd_buf;
 struct venc_pmem vlc_buf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_buffer_flush {
 u32 flush_mode;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
union venc_msg_data {
 struct venc_buffer buf;
 struct venc_buffer_flush flush_ret;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct venc_msg {
 u32 status_code;
 u32 msg_code;
 u32 msg_data_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 union venc_msg_data msg_data;
};
union venc_codec_config {
 struct venc_mpeg4_config mpeg4_params;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_h263_config h263_params;
 struct venc_h264_config h264_params;
};
struct venc_q6_config {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_common_config config_params;
 union venc_codec_config codec_params;
 struct venc_nonio_buf_config buf_params;
 void *callback_event;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_hdr_config {
 struct venc_common_config config_params;
 union venc_codec_config codec_params;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_init_config {
 struct venc_q6_config q6_config;
 struct venc_buffers q6_bufs;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct venc_seq_config {
 int size;
 struct venc_pmem buf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct venc_q6_config q6_config;
};
struct venc_version {
 u32 major;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u32 minor;
};
#define VENC_IOCTL_MAGIC 'V'
#define VENC_IOCTL_CMD_READ_NEXT_MSG   _IOWR(VENC_IOCTL_MAGIC, 1, struct venc_msg)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_IOCTL_CMD_STOP_READ_MSG _IO(VENC_IOCTL_MAGIC, 2)
#define VENC_IOCTL_SET_INPUT_BUFFER   _IOW(VENC_IOCTL_MAGIC, 3, struct venc_pmem)
#define VENC_IOCTL_SET_OUTPUT_BUFFER   _IOW(VENC_IOCTL_MAGIC, 4, struct venc_pmem)
#define VENC_IOCTL_CMD_START _IOW(VENC_IOCTL_MAGIC, 5, struct venc_init_config)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_IOCTL_CMD_ENCODE_FRAME   _IOW(VENC_IOCTL_MAGIC, 6, struct venc_buffer)
#define VENC_IOCTL_CMD_FILL_OUTPUT_BUFFER   _IOW(VENC_IOCTL_MAGIC, 7, struct venc_buffer)
#define VENC_IOCTL_CMD_FLUSH   _IOW(VENC_IOCTL_MAGIC, 8, struct venc_buffer_flush)
#define VENC_IOCTL_CMD_PAUSE _IO(VENC_IOCTL_MAGIC, 9)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_IOCTL_CMD_RESUME _IO(VENC_IOCTL_MAGIC, 10)
#define VENC_IOCTL_CMD_STOP _IO(VENC_IOCTL_MAGIC, 11)
#define VENC_IOCTL_SET_INTRA_PERIOD   _IOW(VENC_IOCTL_MAGIC, 12, int)
#define VENC_IOCTL_CMD_REQUEST_IFRAME _IO(VENC_IOCTL_MAGIC, 13)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_IOCTL_GET_SEQUENCE_HDR   _IOWR(VENC_IOCTL_MAGIC, 14, struct venc_seq_config)
#define VENC_IOCTL_SET_INTRA_REFRESH   _IOW(VENC_IOCTL_MAGIC, 15, int)
#define VENC_IOCTL_SET_FRAME_RATE   _IOW(VENC_IOCTL_MAGIC, 16, struct venc_frame_rate)
#define VENC_IOCTL_SET_TARGET_BITRATE   _IOW(VENC_IOCTL_MAGIC, 17, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define VENC_IOCTL_SET_QP_RANGE   _IOW(VENC_IOCTL_MAGIC, 18, struct venc_qp_range)
#define VENC_IOCTL_GET_VERSION   _IOR(VENC_IOCTL_MAGIC, 19, struct venc_version)
#endif
