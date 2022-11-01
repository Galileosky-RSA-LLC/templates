***General script connection scheme***

**The number of analog ports should be set on the slave side**

**On the master side:**
the following values should be specified:
	MAX_OUT - the maximum value of the output index on the master
	MAX_OUT_SLAVE - the maximum value of the output index on the slave
	MAX_IN - the maximum value of the input index on the master
	MAX_IN_SLAVE - the maximum value of the input index on the slave

- The RS485 handler is requested every 100-200 ms on the master

- The master script checks the values of global variables (boolean flags) of commands:
	- get_input_status - get an input status (comment: a faster way was implemented)
	- get_input - get an input voltage value
	- get_output_status - get an input status (comment: a faster way was implemented)
	- set_output_on - притянуть выход к земле (comment: a faster way was implemented)
	- set_output_off - убрать подтяжку выхода к земле (comment: a faster way was implemented)

- If the flag has "true" value, the command is executed as applied to the port index specified in the port_index global variable

To execute these commands, first write the port_index global variable and only then set the flag of the command you want to execute.

- Reading the necessary states (flags) of the slave outputs in the em_Outs_Cmd global variable. The bit index corresponds to the slave output index.

- Reading actual states (flags) of slave outputs in em_outStat0 to em_outStat3 global variables obtained during previous run of RS485 handler.

- If the states do not match, a command is sent to the slave.

Controlling impulse relay:
- Reading the value in the out_pulse and delay_pulse global variables. out_pulse defaults to -1. A value greater than MAX_OUT belongs to the slave: SLAVE_INDEX_VALUE = out_pulse - (MAX_OUT + 1)
- When valid according to out_pulse, a pulse is executed on the master or a command is sent to the slave.
