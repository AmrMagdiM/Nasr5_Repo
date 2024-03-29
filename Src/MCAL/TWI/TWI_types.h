/*
 * TWI_types.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_TWI_TWI_TYPES_H_
#define SRC_MCAL_TWI_TWI_TYPES_H_


typedef enum
{
	BusError=0,

	Master_Start_Condition = 0x08,
	Master_RepeatedStart_Condition = 0x10,

	MasterTx_SlaveAddrWritebitTx_AckRx = 0x18,
	MasterTx_SlaveAddrWritebitTx_NotAckRx =0x20,
	MasterTx_DataTx_AckRx=0x28,
	MasterTx_DataTx_NotAckRx=0x30,

	Master_ArbitrationLost=0x38,

	MasterRx_SlaveAddrReadbitTx_AckRx = 0x40,
	MasterRx_SlaveAddrReadbitTx_NotAckRx =0x48,
	MasterRx_DataRx_AckTx=0x50,
	MasterRx_DataRx_NotAckTx=0x58,

	SlaveRx_SlaveAddrReadbitRx_AckTx = 0x60,
	SlaveRx_ArbitrationLost_SlaveAddrWritebitRx_AckTx = 0x68,
	SlaveRx_BroadcastAddrRx_AckTx = 0x70,
	SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx = 0x78,

	SlaveRx_PrevSlaveAddrWritebitRx_AckTx = 0x80,
	SlaveRx_PrevArbitrationLost_SlaveAddrWritebitRxx_AckTx = 0x88,
	SlaveRx_PrevBroadcastAddrRx_AckTx = 0x90,
	SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx = 0x98,

	SlaveRx_StopCondition_Or_RepeatedStartCondition = 0xA0,

	SlaveTx_SlaveAddrReadbitRx_AckTx = 0xA8,
	SlaveTx_ArbitrationLost_SlaveAddrReadbitRx_AckTx = 0xB0,

	SlaveTx_DataTx_AckRx = 0xB8,
	SlaveTx_DataTx_NotAckRx = 0xC0,
	SlaveTx_LastDataTx_AckRx = 0xC8,

	NoRelevantState = 0xF8

}TWI_Status_T;


#endif /* SRC_MCAL_TWI_TWI_TYPES_H_ */
