new server{256} = "0.tcp.ngrok.io"
const PORT= 14227
new username{16} = "username"
new password{16} = "password"
const cr_symbol = 0x0D  // CR
const lf_symbol = 0x0A  // LF

clearArr(arr{}, length) {
    for (new q = 0; q <= length; q++) {
        arr{q}=0x00
    }
}

main()
{
new sendBufSize = 0
new sent = 0
const recvBufSize = 256
new recvBuf{recvBufSize}
new rcvd = 0

username{9} = cr_symbol
password{9} = cr_symbol

Diagnostics("Start connect to Telnet server")

if (!SocketOpen(server,PORT,30000))
{
    Diagnostics("Failed to open socket")
    return
}

Diagnostics("Receive greetings")
rcvd = 0
clearArr(recvBuf, recvBufSize);
if (!SocketRecv(recvBuf, recvBufSize, rcvd, 20000) || !rcvd)
{
    Diagnostics("Failed to recieve")
    SocketClose()
    return
}
Diagnostics("Received %d bytes: %s",rcvd, recvBuf)

Diagnostics("Send username")
sendBufSize = 9
sent = 0
if (!SocketSend(username, sendBufSize, sent, 30000) || !sent)
{
    Diagnostics("Failed to send")
    SocketClose()
    return
}
Diagnostics("username sent")

Diagnostics("Receive answer")
rcvd = 0
clearArr(recvBuf, recvBufSize);
if (!SocketRecv(recvBuf, recvBufSize, rcvd, 20000) || !rcvd)
{
    Diagnostics("Failed to recieve")
    SocketClose()
    return
}

Diagnostics("Received %d bytes: %s",rcvd, recvBuf)

Diagnostics("Send password")
sendBufSize = 9
sent = 0
if (!SocketSend(password, sendBufSize, sent, 30000) || !sent)
{
    Diagnostics("Failed to send")
    SocketClose()
    return
}

Diagnostics("password sent")

Diagnostics("Receive answer")
rcvd = 0
clearArr(recvBuf, recvBufSize);
if (!SocketRecv(recvBuf, recvBufSize, rcvd, 20000) || !rcvd)
{
    Diagnostics("Failed to recieve")
    SocketClose()
    return
}

Diagnostics("Received %d bytes: %s",rcvd, recvBuf)

Diagnostics("Close socket")

SocketClose()

}