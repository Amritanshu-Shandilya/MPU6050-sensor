using System;
using System.IO.Ports;

class DataReceiver
{
    static void Main (String[] args)
    {
        SerialPort mySerialPort = new SerialPort("COM3", 115200);
        try
        {
            mySerialPort.Open();
            mySerialPort.DataReceived += (sender, e) =>
            {
                string data = mySerialPort.ReadExisting();
                Console.Write(data);
            };
            Console.ReadKey();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error : {ex.Message}");
        }
        finally {
            mySerialPort.Close(); 
        }
    }
}