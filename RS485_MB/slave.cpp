//! slaveModBusInOut2

#define ADDRESS 0xF7  // адерес устройства (slave)
#define MAX_OUT 4  // максимальное количество выходов
#define MAX_IN 6   // максимальное количество входов
#define IMPULS_DELAY 100  // длина импульсов на выходы для управления импульсными реле
// #define IMPULSE_RELAY 1

//! Коды ошибок, возвращаемые функциями обмена по шине
    #define MB_ERR_OK 0      //!< Успешный обмен данными
    #define MB_ERR_CMD 1     //!< Принятый код функции не может быть обработан
    #define MB_ERR_ADDR 2    //!< Адрес данных, указанный в запросе, недоступен
    #define MB_ERR_VALUE 3   //!< Значение, содержащееся в поле данных запроса, является недопустимой величиной
    #define MB_ERR_ERR 4     //!< Невосстанавливаемая ошибка имела место, пока ведомое устройство пыталось выполнить затребованное действие
    #define MB_ERR_WAIT 5    //!< Ведомое устройство приняло запрос и обрабатывает его, но это требует много времени. Этот ответ предохраняет ведущее устройство от генерации ошибки тайм-аута
    #define MB_ERR_BUSY 6    //!< Ведомое устройство занято обработкой команды. Ведущее устройство должно повторить сообщение позже, когда ведомое освободится
    #define MB_ERR_CNTEXEC 7 //!< Ведомое устройство не может выполнить программную функцию, заданную в запросе
    #define MB_ERR_PARITY 8  //!< Ведомое устройство при чтении расширенной памяти обнаружило ошибку паритета
    #define MB_ERR_CRC 9     //!< Ошибка контрольной суммы
    #define MB_ERR_SIZE 10   //!< Получен ответ некорректного размера

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
    #define BOUD_RATE 115200
    #define PORT_INDEX 2  // RS485
    #define BUF_SIZE 256
    #define STOP_BITS 0 // 0 - 1 stop bit
    #define PARITY 0  // no parity bits

    serialInit()
     {
        // Diagnost("serialInit()")

        PortInit(PORT_INDEX, BOUD_RATE, BUF_SIZE, STOP_BITS, PARITY)
     }

    serialWrite(ioBuf{}, ioBufSize)
     {
        Diagnost("Serial write:")
        DiagnostHex(ioBuf, ioBufSize)

        PortWrite(PORT_INDEX, ioBuf, ioBufSize)
     }

    /*! чтение пакетов из порта, разделённых по временной задержке */
    serialRead(ioBuf{}, bufSize, firstByteTimeout, nextByteTimeout)
     {
        new count = 0
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
        {
            Diagnost("serialRead 0 byts")
            return count
        }
        
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
///////////////// SERIAL END /////////////
//////////////////////////////////////////

/////////////////////////////////////
//////////////// OUT ////////////////
    outputOn(outputNum)
     {
        SetOutputValue(outputNum, 0)
        Diagnost1("Output %d ON", outputNum)
     }

    outputOff(outputNum)
     {
        SetOutputValue(outputNum, 1)
        Diagnost1("Output %d OFF", outputNum)
     }

    getOutputStatus(outputNum)
     {
        switch (outputNum)
        {
            case 0: 
            {
                // Diagnostics("OutputStatus %d: 0x%X", outputNum, GetVar(OUT_0))
                return GetVar(OUT_0)
            }
            case 1: 
            {
                // Diagnostics("OutputStatus %d: 0x%X", outputNum, GetVar(OUT_1))
                return GetVar(OUT_1)
            }
            case 2: 
            {
                // Diagnostics("OutputStatus %d: 0x%X", outputNum, GetVar(OUT_2))
                return GetVar(OUT_2)
            }
            case 3: 
            {
                // Diagnostics("OutputStatus %d: 0x%X", outputNum, GetVar(OUT_3))
                return GetVar(OUT_3)
            }
            default:
            {
                Diagnostics("\"outputNum\" out of range! - %d", outputNum)
                return 0xFFFFFFFF
            }
        }
     }
////////////// OUT END //////////////
/////////////////////////////////////

////////////////////////////////////
//////////////// IN ////////////////
    getInputStatus(inputNum)
     {
        switch (inputNum)
        {
            case 0: return GetVar(STATUS_OF_IN0)
            case 1: return GetVar(STATUS_OF_IN1)
            case 2: return GetVar(STATUS_OF_IN2)
            case 3: return GetVar(STATUS_OF_IN3)
            case 4: return GetVar(STATUS_OF_IN4)
            case 5: return GetVar(STATUS_OF_IN5)
            case 6: return GetVar(STATUS_OF_IN6)
            case 7: return GetVar(STATUS_OF_IN7)
            case 8: return GetVar(STATUS_OF_IN8)
            case 9: return GetVar(STATUS_OF_IN9)
            default:
            {
                Diagnostics("\"inputNum\" out of range! - %d", inputNum)
                return 0xFFFFFFFF
            }
        }
     }

    getInput(inputNum)
     {
        switch (inputNum)
        {
            case 0: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_0))
                return GetVar(IN_0)
            }
            case 1: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_1))
                return GetVar(IN_1)
            }
            case 2: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_2))
                return GetVar(IN_2)
            }
            case 3: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_3))
                return GetVar(IN_3)
            }
            case 4: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_4))
                return GetVar(IN_4)
            }
            case 5: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_5))
                return GetVar(IN_5)
            }
            case 6: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_6))
                return GetVar(IN_6)
            }
            case 7: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_7))
                return GetVar(IN_7)
            }
            case 8: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_8))
                return GetVar(IN_8)
            }
            case 9: 
            {
                // Diagnostics("Input %d: 0x%X", inputNum, GetVar(IN_9))
                return GetVar(IN_9)
            }
            default:
            {
                Diagnostics("\"inputNum\" out of range! - %d", inputNum)
                return 0xFFFFFFFF
            }
        }
     }
////////////// IN END //////////////
////////////////////////////////////

// реализованные функции
    #define CMD_READ_ALL 0x01
    #define CMD_READ_IN 0x04
    #define CMD_READ_OUT_STATUS 0x05
    #define CMD_READ_IN_STATUS 0x02
    #define CMD_SET_OUT 0x10
    #define CMD_SET_VARS 0x03
    #define CMD_MAKE_PULSE 0x30

// функция приёма команд
readApplyCmd(ioBuf{})
 {
    // Diagnost("readApplyCmd()")
    const addrPos = 0
    const cmdPos = 1
    const startRegPos = 2
    const countRegPos = 4
    const crcLen = 2

    new firstByteTimeout = 10 * 1000
    const nextByteTimeout = 100
    
    new count = serialRead(ioBuf, BUF_SIZE, firstByteTimeout, nextByteTimeout)
    new ansSize

    if (!count || ADDRESS != ioBuf{addrPos})
        return 0xFFFFFFFF

    if (ioBuf{cmdPos} == CMD_SET_OUT)
     {
        const dataLenPos = 6
        const headerLen = 7

        new dataPos = 7
        new dataLen = ioBuf{dataLenPos}
        new ansSize = headerLen + dataLen + crcLen
        new crc

        if ( checkMsg(ioBuf, ansSize, count) )
         {
            Diagnostics("MB_ERR_CRC")
            return checkMsg(ioBuf, ansSize, count)
         }

        new startReg = ioBuf{startRegPos + 1}  // регистр с которого начинается чтение
        new countReg = ioBuf{countRegPos + 1}  // кол-во регистров для чтения
        new countByte = dataPos

        for (new out = startReg; out < (startReg + countReg); ++out)
         {
            if (out >= MAX_OUT)
             {
                Diagnost("MB_ERR_VALUE")
                return MB_ERR_VALUE
             }

            new bufValue[1]
            bufValue{2} = ioBuf{dataPos++}
            bufValue{3} = ioBuf{dataPos++}
            new cmdEnable = !bufValue[0]
            
            if (cmdEnable)
                outputOn(out)
            else
                outputOff(out)
         }

        return MB_ERR_OK
     }
    else if(ioBuf{cmdPos} == CMD_READ_IN || 
            ioBuf{cmdPos} == CMD_READ_OUT_STATUS ||
            ioBuf{cmdPos} == CMD_READ_IN_STATUS)
        ansSize = 8
    else if (ioBuf{cmdPos} == CMD_READ_ALL)
        ansSize = 4
    else if (ioBuf{cmdPos} == CMD_SET_VARS)
     {
        ansSize = 7

        if ( checkMsg(ioBuf, ansSize, count) )
         {
            Diagnostics("MB_ERR_CRC")
            return checkMsg(ioBuf, ansSize, count)
         }

        const posFlag = 2
        const posTime = 3

        new flagsOuts = ioBuf{posFlag} & 0x0F
        SetVar(flags_outs, flagsOuts)

        new modKey = (ioBuf{posFlag} >> 4) & 0x03
        SetVar(mod_key, modKey)

        new timeBuf[1]
        timeBuf{2} = ioBuf{posTime}
        timeBuf{3} = ioBuf{posTime + 1}
        SetVar(start_time, timeBuf[0])

        return MB_ERR_OK
     }
    else if (ioBuf{cmdPos} == CMD_MAKE_PULSE)
     {
        ansSize = 8

        if ( checkMsg(ioBuf, ansSize, count) )
         {
            Diagnostics("MB_ERR_CRC")
            return checkMsg(ioBuf, ansSize, count)
         }

        const posOut = 2
        const posDelay = 4
        
        new output[1]
        new delay[1]
        
        output{2} = ioBuf{posOut}
        output{3} = ioBuf{posOut + 1}
        delay{2} = ioBuf{posDelay}
        delay{3} = ioBuf{posDelay + 1}

        impuls(output[0], delay[0])

        return MB_ERR_OK
     }
    else
     {
        Diagnost("MB_ERR_CMD")
        return MB_ERR_CMD
     }

    if ( checkMsg(ioBuf, ansSize, count) )
     {
        Diagnostics("MB_ERR_CRC")
        return checkMsg(ioBuf, ansSize, count)
     }

    return MB_ERR_OK
 }

/*! Управление импульсными реле 
    \param out индекс выхода
    \param delay продолжительность импульса
    */
impuls(out, delay)
 {
    outputOn(out)
    Delay(delay)
    outputOff(out)
 }

/*! Проверка сообщения 
    \param ioBuf{} массив с сообщением
    \param ansSize целевой размер сообщения
    \param count размер принятого сообщения
    \retval код ошибки
    */
checkMsg(ioBuf{}, ansSize, count)
 {
    //Сверяем целевой и фактический размеры ответа
        if (ansSize != count)
        {
            Diagnostics("MB_ERR_SIZE:\nMer[%d]", MB_ERR_SIZE)
            Diagnostics("aS:%d != br:%d", ansSize, count)
            
            return MB_ERR_SIZE
        }

    // Проверяем CRC
        new crc = ioBuf{ansSize - 2} + ioBuf{ansSize - 1} * 256

        if (crc != CRC16(ioBuf, ansSize - 2))
        {
            Diagnost("MB_ERR_CRC")
            return MB_ERR_CRC
        }

    return MB_ERR_OK
 }

// отвечает на принятое сообщение
respond(ioBuf{}, MB_ERR)
 {
    const addrPos = 0
    const cmdPos = 1
    const startRegPos = 2
    const countRegPos = 4
    const crcLen = 2
    const headerLen = 3

    new answerLen = 5

    if (MB_ERR)
     {
        ioBuf{cmdPos} |= 0x08
        ioBuf{startRegPos} = MB_ERR

        answerLen = 3
     }
    else if (ioBuf{cmdPos} == CMD_SET_OUT || ioBuf{cmdPos} == CMD_MAKE_PULSE)
        answerLen = 6
    else if (ioBuf{cmdPos} == CMD_READ_ALL)
     {
        const lenArr = 40
        new buf{lenArr}
        new d_pos = 3

        answerLen = setArrStatus(buf)
        ioBuf{2} = answerLen
        GS_append(ioBuf, d_pos, BUF_SIZE, buf, answerLen)
        answerLen += headerLen
     }
    else
     {
        const posDataLen = 2

        new posData = 3
        new startReg = ioBuf{startRegPos + 1}  // регистр с которого начинается чтение
        new countReg = ioBuf{countRegPos + 1}  // кол-во регистров для чтения

        ioBuf{posDataLen} = countReg * 2

        if (ioBuf{cmdPos} == CMD_READ_OUT_STATUS)
        {
            for (new reg = 0; reg < countReg; ++reg)
            {
                new regC = reg + startReg

                if (regC >= MAX_OUT)
                {
                    Diagnost("MB_ERR_VALUE")
                    return MB_ERR_VALUE
                }

                new buf[1]

                buf[0] = getOutputStatus(regC)
                // Diagnost2("OutStatus %d: 0x%x", regC, buf[0])
                ioBuf{posData} = buf{2}
                ioBuf{posData + 1} = buf{3}
                posData += 2
            }
        }
        else if (ioBuf{cmdPos} == CMD_READ_IN)
        {
            for (new reg = 0; reg < countReg; ++reg)
            {
                new regC = reg + startReg

                if (regC >= MAX_IN)
                {
                    Diagnost("MB_ERR_VALUE")
                    return MB_ERR_VALUE
                }

                new buf[1]

                buf[0] = getInput(regC)
                // Diagnost2("Input %d: 0x%x", regC, buf[0])
                ioBuf{posData} = buf{2}
                ioBuf{posData + 1} = buf{3}
                posData += 2
            }
        }
        else if (ioBuf{cmdPos} == CMD_READ_IN_STATUS)
        {
            for (new reg = 0; reg < countReg; ++reg)
            {
                new regC = reg + startReg

                if (regC >= MAX_IN)
                {
                    Diagnost("MB_ERR_VALUE")
                    return MB_ERR_VALUE
                }

                new buf[1]

                buf[0] = getInputStatus(regC)
                Diagnost2("Input status %d: 0x%x", regC, buf[0])
                ioBuf{posData} = buf{2}
                ioBuf{posData + 1} = buf{3}
                posData += 2
            }
        }
     }

    //Добавляем CRC
    new crc = CRC16(ioBuf, answerLen)
    ioBuf{answerLen++} = crc
    ioBuf{answerLen++} = crc >> 8

    //Пишем в порт
    PortWrite(PORT_INDEX, ioBuf, answerLen)
    Diagnost("PortWrite:")
    DiagnostHex(ioBuf, answerLen)
 }

// выставляет флаги состояний
setArrStatus(buf{})
 {
    buf[0] &= ~0xFFFFFFFF

    for (new input = 0; input < MAX_IN; ++input)
    {
        if (16 == input)  // первые 2 байта статусы входов
        {
            Diagnost("The maximum possible port value has been exceeded!")
            return 0
        }

        new inputStatus = getInputStatus(input)

        if (inputStatus)
            buf[0] |= (0x01 << input)
        else
            buf[0] &= ~(0x01 << input)
    }

    // DiagnostHex(buf, 4)

    for (new out = 0; out < MAX_OUT; ++out)
    {
        if (16 == out)  // следующие 2 байта статусы выходов
        {
            Diagnost("The maximum possible port value has been exceeded!")
            return 0
        }

        new outStatus = getOutputStatus(out)

        if (outStatus)
            buf[0] |= ( 0x01 << (out + 16) )
        else
            buf[0] &= ~( 0x01 << (out + 16) )
    }

    // DiagnostHex(buf, 4)

    new count = 4

    for (new input = 0; input < MAX_IN; ++input)
    {
        new inputValue[1]
        inputValue[0] = getInput(input)
        buf{count++} = inputValue{2}
        buf{count++} = inputValue{3}
    }

    // DiagnostHex(buf, count)

    return count
 }

/*! вставить массив в другой массив (присоединить строку) 
    и "перевести каретку" (инкрементировать указатель позиции)
    \param dst{} массив, куда копируется содержимое второго массива
    \param &d_pos начиная с какого элемента принимающего массива начнется вставка (ПЕРЕДАЕТСЯ ПО ССЫЛКЕ!) 
    \param d_len длина принимающего массива
    \param src{} массив для вставки
    \param s_len длина массива для вставки
    \retval не забудьте, что аргумент d_pos будет инкрементирован количество раз, равное длине второго (вставляемого) массива
    */
GS_append(dst{}, &d_pos, d_len, src{}, s_len)
 {
    new s_pos = 0

    while(s_pos < s_len)
     {
        GS_appendC(dst, d_pos, d_len, src{s_pos})
        ++s_pos
     }
 }

/*! вставить символ в массив, обрабатываемого как строка, 
    и "перевести каретку вперед" (инкрементировать указатель позиции)
    \param dst{} массив, обрабатываемый как строка
    \param &d_pos в какой элемент массива записать символ (ПЕРЕДАЕТСЯ ПО ССЫЛКЕ!) 
    \param d_len длина массива 
    \param c переменная (символ) для вставки
    \retval не забудьте, что аргумент d_pos будет инкрементирован
    */
GS_appendC(dst{}, &d_pos, d_len, c)
 {
    if(d_pos < d_len)
     {
        dst{d_pos} = c
        ++d_pos
     }
 }


main()
{
    Diagnost("script start")
    new ioBuf{BUF_SIZE}

    serialInit()
    Delay(10)

    for (new i = 0; i < 128; ++i)
    {
        new err = readApplyCmd(ioBuf)

        if(err && err != 0xFFFFFFFF)
            Diagnost1("ERROR: 0x%x", err)

        if(0xFFFFFFFF != err)
            respond( ioBuf, err )
    }
}
