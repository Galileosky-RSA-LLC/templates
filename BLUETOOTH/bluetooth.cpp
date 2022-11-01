// New script template.

// Write script description here.

main()
{
    
    const timeout = 2000
    const LEN_MAC = 6

    new MAC{LEN_MAC} = {0xEB, 0x62, 0xC9, 0x54, 0x24, 0x89}  // MAC: EB:62:C9:54:24:89
    new message[BTMSG]  // объявление структуры сообщения BLUETOOTH ---- declaration of the BLUETOOTH message structure

    // Delay(timeout)
    // DiagnosticsHex(MAC, LEN_MAC)

    BTInit()  // инициализация BLUETOOTH ---- BLUETOOTH initialisation
    
    while(1)
    {
        if (BTReceive(message, timeout) && GS_stringEquals(message.mac, MAC, LEN_MAC))
        {
            //Diagnostics("Received")
            Diagnostics("\nMAC: %X:%X:%X:%X:%X:%X", message.mac{0}, message.mac{1}, message.mac{2}, message.mac{3}, message.mac{4}, message.mac{5})
            Diagnostics("RSSI: %d", message.rssi | 0xFFFFFF00)

            if ( (message.rssi | 0xFFFFFF00) >= -30)
            {
                Diagnostics("Удивительно ---- Surprisingly Good")
            }
            else if ( (message.rssi | 0xFFFFFF00) >= -67)
            {
                Diagnostics("Очень хорошо ---- Very Good")
            }
            else if ( (message.rssi | 0xFFFFFF00) >= -70)
            {
                Diagnostics("Хорошо ---- Good")
            }
            else if ( (message.rssi | 0xFFFFFF00) >= -80)
            {
                Diagnostics("Не очень Хорошо ---- Not so Good")
            }
            else if ( (message.rssi | 0xFFFFFF00) >= -90)
            {
                Diagnostics("Не Хорошо ---- Not Good")
            }
            else
            {
                Diagnostics("Неиспользуемый ---- Unused")
            }

            Diagnostics("Data: size %d", message.dataSize)
            DiagnosticsHex(message.data, message.dataSize)
        }

        Delay(1000)
    }
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
        {
            return 0;
        }
    }
    
    return 1;
 }
