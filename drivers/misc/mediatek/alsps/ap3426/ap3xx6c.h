/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 *
 * Filename: ap3xx6.h
 *
 * Summary:
 *	AP3xx6 sensor dirver header file.
 *
 * Modification History:
 * Date	By		Summary
 * -------- -------- -------------------------------------------------------
 * 05/11/12 YC		Original Creation (Test version:1.0)
 */

/*
 * Definitions for AP3xx6 als/ps sensor chip.
 */
#ifndef __AP3xx6_H__
#define __AP3xx6_H__

#include <linux/ioctl.h>

#define AP3xx6_ENABLE						0X00
#define AP3xx6_INT_STATUS					0x01
#define AP3xx6_ADATA_L						0X0C
#define AP3xx6_ADATA_H						0X0D
#define AP3xx6_PDATA_L						0X0E
#define AP3xx6_PDATA_H						0X0F
#define AP3xx6_INT_LOW_THD_LOW				0X2A
#define AP3xx6_INT_LOW_THD_HIGH				0X2B
#define AP3xx6_INT_HIGH_THD_LOW				0X2C
#define AP3xx6_INT_HIGH_THD_HIGH			0X2D
#define AP3xx6_IR_DATA_LOW                  0x0A
#define AP3xx6_IR_DATA_HIGH                 0x0B



#define AP3xx6_SUCCESS						0
#define AP3xx6_ERR_I2C						-1
#define AP3xx6_ERR_STATUS					-3
#define AP3xx6_ERR_SETUP_FAILURE			-4
#define AP3xx6_ERR_GETGSENSORDATA			-5
#define AP3xx6_ERR_IDENTIFICATION			-6

//wt add for ps calibration start
#define CUST_AP_PS_THRES_FAR         70
#define CUST_AP_PS_THRES_CLOSE     290
//wt add for ps calibration end

/******************************************************************************
 * extern functions
*******************************************************************************/
extern void mt_eint_mask(unsigned int eint_num);
extern void mt_eint_unmask(unsigned int eint_num);
extern void mt_eint_set_hw_debounce(unsigned int eint_num, unsigned int ms);
extern void mt_eint_set_polarity(unsigned int eint_num, unsigned int pol);
extern unsigned int mt_eint_set_sens(unsigned int eint_num, unsigned int sens);
extern void mt_eint_registration(unsigned int eint_num, unsigned int flow,
							void (EINT_FUNC_PTR)(void), unsigned int is_auto_umask);

#endif
