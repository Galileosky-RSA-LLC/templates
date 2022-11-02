// New script template.

////////////////////////////////////////////////////
///////////////// DIAGNOSTICS //////////////////////
    Diagnost(text{})
    {
        if (GetVar(diagnost))
            Diagnostics(text)
    }

    Diagnost1(text{}, var)
    {
        if (GetVar(diagnost))
            Diagnostics(text, var)
    }

    Diagnost2(text{}, var1, var2)
    {
        if (GetVar(diagnost))
            Diagnostics(text, var1, var2)
    }

    DiagnostHex(array{}, array_size)
    {
        if (GetVar(diagnost))
            DiagnosticsHex(array, array_size)
    }
///////////////// DIAGNOSTICS END //////////////////
////////////////////////////////////////////////////

//////////////////////////////////////////
///////////////// SERIAL /////////////////
    // 9600, 19200, 38400 - max 1200 meters
    #define BOUD_RATE 9600
    #define PORT_INDEX 2  // RS485
    #define BUF_SIZE 300
    #define STOP_BITS 0 // 0 - 1 stop bit
    #define PARITY 0  // no parity bits

    serialInit()
    {
        Diagnost("serialInit()")
        PortInit(PORT_INDEX, BOUD_RATE, BUF_SIZE, STOP_BITS, PARITY)
    }

    serialWrite(ioBuf{}, ioBufSize)
    {
        Diagnost("Serial write:")
        DiagnostHex(ioBuf, ioBufSize)
        PortWrite(PORT_INDEX, ioBuf, ioBufSize)
    }

    /*! чтение пакетов из порта, разделённых по временной задержке ---- reading packets from the port, separated by time delay */
    serialRead(ioBuf{}, bufSize, firstByteTimeout, nextByteTimeout)
    {
        Diagnost("serialRead()")
        new count = 0

        // if (2 == PORT_INDEX)  // пока реализовано только для RS485 ---- so far implemented only for RS485
        // {
        //     count = PortReadPackage(PORT_INDEX, ioBuf, bufSize, firstByteTimeout, nextByteTimeout)
        //     Diagnost1("serialRead %d byts", count)
        //     DiagnostHex(ioBuf, count)
        //     return count
        // }

        new byteBuf

        if (PortRead(PORT_INDEX, byteBuf, firstByteTimeout))
        {
            ioBuf{count++} = byteBuf

            if (bufSize == count)
            {
                Diagnostics("The read buffer is full! %d byte.", count)
                return count
            }
        }
        else
            return count
        
        while (PortRead(PORT_INDEX, byteBuf, nextByteTimeout))
        {
            ioBuf{count++} = byteBuf

            if (bufSize == count)
            {
                Diagnostics("The read buffer is full! %d byte.", count)
                return count
            }
        }

        Diagnost1("serialRead %d byts:", count)
        DiagnostHex(ioBuf, count)
        return count
    }
///////////////// SERIAL END /////////////////
//////////////////////////////////////////////

main()
{
    new bufPort{BUF_SIZE}
    const firstByteTimeout = 500
    const nextByteTimeout = 100

    bufPort{0} = 0xFA

    serialInit()

    Diagnost("PING")
    serialWrite(bufPort, 1)

    new count = serialRead(bufPort, BUF_SIZE, firstByteTimeout, nextByteTimeout)

    if (count && bufPort{0} == 0xAF)
    	Diagnostics("PONG")
    else if (count)
    	Diagnostics("ERR_PONG: 0x%X", bufPort{0})
    else
    	Diagnostics("NOT_PONG")
}
