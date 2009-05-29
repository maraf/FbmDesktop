object Form1: TForm1
  Left = 192
  Top = 114
  Width = 577
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 264
    Top = 48
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 264
    Top = 64
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label10: TLabel
    Left = 184
    Top = 176
    Width = 38
    Height = 13
    Caption = 'Label10'
  end
  object Label11: TLabel
    Left = 336
    Top = 176
    Width = 38
    Height = 13
    Caption = 'Label11'
  end
  object Label12: TLabel
    Left = 136
    Top = 112
    Width = 38
    Height = 13
    Caption = 'Label12'
  end
  object Label13: TLabel
    Left = 384
    Top = 112
    Width = 38
    Height = 13
    Caption = 'Label13'
  end
  object Label14: TLabel
    Left = 184
    Top = 232
    Width = 59
    Height = 20
    Caption = 'Label14'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label15: TLabel
    Left = 336
    Top = 232
    Width = 59
    Height = 20
    Caption = 'Label15'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label18: TLabel
    Left = 72
    Top = 80
    Width = 38
    Height = 13
    Caption = 'Label18'
  end
  object Button1: TButton
    Left = 248
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Konec'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 256
    Width = 185
    Height = 185
    TabOrder = 1
  end
  object Memo2: TMemo
    Left = 376
    Top = 256
    Width = 185
    Height = 185
    TabOrder = 2
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
end
