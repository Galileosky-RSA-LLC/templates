# Поддержка протокола Galileosky в Multi-Protocol MasterOPC Server

Нужен [Multi-Protocol MasterOPC Server](https://masteropc.ru/multiprotocol) версия от 6.0.15.

gs.mpn - файл конфигурации сервера, поместить в папку "C:\ProgramData\InSAT\Multi-Protocol MasterOPC Server\SERVERCFG".

galileoskyMasterOpc.lua - файл скрипта разбора протокола [Galileosky](https://base.galileosky.com/articles/#!docs-publication/galileosky-protocol), поместить в папку "C:\ProgramData\InSAT\Multi-Protocol MasterOPC Server\MODULES".

MasterScada4proj.zip - проект для [MasterSCADA 4D](https://masterscada.ru/masterscada4d) с визуализацией нескольких тегов из OPC сервера.

В конфигурации OPC сервера перейти в узел Galileosky и указать IP адрес ПК, на котором запущен OPC, и порт.

В терминале указать соответствующие адрес и порт OPC сервера. Для передачи отметить теги, которые принимаются OPC сервером (см. в OPC, открыв файл конфигурации). Для добавления новых тегов см. комментарии в скрипте lua.

----
# Support for Galileosky protocol in Multi-Protocol MasterOPC Server

Need [Multi-Protocol MasterOPC Server](https://masteropc.ru/multiprotocol) version 6.0.15 or high.

gs.mpn - server configuration file, place in a folder "C:\ProgramData\InSAT\Multi-Protocol MasterOPC Server\SERVERCFG".

galileoskyMasterOpc.lua - protocol [Galileosky](https://base.galileosky.com/articles/#!docs-publication/galileosky-protocol) parsing script file, place in a folder "C:\ProgramData\InSAT\Multi-Protocol MasterOPC Server\MODULES".

MasterScada4proj.zip - project for [MasterSCADA 4D](https://masterscada.ru/masterscada4d) with visualization of several tags from the OPC server.

In the OPC server configuration, go to the Galileosky node and specify the IP address of the PC running OPC and the port.
In the terminal, specify the appropriate address and port of the OPC server. For transmission, mark the tags that are accepted by the OPC server (see in OPC, open configuration file). See the comments in the lua script for adding new tags.
