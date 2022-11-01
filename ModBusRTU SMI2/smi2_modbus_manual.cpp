/*!
    Файл содержит библиотеку для работы с шиной Modbus и пример её использования 
    This file contains the library for working with Modbus and an example of using it
*/
#define ADDRESS 16
//!*************************************************************
//!-----------------Библиотека работы с Modbus------------------
//!-----------------------Modbus library------------------------
//!*************************************************************
    //! Порт подключения шины Modbus---Modbus connection port
    #define MB_PORT_INDEX 2

    //! Скорость подключения по шине Modbus----Modbus connection speed
    #define MB_PORT_SPEED 19200    

    //! Количество стопбит----Number of stop bits
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

    //! Запись значения 16-битного регистра в буфер в формате Modbus----Writing a 16-bit register value to the Modbus buffer
    //! \param[in] mbBuf Буфер, куда производится запись----Buffer where the data is written
    //! \param[in] offset Смещение указателя записи от начала буфера----Record pointer offset from the beginning of the buffer
    //! \param[in] value Значение записываемого регистра----Written register value
    setReg(mbBuf{}, offset, value)
    {
        mbBuf{offset} = value >> 8 //Старший байт вперед----High byte forward
        mbBuf{offset + 1} = value //Младший байт----Low byte
    }

    //! Функция возвращает значения 16-битного регистра Modbus из буфера----The function returns the values of the 16-bit Modbus register from the buffer
    //! \param[in] mbBuf Буфер, откуда производится чтение----Buffer from which the reading is done
    //! \param[in] offset Смещение указателя чтения от начала буфера----Read pointer offset from the beginning of the buffer
    //! \return Конвертированное значение регистра----Converted register value
    getReg(mbBuf{}, offset)
    {
        return mbBuf{offset} * 256 + mbBuf{offset + 1}
    }

    //! Функция возвращает значения 32-битного регистра Modbus из буфера----The function returns the values of the 16-bit Modbus register from the buffer
    //! \param[in] mbBuf Буфер, откуда производится чтение----Buffer from which the reading is done
    //! \param[in] offset Смещение указателя чтения от начала буфера----Read pointer offset from the beginning of the buffer
    //! \return Конвертированное значение регистра----Converted register value
    getReg32(mbBuf{}, offset)
    {
        return (mbBuf{offset} << 24) + (mbBuf{offset + 1} << 16) + (mbBuf{offset + 2} << 8) + (mbBuf{offset + 3})
    }

    //! 0x03 - Функция чтение значений из нескольких регистров хранения (Read Holding Registers)----Function for reading values from multiple storage registers (Read Holding Registers)
    //! \param[in] addr Адрес ведомого устройства----Slave address
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными----The clipboard will be overwritten with the read data
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать----Address of the first element which value needs to be read
    //! \param[in] count Количество считываемых элементов----Number of read elements
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
    readRegs(addr, mbBuf{}, fRegAddr, count)
    {
        mbBuf{0} = addr
        mbBuf{1} = 0x03 //Код функции----Function code
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента----First element address
        setReg(mbBuf, 4, count) //Количество считываемых элементов----Number of read elements
        return transact(mbBuf, 6)
    }

    //! 0x04 - Функция чтение значений из нескольких регистров хранения (Read Input Registers)----Function for reading values from multiple storage registers (Read Input Registers)
    //! \param[in] addr Адрес ведомого устройства----Slave address
    //! \param[out] mbBuf Буфер обмена, будет перезаписан считанными данными----The clipboard will be overwritten with the read data
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется прочитать----Address of the first element which value needs to be read
    //! \param[in] count Количество считываемых элементов----Number of read elements
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
    readRegsIn(addr, mbBuf{}, fRegAddr, count)
    {
        mbBuf{0} = addr
        mbBuf{1} = 0x04 //Код функции----Function code
        setReg(mbBuf, 2, fRegAddr) //Адрес первого элемента----First element address
        setReg(mbBuf, 4, count) //Количество считываемых элементов----Number of read elements
        return transact(mbBuf, 6)
    }

    //! 0x10 - Функция записи значений в несколько регистров хранения (Preset Multiple Registers)----Function for writing values to multiple storage registers (Preset Multiple Registers)
    //!
    //! Функция заполнит заголовок буфера и отправит его в шину, полезные данные требуется располагать----The function fills the clipboard header and sends it to the bus, useful data should be placed
    //! начиная с позиции \a MB_WRITE_START. Записываемые значения все 16-битные----starting with \a MB_WRITE_START position. All written values are 16-bit.
    //! \param[in] addr Адрес ведомого устройства----Slave address
    //! \param[in] mbBuf Буфер обмена, который будет отправлен----The clipboard that will be sent.
    //! \param[in] fRegAddr Адрес первого элемента, значение которого требуется записать----Address of the first element which value needs to be written
    //! \param[in] count Количество записываемых элементов----Number of read elements
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
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
    //! Обмен с устройством данными по шине----Exchanging data with the device over the bus
    //! \param[inout] mbBuf Буфер обмена, данные из него будут записаны с добавленной CRC, и в него будут считан ответ без CRC----Clipboard, the data from it will be written with CRC added, and the response without CRC will be read into it 
    //! \param[inout] size Размер буфера обмена----Clipboard size
    //! \return Код ошибки MB_ERR_*. MB_ERR_OK если транзакция прошла успешно----MB_ERR_* error code. MB_ERR_OK if successful
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
        //Проверяем CRC----Checking CRC
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

main()
{
    /*! Введение.----Introduction.

        Протокол модбас широко распространен во всем мире, чаще всего используется в умных домах и для обмена данными с периферией 
        в качестве периферии у нас будет 4х символьный дисплей СМИ2, на его примере и будем разбирать принципы работы протокола и
        нашей библиотеки.
        The Modbus protocol is widely spread around the world.
        It is mostly used in smart homes and for exchanging data with external devices Today we have a four-symbol display as
        an example for looking at the protocol and library operation principles.
        
        Особенностями Modbus-RTU, а именно такой протокол используется в нашем случае, это то что он является бинарным, т.е.
        информация в нем передается байтами, а не символами.
        Т.е. полученное сообщение нельзя сразу прочитать, его приходится расшифровывать, также как и специальным образом
        компоновать передаваемую информацию.
        Функцию по компоновке сообщений выполняет наша библиотека Modbus, которая расположена выше, изменять что-либо в ней можно,
        но не нужно, в общем случае это и не требуется, просто пользуемся ей и всё должно работать.
        Modbus-RTU protocol is used in this case and its special feature is being binary which means the information is
        transmitted within bytes and not symbols while using this protocol. The received message cannot be read on the spot,
        but it should be parsed and the transmitted information should be arranged in a special way.
        The message arranging feature is performed with the Modbus library displayed above. It can be changed, but there is
        no need to do so as it is not required in general cases. The library can be used as it is for performing its goal.

        По протоколу модбас информация на периферии хранится в регистрах, например, температурный датчик, который может в модбас,
        измерил температуру воздуха, и записал результат себе в регистр с определенным номером, например №1.
        Наша задача обращаться к этим регистрам с информацией и считывать оттуда данные, или наоборот записывать в регистры данные,
        чтобы, например, СМИ2 стал отображать на своем дисплее записанное.
        Один регистр содержит два байта информации, если например температура занимает место - 4 байта, то используются два
        соседних регистра.
        The data is contained in registers in external devices, according to the Modbus protocol. For example, if a temperature
        sensor, that can work with modbus, checked the temperature, it will write the received data into its register with a
        specific number (e.g. №1). The purpose is to access these registers and read data from them or write data into them
        for the display to show the recorded value. One register contains 2 bytes of information. If the temperature occupies
        the space of 4 bytes, two near registers are used.
        
        При считывании или записи, мы указываем в аргументах номер первого регистра и следующим аргументом указываем количество
        регистров которое следует считать/записать разом.
        У каждого устройства периферии есть адрес к которому нам нужно обращаться, он записан как ADDRESS в самом верху библиотеки,
        его следует указывать исходя из настроек периферии.
        When reading or writing, the number of the first register is specified in the arguments and the next argument specifies
        the number of registers that should be read/written at the same time. Every external device has an address that should be
        referred, it is written as ADDRESS at the top of the library and it should be set according to the external devices settings.
    */
    
    // создаем массив(буфер) в который будем записывать данные перед отправкой на устройство ---- creating an array/buffer where the data will be written before sending to the device
    new mb_command{MB_BUF_SIZE} = 0 
    
    // инициализируем работу порта ---- initialising the port operation
    modbusInit()  

    // скомпануем посылаемое сообщение (это 4) в специальной структуры сообщение. ---- arranging the sent message (now it is 4) in a specifically structured message.
    setReg(mb_command, MB_WRITE_START, 4) 

    //отправим по адресу (ADDRESS) скомпанованную команду(mb_command) в нужный нам регистр ( 17 ), записать ---- sending the arranged command (mb_command) to the address (ADDRESS) to the needed register ( 17 ),
    // нужно только в один регистр, поэтому ( 1 ) ---- only one register should be written, so ( 1 ) is specified
    writeRegs(ADDRESS, mb_command, 17, 1) 

    //отправим по аналогии указанной выше команду на устройство (примени настройки) ---- sending the command to the device the same way to apply settings 
    //скомпануем ---- arranging
    setReg(mb_command, MB_WRITE_START, 0x81)
    //отправим на устройство ---- sending the command to the device
    writeRegs(ADDRESS, mb_command, 15, 1)

    // Теперь наш СМИ2 переведен в режим "ПОРТРЕТ". ---- The display is in the portrait mode now.
    // Зажгем все 4 верхних сегмента. ---- Let us light up all 4 upper segments.
    // Так как протокол модбас подразумевает регистры только по два байта то комманду придется формировать дважды. ---- Since the Modbus protocol implies registers of only two bytes each, the command will have to be formed twice.
    // Судя по инструкции за верхний сегмент (А) отвечает бит №7, то есть чтобы горел только верхний сегмент, наш ---- According to the manual, bit №7 corresponds to the upper segment, so to light up only the upper segment, 
    // байт должен выглядеть следующим образом: ---- the byte should look like this:
    // 1 0 0 0 0 0 0 0 - если перевести в человеческий вид = 127 в десятичном формате, или = 0x80 в шестнадцатеричном(HEX) ---- 1 0 0 0 0 0 0 0 = 127 in decimal format or = 0x80 in hexadecimal format(HEX)
    setReg(mb_command, MB_WRITE_START, 0x8080)
    setReg(mb_command, MB_WRITE_START + 2, 0x8080) //+2 потому что выше мы уже записали 2 байта, и тут пишем следующие два. ---- +2 is because 2 bytes have already been written.
    // Отправляем комманду на устройство, на этот раз записывать на устройство придется уже в два регистра подряд ---- Sending a command to the device, now the data should be written to 2 registers at once.
    writeRegs(ADDRESS, mb_command, 33, 2)
    Delay(10000)
    // Теперь включим все верхние, все средние и все нижние сегменты. ---- Now let us light up all upper segments, all middle segments and all lower ones.
    // Через калькулятор выбираем как выглядит код. ---- Choosing what the code lloks like in the calculator:
    // 1 0 0 1 0 0 1 0 - это =146(DEC) =0x92(HEX) нагляднее пользоваться HEX ---- 1 0 0 1 0 0 1 0 is =146(DEC) =0x92(HEX) but it is easier to use HEX
    setReg(mb_command, MB_WRITE_START, 0x9292)
    setReg(mb_command, MB_WRITE_START + 2, 0x9292) //+2 потому что выше мы уже записали 2 байта, и тут пишем следующие два. ---- +2 is because 2 bytes have already been written.
    // Отправляем комманду на устройство, также 2 регистра по 2 байта ---- Sending command to the device, again 2 registers of 2 bytes
    writeRegs(ADDRESS, mb_command, 33, 2)
    Delay(10000)

    // Обращаю внимание, та информация, что записана в регистре, она там остается пока не отключим питание, поэтому если ---- Note that the information stored in the register stays there until the power is turned off, so 
    // например послать команду на запись только одного регистра или даже одного байта в регистре, информация в остальных ---- if you send a command to write only one register or even one byte in the register, the information in the rest ones
    // останется прежней. ---- will stay the same.
    setReg(mb_command, MB_WRITE_START, 0x92)
    writeRegs(ADDRESS, mb_command, 33, 1)
    Delay(10000)

    // Пропадут сегменты только на крайнем левом 8-сегментном элементе. ---- Only the segments on the leftmost 8-segment element will be missing.
    // Очистим второй слева элемент дисплея. ---- Clearing the second display element from the left:
    setReg(mb_command, MB_WRITE_START, 0x9200)
    writeRegs(ADDRESS, mb_command, 33, 1)
    Delay(10000)

    //Исходя из спецификации, минимальное время смены символов - 200 мс. ---- Based on the specification, the minimum character change time is 200 ms.
    //Сейчас покажу фишку над которой поразмышляйте сами. ---- Here is the feature for your own consideration:
    setReg(mb_command, MB_WRITE_START, 0x0000)
    setReg(mb_command, MB_WRITE_START + 2, 0x0000)
    writeRegs(ADDRESS, mb_command, 33, 2)

    new j = 0

    while (j < 3)
    {
        new a = 2  //исключим парочку сегментов для красоты представления ---- let us exclude a couple of segments for a better display

        for (new i = 0; i < 6; i++)
        {
            a *= 2
            setReg(mb_command, MB_WRITE_START, a)  // тут значение принимает вид 0x00|_a| ---- the value takes the 0x00|_a| form here
            writeRegs(ADDRESS, mb_command, 33, 1)
            Delay(200)
        }

        j++
    }


    setReg(mb_command, MB_WRITE_START, 0x0000)
    setReg(mb_command, MB_WRITE_START + 2, 0x0000)
    writeRegs(ADDRESS, mb_command, 33, 2)

    j = 0
    while (j < 3)
    {
        new a = 2 //исключим парочку сегментов для красоты представления ---- let us exclude a couple of segments for a better display
        for (new i = 0; i < 6; i++)
        {
            a = a*2
            setReg(mb_command, MB_WRITE_START, a * 256) //256 это 0xFF, тоесть таким способом можно сдвинуть значение на один байт (0x|_a|00) ---- 256 is 0xFF, so this way you can shift the value by one byte (0x|_a|00)
            writeRegs(ADDRESS, mb_command, 33, 1)
            Delay(200)
        }

        j++
    }

    setReg(mb_command, MB_WRITE_START, 0x0000)
    setReg(mb_command, MB_WRITE_START + 2, 0x0000)
    writeRegs(ADDRESS, mb_command, 33, 2)

    j = 0
    while (j < 3)
    {
        new a = 2 //исключим парочку сегментов для красоты представления ---- let us exclude a couple of segments for a better display
        for (new i = 0; i < 6; i++)
        {
            a = a*2
            setReg(mb_command, MB_WRITE_START, a * 256)
            setReg(mb_command, MB_WRITE_START + 1, a * 256)
            setReg(mb_command, MB_WRITE_START + 2, a * 256)
            setReg(mb_command, MB_WRITE_START + 3, a * 256)
            writeRegs(ADDRESS, mb_command, 33, 1)
            Delay(200)
        }

        j++
    }
}
