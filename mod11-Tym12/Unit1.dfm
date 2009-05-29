object Form1: TForm1
  Left = 261
  Top = 122
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'Form1'
  ClientHeight = 625
  ClientWidth = 872
  Color = clMaroon
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 784
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Konec'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 784
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Dalsi'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 64
    Top = 40
    Width = 185
    Height = 521
    TabOrder = 2
  end
  object Button3: TButton
    Left = 784
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Predchozi'
    Enabled = False
    TabOrder = 3
    OnClick = Button3Click
  end
  object Memo2: TMemo
    Left = 256
    Top = 40
    Width = 57
    Height = 521
    TabOrder = 4
  end
  object Memo3: TMemo
    Left = 320
    Top = 40
    Width = 49
    Height = 521
    TabOrder = 5
  end
  object Memo4: TMemo
    Left = 376
    Top = 40
    Width = 49
    Height = 521
    TabOrder = 6
  end
end
