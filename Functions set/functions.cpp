193.193.165.165
GS7 порт 21423 ---- GS7 21423 port
BB  порт 21177 ---- BB 21177 port 

/*! Теги Виалон (Идентификаторы пользовательского массива):" ---- Wialon Tags (User Array Identifiers):"
    0x01 зарезервирован ---- reserved
    0x02 данные счетчика Меркурий ---- Mercury meter data
    0x03 данные тахографа ---- tachograph data
    0x04 устройство СЕНС ---- SENS device
    0x05 устройство СКВТ-М (в разработке) ---- SCVT-M device ( in progress)
    0x06 Система измерения давления в шинах (TPMS) датчик TD5300A-X-04 ---- Tyre Pressure Monitoring System (TPMS) sensor TD5300A-X-04
    0x07 Расходомер Eurosens Delta ---- Eurosens Delta flowmeter
    0x08 Частота с ДУТ ---- Frequency from FLS
    0x09 данные с электросчетчиков ---- Electric meter data
    0x0A датчики пассажиропотока ---- Passenger counting sensors
    0x0B адаптер ЛИН-RS485 для устройств СЕНС ---- LIN-RS485 adapter for SENS devices
    0x0C Информация от VIMS ---- VIMS information
    0x0D Maple (ответы на команды) ---- Maple (command responses)
    0x0E зарезервирован ---- reserved
    0x0F зарезервирован ---- reserved
    0xEE Текстовые данные ---- Text data
    */

/*! номера ошибок в ИЗИ ЛОДЖИК ---- error codes in Easy Logic
    AMX_ERR_NONE,
    // reserve the first 15 error codes for exit codes of the abstract machine ---- 
    AMX_ERR_EXIT,         // forced exit ---- принудительный выход /
    AMX_ERR_ASSERT,       // assertion failed ---- подтверждение не выполнено /
    AMX_ERR_STACKERR,     // stack/heap collision ---- столкновение heap и стека /
    AMX_ERR_BOUNDS,       // index out of bounds ---- выход массива за пределы диапазона /
    AMX_ERR_MEMACCESS,    // invalid memory access ----  недопустимое обращение к памяти /
    AMX_ERR_INVINSTR,     // invalid instruction ---- недопустимая инструкция /
    AMX_ERR_STACKLOW,     // stack underflow ---- обращение к несуществующей области стека /
    AMX_ERR_HEAPLOW,      // heap underflow ---- обращение к несуществующей области heap /
    AMX_ERR_CALLBACK,     // no callback, or invalid callback ---- нет обратного вызова, или некорректный обратный вызов /
    AMX_ERR_NATIVE,       // native function failed ---- платформенно-ориентированная функция не выполнена /
    AMX_ERR_DIVIDE,       // divide by zero ---- деление на ноль /
    AMX_ERR_SLEEP,        // go into sleepmode - code can be restarted ---- переход в спящий режим - код может быть возобновлен /
    AMX_ERR_INVSTATE,     // no implementation for this state, no fall-back ---- нет реализации для этого состояния, нет запасного варианта /

    AMX_ERR_MEMORY = 16,  // out of memory ---- недостаточно памяти /
    AMX_ERR_FORMAT,       // invalid file format ---- некорректный формат файла /
    AMX_ERR_VERSION,      // file is for a newer version of the AMX ---- файл для более новой версии AMX /
    AMX_ERR_NOTFOUND,     // function not found ---- функция не найдена/
    AMX_ERR_INDEX,        // invalid index parameter (bad entry point) ---- недопустимый параметр индекса (некорректная точка входа) /
    AMX_ERR_DEBUG,        // debugger cannot run ---- отладчик не может быть запущен /
    AMX_ERR_INIT,         // AMX not initialized (or doubly initialized) ---- AMX не инициализирован (или дважды инициализирован) /
    AMX_ERR_USERDATA,     // unable to set user data field (table full) ---- невозможно установить поле данных пользователя (таблица заполнена) /
    AMX_ERR_INIT_JIT,     // cannot initialize the JIT---- невозможно инициализировать JIT /
    AMX_ERR_PARAMS,       // parameter error ---- ошибка параметра /
    AMX_ERR_DOMAIN,       // domain error, expression result does not fit in range ---- ошибка домена, результат выражения не вписывается в диапазон /
    AMX_ERR_GENERAL,      // general error (unknown or unspecific error) ---- общая ошибка (неизвестная или неспецифическая ошибка) /
    AMX_ERR_OVERLAY,      // overlays are unsupported (JIT) or uninitialized ---- оверлеи не поддерживаются (JIT) или не инициализированы
    */

/*! Частые команды: ---- Frequent Commands:
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
        битовые флаги: ---- bit flags:
            _CRERR = 0      , //0
            _TEST_O         , //1  тест прибора включен ---- device test is on
            _RESERV0        , //2
            _RESERV1        , //3
            _RESERV2        , //4
            //---------------
            _STAR           , //5  выводится всегда звезда ---- star is always output
            _TIME           , //6  периодический вывод времени (период 10 секунд) ---- intermittent time output (period of 10 seconds)
            //---------------
            _GPS            , //7  обычная диагностика GPS ---- idle GPS diagnostics
            _GPS_F          , //8  полная диагностика GPS ---- full GPS diagnostics
            //---------------
            _GPRS           , //9  обычная диагностика GPRS ---- idle GPRS diagnostics
            _GPRS_F         , //10 полная диагностика GPRS ---- full GPRS diagnostics
            //---------------
            _MEM            , //11 обычная диагностика памяти треков ---- idle track memory diagnostics
            _MEM_F          , //12 полная диагностика памяти треков ---- full track memory diagnostics
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
            _GPS_O          , //21 только диагностика GPS ---- only GPS diagnostics
            _GPRS_O         , //22 только диагностика GPRS ---- only GPRS diagnostics
            _1WIRE          , //23
            _ACC            , //24
            _SPUTNIK        , //25
            _USER_SPACE     , //26
            _USER_SPACE_DIAG, //27 == 134217728
            _RS485          , //28
            _BT               //29
    */

//=======================================================
//============== тэги для записи ========================
//============== tags for writing =======================
//=======================================================
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


    // Users Tags ---- Пользовательские теги
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
//=======================================================
//============== тэги для чтения ========================
//============== tags for reading =======================
//=======================================================
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
    //===============================================================
    // == в остальных просто убрать последнее нижнее подчёркивание ==
    // ==== other tags should just not have the last underscore =====
    //===============================================================

// Встроенные функции ---- Built-in functions
    Delay(const value);
    /*Задержка работы алгоритма ---- algorithm operation delay
    value время задержки в миллисекундах ---- value delay time in milliseconds*/

    SavePoint();
    /*Сохранение точки в архиве ---- Saving point in the archive*/

    min(const value1, const value2);
    /*Получить минимум из двух значений ---- Get the minimum of two values
    value1 значение 1 ---- value 1
    value2 значение 2 ---- value 2
    \return минимум из двух значений ---- the minimum of two values*/

    Rand(const min, const max);

    swapBuf(buf{}, const size);
    /*Инвертировать каждые 4 байта массива ----- Invert every 4 bytes of the array
    //!
    Преобразование LittleEndiang<->BigEndian
    \param[inout] buf{} буфер для преобразования ---- conversion buffer
    size размер буфера ---- buffer size*/

    getIntFromBuf(const buf{}, const index);
    /*Получить число (4-х-байтовый int) из буфера по позиции ----- Get a number (4-byte int) from the buffer by position
    //!
    Число в буфере извлечено в формате LittleEndian ---- The number in the buffer is extracted in LittleEndian format
    buf{} буфер, из которого будет извлекаться число ---- the buffer from which the number will be extracted
    index индекс байта, начиная с которого располагается число в массиве ---- byte index starting from which the number in the array is located
    \return число, извлечённое из буфера ---- number extracted from the buffer*/

    GetIMEI(res[], const resSize);
    /*Получим IMEI ---- Getting IMEI*/

    GetUnsentPackets();
    /*Получить количество еще не отправленных пакетов. Работает только при отправке пакетов в хронологическом порядке ---- Get the unsent packets number. Works only when packets are sent in the chronological order*/

    NewPhoto(const filename[]);
    /*Оповещение прошивки, что сделан новый снимок фотокамерой ---- Firmware notification that a new photo was taken with the camera
    filename полное имя файла --- file full name*/

    PlayAudio(const filename[]);
    /*Воспроизвести аудио файл ---- Play Audio
    filename полное имя файла ---- file full name*/

    setAutoinformerRoute(Dir[]);
    /*Переключаем маршрут в Автоинформаторе ---- Switching the route in the Autoinformer*/

    // Diagnostics ---- Диагностика
        Diagnostics(const message[], ...);
        /*Вывод строчки в Диагностику алгоритмов ---- Line output in the Algorithm Diagnostics
        message Сообщение для вывода, например "Var1=%d, Var2=%d" (см. printf) ---- Message to output, for example "Var1=%d, Var2=%d" (see printf)
        ... Можно указывать два дополнительных параметра для вставки в сообщение: "%d" вывод целого числа ---- Two additional parameters can be specified for inserting into the message: "%d" the output of an integer
        Старайтесь выводить диагностику короткими строчками ---- Try to display the diagnostics in short lines
        Например/Example: Diagnostics("Dev. Req.: %d", REQUEST_SIZE)
        Это уменьшит размер скрипта и скорость вывода диагностики ---- This will reduce the size of the script and the speed of the diagnostic output*/

        DiagnosticsHex(const buf[], const size);
        /*Вывод массива в Диагностику алгоритмов в шестнадцатеричном виде ---- Output the array to the Algorithm Diagnostic in hexadecimal form
        buf[] буфер выводимого массива ---- output array buffer
        size размер буфера ---- buffer size*/

    // Inputs --- Входы
        DisablePulseCounting(const inputNum, const disabled);
        /*Отключение подсчёта импульсов на входе ---- Disable input pulse counting
        inputNum номер входа, на котором будет произведено обнуление счётчика ---- the number of the input on which the counter will be reset
        disabled true - отключить подсчёт импульсов ---- disable pulse counting
        disabled false - включить подсчёт импульсов ---- enable pulse counting*/

        NullInput(const inputNum);
        /*Обнуление счётчика на входе ---- Reset the counter on the input
        inputNum номер входа, на котором будет произведено обнуление счётчика ---- the number of the input on which the counter will be reset*/

        SetOutputValue(const outputNum, const value);
        /*Установить состояние выхода ---- Set Output Value
        outputNum номер выхода ---- output number
        value устанавливаемое состояние ---- setting state*/

    // Variables - Переменные
        GetVar(const name);
        /*Получение тега, значения глобальной или системной переменной ---- Getting a tag, global or system variable value
        name Имя переменной ---- variable name 
        \return значение указанной переменной ---- value of the specified variable*/

        SetVar(const name, const value);
        /*Установка значения глобальной или системной переменной ---- Set the value of a global or system variable
        name Имя переменной ---- variable name
        value устанавливаемое значение ---- setting value*/

    // Tags write ---- Запись в теги
        TagWriteValue(const index, const value);
        /*Запись значения в тег пользователя ---- Writing a value to a user tag
        index индекс тега пользователя ----- user tag index
        Индекс может принимать значения из диапазона `0x62` - `0x69` ---- Index can take values ranging from `0x62` to `0x69`
        value записываемой значение ---- recorded value*/

        TagWriteArray(const index, ...);
        /*Запись буфера данных в массив пользователя ---- Writing a data buffer to a user array
        index индекс массива пользователя. ---- user array index.
        Индекс должен быть равен `0x6A` ---- The index must be equal to `0x6A`
        size размер буфера данных ---- data buffer size
        buf буфер данных ---- data buffer*/

    // Digital ports ---- Цифровые порты
        PortInit(const index, const speed, const bufSize);
        /*Инициализация порта ---- Port initialization
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        speed port speed: 19200
        bufSize size of input buffer
        stopBits количество стоповых бит: ---- Stop bit number:
            0 - 1 стоповый бит (по умолчанию) ---- 1 stop bit (default)
            1 - 2 стоповых бита ---- 2 stop bits
        parity контроль по чётности: ---- parity check:
            0 - без контроля чётности (по умолчанию) ---- without parity check (default)
            1 - контроль по нечётности - odd ---- odd parity check - odd
            2 - контроли по чётности - even ---- even parity check - even
        packetMode пакетный режим: ---- packet mode:
            0 - без разделения на пакеты (по умолчанию) ---- without splitting into packets (default)
            1 - с разделением на пакеты, временной интервал между пакетами составляет 729 мс ---- with packet split, the time interval between packets is 729 ms */

        PortRead(const index, &char, const timeout);
        /*Чтение символа из порта ---- Reading a character from a port
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        \param[out] char received character ---- полученный символ
        timeout wait timeout of the next character ---- период ожидания следующего символа
        \retval 0 - символ не прочитан по истечении тайм-аута ---- the symbol is not read after the timeout expires
        \retval !=0 - символ прочитан ---- the symbol is read */

        PortWrite(const index, const buf[], const size);
        /*Запись данных из буфера в порт ---- Writing data from the buffer to the port
        index port index: 0 - RS232_0, 1 - RS232_1, 2 - RS485
        buf buffer to send ---- отправляемый буфер
        size buffer size ---- размер буфера*/

        PortReadPackage(const index, &char, const timeout);
        /*Чтение пакетов из порта, разделённых по временной задержке ---- Reading packets from a port split by time delay
        index port index: 2 - RS485 (пока реализовано только для RS485) ---- (only for RS485 so far)
        buf указатель на буфер под полученный пакет ---- pointer to the buffer under the received packet
        \param[in] bufSize размер переданного буфера ---- transferred buffer size
        \param[in] firstByteTimeout время ожидания первого байта, мс ---- waiting time of the first byte, ms
        \param[in] nextByteTimeout время ожидания последующего байта, мс ---- waiting time for the next byte, ms
        \return количество прочитанных символов в пакете ----- the number of read characters in the packet*/

    // CRC
        CRC16(const buf[], const size, const crcinit);  // CRC-16-CCITT см. ниже ---- see below
        /*Подсчёт CRC-16 ---- CRC-16 Counting
        buf буфер для подсчёта ---- counting buffer
        size размер буфера ---- buffer size 
        crcinit начальное значение CRC, по умолчанию 0xFFFF ---- Initial CRC value, default is 0xFFFFFF
        \return посчитанное значение CRC16 ---- counted value of CRC16*/

        CRC8(const crcInit], const buf[], const size);
        /*Подсчёт CRC-8 по полиному x^8 + x^7 + x^4 + x^0 (0x91) ---- Counting of CRC-8 by polynomial x^8 + x^7 + x^4 + x^0 (0x91)
        //!
        Посчёт CRC-8 буфера \a buf длиной \a size. ---- CRC-8 counting of a buffer \a buf of length \a size.
        Начальное значение CRC8 устанавливается в \a crcInit. ---- The initial value of CRC8 is set to \a crcInit.
        Значение CRC-8 вычисляется, как разность 0xFF и результата данной функции CRC8() ---- The CRC-8 value is counted as the difference between 0xFF and the result of this function CRC8()
        crcInit начальное значение CRC ---- initial CRC value
        buf[] буфер для подсчёта ---- counting buffer
        size размер буфера ---- buffer size
        \return посчитанное значение CRC8 ---- counted value of CRC8*/

        CRC8_D5(const buf[], const size);
        /*Подсчёт CRC-8 по полиному 0xD5 ---- Counting of CRC-8 by polynomial 0xD5
        //!
        Посчёт CRC-8 буфера \a buf длиной \a size. ---- CRC-8 counting of a buffer \a buf of length \a size.
        buf[] буфер для подсчёта ---- counting buffer
        size размер буфера ---- buffer size
        \return посчитанное значение CRC8 ---- counted value of CRC8*/

    // CD-card
        NextDir(const rootDir[], const lastDir[], res[], const resSize);
        /*Ищем следующий каталог за заданным ---- Search for the next directory after the given one*/

        FileSize(const filename[]);
        /*Получить размер файла ---- Get file size
        filename полное имя файла ---- full file name
        \return размер файла, -1 - если файл не найден ---- file size, -1 If the file is not found*/

        FileRead(const filename[], buf[], const bufSize, const offset = 0);
        /*Прочитать со смещением из файла в массив ---- Read offset from a file to an array
        filename полное имя файла ---- full file name
        buf массив-приёмник ---- receiver array
        bufSize размер массива-приемника ---- receiver array size
        offset смещение в файле, указывающее откуда начинать чтение ---- file offset, indicating where to start reading from
        \return фактическое количество прочитанных байт ---- actual number of bytes read*/

        FileWrite(const filename[], const buf[], const bufSize, const offset = -1);
        /*Записать массив в файл со смещением ---- Write an array to the file with an offset
        filename полное имя файла ---- full file name
        buf массив-источник ---- source array
        bufSize размер массива-источника ---- source array size
        offset смещение в файле, указывающее откуда начинать запись. -1 - записывать в конец файла ---- offset in the file, indicating where to start writing. -1 - write to the end of the file
        \return фактическое количество записа байт ---- actual number of written bytes*/

        FileDelete(const filename[]);
        /*Удалить файл ---- Delete File 
        filename полное имя файла ---- full file name
        \return логическое значение операции удаления файла ---- logical value of the file deletion operation*/

    // Coordinates ---- Координаты
        InZone(const lat, const lon, const angle, const delta, const radExt, const radInt);
        /*Проверим находимся ли мы сейчас в геозоне автоинформатора ---- Check if the device is now in the geofence of the autoinformer*/
        
        SetFlagOfInvalidCoordinates(const enable);

    // Command ---- Команды
        ExecCommand(Cmd[]);
        /*Выполнить команду ---- Execute a command*/

        GetBinaryDataFromCommand(buf[], const bufSize);
        /*получить бинарные данные из принятой команды ---- get the binary data from the received command
        buf массив-приемник ---- receiver array
        bufSize размер массива-приемника ---- receiver array size*/

        SendAnswer(const connectionId, const commandIndex, const answerBuf[], const answerSize, const dataBuf[], const dataSize);
        /*Послать ответ на команду полученную от сервера мониторинга ---- Send a response to a command received from the monitoring server
        connectionId идентификатор соединения ---- connection identifier
        commandIndex номер команды, получаемый в теге `0xE0` ---- command number received in the tag `0xE0`
        answerBuf буфер ответа, содержащий ответ на команду. Подразумевается ответ в виде текста, передаваемый в теге `0xE1` ---- response buffer containing the response to the command. It is understood as a response in the text, which is transmitted in the tag `0xE1`
        answerSize размер буфера ответа ---- response buffer size
        dataBuf буфер данных, содержащий двоичные данные. Передаются в теге `0xEB` ---- data buffer containing binary data. Transmitted in the tag `0xEB`
        dataSize размер буфера данных. Если равен нулю, то тег с данными в ответе не передаётся ---- data buffer size. If it is zero, the tag with the data in the response is not transmitted*/

    // CAN
        CANInit(speed, active);
        /*Инициализировать CAN шину --- CAN bus initialization*/

        CANEnableReception(enable);
        /*Включить приём сообщений ---- Enable message reception*/

        CANSetFilter(id, mask, type);
        /*Установить фильтр ---- Set Filter*/

        CANSend(const msg[CANMSG]);
        /*Послать сообщений ---- Send a message*/

        CANReceive(msg[CANMSG]);
        /*Принять сообщение ---- Receive a message*/

    // TCP
        SocketOpen(const address[], const port, const timeout);
        /*Открыть сокет и подключиться к серверу ---- Open a socket and connect to the server
        const address[]
        const port
        const timeout*/

        SocketSend(const src[], const bytesToSend, &bytesSent, const timeout);
        /*Отправить данные в ранее открытый сокет ---- Send data to a previously opened socket
        const src[]
        const bytesToSend
        &bytesSent
        const timeout*/

        SocketRecv(const dest[], const bufSize, &bytesRcvd, const timeout);
        /*Получить данные из ранее открытого сокета ---- get data from a previously opened socket
        dest[]
        const bufSize
        &bytesRcvd
        const timeout*/

        SocketClose();
        /*Отключиться от сервера и закрыть сокет ---- Disconnect from the server and close the socket*/

    // BLUETOOTH
        BTInit();

        BTReceive(msg[BTMSG], const timeout);

// ===========================================================================
//{ Библиотека вспомогательных функций GalileoSky ============================
//{ GalileoSky auxiliary function library ====================================
// ===========================================================================
    /*! более точный ---- more accurate */
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

    GS_abs(num)
     {
        return (num >= 0) ? num : -num
     }

    /* Возведение в степень --- Exponentiation */
    GS_pow(num, p)
     {
        new buf1 = num
        new buf2 = num

        if ( 0 == p)
            return 1

        if ( 1 == p )
            return buf1

        for (new i = 0; i < (p - 1); ++i)
         {
            buf1 *= buf2
         }

        return buf1
     }

    /*! Возвращает int из числа в формате float32 стандарта IEEE754 ---- Returning int from the IEEE754 standard float 32 format number
        \param numFloat число в формате float32 стандарта IEEE754 ---- IEEE754 standard float 32 format number
        \param definition точность после запятой - кол-во знаков ---- number of decimal places
        \return int
        \example: Diagnostics("result: %d,%d", GS_floatToInt(num, 0), (GS_floatToInt(num, 2) % 100 + 5) / 10)
        */
    GS_floatToInt(numFloat, definition)
     {
        new sign = (numFloat >> 31) ? -1 : 1;  /* Знак ---- Sign*/
        new exponent = (numFloat >> 23) & 0xFF;  /* Порядок ---- Exponent*/
        new mantissa = (exponent) ? (numFloat & 0x7FFFFF) | 0x800000 : (numFloat & 0x7FFFFF) << 1  /* Мантисса ---- Mantissa*/
        new offset = exponent - 150;
        new mult = 1

        if (definition > 2)
        {
            definition = 2  // максимальное значение из-за ограничения размера мантиссы ---- maximum value depending on the mantissa size restriction
        }

        while (definition > 0)
        {
            mult *= 10
            definition--
        }

        mantissa *= mult;

        if (offset > 0)
        {
            mantissa <<= offset
        }
        if (offset < 0)
        {
            mantissa >>= -offset
        }

        return sign * mantissa;
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

    /*! Возвращает длину строки заканчивающуюся нулевым байтом. ---- Returning the string length ending with a null byte
        \param buf{} измеряемая строка ---- measured string
        \param bufsize размер буфера с текстом ---- text array size
        \retval количество байт до 0x00 ---- the number of bytes before 0x00
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

    /*! Возвращает строку из файла ---- Returning a string from a file
        \param file имя файла ---- file name
        \param pos номер байта начала строки ---- number of the string start byte
        \param dst буфер строки ---- string array
        \param dst_size размер буфера строки ---- string array size
        \return length строки ---- string length
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

    /*! Проверяет является ли символ цифрой в формате ASCII ---- Checking is a symbol is an ASCII number
        \param byte предполагаемый символ цифры в ASCII ---- suggested symbol of an ASCII number
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

    /*! Возвращает int из цифры в формате ASCII ---- Returning int from an ASCII number
        \param byte символ цифры в ASCII ---- a symbol of an ASCII number
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

    /*! Алгоритм прямого поиска ---- Direct search algorithm
        \param string1 - где искать ---- where to search
        \param str1Len длина строки string1 ---- string1 length
        \param string2 - что искать ---- what to search for 
        \param str2Len длина строки string2 ---- string2 length
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

    /*! Собирает число из строки ---- Collecting a number from the string
        \param str{} строка символов ---- symbol string
        \param &pos индекс начала чтения строки ---- index of string reading start
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

    /*! Собирает число из строки ---- Collecting a number from a string
        \param str{} строка символов ---- symbol string
        \param &pos индекс начала чтения строки ---- index of a string reading start
        \param precision требуемая точность до Х знака после запятой ---- required precision to X decimal place
        \param sep символ разделитель. Например '.' или ',' ---- divider symbol (e.g., '.' or ',')
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

    /*! Очистка массива ---- Clearing the array*/
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
        использует GS_offsetArrRight8() ---- using GS_offsetArrRight8()
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

    /*! Запись значения в BLUETOOTH_тег ---- Writing values to a BLUETOOTH_tag
        \param index номер тега от 0 до 63 ---- tag number 0 to 63
        \param value записываемое значение ---- value to be written
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

    /*! Чтение значения из BLUETOOTH_тега ---- Reading a value from a BLUETOOTH_tag
        \param index номер тега от 0 до 63 ---- tag number 0 to 63
        \return int
        */
    GS_tagBluetoothReadValue(index)
     {
        if (index < 0 || index > 63)
         {
            return;
         }

        switch (index)
         {
            case 0: { return GetVar(BLUETOOTH_0) }
            case 1: { return GetVar(BLUETOOTH_1) }
            case 2: { return GetVar(BLUETOOTH_2) }
            case 3: { return GetVar(BLUETOOTH_3) }
            case 4: { return GetVar(BLUETOOTH_4) }
            case 5: { return GetVar(BLUETOOTH_5) }
            case 6: { return GetVar(BLUETOOTH_6) }
            case 7: { return GetVar(BLUETOOTH_7) }
            case 8: { return GetVar(BLUETOOTH_8) }
            case 9: { return GetVar(BLUETOOTH_9) }

            case 10: { return GetVar(BLUETOOTH_10) }
            case 11: { return GetVar(BLUETOOTH_11) }
            case 12: { return GetVar(BLUETOOTH_12) }
            case 13: { return GetVar(BLUETOOTH_13) }
            case 14: { return GetVar(BLUETOOTH_14) }
            case 15: { return GetVar(BLUETOOTH_15) }
            case 16: { return GetVar(BLUETOOTH_16) }
            case 17: { return GetVar(BLUETOOTH_17) }
            case 18: { return GetVar(BLUETOOTH_18) }
            case 19: { return GetVar(BLUETOOTH_19) }

            case 20: { return GetVar(BLUETOOTH_20) }
            case 21: { return GetVar(BLUETOOTH_21) }
            case 22: { return GetVar(BLUETOOTH_22) }
            case 23: { return GetVar(BLUETOOTH_23) }
            case 24: { return GetVar(BLUETOOTH_24) }
            case 25: { return GetVar(BLUETOOTH_25) }
            case 26: { return GetVar(BLUETOOTH_26) }
            case 27: { return GetVar(BLUETOOTH_27) }
            case 28: { return GetVar(BLUETOOTH_28) }
            case 29: { return GetVar(BLUETOOTH_29) }

            case 30: { return GetVar(BLUETOOTH_30) }
            case 31: { return GetVar(BLUETOOTH_31) }
            case 32: { return GetVar(BLUETOOTH_32) }
            case 33: { return GetVar(BLUETOOTH_33) }
            case 34: { return GetVar(BLUETOOTH_34) }
            case 35: { return GetVar(BLUETOOTH_35) }
            case 36: { return GetVar(BLUETOOTH_36) }
            case 37: { return GetVar(BLUETOOTH_37) }
            case 38: { return GetVar(BLUETOOTH_38) }
            case 39: { return GetVar(BLUETOOTH_39) }

            case 40: { return GetVar(BLUETOOTH_40) }
            case 41: { return GetVar(BLUETOOTH_41) }
            case 42: { return GetVar(BLUETOOTH_42) }
            case 43: { return GetVar(BLUETOOTH_43) }
            case 44: { return GetVar(BLUETOOTH_44) }
            case 45: { return GetVar(BLUETOOTH_45) }
            case 46: { return GetVar(BLUETOOTH_46) }
            case 47: { return GetVar(BLUETOOTH_47) }
            case 48: { return GetVar(BLUETOOTH_48) }
            case 49: { return GetVar(BLUETOOTH_49) }

            case 50: { return GetVar(BLUETOOTH_50) }
            case 51: { return GetVar(BLUETOOTH_51) }
            case 52: { return GetVar(BLUETOOTH_52) }
            case 53: { return GetVar(BLUETOOTH_53) }
            case 54: { return GetVar(BLUETOOTH_54) }
            case 55: { return GetVar(BLUETOOTH_55) }
            case 56: { return GetVar(BLUETOOTH_56) }
            case 57: { return GetVar(BLUETOOTH_57) }
            case 58: { return GetVar(BLUETOOTH_58) }
            case 59: { return GetVar(BLUETOOTH_59) }

            case 60: { return GetVar(BLUETOOTH_60) }
            case 61: { return GetVar(BLUETOOTH_61) }
            case 62: { return GetVar(BLUETOOTH_62) }
            case 63: { return GetVar(BLUETOOTH_63) }
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
        Name\Имя  : CRC-16 CCITT
        Poly\Полином  : 0x1021    x^16 + x^12 + x^5 + x^0
        Init  : 0x1D0F

        Example 1: ---- Пример 1
        537F0D00046E00802500006E38
        6E38 is the CRC here (in Little endian format) ----- 6E38 здесь CRC (в формате Little endian)

        Example 2: ---- Пример 2
        53000900046100C066
        C066 is the CRC here (in Little endian format) ---- C066 здесь CRC (в формате Little endian)
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

// Таймер и его функции ---- Timer and its features
    /*! закончился таймер или нет ---- checking if the timer is over or not*/
    isTimerExpired()
     {
        return (GetVar(glTimer) <= GetVar(UNIX_TIME))
     }

    /*! запустить таймер на value секунд ---- set the timer for value seconds
        \param value секунды ---- seconds
        */
    setTimer(value)
     {
        SetVar(glTimer, GetVar(UNIX_TIME) + value)
     }

    /*! сбросить таймер ---- reset the timer*/
    unsetTimer()
     {
        SetVar(glTimer, 0)
     }

//!*************************************************************
//!-----------------Библиотека работы с Modbus------------------
//!----------------------Modbus library-------------------------
//!*************************************************************
    //! Порт подключения шины Modbus---Modbus connection port 
    #define MB_PORT_INDEX 2

    //! Скорость подключения по шине Modbus----Modbus connection speed
    #define MB_PORT_SPEED 19200    

    //! Количество стопбит ---- Number of stop bits
    #define MB_PORT_STOP 0  

    //! Размер буфера для обмена по шине Modbus----Buffer size for Modbus exchange
    #define MB_BUF_SIZE 256

    //! Таймаут ожидания ответа слейва, мс----Slave response timeout in ms
    #define MB_TIMEOUT 10000

    //! Коды ошибок, возвращаемые функциями обмена по шине----Error codes returned by bus exchange functions
    #define MB_ERR_OK 0      //!< Успешный обмен данными----Successful data exchange
    #define MB_ERR_CMD 1     //!< Принятый код функции не может быть обработан----Received function code cannot be processed
    #define MB_ERR_ADDR 2    //!< Адрес данных, указанный в запросе, недоступен----The data address specified in the request is not available
    #define MB_ERR_VALUE 3   //!< Значение, содержащееся в поле данных запроса, является недопустимой величиной----The value in the request data field is invalid
    #define MB_ERR_ERR 4     //!< Невосстанавливаемая ошибка имела место, пока ведомое устройство пыталось выполнить затребованное действие----A unrecoverable error occurred while the slave device was trying to perform the requested action
    #define MB_ERR_WAIT 5    //!< Ведомое устройство приняло запрос и обрабатывает его, но это требует много времени. Этот ответ предохраняет ведущее устройство от генерации ошибки тайм-аута----The request is accepted and being processed by the slave device, but this takes a long time. This response prevents the master device from generating a timeout error
    #define MB_ERR_BUSY 6    //!< Ведомое устройство занято обработкой команды. Ведущее устройство должно повторить сообщение позже, когда ведомое освободится----The slave device is busy processing a command. The master must repeat the message later when the slave is free
    #define MB_ERR_CNTEXEC 7 //!< Ведомое устройство не может выполнить программную функцию, заданную в запросе----The slave device cannot execute the program function specified in the request
    #define MB_ERR_PARITY 8  //!< Ведомое устройство при чтении расширенной памяти обнаружило ошибку паритета----The slave device detected a parity error when reading extended memory
    #define MB_ERR_CRC 9     //!< Ошибка контрольной суммы----Checksum error
    #define MB_ERR_SIZE 10   //!< Получен ответ некорректного размера----A response of incorrect size is received

    //! Начальная позиция полезных данных при команде "чтение"----Initial position of useful data at the read command
    #define MB_READ_START 3

    //! Начальная позиция полезных данных при команде "запись"----Initial position of useful data at the write command
    #define MB_WRITE_START 7

    //! Инициализация шины Modbus----Modbus initialisation
    modbusInit()
     {
        PortInit(MB_PORT_INDEX, MB_PORT_SPEED, MB_BUF_SIZE , MB_PORT_STOP);
     }

    /*! Запись значения 16-битного регистра в буфер в формате Modbus----Writing a 16-bit register value to the Modbus buffer
        \param[in] mbBuf Буфер, куда производится запись----Buffer where the data is written
        \param[in] offset Смещение указателя записи от начала буфера----Record pointer offset from the beginning of the buffer
        \param[in] value Значение записываемого регистра----Written register value
        */
    setReg(mbBuf{}, offset, value)
     {
        mbBuf{offset} = value >> 8 //Старший байт вперед----High byte forward
        mbBuf{offset + 1} = value //Младший байт----Low byte
     }

    /*! Функция возвращает значения 16-битного регистра Modbus из буфера----The function returns the values of the 16-bit Modbus register from the buffer
        \param[in] mbBuf Буфер, откуда производится чтение----Buffer from which the reading is done
        \param[in] offset Смещение указателя чтения от начала буфера
        \return Конвертированное значение регистра----Converted register value
        */
    getReg(mbBuf{}, offset)
     {
        return mbBuf{offset} * 256 + mbBuf{offset + 1}
     }

    /*! Функция возвращает значения 32-битного регистра Modbus из буфера----The function returns the values of the 32-bit Modbus register from the buffer
        \param[in] mbBuf Буфер, откуда производится чтение----Buffer from which the reading is done
        \param[in] offset Смещение указателя чтения от начала буфера
        \return Конвертированное значение регистра----Converted register value
        */
    getReg32(mbBuf{}, offset)
     {
        return (mbBuf{offset} << 24) + (mbBuf{offset + 1} << 16) + (mbBuf{offset + 2} << 8) + (mbBuf{offset + 3})
     }

    /*! 0x03 - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)----Function for reading values from multiple storage registers (Read Holding Registers)
        \param[in] addr Адрес ведомого устройства----Slave address
        \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными----The clipboard will be overwritten with the read data
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать----Address of the first element which value needs to be read
        \param[in] count Количество считываемых элементов----Number of read elements
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
        */
    readRegs(addr, mbBuf{}, fRegAddr, count)
     {
        mbBuf{0} = addr
        mbBuf{1} = 0x03 //Код функции----Function code
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента----First element address
        setReg(mbBuf, 4, count) //Количество считываемых элементов----Number of read elements
        return transact(mbBuf, 6)
     }

    /*! 0x04 - Функция чтение значений из нескольких регистров хранения (Read Input Registers)----Function for reading values from multiple storage registers (Read Input Registers)
        \param[in] addr Адрес ведомого устройства----Slave address
        \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными----The clipboard will be overwritten with the read data
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать----Address of the first element which value needs to be read
        \param[in] count Количество считываемых элементов----Number of read elements
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
        */
    readRegsIn(addr, mbBuf{}, fRegAddr, count)
     {
        mbBuf{0} = addr
        mbBuf{1} = 0x04 //Код функции----Function code
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента----First element address
        setReg(mbBuf, 4, count) //Количество считываемых элементов----Number of read elements
        return transact(mbBuf, 6)
     }

    /*! 0x10 - Функция записи значений в несколько регистров хранения (Preset Multiple Registers)----Function for writing values to multiple storage registers (Preset Multiple Registers)
        Функция заполнит заголовок буфера и отправит его в шину, полезные данные требуется располагать----The function fills the clipboard header and sends it to the bus, useful data should be placed
        начиная с позиции \a MB_WRITE_START. Записываемые значения все 16-битные----starting with \a MB_WRITE_START position. All written values are 16-bit.
        \param[in] addr Адрес ведомого устройства----Slave address
        \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными----The clipboard will be overwritten with the read data
        \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать----Address of the first element which value needs to be read
        \param[in] count Количество считываемых элементов----Number of read elements
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
        */
    writeRegs(addr, mbBuf{}, fRegAddr, count)
     {
        mbBuf{0} = addr
        mbBuf{1} = 0x10 //Код функции----Function code
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента----First element address
        setReg(mbBuf, 4, count) //Количество считываемых элементов----Number of read elements
        mbBuf{6} = count * 2
        return transact(mbBuf, 7 + count * 2)
     }

    //!----------------- служебные функции MODBUS ------------------
    //!----------------- MODBUS service functions ------------------
    /*! Обмен с устройством данными по шине----Exchanging data with the device over the bus
        \param[inout] mbBuf Буфер обмена, данные из него будут записаны с добавленной CRC, и в него будут считан ответ без CRC----Clipboard, the data from it will be written with CRC added, and the response without CRC will be read into it 
        \param[inout] size Размер буфера обмена----Clipboard size
        \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
        */
    transact(mbBuf{}, size)
     {    
        //Добавляем CRC----Adding CRC
        new c = CRC16(mbBuf, size)
        mbBuf{size} = c
        mbBuf{size + 1} = c >> 8
        //Пишем в порт----Writing to the port
        PortWrite(MB_PORT_INDEX, mbBuf, size + 2)
        //Размер ответа, для записывающих команд размер известен из стандарта----Response size, it is known from the standard for writing commands
        new ansSize = (mbBuf{1} > 4) ? 8 : MB_BUF_SIZE + 1
        //Слушаем ответ----Listening to the response
        new err = 0
        new bytesRead = 0  
        c = 0    
        while (PortRead(MB_PORT_INDEX, c, MB_TIMEOUT))
        {
            mbBuf{bytesRead} = c
            bytesRead++

            if ((bytesRead >= MB_BUF_SIZE) || (bytesRead >= ansSize))
                break

            //Ошибка ли?----Checking for errors
            if (bytesRead == 2)
                err = (c & 0x80 == 0x80)

            //Определяем длину сообщения, либо код ошибки----Defining the message length or the error code
            if (bytesRead == 3)
            {
                if (err)
                {
                    err = c
                    ansSize = 5
                }
                else 
                {
                    if (ansSize == MB_BUF_SIZE + 1) //Считываем размер только для операций чтения----Reading the size only for reading operations
                        ansSize = 3 + c + 2
                }
            }
        }    
        //Сверяем целевой и фактический размеры ответа----Comparing the target response size and the actual response size
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
        //Проверки пройдены, возвращаем код результата(ошибки)----Checks are passed, returning the result (error) code
        return err
     }

    //! Функция вывода содержимого буфера \a buf длиной \a len---Function for showing the contents of the \a buf buffer of \a len length
    printData(buf{}, len)
     {
        // вывод по 2 байта в строке----showing 2 bytes per line
        for(new i = 0; i < len / 2; i++)
        {
            Diagnostics("%02X %02X", buf{i * 2}, buf{i * 2 + 1})
            Delay(10)
        }
        // вывод последнего байта при нечётной длине----showing the last byte with the odd length
        if (len % 2)
            Diagnostics("%02X", buf{len - 1})
     }

    //! Функция записи значения регистра в тег----Function for writing a register value to a tag
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

    //! Функция записи значения регистров в тег----Function for writing registers values to a tag
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
//!---------------The end of Modbus library---------------------
//!*************************************************************

//////////////////////////////////////////
///////////////// SERIAL /////////////////
    // 9600, 19200, 38400 - max 1200 meters
    #define BOUD_RATE 9600
    #define PORT_INDEX 2  // RS485
    #define BUF_SIZE 300
    #define STOP_BITS 0 // 0 - 1 stop bit
    #define PARITY 0  // no parity bits

    /*! инициализация порта*/
    /*! port initialization */
    serialInit()
     {
        diagnost0("serialInit()")
        PortInit(PORT_INDEX, BAUDRATE, BUF_SIZE, STOP_BITS, PARITY)
     }

    /*! запись в порт ---- port recording
        \param ioBuf{} буфер с данными для отправки в порт ---- buffer with data to send to the port
        \param ioBufSize количество байт для отправки в порт ---- the number of bytes to send to the port
        */
    serialWrite(ioBuf{}, ioBufSize)
     {
        diagnost0("Serial write:")
        diagnostHex(ioBuf, ioBufSize)
        PortWrite(PORT_INDEX, ioBuf, ioBufSize)
     }

    /*! чтение пакетов из порта, разделённых по временной задержке ---- reading packets from a port separated by time delay
        \param ioBuf{} буфер для полученных данных ---- buffer for received data
        \param bufSize размер буфера ---- buffer size
        \param firstByteTimeout время ожидания первого байта ---- first byte timeout
        \param nextByteTimeout время ожидания остальных байт ---- remaining bytes timeout
        \return int количество прочитанных байт ---- number of bytes read
        */
    serialRead(ioBuf{}, bufSize, firstByteTimeout, nextByteTimeout)
     {
        diagnost0("serialRead()")
        new count = 0

        if (2 == PORT_INDEX)  // пока реализовано только для RS485 ---- only available for RS485 for now
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
    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost) ---- output additional diagnostics if the GetVar(diagnost) flag is set
        \param text{} строка сообщения ---- message line
        */
    diagnost0(text{})
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost) ---- output additional diagnostics if the GetVar(diagnost) flag is set
        \param text{} строка сообщения ---- message line
        \param var значение для вставки в строку ---- value to insert into the line
        */
    diagnost1(text{}, var)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost) ---- output additional diagnostics if the GetVar(diagnost) flag is set
        \param text{} строка сообщения ---- message line
        \param var1 значение для вставки в строку ---- value to insert into the line
        \param var2 значение для вставки в строку ---- value to insert into the line
        */
    diagnost2(text{}, var1, var2)
     {
        if (GetVar(diagnost))
        {
            Diagnostics(text, var1, var2)
        }
     }

    /*! вывод доп. диагностики, если выставлен флаг GetVar(diagnost) ---- output additional diagnostics if the GetVar(diagnost) flag is set
        \param array{} массив данных ---- data array
        \param array_size количество байт для вывода в диагностику ---- number of bytes to output to the diagnostics
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
