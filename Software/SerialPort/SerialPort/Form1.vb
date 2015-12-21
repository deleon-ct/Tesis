Imports System
Imports System.Threading
Imports System.IO.Ports
Imports System.ComponentModel

#Const INIT = 38
#Const RELEA = &HF1
#Const RELEB = &HF2
#Const RELEM = &HF3
#Const RELEN = &HF4
#Const ACK = &HF5
#Const RETRANS = &HF6
#Const OFF = &HF7
#Const DSP_LED5_ON = &HE5
#Const DSP_LED5_OFF = &HE6
#Const DSP_LED6_ON = &HE7
#Const DSP_LED6_OFF = &HE8
#Const CLI36 = &H36
#Const CLI44 = &H44


Public Class Form1

    Dim myPorts As Array
    Dim receivedData As Byte
    Dim dataINI As Int16
    Dim dataID As Int16
    Dim dataCRC As Int16

    Delegate Sub SetTextCallBack(ByVal [text] As String)

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        myPorts = IO.Ports.SerialPort.GetPortNames()
        portComboBox.Items.AddRange(myPorts)

        btnEnviar.Enabled = False

    End Sub

    Private Sub btnAbrir_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnAbrir.Click
        SerialPort1.PortName = portComboBox.Text
        'SerialPort1.BaudRate = 9600
        SerialPort1.BaudRate = baudComboBox.Text
        SerialPort1.Encoding = System.Text.Encoding.GetEncoding(28605)

        SerialPort1.Open()
        SerialPort1.RtsEnable = True

        btnEnviar.Enabled = True
        lblEstado.Text = "Conectado"

    End Sub

    Private Sub btnEnviar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnEnviar.Click
        SerialPort1.Write(textToSend.Text)

    End Sub

    Private Sub btnCerrar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCerrar.Click
        SerialPort1.Close()

        btnEnviar.Enabled = True
        lblEstado.Text = "No Conectado"

    End Sub

    Private Sub SerialPort1_DataReceived(ByVal sender As System.Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        RecepcionTexto(SerialPort1.ReadExisting())

    End Sub

    Private Sub Label4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label4.Click

    End Sub

    Private Sub RichTextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub

    Private Sub RecepcionTexto(ByVal [text] As String)
        If Me.receivedTextBox.InvokeRequired Then
            Dim x As New SetTextCallBack(AddressOf RecepcionTexto)
            Me.Invoke(x, New Object() {(text)})
        Else
            Me.receivedTextBox.Text &= [text]
        End If
    End Sub

    Private Sub Label2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label2.Click

    End Sub

    Private Sub Label3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label3.Click

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)

        Thread.Sleep(500)

    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click

    End Sub

    Private Sub Label5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lblEstado.Click

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click


    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click


    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'SerialPort1.RtsEnable = False

        'Thread.Sleep(10)

        'datoTx = &H65
        'SerialPort1.Write(Convert.ToChar(datoTx))

        'SerialPort1.RtsEnable = True

    End Sub


    Private Sub Envio_Datos(ByVal dataID2 As UInt16, ByVal dataFUNC As UInt16)

        dataINI = &H60 'caracter inicio protocolo'
        dataID = &H75   'ID del DSP'
        dataCRC = &H6F


        SerialPort1.RtsEnable = False
        Thread.Sleep(10)

        SerialPort1.Write(Convert.ToChar(dataINI))
        SerialPort1.Write(Convert.ToChar(dataID2))
        SerialPort1.Write(Convert.ToChar(dataFUNC))
        SerialPort1.Write(Convert.ToChar(dataID2 - dataFUNC))

        Thread.Sleep(5)
        SerialPort1.RtsEnable = True
    End Sub

    Private Sub receivedTextBox_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub

    Private Sub RichTextBox1_TextChanged_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles receivedTextBox.TextChanged

    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnBorrar.Click
        receivedTextBox.Clear()

    End Sub

    Private Sub textToSend_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles textToSend.TextChanged

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)


    End Sub

    Private Sub Button7_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSchlumber.Click
        Envio_Datos(&H75, &H44)
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnWenner.Click
        Envio_Datos(&H75, &H4F)

    End Sub

    Private Sub Button4_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClave.Click
        SerialPort1.RtsEnable = False

        SerialPort1.Write("c")
        Thread.Sleep(5)
        SerialPort1.Write("o")
        Thread.Sleep(5)
        SerialPort1.Write("p")
        Thread.Sleep(5)
        SerialPort1.Write("e")
        Thread.Sleep(5)
        SerialPort1.Write("t")
        Thread.Sleep(5)
        SerialPort1.Write("t")
        Thread.Sleep(5)
        SerialPort1.Write("i")
        Thread.Sleep(5)

        SerialPort1.RtsEnable = True
    End Sub

    Private Sub Cambiar_Label_Estado(ByVal frase As String)


    End Sub

    Private Sub Label7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lblHex.Click

    End Sub

    Private Sub portComboBox_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles portComboBox.SelectedIndexChanged

    End Sub

    Private Sub Label7_Click_1(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lblRTS.Click

    End Sub

    Private Sub Button4_Click_2(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim toggleRTS As Boolean
        toggleRTS = True

        If SerialPort1.RtsEnable Then
            SerialPort1.RtsEnable = False
            lblRTS.Text = "RTS = FALSE (TX ON)"
        Else
            SerialPort1.RtsEnable = True
            lblRTS.Text = "RTS = TRUE (RX ON)"
        End If

    End Sub

    Private Sub btnLedON_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReleA.Click
        Envio_Datos(&H74, &H48)
    End Sub

    Private Sub btnLedOFF_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReleB.Click
        Envio_Datos(&H74, &H49)
    End Sub

    Private Sub btnReleM_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReleM.Click
        Envio_Datos(&H74, &H4A)
    End Sub

    Private Sub btnReleN_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnReleN.Click
        Envio_Datos(&H74, &H4B)
    End Sub

    Private Sub btnRelesOFF_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnRelesOFF.Click
        Envio_Datos(&H74, &H4F)
    End Sub
End Class
