object Form1: TForm1
  Left = 195
  Top = 109
  Width = 817
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 56
    Top = 88
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 56
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label7: TLabel
    Left = 104
    Top = 88
    Width = 32
    Height = 13
    Caption = 'Label7'
  end
  object Label8: TLabel
    Left = 104
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Label8'
  end
  object Label9: TLabel
    Left = 240
    Top = 96
    Width = 32
    Height = 13
    Caption = 'Label9'
  end
  object Button1: TButton
    Left = 32
    Top = 24
    Width = 81
    Height = 25
    Caption = 'Nacti A'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 24
    Width = 89
    Height = 25
    Caption = 'Nacti B'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 216
    Top = 24
    Width = 81
    Height = 25
    Caption = 'Simuluj'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 32
    Top = 56
    Width = 81
    Height = 25
    Caption = 'false'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 120
    Top = 56
    Width = 89
    Height = 25
    Caption = 'true'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Memo1: TMemo
    Left = 208
    Top = 168
    Width = 185
    Height = 161
    BevelInner = bvNone
    BevelOuter = bvNone
    BiDiMode = bdRightToLeftNoAlign
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      'Domaci:')
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 5
  end
  object Memo2: TMemo
    Left = 416
    Top = 168
    Width = 185
    Height = 161
    BevelInner = bvNone
    BevelOuter = bvNone
    BiDiMode = bdRightToLeftNoAlign
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      'Hoste:')
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 6
  end
  object Memo3: TMemo
    Left = 8
    Top = 168
    Width = 185
    Height = 241
    BevelInner = bvNone
    BevelOuter = bvNone
    BiDiMode = bdRightToLeftNoAlign
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      'Domaci:')
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 7
  end
  object Memo4: TMemo
    Left = 616
    Top = 168
    Width = 185
    Height = 241
    BevelInner = bvNone
    BevelOuter = bvNone
    BiDiMode = bdRightToLeftNoAlign
    BorderStyle = bsNone
    Color = clBtnFace
    Lines.Strings = (
      'Hoste:')
    ParentBiDiMode = False
    ReadOnly = True
    TabOrder = 8
  end
  object GroupBox1: TGroupBox
    Left = 472
    Top = 80
    Width = 129
    Height = 57
    Caption = 'Golman x Hrac:'
    TabOrder = 9
    object Label15: TLabel
      Left = 83
      Top = 36
      Width = 38
      Height = 13
      Caption = 'Label15'
    end
    object Label14: TLabel
      Left = 83
      Top = 20
      Width = 38
      Height = 13
      Caption = 'Label14'
    end
    object Label13: TLabel
      Left = 11
      Top = 36
      Width = 38
      Height = 13
      Caption = 'Label13'
    end
    object Label12: TLabel
      Left = 11
      Top = 20
      Width = 38
      Height = 13
      Caption = 'Label12'
    end
  end
  object GroupBox2: TGroupBox
    Left = 352
    Top = 80
    Width = 97
    Height = 33
    BiDiMode = bdLeftToRight
    Caption = 'Strely:'
    ParentBiDiMode = False
    TabOrder = 10
    object Label10: TLabel
      Left = 11
      Top = 12
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Label11: TLabel
      Left = 80
      Top = 12
      Width = 6
      Height = 13
      Caption = '0'
    end
  end
  object GroupBox3: TGroupBox
    Left = 376
    Top = 40
    Width = 49
    Height = 33
    Caption = 'Minuty:'
    TabOrder = 11
    object Label6: TLabel
      Left = 24
      Top = 12
      Width = 6
      Height = 13
      Caption = '0'
    end
  end
  object GroupBox4: TGroupBox
    Left = 368
    Top = 120
    Width = 65
    Height = 33
    Caption = 'Skore:'
    TabOrder = 12
    object Label3: TLabel
      Left = 9
      Top = 12
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Label4: TLabel
      Left = 48
      Top = 12
      Width = 6
      Height = 13
      Caption = '0'
    end
    object Label5: TLabel
      Left = 32
      Top = 12
      Width = 3
      Height = 13
      Caption = ':'
    end
  end
  object Button6: TButton
    Left = 216
    Top = 56
    Width = 81
    Height = 25
    Caption = 'Navsteva'
    TabOrder = 13
    OnClick = Button6Click
  end
  object GroupBox5: TGroupBox
    Left = 472
    Top = 40
    Width = 65
    Height = 33
    Caption = 'Navsteva:'
    TabOrder = 14
    object Label16: TLabel
      Left = 8
      Top = 16
      Width = 6
      Height = 13
      Caption = '0'
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
  end
end
