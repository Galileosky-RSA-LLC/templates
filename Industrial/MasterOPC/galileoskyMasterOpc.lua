---- Скрипт разбора протокола Galileosky https://base.galileosky.com/articles/#!docs-publication/galileosky-protocol

-- реализован прием всех тегов, кроме SPN (протокол J1939)
-- все полученные от терминала теги записываются в архив (HDA), наиболее новые из них записываются в текущие значения OPC тегов

---- Настройка терминала
-- в настройках протокола в каждом отправляемом пакете отметить тег "Дата и время", в т.ч. и в первом пакете
-- во всех пакетах для большей точности можно отметить тег "Миллисекунды"

---- Описание тегов OPC:
-- 1) префикс имени "tag_" означает, что тег "обычный" (не расширенный)
--    префикс имени "tagExt_" означает, что тег расширенный
-- 2) после первого "_" в имени идет десятичный номер тега, если тег при этом простой (т.е. не составной), то имя на этом заканчивается (например, tag_1),
--    если тег составной (т.е. состоит из субтегов, как например теги 0x30, 0x33 и т.п.), то после десятичного номера идет "_"
--    и далее десятичный номер субтега, начиная с 1 (например, tag_51_1, tag_51_2)
-- 3) в комментарии тега указано его наименование по протоколу
-- 4) разбираемые типы данных тегов: byte, sbyte, int16, uint16, int32, uint32, string
--    теги с 8-байтными типами данных разбираются как пары 4-байтных субтегов
--    (например, теги OPC "tagExt_253_1" и "tagExt_253_2" соответствуют расширенному тегу протокола 0x00FD "iButton64")
--    если тип данных - string, то в комментарии тега после "," указывается длина строки в байтах (например, "IMEI,15" - строка 15 байт)

PACK_HEADER_POS = 1
PACK_HEADER_LENGTH = 1
PACK_SIZE_LO_POS = PACK_HEADER_POS + PACK_HEADER_LENGTH
PACK_SIZE_HI_POS = PACK_SIZE_LO_POS + 1
PACK_HAS_UNSENT_BIT = 7
SIZE_LENGTH = 2
PACK_TAG_POS = PACK_SIZE_LO_POS + SIZE_LENGTH
CRC_LENGTH = 2
PACK_IN_SIZE_MIN = PACK_HEADER_LENGTH + SIZE_LENGTH + CRC_LENGTH
GENERAL_PACK_HEADER = 0x01
CONFIRM_PACK_HEADER = 0x02
CONFIRM_PACK_SIZE = 3
GARMIN_PACK_HEADER = 0x06
COMPRESSED_PACK_HEADER = 0x08
EXT_TAGS_FLAG = 0xFE
PACK_MAX_SIZE = 8192
DATA_SIZE_MAX = PACK_MAX_SIZE - SIZE_LENGTH - PACK_HEADER_LENGTH - CRC_LENGTH
PACK_RECEIVE_MAX_TIME_S = 120
TAG_DATETIME_COMMENT = "dateTime"
TAG_MS_COMMENT = "ms"
TAG_GENERAL_PREFIX = "tag_"
TAG_EXT_PREFIX = "tagExt_"
TAG_VALUE_TYPE_NUMBER = "NUM"
TAG_VALUE_TYPE_STRING = "STR"

TAG_REFRIGERATOR_ID = 0x5B

TAG_REFRIGERATOR_FLAGS_BYTE = 1
TAG_REFRIGERATOR_FLAGS_SIZE = 2
TAG_REFRIGERATOR_ZONE1_BIT = 1
TAG_REFRIGERATOR_ZONE2_BIT = 2
TAG_REFRIGERATOR_ZONE3_BIT = 3
TAG_REFRIGERATOR_TEMP_SENSOR_1_BIT = 4
TAG_REFRIGERATOR_TEMP_SENSOR_2_BIT = 5
TAG_REFRIGERATOR_TEMP_SENSOR_3_BIT = 6
TAG_REFRIGERATOR_TEMP_SENSOR_4_BIT = 7
TAG_REFRIGERATOR_TEMP_SENSOR_5_BIT = 8
TAG_REFRIGERATOR_TEMP_SENSOR_6_BIT = 9
TAG_REFRIGERATOR_ALARMS_BIT = 10
TAG_REFRIGERATOR_MAINTENANCE_BIT = 11
TAG_REFRIGERATOR_OPERATING_BIT = 12
TAG_REFRIGERATOR_REQUESTS_FAILURE_BIT = 13
TAG_REFRIGERATOR_ENGINE_SPEED_BIT = 14

TAG_REFRIGERATOR_STATIC_SIZE = 7
TAG_REFRIGERATOR_STATIC_SUBTAGS = 6

TAG_REFRIGERATOR_ZONE_SUBTAGS = 6
TAG_REFRIGERATOR_ZONE1_SUBTAG_START = TAG_REFRIGERATOR_STATIC_SUBTAGS + 1
TAG_REFRIGERATOR_ZONE2_SUBTAG_START = TAG_REFRIGERATOR_ZONE1_SUBTAG_START + TAG_REFRIGERATOR_ZONE_SUBTAGS
TAG_REFRIGERATOR_ZONE3_SUBTAG_START = TAG_REFRIGERATOR_ZONE2_SUBTAG_START + TAG_REFRIGERATOR_ZONE_SUBTAGS

TAG_REFRIGERATOR_MAX_TEMP_SENSORS = 6
TAG_REFRIGERATOR_TEMP_SENSOR_1_SUBTAG = TAG_REFRIGERATOR_ZONE3_SUBTAG_START + TAG_REFRIGERATOR_ZONE_SUBTAGS
TAG_REFRIGERATOR_TEMP_SENSOR_2_SUBTAG = TAG_REFRIGERATOR_TEMP_SENSOR_1_SUBTAG + 1
TAG_REFRIGERATOR_TEMP_SENSOR_3_SUBTAG = TAG_REFRIGERATOR_TEMP_SENSOR_2_SUBTAG + 1
TAG_REFRIGERATOR_TEMP_SENSOR_4_SUBTAG = TAG_REFRIGERATOR_TEMP_SENSOR_3_SUBTAG + 1
TAG_REFRIGERATOR_TEMP_SENSOR_5_SUBTAG = TAG_REFRIGERATOR_TEMP_SENSOR_4_SUBTAG + 1
TAG_REFRIGERATOR_TEMP_SENSOR_6_SUBTAG = TAG_REFRIGERATOR_TEMP_SENSOR_5_SUBTAG + 1

TAG_REFRIGERATOR_ALARMS_SUBTAGS = 8
TAG_REFRIGERATOR_ALARMS_SUBTAG_START = TAG_REFRIGERATOR_TEMP_SENSOR_6_SUBTAG + 1

TAG_REFRIGERATOR_MAINTENANCE_SUBTAGS = 5
TAG_REFRIGERATOR_MAINTENANCE_SUBTAG_START = TAG_REFRIGERATOR_ALARMS_SUBTAG_START + TAG_REFRIGERATOR_ALARMS_SUBTAGS

TAG_REFRIGERATOR_OPERATING_SUBTAGS = 3
TAG_REFRIGERATOR_OPERATING_SUBTAG_START = TAG_REFRIGERATOR_MAINTENANCE_SUBTAG_START + TAG_REFRIGERATOR_MAINTENANCE_SUBTAGS

TAG_REFRIGERATOR_REQUESTS_FAILURE_SUBTAG = TAG_REFRIGERATOR_OPERATING_SUBTAG_START + TAG_REFRIGERATOR_OPERATING_SUBTAGS
TAG_REFRIGERATOR_ENGINE_SPEED_SUBTAG = TAG_REFRIGERATOR_REQUESTS_FAILURE_SUBTAG + 1

TAG_REFRIGERATOR_ZONE_SIZE = 10
TAG_REFRIGERATOR_TEMP_SENSOR_SIZE = 2
TAG_REFRIGERATOR_ALARMS_SIZE = 32
TAG_REFRIGERATOR_MAINTENANCE_SIZE = 20
TAG_REFRIGERATOR_OPERATING_SIZE = 12
TAG_REFRIGERATOR_REQUESTS_FAILURE_SIZE = 2
TAG_REFRIGERATOR_ENGINE_SPEED_SIZE = 2

TAG_USER_ARRAY_ID = 0xEA

refrigeratorSizes = {TAG_REFRIGERATOR_ZONE_SIZE,
                    TAG_REFRIGERATOR_ZONE_SIZE,
                    TAG_REFRIGERATOR_ZONE_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_TEMP_SENSOR_SIZE,
                    TAG_REFRIGERATOR_ALARMS_SIZE,
                    TAG_REFRIGERATOR_MAINTENANCE_SIZE,
                    TAG_REFRIGERATOR_OPERATING_SIZE,
                    TAG_REFRIGERATOR_REQUESTS_FAILURE_SIZE,
                    TAG_REFRIGERATOR_ENGINE_SPEED_SIZE}

refrigeratorSubTagIndexes = {{TAG_REFRIGERATOR_ZONE1_SUBTAG_START, TAG_REFRIGERATOR_ZONE_SUBTAGS},
                            {TAG_REFRIGERATOR_ZONE2_SUBTAG_START, TAG_REFRIGERATOR_ZONE_SUBTAGS},
                            {TAG_REFRIGERATOR_ZONE3_SUBTAG_START, TAG_REFRIGERATOR_ZONE_SUBTAGS},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_1_SUBTAG, 1},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_2_SUBTAG, 1},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_3_SUBTAG, 1},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_4_SUBTAG, 1},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_5_SUBTAG, 1},
                            {TAG_REFRIGERATOR_TEMP_SENSOR_6_SUBTAG, 1},
                            {TAG_REFRIGERATOR_ALARMS_SUBTAG_START, TAG_REFRIGERATOR_ALARMS_SUBTAGS},
                            {TAG_REFRIGERATOR_MAINTENANCE_SUBTAG_START, TAG_REFRIGERATOR_MAINTENANCE_SUBTAGS},
                            {TAG_REFRIGERATOR_OPERATING_SUBTAG_START, TAG_REFRIGERATOR_OPERATING_SUBTAGS},
                            {TAG_REFRIGERATOR_REQUESTS_FAILURE_SUBTAG, 1},
                            {TAG_REFRIGERATOR_ENGINE_SPEED_SUBTAG, 1}}

pack = ""
dataSize = 0
hasUnsentData = false
packStartTime = 0
opertags = {} -- {name, value, timeStamp} - костыль, потому что если читать из тега, то иногда получаем архивное значение, хотя по документации не должны

-- initialize
function OnInit()
    for i = 0, server.GetCountTags() - 1, 1 do
        local success, err, attributes = pcall(server.GetAttributeTagByNumber, i)
        if success
        then
            if err
            then
                server.Message("getAttrTagByNumber ", i, "?")
            else
                local value
                if attributes[8] == "string"
                then
                    value = ""
                else
                    value = 0
                end
                server.WriteTagByNumber(i, value, OPC_QUALITY_OUT_OF_SERVICE)
            end
        else
            server.Message("getAttrTagByNumber ", i, "?res=", err)
        end
    end
    resetPack()
end

-- handling
function OnBeforeReading()
    if not getPack()
    then
        server.Message("pack?")
        return
    end
    parseTags()
    sendConfirm()
    delPack()
end

-- handling
function OnAfterReading()
end

-- deinitialize
function OnClose()
end

function setOpertag(opertagIdx, value, timeStamp)
    opertags[opertagIdx][2] = value
    opertags[opertagIdx][3] = timeStamp
end

function addOpertag(tagName, value, timeStamp)
    table.insert(opertags, {tagName, value, timeStamp})
end

function getOpertag(opertagIdx)
    return opertags[opertagIdx][2], opertags[opertagIdx][3]
end

function isOpertagOld(opertagIdx, newTimeStamp)
    return (opertagIdx == nil) or (opertagIdx <= 0) or (opertags[opertagIdx][2] == nil) or (opertags[opertagIdx][3] == nil)
            or (newTimeStamp > opertags[opertagIdx][3])
end

function getOpertagIdx(tagName)
    for i = 1, table.maxn(opertags), 1 do
        if opertags[i][1] == tagName
        then
            return i
        end
    end
    return 0
end

function sendConfirm()
    local sendBuf = makeConfirm()
    local err
    for i = 1, server.GetCurrentDeviceRetry(), 1 do
        err = server.SendAndReceiveData(sendBuf, CONFIRM_PACK_SIZE, 0)
        if not err
        then
            break
        end
        server.Message("sndErr #", i)
    end
end

function getPack()
    local err
    local chunk = ""
    local size = 0
    err, chunk, size = server.SendAndReceiveData("", 0, PACK_MAX_SIZE)
    if err
    then
        if (time.TimeNow() > time.TimeAddSec(packStartTime, PACK_RECEIVE_MAX_TIME_S))
        then
            resetPack()
        end
    else
        server.Message("rcv chunk")
        if (pack:len() <= 0)
        then
            packStartTime = time.TimeNow()
        end
        pack = pack .. chunk
        repeat
            if (pack:len() >= PACK_IN_SIZE_MIN) and (dataSize == 0) and (not getPackParams())
            then
                resetPack()
                return false
            end
            if pack:len() >= (dataSize + PACK_IN_SIZE_MIN)
            then
                err = not isPackCorrect()
                if not err
                then
                    return true
                end
                server.Message("crc?")
                delPack()
                if (pack:len() >= PACK_IN_SIZE_MIN)
                then
                    err = false
                end
            else
                err = true -- т.к. пока только часть
            end
        until err or (pack:len() < PACK_IN_SIZE_MIN)
    end
    return not err
end

function makeConfirm()
    return string.char(CONFIRM_PACK_HEADER) .. getCrcStr()
end

function getCrcStr()
    local pos = getCrcPos()
    return pack:sub(pos, pos + 1)
end

function getCrcPos()
    return PACK_TAG_POS + dataSize
end

function resetPack()
    pack = ""
    dataSize = 0
    hasUnsentData = false
    packStartTime = time.TimeNow()
    server.Message("reset pack")
end

function delPack()
    server.Message("del pack")
    pack = pack:sub(dataSize + PACK_IN_SIZE_MIN + 1, pack:len())
    dataSize = 0
    packStartTime = time.TimeNow()
end

function getPackParams()
    if (pack:byte(PACK_HEADER_POS) ~= GENERAL_PACK_HEADER)
    then
        server.Message("header? ", pack:byte(PACK_HEADER_POS))
        return false
    end
    hasUnsentData = bit.BitFromData(pack:byte(PACK_SIZE_LO_POS), PACK_HAS_UNSENT_BIT)
    if hasUnsentData
    then
        server.Message("has unsent")
    end
    dataSize = bytes2uint(string.char(pack:byte(PACK_SIZE_LO_POS), bit.BitToData(pack:byte(PACK_SIZE_HI_POS), false, PACK_HAS_UNSENT_BIT)))
    server.Message("dataSize=", dataSize)
    if (dataSize <= 0) or (dataSize > DATA_SIZE_MAX)
    then
        server.Message("dataSize?")
        return false
    end
    return true
end

function isPackCorrect()
    local crcPos = getCrcPos()
    return calcCrc(pack, crcPos - 1) == bytes2uint(pack:sub(crcPos, crcPos + 1))
end

function calcCrc(buf, size)
    local auchCrcHi = {
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
        0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
        0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
        0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
        0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
        0x40
        }
    local auchCrcLo = {
        0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
        0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
        0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
        0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
        0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
        0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
        0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
        0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
        0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
        0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
        0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
        0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
        0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
        0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
        0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
        0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
        0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
        0x40
        }
    local crcHi = 0xFF
    local crcLo = 0xFF
    local uIndex = 0
    local i = 0
    for i = 1, math.min(size, buf:len()), 1 do
        uIndex = bit.BitXor(crcLo, buf:byte(i)) + 1
        crcLo = bit.BitXor(crcHi, auchCrcHi[uIndex])
        crcHi = auchCrcLo[uIndex]
    end
    return crcLo + bit.BitAnd(bit.BitLshift(crcHi, 8), 0xFFFF)
end

function str2AsciiHex(str)
    local hex = ""
    for i = 1, #str, 1 do
        hex = hex .. string['format']('%02X', str:byte(i))
    end
    return hex
end

function parseTags()
    server.Message("pack=[", str2AsciiHex(pack), "]")
    local pos = PACK_TAG_POS
    local maxPos = getCrcPos() - 1
    local rec = -1
    while pos <= maxPos do
        rec = rec + 1
        server.Message("rec=", rec)
        local timeStamp = getRecTimeStamp(pos, maxPos)
        if timeStamp == nil
        then
            server.Message("timeStamp?")
        else
            server.Message("timeStamp=", time.TimeStampToString(timeStamp))
        end
        local extTags = false
        local recMaxPos = maxPos
        while pos <= recMaxPos do
            if not extTags and (pack:byte(pos) == EXT_TAGS_FLAG)
            then
                -- начало расширенных тегов
                if (pos + 2) <= recMaxPos
                then
                    local extSize = bytes2uint(pack:sub(pos + 1, pos + 2))
                    recMaxPos = pos + 2 + extSize
                    if timeStamp == nil
                    then
                        pos = recMaxPos + 1 -- т.к. без метки времени запись бесполезна
                    else
                        extTags = true
                        pos = pos + 3
                    end
                else
                    server.Message("extTags?pos=", pos)
                    pos = recMaxPos + 1
                end
            else
                if timeStamp == nil
                then
                    -- пропускаем теги, т.к. без метки времени запись бесполезна
                    local tagId
                    tagId, pos = getTagId(pos, recMaxPos, extTags)
                    if tagId ~= nil
                    then
                        local size
                        size, pos = getTagSize(pos, recMaxPos, tagId, extTags)
                        if size == nil
                        then
                            pos = nil
                        else
                            pos = pos + size
                        end
                    end 
                else
                    pos = getAndWriteTag(pos, recMaxPos, extTags, timeStamp)
                end
                if pos == nil
                then
                    server.Message("tag?pos=", pos)
                    pos = recMaxPos + 1
                end
            end
        end
    end
    server.Message("tagsParsingDone")
end

function getRecTimeStamp(startRecPos, maxPos)
    server.Message("getRecTimeStamp pos=", startRecPos)
    local dateTime
    local ms
    local pos = startRecPos
    maxPos = math.min(maxPos, pack:len() - CRC_LENGTH)
    while (pos <= maxPos) and (pack:byte(pos) ~= EXT_TAGS_FLAG) and ((dateTime == nil) or (ms == nil)) do
        local tagId
        tagId, pos = getTagId(pos, maxPos, false)
        if tagId == nil
        then
            server.Message("tagId?pos=", pos)
            return
        end
        local tagName = getRelativeTagName(tagId, false)
        local tagComment = getTagComment(tagName)
        if tagComment == TAG_MS_COMMENT
        then
            ms, pos = getTagValue(pos, maxPos, tagName)
        else if tagComment == TAG_DATETIME_COMMENT
        then
            dateTime, pos = getTagValue(pos, maxPos, tagName)
        else
            local size
            size, pos = getTagSize(pos, maxPos, tagId, false)
            if (size == nil) or (size == 0)
            then
                server.Message("tagSize?id=", tagId)
                return
            end
            pos = pos + size
        end
        end
        if pos == nil
        then
            server.Message("tagValue?name=", tagName)
            return
        end
    end
    if dateTime == nil
    then
        return
    end
    if ms == nil
    then
        ms = 0
    end
    return time.TimeToTimeStamp(dateTime, ms)
end

function getTagId(pos, maxPos, extTag)
    server.Message("getTagId pos=", pos, ",ext=", extTag)
    if extTag
    then
        return getValueNbytes(pos, maxPos, 2, false)
    end
    return getValueNbytes(pos, maxPos, 1, false)
end

function getTagSize(pos, maxPos, id, extTag)
    server.Message("getTagSize pos=", pos, ",maxPos=", maxPos, ",id=", id, ",ext=", extTag)
    if id == TAG_REFRIGERATOR_ID and not extTag
    then
        return getTagRefrigeratorSize(pos, maxPos)
    end
    if id == TAG_USER_ARRAY_ID and not extTag
    then
        if pos > maxPos
        then
            return
        end
        return pack:byte(pos), pos + 1
    end
    local tagName = getRelativeTagName(id, extTag)
    local size = getValueType(tagName)
    if size ~= nil
    then
        return size, pos
    end
    if not isTagMixed(id, extTag)
    then
        return
    end
    local sub = 1
    local prefix = tagName .. "_"
    local totalSize = 0
    repeat
        tagName = prefix .. sub
        size = getValueType(tagName)
        if size == nil
        then
            if sub == 1
            then
                return
            end
        else
            totalSize = totalSize + size
            sub = sub + 1
        end
    until size == nil
    return totalSize, pos
end

function getTagRefrigeratorSize(pos, maxPos)
    server.Message("getRefrSize pos=", pos, ",maxPos=", maxPos)
    pos = pos + TAG_REFRIGERATOR_FLAGS_BYTE
    local flags
    flags, pos = getValueNbytes(pos, maxPos, TAG_REFRIGERATOR_FLAGS_SIZE, false)
    if flags == nil
    then
        return
    end
    local size = TAG_REFRIGERATOR_STATIC_SIZE
    for i = 1, table.maxn(refrigeratorSizes), 1 do
        if bit.BitFromData(flags, i)
        then
            size = size + refrigeratorSizes[i]
        end
    end
    return size, pos + TAG_REFRIGERATOR_FLAGS_SIZE
end

function getValueType(tagName)
    server.Message("getValType name=", tagName)
    local success, err, attribute = pcall(server.GetAttributeTagByRelativeName, tagName) -- без pcall будет ошибка при несуществующем теге
    if not success or err
    then
        server.Message("gAttr?er=", err)
        return
    end
    if attribute[8] == "byte"
    then
        return 1, TAG_VALUE_TYPE_NUMBER, false
    end
    if attribute[8] == "sbyte"
    then
        return 1, TAG_VALUE_TYPE_NUMBER, true
    end
    if attribute[8] == "uint16"
    then
        return 2, TAG_VALUE_TYPE_NUMBER, false
    end
    if attribute[8] == "int16"
    then
        return 2, TAG_VALUE_TYPE_NUMBER, true
    end
    if attribute[8] == "uint32"
    then
        return 4, TAG_VALUE_TYPE_NUMBER, false
    end
    if attribute[8] == "int32"
    then
        return 4, TAG_VALUE_TYPE_NUMBER, true
    end
    if attribute[8] == "string"
    then
        local pos = attribute[3]:find(",")
        if pos == nil
        then
            return
        end
        local size = tonumber(attribute[3]:sub(pos + 1))
        return size, TAG_VALUE_TYPE_STRING
    end
end

function getRelativeTagName(id, extTag)
    server.Message("getRelativeTagName id=", id, ",ext=", extTag)
    if id == nil
    then
        return ""
    end
    if extTag
    then
        return TAG_EXT_PREFIX .. id
    end
    return TAG_GENERAL_PREFIX .. id
end

function isTagMixed(id, extTag)
    server.Message("isTagMixed id=", id, ",ext=", extTag)
    local tagName = getRelativeTagName(id, extTag)
    if isTagExist(tagName)
    then
        return false
    end
    return isTagExist(tagName .. "_1")
end

function getTagComment(tagName)
    server.Message("getTagComment name=", tagName)
    local success, err, attribute = pcall(server.GetAttributeTagByRelativeName, tagName)
    if not success or err
    then
        return ""
    end
    return attribute[3]
end

function isTagExist(tagName)
    server.Message("isTagExist name=", tagName)
    local success, err = pcall(server.GetAttributeTagByRelativeName, tagName)
    return success and not err
end

function getSubTagsNames(id, extTag)
    server.Message("getSubTagsNames id=", id, ",ext=", extTag)
    local tagNames = {}
    if (id == nil) or (extTag == nil)
    then
        return tagNames
    end
    local sub = 1
    local prefix = getRelativeTagName(id, extTag) .. "_"
    repeat
        local name = prefix .. sub
        local exist = isTagExist(name)
        if exist
        then
            table.insert(tagNames, name)
            sub = sub + 1
        end
    until not exist
    return tagNames
end

function getTagValue(pos, maxPos, tagName)
    server.Message("getTagValue pos=", pos, ",name=", tagName)
    local size
    local valType
    local signed
    size, valType, signed = getValueType(tagName)
    server.Message("size=", size, ",type=", valType, ",signed=", signed)
    if size == nil
    then
        server.Message("size?tagName=", tagName)
        return
    end
    local value = nil
    if valType == TAG_VALUE_TYPE_NUMBER
    then
        value, pos = getValueNbytes(pos, maxPos, size, signed)
    else if valType == TAG_VALUE_TYPE_STRING
    then
        value = pack:sub(pos, pos + size - 1)
        pos = pos + size
    else
        server.Message("type?tagName=", tagName)
        return
    end
    end
    return value, pos
end

function getAndWriteTag(pos, maxPos, extTag, timeStamp)
    server.Message("tag pos=", pos, ",maxPos=", maxPos, ",ext=", extTag)
    local tagId
    tagId, pos = getTagId(pos, maxPos, extTag)
    if tagId == nil
    then
        server.Message("tagId?")
        return
    end
    local tagNames = {}
    if (tagId == TAG_REFRIGERATOR_ID) and (not extTag)
    then
        tagNames = getRefrigeratorSubTagNames(pos, maxPos)
        if table.maxn(tagNames) == 0
        then
            server.Message("tagNames?")
            return
        end
    else
        local name = getRelativeTagName(tagId, extTag)
        if isTagExist(name)
        then
            table.insert(tagNames, name)
        else if not isTagMixed(tagId, extTag)
        then
            server.Message("tagName?")
            return
        else
            tagNames = getSubTagsNames(tagId, extTag)
        end
        end
    end
    local count
    local userArraySize
    if (tagId == TAG_USER_ARRAY_ID) and (not extTag)
    then
        if pos > maxPos
        then
            return
        end
        userArraySize = pack:byte(pos)
        count = math.ceil(userArraySize / 4) + 1
        server.Message("userArraySize=", userArraySize, ",vars=", count)
    else
        count = table.maxn(tagNames)
    end
    local i
    server.Message("subTags=", count)
    for i = 1, count, 1 do
        local value
        if (tagId == TAG_USER_ARRAY_ID) and (not extTag) and (i == count) and (i > 1)
        then
            value, pos = getValueNbytes(pos, maxPos, userArraySize + 8 - 4 * count, true)
        else
            value, pos = getTagValue(pos, maxPos, tagNames[i])
        end
        if value == nil
        then
            server.Message("val?tagName=", tagNames[i])
            return
        else
            server.Message(tagNames[i], "=", value)
            local success, res = pcall(server.WriteTagByRelativeNameToHda, tagNames[i], value, OPC_QUALITY_GOOD, timeStamp)
            if not success
            then
                server.Message("wTagHda?res=", res)
            end
            if not writeToTag(tagNames[i], value, timeStamp)
            then
                server.Message("wTag?")
                return
            end
            
        end
    end
    return pos
end

function getRefrigeratorSubTagNames(pos, maxPos)
    local flags
    flags, pos = getRefrigeratorFlags(pos, maxPos)
    if flags == nil
    then
        return {}
    end
    local prefix = getRelativeTagName(TAG_REFRIGERATOR_ID, false) .. "_"
    local names = {}
    for i = 1, TAG_REFRIGERATOR_STATIC_SUBTAGS, 1 do
        table.insert(names, prefix .. i)
    end
    for i = 1, table.maxn(refrigeratorSizes), 1 do
        if bit.BitFromData(flags, i)
        then
            for j = 0, refrigeratorSubTagIndexes[i][2] - 1, 1 do
                table.insert(names, prefix .. (j + refrigeratorSubTagIndexes[i][1]))
            end
        end
    end
    return names
end

function getRefrigeratorFlags(pos, maxPos)
    if (pos + TAG_REFRIGERATOR_FLAGS_BYTE) > maxPos
    then
        return
    end 
    pos = pos + TAG_REFRIGERATOR_FLAGS_BYTE
    return getValueNbytes(pos, maxPos, TAG_REFRIGERATOR_FLAGS_SIZE, false)
end

function writeToTag(tagName, value, timeStamp)
    server.Message("writeToTag name=", tagName, ",val=", value, ",ts=", time.TimeStampToString(timeStamp))
    if (value == nil) or (timeStamp == nil)
    then
        return false
    end
    local writeVal = value
    local writeTimeStamp = timeStamp
    local idx = getOpertagIdx(tagName)
    if idx > 0
    then
        local prevVal, prevTimeStamp = getOpertag(idx)
        if isOpertagOld(idx, timeStamp)
        then
            setOpertag(idx, value, timeStamp)
        else
            writeVal = prevVal
            writeTimeStamp = prevTimeStamp
            server.Message("old")
        end
    else
        addOpertag(tagName, value, timeStamp)
    end
    local success, res = pcall(server.WriteTagByRelativeName, tagName, writeVal, OPC_QUALITY_GOOD, writeTimeStamp)
    if not success
    then
        server.Message(res)
    end
    return success
end

function getValueNbytes(pos, maxPos, bytes, signed)
    if (pos == nil) or (maxPos == nil) or (bytes == nil) or ((pos + bytes - 1) > maxPos) or (bytes < 1) or (bytes > 4)
    then
        return
    end
    local value = 0
    if signed
    then
        value = bytes2int(pack:sub(pos, pos + bytes - 1))
    else
        value = bytes2uint(pack:sub(pos, pos + bytes - 1))
    end
    return value, pos + bytes
end

function bytes2uint(str)
    local uint = 0
    for i = 1, #str do
        uint = uint + str:byte(i) * 0x100^(i-1)
    end
    return uint
end

function bytes2int(str)
    local uint = bytes2uint(str)
    local max = 0x100 ^ #str
    if uint >= max / 2
    then
        return uint - max
    end
    return uint
end