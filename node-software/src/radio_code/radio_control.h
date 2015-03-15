/**
 * Protocol control for RFM69W radio module - header file
 * This code should provide high-level control of the module without making any
 * processor-specific calls so should be fairly portable
 */

#ifndef RADIO_CONTROL_H_
#define RADIO_CONTROL_H_

#include <stdbool.h>
#include <stdint.h>

//#define DEBUG_RADIO 1

#define RADIO_MAX_PACKET_LEN  60
#define RADIO_RECEIVE_BUFSIZE 1024

#define RADIO_BCAST_ADDR      0x00

bool radio_init(uint8_t addr);

// Internal functions for sending and receiving data - exposed for convienience
bool radio_send_data(char* data_p, uint16_t length, uint8_t dest_addr);
uint16_t radio_retrieve_data(char* data_p, uint16_t length);
void radio_activate_receiver(bool activate);
void radio_powerstate(bool state);

// Functions for low-level interrupt routines to make callbacks
void _radio_payload_ready(void);


#endif /* RADIO_CONTROL_H_ */
