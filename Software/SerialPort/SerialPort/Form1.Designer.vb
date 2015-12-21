<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.btnAbrir = New System.Windows.Forms.Button()
        Me.btnCerrar = New System.Windows.Forms.Button()
        Me.btnEnviar = New System.Windows.Forms.Button()
        Me.portComboBox = New System.Windows.Forms.ComboBox()
        Me.baudComboBox = New System.Windows.Forms.ComboBox()
        Me.lblPuertos = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.textToSend = New System.Windows.Forms.RichTextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.lblEstado = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.receivedTextBox = New System.Windows.Forms.RichTextBox()
        Me.btnBorrar = New System.Windows.Forms.Button()
        Me.btnSchlumber = New System.Windows.Forms.Button()
        Me.btnWenner = New System.Windows.Forms.Button()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.btnClave = New System.Windows.Forms.Button()
        Me.rtbHex = New System.Windows.Forms.RichTextBox()
        Me.lblHex = New System.Windows.Forms.Label()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.lblRTS = New System.Windows.Forms.Label()
        Me.btnReleA = New System.Windows.Forms.Button()
        Me.btnReleB = New System.Windows.Forms.Button()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.btnReleN = New System.Windows.Forms.Button()
        Me.btnReleM = New System.Windows.Forms.Button()
        Me.btnRelesOFF = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btnAbrir
        '
        Me.btnAbrir.Location = New System.Drawing.Point(31, 12)
        Me.btnAbrir.Name = "btnAbrir"
        Me.btnAbrir.Size = New System.Drawing.Size(75, 23)
        Me.btnAbrir.TabIndex = 0
        Me.btnAbrir.Text = "Abrir"
        Me.btnAbrir.UseVisualStyleBackColor = True
        '
        'btnCerrar
        '
        Me.btnCerrar.Location = New System.Drawing.Point(122, 12)
        Me.btnCerrar.Name = "btnCerrar"
        Me.btnCerrar.Size = New System.Drawing.Size(75, 23)
        Me.btnCerrar.TabIndex = 1
        Me.btnCerrar.Text = "Cerrar"
        Me.btnCerrar.UseVisualStyleBackColor = True
        '
        'btnEnviar
        '
        Me.btnEnviar.Location = New System.Drawing.Point(31, 153)
        Me.btnEnviar.Name = "btnEnviar"
        Me.btnEnviar.Size = New System.Drawing.Size(75, 23)
        Me.btnEnviar.TabIndex = 2
        Me.btnEnviar.Text = "Enviar"
        Me.btnEnviar.UseVisualStyleBackColor = True
        '
        'portComboBox
        '
        Me.portComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.portComboBox.FormattingEnabled = True
        Me.portComboBox.Location = New System.Drawing.Point(31, 209)
        Me.portComboBox.Name = "portComboBox"
        Me.portComboBox.Size = New System.Drawing.Size(75, 21)
        Me.portComboBox.TabIndex = 4
        '
        'baudComboBox
        '
        Me.baudComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.baudComboBox.FormattingEnabled = True
        Me.baudComboBox.Items.AddRange(New Object() {"9600", "19200", "57600", "115200"})
        Me.baudComboBox.Location = New System.Drawing.Point(122, 209)
        Me.baudComboBox.Name = "baudComboBox"
        Me.baudComboBox.Size = New System.Drawing.Size(75, 21)
        Me.baudComboBox.TabIndex = 5
        '
        'lblPuertos
        '
        Me.lblPuertos.AutoSize = True
        Me.lblPuertos.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblPuertos.Location = New System.Drawing.Point(33, 190)
        Me.lblPuertos.Name = "lblPuertos"
        Me.lblPuertos.Size = New System.Drawing.Size(44, 13)
        Me.lblPuertos.TabIndex = 6
        Me.lblPuertos.Text = "Puerto"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(119, 190)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(67, 13)
        Me.Label1.TabIndex = 7
        Me.Label1.Text = "Baud Rate"
        '
        'SerialPort1
        '
        '
        'textToSend
        '
        Me.textToSend.Location = New System.Drawing.Point(31, 70)
        Me.textToSend.Name = "textToSend"
        Me.textToSend.Size = New System.Drawing.Size(165, 66)
        Me.textToSend.TabIndex = 3
        Me.textToSend.Text = ""
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(28, 252)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(49, 13)
        Me.Label4.TabIndex = 11
        Me.Label4.Text = "Recibido"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(228, 70)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 13
        Me.Button1.Text = "DSP"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Underline), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(228, 38)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(115, 13)
        Me.Label2.TabIndex = 14
        Me.Label2.Text = "Comunicación con:"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(309, 70)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(75, 23)
        Me.Button2.TabIndex = 15
        Me.Button2.Text = "Cliente 36"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(228, 99)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(75, 23)
        Me.Button3.TabIndex = 16
        Me.Button3.Text = "Cliente 44"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Underline), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(228, 153)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(59, 13)
        Me.Label3.TabIndex = 17
        Me.Label3.Text = "Métodos:"
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(309, 99)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(75, 23)
        Me.Button6.TabIndex = 20
        Me.Button6.Text = "Apagado"
        Me.Button6.UseVisualStyleBackColor = True
        '
        'lblEstado
        '
        Me.lblEstado.AutoSize = True
        Me.lblEstado.Location = New System.Drawing.Point(428, 355)
        Me.lblEstado.Name = "lblEstado"
        Me.lblEstado.Size = New System.Drawing.Size(75, 13)
        Me.lblEstado.TabIndex = 21
        Me.lblEstado.Text = "No conectado"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(379, 355)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(43, 13)
        Me.Label5.TabIndex = 22
        Me.Label5.Text = "Estado:"
        '
        'receivedTextBox
        '
        Me.receivedTextBox.Location = New System.Drawing.Point(31, 268)
        Me.receivedTextBox.Name = "receivedTextBox"
        Me.receivedTextBox.Size = New System.Drawing.Size(165, 67)
        Me.receivedTextBox.TabIndex = 23
        Me.receivedTextBox.Text = ""
        '
        'btnBorrar
        '
        Me.btnBorrar.Location = New System.Drawing.Point(31, 341)
        Me.btnBorrar.Name = "btnBorrar"
        Me.btnBorrar.Size = New System.Drawing.Size(75, 23)
        Me.btnBorrar.TabIndex = 24
        Me.btnBorrar.Text = "Borrar"
        Me.btnBorrar.UseVisualStyleBackColor = True
        '
        'btnSchlumber
        '
        Me.btnSchlumber.Location = New System.Drawing.Point(228, 180)
        Me.btnSchlumber.Name = "btnSchlumber"
        Me.btnSchlumber.Size = New System.Drawing.Size(137, 23)
        Me.btnSchlumber.TabIndex = 25
        Me.btnSchlumber.Text = "DSP-SLB"
        Me.btnSchlumber.UseVisualStyleBackColor = True
        '
        'btnWenner
        '
        Me.btnWenner.Location = New System.Drawing.Point(228, 210)
        Me.btnWenner.Name = "btnWenner"
        Me.btnWenner.Size = New System.Drawing.Size(137, 23)
        Me.btnWenner.TabIndex = 26
        Me.btnWenner.Text = "DSP-RELEs_OFF"
        Me.btnWenner.UseVisualStyleBackColor = True
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Underline), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.Location = New System.Drawing.Point(228, 252)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(42, 13)
        Me.Label6.TabIndex = 27
        Me.Label6.Text = "Inicio:"
        '
        'btnClave
        '
        Me.btnClave.Location = New System.Drawing.Point(231, 278)
        Me.btnClave.Name = "btnClave"
        Me.btnClave.Size = New System.Drawing.Size(75, 23)
        Me.btnClave.TabIndex = 28
        Me.btnClave.Text = "Clave Inicio"
        Me.btnClave.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        Me.btnClave.UseVisualStyleBackColor = True
        '
        'rtbHex
        '
        Me.rtbHex.Location = New System.Drawing.Point(333, 278)
        Me.rtbHex.Name = "rtbHex"
        Me.rtbHex.Size = New System.Drawing.Size(150, 67)
        Me.rtbHex.TabIndex = 29
        Me.rtbHex.Text = ""
        '
        'lblHex
        '
        Me.lblHex.AutoSize = True
        Me.lblHex.Location = New System.Drawing.Point(330, 252)
        Me.lblHex.Name = "lblHex"
        Me.lblHex.Size = New System.Drawing.Size(71, 13)
        Me.lblHex.TabIndex = 30
        Me.lblHex.Text = "Hex recibidos"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(408, 54)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(75, 23)
        Me.Button4.TabIndex = 31
        Me.Button4.Text = "ON/OFF"
        Me.Button4.UseVisualStyleBackColor = True
        '
        'lblRTS
        '
        Me.lblRTS.AutoSize = True
        Me.lblRTS.Location = New System.Drawing.Point(405, 38)
        Me.lblRTS.Name = "lblRTS"
        Me.lblRTS.Size = New System.Drawing.Size(29, 13)
        Me.lblRTS.TabIndex = 32
        Me.lblRTS.Text = "RTS"
        '
        'btnReleA
        '
        Me.btnReleA.Location = New System.Drawing.Point(451, 181)
        Me.btnReleA.Name = "btnReleA"
        Me.btnReleA.Size = New System.Drawing.Size(137, 23)
        Me.btnReleA.TabIndex = 33
        Me.btnReleA.Text = "RELE A"
        Me.btnReleA.UseVisualStyleBackColor = True
        '
        'btnReleB
        '
        Me.btnReleB.Location = New System.Drawing.Point(451, 210)
        Me.btnReleB.Name = "btnReleB"
        Me.btnReleB.Size = New System.Drawing.Size(137, 23)
        Me.btnReleB.TabIndex = 34
        Me.btnReleB.Text = "RELE B"
        Me.btnReleB.UseVisualStyleBackColor = True
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Underline), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.Location = New System.Drawing.Point(448, 158)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(43, 13)
        Me.Label7.TabIndex = 35
        Me.Label7.Text = "Relés:"
        '
        'btnReleN
        '
        Me.btnReleN.Location = New System.Drawing.Point(607, 210)
        Me.btnReleN.Name = "btnReleN"
        Me.btnReleN.Size = New System.Drawing.Size(137, 23)
        Me.btnReleN.TabIndex = 37
        Me.btnReleN.Text = "RELE N"
        Me.btnReleN.UseVisualStyleBackColor = True
        '
        'btnReleM
        '
        Me.btnReleM.Location = New System.Drawing.Point(607, 181)
        Me.btnReleM.Name = "btnReleM"
        Me.btnReleM.Size = New System.Drawing.Size(137, 23)
        Me.btnReleM.TabIndex = 36
        Me.btnReleM.Text = "RELE M"
        Me.btnReleM.UseVisualStyleBackColor = True
        '
        'btnRelesOFF
        '
        Me.btnRelesOFF.Location = New System.Drawing.Point(451, 242)
        Me.btnRelesOFF.Name = "btnRelesOFF"
        Me.btnRelesOFF.Size = New System.Drawing.Size(137, 23)
        Me.btnRelesOFF.TabIndex = 38
        Me.btnRelesOFF.Text = "RELE OFF"
        Me.btnRelesOFF.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(860, 563)
        Me.Controls.Add(Me.btnRelesOFF)
        Me.Controls.Add(Me.btnReleN)
        Me.Controls.Add(Me.btnReleM)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.btnReleB)
        Me.Controls.Add(Me.btnReleA)
        Me.Controls.Add(Me.lblRTS)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.lblHex)
        Me.Controls.Add(Me.rtbHex)
        Me.Controls.Add(Me.btnClave)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.btnWenner)
        Me.Controls.Add(Me.btnSchlumber)
        Me.Controls.Add(Me.btnBorrar)
        Me.Controls.Add(Me.receivedTextBox)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.lblEstado)
        Me.Controls.Add(Me.Button6)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.lblPuertos)
        Me.Controls.Add(Me.baudComboBox)
        Me.Controls.Add(Me.portComboBox)
        Me.Controls.Add(Me.textToSend)
        Me.Controls.Add(Me.btnEnviar)
        Me.Controls.Add(Me.btnCerrar)
        Me.Controls.Add(Me.btnAbrir)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnAbrir As System.Windows.Forms.Button
    Friend WithEvents btnCerrar As System.Windows.Forms.Button
    Friend WithEvents btnEnviar As System.Windows.Forms.Button
    Friend WithEvents portComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents baudComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents lblPuertos As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents SerialPort1 As System.IO.Ports.SerialPort
    Friend WithEvents textToSend As System.Windows.Forms.RichTextBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents lblEstado As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents receivedTextBox As System.Windows.Forms.RichTextBox
    Friend WithEvents btnBorrar As System.Windows.Forms.Button
    Friend WithEvents btnSchlumber As System.Windows.Forms.Button
    Friend WithEvents btnWenner As System.Windows.Forms.Button
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents btnClave As System.Windows.Forms.Button
    Friend WithEvents rtbHex As System.Windows.Forms.RichTextBox
    Friend WithEvents lblHex As System.Windows.Forms.Label
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents lblRTS As System.Windows.Forms.Label
    Friend WithEvents btnReleA As System.Windows.Forms.Button
    Friend WithEvents btnReleB As System.Windows.Forms.Button
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents btnReleN As System.Windows.Forms.Button
    Friend WithEvents btnReleM As System.Windows.Forms.Button
    Friend WithEvents btnRelesOFF As System.Windows.Forms.Button

End Class
