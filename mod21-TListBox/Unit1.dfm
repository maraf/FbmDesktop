object Form1: TForm1
  Left = 242
  Top = 14
  Width = 797
  Height = 714
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'Form1'
  Color = clGreen
  TransparentColorValue = clRed
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnMouseUp = FormMouseUp
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 448
    Width = 59
    Height = 13
    Caption = 'SELECTED:'
  end
  object Label5: TLabel
    Left = 176
    Top = 448
    Width = 3
    Height = 13
  end
  object GroupBox3: TGroupBox
    Left = 408
    Top = 472
    Width = 345
    Height = 169
    Caption = ' 2.lajna '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object Button11: TButton
      Left = 96
      Top = 48
      Width = 161
      Height = 25
      Caption = 'Centr'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnMouseUp = Button11MouseUp
    end
    object Button12: TButton
      Left = 8
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Leve kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnMouseUp = Button12MouseUp
    end
    object Button13: TButton
      Left = 184
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Prave kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnMouseUp = Button13MouseUp
    end
    object Button14: TButton
      Left = 8
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Levy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnMouseUp = Button14MouseUp
    end
    object Button15: TButton
      Left = 184
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Pravy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnMouseUp = Button15MouseUp
    end
    object ComboBox2: TComboBox
      Left = 96
      Top = 16
      Width = 161
      Height = 21
      AutoComplete = False
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 13
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = 'Hrajici lajna'
      Items.Strings = (
        'Hrajici lajna'
        'Jen nahradnici')
    end
  end
  object GroupBox2: TGroupBox
    Left = 440
    Top = 432
    Width = 345
    Height = 169
    Caption = ' 3.lajna '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Button6: TButton
      Left = 96
      Top = 48
      Width = 161
      Height = 25
      Caption = 'Centr'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnMouseUp = Button6MouseUp
    end
    object Button7: TButton
      Left = 8
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Leve kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnMouseUp = Button7MouseUp
    end
    object Button8: TButton
      Left = 184
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Prave kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnMouseUp = Button8MouseUp
    end
    object Button9: TButton
      Left = 8
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Levy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnMouseUp = Button9MouseUp
    end
    object Button10: TButton
      Left = 184
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Pravy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnMouseUp = Button10MouseUp
    end
    object ComboBox4: TComboBox
      Left = 96
      Top = 16
      Width = 161
      Height = 21
      AutoComplete = False
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 13
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = 'Hrajici lajna'
      Items.Strings = (
        'Hrajici lajna'
        'Jen nahradnici')
    end
  end
  object GroupBox4: TGroupBox
    Left = 464
    Top = 400
    Width = 345
    Height = 169
    Caption = ' 4.lajna '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object Button16: TButton
      Left = 96
      Top = 48
      Width = 161
      Height = 25
      Caption = 'Centr'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnMouseUp = Button16MouseUp
    end
    object Button17: TButton
      Left = 8
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Leve kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnMouseUp = Button17MouseUp
    end
    object Button18: TButton
      Left = 184
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Prave kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnMouseUp = Button18MouseUp
    end
    object Button19: TButton
      Left = 8
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Levy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnMouseUp = Button19MouseUp
    end
    object Button20: TButton
      Left = 184
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Pravy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnMouseUp = Button20MouseUp
    end
    object ComboBox3: TComboBox
      Left = 96
      Top = 16
      Width = 161
      Height = 21
      AutoComplete = False
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 13
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = 'Hrajici lajna'
      Items.Strings = (
        'Hrajici lajna'
        'Jen nahradnici')
    end
  end
  object Button21: TButton
    Left = 448
    Top = 40
    Width = 75
    Height = 25
    Caption = '1. lajna'
    TabOrder = 5
    OnClick = Button21Click
  end
  object Button22: TButton
    Left = 528
    Top = 40
    Width = 75
    Height = 25
    Caption = '2. lajna'
    TabOrder = 6
    OnClick = Button22Click
  end
  object Button23: TButton
    Left = 608
    Top = 40
    Width = 75
    Height = 25
    Caption = '3. lajna'
    TabOrder = 7
    OnClick = Button23Click
  end
  object Button24: TButton
    Left = 688
    Top = 40
    Width = 75
    Height = 25
    Caption = '4. lajna'
    TabOrder = 8
    OnClick = Button24Click
  end
  object GroupBox1: TGroupBox
    Left = 432
    Top = 72
    Width = 345
    Height = 169
    Caption = ' 1.lajna '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Button5: TButton
      Left = 96
      Top = 48
      Width = 161
      Height = 25
      Caption = 'Centr'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button5Click
      OnMouseUp = Button5MouseUp
    end
    object Button4: TButton
      Left = 8
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Leve kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnMouseUp = Button4MouseUp
    end
    object Button3: TButton
      Left = 184
      Top = 88
      Width = 153
      Height = 25
      Caption = 'Prave kridlo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnMouseUp = Button3MouseUp
    end
    object Button1: TButton
      Left = 8
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Levy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnMouseUp = Button1MouseUp
    end
    object Button2: TButton
      Left = 184
      Top = 128
      Width = 153
      Height = 25
      Caption = 'Pravy obrance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnMouseUp = Button2MouseUp
    end
    object ComboBox1: TComboBox
      Left = 96
      Top = 16
      Width = 161
      Height = 21
      AutoComplete = False
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 13
      ItemIndex = 0
      ParentFont = False
      TabOrder = 5
      Text = 'Hrajici lajna'
      Items.Strings = (
        'Hrajici lajna'
        'Jen nahradnici')
    end
  end
  object GroupBox5: TGroupBox
    Left = 432
    Top = 256
    Width = 345
    Height = 97
    Caption = ' Golman a nahradni golman: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    object Button25: TButton
      Left = 88
      Top = 24
      Width = 161
      Height = 25
      Caption = 'Golman'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnMouseUp = Button25MouseUp
    end
    object Button26: TButton
      Left = 88
      Top = 56
      Width = 161
      Height = 25
      Caption = 'Nahradni golman'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnMouseUp = Button26MouseUp
    end
  end
  object GroupBox6: TGroupBox
    Left = 8
    Top = 16
    Width = 409
    Height = 433
    Caption = ' Sestava: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    object ListBox1: TListBox
      Left = 8
      Top = 24
      Width = 393
      Height = 401
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clGreen
      DragCursor = crHelp
      Font.Charset = DEFAULT_CHARSET
      Font.Color = cl3DLight
      Font.Height = 18
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 16
      ParentFont = False
      TabOrder = 0
      OnDblClick = ListBox1DblClick
      OnKeyPress = ListBox1KeyPress
      OnMouseDown = ListBox1MouseDown
      OnMouseUp = ListBox1MouseUp
    end
  end
  object Button27: TButton
    Left = 616
    Top = 368
    Width = 123
    Height = 25
    Caption = 'Vymaz vse'
    TabOrder = 11
    OnClick = Button27Click
  end
  object Button28: TButton
    Left = 472
    Top = 368
    Width = 123
    Height = 25
    Caption = 'Uloz sestavu'
    Enabled = False
    TabOrder = 12
  end
  object Panel1: TPanel
    Left = 264
    Top = 448
    Width = 129
    Height = 55
    TabOrder = 0
    Visible = False
    object Label2: TLabel
      Left = 8
      Top = 1
      Width = 40
      Height = 49
      Caption = '20'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -40
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 56
      Top = 28
      Width = 32
      Height = 13
      Caption = 'Label4'
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label3: TLabel
      Left = 56
      Top = 12
      Width = 32
      Height = 13
      Caption = 'Label3'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 16
    Top = 472
  end
end