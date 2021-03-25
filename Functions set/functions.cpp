193.193.165.165
GS7 порт 21423 
BB  порт 21177

/*! Теги Виалон (Идентификаторы пользовательского массива):"
    0x01 зарезервирован
    0x02 данные счетчика Меркурий
    0x03 данные тахографа
    0x04 устройство СЕНС
    0x05 устройство СКВТ-М (в разработке)
    0x06 Система измерения давления в шинах (TPMS) датчик TD5300A-X-04
    0x07 Расходомер Eurosens Delta
    0x08 Частота с ДУТ
    0x09 данные с электросчетчиков
    0x0A датчики пассажиропотока
    0x0B адаптер ЛИН-RS485 для устройств СЕНС
    0x0C Информация от VIMS
    0x0D Maple (ответы на команды)
    0x0E зарезервирован
    0x0F зарезервирован
    0xEE Текстовые данные
    */

/*! номера ошибок в ИЗИ ЛОДЖИК
    AMX_ERR_NONE,
    // reserve the first 15 error codes for exit codes of the abstract machine
    AMX_ERR_EXIT,         // forced exit /
    AMX_ERR_ASSERT,       // assertion failed /
    AMX_ERR_STACKERR,     // stack/heap collision /
    AMX_ERR_BOUNDS,       // index out of bounds /
    AMX_ERR_MEMACCESS,    // invalid memory access /
    AMX_ERR_INVINSTR,     // invalid instruction /
    AMX_ERR_STACKLOW,     // stack underflow /
    AMX_ERR_HEAPLOW,      // heap underflow /
    AMX_ERR_CALLBACK,     // no callback, or invalid callback /
    AMX_ERR_NATIVE,       // native function failed /
    AMX_ERR_DIVIDE,       // divide by zero /
    AMX_ERR_SLEEP,        // go into sleepmode - code can be restarted /
    AMX_ERR_INVSTATE,     // no implementation for this state, no fall-back /

    AMX_ERR_MEMORY = 16,  // out of memory /
    AMX_ERR_FORMAT,       // invalid file format /
    AMX_ERR_VERSION,      // file is for a newer version of the AMX /
    AMX_ERR_NOTFOUND,     // function not found /
    AMX_ERR_INDEX,        // invalid index parameter (bad entry point) /
    AMX_ERR_DEBUG,        // debugger cannot run /
    AMX_ERR_INIT,         // AMX not initialized (or doubly initialized) /
    AMX_ERR_USERDATA,     // unable to set user data field (table full) /
    AMX_ERR_INIT_JIT,     // cannot initialize the JIT /
    AMX_ERR_PARAMS,       // parameter error /
    AMX_ERR_DOMAIN,       // domain error, expression result does not fit in range /
    AMX_ERR_GENERAL,      // general error (unknown or unspecific error) /
    AMX_ERR_OVERLAY,      // overlays are unsupported (JIT) or uninitialized
    */

/*! Частые команды:
    fslist /Pic

    reset

    clearscript
    clearscript MOD_CAM1
    clearscript Camera_JC029F-Y01

    script
    script PBscaleRequest

    upgrade 23

    makephoto 0
    CLEANPHOTOQUEUE

    status
    imei

    erasecfg

    log
        битовые флаги:
            _CRERR = 0      , //0
            _TEST_O         , //1  тест прибора включен
            _RESERV0        , //2
            _RESERV1        , //3
            _RESERV2        , //4
            //---------------
            _STAR           , //5  выводится всегда звезда
            _TIME           , //6  периодический вывод времени (период 10 секунд)
            //---------------
            _GPS            , //7  обычная диагностика GPS
            _GPS_F          , //8  полная диагностика GPS
            //---------------
            _GPRS           , //9  обычная диагностика GPRS
            _GPRS_F         , //10 полная диагностика GPRS
            //---------------
            _MEM            , //11 обычная диагностика памяти треков
            _MEM_F          , //12 полная диагностика памяти треков
            //---------------
            _AUTOINF        , //13
            _WIFI           , //14
            //---------------
            _CAN            , //15
            _CAN_F          , //16
            //---------------
            _RS232_0        , //17
            _868RADIO       , //18
            //---------------
            _RS232_1        , //19
            _RS232_1_F      , //20
            //---------------
            _GPS_O          , //21 только диагностика GPS
            _GPRS_O         , //22 только диагностика GPRS
            _1WIRE          , //23
            _ACC            , //24
            _SPUTNIK        , //25
            _USER_SPACE     , //26
            _USER_SPACE_DIAG, //27 == 134217728
            _RS485          , //28
            _BT               //29
    */

//=============================================
//============== тэги для записи ==============
//=============================================
    // CAN 8 BIT R ..
    #define CAN8BITR_0 0x02
    #define CAN8BITR_1 0x03
    #define CAN8BITR_2 0x04
    #define CAN8BITR_3 0x05
    #define CAN8BITR_4 0x06
    #define CAN8BITR_5 0x07
    #define CAN8BITR_6 0x08
    #define CAN8BITR_7 0x09
    #define CAN8BITR_8 0x0A
    #define CAN8BITR_9 0x0B
    #define CAN8BITR_10 0x0C
    #define CAN8BITR_11 0x0D
    #define CAN8BITR_12 0x0E
    #define CAN8BITR_13 0x0F
    #define CAN8BITR_14 0x10
    #define CAN8BITR_15 0x3D
    #define CAN8BITR_16 0x3E
    #define CAN8BITR_17 0x3F
    #define CAN8BITR_18 0x40
    #define CAN8BITR_19 0x41
    #define CAN8BITR_20 0x42
    #define CAN8BITR_21 0x43
    #define CAN8BITR_22 0x44
    #define CAN8BITR_23 0x45
    #define CAN8BITR_24 0x46
    #define CAN8BITR_25 0x47
    #define CAN8BITR_26 0x48
    #define CAN8BITR_27 0x49
    #define CAN8BITR_28 0x4A
    #define CAN8BITR_29 0x4B
    #define CAN8BITR_30 0x4C

    // CAN 16 BIT R ..
    #define CAN16BITR_0 0x11
    #define CAN16BITR_1 0x12
    #define CAN16BITR_2 0x13
    #define CAN16BITR_3 0x14
    #define CAN16BITR_4 0x15
    #define CAN16BITR_5 0x4D
    #define CAN16BITR_6 0x4E
    #define CAN16BITR_7 0x4F
    #define CAN16BITR_8 0x50
    #define CAN16BITR_9 0x51
    #define CAN16BITR_10 0x52
    #define CAN16BITR_11 0x53
    #define CAN16BITR_12 0x54
    #define CAN16BITR_13 0x55
    #define CAN16BITR_14 0x56

    // CAN 32 BIT R ..
    #define CAN32BITR_0 0x16
    #define CAN32BITR_1 0x17
    #define CAN32BITR_2 0x18
    #define CAN32BITR_3 0x19
    #define CAN32BITR_4 0x1A
    #define CAN32BITR_5 0x57
    #define CAN32BITR_6 0x58
    #define CAN32BITR_7 0x59
    #define CAN32BITR_8 0x5A
    #define CAN32BITR_9 0x5B
    #define CAN32BITR_10 0x5C
    #define CAN32BITR_11 0x5D
    #define CAN32BITR_12 0x5E
    #define CAN32BITR_13 0x5F
    #define CAN32BITR_14 0x60


    // Users Tags
    #define UserTag_0 0x62
    #define UserTag_1 0x63
    #define UserTag_2 0x64
    #define UserTag_3 0x65
    #define UserTag_4 0x66
    #define UserTag_5 0x67
    #define UserTag_6 0x68
    #define UserTag_7 0x69

    #define UserArray 0x6A


    #define CAN_A_0 0x6C
    #define CAN_A_1 0x6D
    #define CAN_B_0 0x6E
    #define CAN_B_1 0x6F

    // BLUETOOTH
    #define BLUE_TOOTH_0 0x70
    #define BLUE_TOOTH_1 0x71
    #define BLUE_TOOTH_2 0x72
    #define BLUE_TOOTH_3 0x73
    #define BLUE_TOOTH_4 0x74
    #define BLUE_TOOTH_5 0x75
    #define BLUE_TOOTH_6 0x76
    #define BLUE_TOOTH_7 0x77
    #define BLUE_TOOTH_8 0x78
    #define BLUE_TOOTH_9 0x79

    #define BLUE_TOOTH_10 0x7A
    #define BLUE_TOOTH_11 0x7B
    #define BLUE_TOOTH_12 0x7C
    #define BLUE_TOOTH_13 0x7D
    #define BLUE_TOOTH_14 0x7E
    #define BLUE_TOOTH_15 0x7F
    #define BLUE_TOOTH_16 0x80
    #define BLUE_TOOTH_17 0x81
    #define BLUE_TOOTH_18 0x82
    #define BLUE_TOOTH_19 0x83

    #define BLUE_TOOTH_20 0x84
    #define BLUE_TOOTH_21 0x85
    #define BLUE_TOOTH_22 0x86
    #define BLUE_TOOTH_23 0x87
    #define BLUE_TOOTH_24 0x88
    #define BLUE_TOOTH_25 0x89
    #define BLUE_TOOTH_26 0x8A
    #define BLUE_TOOTH_27 0x8B
    #define BLUE_TOOTH_28 0x8C
    #define BLUE_TOOTH_29 0x8D

    #define BLUE_TOOTH_30 0x8E
    #define BLUE_TOOTH_31 0x8F
    #define BLUE_TOOTH_32 0x90
    #define BLUE_TOOTH_33 0x91
    #define BLUE_TOOTH_34 0x92
    #define BLUE_TOOTH_35 0x93
    #define BLUE_TOOTH_36 0x94
    #define BLUE_TOOTH_37 0x95
    #define BLUE_TOOTH_38 0x96
    #define BLUE_TOOTH_39 0x97
    
    #define BLUE_TOOTH_40 0x98
    #define BLUE_TOOTH_41 0x99
    #define BLUE_TOOTH_42 0x9A
    #define BLUE_TOOTH_43 0x9B
    #define BLUE_TOOTH_44 0x9C
    #define BLUE_TOOTH_45 0x9D
    #define BLUE_TOOTH_46 0x9E
    #define BLUE_TOOTH_47 0x9F
    #define BLUE_TOOTH_48 0xA0
    #define BLUE_TOOTH_49 0xA1
    
    #define BLUE_TOOTH_50 0xA2
    #define BLUE_TOOTH_51 0xA3
    #define BLUE_TOOTH_52 0xA4
    #define BLUE_TOOTH_53 0xA5
    #define BLUE_TOOTH_54 0xA6
    #define BLUE_TOOTH_55 0xA7
    #define BLUE_TOOTH_56 0xA8
    #define BLUE_TOOTH_57 0xA9
    #define BLUE_TOOTH_58 0xAA
    #define BLUE_TOOTH_59 0xAB

    #define BLUE_TOOTH_60 0xAC
    #define BLUE_TOOTH_61 0xAD
    #define BLUE_TOOTH_62 0xAE
    #define BLUE_TOOTH_63 0xAF
//=============================================
//============== тэги для чтения ==============
//=============================================
    // USER_TAG0
    // USER_TAG1
    // USER_TAG2
    // USER_TAG3
    // USER_TAG4
    // USER_TAG5
    // USER_TAG6
    // USER_TAG7

    // IBUTTON

    // BLUETOOTH_0
    // BLUETOOTH_1
    // BLUETOOTH_№..
    // BLUETOOTH_62
    // BLUETOOTH_63
    //=============================================
    // === в остальных просто убрать последнее ====
    // ========== нижнее подчёркивание ============
    //=============================================

// Встроенные функции
    Delay(const value);
    /*Задержка работы алгоритма
    value время задержки в миллисекундах*/

    SavePoint();
    /*Сохранение точки в архиве*/

    min(const value1, const value2);
    /*Получить минимум из двух значений
    value1 значение 1
    value2 значение 2
    \return минимум из двух значений*/

    Rand(const min, const max);

    swapBuf(buf{}, const size);
    /*Инвертировать каждые 4 байта массива
    //!
    Преобразование LittleEndiang<->BigEndian
    \param[inout] buf{} буфер для преобразования
    size размер буфера*/

    getIntFromBuf(const buf{}, const index);
    /*Получить число (4-х-байтовый int) из буфера по позиции
    //!
    Число в буфере извлечено в формате LittleEndian
    buf{} буфер, из которого будет извлекаться число
    index индекс байта, начиная с которого располагается число в массиве
    \return число, извлечённое из буфера*/

    GetIMEI(res[], const resSize);
    /*Получим IMEI*/

    GetUnsentPackets();
    /*Получить количество еще не отправленных пакетов. Работает только при отправке пакетов в хронологическом порядке*/

    NewPhoto(const filename[]);
    /*Оповещение прошивки, что сделан новый снимок фотокамерой
    filename полное имя файла*/

    PlayAudio(const filename[]);
    /*Воспроизвести аудио файл
    filename полное имя файла*/

    setAutoinformerRoute(Dir[]);
    /*Переключаем маршрут в Автоинформаторе*/

    // Diagnostics
        Diagnostics(const message[], ...);
        /*Вывод строчки в Диагностику алгоритмов
        message Сообщение для вывода, например "Var1=%d, Var2=%d" (см. printf)
        ... Можно указывать два дополнительных параметра для вставки в сообщение: "%d" вывод целого числа
        Старайтесь выводить диагностику короткими строчками
        Например: Diagnostics("Dev. Req.: %d", REQUEST_SIZE)
        Это уменьшит размер скрипта и скорость вывода диагностики*/

        DiagnosticsHex(const buf[], const size);
        /*Вывод массива в Диагностику алгоритмов в шестнадцатеричном виде
        buf[] буфер выводимого массива
        size размер буфера*/

    // Inputs
        DisablePulseCounting(const inputNum, const disabled);
        /*Отключение подсчёта импульсов на входе
        inputNum номер входа, на котором будет произведено обнуление счётчика
        disabled true - отключить подсчёт импульсов
        disabled false - включить подсчёт импульсов*/

        NullInput(const inputNum);
        /*Обнуление счётчика на входе
        inputNum номер входа, на котором будет произведено обнуление счётчика*/

        SetOutputValue(const outputNum, const value);
        /*Установить состояние выхода
        outputNum номер выхода
        value устанавливаемое состояние*/

    // Variables
        GetVar(const name);
        /*Получение тега, значения глобальной или системной переменной
        name Имя переменной
        \return значение указанной переменной*/

        SetVar(const name, const value);
        /*Установка значения глобальной или системной переменной
        name Имя переменной
        value устанавливаемое значение*/

    // Tags write
        TagWriteValue(const index, const value);
        /*Запись значения в тег пользователя
        index индекс тега пользователя
        Индеск может принимать значения из диапазона `0x62` - `0x69`
        value записываемой значение*/

        TagWriteArray(const index, ...);
        /*Запись буфера данных в массив пользователя
        index индекс массива пользователя.
        Индекс должен быть равен `0x6A`
        size размер буфера данных
        buf буфер данных*/

    // Digital ports
        PortInit(const index, const speed, const bufSize);
        /*Инициализация порта
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        speed port speed: 19200
        bufSize size of input buffer
        stopBits количество стоповых бит:
            0 - 1 стоповый бит (по умолчанию)
            1 - 2 стоповых бита
        parity контроль по чётности:
            0 - без контроля чётности (по умолчанию)
            1 - контроль по нечётности - odd
            2 - контроли по чётности - even
        packetMode контроль по чётности:
            0 - без разделения на пакеты (по умолчанию)
            1 - с разделением на пакеты, временной интервал между пакетами составляет 729 мс*/

        PortRead(const index, &char, const timeout);
        /*Чтение символа из порта
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        \param[out] char received character
        timeout wait timeout of the next character
        \retval 0 - символ не прочитан по истечении тайм-аута
        \retval !=0 - символ прочитан*/

        PortWrite(const index, const buf[], const size);
        /*Запись данных из буфера в порт
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        buf buffer to send
        size buffer size*/

        PortReadPackage(const index, &char, const timeout);
        /*Чтение пакетов из порта, разделённых по временной задержке
        index port index: 2 - RS485 (пока реализовано только для RS485)
        buf указатель на буфер под полученный пакет
        \param[in] bufSize размер переданного буфера
        \param[in] firstByteTimeout время ожидания первого байта, мс
        \param[in] nextByteTimeout время ожидания последующего байта, мс
        \return количество прочитанных символов в пакете*/

    // CRC
        CRC16(const buf[], const size, const crcinit);  // CRC-16-CCITT см. ниже
        /*Подсчёт CRC-16
        buf буфер для подсчёта
        size размер буфера
        crcinit начальное значение CRC, по умолчанию 0xFFFF
        \return посчитанное значение CRC16*/

        CRC8(const crcInit], const buf[], const size);
        /*Подсчёт CRC-8 по полиному x^8 + x^7 + x^4 + x^0 (0x91)
        //!
        Посчёт CRC-8 буфера \a buf длиной \a size.
        Начальное значение CRC8 устанавливается в \a crcInit.
        Значение CRC-8 вычисляется, как разность 0xFF и результата данной функции CRC8()
        crcInit начальное значение CRC
        buf[] буфер для подсчёта
        size размер буфера
        \return посчитанное значение CRC8*/

        CRC8_D5(const buf[], const size);
        /*Подсчёт CRC-8 по полиному 0xD5
        //!
        Посчёт CRC-8 буфера \a buf длиной \a size.
        buf[] буфер для подсчёта
        size размер буфера
        \return посчитанное значение CRC8*/

    // CD-card
        NextDir(const rootDir[], const lastDir[], res[], const resSize);
        /*Ищем следующий каталог за заданным*/

        FileSize(const filename[]);
        /*Получить размер файла
        filename полное имя файла
        \return размер файла, -1 - если файл не найден*/

        FileRead(const filename[], buf[], const bufSize, const offset = 0);
        /*Прочитать со смещением из файла в массив
        filename полное имя файла
        buf массив-приёмник
        bufSize размер массива-приемника
        offset смещение в файле, указывающее откуда начинать чтение
        \return фактическое количество прочитанных байт*/

        FileWrite(const filename[], const buf[], const bufSize, const offset = -1);
        /*Записать массив в файл со смещением
        filename полное имя файла
        buf массив-источник
        bufSize размер массива-источника
        offset смещение в файле, указывающее откуда начинать запись. -1 - записывать в конец файла
        \return фактическое количество записа байт*/

        FileDelete(const filename[]);
        /*Удалить файл
        filename полное имя файла
        \return логическое значение операции удаления файла*/

    // Coordinates
        InZone(const lat, const lon, const angle, const delta, const radExt, const radInt);
        /*Проверим находимся ли мы сейчас в геозоне автоинформатора*/
        
        SetFlagOfInvalidCoordinates(const enable);

    // Command
        ExecCommand(Cmd[]);
        /*Выполнить команду*/

        GetBinaryDataFromCommand(buf[], const bufSize);
        /*получить бинарные данные из принятой команды
        buf массив-приемник
        bufSize размер массива-приемника*/

        SendAnswer(const connectionId, const commandIndex, const answerBuf[], const answerSize, const dataBuf[], const dataSize);
        /*Послать ответ на команду полученную от сервера мониторинга
        connectionId идентификатор соединения
        commandIndex номер команды, получаемый в теге `0xE0`
        answerBuf буфер ответа, содержащий ответ на команду. Подразумевается ответ в виде текста, передаваемый в теге `0xE1`
        answerSize размер буфера ответа
        dataBuf буфер данных, содержащий двоичные данные. Передаются в теге `0xEB`
        dataSize размер буфера данных. Если равен нулю, то тег с данными в ответе не передаётся*/

    // CAN
        CANInit(speed, active);
        /*Инициализировать CAN шину*/

        CANEnableReception(enable);
        /*Включить приём сообщений*/

        CANSetFilter(id, mask, type);
        /*Установить фильтр*/

        CANSend(const msg[CANMSG]);
        /*Послать сообщений*/

        CANReceive(msg[CANMSG]);
        /*Принять сообщение*/

    // TCP
        SocketOpen(const address[], const port, const timeout);
        /*Открыть сокет и подключиться к серверу
        const address[]
        const port
        const timeout*/

        SocketSend(const src[], const bytesToSend, &bytesSent, const timeout);
        /*Отправить данные в ранее открытый сокет
        const src[]
        const bytesToSend
        &bytesSent
        const timeout*/

        SocketRecv(const dest[], const bufSize, &bytesRcvd, const timeout);
        /*Получить данные из ранее открытого сокета
        dest[]
        const bufSize
        &bytesRcvd
        const timeout*/

        SocketClose();
        /*Отключиться от сервера и закрыть сокет*/

    // BLUETOOTH
        BTInit();

        BTReceive(msg[BTMSG], const timeout);

// ===========================================================================
//{ Библиотека вспомогательных функций GalileoSky ============================
// ===========================================================================
    /*! более точный */
    delayTime(time)
     {
        const step = 10;

        new startTime = GetVar(UPTIME)

        while ( GetVar(UPTIME) - startTime <= time )
         {
            Delay(step)
         }

        diagnost1( "delay: %d ms", GetVar(UPTIME) - startTime );
     }

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

    /*! Возвращает длину строки заканчивающуюся нулевым байтом.
        \param buf{} измеряемая строка
        \param bufsize размер буфера с текстом
        \retval количество байт до 0x00
        */
    GS_strlen(buf{}, bufsize)
     {
        new i = 0

        while(buf{i++} != 0)
        {
            if(bufSize <= i)
            {
                return -1;
            }
        }
        
        return i
     }

    /*! Возвращает строку из файла
        \param file имя файла
        \param pos номер байта начала строки
        \param dst буфер строки
        \param dst_size размер буфера строки
        \return length строки
        */
    GS_readLine(file{}, pos, dst{}, dst_size)
     {
        const cr_symbol = 0x0D; // CR
        const lf_symbol = 0x0A; // LF

        new len = FileRead(file, dst, dst_size, pos)

        if (len <= 0)
        {
            return 0
        }

        new counter = 0;

        while (counter < dst_size)
        {
            if ( (dst{counter} == cr_symbol) || (counter + 1 < dst_size) || (dst{counter + 1} == lf_symbol) )
            {
                dst{counter} = 0
                return counter
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

    /*! Проверяет является ли символ цифрой в формате ASCII
        \param byte предполагаемый символ цифры в ASCII
        \return bool
        */
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

    /*! Возвращает int из цифры в формате ASCII
        \param byte символ цифры в ASCII
        \return int
        */
    GS_getDigit(byte)
     {
        return byte - 0x30
     }

    /*! Возвращает int */
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
        \param string1 - где искать
        \param str1Len длина строки string1
        \param string2 - что искать
        \param str2Len длина строки string2
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

    /*! Собирает число из строки
        \param str{} строка символов
        \param &pos индекс начала чтения строки
        \return int
        */
    GS_atoi(str{}, &pos)
     {
        new value = 0
        new is_minus = false

        if(str{pos} == 0)
        {
            return 0
        }

        if (str{pos} == '-') 
        {
            is_minus = true
            pos++
        }

        while(GS_isDigit(str{pos}))
        {
            value = value * 10 + GS_getDigit(str{pos})
            ++pos
        }

        if(is_minus)
        {
            return -value
        }

        return value
     }

    /*! Собирает число из строки
        \param str{} строка символов
        \param &pos индекс начала чтения строки
        \param precision требуемая точность до Х хнака после запятой
        \param sep символ разделитель. Например '.' или ','
        \return int 
        */
    GS_atof(str{}, &pos, precision, sep) 
     {
        new value = GS_atoi(str, pos)
        new i = 0

        if(str{pos} == sep)
        {
            ++pos

            for(; i < precision; ++i)
            {
                if(GS_isDigit(str{pos}))
                {
                    value = value * 10 + GS_getDigit(str{pos})
                }
                else
                {
                    break;
                }

                ++pos
            }       
        }

        for(; i < precision; ++i)
        {
            value = value * 10
        }

        while(GS_isDigit(str{pos}))
        {
            ++pos
        }

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

    /*! Очистка массива */
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

    /*! Запись значения в BLUETOOTH_тег
        \param index номер тега от 0 до 63
        \param value записываемое значение
        \return boolean
        */
    GS_tagBluetoothWriteValue(index, value)
     {
        if (index < 0 || index > 63)
         {
            return false;
         }

        TagWriteValue(0x70 + index, value);
        return true;
     }

    /*! Чтение значения из BLUETOOTH_тега
        \param index номер тега от 0 до 63
        \return boolean
        */
    GS_tagBluetoothReadValue(index)
     {
        if (index < 0 || index > 63)
         {
            return false;
         }

        switch (index)
         {
            case 0: { GetVar(BLUETOOTH_0) }
            case 1: { GetVar(BLUETOOTH_1) }
            case 2: { GetVar(BLUETOOTH_2) }
            case 3: { GetVar(BLUETOOTH_3) }
            case 4: { GetVar(BLUETOOTH_4) }
            case 5: { GetVar(BLUETOOTH_5) }
            case 6: { GetVar(BLUETOOTH_6) }
            case 7: { GetVar(BLUETOOTH_7) }
            case 8: { GetVar(BLUETOOTH_8) }
            case 9: { GetVar(BLUETOOTH_9) }

            case 10: { GetVar(BLUETOOTH_10) }
            case 11: { GetVar(BLUETOOTH_11) }
            case 12: { GetVar(BLUETOOTH_12) }
            case 13: { GetVar(BLUETOOTH_13) }
            case 14: { GetVar(BLUETOOTH_14) }
            case 15: { GetVar(BLUETOOTH_15) }
            case 16: { GetVar(BLUETOOTH_16) }
            case 17: { GetVar(BLUETOOTH_17) }
            case 18: { GetVar(BLUETOOTH_18) }
            case 19: { GetVar(BLUETOOTH_19) }

            case 20: { GetVar(BLUETOOTH_20) }
            case 21: { GetVar(BLUETOOTH_21) }
            case 22: { GetVar(BLUETOOTH_22) }
            case 23: { GetVar(BLUETOOTH_23) }
            case 24: { GetVar(BLUETOOTH_24) }
            case 25: { GetVar(BLUETOOTH_25) }
            case 26: { GetVar(BLUETOOTH_26) }
            case 27: { GetVar(BLUETOOTH_27) }
            case 28: { GetVar(BLUETOOTH_28) }
            case 29: { GetVar(BLUETOOTH_29) }

            case 30: { GetVar(BLUETOOTH_30) }
            case 31: { GetVar(BLUETOOTH_31) }
            case 32: { GetVar(BLUETOOTH_32) }
            case 33: { GetVar(BLUETOOTH_33) }
            case 34: { GetVar(BLUETOOTH_34) }
            case 35: { GetVar(BLUETOOTH_35) }
            case 36: { GetVar(BLUETOOTH_36) }
            case 37: { GetVar(BLUETOOTH_37) }
            case 38: { GetVar(BLUETOOTH_38) }
            case 39: { GetVar(BLUETOOTH_39) }

            case 40: { GetVar(BLUETOOTH_40) }
            case 41: { GetVar(BLUETOOTH_41) }
            case 42: { GetVar(BLUETOOTH_42) }
            case 43: { GetVar(BLUETOOTH_43) }
            case 44: { GetVar(BLUETOOTH_44) }
            case 45: { GetVar(BLUETOOTH_45) }
            case 46: { GetVar(BLUETOOTH_46) }
            case 47: { GetVar(BLUETOOTH_47) }
            case 48: { GetVar(BLUETOOTH_48) }
            case 49: { GetVar(BLUETOOTH_49) }

            case 50: { GetVar(BLUETOOTH_50) }
            case 51: { GetVar(BLUETOOTH_51) }
            case 52: { GetVar(BLUETOOTH_52) }
            case 53: { GetVar(BLUETOOTH_53) }
            case 54: { GetVar(BLUETOOTH_54) }
            case 55: { GetVar(BLUETOOTH_55) }
            case 56: { GetVar(BLUETOOTH_56) }
            case 57: { GetVar(BLUETOOTH_57) }
            case 58: { GetVar(BLUETOOTH_58) }
            case 59: { GetVar(BLUETOOTH_59) }

            case 60: { GetVar(BLUETOOTH_60) }
            case 61: { GetVar(BLUETOOTH_61) }
            case 62: { GetVar(BLUETOOTH_62) }
            case 63: { GetVar(BLUETOOTH_63) }
         }
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

// Таймер и его функции
    /*! закончился таймер или нет */
    isTimerExpired()
     {
        return (GetVar(glTimer) <= GetVar(UNIX_TIME))
     }

    /*! запустить таймер на value секунд
        \param value секунды
        */
    setTimer(value)
     {
        SetVar(glTimer, GetVar(UNIX_TIME) + value)
     }

    /*! сбросить таймер */
    unsetTimer()
     {
        SetVar(glTimer, 0)
     }

//!*************************************************************
//!-----------------Библиотека работы с Modbus------------------
//!*************************************************************
    //! Порт подключения шины Modbus
    #define MB_PORT_INDEX 2

    //! Скорость подключения по шине Modbus
    #define MB_PORT_SPEED 19200    

    //! Количество стопбит
    #define MB_PORT_STOP 0  

    //! Размер буфера для обмена по шине Modbus
    #define MB_BUF_SIZE 256

    //! Таймаут ожидания ответа слейва, мс
    #define MB_TIMEOUT 10000

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

    /*! Запись значения 16-битного регистра в буфер в формате Modbus
        \param[in] mbBuf Буфер, куда производится запись
        \param[in] offset Смещение указателя записи от начала буфера
        \param[in] value Значение записываемого регистра
        */
    setReg(mbBuf{}, offset, value)
     {
        mbBuf{offset} = value >> 8 //Старший байт вперед
        mbBuf{offset + 1} = value //Младший байт
     }

    /*! Функция возвращает значения 16-битного регистра Modbus из буфера
        \param[in] mbBuf Буфер, откуда производится чтение
        \param[in] offset Смещение указателя чтения от начала буфера
        \return Конвертированное значение регистра
        */
    getReg(mbBuf{}, offset)
     {
        return mbBuf{offset} * 256 + mbBuf{offset + 1}
     }

    /*! Функция возвращает значения 32-битного регистра Modbus из буфера
        \param[in] mbBuf Буфер, откуда производится чтение
        \param[in] offset Смещение указателя чтения от начала буфера
        \return Конвертированное значение регистра
        */
    getReg32(mbBuf{}, offset)
     {
        return (mbBuf{offset} << 24) + (mbBuf{offset + 1} << 16) + (mbBuf{offset + 2} << 8) + (mbBuf{offset + 3})
     }

    /*! 0x03 - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)
        \param[in] addr Адрес ведомого устройства
        \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
        \param[in] count Количество считываемых элементов
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
        */
    readRegs(addr, mbBuf{}, fRegAddr, count)
     {
        mbBuf{0} = addr
        mbBuf{1} = 0x03 //Код функции
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
        setReg(mbBuf, 4, count) //Количество считываемых элементов
        return transact(mbBuf, 6)
     }

    /*! 0x04 - Функция чтение значений из нескольких регистров хранения (Read Input Registers)
        \param[in] addr Адрес ведомого устройства
        \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать
        \param[in] count Количество считываемых элементов
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
        */
    readRegsIn(addr, mbBuf{}, fRegAddr, count)
     {
        mbBuf{0} = addr
        mbBuf{1} = 0x04 //Код функции
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента
        setReg(mbBuf, 4, count) //Количество считываемых элементов
        return transact(mbBuf, 6)
     }

    /*! 0x10 - Функция записи значений в несколько регистров хранения (Preset Multiple Registers)
        Функция заполнит заголовок буфера и отправит его в шину, полезные данные требуется располагать
        начиная с позиции \a MB_WRITE_START. Записываемые значения все 16-битные
        \param[in] addr Адрес ведомого устройства
        \param[in] mbBuf Буфер обмена, который будет отправлен
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется записать
        \param[in] count Количество записываемых элементов
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
        */
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
    /*! Обмен с устройством данными по шине
        \param[inout] mbBuf Буфер обмена, данные из него будут записаны с добавленной CRC, и в него будут считан ответ без CRC
        \param[inout] size Размер буфера обмена
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно
        */
    transact(mbBuf{}, size)
     {    
        //Добавляем CRC
        new c = CRC16(mbBuf, size)
        mbBuf{size} = c
        mbBuf{size + 1} = c >> 8
        //Пишем в порт
        PortWrite(MB_PORT_INDEX, mbBuf, size + 2)
        //Размер ответа, для записывающих команд размер известен из стандарта
        new ansSize = (mbBuf{1} > 4) ? 8 : MB_BUF_SIZE + 1
        //Слушаем ответ
        new err = 0
        new bytesRead = 0  
        c = 0    
        while (PortRead(MB_PORT_INDEX, c, MB_TIMEOUT))
        {
            mbBuf{bytesRead} = c
            bytesRead++

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
                    if (ansSize == MB_BUF_SIZE + 1) //Считываем размер только для операций чтения
                        ansSize = 3 + c + 2
                }
            }
        }    
        //Сверяем целевой и фактический размеры ответа
        if (ansSize != bytesRead)
        {
            Diagnostics("Mer[%d]", MB_ERR_SIZE)
            Diagnostics("aS:%d != br:%d", ansSize, bytesRead)
            
            return MB_ERR_SIZE
        }

        printData(mbBuf, bytesRead)
        //Проверяем CRC
        c = mbBuf{ansSize - 2} + mbBuf{ansSize - 1} * 256
        if (c != CRC16(mbBuf, ansSize - 2))
            return MB_ERR_CRC
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
    #define BOUD_RATE 9600
    #define PORT_INDEX 2  // RS485
    #define BUF_SIZE 300
    #define STOP_BITS 0 // 0 - 1 stop bit
    #define PARITY 0  // no parity bits

    /*! инициализация порта */
    serialInit()
     {
        diagnost0("serialInit()")
        PortInit(PORT_INDEX, BAUDRATE, BUF_SIZE, STOP_BITS, PARITY)
     }

    /*! запись в порт
        \param ioBuf{} буфер с данными для отправки в порт
        \param ioBufSize количество байт для отправки в порт
        */
    serialWrite(ioBuf{}, ioBufSize)
     {
        diagnost0("Serial write:")
        diagnostHex(ioBuf, ioBufSize)
        PortWrite(PORT_INDEX, ioBuf, ioBufSize)
     }

    /*! чтение пакетов из порта, разделённых по временной задержке
        \param ioBuf{} буфер для полученных данных
        \param bufSize размер буфера
        \param firstByteTimeout время ожидания первого байта
        \param nextByteTimeout время ожидания остальных байт
        \return int количество прочитанных байт
        */
    serialRead(ioBuf{}, bufSize, firstByteTimeout, nextByteTimeout)
     {
        diagnost0("serialRead()")
        new count = 0

        if (2 == PORT_INDEX)  // пока реализовано только для RS485
        {
            count = PortReadPackage(PORT_INDEX, ioBuf, bufSize, firstByteTimeout, nextByteTimeout)
            diagnost1("serialRead %d byts", count)
            diagnostHex(ioBuf, count)
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

        diagnost1("serialRead %d byts:", count)
        diagnostHex(ioBuf, count)
        return count
     }
///////////////// SERIAL END /////////////
//////////////////////////////////////////

////////////////////////////////////////////////////
///////////////// DIAGNOSTICS //////////////////////
    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost)
        \param text{} строка сообщения
        */
    diagnost0(text{})
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost)
        \param text{} строка сообщения
        \param var значение для вставки в строку
        */
    diagnost1(text{}, var)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost)
        \param text{} строка сообщения
        \param var1 значение для вставки в строку
        \param var2 значение для вставки в строку
        */
    diagnost2(text{}, var1, var2)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var1, var2)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost)
        \param array{} массив данных
        \param array_size количество байт для вывода в диагностику
        */
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
    outputOn(outputNum)
     {
        SetOutputValue(outputNum, 0)
        diagnost1("Output %d ON", outputNum)
     }

    outputOff(outputNum)
     {
        SetOutputValue(outputNum, 1)
        diagnost1("Output %d OFF", outputNum)
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
////////////// IN END //////////////
////////////////////////////////////
