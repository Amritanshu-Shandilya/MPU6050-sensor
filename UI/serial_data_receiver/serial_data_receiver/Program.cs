using System;
using System.IO.Ports;

class DataReceiver
{
    static void main (String[] args)
    {
        SerialPort mySerialPort = new SerialPort("COM3", 115200);
    }
}