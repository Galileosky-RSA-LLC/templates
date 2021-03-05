#define MAX_OUT 3
#define MAX_OUT_SLAVE 3

#define MAX_IN 5
#define MAX_IN_SLAVE 5


////////////////////////////////////////////////////
///////////////// DIAGNOSTICS //////////////////////
    diagnost0(text{})
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text)
        }
     }

    diagnost1(text{}, var)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var)
        }
     }

    diagnost2(text{}, var1, var2)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var1, var2)
        }
     }

    diagnostHex(array{}, array_size)
     {
        if (GetVar(diagnost))
        {
            DiagnosticsHex(array, array_size)
        }
     }
///////////////// DIAGNOSTICS END //////////////////
////////////////////////////////////////////////////

/////////////////////////////////////
//////////////// OUT ////////////////
    outputOn(output)
     {
        SetOutputValue(output, 0)
        diagnost1("Output %d ON", output)
     }

    outputOff(output)
     {
        SetOutputValue(output, 1)
        diagnost1("Output %d OFF", output)
     }

    getGlobalOutputStatus(output)
     {
     	if(output <= MAX_OUT)
     	{
     		switch ( output )
            {
                case 0: return GetVar(OUT_0)
                case 1: return GetVar(OUT_1)
                case 2: return GetVar(OUT_2)
                case 3: return GetVar(OUT_3)
            }
     	}

     	if( output <= (MAX_OUT + MAX_OUT_SLAVE + 1) )
     	{
     		switch ( output - (MAX_IN + 1) )
            {
                case 0: return GetVar(em_outStat0)
                case 1: return GetVar(em_outStat1)
                case 2: return GetVar(em_outStat2)
                case 3: return GetVar(em_outStat3)
            }
     	}

     	Diagnostics("ERROR argument: getGlobalOutputStatus(arg: %d)", output)
        return 0xFFFFFFFF
     }

    makeGlobalPulse(output, delayPulse)
     {
     	SetVar(delay_pulse, delayPulse)
     	SetVar(out_pulse, output)
     }
////////////// OUT END //////////////
/////////////////////////////////////

////////////////////////////////////
//////////////// IN ////////////////
    getInputStatus(inputNum)
     {
        new status

        switch (inputNum)
         {
            case 0:
                status = GetVar(STATUS_OF_IN0)
            case 1:
                status = GetVar(STATUS_OF_IN1)
            case 2:
                status = GetVar(STATUS_OF_IN2)
            case 3:
                status = GetVar(STATUS_OF_IN3)
            case 4:
                status = GetVar(STATUS_OF_IN4)
            case 5:
                status = GetVar(STATUS_OF_IN5)
            case 6:
                status = GetVar(STATUS_OF_IN6)
            case 7:
                status = GetVar(STATUS_OF_IN7)
            case 8:
                status = GetVar(STATUS_OF_IN8)
            case 9:
                status = GetVar(STATUS_OF_IN9)
            default:
                Diagnostics("\"inputNum\" out of range! - %d", inputNum)
         }

        diagnost2("Input %d status: 0x%x", inputNum, status)
        return status
     }

    getInputValue(inputNum)
     {
        new value

        switch (inputNum)
         {
            case 0:
                value = GetVar(IN_0)
            case 1:
                value = GetVar(IN_1)
            case 2:
                value = GetVar(IN_2)
            case 3:
                value = GetVar(IN_3)
            case 4:
                value = GetVar(IN_4)
            case 5:
                value = GetVar(IN_5)
            case 6:
                value = GetVar(IN_6)
            case 7:
                value = GetVar(IN_7)
            case 8:
                value = GetVar(IN_8)
            case 9:
                value = GetVar(IN_9)
            default:
                Diagnostics("\"inputNum\" out of range! - %d", inputNum)
         }

        diagnost2("Input %d value: %d", inputNum, value)
        return value
     }

    getGlobalInputStatus(inputNum)
     {
        if(inputNum <= MAX_IN)
     	{
     		return getInputStatus(inputNum)
     	}

     	if( inputNum <= (MAX_IN_SLAVE + MAX_IN + 1) )
     	{
     		switch ( inputNum - (MAX_IN + 1) )
            {
                case 0: return GetVar(em_inStat0)
                case 1: return GetVar(em_inStat1)
                case 2: return GetVar(em_inStat2)
                case 3: return GetVar(em_inStat3)
                case 4: return GetVar(em_inStat4)
                case 5: return GetVar(em_inStat5)
                case 6: return GetVar(em_inStat6)
                case 7: return GetVar(em_inStat7)
                case 8: return GetVar(em_inStat8)
                case 9: return GetVar(em_inStat9)
            }
     	}

        Diagnostics("ERROR argument: getGlobalInputStatus(arg: %d)", inputNum)
        return 0xFFFFFFFF
     }

    getGlobalInputValue(inputNum)
     {
     	if(inputNum <= MAX_IN)
     	{
     		return getInputValue(inputNum)
     	}

     	if( inputNum <= (MAX_IN_SLAVE + MAX_IN + 1) )
     	{
     		switch ( inputNum - (MAX_IN + 1) )
            {
                case 0: return GetVar(em_inp0)
                case 1: return GetVar(em_inp1)
                case 2: return GetVar(em_inp2)
                case 3: return GetVar(em_inp3)
                case 4: return GetVar(em_inp4)
                case 5: return GetVar(em_inp5)
                case 6: return GetVar(em_inp6)
                case 7: return GetVar(em_inp7)
                case 8: return GetVar(em_inp8)
                case 9: return GetVar(em_inp9)
            }
     	}

        Diagnostics("ERROR argument: getGlobalInputValue(arg: %d)", inputNum)
        return 0xFFFFFFFF
     }
////////////// IN END //////////////
////////////////////////////////////


main()
{
	Diagnostics("")

	for (new input = 0; input < (MAX_IN + MAX_IN_SLAVE + 1); input++)
	{
		Diagnostics( "Input: %d Value: %d", input, getGlobalInputValue(input) )
	}

	for (new input = 0; input < (MAX_IN + MAX_IN_SLAVE + 1); input++)
	{
		Diagnostics( "Input: %d Status: %d", input, getGlobalInputStatus(input) )
	}

	for (new out = 0; out < (MAX_OUT + MAX_OUT_SLAVE + 1); out++)
	{
		Diagnostics( "Output: %d Status: %d", out, getGlobalOutputStatus(out) )
	}
}
