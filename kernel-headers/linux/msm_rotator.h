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
#ifndef __MSM_ROTATOR_H__
#define __MSM_ROTATOR_H__
#include <linux/types.h>
#include <linux/msm_mdp.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSM_ROTATOR_IOCTL_MAGIC 'R'
#define MSM_ROTATOR_IOCTL_START   _IOWR(MSM_ROTATOR_IOCTL_MAGIC, 1, struct msm_rotator_img_info)
#define MSM_ROTATOR_IOCTL_ROTATE   _IOW(MSM_ROTATOR_IOCTL_MAGIC, 2, struct msm_rotator_data_info)
#define MSM_ROTATOR_IOCTL_FINISH   _IOW(MSM_ROTATOR_IOCTL_MAGIC, 3, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSM_ROTATOR_IOCTL_BUFFER_SYNC   _IOW(MSM_ROTATOR_IOCTL_MAGIC, 4, struct msm_rotator_buf_sync)
#define ROTATOR_VERSION_01 0xA5B4C301
enum rotator_clk_type {
 ROTATOR_CORE_CLK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ROTATOR_PCLK,
 ROTATOR_IMEM_CLK
};
struct msm_rotator_buf_sync {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t session_id;
 uint32_t flags;
 int acq_fen_fd;
 int rel_fen_fd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct rot_buf_type {
 struct ion_handle *ihdl;
 uint32_t write_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint32_t read_addr;
};
struct msm_rotator_img_info {
 unsigned int session_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct msmfb_img src;
 struct msmfb_img dst;
 struct mdp_rect src_rect;
 unsigned int dst_x;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int dst_y;
 unsigned char rotations;
 int enable;
 unsigned int downscale_ratio;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int secure;
};
struct msm_rotator_data_info {
 int session_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct msmfb_data src;
 struct msmfb_data dst;
 unsigned int version_key;
 struct msmfb_data src_chroma;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct msmfb_data dst_chroma;
 uint32_t wait_for_finish;
};
struct msm_rot_clocks {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 const char *clk_name;
 enum rotator_clk_type clk_type;
 unsigned int clk_rate;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct msm_rotator_platform_data {
 unsigned int number_of_clocks;
 unsigned int hardware_version_number;
 struct msm_rot_clocks *rotator_clks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 char rot_iommu_split_domain;
};
#endif
