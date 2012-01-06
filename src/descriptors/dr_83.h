/*
Copyright (C) 2006  Adam Charrett

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

dr_83.h

Decode Logical Channel Number Descriptor.

*/

#ifndef _DR_83_H
#define _DR_83_H

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * dvbpsi_lcn_entry_t
 *****************************************************************************/
/*!
 * \struct dvbpsi_lcn_entry_s
 * \brief Logical Channel Number Entry
 *
 * This structure is used to store a decoded Logical Channel Number entry.
 */
/*!
 * \typedef struct dvbpsi_lcn_entry_s dvbpsi_lcn_entry_t
 * \brief dvbpsi_lcn_entry_t type definition.
 */
typedef struct dvbpsi_lcn_entry_s
{
    uint16_t i_service_id;             /*!< Service ID this logical channel number refers to */
    int      b_visible_service_flag;   /*!< Whether this LCN should be visible to the user. */
    uint16_t i_logical_channel_number; /*!<The logical channel number for this service. */
}dvbpsi_lcn_entry_t;

/*****************************************************************************
 * dvbpsi_lcn_dr_s
 *****************************************************************************/
/*!
 * \struct dvbpsi_lcn_dr_s
 * \brief Logical Channel Number Descriptor
 *
 * This structure is used to store a decoded Logical Channel Number descriptor.
 */
/*!
 * \typedef struct dvbpsi_lcn_dr_s dvbpsi_lcn_dr_t
 * \brief dvbpsi_lcn_dr_t type definition.
 */
typedef struct dvbpsi_lcn_dr_s
{
    uint8_t i_number_of_entries;     /*!< Number of LCN entries present. */
    dvbpsi_lcn_entry_t p_entries[64];/*!< Array of LCN entries. */
}dvbpsi_lcn_dr_t;

/*****************************************************************************
 * dvbpsi_DecodeLCNDr
 *****************************************************************************/
/*!
 * \fn dvbpsi_lcn_dr_t dvbpsi_DecodeLCNDr(dvbpsi_descriptor_t *p_descriptor)
 * \brief Decode a Logical Channel Number descriptor (tag 0x83)
 * \param p_descriptor Raw descriptor to decode.
 * \return NULL if the descriptor could not be decoded or a pointer to a
 *         dvbpsi_lcn_dr_t structure.
 */
dvbpsi_lcn_dr_t *dvbpsi_DecodeLCNDr(dvbpsi_descriptor_t *p_descriptor);

#ifdef __cplusplus
};
#endif

#endif

