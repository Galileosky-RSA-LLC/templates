#define ADDRESS 0xF7

#define CMD_READ_ALL 0x01
#define CMD_READ_IN 0x04
#define CMD_READ_OUT_STATUS 0x05
#define CMD_READ_IN_STATUS 0x02
#define CMD_SET_OUT 0x10
#define CMD_MAKE_PULSE 0x30

#define MAX_OUT 3
#define MAX_OUT_SLAVE 3

#define MAX_IN 5
#define MAX_IN_SLAVE 5

// ===========================================================================
//{ Библиотека вспомогательных функций GalileoSky ============================
// ===========================================================================

    /* Возведение в степень */
    GS_pow(num, p)
    {
        new buf1 = num
        new buf2 = num

        if ( 0 == p)
            return 1

        if ( 1 == p )
            return buf1

        for (new i = 0; i < p-1; ++i)
        {
            buf1 *= buf2
        }

        return buf1
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

    GS_appendHexHalfByte(dst{}, &d_pos, d_len, number)
    {
        if(d_pos < d_len)
        {
            number = number & 0x0F
            dst{d_pos} = (number < 10) ? (number + 0x30) : (number + 0x41 - 10)
            ++d_pos
        }
    }

    GS_appendHexByte(dst{}, &d_pos, d_len, number)
    {
        GS_appendHexHalfByte(dst, d_pos, d_len, number >> 4)
        GS_appendHexHalfByte(dst, d_pos, d_len, number) 
    }

    GS_extractByte(number, byte_index)
    {
        return ( (number >> (8 * byte_index)) & 0xFF )
    }

    GS_appendHex(dst{}, &d_pos, d_len, number, byte_count)
    {
        while(byte_count)
        {
            GS_appendHexByte(dst, d_pos, d_len, GS_extractByte(number, byte_count-1))
            --byte_count
        }
    }

    GS_appendN(dst{}, &d_pos, d_len, value)
    {
        if(value==0)
        {
            GS_appendC(dst, d_pos, d_len, '0')
            return
        }

        if (value < 0) 
        {
            value = (-1)*value;
            GS_appendC(dst, d_pos, d_len, '-')
        }

        new divider = 1000000000;
        new first = true
        while(divider != 0)
        {
            new c = value/divider
            if(first && (c!=0))
                first = false
            if(!first)
                GS_appendC(dst, d_pos, d_len, c + 0x30)
            value -= c*divider
            divider = divider/10
        }
    }

    GS_strlen(buf{})
    {
        new i = 0
        while(buf{i}!=0)
            ++i
        return i
    }

    GS_readLine(file{}, pos, dst{}, dst_size)
    {
        const cr_symbol = 0x0D; // CR
        const lf_symbol = 0x0A; // LF

        new len = FileRead(file, dst, dst_size, pos)
        if(len <= 0)
            return 0

        new counter = 0;
        while(counter<dst_size)
        {
            if(dst{counter} == cr_symbol)
            {
                if(counter+1 < dst_size)
                    if(dst{counter+1} == lf_symbol)
                    {
                        dst{counter} = 0
                        return counter
                    }
            }
            ++counter
        }
        dst{counter - 1} = 0
        return counter
    }

    /*! сравнить строки побайтово
        \param str1{} первая строка
        \param str2{} вторая строка
        \param len длина строк (должна быть одинаковой, конечно)
        \retval 0 - строки не равны, 1 - строки равны
    */
    GS_stringEquals(str1{}, str2{}, len)
    {
        for(new i = 0; i < len; i++)
        {
            if(str1{i} != str2{i})
                return 0;
        }
        
        return 1;
    }

    /*! копировать строки побайтово
        \param dest{} куда копировать
        \param source{} откуда копировать
        \param len длина строк (должна быть одинаковой, конечно)
        \param destPos смещение
        \param sourcePos смещение
    */
    GS_copyArray(dest{}, source{}, len, destPos, sourcePos)
    {
        for (new i = 0; i < len; ++i)
        {
            dest{i + destPos} = source{i + sourcePos}
        }
        return
    }

    GS_isDigit(byte)
    {
        return ((byte >= '0') && (byte <= '9'))
    }

    GS_isHex(byte)
    {
        new isDigit = GS_isDigit(byte)
        new isHex = byte >= 'A' && byte <= 'F'
        new ishex = byte >= 'a' && byte <= 'f'
        new hex = isHex || ishex

        return ( hex || isDigit)
    }

    GS_getDigit(byte)
    {
        return byte - 0x30
    }

    GS_getHex(byte)
    {
        if (GS_isDigit(byte))
            return GS_getDigit(byte)

        if (byte >= 'A' && byte <= 'F')
            return (byte - 0x40) + 9

        if (byte >= 'a' && byte <= 'f')
            return (byte - 0x60) + 9
    }

    /*! Алгоритм прямого поиска 
      / string1 - где искать
      / string2 - что искать
    */
    GS_strstr(string1{}, str1Len, string2{}, str2Len)
    {
        if ( str2Len > str1Len )
            return -1

        new count = (str1Len - str2Len) + 1
        
        for (new i = 0; i < count; ++i)
        {
            new res = 1
            new iBuf = i

            for (new j = 0; j < str2Len; ++j)
            {
                if (string1{iBuf} != string2{j})
                {
                    res = 0
                    break
                }

                iBuf++
            }
            
            if (res)
                return i
        }

        return -1
    }

    /*! Собирает число из строки */
    GS_atoi(str{}, &pos)  // arr to Int
    {
        new value = 0
        new is_minus = false

        if(str{pos} == 0)
            return 0

        if (str{pos} == '-') 
        {
            is_minus = true
            pos++
        }

        while(GS_isDigit(str{pos}))
        {
            value = value * 10 + (str{pos} - '0')
            ++pos
        }

        if(is_minus)
            return -value

        return value
    }

    GS_arrToFloat(str{}, &pos, precision) 
    {
        new value = 0
        new is_minus = false
        value = GS_atoi(str, pos)
        new i = 0

        if(str{pos} == '.')
        {
            ++pos       
            for(; i < precision; ++i)
            {
                if(GS_isDigit(str{pos}))
                    value = value*10 + GS_getDigit(str{pos})
                else
                    break;
                ++pos
            }       
        }

        for(; i < precision; ++i)
            value = value * 10

        while(GS_isDigit(str{pos}))
            ++pos

        return value
    }

    GS_strToHex(strAscii{}, lenStrAscii, arr{})  // TODO
    {
        new pos = 0
        
        while( pos < lenStrAscii )
        {
            arr{pos / 2} = GS_getHex(strAscii{pos}) << 4 & ~0x0F

            if ( lenStrAscii > (pos + 1) )
                arr{pos / 2} |= GS_getHex(strAscii{pos + 1})

            pos = pos + 2
        }

        if (lenStrAscii % 2)
            GS_offsetArrRight8(arr, pos, 4)
        
        return pos / 2
    }

    GS_swapValue(value, value_size)
    {
      new temp_buf[1] = 0
      temp_buf[0] = value
      swapBuf(temp_buf, 4)
      value = temp_buf[0]
      value = value >> (4 - value_size) * 8
      return value
    }

    GS_clearArr(arr{}, arrSize)
    {
        for (new i = 0; i < arrSize; ++i)
            arr{i} = 0x00
    }

    /*! смещает массив вправо максимум на 8 бит */
    GS_offsetArrRight8(arr{}, arrLenByte, bitOffsetRight)  // TODO УПРОСТИТЬ!!!
    {
        Diagnost("\nStart GS_offsetArrRight8")

        if (!bitOffsetRight) return OK

        if (bitOffsetRight < 0 || bitOffsetRight > 8)
        {
            Diagnostics("ERR")
            return ERR
        }

        Diagnost1("arrLenByte - 1 = %d", arrLenByte - 1)

        for (new i = arrLenByte - 1; i >= 0; --i)
        {
            if (i || arrLenByte == 1)
            {
                arr{i} = arr{i} >> bitOffsetRight

                if(arrLenByte > 1)
                {
                    new byteBuf{1}
                    byteBuf{0} = arr{i - 1} << (8 - bitOffsetRight)
                    arr{i} |= byteBuf{0}
                }

                Diagnost2("arr{%d}: 0x%x", i, arr{i})
            }
        }

        Diagnost("result Array:")
        DiagnostHex(arr, arrLenByte)
        Diagnost("End GS_offsetArrRight8")
    }

    /*! смещает массив вправо
        использует GS_offsetArrRight8()
    */
    GS_offsetArrRight(arr{}, arrLenByte, bitOffsetRight)
    {
        Diagnost("\nStart GS_offsetArrRight")

        const byteLen = 8
        
        if (bitOffsetRight < 0) return ERR

        if (!bitOffsetRight) return OK
        
        for (new i = 0; i < (bitOffsetRight / byteLen); i++)
        {
            GS_offsetArrRight8(arr, arrLenByte, byteLen)
        }

        GS_offsetArrRight8(arr, arrLenByte, (bitOffsetRight % byteLen))

        return OK
    }

    /*! собирает INT32 из байт массива. Максимум на 32 бита */
    GS_getInt(arr{}, startInd, stopInd)
    {
        const byteLen = 8
        new res = 0
        new countByte = stopInd - startInd + 1

        if(countByte > 4)
            return false

        for (new i = 0; i < countByte; ++i)
        {
            res += arr{startInd + i} << byteLen * (countByte - (i + 1))
        }

        return res
    }

    /*! WeightIndicator 
        WeightIndicator::packWeight(weight, &w1, &w2);
        RS232::setValue(_port, w1);
        RS232::setTemperature(_port, w2);
    */
    packWeight(weight)
    {
        const RS232_0_2B = 0x58
        const RS232_0_1B = 0x88
        new t1
        new t2

        if (weight >= 0)
        {
            t1 = weight % 65535
            t2 = weight / 65535
        }
        else
        {
            t2 = (weight / 65535) - 1
            t1 = weight - (t2 * 65535)
        }

        TagWriteValue( RS232_0_2B, (t1 &= 0xFFFF) )
        TagWriteValue( RS232_0_1B, (t2 &= 0xFF) )
    }

    //======================================================================
    //============================== CRC ===================================
    //======================================================================
    /* CRC-16 CCITT
        Name  : CRC-16 CCITT
        Poly  : 0x1021    x^16 + x^12 + x^5 + x^0
        Init  : 0x1D0F

        Example 1:
        537F0D00046E00802500006E38
        6E38 is the CRC here (in Little endian format)

        Example 2:
        53000900046100C066
        C066 is the CRC here (in Little endian format)
    */
    new const Crc16Table[256] = [
            0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
            0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
            0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
            0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
            0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
            0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
            0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
            0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
            0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
            0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
            0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
            0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
            0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
            0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
            0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
            0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
            0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
            0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
            0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
            0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
            0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
            0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
            0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
            0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
            0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
            0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
            0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
            0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
            0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
            0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
            0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
            0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
        ]

    GS_Crc16CCITT(pcBlock{}, len)
    {
        const crcMask = 0xFFFF0000
        new i = 0
        new crc = 0x1D0F

        for (; i < len; i++) 
        {
            crc = ( (crc << 8) & ~crcMask ) ^ Crc16Table[ ((crc >> 8) ^ pcBlock{i}) & 0xFF]
        }

        return crc
    }

    GS_CRC8XOR(arr{}, len)
    {
        new crc8 = 0
        new i = 0

        for (; i < len; ++i)
        {
            crc8 ^= arr{i}
        }

        return crc8
    }
// ===========================================================================
//} Конец библиотеки вспомогательных функций GalileoSky ======================
// ===========================================================================


//!*************************************************************
//!-----------------Библиотека работы с Modbus------------------
//!*************************************************************
    //! Порт подключения шины Modbus
    #define MB_PORT_INDEX 2

    //! Скорость подключения по шине Modbus
    #define MB_PORT_SPEED 115200    

    //! Количество стопбит
    #define MB_PORT_STOP 0  

    //! Размер буфера для обмена по шине Modbus
    #define MB_BUF_SIZE 256

    //! Таймаут ожидания ответа слейва, мс
    #define MB_TIMEOUT 120

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

    //! Начальная позиция полезных данных при команде "чтение"
    #define MB_READ_START 3

    //! Начальная позиция полезных данных при команде "запись"
    #define MB_WRITE_START 7

    //! Инициализация шины Modbus
    modbusInit()
    {
        PortInit(MB_PORT_INDEX, MB_PORT_SPEED, MB_BUF_SIZE , MB_PORT_STOP);
    }

    //! Запись значения 16-битного регистра в буфер в формате Modbus
    //! \param[in] mbBuf Буфер, куда производится запись
    //! \param[in] offset Смещение указателя записи от начала буфера
    //! \param[in] value Значение записываемого регистра
    setReg(mbBuf{}, offset, value)
    {
        mbBuf{offset} = value >> 8 //Старший байт вперед
        mbBuf{offset + 1} = value //Младший байт
    }

    //! Функция возвращает значения 16-битного регистра Modbus из буфера
    //! \param[in] mbBuf Буфер, откуда производится чтение
    //! \param[in] offset Смещение указателя чтения от начала буфера
    //! \return Конвертированное значение регистра
    getReg(mbBuf{}, offset)
    {
        // return mbBuf{offset} * 256 + mbBuf{offset + 1}
        new res[1]
        res{2} = mbBuf{offset}
        res{3} = mbBuf{offset + 1}

        return res[0]
    }

    //! Функция возвращает значения 32-битного регистра Modbus из буфера
    //! \param[in] mbBuf Буфер, откуда производится чтение
    //! \param[in] offset Смещение указателя чтения от начала буфера
    //! \return Конвертированное значение регистра
    getReg32(mbBuf{}, offset)
    {
        return (mbBuf{offset} << 24) + (mbBuf{offset + 1} << 16) + (mbBuf{offset + 2} << 8) + (mbBuf{offset + 3})
    }

    //! 0x03 - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
    //! \param[in] count Количество считываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    readRegs(addr, mbBuf{}, fRegAddr, count)
    {
        mbBuf{0} = addr
        mbBuf{1} = 0x03 //Код функции
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
        setReg(mbBuf, 4, count) //Количество считываемых элементов
        return transact(mbBuf, 6)
    }

    //! 0x04 - Функция чтение значений из нескольких регистров хранения (Read Input Registers)
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
    //! \param[in] count Количество считываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    readRegsIn(addr, mbBuf{}, fRegAddr, count)
    {
        mbBuf{0} = addr
        mbBuf{1} = 0x04 //Код функции
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
        setReg(mbBuf, 4, count) //Количество считываемых элементов
        return transact(mbBuf, 6)
    }

    //! 0x10 - Функция записи значений в несколько регистров хранения (Preset Multiple Registers)
    //!
    //! Функция заполнит заголовок буфера и отправит его в шину, полезные данные требуется располагать
    //! начиная с позиции \a MB_WRITE_START. Записываемые значения все 16-битные
    //! \param[in] addr Адрес ведомого устройства
    //! \param[in] mbBuf Буфер обмена, который будет отправлен
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется записать
    //! \param[in] count Количество записываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    writeRegs(addr, mbBuf{}, fRegAddr, count)
    {
        mbBuf{0} = addr
        mbBuf{1} = 0x10 //Код функции
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
        setReg(mbBuf, 4, count) //Количество считываемых элементов
        mbBuf{6} = count * 2
        return transact(mbBuf, 7 + count * 2)
    }

    //!----------------- служебные функции MODBUS ------------------
    //! Обмен с устройством данными по шине
    //! \param[inout] mbBuf Буфер обмена, данные из него будут записаны с добавленной CRC, и в него будут считан ответ без CRC
    //! \param[inout] size Размер буфера обмена
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    transact(mbBuf{}, size)
    {    
        //Добавляем CRC
        new c = CRC16(mbBuf, size)
        mbBuf{size} = c
        mbBuf{size + 1} = c >> 8

        //Пишем в порт
        Diagnost("PortWrite:")
        DiagnostHex(mbBuf, size + 2)
        PortWrite(MB_PORT_INDEX, mbBuf, size + 2)

        //Размер ответа, для записывающих команд размер известен из стандарта
        new ansSize = (mbBuf{1} > 5) ? 8 : MB_BUF_SIZE + 1

        //Слушаем ответ
        new err = 0
        new bytesRead = 0
        c = 0

        while (PortRead(MB_PORT_INDEX, c, MB_TIMEOUT))
        {
            mbBuf{bytesRead} = c
            bytesRead++

            // Diagnost1("0x%X", c)

            if ((bytesRead >= MB_BUF_SIZE) || (bytesRead >= ansSize))
                break

            //Ошибка ли?
            if (bytesRead == 2)
                err = (c & 0x80 == 0x80)

            //Определяем длину сообщения, либо код ошибки
            if (bytesRead == 3)
            {
                if (err)
                {
                    err = c
                    ansSize = 5
                }
                else 
                {
                    if (ansSize == MB_BUF_SIZE + 1)  //Считываем размер только для операций чтения
                        ansSize = 3 + c + 2
                }
            }
        }

        if (bytesRead)
        {
            Diagnost("PortRead:")
            DiagnostHex(mbBuf, bytesRead)
        }
        else
            Diagnost("PortRead: ----")

        if (!bytesRead)
            return MB_ERR_SIZE

        //Сверяем целевой и фактический размеры ответа
        if (ansSize != bytesRead)
        {
            Diagnostics("Mer[%d]", MB_ERR_SIZE)
            Diagnostics("aS:%d != br:%d", ansSize, bytesRead)
            
            return MB_ERR_SIZE
        }

        // printData(mbBuf, bytesRead)
        //Проверяем CRC
        c = mbBuf{ansSize - 2} + mbBuf{ansSize - 1} * 256
        if (c != CRC16(mbBuf, ansSize - 2))
        {
            Diagnost("MB_ERR_CRC")
            return MB_ERR_CRC
        }
        //Проверки пройдены, возвращаем код результата(ошибки)
        return err
    }

    //! Функция вывода содержимого буфера \a buf длиной \a len
    printData(buf{}, len)
    {
        // вывод по 2 байта в строке
        for(new i = 0; i < len / 2; i++)
        {
            Diagnostics("%02X %02X", buf{i * 2}, buf{i * 2 + 1})
            Delay(10)
        }
        // вывод последнего байта при нечётной длине
        if (len % 2)
            Diagnostics("%02X", buf{len - 1})
    }

    //! Функция записи значения регистра в тег
    readRegWriteTag(mbBuf{}, tag, valueName{}, regAdr)
    {
        Diagnostics(valueName)
        new res = readRegs(ADDRESS, mbBuf, regAdr, 1)
        if (!res)
        {
            res = getReg(mbBuf, MB_READ_START)
            // Diagnostics("value %x: in tag: %d", res, regAdr)
            TagWriteValue(tag, res)
        }
        else
            Diagnostics("Error code: %d in tag: %x", res, regAdr)
    }

    //! Функция записи значения регистров в тег
    readReg32WriteTag(mbBuf{}, tag, valueName{}, regAdr)
    {
        Diagnostics(valueName)
        new res = readRegs(ADDRESS, mbBuf, regAdr, 2)
        if (!res)
        {
            res = getReg32(mbBuf, MB_READ_START)
            // Diagnostics("value %x: in tag: %d", res, regAdr)
            TagWriteValue(tag, res)
        }
        else
            Diagnostics("Error code: %d in tag: %x", res, regAdr)
    }
//!*************************************************************
//!-----------Конец библиотеки работы с Modbus------------------
//!*************************************************************

//////////////////////////////////////////
///////////////// SERIAL /////////////////
    // 9600, 19200, 38400 - max 1200 meters
    #define BOUD_RATE 115200
    #define PORT_INDEX 2  // RS485
    #define BUF_SIZE 128
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

    /*! чтение пакетов из порта, разделённых по временной задержке */
    serialRead(ioBuf{}, bufSize, firstByteTimeout, nextByteTimeout)
    {
        Diagnost("serialRead()")
        new count = 0

        if (2 == PORT_INDEX)  // пока реализовано только для RS485
        {
            count = PortReadPackage(PORT_INDEX, ioBuf, bufSize, firstByteTimeout, nextByteTimeout)
            Diagnost1("serialRead %d byts", count)
            DiagnostHex(ioBuf, count)
            return count
        }

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
///////////////// SERIAL END /////////////
//////////////////////////////////////////

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


/////////////////////////////////////
//////////////// OUT ////////////////
    // #define CMD_READ_IN 0x04
    // #define CMD_READ_OUT_STATUS 0x05
    // #define CMD_READ_IN_STATUS 0x02

    //! CMD_READ_OUT_STATUS - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
    //! \param[in] count Количество считываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    readRegsOutStatus(addr, mbBuf{}, fRegAddr, count)
     {
        new err = 1

        for (new i = 0; i < 10; ++i)
        {
            mbBuf{0} = addr
            mbBuf{1} = CMD_READ_OUT_STATUS  //Код функции
            setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
            setReg(mbBuf, 4, count) //Количество считываемых элементов
            err = transact(mbBuf, 6)

            if(!err)
                break

            // Delay(100)
        }

        return err
     }

     //! CMD_MAKE_PULSE - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)
   
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] outputNum Адрес порта
    //! \param[in] delay Задержка импульса
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    sendMakePulse(addr, mbBuf{}, outputNum, delay)
     {
        new err = 1

        for (new i = 0; i < 10; ++i)
        {
            mbBuf{0} = addr
            mbBuf{1} = CMD_MAKE_PULSE  // Код функции
            setReg(mbBuf, 2, outputNum)  // Адрес порта
            setReg(mbBuf, 4, delay)  // Количество считываемых элементов
            err = transact(mbBuf, 6)

            if(!err)
                break

            // Delay(100)
        }

        return err
     }

    outputOn(outputNum)
     {
        const onOutput = 0

        if(outputNum <= MAX_OUT)
         {
            SetOutputValue(outputNum, onOutput)
            Diagnost1("Output %d ON", outputNum)
            return 1
         }
        else if(outputNum - MAX_OUT - 1 <= MAX_OUT_SLAVE)
         {
            new ioBuf{128}
            new outputNumSlave = outputNum - MAX_OUT - 1

            setReg(ioBuf, MB_WRITE_START, onOutput)

            new err

            for (new i = 0; i < 5; ++i)
             {
                err = writeRegs(ADDRESS, ioBuf, outputNumSlave, 1)
                
                if ( !err )
                 {
                    Diagnost1("Output slave %d ON", outputNumSlave)
                    return 1
                 }
             }
            
            Diagnostics("ERROR")
            return 0
         }

        Diagnostics("ERROR")
        return 0
     }

    outputOff(outputNum)
     {
        const offOutput = 1

        if(outputNum <= MAX_OUT)
         {
            SetOutputValue(outputNum, offOutput)
            Diagnost1("Output %d OFF", outputNum)
            return 1
         }
        else if(outputNum - MAX_OUT - 1 <= MAX_OUT_SLAVE)
         {
            new ioBuf{128}
            new outputNumSlave = outputNum - MAX_OUT - 1

            setReg(ioBuf, MB_WRITE_START, offOutput)

            new err

            for (new i = 0; i < 5; ++i)
             {
                err = writeRegs(ADDRESS, ioBuf, outputNumSlave, 1)
                
                if ( !err )
                 {
                    Diagnost1("Output slave %d OFF", outputNumSlave)
                    return 1
                 }
             }

            Diagnostics("Output slave %d OFF - ERROR: 0x%x", outputNumSlave, err)
            return 0
         }

        Diagnostics("ERROR")
        return 0
     }

    /*! Управление импульсными реле 
        \param outputNum индекс выхода
        \param delay продолжительность импульса
        */
    makePulse()
     {
        if (GetVar(out_pulse) < 0 || GetVar(out_pulse) > MAX_OUT + MAX_OUT_SLAVE + 1)
            return 0

        if(GetVar(out_pulse) <= MAX_OUT)  // выполняется на мастере
         {
            const offOutput = 1
            const onOutput = 0
            new timeStart = GetVar(UPTIME)

            SetOutputValue(GetVar(out_pulse), onOutput)
            // while (GetVar(UPTIME) - timeStart < GetVar(delay_pulse))  // блокирующий
            //  { }
            Delay(GetVar(delay_pulse))  // не блокирующий
            SetOutputValue(GetVar(out_pulse), offOutput)
            SetVar(out_pulse, -1)
            return 1
         }

        new ioBuf{128}
        new outputNumSlave = GetVar(out_pulse) - MAX_OUT - 1

        sendMakePulse(ADDRESS, ioBuf, outputNumSlave, GetVar(delay_pulse))

        SetVar(out_pulse, -1)
        return 1
     }

    getOutputStatus(outputNum)
     {
        const offOutput = 1

        if(outputNum <= MAX_OUT)
         {
            switch (outputNum)
             {
                case 0: 
                 {
                    Diagnost2("Output %d status: 0x%x", outputNum, GetVar(OUT_0))
                    return GetVar(OUT_0)
                 }
                case 1: 
                 {
                    Diagnost2("Output %d status: 0x%x", outputNum, GetVar(OUT_1))
                    return GetVar(OUT_1)
                 }
                case 2: 
                 {
                    Diagnost2("Output %d status: 0x%x", outputNum, GetVar(OUT_2))
                    return GetVar(OUT_2)
                 }
                case 3: 
                 {
                    Diagnost2("Output %d status: 0x%x", outputNum, GetVar(OUT_3))
                    return GetVar(OUT_3)
                 }
                default:
                 {
                    Diagnostics("\"outputNum\" out of range! - %d", outputNum)
                    return 0xFFFFFFFF
                 }
             }

            return 1
         }
        else if(outputNum - MAX_OUT - 1 <= MAX_OUT_SLAVE)
         {
            new ioBuf{128}
            new outputNumSlave = outputNum - MAX_OUT - 1

            setReg(ioBuf, MB_WRITE_START, offOutput)

            if ( !readRegsOutStatus(ADDRESS, ioBuf, outputNumSlave, 1) )
             {
                new offset = 3
                new res  // = getReg(ioBuf, offset)
                new buf[1]
                buf{2} = ioBuf{offset++}
                buf{3} = ioBuf{offset}
                res = buf[0]

                Diagnost2("Output slave %d status: 0x%x", outputNumSlave, res)
                return res
             }

            Diagnostics("ERROR")
            return 0xFFFFFFFF
         }

        Diagnostics("ERROR")
        return 0xFFFFFFFF
     }
////////////// OUT END //////////////
/////////////////////////////////////


////////////////////////////////////
//////////////// IN ////////////////
    //!  CMD_READ_IN 0x04
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
    //! \param[in] count Количество считываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    readRegsInput(addr, mbBuf{}, fRegAddr, count)
     {
        new err = 1

        for (new i = 0; i < 10; ++i)
        {
            mbBuf{0} = addr
            mbBuf{1} = CMD_READ_IN //Код функции
            setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
            setReg(mbBuf, 4, count) //Количество считываемых элементов
            err = transact(mbBuf, 6)

            if(!err)
                break

            // Delay(100)
        }

        return err
     }

    //!  CMD_READ_IN_STATUS 0x02
    //! \param[in] addr Адрес ведомого устройства
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
    //! \param[in] count Количество считываемых элементов
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
    readRegsInStatus(addr, mbBuf{}, fRegAddr, count)
     {
        new err = 1

        for (new i = 0; i < 10; ++i)
        {
            mbBuf{0} = addr
            mbBuf{1} = CMD_READ_IN_STATUS //Код функции
            setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
            setReg(mbBuf, 4, count) //Количество считываемых элементов
            err = transact(mbBuf, 6)

            if(!err) break

            // Delay(100)
        }

        return err
     }

    getInputStatus(inputNum)
     {
        if(inputNum <= MAX_IN)
        {
            switch (inputNum)
            {
                case 0: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN0))
                    return GetVar(STATUS_OF_IN0)
                }
                case 1: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN1))
                    return GetVar(STATUS_OF_IN1)
                }
                case 2: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN2))
                    return GetVar(STATUS_OF_IN2)
                }
                case 3: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN3))
                    return GetVar(STATUS_OF_IN3)
                }
                case 4: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN4))
                    return GetVar(STATUS_OF_IN4)
                }
                case 5: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN5))
                    return GetVar(STATUS_OF_IN5)
                }
                case 6: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN6))
                    return GetVar(STATUS_OF_IN6)
                }
                case 7: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN7))
                    return GetVar(STATUS_OF_IN7)
                }
                case 8: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN8))
                    return GetVar(STATUS_OF_IN8)
                }
                case 9: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(STATUS_OF_IN9))
                    return GetVar(STATUS_OF_IN9)
                }
                default:
                {
                    Diagnost2("\"inputNum\" out of range! - %d", inputNum)
                    return 0xFFFFFFFF
                }
            }

            return 1
        }
        else if(inputNum - MAX_IN - 1 <= MAX_IN_SLAVE)
        {
            new ioBuf{128}
            new inputNumSlave = inputNum - MAX_IN - 1

            // setReg(ioBuf, MB_WRITE_START, offOutput)
            new err = readRegsInStatus(ADDRESS, ioBuf, inputNumSlave, 1)

            if ( !err )
            {
                new offset = 3
                // new res = getReg(ioBuf, offset)
                new res
                new buf[1]
                buf{2} = ioBuf{offset++}
                buf{3} = ioBuf{offset}
                res = buf[0]
                Diagnost2("Input slave %d status: 0x%X", inputNumSlave, res)
                return res
            }

            Diagnostics("ERROR: 0x%X", err)
            return 0xFFFFFFFF
        }

        Diagnostics("ERROR")
        return 0xFFFFFFFF
     }

    getInput(inputNum)
     {
        if(inputNum <= MAX_IN)
        {
            switch (inputNum)
            {
                case 0: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_0))
                    return GetVar(IN_0)
                }
                case 1: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_1))
                    return GetVar(IN_1)
                }
                case 2: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_2))
                    return GetVar(IN_2)
                }
                case 3: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_3))
                    return GetVar(IN_3)
                }
                case 4: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_4))
                    return GetVar(IN_4)
                }
                case 5: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_5))
                    return GetVar(IN_5)
                }
                case 6: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_6))
                    return GetVar(IN_6)
                }
                case 7: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_7))
                    return GetVar(IN_7)
                }
                case 8: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_8))
                    return GetVar(IN_8)
                }
                case 9: 
                {
                    Diagnost2("Input %d status: 0x%x", inputNum, GetVar(IN_9))
                    return GetVar(IN_9)
                }
                default:
                {
                    Diagnost2("\"inputNum\" out of range! - %d", inputNum)
                    return 0xFFFFFFFF
                }
            }
        }
        else if(inputNum - MAX_IN - 1 <= MAX_IN_SLAVE)
        {
            new ioBuf{128}
            new inputNumSlave = inputNum - MAX_IN - 1

            // setReg(ioBuf, MB_WRITE_START, offOutput)
            new err = readRegsInput(ADDRESS, ioBuf, inputNumSlave, 1)

            if ( !err )
            {
                new offset = 3
                // new res = getReg(ioBuf, offset)
                new res
                new buf[1]
                buf{2} = ioBuf{offset++}
                buf{3} = ioBuf{offset}
                res = buf[0]
                Diagnost2("Input slave %d: 0x%X", inputNumSlave, res)
                return res
            }

            Diagnostics("ERROR: 0x%x", err)
            return 0xFFFFFFFF
        }

        Diagnostics("ERROR")
        return 0xFFFFFFFF
     }
////////////// IN END //////////////
////////////////////////////////////

getSlaveAll(bufAll{})
 {
    new timeStart = GetVar(UPTIME)
    new ioBuf{128}
    new err = 1

    for (new i = 0; i < 10; ++i)
    {
        ioBuf{0} = ADDRESS
        ioBuf{1} = CMD_READ_ALL         // Код функции
        // setReg(mbBuf, 2, fRegAddr)   // Адрес первого регистра
        // setReg(mbBuf, 4, count)      // Количество считываемых элементов
        err = transact(ioBuf, 2)

        if(!err)
        {
            break
        }

        // Delay(100)
    }

    if(err)
    {
        Diagnost1("ERROR: 0x%X")
        return err
    }

    new status = GS_getInt(ioBuf, 3, 6)

    // статусы входов
        new input = 0
        SetVar(em_inStat0, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat1, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat2, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat3, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat4, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat5, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat6, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat7, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat8, (status & (0x01 << input++)) ? 1 : 0)
        SetVar(em_inStat9, (status & (0x01 << input))   ? 1 : 0)

    // статусы выходов
        new out = 16

        new bufOutStat = (status & (0x01 << out++)) ? 1 : 0
        SetVar(em_outStat0, bufOutStat)

        bufOutStat = (status & (0x01 << out++)) ? 1 : 0
        SetVar(em_outStat1, bufOutStat)

        bufOutStat = (status & (0x01 << out++)) ? 1 : 0
        SetVar(em_outStat2, bufOutStat)

        bufOutStat = (status & (0x01 << out++)) ? 1 : 0
        SetVar(em_outStat3, bufOutStat)

    // напряжение на входах
        new count = 7

        for (new input = 0; input <= MAX_IN_SLAVE; ++input)
        {
            new inputValue[1]
            inputValue{2} = ioBuf{count++}
            inputValue{3} = ioBuf{count++}

            switch (input)
            {
                case 0: SetVar(em_inp0, inputValue[0])
                case 1: SetVar(em_inp1, inputValue[0])
                case 2: SetVar(em_inp2, inputValue[0])
                case 3: SetVar(em_inp3, inputValue[0])
                case 4: SetVar(em_inp4, inputValue[0])
                case 5: SetVar(em_inp5, inputValue[0])
                case 6: SetVar(em_inp6, inputValue[0])
                case 7: SetVar(em_inp7, inputValue[0])
                case 8: SetVar(em_inp8, inputValue[0])
                case 9: SetVar(em_inp9, inputValue[0])
            }
        }

    // Diagnost
        Diagnost1("----\ntime: %d", (GetVar(UPTIME) - timeStart))

        // Diagnost1("inStat_0: %d", GetVar(inStat0))
        // Diagnost1("inStat_1: %d", GetVar(inStat1))
        // Diagnost1("inStat_2: %d", GetVar(inStat2))
        // Diagnost1("inStat_3: %d", GetVar(inStat3))
        // Diagnost1("inStat_4: %d", GetVar(inStat4))
        // Diagnost1("inStat_5: %d", GetVar(inStat5))
        // Diagnost1("inStat_6: %d", GetVar(inStat6))
        // Diagnost1("inStat_7: %d", GetVar(inStat7))
        // Diagnost1("inStat_8: %d", GetVar(inStat8))
        // Diagnost1("inStat_9: %d", GetVar(inStat9))

        // Diagnost1("outStat_0: %d", GetVar(outStat0))
        // Diagnost1("outStat_1: %d", GetVar(outStat1))
        // Diagnost1("outStat_2: %d", GetVar(outStat2))
        // Diagnost1("outStat_3: %d", GetVar(outStat3))

        // Diagnost1("inp_0: %d", GetVar(inp0))
        // Diagnost1("inp_1: %d", GetVar(inp1))
        // Diagnost1("inp_2: %d", GetVar(inp2))
        // Diagnost1("inp_3: %d", GetVar(inp3))
        // Diagnost1("inp_4: %d", GetVar(inp4))
        // Diagnost1("inp_5: %d", GetVar(inp5))
        // Diagnost1("inp_6: %d", GetVar(inp6))
        // Diagnost1("inp_7: %d", GetVar(inp7))
        // Diagnost1("inp_8: %d", GetVar(inp8))
        // Diagnost1("inp_9: %d", GetVar(inp9))

        // Diagnost("----\n")

    return err
 }

getOutFlags()
 {
    new flags = GetVar(em_outStat0)
    flags |= ( GetVar(em_outStat1) << 1 )
    flags |= ( GetVar(em_outStat2) << 2 )
    flags |= ( GetVar(em_outStat3) << 3 )

    return flags
 }

setOuts(outsFlags, outsFlagsFackt)
 {
    if (outsFlags == outsFlagsFackt)
    {
        return MB_ERR_OK
    }
    
    new portStatus0 = ( outsFlags & (0x01 << 0) ) ? 1 : 0
    new portStatus1 = ( outsFlags & (0x01 << 1) ) ? 1 : 0
    new portStatus2 = ( outsFlags & (0x01 << 2) ) ? 1 : 0
    new portStatus3 = ( outsFlags & (0x01 << 3) ) ? 1 : 0

    const lenBuf = 64
    const portsCount = 4
    const dataLenPos = 6
    new mbBuf{lenBuf}
    new err = 1

    for (new i = 0; i < 10; ++i)
     {
        mbBuf{0} = ADDRESS
        mbBuf{1} = CMD_SET_OUT //Код функции
        setReg(mbBuf, 2, 0) //Адрес первого порта
        setReg(mbBuf, 4, portsCount) //Количество портов
        mbBuf{dataLenPos} = portsCount * 2
        setReg(mbBuf, 7, portStatus0)
        setReg(mbBuf, 9, portStatus1)
        setReg(mbBuf, 11, portStatus2)
        setReg(mbBuf, 13, portStatus3)
        err = transact(mbBuf, 15)

        if(!err)
        {
            break
        }

        // Delay(100)
     }

    return err
 }


main()
{
    Diagnost("script start")
    modbusInit()
    Delay(10)

    new getAllArr[10]
    getSlaveAll(getAllArr)
    Delay(10)

    // отдельные команды
        // if (GetVar(get_input_status))
        // {
        //     new inputStatus = getInputStatus(GetVar(port_index))
        //     SetVar(input_status, inputStatus)
        //     SetVar(get_input_status, 0)
        // }

        if ( (GetVar(port_index) > 0) && GetVar(flag_getInputValue) )
        {
            new inputV = getInput(GetVar(port_index))
            SetVar(input_value, inputV)
            SetVar(flag_getInputValue, 0)
        }

        // if (GetVar(get_output_status))
        // {
        //     new outputStatus = getOutputStatus(GetVar(port_index))
        //     SetVar(output_status, outputStatus)
        //     SetVar(get_output_status, 0)
        // }

        // if (GetVar(set_output_on))
        // {
        //     outputOn(GetVar(port_index))
        //     SetVar(set_output_on, 0)
        // }

        // if (GetVar(set_output_off))
        // {
        //     outputOff(GetVar(port_index))
        //     SetVar(set_output_off, 0)
        // }

    // new outsFlags = GetVar(em_Outs_Cmd)
    // new outsFlagsFackt = getOutFlags()
    // Diagnost1("outsFlags: 0x%X", outsFlags)
    // Diagnost1("outsFlagsFackt: 0x%X", outsFlagsFackt)

    setOuts( GetVar(em_Outs_Cmd), getOutFlags() )
    makePulse()
}
