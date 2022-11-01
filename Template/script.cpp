//! script_name

// ===========================================================================
//{ Библиотека вспомогательных функций GalileoSky ============================
//{ GalileoSky auxiliary function library ====================================
// ===========================================================================

    /* Возведение в степень --- Exponentiation */
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

    /*! вставить символ в массив, обрабатываемого как строка, ---- inserting a character into an array processed as a string
        и "перевести каретку вперед" (инкрементировать указатель позиции) ---- and "moving the carriage forward" (incrementing the position pointer)
        \param dst{} массив, обрабатываемый как строка ---- an array processed as a string
        \param &d_pos в какой элемент массива записать символ (ПЕРЕДАЕТСЯ ПО ССЫЛКЕ!) ---- an array element where the symbol should be written (TRANSMITTED VIA THE LINK)
        \param d_len длина массива ---- an array length
        \param c переменная (символ) для вставки ---- a variable (symbol) to insert
        \retval не забудьте, что аргумент d_pos будет инкрементирован ---- please note that the d_pos argument will be incremented
    */
    GS_appendC(dst{}, &d_pos, d_len, c)
    {
        if(d_pos < d_len)
        {
            dst{d_pos} = c
            ++d_pos
        }
    }

    /*! вставить массив в другой массив (присоединить строку) ---- inserting an array into a different array (attaching a line)
        и "перевести каретку" (инкрементировать указатель позиции) ---- and "moving the carrier" (incrementing the position pointer)
        \param dst{} массив, куда копируется содержимое второго массива ---- an array, where the contents of the second array are copied to
        \param &d_pos начиная с какого элемента принимающего массива начнется вставка (ПЕРЕДАЕТСЯ ПО ССЫЛКЕ!) ---- an element of a receiving array where the insert is started (TRANSMITTED VIA THE LINK)
        \param d_len длина принимающего массива ---- a receiving array length
        \param src{} массив для вставки ---- an array to be inserted
        \param s_len длина массива для вставки ---- an inserted array length
        \retval не забудьте, что аргумент d_pos будет инкрементирован количество раз, равное длине второго (вставляемого) массива ---- please note that the d_pos argument will be incremented the number of times corresponding to the inserted array length
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

    /*! сравнить строки побайтово ---- comparing lines byte for byte
        \param str1{} первая строка ---- first line
        \param str2{} вторая строка ---- second line
        \param len длина строк (должна быть одинаковой, конечно) ---- lines length (lines should have similar length)
        \retval 0 - строки не равны, 1 - строки равны ---- 0 - lines are equal, 1 - lines are inequal
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

    /*! копировать строки побайтово ---- copy lines byte for byte
        \param dest{} куда копировать ---- where to copy
        \param source{} откуда копировать ---- from where to copy
        \param len длина строк (должна быть одинаковой, конечно) ---- lines length (lines should have similar length)
        \param destPos смещение ---- offset
        \param sourcePos смещение ---- offset
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

    /*! Алгоритм прямого поиска ---- Direct search algorithm
      / string1 - где искать ---- where to search
      / string2 - что искать ---- what to search for
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

    /*! Собирает число из строки ---- Collecting a number from the string*/ 
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

    /*! смещает массив вправо максимум на 8 бит ---- array offset to the right by a maximum of 8 bits*/
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

    /*! смещает массив вправо ---- array offset to the right
    *   использует GS_offsetArrRight8() ---- using GS_offsetArrRight8()
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

    /*! собирает INT32 из байт массива. Максимум на 32 бита ---- collecting INT32 from array bytes. 32 bits at maximum*/
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
//} The end of GalileoSky auxiliary function library =========================
// ===========================================================================


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
///////////////// DIAGNOSTICS END //////////////////////
////////////////////////////////////////////////////////

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
////////////// OUT END //////////////
/////////////////////////////////////


main()
{
	Diagnost("\nStart script: script_name\nv.0.0.0")
}
