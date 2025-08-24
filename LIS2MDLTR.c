#include "LIS2MDLTR.h"

LIS2MDLTR_t LIS2MDLTR;

void LIS2MDLTR_select_i2c_mode(void)                                  //DONE
{
	HAL_GPIO_WritePin(AXIS_9_COMMUNICATION_ENABLE_GPIO_Port,AXIS_9_COMMUNICATION_ENABLE_Pin,GPIO_PIN_SET);
}
//

void LIS2MDLTR_offset_x_register_low_w(uint8_t data)
{
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_X_REGISTER_LOW,data);
}	

void LIS2MDLTR_offset_x_register_high_w(uint8_t data)
{
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_X_REGISTER_HIGH,data);
}	

void LIS2MDLTR_offset_y_register_low_w(uint8_t data)
{
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_Y_REGISTER_LOW,data);
}	

void LIS2MDLTR_offset_y_register_high_w(uint8_t data)
{
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_Y_REGISTER_HIGH,data);
}	

void LIS2MDLTR_offset_z_register_low_w(uint8_t data)
{
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_Z_REGISTER_LOW,data);
}	

void LIS2MDLTR_offset_z_register_high_w(uint8_t data)
{	
	LIS2MDLTR_write_register(LIS2MDLTR_OFFSET_Z_REGISTER_HIGH,data);
}	
//

void LIS2MDLTR_who_am_i_register_r(void)                                	//done
{
	LIS2MDLTR_read_register(IDENTIFICATION_REGISTER_ADDRESS,&LIS2MDLTR.who_am_i);
}
//

void LIS2MDLTR_configuration_register_a_write(uint8_t data)              	//done
{
	LIS2MDLTR_write_register(CONFIGURATION_REGISTER_A_ADDRESS,data);
}

void LIS2MDLTR_configuration_register_b_write(uint8_t data)								//DONE
{
	LIS2MDLTR_write_register(CONFIGURATION_REGISTER_B_ADDRESS,data);
}

void LIS2MDLTR_configuration_register_c_write(uint8_t data)								//DONE
{
	LIS2MDLTR_write_register(CONFIGURATION_REGISTER_C_ADDRESS,data);
}
//

void LIS2MDLTR_interupt_control_register_r(void)	                       	//DONE
{
	LIS2MDLTR_read_register(INTERUPT_CONTROL_REGISTER_ADDRESS,&LIS2MDLTR.interupt_control);
}

void LIS2MDLTR_interupt_control_register_w(uint8_t data)           				//done
{
	LIS2MDLTR_write_register(INTERUPT_CONTROL_REGISTER_ADDRESS,data);
}
//

void LIS2MDLTR_interupt_source_register_r(void)													 	//done
{
	LIS2MDLTR_read_register(INTERUPT_SOURCE_REGISTER_ADDRESS,&LIS2MDLTR.interupt_source);
}
//

void LIS2MDLTR_interupt_threshold_low_register_r(void)                    //done
{
	LIS2MDLTR_read_register(INTERUPT_THRESHOLD_LOW_REGISTER_ADDRESS,&LIS2MDLTR.low_threshold);
}
void LIS2MDLTR_interupt_threshold_low_register_w(uint8_t data)						//done
{
	LIS2MDLTR_write_register(INTERUPT_THRESHOLD_LOW_REGISTER_ADDRESS,data);
}
void LIS2MDLTR_interupt_threshold_high_register_r(void)										//done
{
	LIS2MDLTR_read_register(INTERUPT_THRESHOLD_HIGH_REGISTER_ADDRESS,&LIS2MDLTR.high_threshold);
}
void LIS2MDLTR_interupt_threshold_high_register_w(uint8_t data)						//done
{
	LIS2MDLTR_write_register(INTERUPT_THRESHOLD_HIGH_REGISTER_ADDRESS,data);
}
//

void LIS2MDLTR_status_register_r(void)																		//DONE
{
	LIS2MDLTR_read_register(STATUS_REGISTER_ADDRESS,&LIS2MDLTR.status_register);
}

void LIS2MDLTR_output_x_low_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_X_LOW_REGISTER_ADDRESS,&LIS2MDLTR.output_x_low);
}

void LIS2MDLTR_output_x_high_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_X_HIGH_REGISTER_ADDRESS,&LIS2MDLTR.output_x_high);
}

void LIS2MDLTR_output_y_low_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_Y_LOW_REGISTER_ADDRESS,&LIS2MDLTR.output_y_low);
}

void LIS2MDLTR_output_y_high_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_Y_HIGH_REGISTER_ADDRESS,&LIS2MDLTR.output_y_high);
}

void LIS2MDLTR_output_z_low_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_Z_LOW_REGISTER_ADDRESS,&LIS2MDLTR.output_z_low);
}

void LIS2MDLTR_output_z_high_register(void)
{
	LIS2MDLTR_read_register(LIS2MDLTR_OUTPUT_Z_HIGH_REGISTER_ADDRESS,&LIS2MDLTR.output_z_high);
}
//

void LIS2MDLTR_output_x_full(void)
{
	LIS2MDLTR_output_x_low_register();
	LIS2MDLTR_output_x_high_register();
	LIS2MDLTR.output_x_full = ((uint16_t)LIS2MDLTR.output_x_high << 8) | LIS2MDLTR.output_x_low; 
}

void LIS2MDLTR_output_y_full(void)
{
	LIS2MDLTR_output_y_low_register();
	LIS2MDLTR_output_y_high_register();
	LIS2MDLTR.output_y_full = ((uint16_t)LIS2MDLTR.output_y_high << 8) | LIS2MDLTR.output_y_low;
}

void LIS2MDLTR_output_z_full(void)
{
	LIS2MDLTR_output_z_low_register();
	LIS2MDLTR_output_z_high_register();
	LIS2MDLTR.output_z_full = ((uint16_t)LIS2MDLTR.output_z_high << 8) | LIS2MDLTR.output_z_low;
}
//

void LIS2MDLTR_read_register(uint8_t address,uint8_t *data)
{
		HAL_I2C_Master_Transmit(&hi2c3,LIS2MDLTR_I2C_SLAVE_ADDRESS_WITH_WRITE,&address,1,HAL_MAX_DELAY);
	
		HAL_I2C_Master_Receive(&hi2c3,(LIS2MDLTR_I2C_SLAVE_ADDRESS_WITH_READ),data,1,HAL_MAX_DELAY);
}
//

void LIS2MDLTR_write_register(uint8_t address,uint8_t data)
{
	uint8_t txdata[2] = {address,data};
	
	HAL_I2C_Master_Transmit(&hi2c3,LIS2MDLTR_I2C_SLAVE_ADDRESS_WITH_WRITE,txdata,2,HAL_MAX_DELAY);
}
//

void LIS2MDLTR_init(void) 																//done   
{
	LIS2MDLTR_configuration_register_a_write(0X94);     	//configuration_register_a
	
	LIS2MDLTR_configuration_register_b_write(0X00);       //configuration_register_b
	
	LIS2MDLTR_configuration_register_c_write(0X51);       //configuration_regsiter_c
}
//

void LIS2MDLTR_read_all_configuration(void)              //done
{
	LIS2MDLTR_read_register(CONFIGURATION_REGISTER_A_ADDRESS,&LIS2MDLTR.config_a);
	LIS2MDLTR_read_register(CONFIGURATION_REGISTER_B_ADDRESS,&LIS2MDLTR.config_b);
	LIS2MDLTR_read_register(CONFIGURATION_REGISTER_C_ADDRESS,&LIS2MDLTR.config_c);
}
//

void LIS2MDLTR_interupt_configuration(void)               //DONE
{
	LIS2MDLTR_interupt_control_register_w(0XE7);          //enables the inetrupt control register

	LIS2MDLTR_interupt_threshold_low_register_w(0X00);        //sets the threshold for the x,y,z negative axis
	
	LIS2MDLTR_interupt_threshold_high_register_w(0X00);				//sets the threshold for the x,y,z positive axis
}
//

void LIS2MDLTR_read_all_threshold_value(void)							//done
{
	LIS2MDLTR_interupt_threshold_low_register_r();
	LIS2MDLTR_interupt_threshold_high_register_r();
}
//

void LIS2MDLTR_read_all_axis(void)
{
	LIS2MDLTR_output_x_full();
	LIS2MDLTR_output_y_full();
	LIS2MDLTR_output_z_full();
}
//
	
