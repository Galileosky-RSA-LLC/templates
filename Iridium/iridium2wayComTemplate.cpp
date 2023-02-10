// Шаблон для двусторонней коммуникации по спутниковому каналу Iridium ---- Template for two-way communication via Iridium satellite channel

const SENT_MES_MAX_SIZE = 340; // максимальный размер отправляемого сообщения ---- maximum message size to send
const MAX_MES_TO_TRANSMIT = 5; // максимальное количество сообщений для отправки ---- maximum number of messages to send
const RCV_MES_MAX_SIZE = 270; // максимальный размер принимаемого сообщения ---- maximum received message size
const BUF_SIZE = SENT_MES_MAX_SIZE; // максимальный размер буфера приема-передачи ---- maximum size of the receive-transmit buffer
const RCV_TIMEOUT = 1000; // время ожидания входящего сообщения ---- incoming message timeout
const IRIDIUM_DISABLED = 0; // статус выключенного модема Iridium ---- Iridium modem disabled status

main()
{
    Diagnostics("Попытка переключиться в режим Iridium через EL ---- try IridiumELMode");
    if (!IridiumELMode(true))
    {
        Diagnostics("Ошибка включения режима Iridium через EL ---- IridiumELMode error");
        return;
    }
    Diagnostics("Успешное включение режима Iridium через EL ---- IridiumELMode ok");
    while (true)
    {
        // получаем текущий статус работы модема Iridium ---- get the current status of the Iridium modem
        new status = GetVar(IRIDIUM_STATUS);
        Diagnostics("Статус модема Iridium ---- Iridium status=%d", status);
        if (status == IRIDIUM_DISABLED)
        {
            Diagnostics("Попытка включения модема Iridium ---- try IridiumEnable");
            if (!IridiumEnable(true))
            {    
                Diagnostics("Ошибка включения модема Iridium ---- IridiumEnable error");
                return;
            }
            Diagnostics("Успешное включение модема Iridium ---- IridiumEnable ok");
        }
        
        new buf{BUF_SIZE}; // буфер для принимаемых и отправляемых данных ---- buffer for received and sent data
        new bufActualSize; // актуальный размер данных в буфере ---- the actual size of the data in the buffer

        // пытаемся принять входящее сообщение ---- trying to receive an incoming message
        bufActualSize = IridiumReceive(buf, BUF_SIZE, RCV_TIMEOUT);
        if (bufActualSize > 0)
        {
            Diagnostics("Принято входящее сообщение Iridium: ---- Iridium incoming message received:");
            DiagnosticsHex(buf, bufActualSize); // вывели сообщение в диагностику ---- put a message in diagnostics
        }
        else
        {
            Diagnostics("Нет входящих сообщений Iridium ---- No incoming messages Iridium");
        }
        
        // как-то обрабатываем принятое сообщение ---- somehow handle the received message

        new sendQueueSize = IridiumGetCntMsgToTransmit(); // проверяем количество сообщений в очереди на отправку ---- check the number of messages in the queue for sending
        Diagnostics("Сообщений в очереди на отправку ---- messages to transmit=%d", sendQueueSize);
        if (sendQueueSize < MAX_MES_TO_TRANSMIT)
        {
            // формируем исходящее сообщение ---- create an outgoing message
            buf[0] = GetVar(UNIX_TIME);
            bufActualSize = 4;
            
            Diagnostics("Ставим в очередь исходящее сообщение: ---- Queuing a outgoing message:");
            DiagnosticsHex(buf, bufActualSize); // вывели сообщение в диагностику ---- put a message in diagnostics
            new res = IridiumTransmit(buf, bufActualSize); // ставим сообщение в очередь на отправку ---- put the message in the queue for sending
            if (res != 0)
                Diagnostics("Сообщение поставлено в очередь на отправку --- Message queued for sending");
            else
                Diagnostics("Ошибка очереди отправки сообщений ---- Send message queue error");
        }
        else
        {
            Diagnostics("Достигнут предел отправки сообщений ---- Send message limit reached");
        }
    }
}