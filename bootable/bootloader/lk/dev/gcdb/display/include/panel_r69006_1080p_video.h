/* Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*---------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = "1.0"
 *---------------------------------------------------------------------------*/

#ifndef _PANEL_R69006_1080P_VIDEO_H_
#define _PANEL_R69006_1080P_VIDEO_H_
/*---------------------------------------------------------------------------*/
/* HEADER files                                                              */
/*---------------------------------------------------------------------------*/
#include "panel.h"

/*---------------------------------------------------------------------------*/
/* Panel configuration                                                       */
/*---------------------------------------------------------------------------*/
static struct panel_config r69006_1080p_video_panel_data = {
	"qcom,mdss_dsi_r69006_1080p_video", "dsi:0:", "qcom,mdss-dsi-panel",
	10, 0, "DISPLAY_1", 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL
};

/*---------------------------------------------------------------------------*/
/* Panel resolution                                                          */
/*---------------------------------------------------------------------------*/
static struct panel_resolution r69006_1080p_video_panel_res = {
	1080, 1920, 100, 82, 20, 0, 3, 9, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel color information                                                   */
/*---------------------------------------------------------------------------*/
static struct color_info r69006_1080p_video_color = {
	24, 0, 0xff, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Panel on/off command information                                          */
/*---------------------------------------------------------------------------*/
static char r69006_1080p_video_on_cmd0[] = {
	0XB0, 0x00, 0x23, 0x80
};

static char r69006_1080p_video_on_cmd1[] = {
	0x06, 0x00, 0x29, 0xC0,
	0XB3, 0x05, 0x10, 0x00,
	0x00, 0x00, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd2[] = {
	0x03, 0x00, 0x29, 0xC0,
	0XB4, 0x0c, 0x00, 0xFF,
};

static char r69006_1080p_video_on_cmd3[] = {
	0x04, 0x00, 0x29, 0xC0,
	0XB6, 0x3b, 0xc3, 0x00,
};

static char r69006_1080p_video_on_cmd4[] = {
	0XC0, 0x00, 0x23, 0x80
};

static char r69006_1080p_video_on_cmd5[] = {
	0X36, 0x98, 0x15, 0x80
};

static char r69006_1080p_video_on_cmd6[] = {
	0XCC, 0x04, 0x23, 0x80
};

static char r69006_1080p_video_on_cmd7[] = {
	0x20, 0x00, 0x29, 0xC0,
	0xC1, 0x84, 0x00, 0x10,
	0xEF, 0x8B, 0xF1, 0xFF,
	0xFF, 0xDF, 0x9C, 0xC5,
	0x9A, 0x73, 0x8D, 0xAD,
	0x63, 0xFE, 0xFF, 0xFF,
	0xCB, 0xF8, 0x01, 0x00,
	0xAA, 0x40, 0x00, 0xC2,
	0x01, 0x08, 0x00, 0x01,
};

static char r69006_1080p_video_on_cmd8[] = {
	0x0A, 0x00, 0x29, 0xC0,
	0xCB, 0x0D, 0xFE, 0x1F,
	0x2C, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd9[] = {
	0x0B, 0x00, 0x29, 0xC0,
	0xC2, 0x01, 0xF7, 0x80,
	0x04, 0x63, 0x00, 0x60,
	0x00, 0x01, 0x30, 0xFF,
};

static char r69006_1080p_video_on_cmd10[] = {
	0x07, 0x00, 0x29, 0xC0,
	0XC3, 0x55, 0x01, 0x00,
	0x01, 0x00, 0x00, 0xFF,
};

static char r69006_1080p_video_on_cmd11[] = {
	0x12, 0x00, 0x29, 0xC0,
	0XC4, 0x70, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x01,
	0x00, 0x05, 0x01, 0x00,
	0x00, 0x00, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd12[] = {
	0x0F, 0x00, 0x29, 0xC0,
	0xC6, 0x59, 0x07, 0x4a,
	0x07, 0x4a, 0x01, 0x0E,
	0x01, 0x02, 0x01, 0x02,
	0x09, 0x15, 0x07, 0xFF,
};

static char r69006_1080p_video_on_cmd13[] = {
	0x1F, 0x00, 0x29, 0xC0,
	0XC7, 0x00, 0x30, 0x32,
	0x34, 0x42, 0x4E, 0x56,
	0x62, 0x44, 0x4A, 0x54,
	0x62, 0x6B, 0x73, 0x7F,
	0x08, 0x30, 0x32, 0x34,
	0x42, 0x4E, 0x56, 0x62,
	0x44, 0x4A, 0x54, 0x62,
	0x6B, 0x73, 0x7F, 0xFF,
};

static char r69006_1080p_video_on_cmd14[] = {
	0x14, 0x00, 0x29, 0xC0,
	0xC8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0xFC, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xFC, 0x00,
};

static char r69006_1080p_video_on_cmd15[] = {
	0x09, 0x00, 0x29, 0xC0,
	0xC9, 0x1F, 0x68, 0x1F,
	0x68, 0x4C, 0x4C, 0xC4,
	0x11, 0xFF, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd16[] = {
	0x11, 0x00, 0x29, 0xC0,
	0xD0, 0x33, 0x01, 0x91,
	0x0B, 0xD9, 0x19, 0x19,
	0x00, 0x00, 0x00, 0x19,
	0x99, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd17[] = {
	0x1D, 0x00, 0x29, 0xC0,
	0xD3, 0x1B, 0x3B, 0xBB,
	0xAD, 0xA5, 0x33, 0x33,
	0x33, 0x00, 0x80, 0xAD,
	0xA8, 0x6f, 0x6f, 0x33,
	0x33, 0x33, 0xF7, 0xF2,
	0x1F, 0x7D, 0x7C, 0xFF,
	0x0F, 0x99, 0x00, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF,
};

static char r69006_1080p_video_on_cmd18[] = {
	0x04, 0x00, 0x29, 0xC0,
	0xD4, 0x57, 0x33, 0x03,
};

static char r69006_1080p_video_on_cmd19[] = {
	0x0C, 0x00, 0x29, 0xC0,
	0XD5, 0x66, 0x00, 0x00,
	0x01, 0x27, 0x01, 0x27,
	0x00, 0x6D, 0x00, 0x6D,
};

static char r69006_1080p_video_on_cmd20[] = {
	0xD6, 0x81, 0x23, 0x80
};

static char r69006_1080p_video_on_cmd21[] = {
	0x11, 0x00, 0x05, 0x80
};

static char r69006_1080p_video_on_cmd22[] = {
	0x29, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd r69006_1080p_video_on_command[] = {
	{0x4, r69006_1080p_video_on_cmd0, 0x00},
	{0xc, r69006_1080p_video_on_cmd1, 0x00},
	{0x8, r69006_1080p_video_on_cmd2, 0x00},
	{0x8, r69006_1080p_video_on_cmd3, 0x00},
	{0x4, r69006_1080p_video_on_cmd4, 0x00},
	{0x4, r69006_1080p_video_on_cmd5, 0x00},
	{0x4, r69006_1080p_video_on_cmd6, 0x00},
	{0x24, r69006_1080p_video_on_cmd7, 0x00},
	{0x10, r69006_1080p_video_on_cmd8, 0x00},
	{0x10, r69006_1080p_video_on_cmd9, 0x00},
	{0xc, r69006_1080p_video_on_cmd10, 0x00},
	{0x18, r69006_1080p_video_on_cmd11, 0x00},
	{0x14, r69006_1080p_video_on_cmd12, 0x00},
	{0x24, r69006_1080p_video_on_cmd13, 0x00},
	{0x18, r69006_1080p_video_on_cmd14, 0x00},
	{0x10, r69006_1080p_video_on_cmd15, 0x00},
	{0x18, r69006_1080p_video_on_cmd16, 0x00},
	{0x24, r69006_1080p_video_on_cmd17, 0x00},
	{0x8, r69006_1080p_video_on_cmd18, 0x00},
	{0x10, r69006_1080p_video_on_cmd19, 0x00},
	{0x4, r69006_1080p_video_on_cmd20, 0x00},
	{0x4, r69006_1080p_video_on_cmd21, 0x78},
	{0x4, r69006_1080p_video_on_cmd22, 0x78}
};

#define R69006_1080P_VIDEO_ON_COMMAND 23


static char r69006_1080p_videooff_cmd0[] = {
	0x28, 0x00, 0x05, 0x80
};

static char r69006_1080p_videooff_cmd1[] = {
	0x10, 0x00, 0x05, 0x80
};

static struct mipi_dsi_cmd r69006_1080p_video_off_command[] = {
	{0x4, r69006_1080p_videooff_cmd0, 0x78},
	{0x4, r69006_1080p_videooff_cmd1, 0x96}
};

#define R69006_1080P_VIDEO_OFF_COMMAND 2


static struct command_state r69006_1080p_video_state = {
	0, 1
};

/*---------------------------------------------------------------------------*/
/* Command mode panel information                                            */
/*---------------------------------------------------------------------------*/
static struct commandpanel_info r69006_1080p_video_command_panel = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*---------------------------------------------------------------------------*/
/* Video mode panel information                                              */
/*---------------------------------------------------------------------------*/
static struct videopanel_info r69006_1080p_video_video_panel = {
	1, 0, 0, 0, 1, 1, 2, 0, 0x9
};

/*---------------------------------------------------------------------------*/
/* Lane configuration                                                        */
/*---------------------------------------------------------------------------*/
static struct lane_configuration r69006_1080p_video_lane_config = {
	4, 0, 1, 1, 1, 1, 0
};

/*---------------------------------------------------------------------------*/
/* Panel timing                                                              */
/*---------------------------------------------------------------------------*/
static const uint32_t r69006_1080p_video_timings[] = {
	0x7d, 0x25, 0x1d, 0x00, 0x37, 0x33, 0x22, 0x27, 0x1e, 0x03, 0x04, 0x00
};

static const uint32_t r69006_1080p_14nm_video_timings[] = {
	0x24, 0x1f, 0x08, 0x09, 0x05, 0x03, 0x04, 0xa0,
	0x24, 0x1f, 0x08, 0x09, 0x05, 0x03, 0x04, 0xa0,
	0x24, 0x1f, 0x08, 0x09, 0x05, 0x03, 0x04, 0xa0,
	0x24, 0x1f, 0x08, 0x09, 0x05, 0x03, 0x04, 0xa0,
	0x24, 0x1b, 0x08, 0x09, 0x05, 0x03, 0x04, 0xa0,
};

static struct panel_timing r69006_1080p_video_timing_info = {
	0, 4, 0x20, 0x2c
};

static struct labibb_desc r69006_1080p_video_labibb = {
	0, 1, 5700000, 5700000, 5700000, 5700000, 3, 3, 1, 0
};

/*---------------------------------------------------------------------------*/
/* Panel reset sequence                                                      */
/*---------------------------------------------------------------------------*/
static struct panel_reset_sequence r69006_1080p_video_reset_seq = {
	{1, 0, 1, }, {20, 2, 20, }, 2
};

/*---------------------------------------------------------------------------*/
/* Backlight setting                                                         */
/*---------------------------------------------------------------------------*/
static struct backlight r69006_1080p_video_backlight = {
	1, 1, 4095, 100, 1, "PMIC_8941"
};

#define R69006_1080P_VIDEO_SIGNATURE 0xFFFF

#endif /*_PANEL_R69006_1080P_VIDEO_H_*/
