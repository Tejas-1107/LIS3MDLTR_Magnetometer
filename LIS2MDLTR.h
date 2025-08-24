#ifndef __LIS2MDLTR_H
#define __LIS2MDLTR_H

#include "main.h"
#include "i2c.h"

#define LIS2MDLTR_I2C_SLAVE_ADDRESS_WITH_WRITE      (0X3C)    //3C
#define LIS2MDLTR_I2C_SLAVE_ADDRESS_WITH_READ       (0X3D)		//3D

#define LIS2MDLTR_OFFSET_X_REGISTER_LOW							(0X45)    //r w
#define LIS2MDLTR_OFFSET_X_REGISTER_HIGH						(0X46)		//r w		
#define LIS2MDLTR_OFFSET_Y_REGISTER_LOW							(0X47)		//r w
#define LIS2MDLTR_OFFSET_Y_REGISTER_HIGH						(0X48)		//r w
#define LIS2MDLTR_OFFSET_Z_REGISTER_LOW							(0X49)		//r w
#define LIS2MDLTR_OFFSET_Z_REGISTER_HIGH						(0X4A)		//r w

#define IDENTIFICATION_REGISTER_ADDRESS							(0X4F)    //Read for checking

#define CONFIGURATION_REGISTER_A_ADDRESS						(0X60)    //write
#define CONFIGURATION_REGISTER_B_ADDRESS						(0X61)		//write
#define CONFIGURATION_REGISTER_C_ADDRESS						(0X62)		//write

#define INTERUPT_CONTROL_REGISTER_ADDRESS						(0X63)    //write
#define INTERUPT_SOURCE_REGISTER_ADDRESS						(0X64)		//read

#define INTERUPT_THRESHOLD_LOW_REGISTER_ADDRESS     (0x65)		//read	
#define INTERUPT_THRESHOLD_HIGH_REGISTER_ADDRESS    (0x66)		//read

#define STATUS_REGISTER_ADDRESS											(0x67)		//read

#define LIS2MDLTR_OUTPUT_X_LOW_REGISTER_ADDRESS			(0X68)    //read only
#define LIS2MDLTR_OUTPUT_X_HIGH_REGISTER_ADDRESS		(0X69)    //read only
#define LIS2MDLTR_OUTPUT_Y_LOW_REGISTER_ADDRESS			(0X6A)    //read only
#define LIS2MDLTR_OUTPUT_Y_HIGH_REGISTER_ADDRESS		(0X6B)    //read only
#define LIS2MDLTR_OUTPUT_Z_LOW_REGISTER_ADDRESS			(0X6C)    //read only
#define LIS2MDLTR_OUTPUT_Z_HIGH_REGISTER_ADDRESS		(0X6D)    //read only

typedef struct
{
	uint8_t who_am_i;
	uint8_t config_a;
	uint8_t config_b;
	uint8_t config_c;
	uint8_t interupt_control;
	uint8_t interupt_source;
	uint8_t low_threshold;
	uint8_t high_threshold;
	uint8_t status_register;
	uint8_t output_x_low;
	uint8_t output_x_high;
	uint16_t output_x_full;
	uint8_t output_y_low;
	uint8_t output_y_high;
	uint16_t output_y_full;
	uint8_t output_z_low;
	uint8_t output_z_high;
	uint16_t output_z_full;
	uint8_t	value;
}LIS2MDLTR_t;

extern LIS2MDLTR_t LIS2MDLTR; 

void LIS2MDLTR_select_i2c_mode(void);                       				// control select pin for i2c or spi communication

void LIS2MDLTR_offset_x_register_low_w(uint8_t);
void LIS2MDLTR_offset_x_register_high_w(uint8_t);
void LIS2MDLTR_offset_y_register_low_w(uint8_t);
void LIS2MDLTR_offset_y_register_high_w(uint8_t);
void LIS2MDLTR_offset_z_register_low_w(uint8_t);
void LIS2MDLTR_offset_z_register_high_w(uint8_t);

void LIS2MDLTR_who_am_i_register_r(void);														// just for checking 

void LIS2MDLTR_configuration_register_a_write(uint8_t);     				//0x94
void LIS2MDLTR_configuration_register_a_read(void);									//read
void LIS2MDLTR_configuration_register_b_write(uint8_t);		  				//0x00
void LIS2MDLTR_configuration_register_b_read(void);									//read
void LIS2MDLTR_configuration_register_c_write(uint8_t);							//0x51
void LIS2MDLTR_configuration_register_C_read(void);									//read

void LIS2MDLTR_interupt_control_register_r(void);										//read
void LIS2MDLTR_interupt_control_register_w(uint8_t);								//0XE7

void LIS2MDLTR_interupt_source_register_r(void);              			//READ

void LIS2MDLTR_interupt_threshold_low_register_r(void);							//read
void LIS2MDLTR_interupt_threshold_low_register_w(uint8_t data);			//0x00
void LIS2MDLTR_interupt_threshold_high_register_r(void);						//read
void LIS2MDLTR_interupt_threshold_high_register_w(uint8_t data);		//0x00

void LIS2MDLTR_status_register_r(void);															//read

void LIS2MDLTR_output_x_low_register(void);                 				// read-only                  
void LIS2MDLTR_output_x_high_register(void);                				// read-only  
void LIS2MDLTR_output_y_low_register(void);                 				// read-only 
void LIS2MDLTR_output_y_high_register(void);                				// read-only 
void LIS2MDLTR_output_z_low_register(void);                 				// read-only 
void LIS2MDLTR_output_z_high_register(void);                				// read-only 

void LIS2MDLTR_output_x_full(void);																	// read x output value
void LIS2MDLTR_output_y_full(void);																	// read y output value
void LIS2MDLTR_output_z_full(void);																	// read z output value

void LIS2MDLTR_read_register(uint8_t address,uint8_t *data);   			// read register
void LIS2MDLTR_write_register(uint8_t address,uint8_t data);   			// write register

void LIS2MDLTR_init(void);
void LIS2MDLTR_read_all_configuration(void);
void LIS2MDLTR_interupt_configuration(void);
void LIS2MDLTR_read_all_threshold_value(void);
void LIS2MDLTR_read_all_axis(void);

#endif
