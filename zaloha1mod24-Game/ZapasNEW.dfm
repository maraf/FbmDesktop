object Form1: TForm1
  Left = 245
  Top = 133
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'Form1'
  ClientHeight = 627
  ClientWidth = 872
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object SF: TPanel
    Left = 16
    Top = 16
    Width = 800
    Height = 600
    TabOrder = 4
    object SF_B1: TShape
      Left = 8
      Top = 8
      Width = 785
      Height = 585
      Brush.Color = 2169560
      Pen.Color = clWhite
      Pen.Width = 5
      OnMouseUp = SF_B1MouseUp
    end
    object Shape1: TShape
      Left = 24
      Top = 26
      Width = 433
      Height = 25
      Brush.Color = 35840
      Pen.Style = psClear
      Pen.Width = 0
    end
    object SF_L_Number: TLabel
      Left = 46
      Top = 26
      Width = 13
      Height = 20
      Cursor = crHandPoint
      Caption = 'C:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_NumberClick
      OnDblClick = SF_L_NumberDblClick
    end
    object SF_L_Name: TLabel
      Left = 124
      Top = 26
      Width = 106
      Height = 20
      Cursor = crHandPoint
      Caption = 'Jmeno, Prijmeni:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_NameClick
      OnDblClick = SF_L_NameDblClick
    end
    object SF_L_Age: TLabel
      Left = 300
      Top = 26
      Width = 28
      Height = 20
      Cursor = crHandPoint
      Caption = 'Vek:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_AgeClick
      OnDblClick = SF_L_AgeDblClick
    end
    object SF_L_FS: TLabel
      Left = 344
      Top = 26
      Width = 18
      Height = 20
      Cursor = crHandPoint
      Caption = 'FS:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_FSClick
      OnDblClick = SF_L_FSDblClick
    end
    object SF_L_TS: TLabel
      Left = 366
      Top = 26
      Width = 19
      Height = 20
      Cursor = crHandPoint
      Caption = 'TS:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_TSClick
      OnDblClick = SF_L_TSDblClick
    end
    object SF_L_ZS: TLabel
      Left = 400
      Top = 26
      Width = 19
      Height = 20
      Cursor = crHandPoint
      Caption = 'ZS:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_ZSClick
      OnDblClick = SF_L_ZSDblClick
    end
    object SF_L_En: TLabel
      Left = 426
      Top = 26
      Width = 20
      Height = 20
      Cursor = crHandPoint
      Caption = 'En:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_EnClick
      OnDblClick = SF_L_EnDblClick
    end
    object SF_L_Post: TLabel
      Left = 24
      Top = 26
      Width = 12
      Height = 20
      Cursor = crHandPoint
      Caption = 'P:'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = SF_L_PostClick
      OnDblClick = SF_L_PostDblClick
    end
    object SF_B_Back: TButton
      Left = 504
      Top = 552
      Width = 121
      Height = 25
      Caption = 'Zpet domu'
      TabOrder = 0
      OnClick = SF_B_BackClick
      OnMouseUp = SF_B_BackMouseUp
    end
    object SF_GB_Goalkeeper: TGroupBox
      Left = 464
      Top = 264
      Width = 313
      Height = 73
      Caption = ' Golman a nahradni golman: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      OnMouseUp = SF_GB_GoalkeeperMouseUp
      object SF_B_Golman: TButton
        Left = 14
        Top = 32
        Width = 131
        Height = 25
        Caption = 'Golman'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SF_B_GolmanClick
        OnMouseUp = SF_B_GolmanMouseUp
      end
      object SF_B_ReserveGolman: TButton
        Left = 166
        Top = 32
        Width = 131
        Height = 25
        Caption = 'Nahradni golman'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SF_B_ReserveGolmanClick
        OnMouseUp = SF_B_ReserveGolmanMouseUp
      end
    end
    object SF_B_Save: TButton
      Left = 648
      Top = 552
      Width = 123
      Height = 25
      Caption = 'Uloz'
      TabOrder = 2
      OnClick = SF_B_SaveClick
      OnMouseUp = SF_B_SaveMouseUp
    end
    object SF_LB_Players: TListBox
      Left = 24
      Top = 48
      Width = 428
      Height = 529
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 16
      Font.Name = 'Courier'
      Font.Style = []
      ItemHeight = 16
      ParentFont = False
      TabOrder = 3
      OnMouseDown = SF_LB_PlayersMouseDown
      OnMouseUp = SF_LB_PlayersMouseUp
    end
    object SF_B_1stL: TButton
      Left = 464
      Top = 40
      Width = 75
      Height = 25
      Caption = '1. lajna'
      TabOrder = 9
      OnClick = SF_B_1stLClick
      OnMouseUp = SF_B_1stLMouseUp
    end
    object SF_B_2ndL: TButton
      Left = 544
      Top = 40
      Width = 75
      Height = 25
      Caption = '2. lajna'
      TabOrder = 10
      OnClick = SF_B_2ndLClick
      OnMouseUp = SF_B_2ndLMouseUp
    end
    object SF_B_3rdL: TButton
      Left = 624
      Top = 40
      Width = 75
      Height = 25
      Caption = '3. lajna'
      TabOrder = 11
      OnClick = SF_B_3rdLClick
      OnMouseUp = SF_B_3rdLMouseUp
    end
    object SF_B_4thL: TButton
      Left = 704
      Top = 40
      Width = 75
      Height = 25
      Caption = '4. lajna'
      TabOrder = 12
      OnClick = SF_B_4thLClick
      OnMouseUp = SF_B_4thLMouseUp
    end
    object SF_GB_4thLine: TGroupBox
      Left = 464
      Top = 80
      Width = 313
      Height = 177
      Caption = ' 4. lajna: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 8
      OnMouseUp = SF_GB_4thLineMouseUp
      object SF_B_4th_Center: TButton
        Left = 86
        Top = 56
        Width = 131
        Height = 25
        Caption = 'Center'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SF_B_4th_CenterClick
        OnMouseUp = SF_B_4th_CenterMouseUp
      end
      object SF_B_4th_LeftWing: TButton
        Left = 14
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Leve kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SF_B_4th_LeftWingClick
        OnMouseUp = SF_B_4th_LeftWingMouseUp
      end
      object SF_B_4th_RightWing: TButton
        Left = 166
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Prave kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = SF_B_4th_RightWingClick
        OnMouseUp = SF_B_4th_RightWingMouseUp
      end
      object SF_B_4th_RightBack: TButton
        Left = 166
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Pravy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = SF_B_4th_RightBackClick
        OnMouseUp = SF_B_4th_RightBackMouseUp
      end
      object SF_B_4th_LeftBack: TButton
        Left = 14
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Levy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = SF_B_4th_LeftBackClick
        OnMouseUp = SF_B_4th_LeftBackMouseUp
      end
      object SF_CB_4th_Type: TComboBox
        Left = 88
        Top = 24
        Width = 129
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 8
        Font.Name = 'MS Sans Serif'
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
    object SF_GB_3rdLine: TGroupBox
      Left = 464
      Top = 80
      Width = 313
      Height = 177
      Caption = ' 3. lajna: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 7
      OnMouseUp = SF_GB_3rdLineMouseUp
      object SF_B_3rd_Center: TButton
        Left = 86
        Top = 56
        Width = 131
        Height = 25
        Caption = 'Center'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SF_B_3rd_CenterClick
        OnMouseUp = SF_B_3rd_CenterMouseUp
      end
      object SF_B_3rd_LeftWing: TButton
        Left = 14
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Leve kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SF_B_3rd_LeftWingClick
        OnMouseUp = SF_B_3rd_LeftWingMouseUp
      end
      object SF_B_3rd_RightWing: TButton
        Left = 166
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Prave kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = SF_B_3rd_RightWingClick
        OnMouseUp = SF_B_3rd_RightWingMouseUp
      end
      object SF_B_3rd_RightBack: TButton
        Left = 166
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Pravy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = SF_B_3rd_RightBackClick
        OnMouseUp = SF_B_3rd_RightBackMouseUp
      end
      object SF_B_3rd_LeftBack: TButton
        Left = 14
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Levy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = SF_B_3rd_LeftBackClick
        OnMouseUp = SF_B_3rd_LeftBackMouseUp
      end
      object SF_CB_3rd_Type: TComboBox
        Left = 88
        Top = 24
        Width = 129
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 8
        Font.Name = 'MS Sans Serif'
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
    object SF_GB_2ndLine: TGroupBox
      Left = 464
      Top = 80
      Width = 313
      Height = 177
      Caption = ' 2. lajna: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 6
      OnMouseUp = SF_GB_2ndLineMouseUp
      object SF_B_2nd_Center: TButton
        Left = 86
        Top = 56
        Width = 131
        Height = 25
        Caption = 'Center'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SF_B_2nd_CenterClick
        OnMouseUp = SF_B_2nd_CenterMouseUp
      end
      object SF_B_2nd_LeftWing: TButton
        Left = 14
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Leve kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SF_B_2nd_LeftWingClick
        OnMouseUp = SF_B_2nd_LeftWingMouseUp
      end
      object SF_B_2nd_RightWing: TButton
        Left = 166
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Prave kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = SF_B_2nd_RightWingClick
        OnMouseUp = SF_B_2nd_RightWingMouseUp
      end
      object SF_B_2nd_RightBack: TButton
        Left = 166
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Pravy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = SF_B_2nd_RightBackClick
        OnMouseUp = SF_B_2nd_RightBackMouseUp
      end
      object SF_B_2nd_LeftBack: TButton
        Left = 14
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Levy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = SF_B_2nd_LeftBackClick
        OnMouseUp = SF_B_2nd_LeftBackMouseUp
      end
      object SF_CB_2nd_Type: TComboBox
        Left = 88
        Top = 24
        Width = 129
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 8
        Font.Name = 'MS Sans Serif'
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
    object SF_GB_1stLine: TGroupBox
      Left = 464
      Top = 80
      Width = 313
      Height = 177
      Caption = ' 1. lajna: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 4
      OnMouseUp = SF_GB_1stLineMouseUp
      object SF_B_1st_Center: TButton
        Left = 86
        Top = 56
        Width = 131
        Height = 25
        Caption = 'Center'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = SF_B_1st_CenterClick
        OnMouseUp = SF_B_1st_CenterMouseUp
      end
      object SF_B_1st_LeftWing: TButton
        Left = 14
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Leve kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SF_B_1st_LeftWingClick
        OnMouseUp = SF_B_1st_LeftWingMouseUp
      end
      object SF_B_1st_RightWing: TButton
        Left = 166
        Top = 96
        Width = 131
        Height = 25
        Caption = 'Prave kridlo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnClick = SF_B_1st_RightWingClick
        OnMouseUp = SF_B_1st_RightWingMouseUp
      end
      object SF_B_1st_RightBack: TButton
        Left = 166
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Pravy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        OnClick = SF_B_1st_RightBackClick
        OnMouseUp = SF_B_1st_RightBackMouseUp
      end
      object SF_B_1st_LeftBack: TButton
        Left = 14
        Top = 136
        Width = 131
        Height = 25
        Caption = 'Levy obrance'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = 11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnClick = SF_B_1st_LeftBackClick
        OnMouseUp = SF_B_1st_LeftBackMouseUp
      end
      object SF_CB_1st_Type: TComboBox
        Left = 88
        Top = 24
        Width = 129
        Height = 21
        Style = csDropDownList
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = 8
        Font.Name = 'MS Sans Serif'
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
    object SF_P_FlowPanel: TPanel
      Left = 464
      Top = 352
      Width = 129
      Height = 55
      TabOrder = 5
      Visible = False
      object SF_L_FP_Number: TLabel
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
      object SF_L_FP_LastName: TLabel
        Left = 56
        Top = 28
        Width = 48
        Height = 13
        Caption = 'LastName'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object SF_L_FP_Name: TLabel
        Left = 56
        Top = 12
        Width = 28
        Height = 13
        Caption = 'Name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object MA: TPanel
    Left = 8
    Top = 68
    Width = 800
    Height = 600
    Color = 2169560
    Locked = True
    TabOrder = 0
    object MA_B1: TShape
      Left = 8
      Top = 8
      Width = 785
      Height = 585
      Brush.Color = 2169560
      Pen.Color = clWhite
      Pen.Width = 5
    end
    object MA_B2D: TShape
      Left = 24
      Top = 24
      Width = 217
      Height = 513
    end
    object MA_LogoD: TImage
      Left = 48
      Top = 88
      Width = 170
      Height = 170
    end
    object MA_B2H: TShape
      Left = 560
      Top = 24
      Width = 217
      Height = 513
    end
    object MA_LogoH: TImage
      Left = 576
      Top = 88
      Width = 170
      Height = 170
    end
    object MA_B2S: TShape
      Left = 256
      Top = 80
      Width = 289
      Height = 185
    end
    object MA_B2D2: TShape
      Left = 240
      Top = 24
      Width = 145
      Height = 46
    end
    object MA_B2H2: TShape
      Left = 416
      Top = 24
      Width = 145
      Height = 46
    end
    object MA_B2H3: TShape
      Left = 554
      Top = 25
      Width = 9
      Height = 45
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_TH_L: TLabel
      Left = 640
      Top = 32
      Width = 130
      Height = 30
      Alignment = taRightJustify
      Caption = 'MA_TH_L'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Bolt Bd BT'
      Font.Style = []
      ParentFont = False
    end
    object MA_SkoreD: TLabel
      Left = 319
      Top = 96
      Width = 62
      Height = 150
      Alignment = taRightJustify
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 150
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object MA_B2S2: TShape
      Left = 288
      Top = 264
      Width = 225
      Height = 225
    end
    object MA_iHall: TImage
      Left = 315
      Top = 288
      Width = 170
      Height = 170
    end
    object MA_Hall: TLabel
      Left = 312
      Top = 272
      Width = 36
      Height = 20
      Alignment = taCenter
      Caption = 'Hall'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Bolt Bd BT'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object MA_B2D4: TShape
      Left = 240
      Top = 280
      Width = 33
      Height = 257
    end
    object MA_B2H4: TShape
      Left = 528
      Top = 280
      Width = 33
      Height = 257
    end
    object MA_B2D5: TShape
      Left = 234
      Top = 281
      Width = 9
      Height = 256
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_B2H5: TShape
      Left = 554
      Top = 281
      Width = 9
      Height = 256
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_SkoreH: TLabel
      Left = 412
      Top = 96
      Width = 62
      Height = 150
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 150
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object MA_Skore: TLabel
      Left = 380
      Top = 96
      Width = 33
      Height = 150
      Alignment = taRightJustify
      Caption = ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 150
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object MA_B2S3: TShape
      Left = 312
      Top = 80
      Width = 169
      Height = 41
    end
    object MA_B2S4: TShape
      Left = 256
      Top = 224
      Width = 289
      Height = 41
    end
    object MA_B2S5: TShape
      Left = 336
      Top = 224
      Width = 121
      Height = 41
    end
    object MA_Strely: TLabel
      Left = 366
      Top = 229
      Width = 61
      Height = 30
      Alignment = taCenter
      Caption = 'St'#345'ely'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object MA_StrelyD: TLabel
      Left = 289
      Top = 229
      Width = 13
      Height = 30
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object MA_StrelyH: TLabel
      Left = 491
      Top = 229
      Width = 13
      Height = 30
      Alignment = taRightJustify
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object MA_Cas: TLabel
      Left = 353
      Top = 85
      Width = 99
      Height = 30
      Alignment = taRightJustify
      Caption = '0. minuta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
    end
    object MA_Navsteva: TLabel
      Left = 312
      Top = 448
      Width = 99
      Height = 30
      Caption = 'N'#225'v'#353'teva:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object MA_iNavsteva: TLabel
      Left = 472
      Top = 448
      Width = 13
      Height = 30
      Alignment = taRightJustify
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object MA_B2S6: TShape
      Left = 24
      Top = 544
      Width = 753
      Height = 33
    end
    object MA_B2D6: TShape
      Left = 272
      Top = 499
      Width = 65
      Height = 38
    end
    object MA_B2H6: TShape
      Left = 464
      Top = 499
      Width = 65
      Height = 38
    end
    object MA_B2D3: TShape
      Left = 234
      Top = 25
      Width = 9
      Height = 45
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_B2D7: TShape
      Left = 266
      Top = 500
      Width = 9
      Height = 37
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_B2H7: TShape
      Left = 522
      Top = 500
      Width = 9
      Height = 37
      Pen.Style = psClear
      Pen.Width = 0
    end
    object MA_TD_L: TLabel
      Left = 32
      Top = 32
      Width = 130
      Height = 30
      Caption = 'MA_TD_L'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 30
      Font.Name = 'Bolt Bd BT'
      Font.Style = []
      ParentFont = False
    end
    object MA_SD_L: TLabel
      Left = 288
      Top = 500
      Width = 25
      Height = 36
      Alignment = taCenter
      Caption = 'S'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWhite
      Font.Height = -31
      Font.Name = 'Bolt Bd BT'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
      OnClick = MA_SD_LClick
    end
    object MA_SH_L: TLabel
      Left = 488
      Top = 500
      Width = 25
      Height = 36
      Alignment = taCenter
      Caption = 'S'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWhite
      Font.Height = -31
      Font.Name = 'Bolt Bd BT'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlCenter
      OnClick = MA_SH_LClick
    end
    object MA_O1: TLabel
      Left = 168
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_O2: TLabel
      Left = 268
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_O3: TLabel
      Left = 368
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_O4: TLabel
      Left = 468
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_O5: TLabel
      Left = 568
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_O0: TLabel
      Left = 32
      Top = 552
      Width = 81
      Height = 16
      Caption = 'Dal'#353#237' z'#225'pasy:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_Button1: TShape
      Left = 344
      Top = 504
      Width = 113
      Height = 25
    end
    object MA_LButton1: TLabel
      Left = 380
      Top = 510
      Width = 45
      Height = 16
      Cursor = crHandPoint
      Caption = 'PAUZA'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = MA_LButton1Click
    end
    object MA_O6: TLabel
      Left = 672
      Top = 552
      Width = 9
      Height = 16
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object MA_SkoreListD: TMemo
      Left = 40
      Top = 296
      Width = 217
      Height = 233
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object MA_SkoreListH: TMemo
      Left = 544
      Top = 296
      Width = 209
      Height = 233
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object MA_LP_D: TPanel
      Left = 25
      Top = 281
      Width = 247
      Height = 255
      BevelOuter = bvNone
      BiDiMode = bdLeftToRight
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentBiDiMode = False
      ParentFont = False
      TabOrder = 2
      Visible = False
      object MA_LP_DL1: TLabel
        Left = 16
        Top = 16
        Width = 9
        Height = 13
        Caption = 'C:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL2: TLabel
        Left = 40
        Top = 16
        Width = 34
        Height = 13
        Caption = 'Jmeno:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL3: TLabel
        Left = 96
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL4: TLabel
        Left = 120
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL5: TLabel
        Left = 144
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL6: TLabel
        Left = 168
        Top = 16
        Width = 8
        Height = 13
        Caption = 'E:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_DL7: TLabel
        Left = 192
        Top = 16
        Width = 8
        Height = 13
        Caption = 'E:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
    end
    object MA_LP_H: TPanel
      Left = 529
      Top = 281
      Width = 247
      Height = 255
      BevelOuter = bvNone
      TabOrder = 3
      Visible = False
      object MA_LP_HL1: TLabel
        Left = 48
        Top = 16
        Width = 9
        Height = 13
        Caption = 'C:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL2: TLabel
        Left = 72
        Top = 16
        Width = 34
        Height = 13
        Caption = 'Jmeno:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL3: TLabel
        Left = 128
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL4: TLabel
        Left = 152
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL5: TLabel
        Left = 176
        Top = 16
        Width = 10
        Height = 13
        Caption = 'FS'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL6: TLabel
        Left = 200
        Top = 16
        Width = 8
        Height = 13
        Caption = 'E:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
      object MA_LP_HL7: TLabel
        Left = 224
        Top = 16
        Width = 8
        Height = 13
        Caption = 'E:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Calibri'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object LP: TPanel
    Left = 72
    Top = 4
    Width = 800
    Height = 600
    Color = 2169560
    TabOrder = 1
    object LP_B2: TShape
      Left = 8
      Top = 8
      Width = 785
      Height = 585
      Brush.Color = 2169560
      Pen.Color = clWhite
      Pen.Width = 5
    end
    object LP_B1: TShape
      Left = 560
      Top = 20
      Width = 220
      Height = 429
    end
    object LP_Name: TLabel
      Left = 584
      Top = 28
      Width = 69
      Height = 20
      Cursor = crHandPoint
      Caption = 'LP_Name'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 2169560
      Font.Height = 20
      Font.Name = 'Bauhaus 93'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Logo: TImage
      Left = 585
      Top = 48
      Width = 170
      Height = 170
      Transparent = True
    end
    object LP_Hall: TLabel
      Left = 596
      Top = 218
      Width = 56
      Height = 20
      Cursor = crHandPoint
      Caption = 'LP_Hall'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 2169560
      Font.Height = 20
      Font.Name = 'Bauhaus 93'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_iHall: TImage
      Left = 585
      Top = 240
      Width = 170
      Height = 170
    end
    object LP_lCapacity: TLabel
      Left = 593
      Top = 420
      Width = 126
      Height = 15
      Cursor = crHandPoint
      Caption = 'Kapacita . . . . . .'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 2169560
      Font.Height = 15
      Font.Name = 'Bolt Bd BT'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Capacity: TLabel
      Left = 728
      Top = 420
      Width = 33
      Height = 15
      Cursor = crHandPoint
      Caption = 'Cap.'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 2169560
      Font.Height = 15
      Font.Name = 'Bolt Bd BT'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_B3: TShape
      Left = 24
      Top = 20
      Width = 528
      Height = 560
    end
    object LP_B4: TShape
      Left = 30
      Top = 26
      Width = 515
      Height = 25
      Brush.Color = 2169560
      Pen.Style = psClear
      Pen.Width = 0
    end
    object LP_P_L: TLabel
      Left = 40
      Top = 26
      Width = 12
      Height = 20
      Cursor = crHandPoint
      Caption = 'P:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_P_LClick
      OnDblClick = LP_P_LDblClick
    end
    object LP_C_L: TLabel
      Left = 62
      Top = 26
      Width = 13
      Height = 20
      Cursor = crHandPoint
      Caption = 'C:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_C_LClick
      OnDblClick = LP_C_LDblClick
    end
    object LP_J_L: TLabel
      Left = 84
      Top = 26
      Width = 106
      Height = 20
      Cursor = crHandPoint
      Caption = 'Jmeno, Prijmeni:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_J_LClick
      OnDblClick = LP_J_LDblClick
    end
    object LP_V_L: TLabel
      Left = 260
      Top = 26
      Width = 28
      Height = 20
      Cursor = crHandPoint
      Caption = 'Vek:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_V_LClick
      OnDblClick = LP_V_LDblClick
    end
    object LP_F_L: TLabel
      Left = 296
      Top = 26
      Width = 18
      Height = 20
      Cursor = crHandPoint
      Caption = 'FS:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_F_LClick
    end
    object LP_T_L: TLabel
      Left = 326
      Top = 26
      Width = 19
      Height = 20
      Cursor = crHandPoint
      Caption = 'TS:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_T_LClick
      OnDblClick = LP_T_LDblClick
    end
    object LP_Z_L: TLabel
      Left = 356
      Top = 26
      Width = 19
      Height = 20
      Cursor = crHandPoint
      Caption = 'ZS:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_Z_LClick
      OnDblClick = LP_Z_LDblClick
    end
    object LP_L_L: TLabel
      Left = 386
      Top = 26
      Width = 11
      Height = 20
      Cursor = crHandPoint
      Caption = 'L:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_L_LClick
      OnDblClick = LP_L_LDblClick
    end
    object LP_Al_L: TLabel
      Left = 466
      Top = 26
      Width = 17
      Height = 20
      Cursor = crHandPoint
      Caption = 'Al:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_Al_LClick
      OnDblClick = LP_Al_LDblClick
    end
    object LP_En_L: TLabel
      Left = 490
      Top = 26
      Width = 53
      Height = 20
      Cursor = crHandPoint
      Caption = 'Energie:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_En_LClick
      OnDblClick = LP_En_LDblClick
    end
    object LP_Zl_L: TLabel
      Left = 419
      Top = 26
      Width = 16
      Height = 20
      Cursor = crHandPoint
      Caption = 'Zl:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Gl_L: TLabel
      Left = 441
      Top = 26
      Width = 18
      Height = 20
      Cursor = crHandPoint
      Caption = 'Gl:'
      Color = 2169560
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_Gl_LClick
      OnDblClick = LP_Gl_LDblClick
    end
    object LP_P_M: TLabel
      Left = 36
      Top = 50
      Width = 8
      Height = 18
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_C_M: TLabel
      Left = 65
      Top = 50
      Width = 8
      Height = 18
      Alignment = taRightJustify
      Caption = 'C'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_J_M: TLabel
      Left = 84
      Top = 50
      Width = 5
      Height = 18
      Caption = 'J'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_V_M: TLabel
      Left = 266
      Top = 50
      Width = 9
      Height = 18
      Caption = 'V'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_F_M: TLabel
      Left = 296
      Top = 50
      Width = 7
      Height = 18
      Caption = 'F'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_T_M: TLabel
      Left = 326
      Top = 50
      Width = 7
      Height = 18
      Caption = 'T'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Z_M: TLabel
      Left = 356
      Top = 50
      Width = 7
      Height = 18
      Caption = 'Z'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_L_M: TLabel
      Left = 386
      Top = 50
      Width = 6
      Height = 18
      Caption = 'L'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Zl_M: TLabel
      Left = 423
      Top = 50
      Width = 11
      Height = 18
      Alignment = taRightJustify
      Caption = 'Zl'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Gl_M: TLabel
      Left = 445
      Top = 50
      Width = 13
      Height = 18
      Alignment = taRightJustify
      Caption = 'Gl'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_Al_M: TLabel
      Left = 469
      Top = 50
      Width = 13
      Height = 18
      Alignment = taRightJustify
      Caption = 'Al'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_En_M: TLabel
      Left = 522
      Top = 50
      Width = 8
      Height = 18
      Alignment = taRightJustify
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LP_B5: TShape
      Left = 560
      Top = 460
      Width = 220
      Height = 85
    end
    object LP_Buy: TComboBox
      Left = 584
      Top = 472
      Width = 169
      Height = 21
      BevelInner = bvNone
      BevelOuter = bvNone
      Style = csDropDownList
      Ctl3D = True
      DropDownCount = 7
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 13
      ParentCtl3D = False
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      TabStop = False
    end
    object Zpet: TButton
      Left = 704
      Top = 552
      Width = 75
      Height = 25
      Caption = 'Zpet'
      TabOrder = 0
      OnClick = ZpetClick
    end
    object LP_B_Buy: TButton
      Left = 584
      Top = 504
      Width = 73
      Height = 25
      Caption = 'Koupit'
      TabOrder = 2
      OnClick = LP_B_BuyClick
    end
    object LP_B_Loan: TButton
      Left = 680
      Top = 504
      Width = 73
      Height = 25
      Caption = 'Hostovat'
      TabOrder = 3
    end
    object LP_B6: TPanel
      Left = 560
      Top = 232
      Width = 220
      Height = 313
      BevelOuter = bvNone
      BiDiMode = bdLeftToRight
      BorderWidth = 1
      Color = clWhite
      ParentBiDiMode = False
      TabOrder = 4
      object LP_B7: TShape
        Left = 0
        Top = 0
        Width = 220
        Height = 313
      end
      object LP_GB_Training: TGroupBox
        Left = 16
        Top = 8
        Width = 185
        Height = 97
        Caption = 'Trenink: '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object LP_CB_Training: TComboBox
          Left = 8
          Top = 28
          Width = 89
          Height = 21
          BevelInner = bvNone
          BevelOuter = bvNone
          Style = csDropDownList
          Ctl3D = True
          DropDownCount = 7
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ItemIndex = 0
          ParentCtl3D = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          TabStop = False
          Text = 'Trenovat FS'
          Items.Strings = (
            'Trenovat FS'
            'Trenovat TS')
        end
        object LP_CB_TrainingIntensity: TComboBox
          Left = 104
          Top = 28
          Width = 73
          Height = 21
          BevelInner = bvNone
          BevelOuter = bvNone
          Style = csDropDownList
          Ctl3D = True
          DropDownCount = 11
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ItemIndex = 0
          ParentCtl3D = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 1
          TabStop = False
          Text = '0%'
          Items.Strings = (
            '0%'
            '10%'
            '20%'
            '30%'
            '40%'
            '50%'
            '60%'
            '70%'
            '80%'
            '90%'
            '100%')
        end
        object LP_B_Training: TButton
          Left = 8
          Top = 60
          Width = 169
          Height = 21
          Caption = 'Uloz'
          TabOrder = 2
          OnClick = LP_B_TrainingClick
        end
      end
      object LP_GB_Players: TGroupBox
        Left = 16
        Top = 112
        Width = 185
        Height = 97
        Caption = 'Hraci: '
        TabOrder = 1
        object LP_CB_Players: TComboBox
          Left = 8
          Top = 28
          Width = 169
          Height = 21
          BevelInner = bvNone
          BevelOuter = bvNone
          Style = csDropDownList
          Ctl3D = True
          DropDownCount = 7
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ParentCtl3D = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 0
          TabStop = False
        end
        object LP_B_Kick: TButton
          Left = 8
          Top = 60
          Width = 169
          Height = 21
          Caption = 'Propustit'
          TabOrder = 1
          OnClick = LP_B_KickClick
        end
      end
      object LP_GB_Team: TGroupBox
        Left = 16
        Top = 216
        Width = 185
        Height = 89
        Caption = 'Klub: '
        TabOrder = 2
        object LP_B_Finances: TButton
          Left = 8
          Top = 20
          Width = 169
          Height = 21
          Caption = 'Ekonomika'
          TabOrder = 0
        end
        object LP_B_Hall: TButton
          Left = 8
          Top = 52
          Width = 169
          Height = 21
          Caption = 'Hala'
          TabOrder = 1
        end
      end
    end
  end
  object TA: TPanel
    Left = 128
    Top = 96
    Width = 800
    Height = 600
    TabOrder = 3
    Visible = False
    object TA_B1: TShape
      Left = 8
      Top = 8
      Width = 785
      Height = 585
      Brush.Color = 2169560
      Pen.Color = clWhite
      Pen.Width = 5
    end
    object TA_L_Position: TLabel
      Left = 42
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_B2: TShape
      Left = 30
      Top = 26
      Width = 739
      Height = 22
      Pen.Style = psClear
      Pen.Width = 0
    end
    object TA_L_NameHead: TLabel
      Left = 68
      Top = 26
      Width = 82
      Height = 20
      Cursor = crHandPoint
      Caption = 'Nazev Tymu:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = -11194834
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      OnClick = LP_V_LClick
    end
    object TA_L_PositionHead: TLabel
      Left = 42
      Top = 26
      Width = 12
      Height = 18
      Caption = 'P:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_WinsHead: TLabel
      Left = 354
      Top = 26
      Width = 9
      Height = 18
      Caption = 'V'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_DrawsHead: TLabel
      Left = 410
      Top = 26
      Width = 8
      Height = 18
      Caption = 'R'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_LosesHead: TLabel
      Left = 466
      Top = 26
      Width = 8
      Height = 18
      Caption = 'P'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ScoreHead: TLabel
      Left = 538
      Top = 26
      Width = 40
      Height = 18
      Caption = 'SKORE'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_PointsHead: TLabel
      Left = 746
      Top = 26
      Width = 8
      Height = 18
      Caption = 'B'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Wins: TLabel
      Left = 354
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Draws: TLabel
      Left = 410
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ScoreA: TLabel
      Left = 570
      Top = 58
      Width = 11
      Height = 24
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Loses: TLabel
      Left = 466
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ScoreH: TLabel
      Left = 538
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Points: TLabel
      Left = 746
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Name: TLabel
      Left = 66
      Top = 58
      Width = 11
      Height = 24
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_B3: TShape
      Left = 30
      Top = 370
      Width = 739
      Height = 22
      Pen.Style = psClear
      Pen.Width = 0
    end
    object TA_L_LRound: TLabel
      Left = 34
      Top = 370
      Width = 78
      Height = 18
      Caption = 'Minule kolo:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_NRound: TLabel
      Left = 698
      Top = 370
      Width = 66
      Height = 18
      Alignment = taRightJustify
      Caption = 'Pristi kolo:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_LR_D: TLabel
      Left = 155
      Top = 394
      Width = 10
      Height = 22
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_LR_DS: TLabel
      Left = 187
      Top = 394
      Width = 10
      Height = 22
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_LR_HS: TLabel
      Left = 210
      Top = 394
      Width = 10
      Height = 22
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_LR_H: TLabel
      Left = 242
      Top = 394
      Width = 10
      Height = 22
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_NR_D: TLabel
      Left = 555
      Top = 394
      Width = 10
      Height = 22
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_NR_H: TLabel
      Left = 578
      Top = 394
      Width = 10
      Height = 22
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = 22
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_MatchesHead: TLabel
      Left = 298
      Top = 26
      Width = 7
      Height = 18
      Caption = 'Z'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_Matches: TLabel
      Left = 298
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ShootsHead: TLabel
      Left = 642
      Top = 26
      Width = 42
      Height = 18
      Caption = 'STRELY'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ShootsH: TLabel
      Left = 642
      Top = 58
      Width = 11
      Height = 24
      Alignment = taRightJustify
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_L_ShootsA: TLabel
      Left = 674
      Top = 58
      Width = 11
      Height = 24
      Caption = 'V'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 24
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object TA_B_Back: TButton
      Left = 704
      Top = 552
      Width = 75
      Height = 25
      Caption = 'Zpet'
      TabOrder = 0
      OnClick = TA_B_BackClick
    end
  end
  object HO: TPanel
    Left = 48
    Top = 320
    Width = 800
    Height = 600
    TabOrder = 2
    object HO_B1: TShape
      Left = 8
      Top = 8
      Width = 785
      Height = 585
      Brush.Color = 2169560
      Pen.Color = clWhite
      Pen.Width = 5
    end
    object Label1: TLabel
      Left = 472
      Top = 72
      Width = 110
      Height = 18
      Caption = 'HO_L_Label1'
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object HO_B_LineUp: TButton
      Left = 336
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Zobraz'
      TabOrder = 0
      OnClick = HO_B_LineUpClick
    end
    object HO_B_Game: TButton
      Left = 40
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Na zapas'
      Enabled = False
      TabOrder = 1
      OnClick = HO_B_GameClick
    end
    object Quit: TButton
      Left = 448
      Top = 111
      Width = 75
      Height = 25
      Caption = 'Konec'
      TabOrder = 2
      OnClick = QuitClick
    end
    object HO_B_NextWeek: TButton
      Left = 40
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Dalsi tyden'
      TabOrder = 3
      OnClick = HO_B_NextWeekClick
    end
    object HO_B_Table: TButton
      Left = 144
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Tabulka'
      TabOrder = 4
      OnClick = HO_B_TableClick
    end
    object HO_B_SetFormation: TButton
      Left = 336
      Top = 112
      Width = 97
      Height = 25
      Caption = 'Nastav sestavu'
      TabOrder = 5
      OnClick = HO_B_SetFormationClick
    end
    object Button3: TButton
      Left = 240
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Muj tym'
      Enabled = False
      TabOrder = 6
      OnClick = Button3Click
    end
    object GroupBox3: TGroupBox
      Left = 472
      Top = 152
      Width = 289
      Height = 145
      Caption = ' Kalendar: '
      Color = 35840
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 7
      object HO_L_Label1: TLabel
        Left = 16
        Top = 24
        Width = 110
        Height = 18
        Caption = 'HO_L_Label1'
        Color = 35840
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object HO_L_Label2: TLabel
        Left = 16
        Top = 48
        Width = 110
        Height = 18
        Caption = 'HO_L_Label2'
        Color = 35840
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object HO_L_Label3: TLabel
        Left = 16
        Top = 72
        Width = 110
        Height = 18
        Caption = 'HO_L_Label3'
        Color = 35840
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object HO_L_Label4: TLabel
        Left = 16
        Top = 96
        Width = 110
        Height = 18
        Caption = 'HO_L_Label4'
        Color = 35840
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWhite
        Font.Height = -16
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
    end
    object TE_CB_Teams: TComboBox
      Left = 144
      Top = 72
      Width = 169
      Height = 21
      BevelInner = bvNone
      BevelOuter = bvNone
      Style = csDropDownList
      Ctl3D = True
      DropDownCount = 7
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemHeight = 13
      ParentCtl3D = False
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 8
      TabStop = False
    end
    object GroupBox1: TGroupBox
      Left = 48
      Top = 168
      Width = 409
      Height = 337
      Caption = 'GroupBox1'
      TabOrder = 9
      object Label2: TLabel
        Left = 24
        Top = 48
        Width = 32
        Height = 13
        Caption = 'Label2'
      end
      object Label3: TLabel
        Left = 168
        Top = 48
        Width = 32
        Height = 13
        Caption = 'Label3'
      end
      object Button1: TButton
        Left = 328
        Top = 16
        Width = 75
        Height = 25
        Caption = 'Button1'
        TabOrder = 0
        OnClick = Button1Click
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer1Timer
  end
  object Timer2: TTimer
    Interval = 10
    OnTimer = Timer2Timer
    Top = 32
  end
end
